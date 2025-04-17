#include "server.h"
#include "connection.h"
#include "connectionclosedexception.h"
#include "messagehandler.h"
#include "protocol.h"
#include "database_interface.h"

#include <iostream>
#include <memory>
#include <stdexcept>

using namespace std;

void handleClient(shared_ptr<Connection> conn, Database& db) {
    MessageHandler mh(*conn);

    try {
        Protocol cmd = mh.readCommand();

        switch (cmd) {
            case Protocol::COM_LIST_NG: {
                mh.readCommand(); // COM_END
                auto groups = db.listNewsgroups();

                mh.writeCommand(Protocol::ANS_LIST_NG);
                mh.writeNumber(groups.size());
                for (const auto& [id, name] : groups) {
                    mh.writeNumber(id);
                    mh.writeString(name);
                }
                mh.writeCommand(Protocol::ANS_END);
                break;
            }

            case Protocol::COM_CREATE_NG: {
                string name = mh.readString();
                mh.readCommand(); // COM_END

                bool success = db.createNewsgroup(name);
                mh.writeCommand(Protocol::ANS_CREATE_NG);
                if (success) {
                    mh.writeCommand(Protocol::ANS_ACK);
                } else {
                    mh.writeCommand(Protocol::ANS_NAK);
                    mh.writeCommand(Protocol::ERR_NG_ALREADY_EXISTS);
                }
                mh.writeCommand(Protocol::ANS_END);
                break;
            }

            case Protocol::COM_DELETE_NG: {
                int id = mh.readNumber();
                mh.readCommand(); // COM_END

                bool success = db.deleteNewsgroup(id);
                mh.writeCommand(Protocol::ANS_DELETE_NG);
                if (success) {
                    mh.writeCommand(Protocol::ANS_ACK);
                } else {
                    mh.writeCommand(Protocol::ANS_NAK);
                    mh.writeCommand(Protocol::ERR_NG_DOES_NOT_EXIST);
                }
                mh.writeCommand(Protocol::ANS_END);
                break;
            }

            case Protocol::COM_LIST_ART: {
                int ng_id = mh.readNumber();
                mh.readCommand(); // COM_END

                mh.writeCommand(Protocol::ANS_LIST_ART);
                try {
                    auto articles = db.listArticles(ng_id);
                    mh.writeCommand(Protocol::ANS_ACK);
                    mh.writeNumber(articles.size());
                    for (const auto& [id, title] : articles) {
                        mh.writeNumber(id);
                        mh.writeString(title);
                    }
                } catch (...) {
                    mh.writeCommand(Protocol::ANS_NAK);
                    mh.writeCommand(Protocol::ERR_NG_DOES_NOT_EXIST);
                }
                mh.writeCommand(Protocol::ANS_END);
                break;
            }

            case Protocol::COM_CREATE_ART: {
                int ng_id = mh.readNumber();
                string title = mh.readString();
                string author = mh.readString();
                string text = mh.readString();
                mh.readCommand(); // COM_END

                mh.writeCommand(Protocol::ANS_CREATE_ART);
                if (db.createArticle(ng_id, title, author, text)) {
                    mh.writeCommand(Protocol::ANS_ACK);
                } else {
                    mh.writeCommand(Protocol::ANS_NAK);
                    mh.writeCommand(Protocol::ERR_NG_DOES_NOT_EXIST);
                }
                mh.writeCommand(Protocol::ANS_END);
                break;
            }

            case Protocol::COM_DELETE_ART: {
                int ng_id = mh.readNumber();
                int art_id = mh.readNumber();
                mh.readCommand(); // COM_END

                mh.writeCommand(Protocol::ANS_DELETE_ART);
                if (!db.deleteArticle(ng_id, art_id)) {
                    mh.writeCommand(Protocol::ANS_NAK);
                    if (!db.listNewsgroups().empty() && db.listArticles(ng_id).empty()) {
                        mh.writeCommand(Protocol::ERR_ART_DOES_NOT_EXIST);
                    } else {
                        mh.writeCommand(Protocol::ERR_NG_DOES_NOT_EXIST);
                    }
                } else {
                    mh.writeCommand(Protocol::ANS_ACK);
                }
                mh.writeCommand(Protocol::ANS_END);
                break;
            }

            case Protocol::COM_GET_ART: {
                int ng_id = mh.readNumber();
                int art_id = mh.readNumber();
                mh.readCommand(); // COM_END

                mh.writeCommand(Protocol::ANS_GET_ART);
                try {
                    auto [title, author, text] = db.getArticle(ng_id, art_id);
                    mh.writeCommand(Protocol::ANS_ACK);
                    mh.writeString(title);
                    mh.writeString(author);
                    mh.writeString(text);
                } catch (const exception&) {
                    mh.writeCommand(Protocol::ANS_NAK);
                    if (db.listNewsgroups().empty() || db.listArticles(ng_id).empty()) {
                        mh.writeCommand(Protocol::ERR_NG_DOES_NOT_EXIST);
                    } else {
                        mh.writeCommand(Protocol::ERR_ART_DOES_NOT_EXIST);
                    }
                }
                mh.writeCommand(Protocol::ANS_END);
                break;
            }

            default:
                cerr << "Unknown command received" << endl;
                break;
        }

    } catch (ConnectionClosedException&) {
        throw;
    } catch (const exception& e) {
        cerr << "Exception while handling client: " << e.what() << endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2 || argc > 3) {
        cerr << "Usage: ./news_server <port> [--disk]" << endl;
        return 1;
    }

    int port = stoi(argv[1]);
    DatabaseMode mode = (argc == 3 && string(argv[2]) == "--disk") ? DatabaseMode::DISK : DatabaseMode::MEMORY;

    Server server(port);
    if (!server.isReady()) {
        cerr << "Server failed to start." << endl;
        return 2;
    }

    auto db = createDatabase(mode);

    cout << "Server running on port " << port
         << " using " << (mode == DatabaseMode::DISK ? "DiskDatabase" : "MemoryDatabase") << endl;

    while (true) {
        auto conn = server.waitForActivity();

        if (conn == nullptr) {
            auto newConn = make_shared<Connection>();
            server.registerConnection(newConn);
            cout << "New client connected" << endl;
        } else {
            try {
                handleClient(conn, *db);  // Pass Database& not MemoryDatabase&
            } catch (ConnectionClosedException&) {
                server.deregisterConnection(conn);
                cout << "Client disconnected" << endl;
            }
        }
    }
}

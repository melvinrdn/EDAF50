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

        Protocol cmd = mh.readCommand();
        switch (cmd) {
            case Protocol::COM_LIST_NG: {
                Protocol end = mh.readCommand();
                if (end != Protocol::COM_END) throw std::runtime_error("Protocol error: expected COM_END");

                mh.writeCommand(Protocol::ANS_LIST_NG);

                // List the newsgroups
                auto groups = db.listNewsgroups();
                mh.writeNumber(static_cast<int>(groups.size()));
                for (const auto& [id, name] : groups) {
                    mh.writeNumber(id);
                    mh.writeString(name);
                }

                mh.writeCommand(Protocol::ANS_END);
                break;
            }

            case Protocol::COM_CREATE_NG: {
                std::string name = mh.readString();
                Protocol end = mh.readCommand();
                if (end != Protocol::COM_END) throw std::runtime_error("Protocol error: expected COM_END");

                mh.writeCommand(Protocol::ANS_CREATE_NG);
                
                // Check if the newsgroup exists
                auto groups = db.listNewsgroups();
                bool exists = false;
                for (const auto& [id, nm] : groups) {
                    if (nm == name) {
                        exists = true;
                        break;
                    }
                }

                if (exists) {
                    // This newsgroup already exists
                    mh.writeCommand(Protocol::ANS_NAK);
                    mh.writeCommand(Protocol::ERR_NG_ALREADY_EXISTS);
                } else {
                    // Attempt to created the newsgroup
                    if (db.createNewsgroup(name)) {
                        // Newsgroup created successfully
                        mh.writeCommand(Protocol::ANS_ACK);
                    }
                    else {
                        // A bit repetitive... But otherwise the 'if' statement dont have error return
                        mh.writeCommand(Protocol::ANS_NAK);
                        mh.writeCommand(Protocol::ERR_NG_ALREADY_EXISTS);
                    }
                }

                mh.writeCommand(Protocol::ANS_END);
                break;
            }
            

            case Protocol::COM_DELETE_NG: {
                int id = mh.readNumber();
                Protocol end = mh.readCommand();
                if (end != Protocol::COM_END) throw std::runtime_error("Protocol error: expected COM_END");

                mh.writeCommand(Protocol::ANS_DELETE_NG);

                // Check if the newsgroup exists
                auto groups = db.listNewsgroups();
                bool exists = false;
                for (const auto& [ng_id, name] : groups) {
                    if (ng_id == id) {
                        exists = true;
                        break;
                    }
                }

                if (!exists) {
                    // The Newsgroup not found
                    mh.writeCommand(Protocol::ANS_NAK);
                    mh.writeCommand(Protocol::ERR_NG_DOES_NOT_EXIST);
                } else {
                    // Attempt deletion of the newsgroup
                    if (db.deleteNewsgroup(id)) {
                        mh.writeCommand(Protocol::ANS_ACK);
                    } else {
                        // Same as before, COM_CREATE_NG, this is a bit repetitive
                        // and serve as a unexpected error 
                        mh.writeCommand(Protocol::ANS_NAK);
                        mh.writeCommand(Protocol::ERR_NG_DOES_NOT_EXIST);
                    }
                }

                mh.writeCommand(Protocol::ANS_END);
                break;
            }

            case Protocol::COM_LIST_ART: {
                int ng_id = mh.readNumber();
                Protocol end = mh.readCommand();
                if (end != Protocol::COM_END) throw std::runtime_error("Protocol error: expected COM_END");

                mh.writeCommand(Protocol::ANS_LIST_ART);

                // Check if the newsgroup exists
                auto groups = db.listNewsgroups();
                bool exists = false;
                for (const auto& [id, name] : groups) {
                    if (id == ng_id) {
                        exists = true;
                        break;
                    }
                }
                
                if (!exists) {
                    // Newsgroup not found
                    mh.writeCommand(Protocol::ANS_NAK);
                    mh.writeCommand(Protocol::ERR_NG_DOES_NOT_EXIST);
                } else {
                    // List the articles
                    auto articles = db.listArticles(ng_id);
                    mh.writeCommand(Protocol::ANS_ACK);
                    mh.writeNumber(static_cast<int>(articles.size()));
                    for (const auto& [id, title] : articles) {
                        mh.writeNumber(id);
                        mh.writeString(title);
                    }
                }

                mh.writeCommand(Protocol::ANS_END);
                break;
            }

            case Protocol::COM_CREATE_ART: {
                int ng_id = mh.readNumber();
                string title = mh.readString();
                string author = mh.readString();
                string text = mh.readString();
                Protocol end = mh.readCommand();
                if (end != Protocol::COM_END) throw std::runtime_error("Protocol error: expected COM_END");

                mh.writeCommand(Protocol::ANS_CREATE_ART);

                if (db.createArticle(ng_id, title, author, text)) {
                    // Article created successfully
                    mh.writeCommand(Protocol::ANS_ACK);
                } else {
                    // Newsgroup does not exist
                    mh.writeCommand(Protocol::ANS_NAK);
                    mh.writeCommand(Protocol::ERR_NG_DOES_NOT_EXIST);
                }

                mh.writeCommand(Protocol::ANS_END);
                break;
            }

            case Protocol::COM_DELETE_ART: {
                int ng_id   = mh.readNumber();
                int art_id  = mh.readNumber();
                Protocol end = mh.readCommand();
                if (end != Protocol::COM_END)
                    throw std::runtime_error("Protocol error: expected COM_END");
            
                mh.writeCommand(Protocol::ANS_DELETE_ART);

                // Check if the newsgroup exists
                auto groups = db.listNewsgroups();
                bool groupExists = false;
                for (const auto& [id, name] : groups) {
                    if (id == ng_id) {
                        groupExists = true;
                        break;
                    }
                }
            
                if (!groupExists) {
                    // This newsgroup does not exist
                    mh.writeCommand(Protocol::ANS_NAK);
                    mh.writeCommand(Protocol::ERR_NG_DOES_NOT_EXIST);
                } else {
                    // If exist, attempt to delete the article
                    if (!db.deleteArticle(ng_id, art_id)) {
                        // Article does not exist
                        mh.writeCommand(Protocol::ANS_NAK);
                        mh.writeCommand(Protocol::ERR_ART_DOES_NOT_EXIST);
                    } else {
                        // Article deleted successfully
                        mh.writeCommand(Protocol::ANS_ACK);
                    }
                }
            
                mh.writeCommand(Protocol::ANS_END);
                break;
            }
            

            case Protocol::COM_GET_ART: {
                int ng_id = mh.readNumber();
                int art_id = mh.readNumber();
                Protocol end = mh.readCommand();
                if (end != Protocol::COM_END) throw std::runtime_error("Protocol error: expected COM_END");

                mh.writeCommand(Protocol::ANS_GET_ART);

                // Check if the newsgroup exists
                auto groups = db.listNewsgroups();
                bool groupExists = false;
                for (const auto& [id, name] : groups) {
                    if (id == ng_id) {
                        groupExists = true;
                        break;
                    }
                }

                if (!groupExists) {
                    // Newsgroup does not exist
                    mh.writeCommand(Protocol::ANS_NAK);
                    mh.writeCommand(Protocol::ERR_NG_DOES_NOT_EXIST);
                } else {
                    // Check that the article exists in that group
                    auto articles = db.listArticles(ng_id);
                    bool articleExists = false;
                    for (const auto& [id, title] : articles) {
                        if (id == art_id) {
                            articleExists = true;
                            break;
                        }
                    }
            
                    if (!articleExists) {
                        // Article does not exist
                        mh.writeCommand(Protocol::ANS_NAK);
                        mh.writeCommand(Protocol::ERR_ART_DOES_NOT_EXIST);
                    } else {
                        // Article exists, retrieve it
                        auto [title, author, text] = db.getArticle(ng_id, art_id);
                        mh.writeCommand(Protocol::ANS_ACK);
                        mh.writeString(title);
                        mh.writeString(author);
                        mh.writeString(text);
                    }
                }

                mh.writeCommand(Protocol::ANS_END);
                break;
            }

            default:
            // Misbehaving clients are disconnected immediately
            throw ConnectionClosedException();
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
                handleClient(conn, *db);
            } catch (ConnectionClosedException&) {
                server.deregisterConnection(conn);
                cout << "Client disconnected" << endl;
            }
        }
    }
}

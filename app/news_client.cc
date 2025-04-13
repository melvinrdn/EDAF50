#include "connection.h"
#include "connectionclosedexception.h"
#include "messagehandler.h"
#include "protocol.h"

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

void listNewsgroups(MessageHandler &mh)
{
    mh.writeCommand(Protocol::COM_LIST_NG);
    mh.writeCommand(Protocol::COM_END);

    if (mh.readCommand() != Protocol::ANS_LIST_NG)
        return;

    int count = mh.readNumber();
    cout << "\nNewsgroups:\n";
    for (int i = 0; i < count; ++i)
    {
        int id = mh.readNumber();
        string name = mh.readString();
        cout << " [" << id << "] " << name << endl;
    }

    mh.readCommand(); // ANS_END
}

void createNewsgroup(MessageHandler &mh)
{
    cout << "Enter title for the new newsgroup: ";
    string name;
    getline(cin, name);

    mh.writeCommand(Protocol::COM_CREATE_NG);
    mh.writeString(name);
    mh.writeCommand(Protocol::COM_END);

    if (mh.readCommand() == Protocol::ANS_CREATE_NG)
    {
        Protocol status = mh.readCommand();
        if (status == Protocol::ANS_ACK)
        {
            cout << "Newsgroup created successfully.\n";
        }
        else
        {
            mh.readCommand(); // error code
            cout << "Error: Newsgroup already exists.\n";
        }
        mh.readCommand(); // ANS_END
    }
}

void deleteNewsgroup(MessageHandler &mh)
{
    cout << "Enter newsgroup ID to delete: ";
    int id;
    cin >> id;
    cin.ignore();

    mh.writeCommand(Protocol::COM_DELETE_NG);
    mh.writeNumber(id);
    mh.writeCommand(Protocol::COM_END);

    if (mh.readCommand() == Protocol::ANS_DELETE_NG)
    {
        Protocol status = mh.readCommand();
        if (status == Protocol::ANS_ACK)
        {
            cout << "Newsgroup deleted.\n";
        }
        else
        {
            mh.readCommand(); // error code
            cout << "Error: Newsgroup not found.\n";
        }
        mh.readCommand(); // ANS_END
    }
}

void listArticles(MessageHandler &mh)
{
    cout << "Enter newsgroup ID: ";
    int id;
    cin >> id;
    cin.ignore();

    mh.writeCommand(Protocol::COM_LIST_ART);
    mh.writeNumber(id);
    mh.writeCommand(Protocol::COM_END);

    if (mh.readCommand() == Protocol::ANS_LIST_ART)
    {
        Protocol status = mh.readCommand();
        if (status == Protocol::ANS_ACK)
        {
            int count = mh.readNumber();
            cout << "\nArticles:\n";
            for (int i = 0; i < count; ++i)
            {
                int aid = mh.readNumber();
                string title = mh.readString();
                cout << " [" << aid << "] " << title << endl;
            }
        }
        else
        {
            mh.readCommand(); // error
            cout << "Error: Newsgroup does not exist.\n";
        }
        mh.readCommand(); // ANS_END
    }
}

void createArticle(MessageHandler &mh)
{
    cout << "Enter newsgroup ID: ";
    int id;
    cin >> id;
    cin.ignore();

    string title, author, text;
    cout << "Title: ";
    getline(cin, title);
    cout << "Author: ";
    getline(cin, author);
    cout << "Enter article text (end with a single line containing '::done'):\n";
    string line;
    text = "";

    while (true)
    {
        getline(cin, line);
        if (line == "::done")
            break;
        text += line + "\n";
    }

    mh.writeCommand(Protocol::COM_CREATE_ART);
    mh.writeNumber(id);
    mh.writeString(title);
    mh.writeString(author);
    mh.writeString(text);
    mh.writeCommand(Protocol::COM_END);

    if (mh.readCommand() == Protocol::ANS_CREATE_ART)
    {
        Protocol status = mh.readCommand();
        if (status == Protocol::ANS_ACK)
        {
            cout << "Article created.\n";
        }
        else
        {
            mh.readCommand(); // error
            cout << "Error: Newsgroup does not exist.\n";
        }
        mh.readCommand(); // ANS_END
    }
}

void deleteArticle(MessageHandler &mh)
{
    cout << "Enter newsgroup ID: ";
    int ngid;
    cin >> ngid;
    cout << "Enter article ID: ";
    int artid;
    cin >> artid;
    cin.ignore();

    mh.writeCommand(Protocol::COM_DELETE_ART);
    mh.writeNumber(ngid);
    mh.writeNumber(artid);
    mh.writeCommand(Protocol::COM_END);

    if (mh.readCommand() == Protocol::ANS_DELETE_ART)
    {
        Protocol status = mh.readCommand();
        if (status == Protocol::ANS_ACK)
        {
            cout << "Article deleted.\n";
        }
        else
        {
            Protocol err = mh.readCommand();
            if (err == Protocol::ERR_NG_DOES_NOT_EXIST)
                cout << "Error: Newsgroup does not exist.\n";
            else
                cout << "Error: Article does not exist.\n";
        }
        mh.readCommand(); // ANS_END
    }
}

void getArticle(MessageHandler &mh)
{
    cout << "Enter newsgroup ID: ";
    int ngid;
    cin >> ngid;
    cout << "Enter article ID: ";
    int artid;
    cin >> artid;
    cin.ignore();

    mh.writeCommand(Protocol::COM_GET_ART);
    mh.writeNumber(ngid);
    mh.writeNumber(artid);
    mh.writeCommand(Protocol::COM_END);

    if (mh.readCommand() == Protocol::ANS_GET_ART)
    {
        Protocol status = mh.readCommand();
        if (status == Protocol::ANS_ACK)
        {
            string title = mh.readString();
            string author = mh.readString();
            string text = mh.readString();
            cout << "\nTitle: " << title
                 << "\nAuthor: " << author
                 << "\nText:\n"
                 << text << "\n";
        }
        else
        {
            Protocol err = mh.readCommand();
            if (err == Protocol::ERR_NG_DOES_NOT_EXIST)
                cout << "Error: Newsgroup does not exist.\n";
            else
                cout << "Error: Article does not exist.\n";
        }
        mh.readCommand(); // ANS_END
    }
}

void printMenu()
{
    cout << "\nChoose an action:\n"
         << "1 - List Newsgroups\n"
         << "2 - Create Newsgroup\n"
         << "3 - Delete Newsgroup\n"
         << "4 - List Articles in Newsgroup\n"
         << "5 - Create Article\n"
         << "6 - Delete Article\n"
         << "7 - Read Article\n"
         << "0 - Quit\n"
         << "Your choice: ";
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cerr << "Usage: ./news_client <host> <port>" << endl;
        return 1;
    }

    int port = stoi(argv[2]);
    Connection conn(argv[1], port);

    if (!conn.isConnected())
    {
        cerr << "Connection failed.\n";
        return 2;
    }

    MessageHandler mh(conn);

    while (true)
    {
        printMenu();
        int choice;
        cin >> choice;
        cin.ignore(); // flush newline

        switch (choice)
        {
        case 1:
            listNewsgroups(mh);
            break;
        case 2:
            createNewsgroup(mh);
            break;
        case 3:
            deleteNewsgroup(mh);
            break;
        case 4:
            listArticles(mh);
            break;
        case 5:
            createArticle(mh);
            break;
        case 6:
            deleteArticle(mh);
            break;
        case 7:
            getArticle(mh);
            break;
        case 0:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}

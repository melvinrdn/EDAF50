#include "messagehandler.h"

#include <iostream>
#include <stdexcept>

// Constructor
MessageHandler::MessageHandler(Connection& conn) : conn_(conn) {}

Protocol MessageHandler::readCommand() {
    unsigned char code = conn_.read();
    return static_cast<Protocol>(code);
}

int MessageHandler::readNumber()
{
    unsigned char type = conn_.read();
    if (type != static_cast<unsigned char>(Protocol::PAR_NUM)) {
        throw std::runtime_error("Expected PAR_NUM");
    }

    unsigned char b1 = conn_.read();
    unsigned char b2 = conn_.read();
    unsigned char b3 = conn_.read();
    unsigned char b4 = conn_.read();
    return (static_cast<int>(b1) << 24) |
           (static_cast<int>(b2) << 16) |
           (static_cast<int>(b3) << 8) |
           static_cast<int>(b4);
}


std::string MessageHandler::readString()
{
    unsigned char type = conn_.read();
    if (type != static_cast<unsigned char>(Protocol::PAR_STRING)) {
        throw std::runtime_error("Expected PAR_STRING");
    }

    unsigned char b1 = conn_.read();
    unsigned char b2 = conn_.read();
    unsigned char b3 = conn_.read();
    unsigned char b4 = conn_.read();
    int length = (static_cast<int>(b1) << 24) |
                 (static_cast<int>(b2) << 16) |
                 (static_cast<int>(b3) << 8) |
                 static_cast<int>(b4);
    std::string result;
    result.reserve(length);
    for (int i = 0; i < length; ++i) {
        result.push_back(static_cast<char>(conn_.read()));
    }
    return result;
}


void MessageHandler::writeCommand(Protocol cmd)
{
    conn_.write(static_cast<unsigned char>(cmd));
}

void MessageHandler::writeNumber(int number)
{
    conn_.write(static_cast<unsigned char>(Protocol::PAR_NUM));

    conn_.write(static_cast<unsigned char>((number >> 24) & 0xFF));
    conn_.write(static_cast<unsigned char>((number >> 16) & 0xFF));
    conn_.write(static_cast<unsigned char>((number >> 8) & 0xFF));
    conn_.write(static_cast<unsigned char>(number & 0xFF));
}

void MessageHandler::writeString(const std::string& str)
{
    conn_.write(static_cast<unsigned char>(Protocol::PAR_STRING));

    int length = static_cast<int>(str.size());
    conn_.write(static_cast<unsigned char>((length >> 24) & 0xFF));
    conn_.write(static_cast<unsigned char>((length >> 16) & 0xFF));
    conn_.write(static_cast<unsigned char>((length >> 8) & 0xFF));
    conn_.write(static_cast<unsigned char>(length & 0xFF));
    for (char c : str) {
        conn_.write(static_cast<unsigned char>(c));
    }
}


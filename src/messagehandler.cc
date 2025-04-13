#include "messagehandler.h"
#include "connectionclosedexception.h"

#include <iostream>
#include <stdexcept>

// Constructor
MessageHandler::MessageHandler(Connection& conn) : conn_(conn) {}

Protocol MessageHandler::readCommand() {
    unsigned char code = conn_.read();
    return static_cast<Protocol>(code);
}

int MessageHandler::readNumber() {
    if (conn_.read() != static_cast<unsigned char>(Protocol::PAR_NUM)) {
        throw std::runtime_error("Expected PAR_NUM before reading number");
    }

    unsigned char b1 = conn_.read();
    unsigned char b2 = conn_.read();
    unsigned char b3 = conn_.read();
    unsigned char b4 = conn_.read();

    return (b1 << 24) | (b2 << 16) | (b3 << 8) | b4;
}

std::string MessageHandler::readString() {
    if (conn_.read() != static_cast<unsigned char>(Protocol::PAR_STRING)) {
        throw std::runtime_error("Expected PAR_STRING before reading string");
    }

    int length = readNumber(); // read length as a PAR_NUM

    std::string result;
    for (int i = 0; i < length; ++i) {
        result += conn_.read();
    }

    return result;
}

void MessageHandler::writeCommand(Protocol cmd) {
    conn_.write(static_cast<unsigned char>(cmd));
}

void MessageHandler::writeNumber(int number) {
    conn_.write(static_cast<unsigned char>(Protocol::PAR_NUM));

    conn_.write((number >> 24) & 0xFF);
    conn_.write((number >> 16) & 0xFF);
    conn_.write((number >> 8) & 0xFF);
    conn_.write(number & 0xFF);
}

void MessageHandler::writeString(const std::string& str) {
    conn_.write(static_cast<unsigned char>(Protocol::PAR_STRING));
    writeNumber(str.size());

    for (char ch : str) {
        conn_.write(ch);
    }
}

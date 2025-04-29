#ifndef MESSAGE_HANDLER_H
#define MESSAGE_HANDLER_H

#include "connection.h"
#include "protocol.h"
#include <string>

// Handles low-level protocol I/O over a Connection
class MessageHandler {
public:
    // Initialize with an open Connection reference
    explicit MessageHandler(Connection& conn);

    // Read a single command or status byte
    Protocol readCommand();
    // Read a numeric parameter (PAR_NUM)
    int readNumber();
    // Read a string parameter (PAR_STRING)
    std::string readString();

    // Write a command or status byte
    void writeCommand(Protocol cmd);
    // Write a numeric parameter (with PAR_NUM header)
    void writeNumber(int number);
    // Write a string parameter (with PAR_STRING header)
    void writeString(const std::string& str);

private:
    Connection& conn_; // Underlying socket connection
};

#endif

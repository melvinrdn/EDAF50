#ifndef MESSAGE_HANDLER_H
#define MESSAGE_HANDLER_H

#include "connection.h"
#include "protocol.h"
#include <string>

class MessageHandler {
public:
    explicit MessageHandler(Connection& conn);

    Protocol readCommand();         
    int readNumber();               
    std::string readString();       


    void writeCommand(Protocol cmd);   
    void writeNumber(int number);      
    void writeString(const std::string& str); 

private:
    Connection& conn_;
};

#endif 

#ifndef COMMANDINVOKER_H
#define COMMANDINVOKER_H
#include "Command.h"

class CommandInvoker{
private:
    Command* command;

public:
    CommandInvoker();
    ~CommandInvoker();

    void setCommand(Command* command);
    void executeCommand();
};

#endif
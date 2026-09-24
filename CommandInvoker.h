#ifndef COMMAND_INVOKER_H
#define COMMAND_INVOKER_H
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
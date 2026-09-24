#include "CommandInvoker.h"
#include <iostream>

CommandInvoker::CommandInvoker()
{
    command = 0;
}

CommandInvoker::~CommandInvoker()
{
    delete command;
}

void CommandInvoker::setCommand(Command* command)
{
    delete this->command;
    this->command = command;
}

void CommandInvoker::executeCommand()
{
    if (command != 0)
    {
        command->execute();
    }
    else
    {
        std::cout << "[Invoker] No command has been set."
                  << std::endl;
    }
}
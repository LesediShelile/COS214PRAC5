#ifndef CANCEL_COMMAND_H
#define CANCEL_COMMAND_H
#include "Command.h"
#include <string>

class IncidentResponseReceiver;

class CancelCommand : public Command{
private:
    IncidentResponseReceiver* receiver;
    std::string location;

public:
    CancelCommand(IncidentResponseReceiver* receiver,const std::string& location);
    void execute();
};

#endif
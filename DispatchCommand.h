#ifndef DISPATCH_COMMAND_H
#define DISPATCH_COMMAND_H
#include "Command.h"
#include <string>

class IncidentResponseReceiver;

class DispatchCommand : public Command{
private:
    IncidentResponseReceiver* receiver;
    std::string location;

public:
    DispatchCommand(IncidentResponseReceiver* receiver,const std::string& location);
    void execute();
};

#endif
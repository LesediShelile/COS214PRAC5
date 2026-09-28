#ifndef LOCKDOWN_COMMAND_H
#define LOCKDOWN_COMMAND_H
#include "Command.h"
#include <string>

class IncidentResponseReceiver;

class LockdownCommand : public Command{
private:
    IncidentResponseReceiver* receiver;
    std::string location;

public:
    LockdownCommand(IncidentResponseReceiver* receiver, const std::string& location);
    void execute();
};

#endif

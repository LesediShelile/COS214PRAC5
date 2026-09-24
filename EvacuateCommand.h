#ifndef EVACUATE_COMMAND_H
#define EVACUATE_COMMAND_H

#include "Command.h"
#include <string>

class IncidentResponseReceiver;

class EvacuateCommand : public Command
{
private:
    IncidentResponseReceiver* receiver;
    std::string location;

public:
    EvacuateCommand(IncidentResponseReceiver* receiver,
                    const std::string& location);

    void execute();
};

#endif
#ifndef EVACUATECOMMAND_H
#define EVACUATECOMMAND_H
#include "Command.h"
#include <string>

class IncidentResponseReceiver;

class EvacuateCommand : public Command{
private:
    IncidentResponseReceiver* receiver;
    std::string location;

public:
    EvacuateCommand(IncidentResponseReceiver* receiver, const std::string& location);
    void execute();
};

#endif
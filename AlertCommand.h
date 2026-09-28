#ifndef ALERTCOMMAND_H
#define ALERTCOMMAND_H
#include "Command.h"
#include <string>

class IncidentResponseReceiver;

class AlertCommand : public Command{
private:
    IncidentResponseReceiver* receiver;
    std::string message;

public:
    AlertCommand(IncidentResponseReceiver* receiver,const std::string& message);
    void execute();
};

#endif
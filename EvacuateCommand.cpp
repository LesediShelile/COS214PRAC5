#include "EvacuateCommand.h"
#include "IncidentResponseReceiver.h"

EvacuateCommand::EvacuateCommand(
    IncidentResponseReceiver* receiver,
    const std::string& location)
{
    this->receiver = receiver;
    this->location = location;
}

void EvacuateCommand::execute()
{
    receiver->evacuate(location);
}
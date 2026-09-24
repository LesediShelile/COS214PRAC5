#include "DispatchCommand.h"
#include "IncidentResponseReceiver.h"

DispatchCommand::DispatchCommand(
    IncidentResponseReceiver* receiver,
    const std::string& location)
{
    this->receiver = receiver;
    this->location = location;
}

void DispatchCommand::execute()
{
    receiver->dispatch(location);
}
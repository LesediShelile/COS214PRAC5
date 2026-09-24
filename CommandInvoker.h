#include "CancelCommand.h"
#include "IncidentResponseReceiver.h"

CancelCommand::CancelCommand(
    IncidentResponseReceiver* receiver,
    const std::string& location)
{
    this->receiver = receiver;
    this->location = location;
}

void CancelCommand::execute()
{
    receiver->cancel(location);
}
#include "AlertCommand.h"
#include "IncidentResponseReceiver.h"

AlertCommand::AlertCommand(
    IncidentResponseReceiver* receiver,
    const std::string& message)
{
    this->receiver = receiver;
    this->message = message;
}

void AlertCommand::execute()
{
    receiver->alert(message);
}
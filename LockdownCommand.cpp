#include "LockdownCommand.h"
#include "IncidentResponseReceiver.h"

LockdownCommand::LockdownCommand(IncidentResponseReceiver* receiver, const std::string& location){
    this->receiver = receiver;
    this->location = location;
}

void LockdownCommand::execute(){
    receiver->lockdown(location);
}

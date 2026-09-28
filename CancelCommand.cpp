#ifndef CANCELCOMMAND_H
#define CANCELCOMMAND_H
#include "Command.h"
#include <string>

CancelCommand::CancelCommand(IncidentResponseReceiver* receiver, const std::string& location){
    this->receiver = receiver;
    this->location = location;
}

void CancelCommand::execute(){
    receiver->cancel(location);
}

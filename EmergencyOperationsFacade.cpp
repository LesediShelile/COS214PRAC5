#include "EmergencyOperationsFacade.h"
#include "IncidentResponseReceiver.h"
#include "CommandInvoker.h"
#include "DispatchCommand.h"
#include "LockdownCommand.h"
#include "AlertCommand.h"
#include "EvacuateCommand.h"
#include "CancelCommand.h"
#include <iostream>

EmergencyOperationsFacade::EmergencyOperationsFacade(IncidentResponseReceiver* receiver, CommandInvoker* invoker){
    this->receiver = receiver;
    this->invoker = invoker;
}

void EmergencyOperationsFacade::activateEmergencyProtocol(const std::string& location, const std::string& alertMessage){
    std::cout << "\n[Facade] === Activating full emergency protocol for " << location << " ===" << std::endl;

    invoker->setCommand(new DispatchCommand(receiver, location));
    invoker->executeCommand();

    invoker->setCommand(new LockdownCommand(receiver, location));
    invoker->executeCommand();

    invoker->setCommand(new AlertCommand(receiver, alertMessage));
    invoker->executeCommand();

    std::cout << "[Facade] === Emergency protocol activation complete ===\n" << std::endl;
}

void EmergencyOperationsFacade::standDown(const std::string& location){
    std::cout << "\n[Facade] === Standing down response for " << location << " ===" << std::endl;

    invoker->setCommand(new EvacuateCommand(receiver, location));
    invoker->executeCommand();

    invoker->setCommand(new CancelCommand(receiver, location));
    invoker->executeCommand();

    std::cout << "[Facade] === Stand-down complete ===\n" << std::endl;
}

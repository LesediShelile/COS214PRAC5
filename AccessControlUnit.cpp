#include "AccessControlUnit.h"
#include "AccessControlService.h"
#include <iostream>

AccessControlUnit::AccessControlUnit(AccessControlService* accessService){
    this->accessService = accessService;
    this->mediator = 0;
}

void AccessControlUnit::setMediator(ResponseMediator* mediator){
    this->mediator = mediator;
}

bool AccessControlUnit::lockdownArea(const std::string& location){
    std::cout << "[AccessControl] Requesting lockdown of " << location << "." << std::endl;
    return accessService->lockArea(location);
}

bool AccessControlUnit::unlockArea(const std::string& location){
    std::cout << "[AccessControl] Requesting unlock of " << location << "." << std::endl;
    return accessService->unlockArea(location);
}

bool AccessControlUnit::restrictArea(const std::string& location){
    std::cout << "[AccessControl] Requesting restricted access at " << location << "." << std::endl;
    return accessService->restrictArea(location);
}

void AccessControlUnit::receiveAlert(const std::string& message){
    std::cout << "[AccessControl] Alert received: " << message << std::endl;
}

void AccessControlUnit::cancelAction(const std::string& location){
    std::cout << "[AccessControl] Standing down access control action at " << location << "." << std::endl;
}

void AccessControlUnit::update(const std::string& status){
    std::cout << "[AccessControl] Incident status changed to " << status << std::endl;
}

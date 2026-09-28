#ifndef EMERGENCYOPERATIONSFACADE_H
#define EMERGENCYOPERATIONSFACADE_H

#include <string>

class IncidentResponseReceiver;
class CommandInvoker;

class EmergencyOperationsFacade {
private:
    IncidentResponseReceiver* receiver;
    CommandInvoker* invoker;

public:
    EmergencyOperationsFacade(IncidentResponseReceiver* receiver, CommandInvoker* invoker);

    // Coordinates: dispatch + lockdown + alert (3 subsystem operations).
    void activateEmergencyProtocol(const std::string& location, const std::string& alertMessage);

    // Coordinates: evacuate + unlock (via mediator) + cancel (3+ operations).
    void standDown(const std::string& location);
};

#endif

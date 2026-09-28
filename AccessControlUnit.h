#ifndef ACCESSCONTROLUNIT_H
#define ACCESSCONTROLUNIT_H

#include <string>
#include "IncidentObserver.h"

class AccessControlService;
class ResponseMediator;

// Domain-facing response component. It talks only to AccessControlService
// (the target interface) -- it has no idea a legacy system sits behind it.
// It participates as a Mediator colleague and as an Observer of Incident.
class AccessControlUnit : public IncidentObserver {
private:
    AccessControlService* accessService;
    ResponseMediator* mediator;

public:
    explicit AccessControlUnit(AccessControlService* accessService);

    void setMediator(ResponseMediator* mediator);

    bool lockdownArea(const std::string& location);
    bool unlockArea(const std::string& location);
    bool restrictArea(const std::string& location);
    void receiveAlert(const std::string& message);
    void cancelAction(const std::string& location);

    void update(const std::string& status);
};

#endif

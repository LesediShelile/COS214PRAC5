#ifndef ACCESSCONTROLUNIT_H
#define ACCESSCONTROLUNIT_H

#include <string>
#include "IncidentObserver.h"

class AccessControlService;
class ResponseMediator;

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

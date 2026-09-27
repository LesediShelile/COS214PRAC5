#ifndef SECURITYTEAM_H
#define SECURITYTEAM_H
#include <string>
#include "IncidentObserver.h"

class ResponseMediator;

class SecurityTeam : public IncidentObserver{
private:
    ResponseMediator* mediator;

public:
    SecurityTeam();

    void setMediator(ResponseMediator* mediator);

    void dispatch(const std::string& location);
    void evacuate(const std::string& location);
    void receiveAlert(const std::string& message);
    void cancelAction(const std::string& location);

    void reportStatus(const std::string& status);

    void update(const std::string& status);
};

#endif

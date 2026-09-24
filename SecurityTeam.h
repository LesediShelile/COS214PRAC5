#ifndef SECURITY_TEAM_H
#define SECURITY_TEAM_H

#include <string>

class ResponseMediator;

class SecurityTeam
{
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
};

#endif
#ifndef INCIDENTRESPONSERECEIVER_H
#define INCIDENTRESPONSERECEIVER_H

#include <string>

class ResponseMediator;
class Incident;

class IncidentResponseReceiver
{
private:
    ResponseMediator* mediator;
    Incident* incident;

public:
    IncidentResponseReceiver(ResponseMediator* mediator,
                             Incident* incident);

    void dispatch(const std::string& location);
    void evacuate(const std::string& location);
    void alert(const std::string& message);
    void cancel(const std::string& location);
};

#endif
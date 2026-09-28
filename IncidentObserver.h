#ifndef INCIDENTOBSERVER_H
#define INCIDENTOBSERVER_H

#include <string>

class IncidentObserver
{
public:
    virtual void update(const std::string& status) = 0;
    virtual ~IncidentObserver();
};

#endif

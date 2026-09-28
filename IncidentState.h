#ifndef INCIDENTSTATE_H
#define INCIDENTSTATE_H

#include <string>

class IncidentState
{
public:
    virtual std::string getStatus() const = 0;
    virtual bool isFinal() const { return false; }
    virtual ~IncidentState() {}
};

#endif

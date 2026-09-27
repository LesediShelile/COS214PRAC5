#ifndef REPORTEDSTATE_H
#define REPORTEDSTATE_H

#include "IncidentState.h"

class ReportedState : public IncidentState
{
public:
    std::string getStatus() const;
};

#endif

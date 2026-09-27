#ifndef ACTIVESTATE_H
#define ACTIVESTATE_H

#include "IncidentState.h"

class ActiveState : public IncidentState
{
public:
    std::string getStatus() const;
};

#endif

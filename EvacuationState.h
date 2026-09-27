#ifndef EVACUATIONSTATE_H
#define EVACUATIONSTATE_H

#include "IncidentState.h"

class EvacuationState : public IncidentState
{
public:
    std::string getStatus() const;
};

#endif

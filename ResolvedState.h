#ifndef RESOLVEDSTATE_H
#define RESOLVEDSTATE_H

#include "IncidentState.h"

class ResolvedState : public IncidentState
{
public:
    std::string getStatus() const;
    bool isFinal() const { return true; }
};

#endif

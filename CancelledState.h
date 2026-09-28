#ifndef CANCELLEDSTATE_H
#define CANCELLEDSTATE_H

#include "IncidentState.h"

class CancelledState : public IncidentState
{
public:
    std::string getStatus() const;
    bool isFinal() const { return true; }
};

#endif

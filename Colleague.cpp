#include "Colleague.h"

Colleague::Colleague()
{
    mediator = 0;
}

Colleague::~Colleague()
{
}

void Colleague::setMediator(Mediator* mediator)
{
    this->mediator = mediator;
}

Mediator* Colleague::getMediator() const
{
    return mediator;
}
#ifndef MEDIATOR_H
#define MEDIATOR_H

class Colleague;

class Mediator
{
public:
    virtual ~Mediator();

    virtual void notify(Colleague* colleague) = 0;
};

#endif
#ifndef COLLEAGUE_H
#define COLLEAGUE_H

class Mediator;

class Colleague
{
protected:
    Mediator* mediator;

public:
    Colleague();
    virtual ~Colleague();

    void setMediator(Mediator* mediator);
    Mediator* getMediator() const;
};

#endif
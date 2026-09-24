#include "SecurityTeam.h"
#include "ResponseMediator.h"

#include <iostream>

SecurityTeam::SecurityTeam()
{
    mediator = 0;
}

void SecurityTeam::setMediator(ResponseMediator* mediator)
{
    this->mediator = mediator;
}

void SecurityTeam::dispatch(const std::string& location)
{
    std::cout << "[Security] Dispatching security team to "
              << location << "." << std::endl;
}

void SecurityTeam::evacuate(const std::string& location)
{
    std::cout << "[Security] Managing evacuation at "
              << location << "." << std::endl;
}

void SecurityTeam::receiveAlert(const std::string& message)
{
    std::cout << "[Security] Alert received: "
              << message << std::endl;
}

void SecurityTeam::cancelAction(const std::string& location)
{
    std::cout << "[Security] Cancelling security response at "
              << location << "." << std::endl;
}

void SecurityTeam::reportStatus(const std::string& status)
{
    std::cout << "[Security] Reporting status: "
              << status << std::endl;

    if (mediator != 0)
    {
        mediator->notify("SecurityTeam", status);
    }
}
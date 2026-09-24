#include "IncidentResponseReceiver.h"
#include "ResponseMediator.h"
#include "Incident.h"

#include <iostream>

IncidentResponseReceiver::IncidentResponseReceiver(ResponseMediator* mediator,Incident* incident){
    this->mediator = mediator;
    this->incident = incident;
}

void IncidentResponseReceiver::dispatch(const std::string& location){
    std::cout << "[Receiver] Processing dispatch request."<< std::endl;

    incident->setStatus("IN PROGRESS");

    mediator->dispatchResponse(location);
}

void IncidentResponseReceiver::evacuate(const std::string& location){
    std::cout << "[Receiver] Processing evacuation request."<< std::endl;

    incident->setStatus("EVACUATION");
    mediator->evacuateArea(location);
}

void IncidentResponseReceiver::alert(const std::string& message){
    std::cout << "[Receiver] Processing alert request."<< std::endl;
    mediator->sendAlert(message);
}

void IncidentResponseReceiver::cancel(const std::string& location)
{
    std::cout << "[Receiver] Processing cancellation request."<< std::endl;

    incident->setStatus("CANCELLED");
    mediator->cancelResponse(location);
}
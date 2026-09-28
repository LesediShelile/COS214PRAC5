#include "IncidentResponseReceiver.h"
#include "ResponseMediator.h"
#include "Incident.h"
#include "ActiveState.h"
#include "EvacuationState.h"
#include "CancelledState.h"

#include <iostream>

IncidentResponseReceiver::IncidentResponseReceiver(ResponseMediator* mediator, Incident* incident){
    this->mediator = mediator;
    this->incident = incident;
}

void IncidentResponseReceiver::dispatch(const std::string& location){
    std::cout << "[Receiver] Processing dispatch request." << std::endl;

    incident->setStatus(new ActiveState());

    mediator->dispatchResponse(location);
}

void IncidentResponseReceiver::evacuate(const std::string& location){
    std::cout << "[Receiver] Processing evacuation request." << std::endl;

    incident->setStatus(new EvacuationState());
    mediator->evacuateArea(location);
}

void IncidentResponseReceiver::alert(const std::string& message){
    std::cout << "[Receiver] Processing alert request." << std::endl;
    mediator->sendAlert(message);
}

void IncidentResponseReceiver::cancel(const std::string& location)
{
    if (incident->isFinal()){
        std::cout << "[Receiver] Cannot cancel incident " << incident->getIncidentId()
                   << " -- it is already " << incident->getStatus() << "." << std::endl;
        return;
    }

    std::cout << "[Receiver] Processing cancellation request." << std::endl;

    incident->setStatus(new CancelledState());
    mediator->cancelResponse(location);
}

void IncidentResponseReceiver::lockdown(const std::string& location){
    std::cout << "[Receiver] Processing lockdown request." << std::endl;
    mediator->coordinateLockdown(location);
}

void IncidentResponseReceiver::unlock(const std::string& location){
    std::cout << "[Receiver] Processing unlock request." << std::endl;
    mediator->coordinateUnlock(location);
}

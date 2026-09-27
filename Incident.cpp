#include "Incident.h"
#include "IncidentState.h"
#include "IncidentObserver.h"
#include "ReportedState.h"
#include <iostream>

Incident::Incident(int id, const std::string& description,const std::string& location){
    this->incidentId = id;
    this->description = description;
    this->location = location;
    this->status = new ReportedState();
}

int Incident::getIncidentId() const{
    return incidentId;
}

std::string Incident::getDescription() const{
    return description;
}

std::string Incident::getLocation() const{
    return location;
}

std::string Incident::getStatus() const{
    return status->getStatus();
}

void Incident::setStatus(IncidentState* newState){
    delete state;
    state = newState;
    notifyObservers();
}

void Incident::attach(IncidentObserver* observer)
{
    observers.push_back(observer);
}

void Incident::notifyObservers()
{
    for(unsigned int i = 0; i < observers.size(); i++)
    {
        observers[i]->update(
            state->getStatus()
        );
    }
}

void Incident::display() const{
    std::cout << "Incident ID: " << incidentId << std::endl;
    std::cout << "Description: " << description << std::endl;
    std::cout << "Location: " << location << std::endl;
    std::cout << "Status: " << status->getStatus() << std::endl;
}

Incedent::~Incedent(){
    delete status;
}

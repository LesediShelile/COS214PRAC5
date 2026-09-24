#include "Incident.h"
#include <iostream>

Incident::Incident(int id, const std::string& description,const std::string& location){
    this->incidentId = id;
    this->description = description;
    this->location = location;
    this->status = "REPORTED";
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
    return status;
}

void Incident::setStatus(const std::string& status){
    this->status = status;
}

void Incident::display() const{
    std::cout << "Incident ID: " << incidentId << std::endl;
    std::cout << "Description: " << description << std::endl;
    std::cout << "Location: " << location << std::endl;
    std::cout << "Status: " << status << std::endl;
}
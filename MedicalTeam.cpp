#include "MedicalTeam.h"

#include <iostream>

void MedicalTeam::dispatch(const std::string& location)
{
    std::cout << "[Medical] Dispatching medical team to "
              << location << "." << std::endl;
}

void MedicalTeam::evacuate(const std::string& location)
{
    std::cout << "[Medical] Supporting evacuation at "
              << location << "." << std::endl;
}

void MedicalTeam::receiveAlert(const std::string& message)
{
    std::cout << "[Medical] Alert received: "
              << message << std::endl;
}

void MedicalTeam::cancelAction(const std::string& location)
{
    std::cout << "[Medical] Cancelling medical response at "
              << location << "." << std::endl;
}
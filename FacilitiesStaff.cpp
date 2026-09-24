#include "FacilitiesStaff.h"
#include <iostream>

void FacilitiesStaff::dispatch(const std::string& location){
    std::cout << "[Facilities] Sending facilities staff to "<< location << "." << std::endl;
}

void FacilitiesStaff::evacuate(const std::string& location){
    std::cout << "[Facilities] Checking facilities during evacuation at "<< location << "." << std::endl;
}

void FacilitiesStaff::receiveAlert(const std::string& message){
    std::cout << "[Facilities] Alert received: "<< message << std::endl;
}

void FacilitiesStaff::cancelAction(const std::string& location){
    std::cout << "[Facilities] Cancelling facilities response at "<< location << "." << std::endl;
}
#include "ResponseMediator.h"
#include "SecurityTeam.h"
#include "MedicalTeam.h"
#include "FacilitiesStaff.h"
#include <iostream>

ResponseMediator::ResponseMediator(){
    securityTeam = 0;
    medicalTeam = 0;
    facilitiesStaff = 0;
}

void ResponseMediator::setSecurityTeam(SecurityTeam* team){
    securityTeam = team;
}

void ResponseMediator::setMedicalTeam(MedicalTeam* team){
    medicalTeam = team;
}

void ResponseMediator::setFacilitiesStaff(FacilitiesStaff* staff){
    facilitiesStaff = staff;
}

void ResponseMediator::dispatchResponse(const std::string& location){
    std::cout << "[Mediator] Coordinating emergency response." << std::endl;

    if (securityTeam != 0){
        securityTeam->dispatch(location);
    }

    if (medicalTeam != 0){
        medicalTeam->dispatch(location);
    }

    if (facilitiesStaff != 0){
        facilitiesStaff->dispatch(location);
    }
}

void ResponseMediator::evacuateArea(const std::string& location){
    std::cout << "[Mediator] Coordinating evacuation." << std::endl;

    if (securityTeam != 0){
        securityTeam->evacuate(location);
    }

    if (medicalTeam != 0){
        medicalTeam->evacuate(location);
    }

    if (facilitiesStaff != 0){
        facilitiesStaff->evacuate(location);
    }
}

void ResponseMediator::sendAlert(const std::string& message){
    std::cout << "[Mediator] Sending emergency alert." << std::endl;

    if (securityTeam != 0){
        securityTeam->receiveAlert(message);
    }

    if (medicalTeam != 0){
        medicalTeam->receiveAlert(message);
    }

    if (facilitiesStaff != 0){
        facilitiesStaff->receiveAlert(message);
    }
}

void ResponseMediator::cancelResponse(const std::string& location){
    std::cout << "[Mediator] Cancelling emergency response." << std::endl;

    if (securityTeam != 0){
        securityTeam->cancelAction(location);
    }

    if (medicalTeam != 0){
        medicalTeam->cancelAction(location);
    }

    if (facilitiesStaff != 0){
        facilitiesStaff->cancelAction(location);
    }
}

void ResponseMediator::notify(const std::string& sender,const std::string& status){
    std::cout << "[Mediator] " << sender<< " reported status: " << status << std::endl;

    if (sender == "SecurityTeam" && status == "READY"){
        
        std::cout << "[Mediator] Security is ready. "<< "Informing Medical Team and Facilities Staff." << std::endl;

        if (medicalTeam != 0){
            medicalTeam->receiveAlert("Security team is ready for medical coordination.");
        }

        if (facilitiesStaff != 0){
            facilitiesStaff->receiveAlert("Security team is ready. Prepare facilities.");
        }
    }
}
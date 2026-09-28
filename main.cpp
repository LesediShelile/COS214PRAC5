#include <iostream>

#include "Incident.h"
#include "IncidentResponseReceiver.h"
#include "ResponseMediator.h"
#include "SecurityTeam.h"
#include "MedicalTeam.h"
#include "FacilitiesStaff.h"
#include "AccessControlUnit.h"
#include "LegacyAccessControlSystem.h"
#include "LegacyAccessAdapter.h"
#include "CommandInvoker.h"
#include "DispatchCommand.h"
#include "AlertCommand.h"
#include "EvacuateCommand.h"
#include "CancelCommand.h"
#include "LockdownCommand.h"
#include "EmergencyOperationsFacade.h"

static void printBanner(const std::string& text){
    std::cout << "\n================================================================\n";
    std::cout << text << "\n";
    std::cout << "================================================================\n";
}

int main(){


    LegacyAccessControlSystem legacySystem;
    legacySystem.registerZone("Library", 101);
    legacySystem.registerZone("Chemistry Building", 202);
    legacySystem.registerZone("Main Gate", 303);

    LegacyAccessAdapter accessAdapter(&legacySystem);


    SecurityTeam securityTeam;
    MedicalTeam medicalTeam;
    FacilitiesStaff facilitiesStaff;
    AccessControlUnit accessControlUnit(&accessAdapter);

    ResponseMediator mediator;
    mediator.setSecurityTeam(&securityTeam);
    mediator.setMedicalTeam(&medicalTeam);
    mediator.setFacilitiesStaff(&facilitiesStaff);
    mediator.setAccessControlUnit(&accessControlUnit);

    securityTeam.setMediator(&mediator);
    accessControlUnit.setMediator(&mediator);

    CommandInvoker invoker;


    printBanner("SCENARIO 1: Reported fire in the Library");

    Incident incident1(1, "Reported fire", "Library");
    incident1.attach(&securityTeam);
    incident1.attach(&medicalTeam);
    incident1.attach(&facilitiesStaff);
    incident1.attach(&accessControlUnit);
    incident1.display();

    IncidentResponseReceiver receiver1(&mediator, &incident1);

    std::cout << "\n-- Operator dispatches response teams --" << std::endl;
    invoker.setCommand(new DispatchCommand(&receiver1, incident1.getLocation()));
    invoker.executeCommand();
    incident1.display();

    std::cout << "\n-- Operator orders evacuation (Mediator also auto-unlocks exits) --" << std::endl;
    invoker.setCommand(new EvacuateCommand(&receiver1, incident1.getLocation()));
    invoker.executeCommand();
    incident1.display();

    std::cout << "\n-- Operator sends a campus-wide alert --" << std::endl;
    invoker.setCommand(new AlertCommand(&receiver1, "Fire in the Library. Avoid the area."));
    invoker.executeCommand();

    std::cout << "\n-- Incident resolved: operator cancels the response --" << std::endl;
    invoker.setCommand(new CancelCommand(&receiver1, incident1.getLocation()));
    invoker.executeCommand();
    incident1.display();

    std::cout << "\n-- Invalid-operation case: cancelling an already-cancelled incident --" << std::endl;
    invoker.setCommand(new CancelCommand(&receiver1, incident1.getLocation()));
    invoker.executeCommand();

    printBanner("SCENARIO 2: Chemical spill in the Chemistry Building");

    Incident incident2(2, "Chemical spill", "Chemistry Building");
    incident2.attach(&securityTeam);
    incident2.attach(&medicalTeam);
    incident2.attach(&facilitiesStaff);
    incident2.attach(&accessControlUnit);
    incident2.display();

    IncidentResponseReceiver receiver2(&mediator, &incident2);
    EmergencyOperationsFacade facade(&receiver2, &invoker);

    std::cout << "\n-- Operator calls the Facade's one-shot emergency protocol --" << std::endl;
    facade.activateEmergencyProtocol(incident2.getLocation(),
                                      "Chemical spill in the Chemistry Building. Restricted access in effect.");
    incident2.display();

    std::cout << "\n-- Adapter failure case: lockdown requested for an unregistered zone --" << std::endl;
    invoker.setCommand(new LockdownCommand(&receiver2, "Unmapped Annex"));
    invoker.executeCommand();

    std::cout << "\n-- Operator calls the Facade's stand-down workflow to close out --" << std::endl;
    facade.standDown(incident2.getLocation());
    incident2.display();

    printBanner("End of demonstration");

    return 0;
}

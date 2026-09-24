#ifndef RESPONSE_MEDIATOR_H
#define RESPONSE_MEDIATOR_H

#include <string>

class SecurityTeam;
class MedicalTeam;
class FacilitiesStaff;

class ResponseMediator
{
private:
    SecurityTeam* securityTeam;
    MedicalTeam* medicalTeam;
    FacilitiesStaff* facilitiesStaff;

public:
    ResponseMediator();

    void setSecurityTeam(SecurityTeam* team);
    void setMedicalTeam(MedicalTeam* team);
    void setFacilitiesStaff(FacilitiesStaff* staff);

    void dispatchResponse(const std::string& location);
    void evacuateArea(const std::string& location);
    void sendAlert(const std::string& message);
    void cancelResponse(const std::string& location);

    void notify(const std::string& sender,
                const std::string& status);
};

#endif
#ifndef RESPONSE_MEDIATOR_H
#define RESPONSE_MEDIATOR_H
#include <string>

class SecurityTeam;
class MedicalTeam;
class FacilitiesStaff;
class AccessControlUnit;

class ResponseMediator
{
private:
    SecurityTeam* securityTeam;
    MedicalTeam* medicalTeam;
    FacilitiesStaff* facilitiesStaff;
    AccessControlUnit* accessControlUnit;

public:
    ResponseMediator();

    void setSecurityTeam(SecurityTeam* team);
    void setMedicalTeam(MedicalTeam* team);
    void setFacilitiesStaff(FacilitiesStaff* staff);
    void setAccessControlUnit(AccessControlUnit* unit);

    void dispatchResponse(const std::string& location);
    void evacuateArea(const std::string& location);
    void sendAlert(const std::string& message);
    void cancelResponse(const std::string& location);

    void coordinateLockdown(const std::string& location);
    void coordinateUnlock(const std::string& location);

    void notify(const std::string& sender, const std::string& status);
};

#endif

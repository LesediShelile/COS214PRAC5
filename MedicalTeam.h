#ifndef MEDICAL_TEAM_H
#define MEDICAL_TEAM_H
#include <string>

class MedicalTeam{
public:
    void dispatch(const std::string& location);
    void evacuate(const std::string& location);
    void receiveAlert(const std::string& message);
    void cancelAction(const std::string& location);
};

#endif
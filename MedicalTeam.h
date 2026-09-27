#ifndef MEDICALTEAM_H
#define MEDICALTEAM_H
#include <string>
#include "IncidentObserver.h"

class MedicalTeam : public IncidentObserver {
public:
    void dispatch(const std::string& location);
    void evacuate(const std::string& location);
    void receiveAlert(const std::string& message);
    void cancelAction(const std::string& location);

    void update(const std::string& status);
};

#endif

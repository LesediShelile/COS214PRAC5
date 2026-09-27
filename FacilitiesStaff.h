#ifndef FACILITIES_STAFF_H
#define FACILITIES_STAFF_H
#include <string>
#include "IncidentObserver.h"

class FacilitiesStaff : public IncidentObserver {
public:
    void dispatch(const std::string& location);
    void evacuate(const std::string& location);
    void receiveAlert(const std::string& message);
    void cancelAction(const std::string& location);

    void update(const std::string& status);
};

#endif

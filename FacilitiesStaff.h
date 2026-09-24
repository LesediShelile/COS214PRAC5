#ifndef FACILITIES_STAFF_H
#define FACILITIES_STAFF_H

#include <string>

class FacilitiesStaff
{
public:
    void dispatch(const std::string& location);
    void evacuate(const std::string& location);
    void receiveAlert(const std::string& message);
    void cancelAction(const std::string& location);
};

#endif
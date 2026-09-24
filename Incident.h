#ifndef INCIDENT_H
#define INCIDENT_H

#include <string>

class Incident {

private:
    int incidentId;
    std::string description;
    std::string location;
    std::string status;


public:
    Incident(int id, const std::string& description,
             const std::string& location);

    int getIncidentId() const;
    std::string getDescription() const;
    std::string getLocation() const;
    std::string getStatus() const;

    void setStatus(const std::string& status);

    void display() const;




};




#endif
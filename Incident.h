#ifndef INCIDENT_H
#define INCIDENT_H

#include <string>
#include <vector>

class IncidentState;
class IncidentObserver;

class Incident {

private:
    int incidentId;
    std::string description;
    std::string location;
    IncidentState* state;
    std::vector<IncidentObserver*> observers;


public:
    Incident(int id, const std::string& description,const std::string& location);

    ~Incident();
    int getIncidentId() const;
    std::string getDescription() const;
    std::string getLocation() const;
    std::string getStatus() const;

    void setStatus(IncidentState* newState);
    void attach(IncidentObserver* observer);
    void notifyObservers();
    void display() const;
    bool isFinal() const;

};

#endif
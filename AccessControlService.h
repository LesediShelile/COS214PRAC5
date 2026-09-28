#ifndef ACCESSCONTROLSERVICE_H
#define ACCESSCONTROLSERVICE_H

#include <string>

class AccessControlService {
public:
    virtual bool lockArea(const std::string& location) = 0;
    virtual bool unlockArea(const std::string& location) = 0;
    virtual bool restrictArea(const std::string& location) = 0;
    virtual ~AccessControlService();
};

#endif
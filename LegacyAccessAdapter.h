#ifndef LEGACYACCESSADAPTER_H
#define LEGACYACCESSADAPTER_H

#include "AccessControlService.h"

class LegacyAccessControlSystem;

class LegacyAccessAdapter : public AccessControlService {
private:
    LegacyAccessControlSystem* legacySystem;

    bool actuate(const std::string& location, int mode, const std::string& verb);

public:
    explicit LegacyAccessAdapter(LegacyAccessControlSystem* legacySystem);

    bool lockArea(const std::string& location);
    bool unlockArea(const std::string& location);
    bool restrictArea(const std::string& location);
};

#endif

#ifndef LEGACYACCESSCONTROLSYSTEM_H
#define LEGACYACCESSCONTROLSYSTEM_H

#include <string>
#include <map>

class LegacyAccessControlSystem {
private:
    std::map<std::string, int> zoneRegistry;

public:
    LegacyAccessControlSystem();

    void registerZone(const std::string& zoneName, int zoneCode);

    int lookupZoneCode(const std::string& zoneName) const;
d.
    int actuateDoor(int zoneCode, int mode);
};

#endif

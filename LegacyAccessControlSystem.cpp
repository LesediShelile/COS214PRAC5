#include "LegacyAccessControlSystem.h"
#include <iostream>

LegacyAccessControlSystem::LegacyAccessControlSystem(){}

void LegacyAccessControlSystem::registerZone(const std::string& zoneName, int zoneCode){
    zoneRegistry[zoneName] = zoneCode;
}

int LegacyAccessControlSystem::lookupZoneCode(const std::string& zoneName) const{
    std::map<std::string, int>::const_iterator it = zoneRegistry.find(zoneName);
    if (it == zoneRegistry.end()){
        return -1;
    }
    return it->second;
}

int LegacyAccessControlSystem::actuateDoor(int zoneCode, int mode){
    if (zoneCode < 0){
        std::cout << "[LegacyAccessControlSystem] RAW_CMD zone=UNKNOWN mode=" << mode
                   << " -> ERR_CODE=1" << std::endl;
        return 1;
    }

    std::cout << "[LegacyAccessControlSystem] RAW_CMD zone=" << zoneCode
               << " mode=" << mode << " -> STATUS_OK" << std::endl;
    return 0;
}

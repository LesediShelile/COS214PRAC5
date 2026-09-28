#include "LegacyAccessAdapter.h"
#include "LegacyAccessControlSystem.h"
#include <iostream>

LegacyAccessAdapter::LegacyAccessAdapter(LegacyAccessControlSystem* legacySystem){
    this->legacySystem = legacySystem;
}

bool LegacyAccessAdapter::actuate(const std::string& location, int mode, const std::string& verb){
    int zoneCode = legacySystem->lookupZoneCode(location);
    int result = legacySystem->actuateDoor(zoneCode, mode);

    if (result != 0){
        // Invalid-operation case, handled sensibly rather than ignored.
        std::cout << "[Adapter] Could not " << verb << " '" << location
                   << "' -- unknown to the legacy access system. No action taken."
                   << std::endl;
        return false;
    }

    std::cout << "[Adapter] Translated request: " << verb << " '" << location
               << "' -> legacy zone " << zoneCode << "." << std::endl;
    return true;
}

bool LegacyAccessAdapter::lockArea(const std::string& location){
    return actuate(location, 0, "lock");
}

bool LegacyAccessAdapter::unlockArea(const std::string& location){
    return actuate(location, 1, "unlock");
}

bool LegacyAccessAdapter::restrictArea(const std::string& location){
    return actuate(location, 2, "restrict");
}

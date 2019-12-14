#include <checks.h>

// credit to XorTroll's GoldLeaf for these checks

bool isAtmosphere() {
	u64 tmpc = 0;
    return R_SUCCEEDED(splGetConfig((SplConfigItem)65000, &tmpc));
}

bool isReiNX() {
	Handle tmph = 0;
    Result rc = smRegisterService(&tmph, "rnx", false, 1);
    if(R_FAILED(rc)) return true;
    smUnregisterService("rnx");
    return false;
}

bool isSXOS() {
	Handle tmph = 0;
    Result rc = smRegisterService(&tmph, "tx", false, 1);
    if(R_FAILED(rc)) return true;
    smUnregisterService("tx");
    return false;
}
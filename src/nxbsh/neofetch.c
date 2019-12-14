#include <neofetch.h>

void neofetch() {

	Result rc;
	SetSysFirmwareVersion fwv;
	rc = setsysInitialize();

	rc = setsysGetFirmwareVersion(&fwv);
    if(R_FAILED(rc)) {
      printf("0x%x\n", rc);
    }

    char cfw[] = "Atmosphere";
            
    if(isAtmosphere() == true) {
      strcpy(cfw, "Atmosphere");
    } else if(isReiNX() == true) {
      strcpy(cfw, "ReiNX");
    } else if(isSXOS() == true) {
      strcpy(cfw, "SXOS");
    }

    printf("root@switch\n");
    printf("-----------\n");
    printf("OS: %s\n", cfw);
    printf("Firmware: %s\n", fwv.display_version);
    printf("Shell: nxbsh 0.1\n");

}
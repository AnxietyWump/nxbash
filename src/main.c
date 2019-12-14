#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <checks.h>

#include <switch.h>

#define NXSH_VERSION "0.1"

int main(int arc, char **argv) {
	
  	consoleInit(NULL);

    SetSysFirmwareVersion fwv;

  	printf("\033[1;32m");
  	printf("                    __ \n");
  	printf("   ____  _  _______/ /_ \n");
  	printf("  / __ \\| |/_/ ___/ __ \\\n");
  	printf(" / / / />  <(__  ) / / / \n");
  	printf("/_/ /_/_/|_/____/_/ /_/ \n\n");
    printf("\033[0m");
    printf("===================================\n");
    printf("Welcome to nxsh v%s - Press + to exit\n", NXSH_VERSION);
    printf("===================================\n\n");

    while(appletMainLoop()) {
    	
    	hidScanInput();

    	u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);

    	if(kDown & KEY_PLUS) break;

      if(kDown & KEY_A) {
      	Result rc;
        SwkbdConfig kbd;
        char ostr[16] = {0};
        rc = swkbdCreate(&kbd, 0);

        if(!R_FAILED(rc)) {
          swkbdConfigMakePresetDefault(&kbd);
          swkbdConfigSetOkButtonText(&kbd, "OK");
          swkbdConfigSetGuideText(&kbd, "Type your command and press OK");

          rc = swkbdShow(&kbd, ostr, sizeof(ostr));
          rc = setsysInitialize();

          rc = setsysGetFirmwareVersion(&fwv);
          if(R_FAILED(rc)) {
            printf("0x%x\n", rc);
          }

          if(strcmp(ostr, "neofetch") == 0) {
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
            printf("Shell: nxsh 1.0\n");
            printf("Memory Usage: %d\n", InfoType_UsedMemorySize);
          }
        }

      }


    	consoleUpdate(NULL);
  }

    consoleExit(NULL);
    return 0;
}
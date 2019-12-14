#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <switch.h>

#define NXWSH_VERSION "0.1"

int main(int arc, char **argv) {
	
  	consoleInit(NULL);

  	printf("\033[1;32m");
  	printf("                    __ \n");
  	printf("   ____  _  _______/ /_ \n");
  	printf("  / __ \\| |/_/ ___/ __ \\\n");
  	printf(" / / / />  <(__  ) / / / \n");
  	printf("/_/ /_/_/|_/____/_/ /_/ \n\n");
    printf("\033[0m");
    printf("===================================\n");
    printf("Welcome to nxwsh v%s - Press + to exit\n", NXWSH_VERSION);
    printf("===================================\n\n");

    printf("root@switch:sdmc/");

    while(appletMainLoop()) {
    	
    	hidScanInput();

    	u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);

    	if(kDown & KEY_PLUS) break;

    	consoleUpdate(NULL);
  }

    consoleExit(NULL);
    return 0;
}
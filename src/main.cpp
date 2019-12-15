#include <iostream>
#include <switch.h>
#include <ui/ui.hpp>

#define NXSH_VERSION "0.1"

using namespace std;

int main(int argc, char **argv) {
	
	UI u;

	while(appletMainLoop()) {

    	hidScanInput();

    	u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);

    	if(kDown & KEY_PLUS) break;

    }

    return 0;
}
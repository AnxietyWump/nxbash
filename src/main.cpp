#include <iostream>
#include <switch.h>

#define NXSH_VERSION "0.1"

using namespace std;

int main(int argc, char **argv) {
	consoleInit(NULL);

	cout << "test gamer" << endl;

	while(appletMainLoop()) {

    	hidScanInput();

    	u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);

    	if(kDown & KEY_PLUS) break;

    	consoleUpdate(NULL);
    }

    consoleExit(NULL);
    return 0;
}
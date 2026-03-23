#include <vulkan/vulkan.h>
#include <iostream>

typedef struct MyStruct {

}; MyStruct;

int initVulkan();
int mainLoop();
int cleanup();

int run() {
	if (!initVulkan()) {
		printf("%s\n", "!ERROR: in initVulkan()");
		return 1;
	}
	if (!mainLoop()) {
		printf("%s\n", "!ERROR: in mainLoop()");
		return 1;
	}
	if (!cleanup()) {
		printf("%s\n", "!ERROR: in cleanup()");
		return 1;
	}
}

int main(void)
{
	if (!run()) {
		printf("%s\n", "!ERROR: in run()");
		return 1;
	}

	return 0;
}

int initVulkan() {

}

int mainLoop() {

}

int cleanup() {

}

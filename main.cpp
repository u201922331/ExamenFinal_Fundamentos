#include "headers/platformer/App.h"

int main(int argc,char** argv) {
	SDL_Init(SDL_INIT_EVERYTHING);
	App app;
	app.run();

	return 0;
}
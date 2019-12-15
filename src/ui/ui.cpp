#include <ui/ui.hpp>

UI::UI() {
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		SDL_Log("Error: %s\n", SDL_GetError());
		return -1;
	}

	mwindow = SDL_CreateWindow("nxsh", 0, 0, 1920, 1080, 0);
	if(!mwindow) {
		SDL_Log("Error: %s\n", SDL_GetError());
		SDL_Quit();
		return -1;
	}

	mrenderer = SDL_CreateRenderer(mwindow, 0, SDL_RENDERER_ACCELERATED);
	if(!mrenderer) {
		SDL_Log("Error: %s\n", SDL_GetError());
		SDL_Quit();
		return -1;
	}

	SDL_SetRenderDrawColor(mrenderer, 0, 0, 0, 255);
	SDL_RenderClear(mrenderer);
	SDL_RenderPresent(mrenderer);
}

UI::~UI() {
	SDL_DestroyRenderer(mrenderer);
	SDL_DestroyWindow(mwindow);
	SDL_Quit();

	return 0;
}
#include <ui/ui.hpp>

UI::UI() {
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		SDL_Log("Error: %s\n", SDL_GetError());
	}

	mwindow = SDL_CreateWindow("nxsh", 0, 0, 1920, 1080, 0);

	mrenderer = SDL_CreateRenderer(mwindow, 0, SDL_RENDERER_ACCELERATED);

	SDL_SetRenderDrawColor(mrenderer, 0, 0, 0, 255);
	SDL_RenderClear(mrenderer);
	SDL_RenderPresent(mrenderer);
}

UI::~UI() {
	SDL_DestroyRenderer(mrenderer);
	SDL_DestroyWindow(mwindow);
	SDL_Quit();
}
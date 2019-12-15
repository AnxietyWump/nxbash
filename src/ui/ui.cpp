#include <ui/ui.hpp>

UI::UI() {
	SDL_Init(SDL_INIT_EVERYTHING);

	window = SDL_CreateWindow("nxsh", 0, 0, 1920, 1080, 0);

	renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}

UI::~UI() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
#include <iostream>
#include <switch.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

using namespace std;

class UI {
	public:
		UI();
		~UI();
	private:
		SDL_Window *window;
		SDL_Renderer *renderer;
		TTF_Font *font;
};
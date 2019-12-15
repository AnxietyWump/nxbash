#include <iostream>
#include <switch.h>
#include <SDL2/SDL.h>

using namespace std;

class UI {
	public:
		UI();
		~UI();

	private:
		SDL_Window *mwindow;
		SDL_Renderer *mrenderer;
};
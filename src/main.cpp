#include <SDL.h>
#include "Window.h"
#include "Renderer.h"
#ifdef main
#undef main
#endif
int main(int argc, char* args[]){
	using namespace O2D;
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("SDL failed to initialize!");
		SDL_Quit();
		return 0;
	}

	bool running = true;
	Window window = Window(600, 600, "Hello Engine", false);
	SDL_Surface* backboard = window.getWindow();
	Renderer renderer;
	SDL_Event event;
	renderer.createRect(window.getWindow(), "newid", 50, 50, 10, 20, 255, 255, 0);
	renderer.createRect(window.getWindow(), "new", 45, 200, 50, 50, 128, 0, 128);
	while (running) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				window.closeWindow();
			}
		}
		
		renderer.renderShapes(window.getWindow());
	}

	window.closeWindow();

	return 1;
}

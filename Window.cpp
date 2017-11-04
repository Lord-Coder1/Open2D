#include "Window.h"
#include "Variables.h"

O2D::Window::Window(int length, int width, const char* title, bool fullscreen) {
	if (!fullscreen) {
		window = SDL_SetVideoMode(length, width, 32, SDL_SWSURFACE);
	}
	if (fullscreen) {
		window = SDL_SetVideoMode(length, width, 32, SDL_SWSURFACE | SDL_FULLSCREEN);
	}
	SDL_WM_SetCaption(title, NULL);
}

void O2D::Window::closeWindow() {
	SDL_Quit();
}

SDL_Surface* O2D::Window::getWindow(){
	return window;
}

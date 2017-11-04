#include <SDL.h>

namespace O2D {
	class Window {

	public:

		Window(int length, int width, const char* title, bool fullscreen);

		void closeWindow();

		SDL_Surface* getWindow();

	private:

		SDL_Surface* window;

	};
}

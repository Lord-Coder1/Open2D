#include <sdl.h>
#include <string>
#include <vector>
#include <algorithm>
#include "Variables.h"
//Temporarily
#include <iostream>

namespace O2D {
	class Renderer {

	public:

		void createRect(Frame win, std::string id, int x, int y, int width, int height, Uint8 r, Uint8 g, Uint8 b);

		void destroyRect(std::string id);

		void destroyRect(int index);

		bool emptyRect(std::string id);

		bool emptyRect(int index);

		void drawPixel(Frame window, int x, int y);

		void drawPixel(Frame window, int x, int y, int r, int g, int b);

		void renderShapes(Frame window);

	private:

		std::vector<Rect> rectangles;
		std::vector<std::string> ids;
		std::vector<Uint32> colors;

		std::string emptyID();

		Rect getEmptyRect();

		bool getRectEqual(Rect rect1, Rect rect2);

		int getEmptyRectIndex();

		int getIDIndex(std::string id);

		template<class type>
		int sizeofVector(std::vector<type> vector);


	};
}



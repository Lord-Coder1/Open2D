#include "Renderer.h"



void O2D::Renderer::createRect(Frame win, std::string id, int x, int y, int width, int height, Uint8 r, Uint8 g, Uint8 b) {
	Uint32 color;
	color = SDL_MapRGB(win->format, r, g, b);
	std::cout << color << std::endl;
	Rect rect;
	rect.x = x;
	rect.y = y;
	rect.h = height;
	rect.w = width;

	int indexFree = getEmptyRectIndex();
	if (indexFree >= 0) {
		rectangles[indexFree] = rect;
		ids[indexFree] = id;
		colors[indexFree] = color;
	}
	else {
		rectangles.push_back(rect);
		ids.push_back(id);
		colors.push_back(color);
	}
}


void O2D::Renderer::destroyRect(std::string id) {
	for (int index = 0; index < ids.size(); index++) {
		if (ids[index] == id) {
			destroyRect(index);
			break;
		}
	}
}

void O2D::Renderer::destroyRect(int index) {
	rectangles[index] = getEmptyRect();
	ids[index] = emptyID();
	colors[index] = NULL;
}

bool O2D::Renderer::emptyRect(std::string id) {
	int index = getIDIndex(id);
	if (index < 0) {
		return false;
	}
	rectangles[index] = getEmptyRect();
}

bool O2D::Renderer::emptyRect(int index) {
	if (index < 0) {
		return false;
	}
	rectangles[index] = getEmptyRect();
}

void O2D::Renderer::drawPixel(Frame window, int x, int y) {
	Uint32 color;
	color = SDL_MapRGB(window->format, 255, 255, 255);
	Uint32* locationBuffer = (Uint32*)window->pixels + y * window->pitch / 4 * + x;
	(*locationBuffer) = color;
}

void O2D::Renderer::drawPixel(Frame window, int x, int y, int r, int g, int b) {
	Uint32 color;
	color = SDL_MapRGB(window->format, r, g, b);
	Uint32* locationBuffer = (Uint32*)window->pixels + y * window->pitch / 4 * +x;
	(*locationBuffer) = color;
}

void O2D::Renderer::renderShapes(Frame window) {
	for (int index = 0; index < O2D::Renderer::sizeofVector<Rect>(rectangles); index++) {
		if (!getRectEqual(rectangles[index], getEmptyRect())) {
			//Exception Thrown BuG Here(Known)
			SDL_FillRect((window), &(rectangles[index]), (colors[index]));
		}
	}
}




std::string O2D::Renderer::emptyID() { return ""; }

O2D::Rect O2D::Renderer::getEmptyRect() {
	Rect rect; 
	rect.x = 0;
	rect.y = 0;
	rect.h = 0;
	rect.w = 0;
	return rect;
}

bool O2D::Renderer::getRectEqual(Rect rect1, Rect rect2) {
	if (rect1.x == rect2.x && rect1.y == rect2.y) {
		return true;
	}

	return false;
}

int O2D::Renderer::getEmptyRectIndex() {
	for (int index = 0; index < O2D::Renderer::sizeofVector<Rect>(rectangles); index++) {
		if (getRectEqual(rectangles[index], getEmptyRect())) {
			return index;
			break;
		}
	}
	return -1;
}

int O2D::Renderer::getIDIndex(std::string id) {
	for (int index = 0; index < ids.size(); index++) {
		if (ids[index] == id) {
			return index;
			break;
		}
	}
	return -1;
}

template<class type>
int O2D::Renderer::sizeofVector(std::vector<type> vector){
	int lengthOfVector = 0;
	for (std::vector<type>::iterator index = vector.begin(); index != vector.end(); index++) {
		lengthOfVector++;
	}
	return lengthOfVector;
}

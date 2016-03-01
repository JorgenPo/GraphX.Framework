#ifndef XCOLOR_H
#define XCOLOR_H

#include <SDL.h>

namespace GraphX {
	class XColor
	{
	public:
		enum Color
		{
			RED, GREEN, BLUE,
			YELLOW, PURPLE, WHITE,
			BLACK
		};

		XColor(Color color);

		SDL_Color getSDLColor() const { return mColor; }
		Color	  getColor() const { return mColorEnum; }
	private:
		SDL_Color mColor;
		Color mColorEnum;
	};
}

#endif
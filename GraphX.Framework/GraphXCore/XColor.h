#ifndef XCOLOR_H
#define XCOLOR_H

#include <SDL.h>
#include "XError.h"

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
	private:
		SDL_Color mColor;
	};

	
	XColor::XColor(Color color)
	{
		switch (color) {
		case Color::RED:
			mColor.r = 255;
			break;
		case Color::GREEN:
			mColor.g = 255;
			break;
		case Color::BLUE:
			mColor.b = 255;
			break;
		case Color::YELLOW:
			mColor.r = 255;
			mColor.g = 255;
			break;
		case Color::PURPLE:
			mColor.r = 255;
			mColor.b = 255;
			break;
		case Color::WHITE:
			mColor.r = 255;
			mColor.g = 255;
			mColor.b = 255;
			break;
		case Color::BLACK:
			break;
		default:
			throw Error::XError("XColor error", "wrong color passed to constructor.");
			break;
		}
	}
}

#endif XCOLOR_H
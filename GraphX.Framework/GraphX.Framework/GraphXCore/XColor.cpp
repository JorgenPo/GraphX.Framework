#include "XColor.h"

namespace GraphX {
	XColor::XColor(Color color)
		: mColorEnum(color)
	{
		switch (color) {
		case Color::RED:
			mColor.r = 255;
			mColor.g = 0;
			mColor.b = 0;
			mColor.a = 0;
			break;
		case Color::GREEN:
			mColor.r = 0;
			mColor.g = 255;
			mColor.b = 0;
			mColor.a = 0;
			break;
		case Color::BLUE:
			mColor.r = 0;
			mColor.g = 0;
			mColor.b = 255;
			mColor.a = 0;
			break;
		case Color::YELLOW:
			mColor.r = 255;
			mColor.g = 255;
			mColor.b = 0;
			mColor.a = 0;
			break;
		case Color::PURPLE:
			mColor.r = 255;
			mColor.g = 0;
			mColor.b = 255;
			mColor.a = 0;
			break;
		case Color::WHITE:
			mColor.r = 255;
			mColor.g = 255;
			mColor.b = 255;
			mColor.a = 0;
			break;
		case Color::BLACK:
			mColor.r = 0;
			mColor.g = 0;
			mColor.b = 0;
			mColor.a = 0;
			break;
		default:
			//throw Error::XError("XColor error", "wrong color passed to constructor.");
			break;
		}
	}
}
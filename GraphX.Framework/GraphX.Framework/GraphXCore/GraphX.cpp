#include "GraphX.h"

namespace GraphX {
	namespace Core {
		using namespace std;

		void GraphXApp::Release(void * object)
		{
			//
		}

		GraphXApp::GraphXApp(const char * title, size_t width,
			size_t height, SDL_WindowFlags flags)
			: mWidth(width), mHeight(height), quit(false), mBrush(XColor::BLACK)
		{
			if (SDL_Init(SDL_INIT_VIDEO) != 0) {
				throw Error::InitError(SDL_GetError());
			}

			mWindow = SDL_CreateWindow
				(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
					(int)width, (int)height, flags);
			if (mWindow == nullptr) {
				SDL_Quit();
				throw Error::InitError(SDL_GetError());
			}

			mRender = SDL_CreateRenderer
				(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (mRender == nullptr) {
				SDL_DestroyWindow(mWindow);
				SDL_Quit();
				throw Error::InitError(SDL_GetError());
			}
		}

		GraphXApp::~GraphXApp()
		{
			SDL_DestroyWindow(mWindow);
			SDL_DestroyRenderer(mRender);
			SDL_Quit();
		}

		void GraphXApp::SetDrawingColor(XColor::Color color)
		{
			mBrush = XColor(color);
		}

		void GraphXApp::Control()
		{
			while(SDL_PollEvent(&mEvent)) {
				switch (mEvent.type) {
				case SDL_QUIT:
					onExit();
					break;
				case SDL_KEYDOWN:
					onKeyPressed(mEvent);
					break;
				case SDL_MOUSEBUTTONDOWN:
					onMouseClick(mEvent);
					break;
				case SDL_MOUSEMOTION:
					onMouseMove(mEvent);
					break;
				}
			}
		}

		void GraphXApp::onMouseMove(SDL_Event e)
		{

		}

		void GraphXApp::onMouseClick(SDL_Event e)
		{

		}

		void GraphXApp::onStart()
		{
		}

		void GraphXApp::onKeyPressed(SDL_Event e)
		{

		}

		void GraphXApp::onExit()
		{
			quit = true;
		}

		void GraphXApp::DrawPoint(int x, int y)
		{
			SDL_Color color = mBrush.getSDLColor();
			SDL_SetRenderDrawColor(mRender, color.r, color.g, color.b, color.a);
			SDL_RenderDrawPoint(mRender, x, y);
		}

		void GraphXApp::DrawLine(int startX, int startY, int endX, int endY)
		{
			SDL_Color color = mBrush.getSDLColor();
			SDL_SetRenderDrawColor(mRender, color.r, color.g, color.b, color.a);
			SDL_RenderDrawLine(mRender, startX, startY, endX, endY);
		}

		void GraphXApp::DrawCircle(int centerX, int centerY, int r)
		{
			SDL_Color color = mBrush.getSDLColor();
			SDL_SetRenderDrawColor(mRender, color.r, color.g, color.b, color.a);

			int y = 0;
			int x = 0;
			for (double t = 0; t < 2 * M_PI; t+=0.01) {
				x = centerX + (int)(cos(t) * r);
				y = centerY + (int)(sin(t) * r);
				SDL_RenderDrawPoint(mRender, x, y);
			}
		}

		void GraphXApp::DrawSquare(SDL_Rect rectangle)
		{
			SDL_Color color = mBrush.getSDLColor();
			SDL_SetRenderDrawColor(mRender, color.r, color.g, color.b, color.a);
		}

		void GraphXApp::ClearScreen()
		{
			SDL_Color color = mBrush.getSDLColor();
			SDL_SetRenderDrawColor(mRender, color.r, color.g, color.b, color.a);
			SDL_RenderClear(mRender);
		}

		void GraphXApp::UpdateScreen()
		{
			SDL_RenderPresent(mRender);
		}

		SDL_Texture * GraphXApp::LoadTexture(const char * bmpFile)
		{
			SDL_Texture *texture = nullptr;
			SDL_Surface *buffer = SDL_LoadBMP(bmpFile);

			if (buffer == nullptr) {
				SDL_FreeSurface(buffer);
				throw Error::XError
					("GraphX LoadTexture error", "wrong file name passed.");
			}

			texture = SDL_CreateTextureFromSurface(mRender, buffer);
			SDL_FreeSurface(buffer);
			if (texture == nullptr) {
				throw Error::XError
					("GraphX LoadTexture error", "wrong file.");
			}

			return texture;
		}

		void GraphXApp::DrawTexture(SDL_Texture * texture, SDL_Rect source,
			SDL_Rect dest, bool updateScreen)
		{
			if (texture == nullptr) {
				throw Error::NullPointerError("texture", "DrawTexture");
			}

			if (SDL_RenderCopy(mRender, texture, &source, &dest) != 0) {
				throw - 1;
			}
			if (updateScreen) UpdateScreen();
		}

		void GraphXApp::DrawTexture(SDL_Texture * texture, bool updateScreen)
		{
			if (texture == nullptr) {
				throw Error::NullPointerError("texture", "DrawTexture");
				return;
			}

			if (SDL_RenderCopy(mRender, texture, NULL, NULL) != 0) {
				throw - 1;
			}
			if (updateScreen) UpdateScreen();
		}
	}
}
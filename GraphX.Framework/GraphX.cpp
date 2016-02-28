#include "GraphX.h"
#include <iostream>

using namespace std;

void GraphXApp::Release(void * object)
{
	//
}

GraphXApp::GraphXApp(const char * title, size_t width,
	size_t height, SDL_WindowFlags flags) 
	: mWidth(width), mHeight(height)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		cerr << "SDL Init error: " << SDL_GetError() << endl;
		throw - 1;
	}

	mWindow = SDL_CreateWindow
		(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			(int)width, (int)height, flags);
	if (mWindow == nullptr) {
		cerr << "SDL CreateWindow error: " << SDL_GetError() << endl;
		SDL_Quit();
		throw - 1;
	}

	mRender = SDL_CreateRenderer
		(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (mRender == nullptr) {
		cerr << "SDL CreateRenderer error: " << SDL_GetError() << endl;
		SDL_DestroyWindow(mWindow);
		SDL_Quit();
		throw - 1;
	}
}

GraphXApp::~GraphXApp()
{
	SDL_DestroyWindow(mWindow);
	SDL_DestroyRenderer(mRender);
	SDL_Quit();
}

void GraphXApp::DrawPoint(int x, int y, SDL_Color color)
{
	SDL_SetRenderDrawColor(mRender, color.r, color.g, color.b, color.a);
	SDL_RenderDrawPoint(mRender, x, y);
}

void GraphXApp::ClearScreen(SDL_Color color)
{
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
		cerr << "GraphX LoadTexture error: " << SDL_GetError() << endl;
		SDL_FreeSurface(buffer);
		return texture;
	}

	texture = SDL_CreateTextureFromSurface(mRender, buffer);
	SDL_FreeSurface(buffer);
	if (texture == nullptr) {
		cerr << "GraphX LoadTexture error: " << SDL_GetError() << endl;
	}

	return texture;
}

void GraphXApp::RenderTexture(SDL_Texture * texture, SDL_Rect source,
	SDL_Rect dest, bool updateScreen)
{
	if (SDL_RenderCopy(mRender, texture, &source, &dest) != 0) {
		throw - 1;
	}
	if (updateScreen) UpdateScreen();
}

void GraphXApp::RenderTexture(SDL_Texture * texture, bool updateScreen)
{
	if (SDL_RenderCopy(mRender, texture, NULL, NULL) != 0) {
		throw - 1;
	}
	if (updateScreen) UpdateScreen();
}

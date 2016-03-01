#ifndef GRAPHX_H
#define GRAPHX_H

#include <SDL.h>
#include <string>
#include "XError.h"
#include "XColor.h"

namespace GraphX {
	namespace Core {
		class GraphXApp
		{
		public:
			static void Release(void* object);

			GraphXApp(const char* title = "New SDL App", size_t width = 640,
				size_t height = 480, SDL_WindowFlags flags = SDL_WindowFlags::SDL_WINDOW_SHOWN);

			~GraphXApp();

			// Virtual methods
			virtual int  Run() = 0;
			virtual void Init() = 0;
			virtual void Update() = 0;
			virtual void Draw() = 0;

			// Input methods 
			virtual void onMouseMove(SDL_Event);
			virtual void onMouseClick(SDL_Event);
			virtual void onStart();
			virtual void onKeyPressed(SDL_Event);
			virtual void onExit();

			// Drawing methods
			void DrawPoint(int x, int y);
			void DrawLine(int startX, int startY, int endX, int endY);
			void DrawCircle(int centerX, int centerY, int r);
			void DrawSquare(SDL_Rect rectangle);
			//void DrawTriangle(); /*Maybe this method is useless?*/
			
			// Screen manipulations
			void ClearScreen();
			void UpdateScreen();

			// Texture methods
			SDL_Texture * LoadTexture(const char* file);

			void DrawTexture(SDL_Texture *texture,
				SDL_Rect source, SDL_Rect dest, bool updateScreen = true);
			void DrawTexture(SDL_Texture *texture, bool updateScreen = true);

			// Get methods
			SDL_Window*			GetWindow() { return mWindow; }
			SDL_Renderer*		GetRenderer() { return mRender; }

			// Set methods
			void				SetDrawingColor(XColor::Color color);
		protected/*methods*/:
			void Control();

		protected/*properties*/:
			bool quit;
			SDL_Window *mWindow;
			SDL_Renderer *mRender;
			SDL_Event	mEvent;

			XColor		mBrush;
			size_t mWidth, mHeight;
		};
	}
}
#endif
#include "XApplication.h"


XApplication::XApplication()
	:GraphXApp()
{
	welcome = nullptr;
	// Move all loading stuff in Init() function
	// Here are some other init... :)
}


XApplication::~XApplication()
{
	// Release resources
	SDL_DestroyTexture(welcome);
}

int XApplication::Run()
{
	this->Init();
	while (!quit) {
		this->Control();
		this->Update();
		this->Draw();
	}

	return 0;
}

void XApplication::Init()
{
	/*Welcome texture. Delete it, if you don't need it:)*/
	welcome = LoadTexture("GraphX_Welcome.bmp");

	// Init logic here. There are only one-time initialization
	//per-frame initialization must be moved to Update() function
}

void XApplication::Update()
{
	// Per-frame update 
}

void XApplication::Draw()
{
	ClearScreen();
	
	//Draw here! :)
	DrawTexture(welcome); /*Delete it*/

	UpdateScreen();
}

#include "XApplication.h"



XApplication::XApplication()
	:GraphXApp()
{
	// Move all loading stuff in Init() function
	// Here are some other init... :)
}


XApplication::~XApplication()
{
	// Release resources
}

int XApplication::Run()
{
	this->Init();
	while (true) {
		this->Update();
		this->Draw();
	}

	return 0;
}

void XApplication::Init()
{
	SDL_Texture *welcome = LoadTexture("GraphX_Welcome.bmp");
	if (welcome != nullptr) {
		RenderTexture(welcome, true);
	}
	SDL_DestroyTexture(welcome);

	// Init logic here. There are only one-time initialization
	//per-frame initialization must be moved to Update() function
}

void XApplication::Update()
{
	//Per-frame update 
}

void XApplication::Draw()
{
	//Per-frame draw
}

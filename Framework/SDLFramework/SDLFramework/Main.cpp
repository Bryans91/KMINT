#include <iostream>
#define _CRTDBG_MAP_ALLOC
#include "Config.h"
#include "FWApplication.h"
#include <SDL_events.h>
#include "SDL_timer.h"
#include <time.h>
#include "Game.h"

int main(int args[])
{
	//auto window = Window::CreateSDLWindow();
	auto application = new FWApplication();
	if (!application->GetWindow())
	{
		LOG("Couldn't create window...");
		return EXIT_FAILURE;
	}
	
	application->SetTargetFPS(60);
	application->SetColor(Color(255, 10, 40, 255));
	
	Game game(application);
	

	//while (true){}
	int frame = 0;
	while (application->IsRunning())
	{
		application->StartTick();

		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				application->Quit();
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym){

				default:
					break;
				}
			}
		}

		
		application->SetColor(Color(0, 0, 0, 255));
		application->DrawText("Welcome to KMint", 800 / 2, 600 / 2);

		// For the background
		application->SetColor(Color(255, 255, 255, 255));

		game.update(frame);

		game.drawObjects(application);

		application->UpdateGameObjects();
		application->RenderGameObjects();
		application->EndTick();

		frame++;
		if (frame == 59) {
			frame = 0;
		}
	}
	_CrtDumpMemoryLeaks();
	return EXIT_SUCCESS;
}
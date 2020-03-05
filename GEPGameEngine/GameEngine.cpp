#include "SDL.h"
#include "Game.h"

int main(int argc, char* argv[])
{
	if (!Game::Instance()->Init("SDL Framework", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 768, 0))
	{
		return 1;
	}

	Game::Instance()->InitializeActor(1024/2, 768/2, 60, 60, Colour{255,0,0,255});
	while (Game::Instance()->IsRunning())
	{
		Game::Instance()->HandleEvents();
		Game::Instance()->Update();
		Game::Instance()->Render();
		SDL_Delay(10);
	}

	Game::Instance()->Clean();
	


	return 0;
}
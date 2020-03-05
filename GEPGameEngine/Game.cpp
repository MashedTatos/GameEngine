#include "Game.h"
#include <iostream>

Game* Game::Instance()
{
	static Game* instance = new Game();
	return instance;
}


bool Game::Init(const char* title, const int xPos, const int yPos, const int width, const int height, const int flags)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL Initialzation successfull\n";
		sdlWindow = SDL_CreateWindow(title, xPos, yPos, width, height, flags);
		if (sdlWindow == nullptr)
		{
			std::cout << "Window init failed";
			return false;
		}

		std::cout << "Window succesfully created";
		sdlRenderer = SDL_CreateRenderer(sdlWindow, -1, 0);
		if (sdlRenderer == nullptr)
		{
			std::cout << "Renderer failed to init";
			return false;
		}

		std::cout << "Renderer created";

		

	}
	else
	{
		std::cout << "SDL Failed to initialize";
		return false;
	}


	m_iKeystates = SDL_GetKeyboardState(nullptr);
	isAppRunning = true;
	return true;
	

}

bool Game::IsRunning()
{
	return isAppRunning;
}

bool Game::KeyDown(SDL_Scancode c)
{
	if (m_iKeystates == nullptr)
	{
		return false;
	}

	if (m_iKeystates[c] == 1)
	{
		return true;
	}

	else
	{
		return false;
	}
}


bool Game::KeyRealeased(SDL_Scancode c)
{
	bool isPrevStateDown = KeyDown(c);
	if (isPrevStateDown)
	{
		if (KeyDown(c) == false)
		{
			return true;
		}

		else
		{
			return false;
		}
	}


}

void Game::Update()
{
	player->Action();
}

void Game::HandleEvents()
{
	SDL_Event event;
	
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			isAppRunning = false;
			break;
		default:
			break;
		}
	}
}

void Game::InitializeActor(int x, int y, int width, int height, Colour colour)
{

	Actor* actor = new Actor(Rectangle{x,y,width,height},colour);
	this->player = actor;

	/*actor.x = x;
	actor.y = y;
	actor.h = height;
	actor.w = width;*/

}

void Game::RenderActor()
{
	Colour c = this->player->GetColour();
	SDL_SetRenderDrawColor(sdlRenderer, c.r, c.g, c.b, c.a);
	SDL_RenderFillRect(sdlRenderer, &player->GetRect());
}

void Game::Render()
{
	SDL_SetRenderDrawColor(sdlRenderer, 255, 255, 255, 255);
	SDL_RenderClear(sdlRenderer);
	RenderActor();
	SDL_RenderPresent(sdlRenderer);
}


void Game::Clean()
{
	std::cout << "Clean up";
	SDL_DestroyWindow(sdlWindow);
	SDL_DestroyRenderer(sdlRenderer);
	SDL_Quit();
}

Vector2 Game::GetWindowSize()
{
	Vector2 v2;
	SDL_GetWindowSize(sdlWindow, &v2.x, &v2.y);
	return v2;
}
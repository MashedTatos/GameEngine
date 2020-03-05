#pragma once
#include <SDL.h>
#include "Actor.h"


class Game 
{

private:
	SDL_Window* sdlWindow;
	SDL_Renderer* sdlRenderer;
	bool isAppRunning;
	const Uint8* m_iKeystates;
	SDL_Rect actor;
	Actor* player;


public:
	static Game* Instance();
	bool Init(const char* title, const int xPos, const int yPos, const int width, const int height, const int flags);
	SDL_Window* GetWindow() { return this->sdlWindow; }
	SDL_Renderer* GetRenderer() { return this->sdlRenderer; }
	void InitializeActor(int x, int y, int width, int height, Colour colour);
	bool KeyRealeased(SDL_Scancode c);

	bool IsRunning();
	bool KeyDown(SDL_Scancode c);
	void Update();
	void HandleEvents();
	void RenderActor();

	void Render();

	void Clean();
	Vector2 GetWindowSize();



};
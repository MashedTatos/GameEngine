#include "Actor.h"
#include "Game.h"
#include "Random.h"
Actor::Actor()
{
	this->colour = Colour{255,255,255,255};
	this->rectangle = Rectangle{ 0,0,0,0 };
	this->direction = Vector2{ 0,1 };
	this->isPaused = false;
}

Actor::Actor(int x, int y, int w, int h, Colour colour) : Actor()
{
	this->rectangle = Rectangle{ x,y,w,h };
	this->colour = colour;

}

Actor::Actor(Rectangle rectangle, Colour colour) : Actor()
{
	this->rectangle = rectangle;
	this->colour = colour;

}




void Actor::Move(const Vector2 vector2)
{
	this->rectangle.x += vector2.x;
	this->rectangle.y += vector2.y;
}

void Actor::Action()
{

	if (this->rectangle.y% Game::Instance()->GetWindowSize().y == 0 )
	{
		this->direction = this->direction * Vector2{ 0,-1 };
		this->colour = Colour{ GEP::RandomRange(0,255),GEP::RandomRange(0,255),GEP::RandomRange(0,255),255 };

	}

	if (Game::Instance()->KeyDown(SDL_SCANCODE_SPACE))
	{
		isPaused = !isPaused;
	}

	if (Game::Instance()->KeyDown(SDL_SCANCODE_R))
	{
		this->rectangle.x = Game::Instance()->GetWindowSize().x / 2;
		this->rectangle.y = Game::Instance()->GetWindowSize().y / 2;
	}

	if (!isPaused)
	{
		this->Move(Vector2{ 1,1 } *direction);
	}

	



	/*if (Game::Instance()->KeyDown(SDL_SCANCODE_LEFT))
	{
		this->Move(Vector2{ -1,0 });
	}

	if (Game::Instance()->KeyDown(SDL_SCANCODE_RIGHT))
	{
		this->Move(Vector2{ 1,0 });
	}

	if (Game::Instance()->KeyDown(SDL_SCANCODE_UP))
	{
		this->Move(Vector2{ 0,-1 });
	}

	if (Game::Instance()->KeyDown(SDL_SCANCODE_DOWN))
	{
		this->Move(Vector2{ 0,1 });
	}
	*/
}


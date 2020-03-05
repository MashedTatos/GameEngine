#pragma once
#pragma once
#include "Utility.h"
class Actor
{
	
private:
	Rectangle rectangle;
	Colour colour;
	Vector2 direction;
	bool isPaused;
public:
	Actor();
	Actor(int x, int y, int w, int h, Colour colour);
	Actor(Rectangle rectangle, Colour colour);
	Rectangle GetRect() { return this->rectangle; }
	Colour GetColour() { return this->colour; }
	void SetRect(Rectangle value) { this->rectangle = value; }
	void SetColor(Colour value) { this->colour = value; }
	void Move(const Vector2 vector);
	void Action();
};


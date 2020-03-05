#pragma once
#include <SDL.h>

typedef SDL_Rect Rectangle;

struct Vector2 {
	int x;
	int y;

	Vector2& operator +(const Vector2& vector)
	{
		this->x += vector.x;
		this->y += vector.y;
		return *this;
	}

	Vector2& operator -(const Vector2& vector)
	{
		this->x -= vector.x;
		this->y -= vector.y;
		return *this;
	}

	Vector2& operator *(const Vector2& vector)
	{
		this->x = vector.x * this->x;
		this->y = vector.y * this->y;
		return *this;
	}

	Vector2& operator ^(const Vector2& vector)
	{
		this->x = vector.x ^ this->x;
		this->y = vector.y ^ this->y;
		return *this;
	}

};


struct Colour {
	int r;
	int g;
	int b;
	int a;
};
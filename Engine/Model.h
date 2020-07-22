#pragma once

#include <vector>
#include "Vec2.h"

class Model
{
public:
	Model(std::vector<Vec2> vertices, float width, float height)
		:
		vertices(vertices), width(width), height(height)
	{

	}

	std::vector<Vec2> GetVertices() const
	{
		return vertices;
	}

	float GetWidth() const
	{
		return width;
	}

	float GetHeight() const
	{
		return height;
	}

private:
	std::vector<Vec2> vertices;
	float width;
	float height;
};
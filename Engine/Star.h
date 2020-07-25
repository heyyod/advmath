#pragma once

#include "Entity.h"
#include "Vec2.h"
#include <vector>

class Star : public Entity
{
public:
	Star(Vec2 pos, float radius, float innerRatio, int nFlares, Color c)
		:
		Entity(Star::Make(radius, radius * innerRatio, nFlares), pos, c),
		radius(radius)
	{}

	float GetRadius() const
	{
		return radius;
	}

private:
	static std::vector<Vec2> Make(float outerRadius, float innerRadius, int nFlares = 5)
	{
		int totalVerteces = 2 * nFlares;
		std::vector<Vec2> star;
		star.reserve(totalVerteces);
		float dTheta = 2.0f * 3.14159f / totalVerteces;
		for (int i = 0; i < totalVerteces; i++)
		{
			const float rad = (i % 2 == 0) ? outerRadius : innerRadius;
			star.emplace_back(rad*cos(float(i) * dTheta), rad*sin(float(i)*dTheta));
		}
		return star;
	}

private:
	float radius;
};
#pragma once

#include "Vec2.h"
#include "Graphics.h"
#include "vector"

class CoordinateTransformer
{
public:
	CoordinateTransformer(Graphics& gfx)
		:
		gfx(gfx)
	{}
	
	void DrawPolyline(std::vector<Vec2> poly, Color c)
	{
		for (auto& i : poly)
		{
			i.y *= -1.0f;
			i.x += float( gfx.ScreenWidth / 2 );
			i.y += float( gfx.ScreenHeight / 2 );
		}
		gfx.DrawClosedPolyline(poly, c);
	}

private:
	Graphics& gfx;
};
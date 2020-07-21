#pragma once

#include "Vec2.h"
#include "Graphics.h"
#include "vector"
#include "Drawable.h"

class CoordinateTransformer
{
public:
	CoordinateTransformer(Graphics& gfx)
		:
		gfx(gfx)
	{}
	
	void Draw(Drawable& d)
	{
		d.Scale(1.0f, -1.0f); // flips the y axis
		d.Translate({ gfx.ScreenWidth / 2, gfx.ScreenHeight / 2 }); // puts the object in the middle of the coordinate system.
		d.Render(gfx);
	}

private:
	Graphics& gfx;
};
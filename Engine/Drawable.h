#pragma once

#include <vector>
#include "Vec2.h"
#include "Graphics.h"

class Drawable
{
public:
	Drawable(std::vector<Vec2> model, Color c)
		:
		model(std::move(model)),
		c(c)
	{
	}

	void Translate(const Vec2& translation_in)
	{
		translation += translation_in;
	}

	void Scale(const float scale_in)
	{
		scale_x *= scale_in;
		scale_y *= scale_in;
		translation *= scale_in;
	}

	void Scale(const float scale_x_in, const float scale_y_in)
	{
		scale_x *= scale_x_in;
		scale_y *= scale_y_in;
		translation.x *= scale_x_in;
		translation.y *= scale_y_in;
	}

	void Render(Graphics& gfx)
	{
		for (auto& v : model)
		{
			v.x *= scale_x;
			v.y *= scale_y;
			v += translation;
		}
		gfx.DrawClosedPolyline(model, c);
	}

private:
	std::vector<Vec2> model;
	Vec2 translation = { 0.0f, 0.0f };
	float scale_x = 1.0f;
	float scale_y = 1.0f;
	Color c;
};
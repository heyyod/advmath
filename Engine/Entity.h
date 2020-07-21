#pragma once

#include "Vec2.h"
#include <vector>

class Entity
{
public:
	Entity(std::vector<Vec2> model, const Vec2& pos = { 0.0f, 0.0f }, Color c = Colors::Yellow)
		:
		pos(pos),
		model(std::move(model)),
		c(c)
	{}

	void TranslateBy(Vec2 offset)
	{
		pos += offset;
	}

	void SetScale(float s)
	{
		scale *= s;
	}

	float GetScale() const
	{
		return scale;
	}

	Drawable GetDrawable() const
	{
		Drawable d(model, c);
		d.Scale(scale);
		d.Translate(pos);
		return d;
	}

private:
	float scale = 1.0f;
	Vec2 pos;
	std::vector<Vec2> model;
	Color c;
};
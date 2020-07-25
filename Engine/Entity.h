#pragma once

#include "Vec2.h"
#include <vector>

class Entity
{
public:
	Entity(std::vector<Vec2> model, const Vec2& pos = { 0.0f, 0.0f }, Color c = Colors::Red)
		:
		model(std::move(model)),
		pos(pos),
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

	void Shrink(float s)
	{
		scale -= s;
	}

	void Enlarge(float s)
	{
		scale += s;
	}

	Vec2 GetPos() const
	{
		return pos;
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
	std::vector<Vec2> model;
	Vec2 pos;
	Color c;
};
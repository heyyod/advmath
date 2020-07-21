#pragma once

#include "Vec2.h"
#include <vector>

class Entity
{
public:
	Entity(std::vector<Vec2> model, const Vec2& pos = { 0.0f, 0.0f })
		:
		pos(pos),
		model(std::move(model))
		
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
	std::vector<Vec2> GetPolyline()
	{
		auto poly = model;
		for (auto& i : poly)
		{
			i *= scale;
			i += pos;
		}
		return poly;
	}

private:
	float scale = 1.0f;
	Vec2 pos;
	std::vector<Vec2> model;
};
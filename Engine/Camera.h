#pragma once

#include "CoordinateTransformer.h"
#include "Vec2.h"

class Camera
{
public:
	Camera(CoordinateTransformer& ct)
		:
		model(std::move(model)),
		ct(ct)
	{
	}

	void MoveBy(const Vec2& offset)
	{
		pos += offset;
	}
	void MoveTo(const Vec2& pos_in)
	{
		pos = pos_in;
	}
	void SetScale(float s)
	{
		scale = s;
	}
	float GetScale() const
	{
		return scale;
	}
	void Draw(std::vector<Vec2> poly, Color c)
	{
		for (auto& i : poly)
		{
			i -= pos;
			i *= scale;
		}
		ct.DrawPolyline(std::move(poly), c);
	}

private:
	float scale = 1.0f;
	Vec2 pos = { 0.0f, 0.0f };
	CoordinateTransformer ct;
	std::vector<Vec2> model;
};
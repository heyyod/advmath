#pragma once

#include "CoordinateTransformer.h"
#include "Vec2.h"
#include "Drawable.h"

class Camera
{
public:
	Camera(CoordinateTransformer& ct)
		:
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
	void Draw(Drawable& d)
	{
		d.Translate(-pos);
		d.Scale(scale);
		ct.Draw(std::move(d));
	}

private:
	float scale = 1.0f;
	Vec2 pos = { 0.0f, 0.0f };
	CoordinateTransformer ct;
	std::vector<Vec2> model;
};
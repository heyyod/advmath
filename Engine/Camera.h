#pragma once

#include "Graphics.h"
#include "CoordinateTransformer.h"
#include "Vec2.h"
#include "Drawable.h"

class Camera
{
public:
	Camera(Graphics& gfx, CoordinateTransformer& ct)
		:
		gfx(gfx),
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
	void SetScale(float s, Vec2 mousePos)
	{
		// trying to zoom towards mouse pos
		Vec2 center(gfx.ScreenWidth / 2.0f, gfx.ScreenHeight / 2.0f);
		Vec2 camCenter = (mousePos - center) / 2;
		camCenter.y = -camCenter.y;
		MoveBy(camCenter);
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
	Graphics& gfx;
	std::vector<Vec2> model;
};
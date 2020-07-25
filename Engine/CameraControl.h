#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Camera.h"

class CameraControl
{
public:
	CameraControl(Mouse& mouse, Keyboard& kbd, Camera& cam)
		:
		mouse(mouse),
		kbd(kbd),
		cam(cam)
	{}

void Update()
	{
		float speed = 50.0f;
		if (kbd.KeyIsPressed(VK_UP))
		{
			cam.MoveBy({ 0.0f, speed });
		}
		if (kbd.KeyIsPressed(VK_DOWN))
		{
			cam.MoveBy({ 0.0f, -speed });
		}
		if (kbd.KeyIsPressed(VK_LEFT))
		{
			cam.MoveBy({ -speed, 0.0f });
		}
		if (kbd.KeyIsPressed(VK_RIGHT))
		{
			cam.MoveBy({ speed,0.0f });
		}

		while (!mouse.IsEmpty())
		{
			auto e = mouse.Read();
			switch (e.GetType())
			{
			case Mouse::Event::Type::LPress:
				lastPos = (Vec2)e.GetPos();
				engaged = true;
				break;
			case Mouse::Event::Type::LRelease:
				engaged = false;
				break;
			case Mouse::Event::Type::WheelUp:
				cam.SetScale(cam.GetScale() * zoomFactor);
				break;
			case Mouse::Event::Type::WheelDown:
				cam.SetScale(cam.GetScale() / zoomFactor);
				break;
			}

			if (engaged)
			{
				auto curPos = (Vec2)mouse.GetPos();
				auto delta = curPos - lastPos;
				delta.x = -delta.x;
				cam.MoveBy(delta / cam.GetScale());
				lastPos = curPos;
			}
		}
	}
private:
	float zoomFactor = 1.15f;
	bool engaged = false;
	Vec2 lastPos;
	Mouse& mouse;
	Keyboard& kbd;
	Camera& cam;
};
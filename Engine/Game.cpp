/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include <random>

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	ct( gfx ),
	cam(ct)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> flaresDistr(3, 8);
	std::uniform_real_distribution<> outterRadiusDistr(30.0f, 500.0f);
	std::uniform_real_distribution<> innerRadiusDistr(20.0f, 400.0f);
	std::uniform_real_distribution<> posXDistr(-10000.0f, 10000.0f);
	std::uniform_real_distribution<> posYDistr(-5000.0f, 5000.0f);

	//for(int i = 0; i < 2000; i++)
	while(entities.size() <= 500)
	{
		int flares = flaresDistr(gen);
		float outterRadius = (float) outterRadiusDistr(gen);
		float innerRadius = (float) innerRadiusDistr(gen);
		float posX = (float) posXDistr(gen);
		float posY = (float) posYDistr(gen);

		if (outterRadius < innerRadius)
		{
			std::swap(outterRadius, innerRadius);
		}

		Model m(Star::Make(outterRadius, innerRadius), outterRadius, outterRadius);
		Entity newEntity(m, Vec2(posX, posY));

		bool canPlace = true;
		for (auto& e : entities)
		{
			if (newEntity.Intesect(e))
			{
				canPlace = false;
				break;
			}
		}
		if (canPlace)
		{
			entities.emplace_back(newEntity);
		}
	}
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	float speed = 50.0f;
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		cam.MoveBy({0.0f, speed });
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		cam.MoveBy({ 0.0f, -speed });
	}
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		cam.MoveBy({ -speed, 0.0f });
	}
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		cam.MoveBy({ speed,0.0f });
	}
	
	while (!wnd.mouse.IsEmpty())
	{
		const auto e = wnd.mouse.Read();
		if (e.GetType() == Mouse::Event::Type::WheelUp)
		{
			cam.SetScale(cam.GetScale() * 1.15f);
		}
		if (e.GetType() == Mouse::Event::Type::WheelDown)
		{
			cam.SetScale(cam.GetScale() * 0.85f);
		}
	}
}

void Game::ComposeFrame()
{
	for (auto e : entities)
	{
		cam.Draw(e.GetDrawable());
		cam.Draw(
			Drawable({
			{e.left(), e.top()},
			{e.left(), e.bottom()},
			{e.right(), e.bottom()},
			{e.right(), e.top()} },
			Colors::Green)
			);
	}
}

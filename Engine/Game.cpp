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

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
	// Q2
	// (-2,1)
	if ((float)1 == ((6 / 9)*(-1) + 3))
	{
		OutputDebugStringA("(-2,1) is on the line y=(6/9)x+3\n");
	}
	else
	{
		OutputDebugStringA("(-2,1) is not on the line y=(6/9)x+3\n");
	}

	// (3,5)
	if ((float)5 == ((6 / 9)*(3) + 3))
	{
		OutputDebugStringA("(3,5) is on the line y=(6/9)x+3\n");
	}
	else
	{
		OutputDebugStringA("(3,5) is not on the line y=(6/9)x+3\n");
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
}

void Game::ComposeFrame()
{
	if (wnd.mouse.LeftIsPressed())
	{
		gfx.DrawLineSegment({ gfx.ScreenWidth / 2, gfx.ScreenHeight / 2 }, 
							(Vec2)wnd.mouse.GetPos(), 
							Colors::Yellow);
	}
	
	
	gfx.DrawClosedPolyline({ {10.0f, 10.0f}, {100.0f, 100.0f}, {200.0f, 25.0f}, {150.0f, 40.0f}, {50.0f, 5.0f} }, Colors::White);
}

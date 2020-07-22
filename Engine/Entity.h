#pragma once

#include "Vec2.h"
#include "Model.h"
#include <vector>

class Entity
{
public:
	Entity(Model model, const Vec2& pos = { 0.0f, 0.0f }, Color c = Colors::Red)
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

	Vec2 GetPos() const
	{
		return pos;
	}

	float GetScale() const
	{
		return scale;
	}

	std::vector<Vec2> GetVertices() const
	{
		return model.GetVertices();
	}

	float GetWidth() const
	{
		return model.GetWidth();
	}

	float GetHeight() const
	{
		return model.GetHeight();
	}

	Drawable GetDrawable() const
	{
		Drawable d(model.GetVertices(), c);
		d.Scale(scale);
		d.Translate(pos);
		return d;
	}

	float left() const
	{
		return (pos.x - GetWidth());
	}
	float right() const
	{
		return (pos.x + GetWidth());
	}
	float top() const
	{
		return (pos.y + GetHeight());
	}
	float bottom() const
	{
		return (pos.y - GetHeight());
	}

	bool Intesect(Entity e) const
	{
		bool result = false;
		if ((this->left() >= e.left() && this->right() <= e.right() && this->top() <= e.top() && this->bottom() >= e.bottom()) ||
			(this->left() <= e.left() && this->right() >= e.right() && this->top() >= e.top() && this->bottom() <= e.bottom()))
		{
			result = true;
		}
		else if (this->right() >= e.right() && this->left() <= e.left())
		{
			result = ((this->bottom() <= e.top() && this->bottom() >= e.bottom()) || (this->top() >= e.bottom() && this->top() <= e.top()));
		}
		else if (this->bottom() <= e.bottom() && this->top() >= e.top())
		{
			result = ((this->right() >= e.left() && this->right() <= e.right()) || (this->left() <= e.right() && this->left() >= e.left()));
		}
		else
		{
			result =
				(((this->right() >= e.left() && this->right() <= e.right()) || (this->left() <= e.right() && this->left() >= e.left())) &&
				((this->bottom() <= e.top() && this->bottom() >= e.bottom()) || (this->top() >= e.bottom() && this->top() <= e.top())));
		}
		return result;
	}

private:
	float scale = 1.0f;
	Model model;
	Vec2 pos;
	Color c;
};
#include "Table.hpp"

Table::Table()
{
	constructCircles();
}

void Table::update()
{
	// Update all circles
	for (auto& c : mTopRow)
	{
		c.update();
	}
	for (auto& c : mLeftColumn)
	{
		c.update();
	}
}

void Table::constructCircles()
{
	for (int i = 0; i < 6; ++i)
	{
		mTopRow.push_back(Circle(float(i + 1)));
		Circle& top = mTopRow.back();
		top.setPosition((i + 1.5f) * top.getRadius() * 2, top.getRadius());

		mLeftColumn.push_back(Circle(float(i + 1)));
		Circle& left = mLeftColumn.back();
		left.setPosition(top.getRadius(), (i + 1.5f) * top.getRadius() * 2);
	}
}

void Table::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (auto& i : mTopRow)
	{
		target.draw(i);
	}

	for (auto& i : mLeftColumn)
	{
		target.draw(i);
	}
}
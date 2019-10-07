#include "Table.hpp"

Table::Table()
{
	constructCircles();
}

void Table::update()
{
	// On (R) key press, reset all points
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		mPoints.clearPoints();
	}

	// Update all circles
	for (auto& c : mTopRow)
	{
		c.update();
	}
	for (auto& c : mLeftColumn)
	{
		c.update();
	}

	updateLines();
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

void Table::updateLines()
{
	mLines.clear();
	// For every upper circle
	for (auto& tc : mTopRow)
	{   // For every left circle.
		for (auto& lc : mLeftColumn)
		{
			// the two dot positions
			sf::Vector2f dotL = lc.getDotPos();
			sf::Vector2f dotT = tc.getDotPos();
			// the meeting point.
			sf::Vector2f meeting = { dotT.x, dotL.y };
			// add the two lines
			mLines.push_back(Line(dotT, meeting));
			mLines.push_back(Line(dotL, meeting));
			// add a point at the meeting points.
			mPoints.addPoint(meeting);
		}
	}
}

void Table::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (auto& i : mTopRow)
	{
		target.draw(i, states);
	}
	for (auto& i : mLeftColumn)
	{
		target.draw(i, states);
	}
	for (auto& i : mLines)
	{
		target.draw(i, states);
	}
	target.draw(mPoints, states);
	s
}
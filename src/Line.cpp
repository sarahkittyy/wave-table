#include <math.h>
#include "Line.hpp"

Line::Line()
	: mPt1(0, 0),
	  mPt2(0, 0)
{
	mLine.setPrimitiveType(sf::Lines);
	updateVertices();
}

void Line::updateVertices()
{
	mLine.clear();
	float length = std::hypot(mPt2.x - mPt1.x, mPt2.y - mPt1.y);
	for (float t = 0; t < length - DOT_SIZE; t += DOT_SIZE)
	{
		// Get the initial and next point.
		sf::Vector2f current = getPointBetween(t);
		sf::Vector2f next	= getPointBetween(t + DOT_SIZE);

		// Add a line from current to next.
		mLine.append(sf::Vertex(
			current,
			sf::Color(127, 127, 127, 127)));
		mLine.append(sf::Vertex(
			next,
			sf::Color(127, 127, 127, 127)));
	}
}

sf::Vector2f Line::getPointBetween(float t) const
{
	sf::Vector2f ret;

	ret.x = (mPt2.x - mPt1.x) * t;
	ret.y = (mPt2.y - mPt1.y) * t;

	return ret;
}

void Line::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mLine, states);
}
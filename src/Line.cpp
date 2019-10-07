#include <math.h>
#include "Line.hpp"

Line::Line(sf::Vector2f a, sf::Vector2f b)
	: mPt1(a),
	  mPt2(b)
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
		float percent_through	  = t / (length - DOT_SIZE);
		float percent_through_next = (t + 1) / (length - DOT_SIZE);
		// Get the initial and next point.
		sf::Vector2f current = getPointBetween(percent_through);
		sf::Vector2f next	= getPointBetween(percent_through_next);

		// Add a line from current to next.
		mLine.append(sf::Vertex(
			current,
			sf::Color(127, 127, 127)));
		mLine.append(sf::Vertex(
			next,
			sf::Color(127, 127, 127)));
	}
}

void Line::setPointA(sf::Vector2f a)
{
	mPt1 = a;
	updateVertices();
}

void Line::setPointB(sf::Vector2f b)
{
	mPt2 = b;
	updateVertices();
}

sf::Vector2f Line::getPointA() const
{
	return mPt1;
}

sf::Vector2f Line::getPointB() const
{
	return mPt2;
}

sf::Vector2f Line::getPointBetween(float t) const
{
	sf::Vector2f ret;

	ret.x = (mPt2.x - mPt1.x) * t;
	ret.y = (mPt2.y - mPt1.y) * t;

	return ret + mPt1;
}

void Line::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mLine, states);
}
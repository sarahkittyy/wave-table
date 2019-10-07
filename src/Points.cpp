#include "Points.hpp"

Points::Points()
{
	mVertices.setPrimitiveType(sf::Points);
}

void Points::clearPoints()
{
	mVertices.clear();
}

void Points::addPoint(sf::Vector2f pos)
{
	mVertices.append(sf::Vertex(pos, sf::Color::White));
}

void Points::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mVertices, states);
}
#include <cmath>
#include "Circle.hpp"

// Helper functions

double sigmoid(double x)
{
	return 1.0 / (1 + std::exp(-x));
}

sf::Vector2f centerOf(const sf::CircleShape& s)
{
	return sf::Vector2f(
		s.getLocalBounds().width / 2.f,
		s.getLocalBounds().height / 2.f);
}

//! Begin class def

Circle::Circle(float speed)
{
	mTime = sf::seconds(1 / speed);

	// Initialize the circles
	mDot.setFillColor(sf::Color::White);
	mDot.setRadius(RADIUS / 20);
	mDot.setOutlineThickness(0);
	mDot.setOrigin(centerOf(mDot));

	mCircle.setRadius(RADIUS);
	mCircle.setFillColor(sf::Color::Transparent);
	mCircle.setOutlineColor(redShift(speed));
	mCircle.setOutlineThickness(2);
	mCircle.setOrigin(centerOf(mCircle));
}

void Circle::update()
{
	sf::Time elapsed = mClock.getElapsedTime();
	// Parameterized curve parameter t goes from 0 -> 1 as the dot spins around the circle.
	float t = elapsed.asSeconds() / mTime.asSeconds();

	setDotPos(t);
}

void Circle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(mCircle, states);
	target.draw(mDot, states);
}

const float Circle::getRadius() const
{
	return RADIUS;
}

sf::Vector2f Circle::getDotPos() const
{
	return getTransform().transformPoint(mDot.getPosition());
}

sf::Color Circle::redShift(float speed) const
{
	float red_percent = sigmoid(speed);
	return sf::Color(red_percent * 255.f, 127, 127);
}

void Circle::setDotPos(float t)
{
	float x = RADIUS * std::sin(t);
	float y = RADIUS * std::cos(t);

	mDot.setPosition(x, y);
}

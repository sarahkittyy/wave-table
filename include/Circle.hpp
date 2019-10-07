#include <SFML/Graphics.hpp>

/**
 * @brief A circle with a point spinning around it.
 * 
 */
class Circle : public sf::Drawable, public sf::Transformable
{
public:
	/**
	 * @brief Construct the circle
	 * 
	 * @param speed The speed multiplier for the point that spins around the circle..
	 */
	Circle(float speed);

	/**
	 * @brief Update the circle. Call once per frame.
	 * 
	 */
	void update();

private:
	/// SFML draw override.
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	/// The main circle
	sf::CircleShape mCircle;
	/// The dot that rotates around the circle.
	sf::CircleShape mDot;
	/// The radius of the big circle.
	const float RADIUS = 100;

	/// Returns the redshift on the circle -- the faster the dot, the more red.
	sf::Color redShift(float speed);

	/// Sets the dot to a position 0 <= t <= 1, where t is the percentage around the circle.
	void setDotPos(float t);

	/// Internal clock for timing the circle spin speed.
	sf::Clock mClock;
	/// The time it takes for the point to spin around the circle once.
	sf::Time mTime;
};
#include <SFML/Graphics.hpp>

/**
 * @brief A simple line, going from one point to another.
 * 
 */
class Line : public sf::Drawable
{
public:
	Line(sf::Vector2f a = {0,0}, sf::Vector2f b = {0,0});

	void setPointA(sf::Vector2f a);
	void setPointB(sf::Vector2f b);

	sf::Vector2f getPointA() const;
	sf::Vector2f getPointB() const;

private:
	/// SFML draw override.
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	/// The two points of the line
	sf::Vector2f mPt1;
	sf::Vector2f mPt2;

	/// The line vertex array.
	sf::VertexArray mLine;
	/// Updates the vertex array given pt1 and pt2.
	void updateVertices();

	/// Returns the point interpolated between point a and b at t [0, 1]
	sf::Vector2f getPointBetween(float t) const;

	/// Size of dot to split the dotted line into.
	const float DOT_SIZE = 2;
};
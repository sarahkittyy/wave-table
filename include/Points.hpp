#include <SFML/Graphics.hpp>

/**
 * @brief Manages points on a plane.
 * 
 */
class Points : public sf::Drawable
{
public:
	Points();

	/// Add a point to the point manager.
	void addPoint(sf::Vector2f pos);
	/// Clear all points
	void clearPoints();

private:
	/// SFML draw() override.
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	/// All points attached to this object.
	sf::VertexArray mVertices;
};
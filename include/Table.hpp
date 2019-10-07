#include <SFML/Graphics.hpp>
#include <vector>
#include "Circle.hpp"
#include "Line.hpp"
#include "Points.hpp"

/**
 * @brief The waveform table class.
 * 
 */
class Table : public sf::Drawable
{
public:
	Table();

	/// Updates all animations.
	void update();

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	/// The top row of circles
	std::vector<Circle> mTopRow;
	/// The left column of circles.
	std::vector<Circle> mLeftColumn;
	/// The vector of lines attached to circles.
	std::vector<Line> mLines;
	/// All points drawn to the screen.
	Points mPoints;

	/// Constructs all twelve circles
	void constructCircles();
	/// Update all connecting lines.
	void updateLines();
};
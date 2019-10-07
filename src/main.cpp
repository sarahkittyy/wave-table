#include <SFML/Graphics.hpp>
#include "Circle.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "wave-table");

	//* App object init
	Circle c(1);
	c.setPosition({ 100, 100 });

	// App loop
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			default:
				break;
			case sf::Event::Closed:
				window.close();
				break;
			}
		}
		//* Updates
		c.update();

		//* Render
		window.clear(sf::Color(0x111111));
		window.draw(c);
		window.display();
	}

	return 0;
}
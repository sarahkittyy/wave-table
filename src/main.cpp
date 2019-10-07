#include <SFML/Graphics.hpp>
#include "Table.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(700, 700), "wave-table");

	//* App object init
	Table t;

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
		//* Update
		t.update();

		//* Render
		window.clear(sf::Color(0x111111));
		window.draw(t);
		window.display();
	}

	return 0;
}
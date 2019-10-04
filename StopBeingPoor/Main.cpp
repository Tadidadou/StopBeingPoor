#include "Map.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), WINDOW_TITLE);
	
	/*Map map;
	sf::Sprite mapSprite;
	mapSprite = map.DrawMap("test_texture.jpg");
	mapSprite.setPosition(10, 10);*/

	// Test 
	sf::Texture texture;
	std::string filename = TEXTURE_FILES_PREFIX + "test_texture.jpg";
	if (!texture.loadFromFile(filename, sf::IntRect(0, 0, 1000, 150))) {
		std::cout << "Error loading texture file" + filename << std::endl;
	}

	sf::Sprite sprite;
	sprite.setTexture(texture);
	int x = -100;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed) 
			{
				if (event.key.code == sf::Keyboard::Left)
					x+=10;
				else if (event.key.code == sf::Keyboard::Right)
					x-=10;
			}
		}

		sprite.setPosition(x, 250);
		window.clear();
		//window.draw(mapSprite);
		window.draw(sprite);
		window.display();
	}

	return 0;
}
#include "Map.h"
#include "CharacterManager.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), WINDOW_TITLE);
	window.setFramerateLimit(WINDOW_FRAMERATE);
	
	Map map;
	int pos = WINDOW_SIZE_X / 2 - MAP_SIZE_X / 2;
	float movement = 0;
	map.SetPosition(pos);
	map.SetGroundTexture("Foreground/Tileset.png");
	map.SetBackgroundTexture("Background/BGFront.png");

	CharacterManager charManager;
	charManager.CreateCharacter("main", "Characters/test-character.png", ALIVE, sf::Vector2f(400, WINDOW_SIZE_Y - HEIGHT_OF_GROUND - 28));

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
					movement = -MOVING_SPEED;
				else if (event.key.code == sf::Keyboard::Right)
					movement = MOVING_SPEED;
			}
			else if (event.type == sf::Event::KeyReleased)
				movement = 0;
		}

		// Move the map
		map.Scroll(movement);
		charManager.GetCharacter("main")->Move(movement);

		window.clear();
		window.draw(map);
		/*Character* mainPersoPtr = charManager.GetCharacter("main");
		Character mainPerso = *mainPersoPtr;
		window.draw(mainPerso);*/
		window.draw(charManager);
		window.display();
	}

	return 0;
}
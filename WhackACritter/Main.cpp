#include <SFML/Graphics.hpp>
#include <cstdlib> //gives access to random functions
#include <ctime>   //gives access to time functions

//project includes
#include "Critter.h"



int main()
{
	// Make a variable called gameWindow of type RenderWindow
	sf::RenderWindow gameWindow;
	gameWindow.create(sf::VideoMode::getDesktopMode(), "WhackACritter",
		sf::Style::Titlebar | sf::Style::Close);
	sf::Clock gameClock;

	//seed our random number generator
	srand(time(NULL));

	//Create an instance of our critter class
	Critter myCritter;

	while (gameWindow.isOpen())
	{

		//----------------------------------------------------
		//Input
		//----------------------------------------------------
		sf::Event event;
		while (gameWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				gameWindow.close();
			}//End if (closed)
		}//end event polling loop

		//----------------------------------------------------
		//End input
		//----------------------------------------------------
		sf::Time frameTime = gameClock.restart();

		//clear the window to a single colour
		gameWindow.clear();

		//draw everything
		myCritter.Draw(gameWindow);

		//display the windows contents to the screen
		gameWindow.display();

		//end draw
	}//end of the game while loop

	return 0;
}

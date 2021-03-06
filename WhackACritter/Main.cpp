#include <SFML/Graphics.hpp>
#include <cstdlib> //gives access to random functions
#include <ctime>   //gives access to time functions
#include <string> //gives acces to string functions

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
	myCritter.Setup("graphics/gorilla.png", 10);

	Critter secondCritter;
	secondCritter.Setup("graphics/pig.png", 5);

	const int NUM_CRITTERS = 5;
	Critter critters[NUM_CRITTERS];
	critters[0].Setup("graphics/gorilla.png", 10);
	critters[1].Setup("graphics/pig.png", 5);
	critters[2].Setup("graphics/whale.png", 20);
	critters[3].Setup("graphics/zebra.png", 15);
	critters[4].Setup("graphics/hippo.png", 1);

	//game font
	sf::Font gameFont;
	gameFont.loadFromFile("fonts/mainFont.ttf");

	//Score tracking
	int score = 0;
	sf::Text scoreText;
	scoreText.setFont(gameFont);
	scoreText.setString("Score: " + std::to_string(score));
	scoreText.setCharacterSize(50);
	scoreText.setFillColor(sf::Color::Red);
	scoreText.setPosition(50, 50);

	while (gameWindow.isOpen())
	{

		//----------------------------------------------------
		//Input
		//----------------------------------------------------
		sf::Event event;
		while (gameWindow.pollEvent(event))
		{
			//process input on critters
			
			for (int i = 0; i < NUM_CRITTERS; ++i)
			{
				critters[i].Input(event);
			}

			if (event.type == sf::Event::Closed)
			{
				gameWindow.close();
			}//End if (closed)
		}//end event polling loop

		//----------------------------------------------------
		//End input
		//----------------------------------------------------
		sf::Time frameTime = gameClock.restart();

		//see if there is any pending score
		for (int i = 0; i < NUM_CRITTERS; ++i)
		{
			score += critters[i].GetPendingScore();
			critters[i].ClearPendingScore();
		}
	

		score += secondCritter.GetPendingScore();
		secondCritter.ClearPendingScore();

		scoreText.setString("Score: " + std::to_string(score));

		//clear the window to a single colour
		gameWindow.clear();

		//draw everything
		for (int i = 0; i < NUM_CRITTERS; ++i)
		{
			critters[i].Draw(gameWindow);
		}
		gameWindow.draw(scoreText);

		//display the windows contents to the screen
		gameWindow.display();

		//end draw
	}//end of the game while loop

	return 0;
}

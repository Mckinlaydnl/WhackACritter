#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Critter
{

    //-------------------------------------
	//Behaviour
	//-------------------------------------

public:
	//constructor
	Critter();

	//Render the critter to the target
	void Draw(sf::RenderTarget & _target);

	//process input on the critter
	void Input(sf::Event _gameEvent);

	//Get pending score data
	int GetPendingScore();

	//clear the pending score
	void ClearPendingScore();

	//End Behaviour
	//-------------------------------------

	//-------------------------------------
	//Data
	//-------------------------------------

private:
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	bool m_alive;
	sf::Sound m_deathSound;
	sf::SoundBuffer m_deathBuffer;
	int m_pendingScore;

	//end data
	//-------------------------------------
};//end critter class
#pragma once

#include <SFML/Graphics.hpp>


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

	//End Behaviour
	//-------------------------------------

	//-------------------------------------
	//Data
	//-------------------------------------

private:
	sf::Sprite m_sprite;
	sf::Texture m_texture;

	//end data
	//-------------------------------------
};//end critter class
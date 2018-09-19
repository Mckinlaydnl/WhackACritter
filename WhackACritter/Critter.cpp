
//------------------------------
//Includes
//------------------------------

//Library includes
#include<cstdlib>

//Project includes
#include "Critter.h";

Critter::Critter()

//initialisation list
	: m_sprite()
	, m_texture()
	, m_alive(true)
	, m_deathSound()
	, m_deathBuffer()
	, m_pendingScore(0)
	, m_scoreValue(1)
{

	//set up the death sound
	m_deathBuffer.loadFromFile("audio/death.ogg");
	m_deathSound.setBuffer(m_deathBuffer);
}




void Critter::Draw(sf::RenderTarget & _target)
{
	if (m_alive)
	{
		_target.draw(m_sprite);
	}
}


void Critter::Input(sf::Event _gameEvent)
{
	if (m_alive)
	{
		//check if mouse is clicked
		if (_gameEvent.type == sf::Event::MouseButtonPressed)
		{
			//check if they clicked on the critter
			if (m_sprite.getGlobalBounds().contains(_gameEvent.mouseButton.x, _gameEvent.mouseButton.y))
			{
				//The player clicked the critter

				//We die
				m_alive = false;

				//play the death sound
				m_deathSound.play();

				//Add to pending score 
				m_pendingScore += m_scoreValue;

			}


		}//end if statement
	}
}

int Critter::GetPendingScore()
{
	return m_pendingScore;
}

void Critter::ClearPendingScore()
{
	m_pendingScore = 0;
}

void Critter::Setup(std::string _textureFile, int _pointValue)
{
	m_texture.loadFromFile(_textureFile);
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(rand() % sf::VideoMode::getDesktopMode().width,
		rand() % sf::VideoMode::getDesktopMode().height);

	m_scoreValue = _pointValue;
}
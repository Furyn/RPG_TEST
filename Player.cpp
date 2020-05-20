#include "Player.h"
#include "Inventaire.h"

Player::Player(std::string name, ClassCharacter _classCharacter) : Character(name,_classCharacter) {
	this->inventaire = new Inventaire();
	this->circlePlayer.setRadius(15);
	this->circlePlayer.setOrigin(this->circlePlayer.getRadius(),this->circlePlayer.getRadius());
}

void Player::UpdatePosPlayer(int posX, int posY)
{
	this->circlePlayer.setPosition( this->circlePlayer.getPosition() + *new sf::Vector2f(posX,posY) );
}

void Player::Display(sf::RenderWindow* window)
{
	window->draw(this->circlePlayer);
}

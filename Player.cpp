#include "Player.h"
#include "Inventaire.h"

Player::Player(std::string name, ClassCharacter _classCharacter) : Character(name,_classCharacter) {
	this->inventaire = new Inventaire();
}

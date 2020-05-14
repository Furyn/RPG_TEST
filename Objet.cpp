#include "Objet.h"

Objet::Objet(std::string _name, CATEGORIE_OBJET _category, int valueOfBonusStats)
{
	this->name = _name;
	this->category = _category;

	switch (_category)
	{
	case CATEGORIE_OBJET::POTION_VIE:
		this->maxQuantityInInventory = 10;
		break;
	case CATEGORIE_OBJET::POTION_MANA:
		this->maxQuantityInInventory = 10;
		break;
	case CATEGORIE_OBJET::EQUIPEMENT_PLASTRON:
		this->maxQuantityInInventory = 1;
		break;
	case CATEGORIE_OBJET::EQUIPEMENT_CASQUE:
		this->maxQuantityInInventory = 1;
		break;
	case CATEGORIE_OBJET::EQUIPEMENT_GANT:
		this->maxQuantityInInventory = 1;
		break;
	case CATEGORIE_OBJET::EQUIPEMENT_BOTTE:
		this->maxQuantityInInventory = 1;
		break;
	case CATEGORIE_OBJET::EQUIPEMENT_ARME:
		this->maxQuantityInInventory = 1;
		break;
	default:
		this->maxQuantityInInventory = 0;
		break;
	}

	this->quantityInInventory = 1;
	this->circle.setRadius(10);
	this->circle.setOrigin(this->circle.getRadius(), this->circle.getRadius());
}

void Objet::Display(sf::RenderWindow* window)
{
	window->draw(this->circle);
}

void Objet::UpdatePosToDisplay(float posX, float posY)
{
	this->circle.setPosition(posX, posY);
}
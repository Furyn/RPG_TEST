#include "CaseInventaie.h"
#include "Objet.h"

CaseInventaire::CaseInventaire()
{
	this->objetInCase = nullptr;
	this->contoureCase.setSize(sf::Vector2f(75, 75));
	this->contoureCase.setOutlineColor(sf::Color::Red);
	this->contoureCase.setOutlineThickness(3);
	this->contoureCase.setFillColor(sf::Color::Black);
	this->contoureCase.setOrigin(this->contoureCase.getSize().x / 2, this->contoureCase.getSize().y / 2);
}

void CaseInventaire::UpdatePose(float posX, float posY)
{
	this->contoureCase.setPosition(posX,posY);
	if (objetInCase != nullptr) {
		this->objetInCase->UpdatePosToDisplay(posX,posY);
	}
}

void CaseInventaire::Display(sf::RenderWindow* window)
{
	window->draw(this->contoureCase);
	if (this->objetInCase != nullptr) {
		this->objetInCase->Display(window);
	}
}

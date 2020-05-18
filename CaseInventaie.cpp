#include "CaseInventaie.h"
#include "Objet.h"
#include "GameManager.h"

CaseInventaire::CaseInventaire()
{
	this->objetInCase = nullptr;
	this->contoureCase.setSize(sf::Vector2f(75, 75));
	this->contoureCase.setOutlineColor(sf::Color::Red);
	this->contoureCase.setOutlineThickness(3);
	this->contoureCase.setFillColor(sf::Color::Black);
	this->contoureCase.setOrigin(this->contoureCase.getSize().x / 2, this->contoureCase.getSize().y / 2);
	this->pFunctionToExecuteOnClick = nullptr;
}

void CaseInventaire::UpdatePose(float posX, float posY)
{
	this->contoureCase.setPosition(posX, posY);
	if (objetInCase != nullptr) {
		this->objetInCase->UpdatePosToDisplay(posX, posY);
	}
}

void CaseInventaire::CheckOnHover(sf::Vector2f positionMouse)
{
	float maxRectX = this->contoureCase.getPosition().x + this->contoureCase.getSize().x / 2;
	float maxRectY = this->contoureCase.getPosition().y + this->contoureCase.getSize().y / 2;

	float minRectX = this->contoureCase.getPosition().x - this->contoureCase.getSize().x / 2;
	float minRectY = this->contoureCase.getPosition().y - this->contoureCase.getSize().y / 2;

	if ((positionMouse.x < maxRectX && positionMouse.x > minRectX) && (positionMouse.y > minRectY && positionMouse.y < maxRectY)) {
		this->onHover = true;
	}
	else {
		this->onHover = false;
	}
}

void CaseInventaire::OnClick(GameManager* game, Objet* objetToEquipe)
{
	if (onHover && isVisible && pFunctionToExecuteOnClick != nullptr && (*pFunctionToExecuteOnClick)(game, objetToEquipe)) {
		game->player->inventaire->RemoveObjet(objetToEquipe);
	}
}

void CaseInventaire::Display(sf::RenderWindow* window)
{
	window->draw(this->contoureCase);
	if (this->objetInCase != nullptr) {
		this->objetInCase->Display(window);
	}
}

#include "UIInventaire.h"
#include "UIStats.h"
#include "GameManager.h"

UIInventaire::UIInventaire(sf::Font* fontForText)
{

	this->statsPlayer = new UIStats(fontForText);
	this->bordureInventaire.setSize(sf::Vector2f(1200, 800));
	this->bordureInventaire.setOutlineColor(sf::Color::Red);
	this->bordureInventaire.setOutlineThickness(3);
	this->bordureInventaire.setFillColor(sf::Color::Black);
	this->bordureInventaire.setOrigin(this->bordureInventaire.getSize().x / 2, this->bordureInventaire.getSize().y / 2);

	for (int i = 0; i < this->nombreCaseInventaire; i++)
	{
		this->listeCaseInventaire.push_back(new CaseInventaire());
	}

}

void UIInventaire::UpdatePosAllCase(float posX, float posY)
{
	this->bordureInventaire.setPosition(posX, posY);

	int nombreCaseParcourue = 0;
	std::list<CaseInventaire*>::iterator it = this->listeCaseInventaire.begin();
	float lastPosX = this->bordureInventaire.getPosition().x - this->bordureInventaire.getSize().x / 2;
	float lastPosY = this->bordureInventaire.getPosition().y - this->bordureInventaire.getSize().y / 2;
	while (it != this->listeCaseInventaire.end()) {
		if (nombreCaseParcourue % nombreCaseInLigne == 0) {
			lastPosY += (*it)->contoureCase.getSize().x + (*it)->contoureCase.getOutlineThickness();
			lastPosX = this->bordureInventaire.getPosition().x - this->bordureInventaire.getSize().x / 2 + (*it)->contoureCase.getSize().x + this->bordureInventaire.getOutlineThickness();
		}
		else {
			lastPosX += (*it)->contoureCase.getSize().x + this->bordureInventaire.getOutlineThickness();
		}
		(*it)->UpdatePose(lastPosX, lastPosY);
		nombreCaseParcourue++;
		it++;
	}
}

void UIInventaire::UpdateUI(GameManager* game)
{
	statsPlayer->UpdateTextUI(game->player);
}

void UIInventaire::UpdatePos(float posX, float posY)
{
	this->statsPlayer->UpdatePosUi(posX + this->bordureInventaire.getSize().x / 2.5f, posY + this->bordureInventaire.getSize().y / 4.5f );
	this->UpdatePosAllCase(posX, posY);
}

void UIInventaire::DisplayUi(sf::RenderWindow* window)
{
	window->draw(this->bordureInventaire);
	statsPlayer->DisplayUi(window, true);
	std::list<CaseInventaire*>::iterator it = this->listeCaseInventaire.begin();
	while (it != this->listeCaseInventaire.end()) {
		(*it)->Display(window);
		it++;
	}
}
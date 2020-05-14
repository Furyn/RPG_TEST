#include "UIInventaire.h"

UIInventaire::UIInventaire(sf::Font* fontForText)
{
	this->bordureInventaire.setSize(sf::Vector2f(900, 500));
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
	while (it != this->listeCaseInventaire.end()) {
		nombreCaseParcourue++;
		if (nombreCaseParcourue % 3 == 0) {
			(*it)->UpdatePose(this->bordureInventaire.getPosition().x - this->bordureInventaire.getSize().x / 2 + this->bordureInventaire.getOutlineThickness(), this->bordureInventaire.getPosition().y - this->bordureInventaire.getSize().y / 2 + this->bordureInventaire.getOutlineThickness());
		}
		else if (nombreCaseParcourue % 3 == 1) {
			(*it)->UpdatePose(this->bordureInventaire.getPosition().x - this->bordureInventaire.getSize().x / 2 + this->bordureInventaire.getOutlineThickness() + (*it)->contoureCase.getSize().x + (*it)->contoureCase.getOutlineThickness(), this->bordureInventaire.getPosition().y - this->bordureInventaire.getSize().y / 2 + this->bordureInventaire.getOutlineThickness());
		}
		else {
			(*it)->UpdatePose(this->bordureInventaire.getPosition().x - this->bordureInventaire.getSize().x / 2 + this->bordureInventaire.getOutlineThickness() + 2 * ((*it)->contoureCase.getSize().x + (*it)->contoureCase.getOutlineThickness()), this->bordureInventaire.getPosition().y - this->bordureInventaire.getSize().y / 2 + this->bordureInventaire.getOutlineThickness());
		}
		it++;
	}
}

void UIInventaire::DisplayUi(sf::RenderWindow* window)
{
	window->draw(this->bordureInventaire);

	std::list<CaseInventaire*>::iterator it = this->listeCaseInventaire.begin();
	while (it != this->listeCaseInventaire.end()) {
		(*it)->Display(window);
		it++;
	}
}
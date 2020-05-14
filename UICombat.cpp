#include "UICombat.h"
#include "ButtonInteraction.h"
#include "Button.h"

UICombat::UICombat(sf::Font* fontForText) : fontForText(fontForText){

	this->rectOfAllText.setSize(sf::Vector2f(700, 520));
	this->rectOfAllText.setOutlineColor(sf::Color::Red);
	this->rectOfAllText.setOutlineThickness(3);
	this->rectOfAllText.setFillColor(sf::Color::Transparent);
	this->rectOfAllText.setOrigin(this->rectOfAllText.getSize().x / 2, this->rectOfAllText.getSize().y / 2);

	this->listAllButton["ButtonAttaqueNormale"] = new Button(300, 70, 500, 500, "ATTAQUE NORMALE", 20, sf::Color(51, 51, 255), sf::Color(153, 163, 164), fontForText, buttonInteraction::AttaqueNormale, nullptr);
	this->listAllButton["ButtonAttaqueDesespere"] = new Button(300, 70, 500, 500, "ATTAQUE DESESPERE", 20, sf::Color(51, 51, 255), sf::Color(153, 163, 164), fontForText, buttonInteraction::AttaqueDesespere, nullptr);
	this->listAllButton["ButtonAttaqueMagique"] = new Button(300, 70, 500, 500, "ATTAQUE MAGIQUE", 20, sf::Color(51, 51, 255), sf::Color(153, 163, 164), fontForText, buttonInteraction::AttaqueMagique, buttonInteraction::CheckForAttaqueMagique);
	this->listAllButton["ButtonPotionDeVie"] = new Button(300, 70, 500, 500, "POTION DE VIE", 20, sf::Color(51, 51, 255), sf::Color(153, 163, 164), fontForText, buttonInteraction::PotionDeVie, buttonInteraction::CheckForPotionDeVie);
	this->listAllButton["ButtonPotionDeMana"] = new Button(300, 70, 500, 500, "POTION DE MANA", 20, sf::Color(51, 51, 255), sf::Color(153, 163, 164), fontForText, buttonInteraction::PotionDeMana, buttonInteraction::CheckForPotionDeMana);

}

void UICombat::AddText(std::string textToAdd)
{
	sf::Text* newText = new sf::Text(textToAdd, *this->fontForText, 20);

	newText->setOrigin(newText->getGlobalBounds().width / 2, newText->getGlobalBounds().height / 2);

	listAllTextToDisplay.push_back(newText);
}

void UICombat::RemoveFirstText()
{
	listAllTextToDisplay.pop_front();
}

void UICombat::RemoveAllText()
{
	this->listAllTextToDisplay.clear();
}


void UICombat::UpdatePosUi(sf::RenderWindow* window, float posX, float posY)
{
	this->rectOfAllText.setPosition(sf::Vector2f(posX, posY));

	float lastPosY = posY - this->rectOfAllText.getSize().y / 2;
	float newPosY;

	int i = 0;

	//Ligne 1 choix des attaques
	this->listAllButton["ButtonAttaqueNormale"]->UpdatePos(window->getSize().x * 0.25, window->getSize().y * 0.70);
	this->listAllButton["ButtonAttaqueMagique"]->UpdatePos(window->getSize().x * 0.50, window->getSize().y * 0.70);
	this->listAllButton["ButtonAttaqueDesespere"]->UpdatePos(window->getSize().x * 0.75, window->getSize().y * 0.70);
	//Ligne 2 choix des potions
	this->listAllButton["ButtonPotionDeVie"]->UpdatePos(window->getSize().x * 0.375, window->getSize().y * 0.80);
	this->listAllButton["ButtonPotionDeMana"]->UpdatePos(window->getSize().x * 0.625, window->getSize().y * 0.80);

	std::list<sf::Text*>::iterator it = listAllTextToDisplay.begin();
	while (it != listAllTextToDisplay.end()) {
		i++;

		newPosY = lastPosY + 45 + (*it)->getGlobalBounds().height / 2;

		if (newPosY > posY + this->rectOfAllText.getSize().y / 2) {
			this->RemoveFirstText();
			this->UpdatePosUi(window,posX,posY);
			return;
		}

		if (i == 1) {
			newPosY = lastPosY + (*it)->getGlobalBounds().height / 2;
		}

		(*it)->setPosition(posX, newPosY);
		lastPosY = newPosY + (*it)->getGlobalBounds().height / 2;
		it++;
	}

}

void UICombat::DisplayUi(sf::RenderWindow* window)
{
	window->draw(this->rectOfAllText);

	std::list<sf::Text*>::iterator it = listAllTextToDisplay.begin();
	while (it != listAllTextToDisplay.end()) {
		window->draw(*(*it));
		it++;
	}

	if (this->afficherOptionsCombats) {
		std::map<std::string, Button*>::iterator it2 = listAllButton.begin();
		while (it2 != listAllButton.end()) {
			(*it2).second->DisplayButton(window);
			(*it2).second->isVisible = true;
			it2++;
		}
	}
	
}

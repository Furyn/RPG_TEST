#include "UIStats.h"
#include "Character.h"

using namespace std;

UIStats::UIStats(sf::Font* fontForText)
{
	this->rectDisplayArea.setSize(sf::Vector2f(500, 165));
	this->rectDisplayArea.setOutlineColor(sf::Color::Red);
	this->rectDisplayArea.setOutlineThickness(3);
	this->rectDisplayArea.setFillColor(sf::Color::Transparent);
	this->rectDisplayArea.setOrigin(this->rectDisplayArea.getSize().x, 0);

	this->nameClasse.setFont(*fontForText);
	this->textLife.setFont(*fontForText);
	this->textMana.setFont(*fontForText);
	this->textArmor.setFont(*fontForText);
	this->textDexterity.setFont(*fontForText);
	this->textForce.setFont(*fontForText);
	this->textIntelligence.setFont(*fontForText);
	this->textLuck.setFont(*fontForText);

	this->nameClasse.setCharacterSize(20);
	this->textLife.setCharacterSize(20);
	this->textMana.setCharacterSize(20);
	this->textArmor.setCharacterSize(20);
	this->textDexterity.setCharacterSize(20);
	this->textForce.setCharacterSize(20);
	this->textIntelligence.setCharacterSize(20);
	this->textLuck.setCharacterSize(20);
}

void UIStats::UpdateTextUI(Character* character)
{

	switch (character->classCharacter)
	{
	case ClassCharacter::Warrior:
		this->nameClasse.setString("Warrior");
		break;
	case ClassCharacter::Mage:
		this->nameClasse.setString("Mage");
		break;
	case ClassCharacter::Priest:
		this->nameClasse.setString("Priest");
		break;
	case ClassCharacter::Assassin:
		this->nameClasse.setString("Assasin");
		break;
	case ClassCharacter::Ranger:
		this->nameClasse.setString("Ranger");
		break;
	case ClassCharacter::Knight:
		this->nameClasse.setString("Knight");
		break;
	default:
		this->nameClasse.setString("Error");
		break;
	}

	this->textLife.setString("HEALTH : " + to_string(character->life) + "/" + to_string(character->maxLife));
	this->textMana.setString("MANA : " + to_string(character->mana));
	this->textArmor.setString("ARMOR : " + to_string(character->armor));
	this->textDexterity.setString("DEXTERITY : " + to_string(character->critical));
	this->textForce.setString("POWER : " + to_string(character->force));
	this->textIntelligence.setString("INTELLIGENCE : " + to_string(character->intelligence));
	this->textLuck.setString("LUCK : " + to_string(character->luck));
}

void UIStats::UpdatePosUi(float posX, float posY)
{
	this->rectDisplayArea.setPosition(sf::Vector2f(posX,posY));
	this->nameClasse.setPosition(this->rectDisplayArea.getPosition() - sf::Vector2f(this->rectDisplayArea.getSize().x - this->rectDisplayArea.getOutlineThickness() * 4, -this->rectDisplayArea.getOutlineThickness() * 2));
	this->textLife.setPosition(this->nameClasse.getPosition() + sf::Vector2f(0, this->nameClasse.getGlobalBounds().height * 2));
	this->textMana.setPosition(this->textLife.getPosition() + sf::Vector2f(0, this->textLife.getGlobalBounds().height * 2));
	this->textForce.setPosition(this->textMana.getPosition() + sf::Vector2f(0, this->textMana.getGlobalBounds().height * 2));
	this->textArmor.setPosition(this->textForce.getPosition() + sf::Vector2f(0, this->textForce.getGlobalBounds().height * 2));
	this->textDexterity.setPosition(this->textMana.getPosition() + sf::Vector2f(this->rectDisplayArea.getSize().x / 2, 0));
	this->textIntelligence.setPosition(this->textDexterity.getPosition() + sf::Vector2f(0, this->textDexterity.getGlobalBounds().height * 2));
	this->textLuck.setPosition(this->textIntelligence.getPosition() + sf::Vector2f(0, this->textIntelligence.getGlobalBounds().height * 2));
}

void UIStats::DisplayUi(sf::RenderWindow* window, bool afficherAllStats)
{
	window->draw(this->rectDisplayArea);
	window->draw(this->nameClasse);
	window->draw(this->textLife);
	window->draw(this->textMana);

	if (afficherAllStats) {
		window->draw(this->textForce);
		window->draw(this->textArmor);
		window->draw(this->textDexterity);
		window->draw(this->textIntelligence);
		window->draw(this->textLuck);
	}
	else {
		this->rectDisplayArea.setSize(sf::Vector2f(250, 100));
		this->rectDisplayArea.setOrigin(this->rectDisplayArea.getSize().x, 0);
	}
}

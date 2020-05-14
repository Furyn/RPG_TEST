#include "UI.h"
#include "GameManager.h"
#include "Button.h"
#include "UIStats.h"

using namespace std;

UI::UI(sf::Font* fontForText)
{
	this->statsEnemi = new UIStats(fontForText);
	this->combat = new UICombat(fontForText);
	this->inventaire = new UIInventaire(fontForText);

	this->rectDisplayArea.setSize(sf::Vector2f(250, 100));
	this->rectDisplayArea.setOutlineColor(sf::Color::Red);
	this->rectDisplayArea.setOutlineThickness(3);
	this->rectDisplayArea.setFillColor(sf::Color::Transparent);
	this->rectDisplayArea.setOrigin(this->rectDisplayArea.getSize().x, 0);

	this->nameClasse.setFont(*fontForText);
	this->textLife.setFont(*fontForText);
	this->textMana.setFont(*fontForText);

	this->nameClasse.setCharacterSize(20);
	this->textLife.setCharacterSize(20);
	this->textMana.setCharacterSize(20);
}

void UI::UpdateUI(GameManager* game)
{

	switch (game->player->classCharacter)
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

	this->textLife.setString("HEALTH : " + to_string(game->player->life) + "/" + to_string(game->player->maxLife));
	this->textMana.setString("MANA : " + to_string(game->player->mana));

	if (game->combat->enemie != nullptr) {
		statsEnemi->UpdateTextUI(game->combat->enemie);
	}
}

void UI::CheckHoverButton(sf::Vector2f positionMouse, GameManager* game)
{
	std::map<std::string, Button*>::iterator it = this->combat->listAllButton.begin();
	while (it != this->combat->listAllButton.end()) {
		(*it).second->CheckOnHover(positionMouse);
		(*it).second->OnHover(sf::Color::Blue, sf::Color(61, 219, 46), game);
		it++;
	}
}

void UI::AddTextOnCombatScreen(std::string textToAdd)
{
	this->combat->AddText(textToAdd);
}

void UI::ClearTextOnCombatScreen()
{
	this->combat->RemoveAllText();
}

void UI::UpdatePosUi(sf::RenderWindow* window)
{
	this->statsEnemi->UpdatePosUi(this->statsEnemi->rectDisplayArea.getOutlineThickness() + this->statsEnemi->rectDisplayArea.getSize().x, this->statsEnemi->rectDisplayArea.getOutlineThickness());
	this->combat->UpdatePosUi(window, window->getSize().x / 2, window->getSize().y / 3);
	this->inventaire->UpdatePos(window->getSize().x / 2, window->getSize().y / 2);
	this->rectDisplayArea.setPosition(sf::Vector2f(window->getSize().x - this->rectDisplayArea.getOutlineThickness(), this->rectDisplayArea.getOutlineThickness()));
	this->nameClasse.setPosition(this->rectDisplayArea.getPosition() - sf::Vector2f(this->rectDisplayArea.getSize().x - this->rectDisplayArea.getOutlineThickness() * 4, -this->rectDisplayArea.getOutlineThickness() * 2));
	this->textLife.setPosition(this->nameClasse.getPosition() + sf::Vector2f(0, this->nameClasse.getGlobalBounds().height * 2));
	this->textMana.setPosition(this->textLife.getPosition() + sf::Vector2f(0, this->textLife.getGlobalBounds().height * 2));
}

void UI::DisplayUi(sf::RenderWindow* window, bool fightInProgress)
{
	
	window->draw(this->rectDisplayArea);
	window->draw(this->nameClasse);
	window->draw(this->textLife);
	window->draw(this->textMana);

	if (fightInProgress) {
		this->combat->DisplayUi(window);
		statsEnemi->DisplayUi(window, false);
	}

	if (this->afficherInventairePlayer) {
		this->inventaire->DisplayUi(window);
	}
}

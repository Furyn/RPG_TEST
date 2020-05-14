#include "UI.h"
#include "GameManager.h"
#include "Button.h"
#include "UIStats.h"

using namespace std;

UI::UI(sf::Font* fontForText)
{
	this->statsPlayer = new UIStats(fontForText);
	this->statsEnemi = new UIStats(fontForText);
	this->combat = new UICombat(fontForText);
	this->inventaire = new UIInventaire(fontForText);
}

void UI::UpdateUI(GameManager* game)
{
	statsPlayer->UpdateTextUI(game->player);
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
	this->statsPlayer->UpdatePosUi(window->getSize().x - this->statsPlayer->rectDisplayArea.getOutlineThickness(), this->statsPlayer->rectDisplayArea.getOutlineThickness());
	this->statsEnemi->UpdatePosUi(this->statsEnemi->rectDisplayArea.getOutlineThickness() + this->statsEnemi->rectDisplayArea.getSize().x, this->statsEnemi->rectDisplayArea.getOutlineThickness());
	this->combat->UpdatePosUi(window, window->getSize().x / 2, window->getSize().y / 3);
	this->inventaire->UpdatePosAllCase(window->getSize().x / 2, window->getSize().y / 2);
}

void UI::DisplayUi(sf::RenderWindow* window, bool fightInProgress)
{
	statsPlayer->DisplayUi(window, this->afficherStatsPlayer);
	if (fightInProgress) {
		this->combat->DisplayUi(window);
		statsEnemi->DisplayUi(window, false);
	}

	if (this->afficherInventairePlayer) {
		this->inventaire->DisplayUi(window);
	}
}

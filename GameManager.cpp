#include "GameManager.h"
#include "Button.h"
#include <stdlib.h>
#include <time.h> 

GameManager::GameManager(Player* _player, sf::RenderWindow* _window, std::string fontForText)
{
	srand(time(NULL));

	this->fontOftext = new sf::Font;
	this->fontOftext->loadFromFile(fontForText);

	this->ui = new UI(this->fontOftext);
	this->player = _player;
	this->window = _window;
	this->combat = new Combat(this->player);
}

void GameManager::TurnOnOffAffichageInventairePlayer(bool KeyReleased)
{
	if (!this->ui->waitKeyReleasedInventaire && !KeyReleased) {
		this->ui->afficherInventairePlayer = !this->ui->afficherInventairePlayer;
		this->ui->waitKeyReleasedInventaire = true;

		std::list<CaseInventaire*>::iterator it = this->ui->inventaire->listeCaseInventaire.begin();
		while (it != this->ui->inventaire->listeCaseInventaire.end())
		{
			(*it)->isVisible = this->ui->afficherInventairePlayer;
			it++;
		}
	}

	if (KeyReleased) {
		this->ui->waitKeyReleasedInventaire = false;
	}

}

void GameManager::CheckFotTurnPlayer()
{
	if (this->combat->turnPlayer && this->combat->fightInProgress && this->combat->timerForNextAction <= 0) {
		this->ui->combat->afficherOptionsCombats = true;
	}
	else {
		this->ui->combat->afficherOptionsCombats = false;
	}

	std::map<std::string, Button*>::iterator it = this->ui->combat->listAllButton.begin();
	while (it != this->ui->combat->listAllButton.end()) {
		(*it).second->isVisible = this->ui->combat->afficherOptionsCombats;
		it++;
	}
}

void GameManager::CheckOnClickLeftButton()
{
	std::map<std::string, Button*>::iterator it = this->ui->combat->listAllButton.begin();
	while (it != this->ui->combat->listAllButton.end()) {
		(*it).second->OnClick(this);
		it++;
	}
}

void GameManager::CheckOnClickRightButton(bool mouseReleased)
{
	if (!this->ui->waitMouseReleasedCaseInventaire && !mouseReleased) {
		this->ui->waitMouseReleasedCaseInventaire = true;
		std::list<CaseInventaire*>::iterator it = this->ui->inventaire->listeCaseInventaire.begin();
		while (it != this->ui->inventaire->listeCaseInventaire.end())
		{
			(*it)->OnClick(this, (*it)->objetInCase);
			it++;
		}

	}

	if (mouseReleased) {
		this->ui->waitMouseReleasedCaseInventaire = false;
	}
	
}

void GameManager::UpdateTime(float _deltaTime)
{
	this->deltaTime = _deltaTime;
	this->totalTime += _deltaTime;
	this->combat->UpdateTimeCombat(_deltaTime);
}

void GameManager::UpdateGame(sf::Vector2f mousePos)
{
	this->combat->UpdateCombat(this->ui);
	this->CheckFotTurnPlayer();
	this->ui->CheckHoverButton(mousePos, this);

	std::list<CaseInventaire*>::iterator it = this->ui->inventaire->listeCaseInventaire.begin();
	while (it != this->ui->inventaire->listeCaseInventaire.end())
	{
		(*it)->CheckOnHover(mousePos);
		it++;
	}
}

void GameManager::DisplayGame()
{
	this->ui->UpdateUI(this);
	this->ui->UpdatePosUi(this->window);
	this->ui->DisplayUi(this->window, this->combat->fightInProgress);
}

void GameManager::DestroyGame()
{
	this->ui->~UI();
	this->player->~Player();
	delete this->fontOftext;
	this->~GameManager();
}

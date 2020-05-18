#include "UIInventaire.h"
#include "UIStats.h"
#include "GameManager.h"
#include "Inventaire.h"
#include "ButtonInteraction.h"

UIInventaire::UIInventaire(sf::Font* fontForText)
{
	this->statsPlayer = new UIStats(fontForText);
	this->bordureInventaire.setSize(sf::Vector2f(1200, 800));
	this->bordureInventaire.setOutlineColor(sf::Color::Red);
	this->bordureInventaire.setOutlineThickness(3);
	this->bordureInventaire.setFillColor(sf::Color::Black);
	this->bordureInventaire.setOrigin(this->bordureInventaire.getSize().x / 2, this->bordureInventaire.getSize().y / 2);

	this->casqueEquiper = new CaseInventaire();
	this->plastronEquiper = new CaseInventaire();
	this->gantEquiper = new CaseInventaire();
	this->pantalonEquiper = new CaseInventaire();
	this->botteEquiper = new CaseInventaire();
	this->ArmeEquiper = new CaseInventaire();
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

	this->casqueEquiper->UpdatePose(this->bordureInventaire.getPosition().x + this->bordureInventaire.getSize().x / 5, this->bordureInventaire.getPosition().y - this->bordureInventaire.getSize().y / 2.5f);
	this->plastronEquiper->UpdatePose(this->casqueEquiper->contoureCase.getPosition().x, this->casqueEquiper->contoureCase.getPosition().y + this->casqueEquiper->contoureCase.getSize().y * 1.75f);
	this->pantalonEquiper->UpdatePose(this->plastronEquiper->contoureCase.getPosition().x, this->plastronEquiper->contoureCase.getPosition().y + this->plastronEquiper->contoureCase.getSize().y * 1.75f);
	this->botteEquiper->UpdatePose(this->pantalonEquiper->contoureCase.getPosition().x, this->pantalonEquiper->contoureCase.getPosition().y + this->pantalonEquiper->contoureCase.getSize().y * 1.75f);
	this->gantEquiper->UpdatePose(this->plastronEquiper->contoureCase.getPosition().x + this->plastronEquiper->contoureCase.getSize().x * 2.5f, this->plastronEquiper->contoureCase.getPosition().y + this->plastronEquiper->contoureCase.getSize().y / 1.10f);
	this->ArmeEquiper->UpdatePose(this->plastronEquiper->contoureCase.getPosition().x - this->plastronEquiper->contoureCase.getSize().x * 2.5f, this->plastronEquiper->contoureCase.getPosition().y + this->plastronEquiper->contoureCase.getSize().y / 1.10f);

}

void UIInventaire::UpdateUI(GameManager* game)
{

	if (this->listeCaseInventaire.size() == 0) {
		for (int i = 0; i < game->player->inventaire->nombreCaseInventaire; i++)
		{
			this->listeCaseInventaire.push_back(new CaseInventaire());
		}
	}

	statsPlayer->UpdateTextUI(game->player);

	std::list<Objet*>::iterator it = game->player->inventaire->inventaire.begin();
	std::list<CaseInventaire*>::iterator it2 = this->listeCaseInventaire.begin();

	while (it2 != this->listeCaseInventaire.end())
	{
		(*it2)->objetInCase = nullptr;
		it2++;
	}

	it2 = this->listeCaseInventaire.begin();
	
	while (it != game->player->inventaire->inventaire.end())
	{
		(*it2)->objetInCase = (*it);

		switch ((*it2)->objetInCase->category)
		{
		case CATEGORIE_OBJET::EQUIPEMENT_CASQUE:
			(*it2)->pFunctionToExecuteOnClick = buttonInteraction::EquipeCasque;
			break;
		default:
			(*it2)->pFunctionToExecuteOnClick = nullptr;
			break;
		}
		it++;
		it2++;
	}

	this->casqueEquiper->objetInCase = game->player->inventaire->equipementCasque;
	this->plastronEquiper->objetInCase = game->player->inventaire->equipementPlastron;
	this->pantalonEquiper->objetInCase = game->player->inventaire->equipementPantalon;
	this->botteEquiper->objetInCase = game->player->inventaire->equipementBotte;
	this->gantEquiper->objetInCase = game->player->inventaire->equipementGant;
	this->ArmeEquiper->objetInCase = game->player->inventaire->equipementArme;

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
	this->casqueEquiper->Display(window);
	this->plastronEquiper->Display(window);
	this->gantEquiper->Display(window);
	this->pantalonEquiper->Display(window);
	this->botteEquiper->Display(window);
	this->ArmeEquiper->Display(window);
}
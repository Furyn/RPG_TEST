#include "ButtonInteraction.h"
#include "GameManager.h"

namespace buttonInteraction {

	bool AttaqueMagique(GameManager* game) {

		int dommagePlayer = game->player->DommageOfMagiqueAttaque();
		std::string textToDraw = "THE PLAYER USES MAGIQUE ATTACK !\n";
		if (dommagePlayer > 0) {
			if (game->player->coupCritique) {
				textToDraw += "CRITICAL STRIKE ! \n";
			}
			textToDraw += "THE PLAYER HAS DAMAGED " + std::to_string(game->combat->enemie->TakeDommage(dommagePlayer)) + " POINTS.";
		}
		else if (dommagePlayer == -1){
			textToDraw += "MISSED ATTACK !";
		}
		else
		{
			return false;
		}
		game->ui->AddTextOnCombatScreen(textToDraw + "\n");

		game->player->mana -= 2;

		game->combat->timerForNextAction = game->combat->timerBeetweenTwoActions;
		game->combat->turnPlayer = false;

		return true;
	};

	bool AttaqueNormale(GameManager* game) {

		int dommagePlayer = game->combat->player->DommageOfNormaleAttaque();
		std::string textToDraw = "THE PLAYER USES NORMAL ATTACK !\n";
		if (dommagePlayer > 0) {
			if (game->player->coupCritique) {
				textToDraw += "CRITICAL STRIKE ! \n";
			}
			textToDraw += "THE PLAYER HAS DAMAGED " + std::to_string(game->combat->enemie->TakeDommage(dommagePlayer)) + " POINTS.";
		}
		else if (dommagePlayer == -1) {
			textToDraw += "MISSED ATTACK !";
		}
		else
		{
			return false;
		}
		game->ui->AddTextOnCombatScreen(textToDraw + "\n");

		game->combat->timerForNextAction = game->combat->timerBeetweenTwoActions;
		game->combat->turnPlayer = false;

		return true;
	};

	bool AttaqueDesespere(GameManager* game)
	{
		int dommagePlayer = game->player->DommageOfDesperateAttaque();
		std::string textToDraw = "THE PLAYER USES DESPERATE ATTACK !\n";
		if (dommagePlayer > 0) {
			if (game->player->coupCritique) {
				textToDraw += "CRITICAL STRIKE !\n";
			}
			textToDraw += "THE PLAYER HAS DAMAGED " + std::to_string(game->combat->enemie->TakeDommage(dommagePlayer)) + " POINTS.";
		}
		else if (dommagePlayer == -1) {
			textToDraw += "MISSED ATTACK !";
		}
		else
		{
			return false;
		}
		game->ui->AddTextOnCombatScreen(textToDraw + "\n");

		game->combat->timerForNextAction = game->combat->timerBeetweenTwoActions;
		game->combat->turnPlayer = false;

		return true;
	}

	bool PotionDeVie(GameManager* game)
	{

		if (game->player->life == game->player->maxLife) {
			return false;
		}

		std::string textToDraw = "THE PLAYER USES LIFE POTION !\n";

		int nbAddLife = game->player->maxLife * 0.10;

		if (game->player->life + nbAddLife > game->player->maxLife) {
			nbAddLife = game->player->maxLife - game->player->life;
			game->player->life = game->player->maxLife;
		}
		else {
			game->player->life += nbAddLife;
		}

		textToDraw += "THE PLAYER HAS GAIN "+ std::to_string(nbAddLife) +" LIFE POINT";
		
		game->ui->AddTextOnCombatScreen(textToDraw + "\n");

		game->combat->timerForNextAction = game->combat->timerBeetweenTwoActions;
		game->combat->turnPlayer = false;

		return true;
	}

	bool PotionDeMana(GameManager* game)
	{
		if (game->player->mana == game->player->maxMana) {
			return false;
		}

		std::string textToDraw = "THE PLAYER USES MANA POTION !\n";

		int nbAddMana = game->player->maxMana * 0.20;

		if (game->player->mana + nbAddMana > game->player->maxMana) {
			nbAddMana = game->player->maxMana - game->player->mana;
			game->player->mana = game->player->maxMana;
		}
		else {
			game->player->mana += nbAddMana;
		}

		textToDraw += "THE PLAYER HAS GAIN " + std::to_string(nbAddMana) + " MANA POINT";

		game->ui->AddTextOnCombatScreen(textToDraw + "\n");

		game->combat->timerForNextAction = game->combat->timerBeetweenTwoActions;
		game->combat->turnPlayer = false;

		return true;
	}

	bool CheckForPotionDeVie(GameManager* game)
	{
		if (game->player->life == game->player->maxLife) {
			return false;
		}
		return true;
	}

	bool CheckForPotionDeMana(GameManager* game)
	{
		if (game->player->mana == game->player->maxMana) {
			return false;
		}
		return true;
	}

	bool CheckForAttaqueMagique(GameManager* game)
	{
		if (game->player->DommageOfMagiqueAttaque() == -2) {
			return false;
		}
		return true;
	}

	Objet* EquipePlastron(GameManager* game,Objet* plastron)
	{
		Objet* objetToReturn = nullptr;
		if (plastron->category == CATEGORIE_OBJET::EQUIPEMENT_PLASTRON) {
			objetToReturn = game->player->inventaire->equipementPlastron;
			game->player->inventaire->equipementPlastron = plastron;
		}
		return objetToReturn;
	}

	Objet* EquipeCasque(GameManager* game, Objet* casque)
	{
		Objet* objetToReturn = nullptr;
		if (casque->category == CATEGORIE_OBJET::EQUIPEMENT_CASQUE) {
			objetToReturn = game->player->inventaire->equipementCasque;
			game->player->inventaire->equipementCasque = casque;
		}
		return objetToReturn;
	}

	Objet* EquipeGant(GameManager* game, Objet* gant)
	{
		Objet* objetToReturn = nullptr;
		if (gant->category == CATEGORIE_OBJET::EQUIPEMENT_GANT) {
			objetToReturn = game->player->inventaire->equipementGant;
			game->player->inventaire->equipementGant = gant;
		}
		return objetToReturn;
	}

	Objet* EquipePantalon(GameManager* game, Objet* pantalon)
	{
		Objet* objetToReturn = nullptr;
		if (pantalon->category == CATEGORIE_OBJET::EQUIPEMENT_PANTALON) {
			objetToReturn = game->player->inventaire->equipementPantalon;
			game->player->inventaire->equipementPantalon = pantalon;
		}
		return objetToReturn;
	}

	Objet* EquipeBotte(GameManager* game, Objet* botte)
	{
		Objet* objetToReturn = nullptr;
		if (botte->category == CATEGORIE_OBJET::EQUIPEMENT_BOTTE) {
			objetToReturn = game->player->inventaire->equipementBotte;
			game->player->inventaire->equipementBotte = botte;
		}
		return objetToReturn;
	}

	Objet* EquipeArme(GameManager* game, Objet* arme)
	{
		Objet* objetToReturn = nullptr;
		if (arme->category == CATEGORIE_OBJET::EQUIPEMENT_ARME) {
			objetToReturn = game->player->inventaire->equipementArme;
			game->player->inventaire->equipementArme = arme;
		}
		return objetToReturn;
	}

}
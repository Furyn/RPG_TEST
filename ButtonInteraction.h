#pragma once

class GameManager;

namespace buttonInteraction {

	bool AttaqueMagique(GameManager* game);
	bool AttaqueNormale(GameManager* game);
	bool AttaqueDesespere(GameManager* game);
	bool PotionDeVie(GameManager* game);
	bool PotionDeMana(GameManager* game);

	bool CheckForPotionDeVie(GameManager* game);
	bool CheckForPotionDeMana(GameManager* game);
	bool CheckForAttaqueMagique(GameManager* game);

};


#pragma once

class GameManager;
class Objet;

namespace buttonInteraction {

	bool AttaqueMagique(GameManager* game);
	bool AttaqueNormale(GameManager* game);
	bool AttaqueDesespere(GameManager* game);
	bool PotionDeVie(GameManager* game);
	bool PotionDeMana(GameManager* game);

	bool CheckForPotionDeVie(GameManager* game);
	bool CheckForPotionDeMana(GameManager* game);
	bool CheckForAttaqueMagique(GameManager* game);

	bool EquipePlastron(GameManager* game, Objet* plastron);
	bool EquipeCasque(GameManager* game, Objet* casque);
	bool EquipeGant(GameManager* game, Objet* gant);
	bool EquipePantalon(GameManager* game, Objet* pantalon);
	bool EquipeBotte(GameManager* game, Objet* botte);
	bool EquipeArme(GameManager* game, Objet* arme);
};


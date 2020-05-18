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

	Objet* EquipePlastron(GameManager* game, Objet* plastron);
	Objet* EquipeCasque(GameManager* game, Objet* casque);
	Objet* EquipeGant(GameManager* game, Objet* gant);
	Objet* EquipePantalon(GameManager* game, Objet* pantalon);
	Objet* EquipeBotte(GameManager* game, Objet* botte);
	Objet* EquipeArme(GameManager* game, Objet* arme);
};


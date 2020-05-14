#pragma once
#include <iostream>
#include <list>
#include "Objet.h"

class Inventaire
{
public:
	std::list<Objet*> inventaire;

	Objet* equipementPlastron;
	Objet* equipementCasque;
	Objet* equipementGant;
	Objet* equipementBotte;
	Objet* equipementArme;

public:
	Inventaire();

	void AddObjet(Objet* objetToAdd);
	void RemoveObjet(Objet* objetToRemove);

	bool EquipePlastron(Objet* plastron);
	bool EquipeCasque(Objet* casque);
	bool EquipeGant(Objet* gant);
	bool EquipeBotte(Objet* botte);
	bool EquipeArme(Objet* arme);
};


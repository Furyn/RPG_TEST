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
	Objet* equipementPantalon;
	Objet* equipementBotte;
	Objet* equipementArme;

	int nombreCaseInventaire = 45;

public:
	Inventaire();

	void AddObjet(Objet* objetToAdd);
	void RemoveObjet(Objet* objetToRemove);
};


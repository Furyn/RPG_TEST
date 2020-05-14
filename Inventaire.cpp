#include "Inventaire.h"

Inventaire::Inventaire()
{
	this->equipementPlastron = nullptr;
	this->equipementCasque = nullptr;
	this->equipementGant = nullptr;
	this->equipementBotte = nullptr;
	this->equipementArme = nullptr;
}

void Inventaire::AddObjet(Objet* objetToAdd)
{
	std::list<Objet*>::iterator it = this->inventaire.begin();
	while (it != this->inventaire.end()) {
		Objet* objetSelected = (*it);
		if (objetSelected->category == objetToAdd->category && objetSelected->name == objetToAdd->name && objetSelected->maxQuantityInInventory > objetSelected->quantityInInventory) {
			objetSelected->quantityInInventory++;
			return;
		}
		it++;
	}
	this->inventaire.push_back(objetToAdd);
}

void Inventaire::RemoveObjet(Objet* objetToRemove)
{
	std::list<Objet*>::iterator it = this->inventaire.begin();
	while (it != this->inventaire.end()) {
		Objet* objetSelected = (*it);
		if (objetSelected->category == objetToRemove->category && objetSelected->name == objetToRemove->name && objetSelected->maxQuantityInInventory > objetSelected->quantityInInventory) {
			objetSelected->quantityInInventory--;
			return;
		}
		it++;
	}
	this->inventaire.remove(objetToRemove);
	objetToRemove->~Objet();
}

bool Inventaire::EquipePlastron(Objet* plastron)
{
	if (plastron->category == CATEGORIE_OBJET::EQUIPEMENT_PLASTRON) {
		this->equipementPlastron = plastron;
		return true;
	}
	return false;
}

bool Inventaire::EquipeCasque(Objet* casque)
{
	if (casque->category == CATEGORIE_OBJET::EQUIPEMENT_CASQUE) {
		this->equipementPlastron = casque;
		return true;
	}
	return false;
}

bool Inventaire::EquipeGant(Objet* gant)
{
	if (gant->category == CATEGORIE_OBJET::EQUIPEMENT_GANT) {
		this->equipementPlastron = gant;
		return true;
	}
	return false;
}

bool Inventaire::EquipeBotte(Objet* botte)
{
	if (botte->category == CATEGORIE_OBJET::EQUIPEMENT_BOTTE) {
		this->equipementPlastron = botte;
		return true;
	}
	return false;
}

bool Inventaire::EquipeArme(Objet* arme)
{
	if (arme->category == CATEGORIE_OBJET::EQUIPEMENT_ARME) {
		this->equipementPlastron = arme;
		return true;
	}
	return false;
}

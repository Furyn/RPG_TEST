#include "Inventaire.h"

Inventaire::Inventaire()
{
	this->equipementPlastron = nullptr;
	this->equipementCasque = nullptr;
	this->equipementGant = nullptr;
	this->equipementPantalon = nullptr;
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
	if (this->inventaire.size() < this->nombreCaseInventaire) {
		this->inventaire.push_back(objetToAdd);
	}
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
}
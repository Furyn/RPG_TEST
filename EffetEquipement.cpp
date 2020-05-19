#include "EffetEquipement.h"
#include "Character.h"

EffetEquipement::EffetEquipement(int maxManaBonus, int maxLifeBonus, int forceBonus, int criticalBonus, int armorBonus, int intelligenceBonus, int luckBonus)
{
	this->listeEffet = new map<string, int>();

	(*this->listeEffet)["maxMana"] = maxManaBonus;
	(*this->listeEffet)["maxLife"] = maxLifeBonus;
	(*this->listeEffet)["force"] = forceBonus;
	(*this->listeEffet)["critical"] = criticalBonus;
	(*this->listeEffet)["armor"] = armorBonus;
	(*this->listeEffet)["intelligence"] = intelligenceBonus;
	(*this->listeEffet)["luck"] = luckBonus;
}

void EffetEquipement::ApplyEffet(Character* character)
{
	character->maxManaBonus += (*this->listeEffet)["maxMana"];
	character->maxLifeBonus += (*this->listeEffet)["maxLife"];
	character->forceBonus += (*this->listeEffet)["force"];
	character->criticalBonus += (*this->listeEffet)["critical"];
	character->armorBonus += (*this->listeEffet)["armor"];
	character->intelligenceBonus += (*this->listeEffet)["intelligence"];
	character->luckBonus += (*this->listeEffet)["luck"];

}

void EffetEquipement::RemoveEffet(Character* character)
{
	character->maxManaBonus -= (*this->listeEffet)["maxMana"];
	character->maxLifeBonus -= (*this->listeEffet)["maxLife"];
	character->forceBonus -= (*this->listeEffet)["force"];
	character->criticalBonus -= (*this->listeEffet)["critical"];
	character->armorBonus -= (*this->listeEffet)["armor"];
	character->intelligenceBonus -= (*this->listeEffet)["intelligence"];
	character->luckBonus -= (*this->listeEffet)["luck"];
}

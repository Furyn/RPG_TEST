#include "Character.h"

Character::Character(std::string _name, ClassCharacter _classCharacter){

    this->classCharacter = _classCharacter;

	switch (_classCharacter)
	{
    case ClassCharacter::Warrior:
        this->maxLife = 50;
        this->force = 15;
        this->armor = 10;
        this->maxMana = 0;
        this->intelligence = 5;
        this->critical = 10;
        this->luck = 5;
        break;
    case ClassCharacter::Mage:
        this->maxLife = 50;
        this->force = 5;
        this->armor = 10;
        this->maxMana = 10;
        this->intelligence = 15;
        this->critical = 10;
        this->luck = 5;
        break;
    case ClassCharacter::Priest:
        this->maxLife = 40;
        this->force = 1;
        this->armor = 1;
        this->maxMana = 1;
        this->intelligence = 1;
        this->critical = 1;
        this->luck = 1;
        break;
    case ClassCharacter::Assassin:
        this->maxLife = 40;
        this->force = 1;
        this->armor = 1;
        this->maxMana = 1;
        this->intelligence = 1;
        this->critical = 1;
        this->luck = 1;
        break;
    case ClassCharacter::Ranger:
        this->maxLife = 50;
        this->force = 1;
        this->armor = 1;
        this->maxMana = 1;
        this->intelligence = 1;
        this->critical = 1;
        this->luck = 1;
        break;
    case ClassCharacter::Knight:
        this->maxLife = 60;
        this->force = 10;
        this->armor = 15;
        this->maxMana = 0;
        this->intelligence = 5;
        this->critical = 10;
        this->luck = 5;
        break;
    default:
        this->maxLife = 1;
        this->force = 1;
        this->armor = 1;
        this->maxMana = 1;
        this->intelligence = 1;
        this->critical = 1;
        this->luck = 1;
        break;
	}

    this->life = this->maxLife;
    this->mana = this->maxMana;

}

int Character::DommageOfNormaleAttaque()
{
    int dommage = -1; 
    float randomeSuccess = 0.01 * (rand() % 101 );

    if (randomeSuccess > 0.1)
    {
        dommage = this->force * 1.5;
        float randomeCritique = (rand() % 101);
        if (randomeCritique < this->critical) {
            dommage *= 2;
            coupCritique = true;
        }
        else {
            coupCritique = false;
        }
    }
    else {
        coupCritique = false;
    }

	return dommage;//Fail Attaque = -1
}

int Character::DommageOfDesperateAttaque()
{
    int dommage = -1;
    float randomeSuccess = 0.01 * (rand() % 101);

    if (randomeSuccess > 0.5)
    {
        dommage = this->force * 1.5 * 2;
        coupCritique = true;
    }
    else {
        coupCritique = false;
    }

    return dommage;//Fail Attaque = -1
}

int Character::DommageOfMagiqueAttaque()
{

    if (this->mana < 2) {
        return -2; //IMPOSSIBLE D'UTILISER CETTE ATTAQUE = -2
    }

    int dommage = -1;
    float randomeSuccess = 0.01 * (rand() % 101);

    if (randomeSuccess > 0.1)
    {
        dommage = this->intelligence * 1.5;
        float randomeCritique = (rand() % 101);
        if (randomeCritique < this->critical) {
            dommage *= 2;
            coupCritique = true;
        }
        else {
            coupCritique = false;
        }
    }
    else {
        coupCritique = false;
    }

    return dommage;//Fail Attaque = -1
}

int Character::TakeDommage(int dommage)
{
    int dommageTaken = dommage - this->armor;
    if (dommageTaken >= 0) {
        this->life -= dommageTaken;
    }
    else {
        dommageTaken = 0;
    }
    return dommageTaken;
}

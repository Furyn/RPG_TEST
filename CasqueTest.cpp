#include "CasqueTest.h"

CasqueTest::CasqueTest() : Objet("CasqueDeTest",CATEGORIE_OBJET::EQUIPEMENT_CASQUE,10)
{
	this->circle.setFillColor(sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1));
}

#include <fstream>
#include <vector>
#include <string>
#include "PlateauJeux.h"
#include "GameManager.h"

PlateauJeux::PlateauJeux(int _tile_size)
{
	this->tile_size = _tile_size;
}

void PlateauJeux::ChargerPlateu(std::string pathTextLevel, GameManager* game)
{
	std::ifstream levelFile(pathTextLevel.c_str(), std::ios::in);
	if (levelFile.fail()) {
		printf("File %s not found !\n", pathTextLevel);
	}
	else {
		std::string line;
		std::vector<std::string> linesLevel;
		while (std::getline(levelFile, line)) {
			linesLevel.resize(linesLevel.size() + 1, line);
		}
		levelFile.close();

		int maxWidth = 0;
		for (int i = 0; i < linesLevel.size(); i++)
		{
			if (static_cast<int>(linesLevel[i].length()) > maxWidth) {
				maxWidth = static_cast<int>(linesLevel[i].length());
			}
		}

		this->InitPlateau(maxWidth, linesLevel.size(), 0, 0, linesLevel);

		for (int j = 0; j < linesLevel.size(); j++)
		{
			for (int i = 0; i < maxWidth; i++)
			{
				if (linesLevel[j][i] == 'P') {
					printf("PLAYER\n");
				}else if (linesLevel[j][i] == '#') {
					printf("MURE\n");
				}
				else if (linesLevel[j][i] == 'X') {
					printf("BOSS\n");
				}
				else if (isdigit(linesLevel[j][i])) {
					printf("ENNEMIE %d\n", (int)linesLevel[j][i] - '0');
				}
			}
		}

	}
}

void PlateauJeux::InitPlateau(int width, int height, int origineX, int origineY, std::vector<std::string> linesLevel)
{
	Tile*** tabTuiles = new Tile * *[width];
	this->plateau = tabTuiles;

	for (int i = 0; i < width; i++)
	{
		tabTuiles[i] = new Tile * [height];
		for (int j = 0; j < height; j++)
		{
			if (linesLevel[j][i] == '#') {
				tabTuiles[i][j] = CreateTile(i, j, origineX, origineY, typeOfTile::WALL);
			}
			else {
				tabTuiles[i][j] = CreateTile(i, j, origineX, origineY, typeOfTile::FLOOR);
			}
		}
	}
}

Tile* PlateauJeux::CreateTile(int posTuileX, int posTuileY, int originePlateauX, int originePlateauY, typeOfTile type)
{
	Tile* tuile = new Tile{};
	tuile->positionX = posTuileX;
	tuile->positionY = posTuileY;
	tuile->type = type;

	GetTileScreenPosition(posTuileX, posTuileY, originePlateauX, originePlateauY, posTuileX, posTuileY);
	tuile->texture.setPosition(posTuileX, posTuileY);
	tuile->texture.setSize(sf::Vector2f(tile_size, tile_size));

	if (type == typeOfTile::WALL) {
		tuile->texture.setFillColor(sf::Color(128, 0, 0));//MARRON
	}
	else if ((tuile->positionX + tuile->positionY) % 2 == 0) {
		tuile->texture.setFillColor(sf::Color(255, 255, 0));//JAUNE
	}
	else {
		tuile->texture.setFillColor(sf::Color(0, 255, 0));//VERT
	}

	return tuile;
}

void PlateauJeux::GetTileScreenPosition(int posTuileX, int posTuileY, int originePlateauX, int originePlateauY, int& outX, int& outY)
{
	outX = originePlateauX + tile_size * posTuileX;
	outY = originePlateauY + tile_size * posTuileY;
}

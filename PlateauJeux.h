#pragma once
#include "SFML/Graphics.hpp"

enum class typeOfTile { WALL, FLOOR };

struct Tile {
	int positionX;
	int positionY;
	typeOfTile type;
	sf::RectangleShape texture;
};

class GameManager;

class PlateauJeux
{

public:
	Tile*** plateau;

private:
	int tile_size;

public :
	PlateauJeux(int tile_size);
	void ChargerPlateu(std::string pathTextLevel, GameManager* game);
	void InitPlateau(int width, int height, int origineX, int origineY, std::vector<std::string> linesLevel);
	Tile* CreateTile(int posTuileX, int posTuileY, int originePlateauX, int originePlateauY, typeOfTile type);
	void GetTileScreenPosition(int posTuileX, int posTuileY, int originePlateauX, int originePlateauY, int& outX, int& outY);
};


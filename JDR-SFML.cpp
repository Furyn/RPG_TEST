#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameManager.h"
#include "PlateauJeux.h"
#include "Player.h"
#include "Button.h"
#include "windows.h"
#include "CasqueTest.h"

using namespace std;

int speedPlayer = 40;

string getAppPath();
string getAssetPath();

int main()
{
	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "RPG-SFML", sf::Style::Fullscreen);

	GameManager* game = new GameManager(new Player("Furyn", ClassCharacter::Mage), &window, getAssetPath() + "\\retro.ttf");

	string pathAsset = getAssetPath();

	PlateauJeux* plateau = new PlateauJeux(50);

	plateau->ChargerPlateu(pathAsset + "\\level.txt",game);

	sf::Clock clock;
	sf::Mouse mouse;

	float deltaTime = 0.0f;

	game->player->UpdatePosPlayer(window.getSize().x / 2, window.getSize().y / 2);

	// Game loop
	while (window.isOpen()) {

		deltaTime = clock.restart().asSeconds();

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
				window.close();
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::I) {
				game->TurnOnOffAffichageInventairePlayer(false);
			}
			else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::I) {
				game->TurnOnOffAffichageInventairePlayer(true);
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A) {
				game->player->inventaire->AddObjet(new CasqueTest());
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Z && game->player->canMoveUp) {
				game->player->UpdatePosPlayer(0, -speedPlayer);
				game->player->canMoveUp = false;
			}
			else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Z) {
				game->player->canMoveUp = true;
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S && game->player->canMoveDown) {
				game->player->UpdatePosPlayer(0, speedPlayer);
				game->player->canMoveDown = false;
			}
			else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::S) {
				game->player->canMoveDown = true;
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Q && game->player->canMoveLeft) {
				game->player->UpdatePosPlayer(-speedPlayer, 0);
				game->player->canMoveLeft = false;
			}
			else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Q) {
				game->player->canMoveLeft = true;
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::D && game->player->canMoveRight) {
				game->player->UpdatePosPlayer(speedPlayer, 0);
				game->player->canMoveRight = false;
			}
			else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::D) {
				game->player->canMoveRight = true;
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
				if (!game->combat->fightInProgress) {
					game->combat->StartCombatWith(new Character("Soldat Impérial", ClassCharacter::Warrior));
					game->ui->ClearTextOnCombatScreen();
				}
			}

		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			game->CheckOnClickLeftButton();
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)) {
			game->CheckOnClickRightButton(false);
		}
		else {
			game->CheckOnClickRightButton(true);
		}

		sf::Vector2f mousePos = window.mapPixelToCoords(sf::Vector2i(mouse.getPosition(window).x, mouse.getPosition(window).y));

		game->UpdateTime(deltaTime);
		game->UpdateGame(mousePos);

		window.clear();

		game->DisplayGame();

		window.display();
	}

	game->DestroyGame();

}

string getAppPath() {
	char cExeFilePath[256];
	GetModuleFileNameA(NULL, cExeFilePath, 256);
	string exeFilePath = cExeFilePath;
	int exeNamePos = exeFilePath.find_last_of("\\/");
	return exeFilePath.substr(0, exeNamePos + 1);
}

string getAssetPath() {
	static string path = getAppPath();
	return path + "Assets";
}

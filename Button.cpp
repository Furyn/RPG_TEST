#include "Button.h"
#include "GameManager.h"

Button::Button(float widthButton, float heightButton, float posX, float posY, std::string textButton, float sizeCharacter, sf::Color colorOutline, sf::Color colorFill, sf::Font* fontForText,bool(*_pFunctionToExecute)(GameManager*), bool (*_pFunctionToExecuteOnHover)(GameManager*))
{
	this->colorOutline = colorOutline;
	this->colorFill = colorFill;
	this->pFunctionToExecuteOnClick = _pFunctionToExecute;
	this->pFunctionToExecuteOnHover = _pFunctionToExecuteOnHover;

	this->rectButton.setSize(sf::Vector2f(widthButton, heightButton));
	this->rectButton.setOrigin(sf::Vector2f(this->rectButton.getSize().x / 2, this->rectButton.getSize().y / 2));
	this->rectButton.setPosition(sf::Vector2f(posX, posY));
	this->rectButton.setOutlineThickness(3);
	this->rectButton.setOutlineColor(colorOutline);
	this->rectButton.setFillColor(colorFill);

	this->textButton.setFont(*fontForText);
	this->textButton.setString(textButton);
	this->textButton.setCharacterSize(sizeCharacter);
	this->textButton.setOrigin(this->textButton.getLocalBounds().width / 2, this->textButton.getLocalBounds().height);
	this->textButton.setPosition(sf::Vector2f(posX, posY));
	this->textButton.setFillColor(sf::Color::Black);
}

void Button::CheckOnHover(sf::Vector2f positionMouse)
{
	float maxRectX = this->rectButton.getPosition().x + this->rectButton.getSize().x / 2;
	float maxRectY = this->rectButton.getPosition().y + this->rectButton.getSize().y / 2;

	float minRectX = this->rectButton.getPosition().x - this->rectButton.getSize().x / 2;
	float minRectY = this->rectButton.getPosition().y - this->rectButton.getSize().y / 2;

	if ( (positionMouse.x < maxRectX && positionMouse.x > minRectX) && (positionMouse.y > minRectY && positionMouse.y < maxRectY)) {
		this->onHover = true;
	}
	else {
		this->onHover = false;
	}

}

void Button::OnHover(sf::Color colorOutline, sf::Color colorFill, GameManager* game)
{
	if (onHover) {
		if (this->pFunctionToExecuteOnHover == nullptr || this->pFunctionToExecuteOnHover(game)) {
			this->rectButton.setOutlineColor(colorOutline);
			this->rectButton.setFillColor(colorFill);
		}
		else {
			this->rectButton.setOutlineColor(colorOutline);
			this->rectButton.setFillColor(sf::Color::Red);
		}
	}
	else {
		this->rectButton.setOutlineColor(this->colorOutline);
		this->rectButton.setFillColor(this->colorFill);
	}
}

void Button::UpdatePos(float posX, float posY)
{
	this->rectButton.setPosition(sf::Vector2f(posX, posY));
	this->textButton.setPosition(sf::Vector2f(posX, posY));
}

void Button::DisplayButton(sf::RenderWindow* window)
{
	window->draw(this->rectButton);
	window->draw(this->textButton);
}

void Button::OnClick(GameManager* game)
{
	if (onHover && isVisible) {
		(*pFunctionToExecuteOnClick)(game);
	}
}

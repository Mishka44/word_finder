#include <iostream>
#include "menu.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;

//void menu(RenderWindow& window);
int main() {

	//создание окна
	RenderWindow window(sf::VideoMode(1440, 1024), "Alias");
	menu(window);
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed || event.key.code == Keyboard::Escape) window.close();
		}
	}
	/*
	//создание фона
	RectangleShape Background_sh(Vector2f(1440, 1024));
	Texture background_tx;
	if (!background_tx.loadFromFile("images/background.png")) return 1;
	Background_sh.setTexture(&background_tx);

	//создание иконки
	Image icon;
	if (!icon.loadFromFile("images/icon.png")) return 1;
	window.setIcon(32, 32, icon.getPixelsPtr());

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed || event.key.code == Keyboard::Escape) window.close();
		}
		window.clear();
		window.draw(Background_sh);
		window.display();
	}
	*/

	return 0;
}
/*
void menu(RenderWindow& window) {

	Texture menuTexture1, menuTexture2, menuTexture3, rulesTexture, backgroundTexture;
	menuTexture1.loadFromFile("images/play_button.png");
	menuTexture2.loadFromFile("images/rules_button.png");
	rulesTexture.loadFromFile("images/rules_window.png");
	backgroundTexture.loadFromFile("images/background.png");
	Sprite menu1(menuTexture1), menu2(menuTexture2), rules(rulesTexture), menuBg(backgroundTexture);
	bool isMenu = 1;
	int menuNum = 0;
	menu1.setPosition(835, 718);
	menu2.setPosition(835, 829);
	menuBg.setPosition(0, 0);

	/////////////////////////////////////////

	while (isMenu)
	{
		menu1.setColor(Color::White);
		menu2.setColor(Color::White);
		menuNum = 0;
		window.clear(); //!возможно убрать

		if (IntRect(835, 718, 300, 50).contains(Mouse::getPosition(window))) { menuNum = 1; }
		if (IntRect(835, 829, 300, 50).contains(Mouse::getPosition(window))) { menuNum = 2; }

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) isMenu = false;//если нажали первую кнопку, то выходим из меню - начинается игра
			if (menuNum == 2) { window.draw(rules); window.display(); while (!Keyboard::isKeyPressed(Keyboard::Num0)); }

		}

		window.draw(menuBg);
		window.draw(menu1);
		window.draw(menu2);

		window.display();
	}
	////////////////////////////////////////////////////

}*/
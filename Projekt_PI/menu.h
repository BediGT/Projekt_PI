#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>

#define liczbaOpcji 4
#define liczbaPoziomow 3
#define liczbaZmian 3
#define liczbaPoziomowGlosnosci 4

class Menu
{
private:
	//menu
	sf::Sprite spriteMenuTlo;
	sf::Font czcionka;
	sf::Music muzykaMenu;
	sf::Texture txtMenuTlo;
	sf::Vector2i myszkaWzgOkna;
	sf::Text tytul;

	//poziomy
	sf::Text nrPoziomow[liczbaPoziomow + 2];
	sf::Font czcionkaPoziomy;
	sf::Texture txtPoziomyTlo;
	sf::Sprite spritePoziomyTlo;
	sf::Vector2i myszkaWzgOknaPoziomy;
	sf::Vector2f widokPozycjiMyszkiPoziomy;

	//opcje
	sf::Text opcje[liczbaOpcji + 1];
	sf::Text opcjeRozne[liczbaZmian];
	sf::Text poziomGlosnosci[liczbaPoziomowGlosnosci];
	sf::Text powrotZOpcji;
	sf::Texture txtOpcjeTlo;
	sf::Sprite spriteOpcjeTlo;
	sf::Vector2i myszkaWzgOknaOpcje;
	sf::Vector2f widokPozycjiMyszkiOpcje;
	sf::Text jezyki[2];

	//survival
	sf::Texture txtSurvivalTlo;
	sf::Sprite spriteSurvivalTlo;
	sf::Vector2i myszkaWzgOknaSurvival;
	sf::Vector2f widokPozycjiMyszkiSurvival;
	sf::SoundBuffer strzalBuffor;
	sf::Sound strzal;

	//animacja
	class Postac
	{
	public:
		sf::Texture txt;
		sf::Sprite sprit;
		sf::IntRect img;
		sf::Clock time;
	};

	Postac smok;
	Postac przeciwnik;

	//strzelanie
	class Bullet
	{
	public:
		sf::CircleShape shape;
		sf::Vector2f currVelocity;
		float maxSpeed;

		Bullet(float radius = 2.f)
			: currVelocity(0.f, 0.f), maxSpeed(30.f)
		{
			shape.setRadius(radius);
			shape.setFillColor(sf::Color(255, 215, 000));
		}
	};
	Bullet b1;
	std::vector<Bullet> bullets;
	sf::Vector2f playerCenter;
	sf::Vector2f mousePosWindow;
	sf::Vector2f aimDir;
	sf::Vector2f aimDirNorm;

public:

	Menu();
	~Menu();

	//main
	void mainUpdate(sf::RenderWindow* okno);
	void mainDraw(sf::RenderWindow* okno);

	//menu
	sf::Vector2f pozycjaMyszki(sf::RenderWindow* okno);
	void wyswietlTlo(sf::RenderWindow* okno, sf::Sprite* Tlo);
	void przycisk(sf::Text* tabi, sf::Font* font, int size, std::string caption, float x, float y);
	void wyswietlOpcje(sf::RenderWindow* okno);
	void grajMuzyke();
	void pollEv(sf::RenderWindow* okno);
	void eventPolling(sf::RenderWindow* okno);
	void wykrywanieKursora(sf::RenderWindow* okno, int liczbaIteracji, sf::Text* odnosnik);
	void podswietlanie(sf::Text* arg, sf::RenderWindow* okno);

	//poziomy
	void wyswietlPoziomy(sf::RenderWindow* okno);
	bool loopPoziomy(sf::RenderWindow* okno);

	//opcje
	void wykrywanieKursoraOpcje(sf::RenderWindow* zmiany);
	void wyswietlOpcjeDoZmiany(sf::RenderWindow* zmiany);
	void zmianaGlosnosci(sf::RenderWindow*  okno);
	void zmianaJezyka(sf::RenderWindow* okno);
	bool loopOpcje(sf::RenderWindow* okno);
	//void zmianaPoziomuTrudnosci();

	//survival
	void warunekWyboruPoziomow(sf::RenderWindow* okno);
	void pokazanieTlaAnimacjaSurvival(sf::RenderWindow* survival);
	void animacjaSmoka();
	void zmianaKierunku();
	void animacjaPrzeciwnika();
	void strzelanie(sf::RenderWindow* survival);
	void loopSurvival();

};


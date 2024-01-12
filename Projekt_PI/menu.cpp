#include "Menu.h"

Menu::Menu()
{
	//wczytanie czcionki
	if (!czcionka.loadFromFile("czcionki/NanumMyeongjo-Regular.ttf"))
		std::cout << "BLAD - Nie wczytano czcionki!\n";
	//wczytanie muzyki
	if (!muzykaMenu.openFromFile("soundtrack.wav"))
		std::cout << "BLAD - Nie wczytano muzyki!\n";
	//wczytanie tla do menu
	if (!txtMenuTlo.loadFromFile("grafika/wallpaperflare.com_wallpaper.jpg"))
		std::cout << "BLAD - Nie wczytano tla!\n";

	spriteMenuTlo.setTexture(txtMenuTlo); //ustawienie tekstury na tlo

	przycisk(&opcje[0], &czcionka, 50, "Graj", 30.f, 200);
	przycisk(&opcje[1], &czcionka, 50, "Opcje", 30.f, opcje[0].getPosition().y + 75.f);
	przycisk(&opcje[2], &czcionka, 50, "Autorzy", 30.f, opcje[1].getPosition().y + 75.f);
	przycisk(&opcje[3], &czcionka, 50, "Wyjscie", 30.f, opcje[2].getPosition().y + 75.f);
	przycisk(&opcje[4], &czcionka, 100, "Dungeon Conquest", 400.f, 50.f);

	//juz do poziomow

	if (!czcionkaPoziomy.loadFromFile("czcionki/NanumMyeongjo-Regular.ttf"))
		std::cout << "BLAD - Nie wczytano czcionki!\n";
	if (!txtPoziomyTlo.loadFromFile("grafika/wallpaperflare.com_wallpaper.jpg"))
		std::cout << "BLAD - Nie wczytano tla!\n";

	spritePoziomyTlo.setTexture(txtPoziomyTlo);

	przycisk(&nrPoziomow[0], &czcionkaPoziomy, 50, "Poziom 1", 380.f, 200.f);
	przycisk(&nrPoziomow[1], &czcionkaPoziomy, 50, "Poziom 2", nrPoziomow[0].getPosition().x + 300, 200.f);
	przycisk(&nrPoziomow[2], &czcionkaPoziomy, 50, "Poziom 3", nrPoziomow[1].getPosition().x + 300, 200.f);

	przycisk(&nrPoziomow[3], &czcionkaPoziomy, 50, "Powrot do menu", 30.f, 800.f);

	//do opcji
	przycisk(&opcjeRozne[0], &czcionkaPoziomy, 50, "GLOSNOSC", 700.f, 150.f);
	przycisk(&poziomGlosnosci[0], &czcionkaPoziomy, 40, "100%", 400.f, 240.f);
	przycisk(&poziomGlosnosci[1], &czcionkaPoziomy, 40, "75%", poziomGlosnosci[0].getPosition().x + 200.f, 240.f);
	przycisk(&poziomGlosnosci[2], &czcionkaPoziomy, 40, "40%", poziomGlosnosci[1].getPosition().x + 200.f, 240.f);
	przycisk(&poziomGlosnosci[3], &czcionkaPoziomy, 40, "WYCISZ", poziomGlosnosci[2].getPosition().x + 200.f, 240.f);

	przycisk(&opcjeRozne[1], &czcionkaPoziomy, 50, "POZIOM TRUDNOSCI", 600.f, 360.f);

	przycisk(&opcjeRozne[2], &czcionkaPoziomy, 50, "JEZYK", 725.f, 570.f);
	przycisk(&jezyki[0], &czcionkaPoziomy, 30, "Polski", 670.f, 650.f);
	przycisk(&jezyki[1], &czcionkaPoziomy, 30, "Angielski", jezyki[0].getPosition().x + 150, 650.f);


	przycisk(&powrotZOpcji, &czcionkaPoziomy, 60, "Powrot do Menu", 40.f, 800.f);

	if (!txtOpcjeTlo.loadFromFile("grafika/Final_Fantasy_Final_Fantasy_IV_pixel_art_Baron_video_games_castle-196377.jpg"))
		std::cout << "BLAD - nie wczytano tla do opcji!\n";
	spriteOpcjeTlo.setTexture(txtOpcjeTlo);

	//do poziomu survival
	przycisk(&nrPoziomow[4], &czcionkaPoziomy, 50, "Survival", nrPoziomow[1].getPosition().x, nrPoziomow[0].getPosition().y + 200);

	if (!txtSurvivalTlo.loadFromFile("grafika/Fale.jpg"))
		std::cout << "BLAD - nie wczytano tla dla survivalu\n";
	spriteSurvivalTlo.setTexture(txtSurvivalTlo);

	if (!smok.txt.loadFromFile("grafika/postac.png"))
		std::cout << "BLAD - nie wczytano smoka!" << std::endl;

	smok.img.left = 106;
	smok.img.top = 0;
	smok.img.width = 106;
	smok.img.height = 106;

	smok.sprit.setTexture(smok.txt);
	smok.sprit.setTextureRect(smok.img);

	smok.sprit.setPosition(500.f, 200.f);

	//strzal
	if (!strzalBuffor.loadFromFile("shoot.wav"))
		std::cout << "BLAD - nie wczytano dzwieku wystrzalu!\n";
	else
		strzal.setBuffer(strzalBuffor);

	//przeciwnik
	if (!przeciwnik.txt.loadFromFile("grafika/animacjaPostac.png"))
		std::cout << "BLAD - nie wczytano grafiki przeciwnika!\n";

	przeciwnik.img.top = 128;
	przeciwnik.img.width = 64;
	przeciwnik.img.height = 64;
	przeciwnik.img.left = 320;

	przeciwnik.sprit.setTextureRect(przeciwnik.img);
	przeciwnik.sprit.setTexture(przeciwnik.txt);
	przeciwnik.sprit.setPosition(120.f, 120.f);
}

Menu::~Menu()
{

}

void Menu::mainUpdate(sf::RenderWindow* okno)
{
	wykrywanieKursora(okno, liczbaOpcji, &opcje[0]);
}

void Menu::mainDraw(sf::RenderWindow* okno)
{
	wyswietlTlo(okno, &spriteMenuTlo);
	wyswietlOpcje(okno);
}

void Menu::przycisk(sf::Text* tabi, sf::Font* font, int size, std::string caption, float x, float y)
{
	tabi->setFont(*font);
	tabi->setCharacterSize(size);
	tabi->setString(caption);
	tabi->setPosition(x, y);
	tabi->setFillColor(sf::Color::White);
	tabi->setOutlineColor(sf::Color::Black);
	tabi->setOutlineThickness(5);
}

void Menu::wyswietlOpcje(sf::RenderWindow* okno)
{
	for (int i = 0; i < liczbaOpcji+1; i++)
	{
		okno->draw(opcje[i]);
	}
	okno->draw(tytul);
}

void Menu::wyswietlTlo(sf::RenderWindow* okno, sf::Sprite* Tlo)
{
	okno->draw(*Tlo);
}

void Menu::wyswietlPoziomy(sf::RenderWindow* okno)
{
	for (int i = 0; i < liczbaPoziomow+2; i++)
	{
		okno->draw(nrPoziomow[i]);
	}
}

void Menu::wyswietlOpcjeDoZmiany(sf::RenderWindow* zmiany)
{
	for (int i = 0; i < liczbaZmian; i++)
	{
		zmiany->draw(opcjeRozne[i]);
	}
	for (int i = 0; i < liczbaPoziomowGlosnosci; i++)
	{
		zmiany->draw(poziomGlosnosci[i]);
	}
	for (int i = 0; i < 2; i++)
	{
		zmiany->draw(jezyki[i]);
	}

	zmiany->draw(powrotZOpcji);

}

void Menu::podswietlanie(sf::Text* arg, sf::RenderWindow* okno)
{
	if (arg->getGlobalBounds().contains(pozycjaMyszki(okno)))
	{
		arg->setFillColor(sf::Color::Yellow);
		//arg.setPosition(opcje[i].getPosition().x, opcje[i].getPosition().y);
		arg->setScale(1.2f, 1.f);
	}
	else
	{
		arg->setFillColor(sf::Color::White);
		//arg.setPosition(opcje[i].getPosition().x, opcje[i].getPosition().y);
		arg->setScale(1.f, 1.f);
	}
}

sf::Vector2f Menu::pozycjaMyszki(sf::RenderWindow* okno)
{
	myszkaWzgOkna = sf::Mouse::getPosition(*okno);
	return okno->mapPixelToCoords(this->myszkaWzgOkna);  //to ma sie zawierac
}

void Menu::wykrywanieKursora(sf::RenderWindow* okno, int liczbaIteracji, sf::Text* odnosnik)
{
	pozycjaMyszki(okno);

	for (int i = 0; i < liczbaIteracji; i++)
	{
		podswietlanie(&odnosnik[i], okno);
	}
}

void Menu::grajMuzyke()
{
	muzykaMenu.play();
	muzykaMenu.setLoop(true);
}

void Menu::pollEv(sf::RenderWindow* okno)
{
	sf::Event event;

	while (okno->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
		{
			okno->close();
			break;
		}
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape)
				okno->close();
			break;
		}
	}
}

void Menu::eventPolling(sf::RenderWindow* okno)
{
	pollEv(okno);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (opcje[0].getGlobalBounds().contains(pozycjaMyszki(okno)))
		{
			if (loopPoziomy(okno))
				return;
		}
			

		else if (opcje[1].getGlobalBounds().contains(pozycjaMyszki(okno)))
		{
			if (loopOpcje(okno))
				return;
		}

		else if (opcje[3].getGlobalBounds().contains(pozycjaMyszki(okno)))
			okno->close();
	}
}

bool Menu::loopPoziomy(sf::RenderWindow* okno)
{
	okno->clear();
	while (okno->isOpen())
	{
		pollEv(okno);

		wykrywanieKursora(okno, liczbaPoziomow + 2, &nrPoziomow[0]);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && nrPoziomow[3].getGlobalBounds().contains(pozycjaMyszki(okno)))
			return 1;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && nrPoziomow[4].getGlobalBounds().contains(pozycjaMyszki(okno)))
			loopSurvival();

		okno->clear();

		wyswietlTlo(okno, &spriteOpcjeTlo);
		wyswietlPoziomy(okno);


		okno->display();
	}

	return 0;
}

bool Menu::loopOpcje(sf::RenderWindow* okno)
{
	okno->clear();
	while (okno->isOpen())
	{
		pollEv(okno);

		wykrywanieKursora(okno, 1, &powrotZOpcji);

		wykrywanieKursora(okno, liczbaPoziomowGlosnosci, &poziomGlosnosci[0]);
		zmianaGlosnosci(okno);

		wykrywanieKursora(okno, 2, &jezyki[0]);
		zmianaJezyka(okno);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && nrPoziomow[3].getGlobalBounds().contains(pozycjaMyszki(okno)))
			return 1;

		okno->clear();

		wyswietlTlo(okno, &spriteOpcjeTlo);
		wyswietlOpcjeDoZmiany(okno);


		okno->display();
	}

	return 0;
}

void Menu::strzelanie(sf::RenderWindow* okno)
{
	//Vectors
	playerCenter = sf::Vector2f(smok.sprit.getPosition().x + smok.img.width / 2,
		smok.sprit.getPosition().y + smok.img.height / 2);
	mousePosWindow = sf::Vector2f(sf::Mouse::getPosition(*okno));
	aimDir = mousePosWindow - playerCenter;
	aimDirNorm = aimDir / (float)sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));

	//Strzelanie
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		b1.shape.setPosition(playerCenter);
		b1.currVelocity = aimDirNorm * b1.maxSpeed;

		bullets.push_back(Bullet(b1));
	}

	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i].shape.move(bullets[i].currVelocity);

		//Out of bounds
		if (bullets[i].shape.getPosition().x < 0
			|| bullets[i].shape.getPosition().x > okno->getSize().x
			|| bullets[i].shape.getPosition().y < 0
			|| bullets[i].shape.getPosition().y > okno->getSize().y)
			bullets.erase(bullets.begin() + i);
		/*else
		{
			//Enemy Collision
			for (int k = 0; k < enemies.size(); k++)
			{
				if (bullets[i].shape.getGlobalBounds().intersects(enemies[k].getGlobalBounds()))
				{
					bullets.erase(bullets.begin() + i);
					enemies.erase(enemies.begin() + k);
				}
			}
		}*/
	}
}

void Menu::warunekWyboruPoziomow(sf::RenderWindow* okno)
{
	
}

void Menu::loopSurvival()
{
	sf::RenderWindow SURVIVAL(sf::VideoMode(1920, 1080), "Survival", sf::Style::Fullscreen);
	SURVIVAL.setFramerateLimit(120);

	while (SURVIVAL.isOpen())
	{
		pollEv(&SURVIVAL);

		wykrywanieKursora(&SURVIVAL, 0, 0);

		//Gracz
		animacjaSmoka();
		animacjaPrzeciwnika();
		zmianaKierunku();

		//Strzelanie
		strzelanie(&SURVIVAL);

		//Draw
		SURVIVAL.clear();

		pokazanieTlaAnimacjaSurvival(&SURVIVAL);

		SURVIVAL.display();
	}
}

void Menu::zmianaGlosnosci(sf::RenderWindow* okno)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (poziomGlosnosci[0].getGlobalBounds().contains(pozycjaMyszki(okno)))
		{
			muzykaMenu.setVolume(100);
		}
		else if (poziomGlosnosci[1].getGlobalBounds().contains(pozycjaMyszki(okno)))
		{
			muzykaMenu.setVolume(75);
		}
		else if (poziomGlosnosci[2].getGlobalBounds().contains(pozycjaMyszki(okno)))
		{
			muzykaMenu.setVolume(40);
		}
		else if (poziomGlosnosci[3].getGlobalBounds().contains(pozycjaMyszki(okno)))
		{
			muzykaMenu.setVolume(0);
		}
	}
}

void Menu::wykrywanieKursoraOpcje(sf::RenderWindow* zmiany)
{
	myszkaWzgOknaOpcje = sf::Mouse::getPosition(*zmiany);
	widokPozycjiMyszkiOpcje = zmiany->mapPixelToCoords(myszkaWzgOknaOpcje);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (powrotZOpcji.getGlobalBounds().contains(widokPozycjiMyszkiOpcje))
		{
			zmiany->close();
		}
	}

	else if (powrotZOpcji.getGlobalBounds().contains(widokPozycjiMyszkiOpcje))
	{
		powrotZOpcji.setFillColor(sf::Color::Magenta);
		powrotZOpcji.setScale(1.2f, 1.f);
	}

	else
	{
		powrotZOpcji.setFillColor(sf::Color::White);
		powrotZOpcji.setScale(1.f, 1.f);
	}
}

void Menu::zmianaJezyka(sf::RenderWindow* okno)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (jezyki[0].getGlobalBounds().contains(widokPozycjiMyszkiOpcje))
		{
			opcje[0].setString("Graj");
			opcje[1].setString("Opcje");
			opcje[2].setString("Autorzy");
			opcje[3].setString("Wyjscie");

			nrPoziomow[0].setString("Poziom 1");
			nrPoziomow[1].setString("Poziom 2");
			nrPoziomow[2].setString("Poziom 3");

			opcjeRozne[0].setString("GLOSNOSC");
			opcjeRozne[1].setString("POZIOM TRUDNOSCI");
			opcjeRozne[2].setString("JEZYK");

			poziomGlosnosci[3].setString("WYCISZ");

			jezyki[0].setString("Polski");
			jezyki[1].setString("Angielski");
			powrotZOpcji.setString("Powrot do menu");
		}
		else if (jezyki[1].getGlobalBounds().contains(widokPozycjiMyszkiOpcje))
		{
			opcje[0].setString("Play");
			opcje[1].setString("Settings");
			opcje[2].setString("Authors");
			opcje[3].setString("Exit");

			nrPoziomow[0].setString("Level 1");
			nrPoziomow[1].setString("Level 2");
			nrPoziomow[2].setString("Level 3");

			opcjeRozne[0].setString("VOLUME");
			opcjeRozne[1].setString("DIFFICULTY");
			opcjeRozne[2].setString("LANGUAGE");

			poziomGlosnosci[3].setString("Mute");

			jezyki[0].setString("Polish");
			jezyki[1].setString("English");
			powrotZOpcji.setString("Return to menu");
			nrPoziomow[3].setString("Return to menu");
		}
	}
}

void Menu::pokazanieTlaAnimacjaSurvival(sf::RenderWindow* survival)
{
	//survival->draw(Stlo_survival);
	survival->draw(smok.sprit);
	survival->draw(przeciwnik.sprit);

	//rysowanie pociskow
	for (int i = 0; i < bullets.size(); i++)
	{
		survival->draw(bullets[i].shape);
	}
}

void Menu::animacjaSmoka()
{
	if (smok.time.getElapsedTime().asSeconds() > 0.1f)
	{
		if (smok.img.left == 212)
			smok.img.left = 0;
		else
			smok.img.left += 106;

		smok.sprit.setTextureRect(smok.img);
		smok.time.restart();
	}
}

void Menu::zmianaKierunku()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		smok.img.top = 106;
		smok.sprit.move(sf::Vector2f(-5.f, 0.f));

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			smok.sprit.move(sf::Vector2f(0.f, -5.f));
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			smok.sprit.move(sf::Vector2f(0.f, 5.f));
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		smok.img.top = 212;
		smok.sprit.move(sf::Vector2f(5.f, 0.f));

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			smok.sprit.move(sf::Vector2f(0.f, -5.f));
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			smok.sprit.move(0.f, 5.f);
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		smok.img.top = 318;
		smok.sprit.move(sf::Vector2f(0.f, -5.f));
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		smok.img.top = 0;
		smok.sprit.move(sf::Vector2f(0.f, 5.f));
	}

}

void Menu::animacjaPrzeciwnika()
{
	if (przeciwnik.time.getElapsedTime().asSeconds() > 0.1f)
	{
		if (przeciwnik.img.left == 512)
			przeciwnik.img.left = 0;
		else
			przeciwnik.img.left += 64;

		przeciwnik.sprit.setTextureRect(przeciwnik.img);
		przeciwnik.time.restart();
	}
}


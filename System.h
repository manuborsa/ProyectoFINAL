#pragma once
#include "Mapa.h"
#include "Player.h"
#include <SFML/Graphics.hpp>


class System 
{
public:
	System(Player& player, Mapa& mapa, Mapa& fondo, Mapa& obstacle, Mapa& dead, int anchoMapa, int altoMapa, std::ifstream& fileMap);
	~System();
	void update();
	void cmd();
	void draw(sf::RenderWindow& window);
	void CheckCollision();
	sf::Vector2f getPositionPlayer();
	
private:
	Player _player;
	Mapa _mapa;
	Mapa _fondo;
	Mapa _obstacle;
	Mapa _dead;
	int _anchoMapa;
	int _altoMapa;
};

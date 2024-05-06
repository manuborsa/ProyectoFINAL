#pragma once
#include <fstream>
#include <SFML/Graphics.hpp>

using namespace sf;

class Mapa {
public:
	Mapa(int _filas, int _columnas);
	Mapa();
	~Mapa();
	void MapCreator(std::ifstream& file);
	sf::Sprite getSprite(int i, int j);

	sf::FloatRect getOrigen(int i, int j)
	{
		return tilMap[i][j].getGlobalBounds();
	}
	sf::Vector2f getPosition(int i, int j)
	{
		return tilMap[i][j].getPosition();
	}	
private:
	int nFilas;
	int nColumnas;
	std::vector<std::vector <sf::Sprite>> tilMap;
	sf::Texture *_texture = new sf::Texture [20];
};


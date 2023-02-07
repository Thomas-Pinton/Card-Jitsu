#pragma once

#include "SFML/Graphics.hpp"
#include "Card.hpp"
#include <map>

class GraphicManager
{
protected:
	static GraphicManager* instance;
	GraphicManager();
	std::map<std::string, sf::Font*> fontMap;
	std::map<std::string, sf::Texture*> textureMap;
public:
	sf::RenderWindow window;

	~GraphicManager();
	static GraphicManager* getInstance();
	void printCard(Card* c);
	void printText(sf::Text* pT);
	void clear();
	void display();
	sf::Texture* loadTexture(std::string filePath);
	sf::Font* loadFont(std::string filePath);
};


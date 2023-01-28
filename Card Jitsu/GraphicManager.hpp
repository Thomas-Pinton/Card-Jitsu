#pragma once

#include "Card.hpp"

class GraphicManager
{
protected:
	static GraphicManager* instance;
	GraphicManager();
public:
	sf::RenderWindow window;

	static GraphicManager* getInstance();
	void printCard(Card* c);
	void clear();
	void display();
};


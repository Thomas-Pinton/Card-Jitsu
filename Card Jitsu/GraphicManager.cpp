#include "GraphicManager.hpp"
#include <iostream>

GraphicManager* GraphicManager::instance = NULL;

GraphicManager::GraphicManager() :
	window(sf::VideoMode(1280, 720), "Card Jitsu")
{
}

GraphicManager* GraphicManager::getInstance()
{
	if (!instance)
	{
		instance = new GraphicManager();
	}
	return instance;
}

void GraphicManager::printCard(Card* c)
{
	window.draw(c->rectangle);
}

void GraphicManager::clear()
{
	window.clear();
}

void GraphicManager::display()
{
	window.display();
}
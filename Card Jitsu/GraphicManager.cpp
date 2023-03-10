#include "GraphicManager.hpp"
#include <iostream>

GraphicManager* GraphicManager::instance = NULL;

GraphicManager::GraphicManager() :
	window(sf::VideoMode(1280, 720), "Card Jitsu")
{
}

GraphicManager::~GraphicManager()
{
	for (std::map<std::string, sf::Font*>::iterator paths = fontMap.begin(); paths != fontMap.end(); paths++)
	{
		delete (*paths).second;
	}
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
	window.draw(c->powerShape);
	window.draw(c->text);
}

void GraphicManager::printText(sf::Text* pT)
{
	window.draw(*pT);
}

void GraphicManager::clear()
{
	window.clear(sf::Color::Black);
}

void GraphicManager::display()
{
	window.display();
}

sf::Texture* GraphicManager::loadTexture(std::string filePath)
{
	for (std::map<std::string, sf::Texture*>::iterator paths = textureMap.begin(); paths != textureMap.end(); paths++)
	{
		if ((*paths).first == filePath)
		{
			return (*paths).second;
		}
	}



	sf::Texture* text = new sf::Texture();
	if (text->loadFromFile("../Assets/" + filePath))
	{
		textureMap.insert({ filePath, text });
		std::cout << "Image " << "../Assets/" + filePath << "loaded successfully! " << std::endl;
	}


	return text;

}

sf::Font* GraphicManager::loadFont(std::string filePath)
{
	for (std::map<std::string, sf::Font*>::iterator paths = fontMap.begin(); paths != fontMap.end(); paths++)
	{
		if ((*paths).first == filePath)
		{
			return (*paths).second;
		}
	}

	sf::Font* font = new sf::Font();
	if (!font->loadFromFile("../Assets/" + filePath))
		//if (!text->loadFromFile(filePath))

		fontMap.insert({ filePath, font });


	return font;

}

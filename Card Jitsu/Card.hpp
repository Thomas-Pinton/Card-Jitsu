#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>
#include <unordered_map>
#include <stdlib.h>
#include <time.h> 

enum Color
{
	red,
	green,
	purple,
	yellow,
	blue,
	orange
};

enum Element
{
	fire,
	water,
	snow
};

class Card
{
public:
	sf::RectangleShape rectangle;
	Color color;
	int value;
	Element element;
	sf::Text text;
public:
	Card();
	void setPosition(sf::Vector2f pos);

};

std::ostream& operator<< (std::ostream& COUT, Card& card);


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

enum Power
{
	none = -1,
	plus2,
	dicardFire,
	discardWater,
	discardSnow
};


class Card
{
public:
	sf::RectangleShape rectangle;
	sf::RectangleShape powerShape;
	Color color;
	int value;
	Element element;
	Power power;
	sf::Text text;

public:
	Card();
	void setPosition(sf::Vector2f pos);

};

std::ostream& operator<< (std::ostream& COUT, Card& card);


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
	Card();
public:
	sf::RectangleShape rectangle;
	Color color;
	int value;
	Element element;
};

std::ostream& operator<< (std::ostream& COUT, Card& card);


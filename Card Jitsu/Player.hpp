#pragma once

#include "Card.hpp"
#include <iostream>
#include <vector>

class Player
{
public:
	std::vector<Card*> deck;
	std::vector<Card*> pontuation[3];
	Card* selectedCard;
	int chosenCard;
public:
	Player();
	void resetCards();
	void printScore();
	~Player();
};


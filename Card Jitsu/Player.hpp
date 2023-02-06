#pragma once

#include "Card.hpp"
#include "GraphicManager.hpp"
#include <iostream>
#include <vector>

class Player
{
public:
	std::vector<Card*> deck;
	std::vector<Card*> pontuation[3];
	Card* selectedCard;
	int chosenCard;
	int id;
public:
	Player();
	void chooseRandomCard();
	void buyCards();
	void addCard();

	void printScore();
	void printCards();

	~Player();
};


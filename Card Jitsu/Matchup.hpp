#pragma once

#include "Player.hpp"
#include "GraphicManager.hpp"

class Matchup
{
private:
	Player player1;
	Player player2;
	sf::Text statusText;
public:
	Matchup();
	void execute();
	void printCards();
	void chooseCards();
	void printScore();
	void compareCards();
	void resetCards(Player* winner, Player* loser);
	void checkForWin();
};


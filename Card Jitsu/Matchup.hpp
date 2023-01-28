#pragma once

#include "Player.hpp"

class Matchup
{
private:
	Player player1;
	Player player2;
public:
	void execute();
	void printCards();
	void printScore();
	void chooseCards();
	void compareCards();
	void resetCards(Player* winner, Player* loser);
	void checkForWin();
};


#include "Player.hpp"

Player::Player()
{
	srand(time(NULL));

	chosenCard = -1;

	for (int i = 0; i < 5; i++)
		deck.push_back(new Card());
	selectedCard = NULL;
}

void Player::resetCards() 
{
	deck[chosenCard] = new Card();
	chosenCard = -1;
}

void Player::printScore()
{
	std::cout << "Fire: " << pontuation[fire].size();
	std::cout << " Water: " << pontuation[water].size();
	std::cout << " Snow: " << pontuation[snow].size();
}

Player::~Player()
{
	for (int i = 0; i < 5; i++)
		delete deck[i];
	deck.clear();

	delete selectedCard;

	for (int i = 0; i < 3; i++)
	{
		int length = pontuation[i].size();
		for (int j = 0; j < length; i++)
			delete pontuation[i][j];
		pontuation[i].clear();
	}

		
}

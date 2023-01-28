#include "Matchup.hpp"




void Matchup::execute()
{
	
	printCards();

	chooseCards();
	
	if (player1.selectedCard && player2.selectedCard)
	{
		compareCards();
	}
}

void Matchup::printCards()
{
	std::cout << std::endl;
	std::cout << "-----------------------------" << std::endl;

	std::cout << "Your cards are: " << std::endl;

	for (int i = 0; i < 5; i++)
	{
		std::cout << *(player1.deck[i]) << std::endl;
		// player1.deck[i] is a pointer, and you need to send the actual card
	}
}

void Matchup::chooseCards()
{
	player1.chosenCard = -2;

	do {
		std::cout << "Select which card you wish to play (1 - 5)" << std::endl;
		std::cout << "or select '-1' to see the score!" << std::endl;
		std::cin >> player1.chosenCard;
		if (player1.chosenCard == -1)
		{
			printScore();
		}
	} while (player1.chosenCard < 1 || player1.chosenCard > 5);

	player1.selectedCard = player1.deck[--player1.chosenCard];

	int chosenCard = rand() % 5;

	player2.selectedCard = player2.deck[rand() % 5];
	player2.chosenCard = chosenCard;
}

void Matchup::printScore()
{
	std::cout << "Player 1: " << std::endl;
	player1.printScore();
	std::cout << std::endl;
	std::cout << "Player 2: " << std::endl;
	player2.printScore();
	std::cout << std::endl;
}

void Matchup::compareCards()
{

	std::cout << "Your card is" << std::endl;
	std::cout << *(player1.selectedCard) << std::endl;
	
	std::cout << "Your enemy card is" << std::endl;
	std::cout << *(player2.selectedCard) << std::endl;

	if (player1.selectedCard->element == water && player2.selectedCard->element == fire ||
		player1.selectedCard->element == fire && player2.selectedCard->element == snow ||
		player1.selectedCard->element == snow && player2.selectedCard->element == water)
	{
		std::cout << "player 1 won this round!" << std::endl;
		resetCards(&player1, &player2);
	}
	else if (player1.selectedCard->element == player2.selectedCard->element)
	{
		if (player1.selectedCard->value > player2.selectedCard->value)
		{
			resetCards(&player1, &player2);
			std::cout << "player 1 won this round!" << std::endl;
		}
		else if (player1.selectedCard->value < player2.selectedCard->value)
		{
			resetCards(&player2, &player1);
		}
	}
	else
	{
		resetCards(&player2, &player1);
	}

	checkForWin();

	player1.selectedCard = NULL;
	player2.selectedCard = NULL;
}

void Matchup::resetCards(Player* winner, Player* loser)
{
	winner->pontuation[winner->selectedCard->element].push_back(winner->selectedCard);
	delete (loser->selectedCard);

	player1.resetCards();
	player2.resetCards();
}

void Matchup::checkForWin()
{
	bool p1AllElements = true;
	bool p2AllElements = true;
	for (int i = 0; i < 3; i++)
	{
		if (!player1.pontuation[i].size())
			p1AllElements = false;
		if (!player2.pontuation[i].size())
			p2AllElements = false;
		if (player1.pontuation[i].size() > 2)
		{
			/*
			int diferentColors = 0;

			int colors[6] = {0, 0, 0, 0, 0, 0};
			for (int j = 0; j < player1.pontuation[i].size(); j++)
				colors[player1.pontuation[i][j]->color]++;
			for (int j = 0; j < 6; j++)
				if (colors[j])
					diferentColors++;

			if (diferentColors > 3)
			*/
			// Testing if colors repeat
			std::cout << "Jogador 1 ganhou!" << std::endl;
		}
		else if (player2.pontuation[i].size() > 2)
		{
			std::cout << "Jogador 2 ganhou!" << std::endl;
		}
	}
	
	if (p1AllElements)
		std::cout << "Jogador 1 ganhou!" << std::endl;
	else if (p2AllElements)
		std::cout << "Jogador 2 ganhou!" << std::endl;
}
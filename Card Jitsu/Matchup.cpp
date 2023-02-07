#include "Matchup.hpp"
#include<windows.h>

Matchup::Matchup()
{
	statusText.setFont(*(GraphicManager::getInstance()->loadFont("../Assets/GUI_Essential_Free_v1.1/Font/TTF/m5x7.ttf")));
	statusText.setString("Teste");
	statusText.setCharacterSize(64);
	statusText.setPosition(GraphicManager::getInstance()->window.getSize().x / 2 - 200, 0);
	statusText.setString("Your cards are: ");

	for (int i = 0; i < 5; i++)
	{
		player2.deck[i]->setPosition(sf::Vector2f(800, (int)(10 + 60 * i)));
	}

	player1.id = 1;
	player2.id = 2;
}

void Matchup::execute()
{
	
	printCards();
	
	if (player1.selectedCard && player2.selectedCard)
	{
		Sleep(1 * 1000);
		compareCards();
	}
	else
	{
		chooseCards();
	}
}

void Matchup::printCards()
{
	GraphicManager::getInstance()->clear();

	GraphicManager::getInstance()->printText(&statusText);

	player1.printCards();
	player2.printCards();

	GraphicManager::getInstance()->display();

}

void Matchup::chooseCards()
{
	sf::Event event;

	statusText.setString("Your cards are: ");

	//pooling events from in 2 separate places (fix later)
	while (GraphicManager::getInstance()->window.pollEvent(event))
	{
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code >= sf::Keyboard::Num1 && event.key.code <= sf::Keyboard::Num5) // if it is a number between 1 and 5
			{

				player1.chosenCard = (int) event.key.code - 26;
				player1.selectedCard = player1.deck[--player1.chosenCard];
				std::cout << player1.chosenCard << std::endl;

				player1.selectedCard->rectangle.setOutlineColor(sf::Color::Green);

				player2.chooseRandomCard();

				player2.selectedCard->rectangle.setOutlineColor(sf::Color::Green);

			}
		}
	}
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

	//std::cout << "Your card is" << std::endl;
	//std::cout << *(player1.selectedCard) << std::endl;
	
	//std::cout << "Your enemy card is" << std::endl;
	//std::cout << *(player2.selectedCard) << std::endl;

	if (player1.selectedCard->element == water && player2.selectedCard->element == fire ||
		player1.selectedCard->element == fire && player2.selectedCard->element == snow ||
		player1.selectedCard->element == snow && player2.selectedCard->element == water)
	{
		resetCards(&player1, &player2);
	}
	else if (player1.selectedCard->element == player2.selectedCard->element)
	{
		if (player1.selectedCard->value > player2.selectedCard->value)
		{
			resetCards(&player1, &player2);
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

	if (winner->selectedCard->power >= 0)
	{
		if (winner->selectedCard->power >= 1)
			if (loser->pontuation[winner->selectedCard->power - 1].size() > 0)
				loser->pontuation[winner->selectedCard->power - 1].pop_back();
	}

	winner->addCard();
	delete (loser->selectedCard);

	if (winner->id == 1)
		statusText.setString("Player 1 won this round! ");
	else 
		statusText.setString("Player 2 won this round! ");

	player1.buyCards();
	player2.buyCards();

}

void Matchup::checkForWin()
{

	///*
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
			
			int diferentColors = 0;

			int colors[6] = {0, 0, 0, 0, 0, 0};
			for (int j = 0; j < player1.pontuation[i].size(); j++)
				colors[player1.pontuation[i][j]->color]++;
			for (int j = 0; j < 6; j++)
				if (colors[j])
					diferentColors++;

			if (diferentColors > 3)
			
			// Testing if colors repeat
			std::cout << "Jogador 1 ganhou!" << std::endl;
			statusText.setString("Jogador 1 ganhou!");
			
		}
		else if (player2.pontuation[i].size() > 2)
		{
			std::cout << "Jogador 2 ganhou!" << std::endl;
			statusText.setString("Jogador 2 ganhou!");
		}
	}
	
	if (p1AllElements)
		std::cout << "Jogador 1 ganhou!" << std::endl;
	else if (p2AllElements)
		std::cout << "Jogador 2 ganhou!" << std::endl;
	//*/
}
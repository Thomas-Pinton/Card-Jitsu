#include "Player.hpp"


/*

// Criar classe player1 e player2 (polimorfismo)

*/

Player::Player()
{
	chosenCard = -1;

	for (int i = 0; i < 5; i++)
	{
		deck.push_back(new Card());
		deck[i]->setPosition(sf::Vector2f(10, (int) (10 + 60 * i)));
	}
	selectedCard = NULL;
}

void Player::chooseRandomCard()
{
	int cCard = rand() % 5;

	selectedCard = deck[cCard];
	chosenCard = cCard;
}

void Player::buyCards()
{
	deck[chosenCard] = new Card();

	if (id == 1)
		deck[chosenCard]->setPosition(sf::Vector2f(10, (int)(10 + 60 * chosenCard)));
	else 
		deck[chosenCard]->setPosition(sf::Vector2f(800, (int)(10 + 60 * chosenCard)));

	chosenCard = -1;
}

void Player::printScore()
{
	std::cout << "Fire: " << pontuation[fire].size();
	std::cout << " Water: " << pontuation[water].size();
	std::cout << " Snow: " << pontuation[snow].size();
}

void Player::printCards()
{
	for (int i = 0; i < 5; i++)
	{
		GraphicManager::getInstance()->printCard(deck[i]);
	}
	
	//pontuation
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < pontuation[i].size(); j++)
		{
			GraphicManager::getInstance()->printCard(pontuation[i][j]);
		}
	}
}

void Player::addCard()
{
	int qtdCartas = pontuation[selectedCard->element].size();

	selectedCard->rectangle.setOutlineColor(sf::Color::Transparent);

	if (id == 1)
		selectedCard->setPosition(sf::Vector2f(10 + 60 * (int)selectedCard->element, 500 + qtdCartas * 60));
	else 
		selectedCard->setPosition(sf::Vector2f( 700 + 60 * (int)selectedCard->element, 500 + qtdCartas * 60));
	
	pontuation[selectedCard->element].push_back(selectedCard);
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

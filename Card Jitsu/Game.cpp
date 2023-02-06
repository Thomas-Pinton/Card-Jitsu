#include "Game.hpp"

Game::Game()
{
}

void Game::execute()
{
	srand(time(NULL));

	GraphicManager* pGM = GraphicManager::getInstance();
	Matchup matchup;
	while (pGM->window.isOpen())
	{
		sf::Event event;
		while (pGM->window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				pGM->window.close();

			if (event.type == sf::Event::MouseButtonPressed)
				std::cout << "Mouse clicked " << std::endl;
			
			if (event.type == sf::Event::KeyPressed)
				std::cout << "Key pressed " << std::endl;
		}
		matchup.execute();
	}
}

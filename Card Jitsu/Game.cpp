#include "Game.hpp"
#include "GraphicManager.hpp"

Game::Game()
{
}

void Game::execute()
{
	//GraphicManager* pGM = GraphicManager::getInstance();
	Matchup matchup;
	//while (pGM->window.isOpen())
	//{
		//sf::Event event;
		//while (pGM->window.pollEvent(event))
		//{
		//	if (event.type == sf::Event::Closed)
		//		pGM->window.close();
		//}
	while (true)
		matchup.execute();
	//}
}

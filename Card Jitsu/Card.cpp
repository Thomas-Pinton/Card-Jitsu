#include "Card.hpp"
#include "GraphicManager.hpp"

Card::Card()
{
	element = (Element)(rand() % 3);
	color = (Color)(rand() % 6);
	value = rand() % 10 + 1;

	rectangle.setPosition(0, 0);
	rectangle.setSize({50, 50});
	rectangle.setOutlineThickness(2);
	rectangle.setOutlineColor(sf::Color::Transparent);

	text.setString(std::to_string((int)value));
	text.setFont(*(GraphicManager::getInstance()->loadFont("../Assets/GUI_Essential_Free_v1.1/Font/TTF/m5x7.ttf")));
	text.setCharacterSize(32);
	text.setFillColor(sf::Color::Black);
	text.setPosition(rectangle.getPosition());

	switch (element) 
	{
		case fire:
			rectangle.setFillColor(sf::Color::Red);
			break;
		case water:
			rectangle.setFillColor(sf::Color::Blue);
			text.setFillColor(sf::Color::White);
			break;
		case snow:
			rectangle.setFillColor(sf::Color::White);
			break;
	}
}

void Card::setPosition(sf::Vector2f pos)
{
	rectangle.setPosition(pos);
	sf::FloatRect textRect = text.getLocalBounds();

	text.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);

	text.setPosition(pos + rectangle.getSize() / 2.0f);
}


const std::unordered_map<std::string, Element> element_map {
	{ "fire", fire },
	{ "water", water },
	{ "snow", snow }
};


std::ostream& operator<<(std::ostream& os, Element& i) {
	auto const it = std::find_if(element_map.begin(), element_map.end(),
		[i](std::pair<std::string, Element> const& e) {
			return e.second == i;
		}
	);
	if (it != element_map.end())
		os << it->first;
	return os;
}

std::ostream& operator<< (std::ostream& COUT, Card& card)
{
	std::cout << "Elemento: " << card.element;
	std::cout << " Valor: " << card.value;
	std::cout << " Cor: " << card.color;
	std::cout << std::endl;
	return COUT;
}
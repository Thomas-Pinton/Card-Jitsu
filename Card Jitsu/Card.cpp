#include "Card.hpp"


Card::Card()
{
	element = (Element) (rand() % 3);
	color = (Color) (rand() % 6);
	value = rand() % 10 + 1;
	rectangle.setPosition(0, 0);
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
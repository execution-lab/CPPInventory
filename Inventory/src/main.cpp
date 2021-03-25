#include <iostream>
#include <vector>
#include <unordered_map>
#include <memory>

#include "core.h"
#include "item/item.h"
#include "item/symcard.h"


std::unordered_map<size_t, std::unique_ptr<Item>> market;

int main()
{
	setlocale(LC_ALL, "Russian");

	core = std::make_unique<Core>();

	std::unique_ptr<Item> item = std::make_unique<Items::Symcard>();
	
	market[0] = std::move(item);

	auto p = market.find(0);
	std::unique_ptr<Item> item1 = p->second->clone();

	market[1] = std::move(item1);

	for (auto const &i : market)
	{
		std::cout << "This has: " << i.second->getName() << std::endl;
	}

	return 0;
}
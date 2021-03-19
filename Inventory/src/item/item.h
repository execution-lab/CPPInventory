#pragma once
#include "itemtype.h"

#include <string>
#include <memory>

using namespace std;

constexpr int MAX_ITEMS = 10;

class Item
{
public:
	Item() { }
	Item(std::string name, ItemType itemType);

	virtual ~Item() {}
	virtual std::unique_ptr<Item> clone() = 0;
	std::string getName();
	ItemType getType();

private:
	std::string m_name;
	ItemType m_itemType;
};


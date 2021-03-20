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
	Item(std::string name, ItemType itemType, float weight, bool isCombination);

	virtual ~Item() {}
	virtual std::unique_ptr<Item> clone() = 0;
	std::string getName();
	ItemType getType();
	float getWeight();
	bool isCombination();

private:
	std::string m_name;
	ItemType m_itemType;
	float m_weight;
	bool m_isCombination;
};


#pragma once
#include "itemtype.h"
#include "constants.h"

#include <string>
#include <memory>

using namespace std;

class Item
{
public:
	Item() { }
	Item(std::string name, ItemType itemType, float weight, 
		 bool isCombination, int limit);

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
	int m_limit;
};


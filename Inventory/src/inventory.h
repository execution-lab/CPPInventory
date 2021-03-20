#pragma once

#include "inventorycell.h"
#include "item/itemtype.h"

#include <vector>

constexpr int MAX_INVENTORY_CELL = 10;
constexpr int INVALID_INVENTORY_CELL = -1;

class Inventory
{
public:
	Inventory();

	bool add(const std::unique_ptr<Item> &item, int count);
	bool remove(ItemType itemType);
	float getWeight();
	size_t getFreeSlot();
	size_t getItemSlot(ItemType itemType);

private:
	std::vector<InventoryCell> m_cells;
};


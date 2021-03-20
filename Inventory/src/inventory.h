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

	bool add(std::unique_ptr<Item> item, int count);
	bool remove(ItemType itemType);
	size_t getFreeSlot();

private:
	std::vector<InventoryCell> m_cells;
};


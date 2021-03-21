#pragma once

#include "inventorycell.h"
#include "item/itemtype.h"
#include "constants.h"

#include <vector>


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


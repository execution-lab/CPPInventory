#pragma once

#include "inventorycell.h"
#include "item/itemtype.h"
#include "constants.h"
#include "inventoryadditemerror.h"

#include <vector>
#include <memory>


class Inventory
{
public:
	Inventory();

	bool add(const std::unique_ptr<Item> &item, int amount);
	bool remove(ItemType itemType);
	float getWeight();
	size_t getFreeSlot();
	size_t getItemSlot(ItemType itemType);
	int getItemCount(ItemType itemType);
	InventoryAddItemError isAddItem(const std::unique_ptr<Item> &item, int amount, size_t slot);

private:
	std::vector<InventoryCell> m_cells;
};


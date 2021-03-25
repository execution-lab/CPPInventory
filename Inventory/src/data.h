#pragma once

#include "inventory.h"
#include "item/item.h"
#include "item/itemtype.h"
#include "item/symcard.h"

#include <memory>
#include <unordered_map>

class Data
{
public:
	Data();
	~Data() {}

	Inventory * getInventory() const;

private:
	std::unique_ptr<Inventory> m_inventory;
	std::unordered_map<ItemType, std::unique_ptr<Item>> m_itemList;
};


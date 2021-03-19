#pragma once
#include "item/item.h"
#include "item/itemtype.h"

#include <memory>

class InventoryCell
{
public:
	InventoryCell() { }
	~InventoryCell() { }
	InventoryCell(const InventoryCell &);

	bool add(std::unique_ptr<Item> &item);
	bool remove();
	Item * getItem();

private:
	std::unique_ptr<Item> m_item;
};
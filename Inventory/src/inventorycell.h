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

	bool add(const std::unique_ptr<Item> &item, int count);
	bool remove();
	Item * getItem() const;

private:
	std::unique_ptr<Item> m_item;
	int m_count;
};
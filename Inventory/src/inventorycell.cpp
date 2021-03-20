#include "inventorycell.h"

InventoryCell::InventoryCell(const InventoryCell &cell)
{
	m_item = cell.m_item->clone();
}

bool InventoryCell::add(std::unique_ptr<Item> &item, int count)
{
	if (item && !m_item)
	{
		m_item = std::move(item);

		return 1;
	}

	return 0;
}

bool InventoryCell::remove()
{
	if (m_item)
	{
		m_item.reset();

		return 1;
	}

	return 0;
}

Item * InventoryCell::getItem()
{
	return m_item.get();
}

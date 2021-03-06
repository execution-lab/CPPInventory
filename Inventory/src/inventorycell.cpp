#include "inventorycell.h"

InventoryCell::InventoryCell(const InventoryCell &cell)
{
	m_item = cell.m_item->clone();
	m_count = cell.m_count;
}

bool InventoryCell::add(const std::unique_ptr<Item> &item, int count)
{
	if (item && !m_item)
	{
		std::unique_ptr<Item> current_item = item->clone();

		m_item = std::move(current_item);
		m_count = count;

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

Item * InventoryCell::getItem() const
{
	return m_item.get();
}

int InventoryCell::getCount()
{
	return m_count;
}

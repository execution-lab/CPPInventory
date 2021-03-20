#include "inventory.h"

Inventory::Inventory()
{
	m_cells.resize(MAX_INVENTORY_CELL);
}

bool Inventory::add(std::unique_ptr<Item> item, int count = 1)
{
	if (m_cells.size() >= MAX_INVENTORY_CELL)
	{
		size_t free_slot = getFreeSlot();
		if (free_slot != INVALID_INVENTORY_CELL)
		{
			m_cells.at(free_slot).add(item);
		}

		return 1;
	}

	return 0;
}

bool Inventory::remove(ItemType itemType)
{
	for (auto &i : m_cells)
	{
		// Если нашли объект - удаляем
		if (i.getItem()->getType() == itemType)
		{
			i.remove();

			return 1;
		}
	}

	return 0;
}


size_t Inventory::getFreeSlot()
{
	size_t slot = INVALID_INVENTORY_CELL;

	for (size_t i = 0; i < MAX_INVENTORY_CELL; i++)
	{
		if (m_cells.at(i).getItem() == nullptr)
		{
			slot = i;
			break;
		}
	}

	return slot;
}
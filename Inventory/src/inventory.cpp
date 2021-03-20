#include "inventory.h"

Inventory::Inventory()
{
	m_cells.resize(MAX_INVENTORY_CELL);
}

bool Inventory::add(const std::unique_ptr<Item> &item, int count = 1)
{
	if (m_cells.size() >= MAX_INVENTORY_CELL)
	{
		size_t free_slot = getFreeSlot();
		if (free_slot != INVALID_INVENTORY_CELL)
		{
			m_cells.at(free_slot).add(item, count);
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

float Inventory::getWeight()
{
	float weight = 0.0f;

	for (auto &i : m_cells)
	{
		weight += i.getItem()->getWeight();
	}

	return weight;
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

size_t Inventory::getItemSlot(ItemType itemType)
{
	size_t slot = INVALID_INVENTORY_CELL;

	for (size_t i = 0; i < MAX_INVENTORY_CELL; i++)
	{
		if (m_cells.at(i).getItem()->getType() == itemType)
		{
			slot = i;
			break;
		}
	}

	return slot;
}

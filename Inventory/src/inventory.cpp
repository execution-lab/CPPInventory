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
	size_t slot = getItemSlot(itemType);
	if (slot != MAX_INVENTORY_CELL)
	{
		m_cells.at(slot).remove();

		return 1;
	}

	return 0;
}

float Inventory::getWeight()
{
	float weight = 0.0f;

	for (auto &i : m_cells)
	{
		if (i.getItem() != nullptr)
		{
			weight += i.getItem()->getWeight();
		}
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
		if (m_cells.at(i).getItem() != nullptr && 
			m_cells.at(i).getItem()->getType() == itemType)
		{
			slot = i;
			break;
		}
	}

	return slot;
}

int Inventory::getItemCount(ItemType itemType)
{
	int count = 0;

	for (auto &i : m_cells)
	{
		if (i.getItem() != nullptr)
		{
			count += i.getCount();
		}
	}

	return 0;
}

InventoryAddItemError Inventory::isAddItem(const std::unique_ptr<Item> &item, int amount, size_t slot = INVALID_INVENTORY_CELL)
{
	float inv_weight = getWeight();
	float item_weight = item->getWeight();
	float add_item_weight = item_weight * item->isCombination() ? static_cast<float>(amount) : 1.0F;

	if ((inv_weight + add_item_weight) > MAX_INVENTORY_WEIGHT)
	{
		return InventoryAddItemError::WEIGHT_LIMITED;
	}

	if (slot == INVALID_INVENTORY_CELL)
	{
		if (item->isCombination())
		{
			slot = getItemSlot(item->getType());
		}

		if (slot == INVALID_INVENTORY_CELL && (slot = getFreeSlot()) == INVALID_INVENTORY_CELL)
		{
			return InventoryAddItemError::LIMITED;
		}
	}

	if ((getItemCount(item->getType()) + amount) > item->getLimit())
	{
		return InventoryAddItemError::AMOUNT_LIMITED;
	}

	return InventoryAddItemError::SUCCESS;
}

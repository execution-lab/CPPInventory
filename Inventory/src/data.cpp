#include "data.h"

Data::Data()
{
	m_inventory = std::make_unique<Inventory>();

	m_itemList.insert(std::make_pair(ItemType::ITEM_TYPE_PHONE, std::make_unique<Items::Symcard>()));
}

Inventory * Data::getInventory() const
{
	return m_inventory.get();
}
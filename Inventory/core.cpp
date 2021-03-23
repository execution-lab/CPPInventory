#include "core.h"

std::unique_ptr<Core> core;

Core::Core()
{
	m_inventory = std::make_unique<Inventory>();
}

Inventory * Core::getInventory() const
{
	return m_inventory.get();
}

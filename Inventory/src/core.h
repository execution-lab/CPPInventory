#pragma once

#include "inventory.h"

#include <memory>

class Core
{
public:
	Core();

	Inventory * getInventory() const;

private:
	std::unique_ptr<Inventory> m_inventory;
};

extern std::unique_ptr<Core> core;


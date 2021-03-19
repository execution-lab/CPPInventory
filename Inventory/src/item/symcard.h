#pragma once

#include "item/item.h"

#include <string>
#include <memory>

namespace Items
{
	class Symcard : public Item
	{
	public:
		Symcard();
		Symcard(const Symcard&);
		~Symcard() { }

		virtual std::unique_ptr<Item> clone() override;
	};
}


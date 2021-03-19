#include "item.h"

Item::Item(std::string name, ItemType itemType) :
	m_name(name), m_itemType(itemType)
{

}

std::string Item::getName()
{
	return m_name;
}

ItemType Item::getType()
{
	return m_itemType;
}


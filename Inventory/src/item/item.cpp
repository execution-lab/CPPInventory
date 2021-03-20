#include "item.h"

Item::Item(std::string name, ItemType itemType, float weight, bool isCombination) :
	m_name(name), m_itemType(itemType), m_weight(weight), m_isCombination(isCombination)
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

float Item::getWeight()
{
	return m_weight;
}

bool Item::isCombination()
{
	return m_isCombination;
}


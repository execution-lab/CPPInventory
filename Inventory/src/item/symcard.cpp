#include "symcard.h"

/*string Items::Symcard::getName()
{
	return "Сим-карта";
}

ItemType Items::Symcard::getType()
{
	return ITEM_TYPE_PHONE;
}*/

Items::Symcard::Symcard(const Symcard& symcard) :
	Items::Symcard::Symcard()
{

}

Items::Symcard::Symcard() :
	Item("Сим-Карта", ItemType::ITEM_TYPE_PHONE)
{

}

std::unique_ptr<Item> Items::Symcard::clone()
{
	return std::make_unique<Items::Symcard>(*this);
}
#include "symcard.h"

Items::Symcard::Symcard(const Symcard& symcard) :
	Items::Symcard::Symcard()
{

}

Items::Symcard::Symcard() :
	Item("Сим-Карта", ItemType::ITEM_TYPE_PHONE, 0.5f, false)
{

}

std::unique_ptr<Item> Items::Symcard::clone()
{
	return std::make_unique<Items::Symcard>(*this);
}
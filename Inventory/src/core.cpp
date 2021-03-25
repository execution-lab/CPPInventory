#include "core.h"

std::unique_ptr<Core> core;

Core::Core()
{
	m_data = std::make_unique<Data>();
}

Data * Core::getData() const
{
	return m_data.get();
}

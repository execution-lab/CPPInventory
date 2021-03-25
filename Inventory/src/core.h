#pragma once

#include "data.h"

#include <memory>


class Core
{
public:
	Core();

	Data * getData() const;

private:
	std::unique_ptr<Data> m_data;

};

extern std::unique_ptr<Core> core;


#pragma once
#include "CrudRepository.h"
#include "../entities/Car.h"

class CarRepository : public CrudRepository<Car>
{
public:
	explicit CarRepository(const string& name)
		: CrudRepository<Car>(name)
	{
	}
};

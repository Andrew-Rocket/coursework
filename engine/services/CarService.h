#pragma once
#include "../enums/CarProperties.h"
#include "../enums/Order.h"
#include "../exceptions/StringToBoolCastException.h"
#include "../repos/CarRepository.h"
#include "../utils/Utils.h"

class CarService
{
	CarRepository* cars;


public:
	CarService(CarRepository* cars)
		: cars(cars)
	{
	}

	vector<Car*> getAll()
	{
		return cars->getAll();
	}

	bool createAndSave(const string& brand, const string& model, int manufacture_year, const string& color, bool isElectric, int maxSpeed,
		double baseCost, double price)
	{
		return cars->save(new Car(brand, model, manufacture_year, color, isElectric, maxSpeed, baseCost, price));
	}



	vector<Car*> sort(CarProperties prop, Order order)
	{
		vector<Car*> cars = getAll();


		if (prop == PRICE)
		{
			std::sort(cars.begin(), cars.end(),
				[](Car* a, Car* b) -> bool
				{
					return a->getPrice() > b->getPrice();
				});
		}

		if (prop == MAX_SPEED)
		{
			std::sort(cars.begin(), cars.end(),
				[](Car* a, Car* b) -> bool
				{
					return a->getMaxSpeed() > b->getMaxSpeed();
				});
		}

		if (prop == YEAR)
		{
			std::sort(cars.begin(), cars.end(),
				[](Car* a, Car* b) -> bool
				{
					return a->getManufactureYear() > b->getManufactureYear();
				});
		}

		if (prop == COLOR)
		{
			std::sort(cars.begin(), cars.end(),
				[](Car* a, Car* b) -> bool
				{
					return a->getColor() > b->getColor();
				});
		}


		if (prop == BRAND)
		{
			std::sort(cars.begin(), cars.end(),
				[](Car* a, Car* b) -> bool
				{
					return a->getBrand() > b->getBrand();
				});
		}

		if (prop == ELECTRIC)
		{
			std::sort(cars.begin(), cars.end(),
				[](Car* a, Car* b) -> bool
				{
					return a->getElectric() > b->getElectric();
				});
		}

		if (order == DESC)
		{
			std::reverse(cars.begin(), cars.end());
		}

		return cars;


	}

	vector<Car*> filter(CarProperties prop, string param)
	{
		vector<Car*> cars = getAll();
		vector<Car*> filtered;

		if (prop == COLOR)
		{
			for (auto car : cars) {
				if (Utils::toUpperCase(car->getColor()) == Utils::toUpperCase(param))
				{
					filtered.push_back(car);
				}
			}
			return filtered;
		}

		if (prop == BRAND)
		{
			for (auto car : cars) {
				if (Utils::toUpperCase(car->getBrand()) == Utils::toUpperCase(param))
				{
					filtered.push_back(car);
				}
			}
			return filtered;
		}

		if (prop == ELECTRIC)
		{
			try {
				for (auto car : cars) {

					if (car->getElectric() == Utils::stringToBool(param))
					{
						filtered.push_back(car);
					}
				}
			}
			catch (StringToBoolCastException ex) {

			}
			return filtered;
		}


	}

	vector<Car*> filter(CarProperties prop, int floor, int cellar)
	{
		vector<Car*> cars = getAll();
		vector<Car*> filtered;

		if (prop == MAX_SPEED)
		{
			for (auto car : cars) {
				if (car->getMaxSpeed() >= floor && car->getMaxSpeed() <= cellar)
				{
					filtered.push_back(car);
				}
			}
			return filtered;
		}

		if (prop == PRICE)
		{
			for (auto car : cars) {
				if (car->getPrice() >= floor && car->getPrice() <= cellar)
				{
					filtered.push_back(car);
				}
			}
			return filtered;
		}

		if (prop == YEAR)
		{
			for (auto car : cars) {
				if (car->getManufactureYear() >= floor && car->getManufactureYear() <= cellar)
				{
					filtered.push_back(car);
				}
			}
			return filtered;
		}
	}
};

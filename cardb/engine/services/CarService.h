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

	bool deleteCarById(int id)
	{
		return cars->deleteById(id);
	}

	void updateCarById(int id, Car* car)
	{
		cars->updateById(id, car);
	}

	Car* findCarById(int id)
	{
		return cars->findById(id);
	}

	void saveAll()
	{
		cars->saveAll();
	}


	bool updateCarByIdWithParam(int id, CarProperties prop, string value)
	{
		Car* car = cars->findById(id);
		if (car != nullptr) {
			switch (prop)
			{
			case PRICE:
				car->setPrice(stod(value));
				break;
			case MAX_SPEED:
				car->setMaxSpeed(stoi(value));
				break;
			case YEAR:
				car->setManufactureYear(stoi(value));
				break;

			case ELECTRIC:
				car->setElectric(Utils::stringToBool(value));
				break;

			case BRAND:
				car->setBrand(value);
				break;

			case COLOR:
				car->setColor(value);
				break;
			default:
				break;
			}

			cars->updateById(id, car);
			return true;
		}

		return false;
	}



	vector<Car*> sort(CarProperties prop, Order order)
	{
		vector<Car*> cars = getAll();

		switch (prop)
		{
		case PRICE:
			std::sort(cars.begin(), cars.end(),
				[](Car* a, Car* b) -> bool
				{
					return a->getPrice() > b->getPrice();
				});
			break;
		case MAX_SPEED:
			std::sort(cars.begin(), cars.end(),
				[](Car* a, Car* b) -> bool
				{
					return a->getMaxSpeed() > b->getMaxSpeed();
				});
			break;
		case YEAR:
			std::sort(cars.begin(), cars.end(),
				[](Car* a, Car* b) -> bool
				{
					return a->getManufactureYear() > b->getManufactureYear();
				});
			break;

		case ELECTRIC:
			std::sort(cars.begin(), cars.end(),
				[](Car* a, Car* b) -> bool
				{
					return a->getElectric() > b->getElectric();
				});
			break;

		case BRAND:
			std::sort(cars.begin(), cars.end(),
				[](Car* a, Car* b) -> bool
				{
					return a->getBrand() > b->getBrand();
				});
			break;

		case COLOR:
			std::sort(cars.begin(), cars.end(),
				[](Car* a, Car* b) -> bool
				{
					return a->getColor() > b->getColor();
				});
			break;
		default:
			break;
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

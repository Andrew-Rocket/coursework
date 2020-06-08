#pragma once
#include <ostream>
#include <string>

#include "../abstract/Serializable.h"

using namespace std;


class Car : public Serializable
{
private:
	static int counter;

	int id;
	string brand;
	string model;
	int manufactureYear;
	string color;
	bool isElectric;
	int maxSpeed;
	double baseCost;
	double price;

public:
	Car(const string& brand, const string& model, int manufacture_year, const string& color, bool is_electric,
		int max_speed,
		double base_cost, double price)
		:
		brand(brand),
		model(model),
		manufactureYear(manufacture_year),
		isElectric(is_electric),
		color(color),
		maxSpeed(max_speed),
		baseCost(base_cost),
		price(price)
	{
		id = counter;
		counter++;
	}


	Car() = default;

	void serialize(std::ostream& os) override
	{
		string type = typeid(*this).name();
		type.erase(0, type.find(" ") + 1);
		os << type << " " << this->toString() << endl;
	}


	void deserialize(std::istream& is) override
	{
		is >> id;
		counter = id + 1;

		is >> brand;
		is >> model;
		is >> manufactureYear;
		is >> color;
		is >> isElectric;
		is >> maxSpeed;
		is >> baseCost;
		is >> price;
	}

	string toString()
	{
		string tmp;
		tmp = tmp.append(to_string(this->id)).append(" ")
			.append(this->brand).append(" ")
			.append(this->model).append(" ")
			.append(to_string(this->manufactureYear)).append(" ")
			.append(color).append(" ")
			.append(to_string(this->isElectric)).append(" ")
			.append(to_string(this->maxSpeed)).append(" ")
			.append(to_string(this->baseCost)).append(" ")
			.append(to_string(this->price));
		return tmp;
	}


	//Geters and setters
	int getId() override
	{
		return id;
	}

	string getModel() const
	{
		return model;
	}

	void setModel(string model)
	{
		this->model = model;
	}

	string getColor() const
	{
		return color;
	}

	void setColor(string color)
	{
		this->color = color;
	}

	double getPrice() const
	{
		return price;
	}

	void setPrice(double price)
	{
		this->price = price;
	}


	string getBrand() const
	{
		return brand;
	}

	void setBrand(string brand)
	{
		this->brand = brand;
	}

	int getManufactureYear() const
	{
		return manufactureYear;
	}

	void setManufactureYear(int manufacture_year)
	{
		manufactureYear = manufacture_year;
	}

	bool getElectric() const
	{
		return isElectric;
	}

	void setElectric(bool is_electric)
	{
		isElectric = is_electric;
	}

	int getMaxSpeed() const
	{
		return maxSpeed;
	}

	void setMaxSpeed(int max_speed)
	{
		maxSpeed = max_speed;
	}

	double getBaseCost() const
	{
		return baseCost;
	}

	void setBaseCost(double base_cost)
	{
		baseCost = base_cost;
	}
};

int Car::counter = 1;

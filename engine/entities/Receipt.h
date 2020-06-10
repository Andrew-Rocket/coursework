#pragma once
#include <ostream>
#include <string>

#include "../abstract/Serializable.h"

using namespace std;


class Receipt : public Serializable
{
private:
	static int counter;

	int id;
	int userId;
	int carId;
	double price;
	double profit;

public:


	Receipt(int user_id, int car_id, double price, double profit)
		: userId(user_id),
		carId(car_id),
		price(price),
		profit(profit)
	{
		id = counter;
		counter++;
	}

	Receipt() = default;

	void serialize(std::ostream& os) override
	{
		string type = typeid(*this).name();
		type.erase(0, type.find(" ") + 1);
		os << type << " " << this->toString() << endl;
	}


	void deserialize(std::istream& is) override
	{
		string tmp;
		is >> tmp;
		id = stoi(tmp);
		counter = id + 1;

		is >> tmp;
		userId = stoi(tmp);

		is >> tmp;
		carId = stod(tmp);

		is >> tmp;
		price = stod(tmp);

		is >> tmp;
		profit = stod(tmp);
	}

	string toString()
	{
		string tmp;
		tmp = tmp.append(to_string(this->id)).append(" ")
			.append(to_string(userId)).append(" ")
			.append(to_string(carId)).append(" ")
			.append(to_string(price)).append(" ")
			.append(to_string(profit));

		return tmp;
	}


	//Geters and setters

	int getId() override
	{
		return id;
	}

	void setId(int id)
	{
		this->id = id;
	}

	int getUserId() const
	{
		return userId;
	}

	void setUserId(int user_id)
	{
		userId = user_id;
	}

	int getCarId() const
	{
		return carId;
	}

	void setCarId(int car_id)
	{
		carId = car_id;
	}

	double getPrice() const
	{
		return price;
	}

	void setPrice(double price)
	{
		this->price = price;
	}

	double getProfit() const
	{
		return profit;
	}

	void setProfit(double profit)
	{
		this->profit = profit;
	}
};

int Receipt::counter = 1;

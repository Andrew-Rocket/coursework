#pragma once
#include <iomanip>
#include <iostream>

#include "HelpView.h"
#include "View.h"
#include "../../entities/User.h"
#include "../../services/CarService.h"

using namespace std;

//View to view products
class ProductsView : public View
{

private:
	vector<Car*> cars;
	HelpView* view;
public:
	ProductsView(User* user, vector<Car*> cars)
		: View(user)
	{
		this->cars = cars;
		view = new HelpView(user);
	}

	void display() override
	{
		//	system("CLS");

			//Using printf instead of cout to make it shorter 
		printf("|%+12s|%+12s|%+12s|%+12s|%+12s|%+12s|%+12s|%+12s|\n",
			"Id", "Brand", "Model", "Year", "Color", "Engine", "Max Speed", "Price");
		cout << string(105, '-') << endl;

		for (auto car : cars)
		{
			string engine = car->getElectric() ? "Electric" : "Gasoline";

			cout << "|" << setw(12) << std::right << car->getId();
			cout << "|" << setw(12) << std::right << car->getBrand();
			cout << "|" << setw(12) << std::right << car->getModel();
			cout << "|" << setw(12) << std::right << car->getManufactureYear();
			cout << "|" << setw(12) << std::right << car->getColor();
			cout << "|" << setw(12) << std::right << engine;
			cout << "|" << setw(12) << std::right << car->getMaxSpeed();
			cout << "|" << setw(12) << std::right << car->getPrice();
			cout << "|" << endl;
		}
		cout << endl;
		view->display();
	};
};

#pragma once
#include <iostream>
#include <map>

#include "../Command.h"
#include "../../../utils/Utils.h"
#include "../../../entities/User.h"
#include "../../../services/CarService.h"
#include "../../../services/ReceiptService.h"
#include "../../views/ProductsView.h"
#include "../../views/View.h"

using namespace std;

class BuyCommand : public Command
{
private:
	CarService* carService;
	ReceiptService* receiptService;
	View* view;
public:

	BuyCommand(CarService* carService, ReceiptService* receiptService)
	{
		this->carService = carService;
		this->receiptService = receiptService;
		name = "buy";
		description = "buy {id} - buy a car";
		admin = false;
	}

	void execute(vector<string> args, User* user) override
	{
		int id = stoi(args.at(1));
		Car* car = carService->findCarById(id);
		if (user->getBalance() > car->getPrice())
		{
			//Money management 
			user->setBalance(user->getBalance() - car->getPrice());
			user->setSpent(user->getSpent() + car->getPrice());

			//Create receipt
			receiptService->createAndSave(user->getId(), car->getId(), car->getBaseCost(), car->getPrice());
			cout << car->getBrand() << " " << car->getModel() << " was successfully ordered, manager will contact you soon!" << endl;
		}
		else
		{
			cout << "You have not enough money on your balance" << endl;
		}

	}
};

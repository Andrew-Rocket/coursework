#pragma once
#include "entities/User.h"
#include "repos/CarRepository.h"
#include "Auth.h"
#include "console/views/ProductsView.h"
#include "console/views/WelcomeView.h"
#include "repos/ReceiptRepository.h"
#include "services/CommandService.h"

class Application
{
private:
	User* user;
	Auth* auth;

	CarRepository* cars = new CarRepository("cars");
	ReceiptRepository* receipts = new ReceiptRepository("receipts");

	CarService* carService = new CarService(cars);
	ReceiptService* receiptService = new ReceiptService(receipts);

	CommandsBuilder* cmdBuilder = new CommandsBuilder(auth->getUserService(), carService, receiptService);
	CommandService* cmdService;

	View* welcomeView;
	View* productsView;

public:


	explicit Application(Auth* auth)
		: auth(auth)
	{
	}

	void start()
	{
		setEncodings();
		try {
			while (true) {

				user = auth->makeAuth();

				if (user == nullptr)
				{
					throw exception("Error, no user");
				}

				system("CLS");

				welcomeView = new WelcomeView(user);
				welcomeView->display();

				/*productsView = new ProductsView(user, carService);
				productsView->display();*/


				cmdService = new CommandService(cmdBuilder->build());
				cmdService->start(user);
			}
		}
		catch (exception e)
		{
			auth->getUserService()->saveAll();
			carService->saveAll();
			receiptService->saveAll();
		}
	}


	void setEncodings()
	{
		SetConsoleCP(CP_UTF8);
		SetConsoleOutputCP(CP_UTF8);
		setvbuf(stdout, nullptr, _IOFBF, 1000);
	}

};

#pragma once
#include <iomanip>
#include <iostream>

#include "HelpView.h"
#include "View.h"
#include "../../entities/Receipt.h"
#include "../../entities/User.h"

using namespace std;

//View to view products
class ReceiptView : public View
{

private:
	vector<Receipt*> receipts;
	HelpView* view;
public:


	ReceiptView(User* user, const vector<Receipt*>& receipts)
		: View(user)
	{
		this->receipts = receipts;
		view = new HelpView(user);
	}

	void display() override
	{
		//system("CLS");

		//Using printf instead of cout to make it shorter 
		printf("|%+10s|%+10s|%+10s|%+10s|%+10s|\n",
			"Id", "UserId", "CarId", "Price", "Profit");
		cout << string(55, '-') << endl;

		for (auto receipt : receipts)
		{
			cout << "|" << setw(10) << std::right << receipt->getId();
			cout << "|" << setw(10) << std::right << receipt->getUserId();
			cout << "|" << setw(10) << std::right << receipt->getCarId();
			cout << "|" << setw(10) << std::right << receipt->getPrice();
			cout << "|" << setw(10) << std::right << receipt->getProfit();
			cout << "|" << endl;
		}
		cout << endl;
		view->display();
	};
};

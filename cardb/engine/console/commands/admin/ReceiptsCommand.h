#pragma once
#include <iostream>
#include <map>
#include "../Command.h"
#include "../../../entities/User.h"
#include "../../../services/ReceiptService.h"
#include "../../views/ReceiptView.h"
#include "../../views/View.h"

using namespace std;

class ReceiptsCommand : public Command
{
private:
	ReceiptService* receiptService;
	View* view;
public:

	ReceiptsCommand(ReceiptService* receiptService)
	{
		this->receiptService = receiptService;
		name = "receipts";
		description = "*receipts - show all the receipts in the db";
		admin = true;

	}

	void execute(vector<string> args, User* user) override
	{
		view = new ReceiptView(user, receiptService->getAll());
		view->display();
	}
};

#pragma once
#include "../entities/Receipt.h"
#include "../entities/User.h"
#include "../repos/CrudRepository.h"
#include "../repos/UserRepository.h"

class ReceiptService
{
	ReceiptRepository* receipts;


public:
	ReceiptService(ReceiptRepository* receipts)
	{
		this->receipts = receipts;
	}

	void createAndSave(int userId, int carId, double baseCost, double price)
	{
		double profit = price - baseCost;
		receipts->save(new Receipt(userId, carId, price, profit));
	}

	vector<Receipt*> getAll()
	{
		return receipts->getAll();
	}

	void saveAll()
	{
		receipts->saveAll();
	}

};

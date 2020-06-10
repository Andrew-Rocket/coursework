#pragma once
#include "CrudRepository.h"
#include "../entities/Receipt.h"

class ReceiptRepository : public CrudRepository<Receipt>
{
public:
	explicit ReceiptRepository(const string& name)
		: CrudRepository<Receipt>(name)
	{
	}
};

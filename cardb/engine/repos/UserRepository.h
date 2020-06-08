#pragma once
#include "CrudRepository.h"
#include "../entities/User.h"

class UserRepository : public CrudRepository<User>
{
public:


	explicit UserRepository(const string& name)
		: CrudRepository<User>(name)
	{
	}

	User* findByUsername(string username)
	{
		for (User* element : elements)
		{
			if (element->getUsername() == username)
			{
				return element;
			}
		}
		return nullptr;
	}
};

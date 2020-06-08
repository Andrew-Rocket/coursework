#pragma once
#include "../entities/User.h"
#include "../repos/CrudRepository.h"
#include "../repos/UserRepository.h"

class UserService
{
	UserRepository* users;


public:
	UserService(UserRepository* users)
	{
		this->users = users;
	}

	User* login(string username, string password)
	{
		//vector<User*> tmp = users->getAll();
		/*for (auto element : tmp)
		{
			if (element->getUsername() == username && element->getPassword() == password)
			{
				return element;
			}
		}
		return nullptr;*/
		User* user = users->findByUsername(username);
		if (user != nullptr && user->getPassword() == password)
		{
			return user;
		}
		return nullptr;
	}


	User* registration(string username, string password, string rpassword)
	{
		User* user = users->findByUsername(username);
		if (user == nullptr && password == rpassword)
		{
			User* newUser = new User(username, password, 1000, 0, false);
			users->save(newUser);
			return newUser;
		}
		return nullptr;
	}

	void SaveAll()
	{
		users->saveAll();
	}

	void updateById(int id, User* user)
	{
		users->updateById(id, user);
	}
};

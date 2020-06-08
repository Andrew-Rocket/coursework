#pragma once
class View
{
protected:
	User* user;


	View(User* user)
		: user(user)
	{
	}

public:

	virtual void display() = 0;
};

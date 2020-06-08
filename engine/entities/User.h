#pragma once
#include <ostream>
#include <string>
#include <vector>


#include "../abstract/Serializable.h"
#include "../utils/Utils.h"

using namespace std;

class User : public Serializable
{
protected:
	static int counter;

	int id;
	string username;
	string password;

	double balance;
	double spent;

	bool admin;


public:

	User(string username, string password, double balance, double spent, bool admin)
		: username(username),
		password(password),
		balance(balance),
		spent(spent),
		admin(admin)
	{
		id = counter;
		counter++;
	}

	User() = default;

	void serialize(std::ostream& os) override
	{
		string type = typeid(*this).name();
		type.erase(0, type.find(" ") + 1);
		os << type << " " << toString() << endl;
	}


	void deserialize(std::istream& is) override
	{
		string tmp;
		is >> tmp;
		id = stoi(tmp);
		counter = id + 1;

		is >> username;
		is >> password;

		is >> tmp;
		balance = stoi(tmp);

		is >> tmp;
		spent = stod(tmp);

		is >> tmp;
		admin = Utils::stringToBool(tmp);
	}


	string toString()
	{
		string tmp;
		tmp = tmp.append(to_string(id)).append(" ")
			.append(username).append(" ")
			.append(password).append(" ")
			.append(to_string(balance)).append(" ")
			.append(to_string(spent)).append(" ")
			.append(to_string(admin));
		return tmp;
	}

	//Geters and Setters
	int getId() override
	{
		return id;
	}

	void setId(int id)
	{
		this->id = id;
	}


	string getUsername() const
	{
		return username;
	}

	void setUsername(string email)
	{
		this->username = email;
	}


	string getPassword() const
	{
		return password;
	}

	void setPassword(string password)
	{
		this->password = password;
	}


	double getBalance() const
	{
		return balance;
	}

	void setBalance(double balance)
	{
		this->balance = balance;
	}

	double getSpent() const
	{
		return spent;
	}

	void setSpent(double spent)
	{
		this->spent = spent;
	}


	bool isAdmin() const
	{
		return admin;
	}

	void setAdmin(bool is_admin)
	{
		admin = is_admin;
	}
};

int User::counter = 1;

//#pragma once
//#include "Person.h"
//#include <ostream>
//
//#include "../abstract/Serializable.h"
//
//using namespace std;
//
//class Client : public Serializable
//{
//private:
//	static int counter;
//
//	int id;
//	string firstName;
//	string lastName;
//	string phone;
//	string email;
//	string city;
//	string street;
//	string houseNumber;
//
//	int spent;
//
//public:
//
//
//	Client() = default;
//
//
//	Client(const string& first_name, const string& last_name, const string& phone, const string& email,
//		const string& city, const string& street, const string& house_number, int spent)
//		: firstName(first_name),
//		lastName(last_name),
//		phone(phone),
//		email(email),
//		city(city),
//		street(street),
//		houseNumber(house_number),
//		spent(spent)
//	{
//		id = counter;
//		counter++;
//	}
//
//	void serialize(std::ostream& os) override
//	{
//		string type = typeid(*this).name();
//		type.erase(0, type.find(" ") + 1);
//		os << type << " " << toString() << endl;
//	}
//
//
//	void deserialize(std::istream& is) override
//	{
//		is >> id;
//		counter = id + 1;
//
//		is >> firstName;
//		is >> lastName;
//		is >> phone;
//		is >> email;
//		is >> city;
//		is >> street;
//		is >> houseNumber;
//
//		is >> spent;
//	}
//
//	string toString()
//	{
//		string tmp;
//		tmp = tmp.append(to_string(id)).append(" ")
//			.append(firstName).append(" ")
//			.append(lastName).append(" ")
//			.append(phone).append(" ")
//			.append(email).append(" ")
//			.append(city).append(" ")
//			.append(street).append(" ")
//			.append(houseNumber).append(" ")
//			.append(to_string(spent)).append(" ");
//		return tmp;
//	}
//
//	//Geters and Setters
//	int getId() override
//	{
//		return id;
//	}
//
//	void setId(int id)
//	{
//		this->id = id;
//	}
//
//	string getFirstName() const
//	{
//		return firstName;
//	}
//
//	void setFirstName(string first_name)
//	{
//		firstName = first_name;
//	}
//
//	string getLastName() const
//	{
//		return lastName;
//	}
//
//	void getLastName(string last_name)
//	{
//		lastName = last_name;
//	}
//
//	string getPhone() const
//	{
//		return phone;
//	}
//
//	void setPhone(string phone)
//	{
//		this->phone = phone;
//	}
//
//	string getEmail() const
//	{
//		return email;
//	}
//
//	void setEmail(string email)
//	{
//		this->email = email;
//	}
//
//	string getCity() const
//	{
//		return city;
//	}
//
//	void setCity(string city)
//	{
//		this->city = city;
//	}
//
//	string getStreet() const
//	{
//		return street;
//	}
//
//	void setStreet(string street)
//	{
//		this->street = street;
//	}
//
//	string getHouseNumber() const
//	{
//		return houseNumber;
//	}
//
//	void setHouseNumber(string house_number)
//	{
//		houseNumber = house_number;
//	}
//};
//
//int Client::counter = 1;

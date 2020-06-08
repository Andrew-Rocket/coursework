#pragma once
#include <exception>

class StringToBoolCastException : std::exception
{
public:

	explicit StringToBoolCastException(char const* _Message)
		: exception(_Message)
	{
	}
};

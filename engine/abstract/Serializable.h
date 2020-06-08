#pragma once
#include <iosfwd>
#include <ostream>

class Serializable
{
protected:
	virtual ~Serializable() = default;

public:

	virtual void serialize(std::ostream& os) = 0;
	virtual void deserialize(std::istream& is) = 0;
	//virtual auto serialized_size() const noexcept -> std::size_t = 0;

	virtual int getId() = 0;
};

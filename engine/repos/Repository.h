#pragma once
#include <ostream>


template <class T>
class Repository
{
public:

	virtual T* findById(int id) = 0;

	virtual std::vector<T*> getAll() = 0;

	virtual void deleteById(int id) = 0;

	virtual bool save(T* element) = 0;

	virtual void saveAll() = 0;

	virtual std::vector<T*> load() = 0;
};

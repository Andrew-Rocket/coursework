#pragma once
#include <string>
#include <vector>
#include <fstream>

#include "Repository.h"

using namespace std;

template <class T>
class CrudRepository
{
protected:
	vector<T*> elements;
	string filePath;
	std::ofstream saveStream;

public:


	CrudRepository(string name)
	{
		filePath.append(name);
		filePath.append(".txt");
		saveStream.open(filePath, ios::app);

		elements = load();
		//static_assert(is_base_of<Serializable, T>::value);
	}


	~CrudRepository()
	{
		saveStream.close();
	}


	T* findById(int id)
	{
		for (T* element : elements)
		{
			if (element->getId() == id)
			{
				return element;
			}
		}
		return nullptr;
	}

	std::vector<T*> getAll()
	{
		return elements;
	}

	void deleteById(int id)
	{
		int i = 0;
		for (auto element : elements)
		{
			if (element->getId() == id)
			{
				elements.erase(i);
				return;
			}
			i++;
		}
	}

	void updateById(int id, T* t)
	{
		for (int i = 0; i < elements.size(); i++)
		{
			if (elements.at(i)->getId() == id)
			{
				elements[i] = t;
				saveAll();
			}
		}
	}

	bool save(T* element)
	{
		if (findById(element->getId()) != nullptr)
		{
			return false;
		}

		elements.push_back(element);
		element->serialize(saveStream);

		return true;
	}

	void saveAll()
	{
		saveStream.close();
		saveStream.open(filePath);

		for (auto element : elements)
		{
			element->serialize(saveStream);
		}

		saveStream.close();
		saveStream.open(filePath, ios::app);
	}


	std::vector<T*> load()
	{
		std::vector<T*> elements;

		string type;

		ifstream loadStream(filePath);
		if (loadStream.is_open())
		{
			while (loadStream >> type)
			{
				T* tmp = new T();
				tmp->deserialize(loadStream);
				elements.push_back(tmp);
			}
			loadStream.close();
		}

		return elements;
	}
};

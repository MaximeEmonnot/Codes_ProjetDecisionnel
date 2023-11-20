#include "CSVRow.h"

#include <iostream>

void CSVRow::AddValue(std::string const& value)
{
	values.push_back(value);
}

void CSVRow::SetValueAt(size_t index, std::string const& value)
{
	values[index] = value;
}

std::string CSVRow::GetValueAt(size_t index)
{
	return values.at(index);
}

void CSVRow::DeleteValueAt(size_t index)
{
	values.erase(values.begin() + static_cast<long long>(index));
}

size_t CSVRow::GetLength() const
{
	return values.size();
}

void CSVRow::ReorganizeValues(std::vector<size_t> const& indices)
{
	std::vector<std::string> newValues;
	newValues.reserve(values.size());
	for(size_t const index : indices)
		newValues.emplace_back(values.at(index));
	values = newValues;
}

void CSVRow::Print() const
{
	for(std::string const& value : values)
		std::cout << "|" << value;
	std::cout << "|" << std::endl;
}

std::string CSVRow::Serialize(std::string const& delimiter) const
{
	std::stringstream ss;
	for(size_t i = 0; i < values.size(); ++i)
	{
		ss << values.at(i);
		if(i != values.size() - 1)
			ss << delimiter;
	}
	return ss.str();
}

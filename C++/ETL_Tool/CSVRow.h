#pragma once
#include <sstream>
#include <string>
#include <vector>

class CSVRow
{
public:
	CSVRow() = default;
	virtual ~CSVRow() = default;

	void AddValue(std::string const& value);

	void SetValueAt(size_t index, std::string const& value);

	std::string GetValueAt(size_t index);

	void DeleteValueAt(size_t index);

	size_t GetLength() const;

	void ReorganizeValues(std::vector<size_t> const& indices);

	void Print() const;

	std::string Serialize(std::string const& delimiter = ",") const;

protected:
	std::vector<std::string> values;
};

class CSVHeader : public CSVRow
{
public:
	CSVHeader() = default;

	std::vector<std::string> GetColumnNames() const;

	size_t GetColumnIndexByName(std::string const& name) const;
};

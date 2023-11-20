#include "CSVRow.h"

std::vector<std::string> CSVHeader::GetColumnNames() const
{
	return values;
}

size_t CSVHeader::GetColumnIndexByName(std::string const& name) const
{
	for(size_t i = 0; i < values.size(); ++i)
	{
		std::string val = values.at(i);
		if(val == name)
			return i;
	}
	return -1;
}

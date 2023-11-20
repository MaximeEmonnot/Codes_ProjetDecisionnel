#include "CSVTable.h"

#include <fstream>

#include "CSVRow.h"
#include "Extras.h"

CSVTable::CSVTable(std::filesystem::path const& filePath, std::string const& delimiter)
{
	std::ifstream input(filePath);
	std::string line{};

	// Read Header
	std::getline(input, line);
	std::shared_ptr<CSVHeader> header = std::make_shared<CSVHeader>();
	DeserializeRow(header, line, delimiter);
	rows.emplace_back(header);

	// Read Rows
	while(std::getline(input, line))
	{
		std::shared_ptr<CSVRow> row = std::make_shared<CSVRow>();
		DeserializeRow(row, line, delimiter, header);
		rows.emplace_back(row);
	}
	input.close();
	Debug::Alert("Finished Parsing !");
}

void CSVTable::AddRow(std::shared_ptr<CSVRow> const& row)
{
	rows.emplace_back(row);
}

void CSVTable::DeleteColumns(std::vector<std::string> const& columnNames) const
{
	std::shared_ptr<CSVHeader> const header = std::dynamic_pointer_cast<CSVHeader>(rows.at(0));
	// Column Indices
	std::vector<size_t> columnIndices;
	columnIndices.reserve(columnNames.size());
	for(std::string const& columnName : columnNames)
		columnIndices.emplace_back(header->GetColumnIndexByName(columnName));

	DeleteColumns(columnIndices);
}

void CSVTable::DeleteColumns(std::vector<size_t> columnIndices) const
{
	std::sort(columnIndices.begin(), columnIndices.end(), [](size_t a, size_t b) { return a > b; });

	for(std::shared_ptr<CSVRow> const& row : rows)
		for(size_t const columnIndex : columnIndices)
			row->DeleteValueAt(columnIndex);
	Debug::Alert("Finished Deleting Columns !");
}

std::unique_ptr<CSVTable> CSVTable::ExtractColumns(std::vector<std::string> const& columnNames) const
{
	std::unique_ptr<CSVTable> outputTable = std::make_unique<CSVTable>();
	std::shared_ptr<CSVHeader> const header = std::dynamic_pointer_cast<CSVHeader>(rows.at(0));

	for(std::shared_ptr<CSVRow> const& row : rows)
	{
		std::shared_ptr<CSVRow> newRow;
		if(outputTable->rows.empty()) newRow = std::make_shared<CSVHeader>();
		else                          newRow = std::make_shared<CSVRow>();

		for(std::string const& columnName : columnNames)
		{
			size_t const columnIndex = header->GetColumnIndexByName(columnName);
			newRow->AddValue(row->GetValueAt(columnIndex));
		}

		outputTable->AddRow(newRow);
	}

	Debug::Alert("Finished Extracting Columns !");

	return outputTable;
}

void CSVTable::RunTransformation(std::vector<std::string> const& columnInputNames,
                                 std::vector<std::string> const& columnOutputNames,
                                 std::function<std::vector<std::string>(std::vector<std::string> const&)> const& transformation,
                                 std::vector<std::string> const& newColumnNames) const
{
	std::shared_ptr<CSVHeader> const header = std::dynamic_pointer_cast<CSVHeader>(rows.at(0));

	// Input Indices by Names
	std::vector<size_t> columnInputIndices{};
	for(std::string const& inputName : columnInputNames)
		columnInputIndices.emplace_back(header->GetColumnIndexByName(inputName));

	// Output Indices by Names
	std::vector<size_t> columnOutputIndices{};
	for(std::string const& outputName : columnOutputNames)
		columnOutputIndices.emplace_back(header->GetColumnIndexByName(outputName));

	// Add new columns if new columns are created
	if(!newColumnNames.empty())
	{
		for(std::string const& newName : newColumnNames)
		{
			header->AddValue(newName);
			columnOutputIndices.emplace_back(header->GetColumnIndexByName(newName));
		}
	}

	RunTransformation(columnInputIndices, columnOutputIndices, transformation);
}

void CSVTable::RunTransformation(std::vector<size_t> const& columnInputIndices,
	std::vector<size_t> const& columnOutputIndices,
	std::function<std::vector<std::string>(std::vector<std::string> const&)> const& transformation) const
{
	for(size_t i = 1; i < rows.size(); i++)
	{
		// Input Initialization
		std::vector<std::string> inputValues{};
		for(size_t inputIndex : columnInputIndices)
			inputValues.emplace_back(rows[i]->GetValueAt(inputIndex));

		// Transformation
		std::vector<std::string> outputValues = transformation(inputValues);
		for(size_t j = 0; j < columnOutputIndices.size(); ++j)
		{
			size_t const      outputIndex = columnOutputIndices.at(j);
			std::string const outputValue = outputValues.at(j);
			if(outputIndex >= rows[i]->GetLength())
				rows[i]->AddValue(outputValue);
			else
				rows[i]->SetValueAt(outputIndex, outputValue);
		}
	}

	Debug::Alert("Finished Transformation !");
}

void CSVTable::ReorganizeColumns(std::vector<std::string> const& newColumnOrder) const
{
	std::shared_ptr<CSVHeader> const header = std::dynamic_pointer_cast<CSVHeader>(rows.at(0));

	std::vector<size_t> columnOrderIndices;
	columnOrderIndices.reserve(newColumnOrder.size());
	for(std::string const& name : newColumnOrder)
		columnOrderIndices.emplace_back(header->GetColumnIndexByName(name));

	ReorganizeColumns(columnOrderIndices);
}

void CSVTable::ReorganizeColumns(std::vector<size_t> const& newColumnOrder) const
{
	for(std::shared_ptr<CSVRow> const& row : rows)
		row->ReorganizeValues(newColumnOrder);

	Debug::Alert("Finished Reorganizing !");
}

void CSVTable::RenameColumn(size_t columnIndex, std::string const& newColumnName) const
{
	std::shared_ptr<CSVHeader> const header = std::dynamic_pointer_cast<CSVHeader>(rows.at(0));
	header->SetValueAt(columnIndex, newColumnName);
	Debug::Alert("Finished Renaming !");
}

void CSVTable::FilterRows(size_t columnIndex, std::string const& filterValue, std::function<bool(std::string const&, std::string const&)> const& predicate)
{
	std::vector<std::shared_ptr<CSVRow>> newRows;
	newRows.emplace_back(rows[0]);
	for(size_t i = 1; i < rows.size(); ++i)
		if(predicate(rows[i]->GetValueAt(columnIndex), filterValue))
			newRows.emplace_back(rows[i]);

	rows.clear();
	rows = newRows;

	Debug::Alert("Finished Filter !");
}

void CSVTable::PrintFirstRow() const
{
	rows[0]->Print();
	rows[1]->Print();
}

void CSVTable::Serialize(std::string const& outputPath, std::string const& delimiter) const
{
	std::ofstream output(outputPath);

	for(std::shared_ptr<CSVRow> const& row : rows)
		output << row->Serialize(delimiter) << "\n";

	output.close();

	Debug::Alert("Finished Serialization !");
}

std::vector<std::string> CSVTable::GetColumnNames() const
{
	std::shared_ptr<CSVHeader> const header = std::dynamic_pointer_cast<CSVHeader>(rows.at(0));
	return header->GetColumnNames();
}

// STATIC METHODS

void CSVTable::DeserializeRow(std::shared_ptr<CSVRow> const& row, std::string const& line, std::string const& delimiter, std::shared_ptr<CSVHeader> const& header)
{
	std::stringstream ss(line);
	std::string       word;
	bool bHasQuote{};
	while(std::getline(ss, word, delimiter[0]))
	{
		if(bHasQuote)
			row->SetValueAt(row->GetLength() - 1, row->GetValueAt(row->GetLength() - 1).append(delimiter + word));
		else
			row->AddValue(word);

		if(!word.empty())
		{
			if(word.at(0) == '"')
				bHasQuote = !bHasQuote;
			if(word.size() > 1 && word.at(word.size() - 1) == '"')
				bHasQuote = false;
		}
	}

	// If the last values were empty...
	while(header && header->GetLength() > row->GetLength())
		row->AddValue({});
}

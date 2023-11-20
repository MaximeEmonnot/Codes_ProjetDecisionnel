#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>

#include "CSVTable.h"
#include "Extras.h"

int main()
{
	// Transformations
	std::vector<std::pair<std::string, std::function<std::vector<std::string>(std::vector<std::string> const&)>>> transformations
	{
		{ "Test",                        Transformations::Test                       },
		{ "Timestamp Converter",         Transformations::TimestampConverter         },
		{ "Date Splitter",               Transformations::DateSplitter               },
		{ "Boolean Converter",           Transformations::BooleanConverter           },
		{ "Magnitude Type From Columns", Transformations::MagnitudeTypeFromColumn    },
		{ "Magnitude Converter",         Transformations::MagnitudeConverter         },
		{ "Move Total To Value",         Transformations::MoveTotalToValue           },
		{ "Remove Spaces",               Transformations::RemoveSpaces               },
		{ "Fahrenheit to Celsius",       Transformations::ConvertFahrenheitToCelsius },
	};

	// Filter predicates
	std::vector<std::pair<std::string, std::function<bool(std::string const&, std::string const&)>>> filterPredicates
	{
		{ "less (<)",              [](std::string const& A, std::string const& B) { return std::stof(A) <  std::stof(B); } },
		{ "less or equal (<=)",    [](std::string const& A, std::string const& B) { return std::stof(A) <= std::stof(B); } },
		{ "equal (==)",            [](std::string const& A, std::string const& B) { return A            == B;            } },
		{ "different (!=)",        [](std::string const& A, std::string const& B) { return A            != B;            } },
		{ "greater or equal (>=)", [](std::string const& A, std::string const& B) { return std::stof(A) >= std::stof(B); } },
		{ "greater (>)",           [](std::string const& A, std::string const& B) { return std::stof(A) >  std::stof(B); } },
	};

	// Routine
	while(true)
	{
		// Get all Files from Input folder
		std::vector<std::filesystem::path> files{};
		int fileChoice = -1;
		while(fileChoice == -1)
		{
			files.clear();
			for(const auto& entry : std::filesystem::directory_iterator("Input"))
				files.emplace_back(entry.path());

			// Ask the user to select a file from the list
			std::cout << "Select your file : " << std::endl;
			for(size_t i = 0; i < files.size(); ++i)
				std::cout << " " << i << " - " << files.at(i) << std::endl;
			std::cout << "-1 - Refresh list" << std::endl;
			std::cin >> fileChoice;
		}

		// Ask the user to select a delimiter from the list
		std::vector<std::string> delimiterList { ",", ";", "|", "."};
		std::cout << "Select your delimiter : " << std::endl;
		for(size_t i = 0; i < delimiterList.size(); ++i)
			std::cout << i << " - " << delimiterList.at(i) << std::endl;
		int delimiterChoice{};
		std::cin >> delimiterChoice;

		std::filesystem::path file = files.at(fileChoice);
		std::string           delimiter = delimiterList.at(delimiterChoice);

		std::cout << "Your choice : " << file << " | Delimiter : " << delimiter << std::endl;

		// Open the CSV file
		std::unique_ptr<CSVTable> const csvTable = std::make_unique<CSVTable>(file, delimiter);

		// Treatment Routine
		while(true)
		{
			std::vector<std::string> actions{"Delete Columns", "Extract Columns", "Reorganize Columns", "Rename Columns", "Transform Values", "Filter Rows", "Print First Row", "Serialize Result and Quit" };
			size_t actionChoice{};
			std::cout << "Select the treatment you want to apply : " << std::endl;
			for(size_t i = 0; i < actions.size(); ++i)
				std::cout << i << " - " << actions.at(i) << std::endl;
			std::cin >> actionChoice;

			switch(actionChoice)
			{
			case 0: // Delete Columns
				{
				std::cout << "Select the Columns you want to delete : " << std::endl;
				for(size_t i = 0; i < csvTable->GetColumnNames().size(); ++i)
					std::cout << " " << i << " - " << csvTable->GetColumnNames().at(i) << std::endl;
				std::cout << "-1 - End Selection" << std::endl;

				std::vector<size_t> columnsToDelete{};
				int value{};
				do
				{
					std::cin >> value;
					if(value != -1)
						columnsToDelete.emplace_back(value);
				} while(value != -1);

				csvTable->DeleteColumns(columnsToDelete);
				}
				break;
			case 1: // Extract Columns
				{
				std::cout << "Select the Columns you want to extract : " << std::endl;
				for(size_t i = 0; i < csvTable->GetColumnNames().size(); ++i)
					std::cout << " " << i << " - " << csvTable->GetColumnNames().at(i) << std::endl;
				std::cout << "-1 - End Selection" << std::endl;

				std::vector<std::string> columnsToExtract{};
				int value{};
				do
				{
					std::cin >> value;
					if(value != -1)
						columnsToExtract.emplace_back(csvTable->GetColumnNames().at(value));
				} while(value != -1);

				std::cout << "Type your extract file name : " << std::endl;
				std::string outputName{};
				std::cin >> outputName;
				std::cout << "Select your delimiter : " << std::endl;
				for(size_t i = 0; i < delimiterList.size(); ++i)
					std::cout << i << " - " << delimiterList.at(i) << std::endl;
				int newDelimiterChoice{};
				std::cin >> newDelimiterChoice;
				csvTable->ExtractColumns(columnsToExtract)->Serialize("Extract/" + outputName + ".csv", delimiterList.at(newDelimiterChoice));
				}
				break;
			case 2: // Reorganize Columns
				{
				std::cout << "Your current Columns Order : " << std::endl;
				for(size_t i = 0; i < csvTable->GetColumnNames().size(); ++i)
					std::cout << " " << i << " - " << csvTable->GetColumnNames().at(i) << std::endl;
				std::cout << "Type the new Columns Order : " << std::endl;
				std::vector<size_t> columnOrder;
				while(columnOrder.size() != csvTable->GetColumnNames().size())
				{
					int value{};
					std::cin >> value;
					columnOrder.emplace_back(value);
				}
				csvTable->ReorganizeColumns(columnOrder);
				}
				break;
			case 3: // Rename Columns
				{
				std::cout << "Select the column you want to rename : " << std::endl;
				for(size_t i = 0; i < csvTable->GetColumnNames().size(); ++i)
					std::cout << " " << i << " - " << csvTable->GetColumnNames().at(i) << std::endl;
				size_t index{};
				std::cin >> index;
				std::cout << "Type the column's new name : " << std::endl;
				std::string newName{};
				std::cin >> newName;
				csvTable->RenameColumn(index, newName);
				}
				break;
			case 4: // Transform Values
				{
				std::cout << "Select a transformation to run : " << std::endl;

				for(size_t i = 0; i < transformations.size(); i++)
					std::cout << i << " - " << transformations.at(i).first << std::endl;
				size_t value{};
				std::cin >> value;

				std::cout << "Your file columns : " << std::endl;
				for(size_t i = 0; i < csvTable->GetColumnNames().size(); ++i)
					std::cout << i << " - " << csvTable->GetColumnNames().at(i) << std::endl;

				// Input Selection
				std::cout << "Select your input columns (-1 to leave selection) : " << std::endl;
				std::vector<std::string> inputColumns{};
				int inputCol{};
				do
				{
					std::cin >> inputCol;
					if(inputCol != -1)
						inputColumns.emplace_back(csvTable->GetColumnNames().at(inputCol));
				} while(inputCol != -1);

				// Output Selection
				std::cout << "Select your output columns (-1 to leave selection) : " << std::endl;
				std::vector<std::string> outputColumns{};
				int outputCol{};
				do
				{
					std::cin >> outputCol;
					if(outputCol != -1)
						outputColumns.emplace_back(csvTable->GetColumnNames().at(outputCol));
				} while(outputCol != -1);

				// New Columns Specification
				std::cout << "If your transformation creates new column, write them (separated with spaces, 'exit' to finish) : " << std::endl;
				std::vector<std::string> newColumns{};
				std::string colName{};
				do
				{
					std::cin >> colName;
					if(colName != "exit")
						newColumns.emplace_back(colName);
				} while(colName != "exit");

				// Apply Transformation
				std::cout << "Summary : " << std::endl;
				std::cout << "- Transformation chosen : " << transformations.at(value).first << std::endl;
				std::cout << "- Input columns : " << std::endl;
				for(std::string const& input : inputColumns)
					std::cout << "  * "<< input << std::endl;
				std::cout << "- Output columns : " << std::endl;
				for(std::string const& output : outputColumns)
					std::cout << "  * " << output << std::endl;
				std::cout << "- New columns : " << std::endl;
				for(std::string const& newCol : newColumns)
					std::cout << "  * " << newCol << std::endl;

				std::cout << "Running Transformation..." << std::endl;
				csvTable->RunTransformation(inputColumns, outputColumns, transformations.at(value).second, newColumns);
				}
				break;
			case 5:
				{
				std::cout << "Select the column to filter : " << std::endl;
				for(size_t i = 0; i < csvTable->GetColumnNames().size(); ++i)
					std::cout << " " << i << " - " << csvTable->GetColumnNames().at(i) << std::endl;
				size_t col{};
				std::cin >> col;
				std::cout << "Type the value to test : " << std::endl;
				std::string value{};
				std::cin >> value;

				std::cout << "Select the operator : " << std::endl;
				for(size_t i = 0; i < filterPredicates.size(); i++)
					std::cout << i << " - " << filterPredicates.at(i).first << std::endl;
				size_t op{};
				std::cin >> op;
				csvTable->FilterRows(col, value, filterPredicates.at(op).second);
				}
				break;
			case 6:
				{
				csvTable->PrintFirstRow();
				}
				break;
			case 7: // Serialize Result and Quit
				{
				std::cout << "Type your file name : " << std::endl;
				std::string outputName{};
				std::cin >> outputName;
				std::cout << "Select your delimiter : " << std::endl;
				for(size_t i = 0; i < delimiterList.size(); ++i)
					std::cout << i << " - " << delimiterList.at(i) << std::endl;
				int newDelimiterChoice{};
				std::cin >> newDelimiterChoice;
				csvTable->Serialize("Output/" + outputName + ".csv", delimiterList.at(newDelimiterChoice));
				}
				break;
			default:
				break;
			}
			if(actionChoice == 7) break;
		}
 	}
	return 0;
}
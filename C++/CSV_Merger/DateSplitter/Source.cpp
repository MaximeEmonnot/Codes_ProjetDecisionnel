#define _CRT_SECURE_NO_WARNINGS

#include <chrono>
#include <fstream>
#include <format>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>

std::string splitDate(std::string const& date, std::string const& delimiter)
{
	int year{}, month{}, day{}, hour{}, minute{}, second{}, millisecond{};
	std::string output{};
	if(sscanf(date.c_str(), "%d-%d-%d %d:%d:%d.%d", &year, &month, &day, &hour, &minute, &second, &millisecond) == 7)
		output += std::to_string(year) + delimiter + std::to_string(month) + delimiter + std::to_string(day) + delimiter + std::to_string(hour) + delimiter + std::to_string(minute) + delimiter + std::to_string(second) + delimiter + std::to_string(millisecond);
	return output;
}

int main()
{
	while(true)
	{
		std::string file;
		char delimiter{};
		std::cout << "Enter your file name : ";
		std::cin >> file;
		std::cout << "Enter your file's delimiter : ";
		std::cin >> delimiter;

		std::string const csvPath = file + std::string(".csv");
		std::ifstream     in(std::string("Data/") + csvPath);

		std::string       line;
		std::getline(in, line);

		std::vector<std::string> attributes;
		std::stringstream        ss(line);
		std::string              word;
		while(std::getline(ss, word, delimiter))
			attributes.push_back(word);

		std::string delim = std::string(1, delimiter);

		for(size_t i = 0; i < attributes.size(); i++)
			std::cout << i << " : " << attributes.at(i) << std::endl;
		std::cout << "Select the date column to split : " << std::endl;

		int value{};
		std::cin >> value;

		std::ofstream out(std::string("Output/") + csvPath);

		std::string newFileAttributes;
		for(size_t i = 0; i < attributes.size(); i++)
		{
			if(static_cast<int>(i) != value) 
			{
				newFileAttributes += attributes.at(i) + delim;
			}
			else
			{
				newFileAttributes = newFileAttributes + "Year"+ delim +"Month" + delim + "Day" + delim + "Hour" + delim + "Minutes" + delim + "Seconds"+ delim + "Milliseconds" + delim;
			}
		}
		newFileAttributes.pop_back();

		std::cout << "New file attributes : " << newFileAttributes << std::endl;

		out << newFileAttributes << "\n";

		int l = 0;

		while(std::getline(in, line))
		{
			std::cout << "Processing line " << ++l << std::endl;

			std::stringstream        lineSS(line);
			std::vector<std::string> lineValues;
			std::string              lineWord;

			bool bHadQuote{};
			while(std::getline(lineSS, lineWord, delimiter))
			{
				if(lineWord.empty())
					lineValues.push_back({});
				else
				{
					if(bHadQuote)
						lineValues[lineValues.size() - 1].append(delim + lineWord);
					else
						lineValues.push_back(lineWord);

					if(lineWord.at(0) == '"')
						bHadQuote = true;
					if(lineWord.at(lineWord.size() - 1) == '"')
						bHadQuote = false;
				}
			}

			for(size_t i = 0; i < lineValues.size(); i++)
			{
				std::string const val = lineValues.at(i);

				if(static_cast<int>(i) != value)
					out << val;
				else
				{
					out << splitDate(val, delim);
				}

				if(val != lineValues.back())
					out << ",";
				else
					out << "\n";
			}
		}

		std::cout << "Finished processing file" << std::endl;
		out.close();
		in.close();
	}
}
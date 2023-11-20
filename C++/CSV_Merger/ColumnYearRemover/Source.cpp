#define _CRT_SECURE_NO_WARNINGS

#include <chrono>
#include <fstream>
#include <iostream>
#include <map>
#include <regex>
#include <sstream>
#include <string>


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

		std::map<size_t, std::string> years;

		for(size_t i = 0; i < attributes.size(); i++)
		{
			try
			{
				std::cout << "Adding " << std::stoi(attributes.at(i)) << " to years columns" << std::endl;
				years.emplace(i, attributes.at(i));
			}
			catch(...){}
		}
		std::ofstream out(std::string("Output/") + csvPath);

		std::string newFileAttributes;
		for(size_t i = 0; i < attributes.size(); i++)
			if(years.find(i) == years.end())
				newFileAttributes += attributes.at(i) + std::string(1, delimiter);

		newFileAttributes += "Year" + std::string(1, delimiter) + file;

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
						lineValues[lineValues.size() - 1].append(std::string(1, delimiter) + lineWord);
					else
						lineValues.push_back(lineWord);

					if(lineWord.at(0) == '"')
						bHadQuote = true;
					if(lineWord.at(lineWord.size() - 1) == '"')
						bHadQuote = false;
				}
			}

			for(auto const& [index, value] : years)
			{
				std::string newLine;

				for(size_t i = 0; i < lineValues.size(); i++)
				{
					if(years.find(i) == years.end())
					{
						newLine += lineValues.at(i) + std::string(1, delimiter);
					}
					else if(index == i)
					{
						newLine += value + std::string(1, delimiter) + lineValues.at(i);
					}
				}

				out << newLine << "\n";
			}
		}
		
		std::cout << "Finished processing file" << std::endl;
		out.close();
		in.close();
	}
}
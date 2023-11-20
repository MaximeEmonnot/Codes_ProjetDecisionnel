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

		std::string delim = std::string(1, delimiter);

		for(size_t i = 0; i < attributes.size(); i++)
			std::cout << i << " : " << attributes.at(i) << std::endl;

		std::cout << "Select the values column : " << std::endl;
		int values{};
		std::cin >> values;

		std::cout << "Select the Total column : " << std::endl;
		int total{};
		std::cin >> total;

		std::string newFileAttributes;
		for(size_t i = 0; i < attributes.size(); i++)
			if(static_cast<int>(i) != total)
				newFileAttributes += attributes.at(i) + delim;
		newFileAttributes.pop_back();

		std::cout << "New file attributes : " << newFileAttributes << std::endl;

		std::ofstream out(std::string("Output/") + csvPath);
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
			while(lineValues.size() < attributes.size())
				lineValues.push_back({});

			for(size_t i = 0; i < lineValues.size(); i++)
			{
				bool bHasWritten{};
				std::string const val = lineValues.at(i);
				if(static_cast<int>(i) == values)
				{
					bHasWritten = true;
					if(val.empty())
						out << lineValues.at(total);
					else
						out << val;
				}
				else if(static_cast<int>(i) != total)
				{
					bHasWritten = true;
					out << val;
				}


				if(bHasWritten)
				{
					if(i != lineValues.size() - 1)
						out << delim;
					else
						out << "\n";
				}
				else if(i == lineValues.size() - 1)
					out << "\n";
			}
		}

		std::cout << "Finished processing file" << std::endl;
		out.close();
		in.close();
	}
}
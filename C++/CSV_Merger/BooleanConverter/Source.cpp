#define _CRT_SECURE_NO_WARNINGS

#include <chrono>
#include <fstream>
#include <iostream>
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
		std::cout << "Enter your file delimiter : ";
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

		std::cout << "Select the boolean column to convert : " << std::endl;
		for(size_t i = 0; i < attributes.size(); i++)
			std::cout << i << " : " << attributes.at(i) << std::endl;

		int value{};
		std::cin >> value;

		std::ofstream out(std::string("Output/") + csvPath);
		out << line << "\n";

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
						lineValues[lineValues.size() - 1].append(delimiter + lineWord);
					else
						lineValues.push_back(lineWord); 

					if(lineWord.at(0) == '"')
						bHadQuote = true;
					if(lineWord.at(lineWord.size() - 1) == '"')
						bHadQuote = false;
				}
			}

			lineValues[value] = lineValues[value] == "Yes" ? "1" : (lineValues[value] == "No" ? "0" : "");

			for(size_t i = 0; i < lineValues.size(); i++)
			{
				std::string val = lineValues.at(i);
				out << val;

				if(i != lineValues.size() - 1)
					out << delimiter;
				else
					out << "\n";
			}
		}

		std::cout << "Finished processing file" << std::endl;
		out.close();
		in.close();
	}
}
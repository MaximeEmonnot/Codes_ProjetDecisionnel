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

		std::cout << "Select the primary magnitude column : " << std::endl;
		int primary{};
		std::cin >> primary;

		std::cout << "Select the secondary columns (MW - MS - MB - ML - MFA - UNKNOWN) : " << std::endl;
		int mw{}, ms{}, mb{}, ml{}, mfa{}, unk{};
		std::map<int, std::string> magTypes;
		std::cin >> mw >> ms >> mb >> ml >> mfa >> unk;
		magTypes.emplace(mw, "mw");
		magTypes.emplace(ms, "ms");
		magTypes.emplace(mb, "mb");
		magTypes.emplace(ml, "ml");
		magTypes.emplace(mfa, "mfa");
		magTypes.emplace(unk, "unk");

		std::string newFileAttributes;
		for(size_t i = 0; i < attributes.size(); i++)
		{
			if(static_cast<int>(i) != primary && magTypes.find(static_cast<int>(i)) == magTypes.end())
			{
				newFileAttributes += attributes.at(i) + delim;
			}
			else if(static_cast<int>(i) == primary)
			{
				newFileAttributes += "MAGNITUDE" + delim;
			}
			else if(magTypes.find(static_cast<int>(i)) != magTypes.end())
			{
				newFileAttributes += "MAG_TYPE" + delim;
				i = unk;
			}
		}
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

			for(size_t i = 0; i < lineValues.size(); i++)
			{
				bool bHasWritten{};
				std::string const val = lineValues.at(i);
				if(magTypes.find(static_cast<int>(i)) == magTypes.end())
				{
					bHasWritten = true;
					out << val;
				}
				else if(!lineValues.at(i).empty())
				{
					bHasWritten = true;
					out << magTypes[static_cast<int>(i)];
					i = unk;
				}
				else if(lineValues.at(primary).empty())
				{
					bHasWritten = true;
					i = unk;
				}
				if(bHasWritten)
				{
					if(i != lineValues.size() - 1)
						out << delim;
					else
						out << "\n";
				}
			}
		}

		std::cout << "Finished processing file" << std::endl;
		out.close();
		in.close();
	}
}
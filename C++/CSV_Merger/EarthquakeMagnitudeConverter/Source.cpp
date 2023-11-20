#define _CRT_SECURE_NO_WARNINGS

#include <chrono>
#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>

std::string convertMagnitude(std::string type, std::string magnitude)
{
	type.erase(std::remove_if(type.begin(), type.end(), ::isspace), type.end());
	magnitude.erase(std::remove_if(magnitude.begin(), magnitude.end(), ::isspace), magnitude.end());

	if(magnitude.empty()) return magnitude;

	float const mag = std::strtof(magnitude.c_str(), nullptr);

	// Body-wave Magnitude Scale
	if(type == "mb"
	|| type == "Mb"
	|| type == "mb_lg"
	|| type == "mb_Lg"
	|| type == "mblg")
		return magnitude;
	// Duration Magnitude Scale
	if(type == "Md" 
	|| type == "md" 
	|| type == "mdi")
	{
		float const newMag = 2.49f * mag - 0.16f;
		return std::to_string(newMag);
	}
	// Energy Magnitude Scale
	if(type == "me")
	{
		float const newMag = 4.53f * log((mag + 3.2f) * logf(10) - 3.2f) - 2.09f;
		return std::to_string(newMag);
	}
	// Surface-wave Magnitude Scale
	if(type == "ms" 
	|| type == "ms_20")
	{
		float const newMag = 4.53f * log(2.f / 3.f * (4.8f + 1.5f * mag) - 3.2f) - 2.09f;
		return std::to_string(newMag);
	}
	// Moment Magnitude Scale
	if(type == "m"
	|| type == "ma"
	|| type == "mw" 
	|| type == "mwb" 
	|| type == "mwc" 
	|| type == "mwp" 
	|| type == "mwr" 
	|| type == "mww"
	|| type == "Mi")
	{
		float const newMag = 4.53f * log(mag) - 2.09f;
		return std::to_string(newMag);
	}

	return magnitude;
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

		for(size_t i = 0; i < attributes.size(); i++)
			std::cout << i << " : " << attributes.at(i) << std::endl;

		std::cout << "Select the magnitude column to convert : " << std::endl;
		int magnitude{};
		std::cin >> magnitude;

		std::cout << "Select the magnitude type : " << std::endl;
		int type{};
		std::cin >> type;

		std::ofstream out(std::string("Output/") + csvPath);
		out << line << "\n";

		int l = 0;

		std::string delim = std::string(1, delimiter);

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

			if(lineValues.size() >= type && !lineValues.empty())
				lineValues[magnitude] = convertMagnitude(lineValues[type], lineValues[magnitude]);

			for(size_t i = 0; i < lineValues.size(); i++)
			{
				std::string const val = lineValues.at(i);
				out << val;

				if(i != lineValues.size() - 1)
					out << delim;
				else
					out << "\n";
			}
		}

		std::cout << "Finished processing file" << std::endl;
		out.close();
		in.close();
	}
}
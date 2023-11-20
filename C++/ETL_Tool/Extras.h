#define _CRT_SECURE_NO_WARNINGS

#pragma once

#include <iostream>

namespace Debug
{
	inline void Alert(std::string const& message)
	{
		std::cout << message << "\a\n";
	}
}

namespace Transformations
{
	inline auto const Test = [](std::vector<std::string> const& input)
	{
		std::vector<std::string> output;
		output.emplace_back("Test Value");
		return output;
	};

	inline auto const TimestampConverter = [](std::vector<std::string> const& input)
	{
		std::vector<std::string> output;

		auto ms = std::strtoull(input.at(0).c_str(), nullptr, 10);
		std::time_t t = ms / 1000;

		auto* timeinfo = std::localtime(&t);

		std::string year = std::to_string(timeinfo->tm_year + 1900);
		std::string month = std::to_string(timeinfo->tm_mon + 1);
		if(month.size() == 1) month = "0" + month;
		std::string day = std::to_string(timeinfo->tm_mday);
		if(day.size() == 1) day = "0" + day;
		std::string hours = std::to_string(timeinfo->tm_hour);
		if(hours.size() == 1) hours = "0" + hours;
		std::string minutes = std::to_string(timeinfo->tm_min);
		if(minutes.size() == 1) minutes = "0" + minutes;
		std::string seconds = std::to_string(timeinfo->tm_sec);
		if(seconds.size() == 1) seconds = "0" + seconds;
		std::string milliseconds = std::to_string(ms % 1000);
		if(milliseconds.size() == 1) milliseconds = "0" + milliseconds;
		if(milliseconds.size() == 2) milliseconds = "0" + milliseconds;

		output.push_back(year + "-" + month + "-" + day + "T" + hours + ":" + minutes + ":" + seconds + "." + milliseconds + "Z");

		return output;
	};

	inline auto const DateSplitter = [](std::vector<std::string> const& input)
	{
		std::vector<std::string> output;

		int year{}, month{}, day{}, hour{}, minute{}, second{}, millisecond{};
		if(sscanf(input.at(0).c_str(), "%d-%d-%d %d:%d:%d.%d", &year, &month, &day, &hour, &minute, &second, &millisecond) == 7
		|| sscanf(input.at(0).c_str(), "%d-%d-%dT%d:%d:%d.%dZ", &year, &month, &day, &hour, &minute, &second, &millisecond) == 7)
		{
			output.push_back(std::to_string(year));
			output.push_back(std::to_string(month));
			output.push_back(std::to_string(day));
			output.push_back(std::to_string(hour));
			output.push_back(std::to_string(minute));
			output.push_back(std::to_string(second));
			output.push_back(std::to_string(millisecond));
		}
		return output;
	};

	inline auto const BooleanConverter = [](std::vector<std::string> const& input)
	{
		std::vector<std::string> output;

		output.emplace_back(input.at(0) == "Yes" ? "1" : input.at(0) == "No" ? "0" : "");

		return output;
	};

	inline auto const MagnitudeTypeFromColumn = [](std::vector<std::string> const& input)
	{
		std::vector<std::string> output;

		output.emplace_back(input.at(0));
		std::string type{};
		if(!input.at(1).empty()) type = "mw";
		if(!input.at(2).empty()) type = "ms";
		if(!input.at(3).empty()) type = "mb";
		if(!input.at(4).empty()) type = "ml";
		if(!input.at(5).empty()) type = "mfa";
		if(!input.at(6).empty()) type = "unk";
		output.emplace_back(type);

		return output;
	};

	inline auto const MagnitudeConverter = [](std::vector<std::string> const& input)
	{
		std::vector<std::string> output;

		std::string magnitude = input.at(0);
		std::string type      = input.at(1);

		std::erase_if(type,      ::isspace);
		std::erase_if(magnitude, ::isspace);

		if(magnitude.empty()) output.emplace_back(magnitude);
		else
		{
			float const mag = std::strtof(magnitude.c_str(), nullptr);
			// Body-wave Magnitude Scale
			if(type == "mb"
			|| type == "Mb"
			|| type == "mb_lg"
			|| type == "mb_Lg"
			|| type == "mblg")
				output.emplace_back(magnitude);
			// Duration Magnitude Scale
			if(type == "Md"
			|| type == "md"
			|| type == "mdi")
			{
				float const newMag = 0.936f * mag - 0.16f;
				output.emplace_back(std::to_string(newMag));
			}
			// Energy Magnitude Scale
			if(type == "me")
			{
				float const newMag = 4.53f * log((mag + 3.2f) * logf(10) - 3.2f) - 2.09f;
				output.emplace_back(std::to_string(newMag));
			}
			// Surface-wave Magnitude Scale
			if(type == "ms"
			|| type == "ms_20")
			{
				float const newMag = 4.53f * log(2.f / 3.f * (4.8f + 1.5f * mag) - 3.2f) - 2.09f;
				output.emplace_back(std::to_string(newMag));
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
				output.emplace_back(std::to_string(newMag));
			}
		}
		if(output.empty())
			output.emplace_back(magnitude);

		return output;
	};

	inline auto const MoveTotalToValue = [](std::vector<std::string> const& input)
	{
		std::vector<std::string> output;

		if(input.at(0).empty()) output.emplace_back(input.at(1));
		else output.emplace_back(input.at(0));

		return output;
	};

	inline auto const RemoveSpaces = [](std::vector<std::string> const& input)
	{
		std::vector<std::string> output;

		for(std::string value : input)
		{
			std::erase_if(value, ::isspace);
			output.emplace_back(value);
		}

		return output;
	};

	inline auto const ConvertFahrenheitToCelsius = [](std::vector<std::string> const& input)
	{
		std::vector<std::string> output;

		float const fahrenheit = std::strtof(input.at(0).c_str(), nullptr);
		float const celsius = (fahrenheit - 32.f) / 1.8f;

		output.push_back(std::to_string(celsius));
		return output;
	};
}

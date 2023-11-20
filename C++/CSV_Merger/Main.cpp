#include <filesystem>
#include <fstream>
#include <iostream>
#include <regex>

int main()
{
    while(true)
    {
        std::string folder;
        std::cout << "Enter folder to merge : ";
        std::cin >> folder;

        std::string const outputPath = std::string("Output/") + folder + std::string(".csv");

        std::ofstream result(outputPath);
        bool bWroteFirstLine{};

        for(auto const& entry : std::filesystem::recursive_directory_iterator(folder))
        {
            if(entry.path().string().ends_with(".csv"))
            {
                std::cout << "Processing " << entry.path().string() << "..." << std::endl;
                std::ifstream input(entry.path().string());

                std::string line{};
                for(size_t i = 0; std::getline(input, line); i++)
                {
                    if((i == 0 && !bWroteFirstLine) || (i != 0 && bWroteFirstLine))
                    {
                        result << line << "\n";
                        bWroteFirstLine = true;
                    }
                }
            }
        }

        std::cout << "Final CSV generated at " << outputPath << std::endl;
        result.close();
    }

    return 0;
}
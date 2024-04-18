#include "DiskStorage.h"

#include <fstream>
#include <filesystem>
#include <iostream>

#include "../utils/StringUtils.h"
namespace storage
{

    DiskStorage::~DiskStorage()
    {
    }

    bool DiskStorage::SetSourceDestination(const std::string &dest)
    {
        file_ = dest;

        // Update idx with the new destination
        currentIdx_ = GetCurrentIdx();

        // Check if the file can be opened or created
        std::ofstream file(file_, std::ios::app); // This is for truncating -> std::ios::trunc

        if (!file.is_open())
        {
            std::cout << "Failed to open or create the file for order storage" << std::endl;
            return false;
        }
        else
        {
            // Check if the file is first time open and set the title
            if (currentIdx_ == 0)
            {
                file << "#idx;beverage;variety;extra1-extra2;price" << "\n";
            }
        }

        file.close();
        return true;
    }

    bool DiskStorage::StoreOrder(const std::shared_ptr<Order> order)
    {
        std::ofstream file(file_, std::ios::app);

        if (!file.is_open())
        {
            std::cout << "Failed to open the file for order storage" << std::endl;
            return false;
        }

        // Increment the current index and write the order to the file
        currentIdx_++;
        file << currentIdx_ << ";" << order->ToString() << "\n";
        file.close();
        return true;
    }

    bool DiskStorage::RemoveOrder(const int index)
    {
        // Open the file
        std::ifstream inFile(file_);
        if (!inFile.is_open())
        {
            // Failed to open the file
            return false;
        }

        // Create a temporary file
        std::string tempFile = file_ + ".tmp";
        std::ofstream outFile(tempFile);
        if (!outFile.is_open())
        {
            // Failed to create the temporary file
            inFile.close();
            return false;
        }

        // Copy orders from inFile to outFile, except for the order at the specified index
        int currentIndex = 0;
        std::string line;
        while (std::getline(inFile, line))
        {
            if (currentIndex != index)
            {
                outFile << line << "\n";
            }
            currentIndex++;
        }

        // Close the files
        inFile.close();
        outFile.close();

        // Remove the original file
        std::remove(file_.c_str());

        // Rename the temporary file to the original filename
        std::rename(tempFile.c_str(), file_.c_str());

        return true;
    }

    int DiskStorage::GetCurrentIdx()
    {
        // Read the file to determine the current index
        int maxIdx = 0;
        std::ifstream inFile(file_);

        if (inFile.is_open())
        {
            std::string line;
            while (std::getline(inFile, line))
            {
                if (line.empty() || line[0] == '#')
                {
                    // Skip empty lines and lines that dont start with '#'
                    continue;
                }

                // Parse the index from the line
                std::vector<std::string> tokens;
                utils::Tokenize(line, ';', tokens);

                int idx = std::stoi(tokens[0]);
                if (idx > maxIdx)
                {
                    maxIdx = idx;
                }
            }
            inFile.close();
        }
        return maxIdx;
    }

}
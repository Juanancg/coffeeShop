#include "CSVParser.h"

#include <iostream>
#include <sstream>
#include <fstream>

namespace menu
{

    CSVParser::CSVParser()
    {
    }

    CSVParser::~CSVParser()
    {
    }

    bool CSVParser::ParseMenu(const std::string &path)
    {

        menu_.clear();

        std::ifstream file(path);
        if (!file.is_open())
        {
            std::cout << "Error: Could not open CSV file" << std::endl;
            return false;
        }

        std::string line;
        while (std::getline(file, line))
        {
            if (0 < line.size())
            {
                if (line[0] != '#')
                {
                    // Get all the info of line
                    std::vector<std::string> lineTokens;
                    char lineSeparator = ',';
                    utils::Tokenize(line, lineSeparator, lineTokens);

                    if (MAX_FIELDS <= lineTokens.size())
                    {
                        stcBeverageMenuEntry entry;
                        std::string name = lineTokens[BEVERAGE_FIELD];
                        ProcessMenuEntry(lineTokens, entry);
                        SaveRawRules(name, entry);
                        menu_[name].emplace_back(entry);
                    }
                }
            }
        }

        return true;
    }

    void CSVParser::ProcessMenuEntry(const std::vector<std::string> &lineTokens, stcBeverageMenuEntry &entry)
    {

        entry.type = lineTokens[BEV_TYPE_FIELD];
        entry.price = std::stod(lineTokens[BEV_PRICE_FIELD]);

        char secondSeparator = '-';
        utils::Tokenize(lineTokens[EXTRAS_FIELD], secondSeparator, entry.extras);
        utils::Tokenize(lineTokens[RULE_FIELD], secondSeparator, entry.rules);

        auto it = entry.rules.begin();

        while (it != entry.rules.end())
        {
            // If the field is empty
            if (*it == "" || *it == "\"\"")
            {
                it = entry.rules.erase(it); // Erase the element and move iterator to the next one
            }
            else
            {
                ++it;
            }
        }
    }

    void CSVParser::SaveRawRules(const std::string &beverageName, const stcBeverageMenuEntry &entry)
    {
        BeverageVariety beverageVariety = {beverageName, entry.type};

        setRawRules_.insert(std::make_pair(beverageVariety, entry.rules));
    }

} // namespace menu
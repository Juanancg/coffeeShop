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
                    Tokenize(line, lineSeparator, lineTokens);

                    if (MAX_FIELDS <= lineTokens.size())
                    {
                        stcBeverageMenuEntry entry;
                        std::string name = lineTokens[BEVERAGE_FIELD];
                        ProcessMenuEntry(lineTokens, entry);

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
        Tokenize(lineTokens[EXTRAS_FIELD], secondSeparator, entry.extras);
        Tokenize(lineTokens[RULE_FIELD], secondSeparator, entry.rules);
    }

    void CSVParser::SaveRawRules(const std::string &beverageName, const stcBeverageMenuEntry &entry)
    {
        BeverageVariety beverageVariety = {beverageName, entry.type};

        setRawRules_.insert(std::make_pair(beverageVariety, entry.rules));
    }

    void CSVParser::Tokenize(const std::string &line, const char separator, std::vector<std::string> &tokens)
    {
        std::stringstream ssLine(line);

        std::vector<std::string> lineTokens;
        std::string elem = "";
        while (std::getline(ssLine, elem, separator))
        {
            tokens.push_back(elem);
        }
    }

} // namespace menu
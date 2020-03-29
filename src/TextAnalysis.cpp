#include <cstring>
#include <string>
#include <mutex>
#include "TextAnalysis.h"
#include <iostream>

using namespace TA;

TextAnalysis* instance = nullptr;
std::mutex mutex;

TextAnalysis* TextAnalysis::Instance()
{
    std::lock_guard<std::mutex> lock(mutex);
    if(instance == nullptr)
    {
        instance = new TextAnalysis();
    }

    return instance;
}

void TextAnalysis::DefineFilters(const std::vector<Filter>& filters)
{
    _filters = filters;
}

int TextAnalysis::Process(std::istream& in, std::ostream& out)
{
    std::string line;
    while(in.eof() == false)
    {
        std::lock_guard<std::mutex> lock(mutex);
        std::getline(in, line);

        if(line.length() <= 1)
        {
            line += "\n";
            out.write(line.c_str(), line.length());
        }
        else
        {
            for(size_t idx = 0; idx < _filters.size(); idx++)
            {
                std::string copy = line.substr(0, line.length() - 1);
                
                if(_filters[idx].Process(copy))
                {
                    copy += "\n";
                    out.write(copy.c_str(), copy.length());
                }
            }
        }
    }
}
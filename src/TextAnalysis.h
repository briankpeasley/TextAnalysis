#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <memory>
#include <thread>
#include <fstream>
#include <regex>

namespace TA
{
    class Filter
    {
    public:
        Filter(std::string regex)
        {
            _regex = std::regex(regex);
        }

        bool Process(std::string line)
        {
            
            return std::regex_match(line, _regex);
        }

    private:
        std::regex _regex;
    };

    class TextAnalysis
    {
        public:
            static TextAnalysis* Instance();

            void DefineFilters(const std::vector<Filter>& filters);
            int Process(std::istream& in, std::ostream& out);

        private:
            TextAnalysis(){}

            std::vector<Filter> _filters;
    };
}
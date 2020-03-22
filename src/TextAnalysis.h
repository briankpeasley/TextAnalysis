#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <memory>
#include <thread>
#include <fstream>

namespace TA
{
    struct Filter
    {
        std::string RegEx;
    };

    class TextAnalysis
    {
        public:
            ~TextAnalysis();
            static TextAnalysis* Instance();

            void DefineFilters(std::vector<Filter> filters);
            int Open(const char* in, const char* out = nullptr);
            void Close();

        private:
            TextAnalysis(){}

            std::thread _readThread;
            std::vector<Filter> _filters;
            std::istream* _in_stream;
    };
}
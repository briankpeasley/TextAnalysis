#include <cstring>
#include <string>
#include <mutex>
#include "TextAnalysis.h"
#include <iostream>

using namespace TA;

TextAnalysis* instance = nullptr;
std::mutex mutex;

TextAnalysis::~TextAnalysis()
{
    Close();
    if(_readThread.joinable())
    {
        _readThread.join();
    }
}

TextAnalysis* TextAnalysis::Instance()
{
    std::lock_guard<std::mutex> lock(mutex);
    if(instance == nullptr)
    {
        instance = new TextAnalysis();
    }

    return instance;
}

void TextAnalysis::DefineFilters(std::vector<Filter> filters)
{
    _filters.resize(filters.size());
    memcpy(&(_filters[0]), &filters[0], filters.size() * sizeof(Filter));
}

int TextAnalysis::Open(const char* in, const char* out)
{
    printf("opening\n");
    _in_stream = &std::cin;
    
    // // _in_stream.open(in, std::ios_base::openmode::_S_in);
    // if(_in_stream->isis_open() == false)
    // {
    //     printf("couldn't open\b");
    //     return 1;
    // }    

    _readThread = std::thread([this]() -> void 
    {
        std::string line;

        printf("read thread\n");
        while(_in_stream->eof() == false)
        {
            std::lock_guard<std::mutex> lock(mutex);
            // if(_in_stream.is_open() == false)
            // {
            //     break;
            // }
            
            printf("reading line\n");
            getline(*_in_stream, line);
            printf("%s", line.c_str());
        }
    });

    _readThread.detach();
}

void TextAnalysis::Close()
{
    // std::lock_guard<std::mutex> lock(mutex);
    // if(_in_stream.is_open())
    // {
    //     _in_stream.close();
    // }
}
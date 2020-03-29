#include <stdio.h>  
#include <unistd.h>  
#include "TextAnalysis.h"
#include <iostream>

using namespace TA;
int main(int argc, char *argv[])
{
    // int opt; 
      
    // // put ':' in the starting of the 
    // // string so that program can  
    // //distinguish between '?' and ':'  
    // while((opt = getopt(argc, argv, ":e:f:i:o:")) != -1)  
    // {  
    //     switch(opt)  
    //     {  
    //         case 'e':  
    //             printf("option: %c\n", opt);  
    //             break;  
    //         case 'f':  
    //             printf("filename: %s\n", optarg);  
    //             break;  
    //         case ':':  
    //             printf("Usage: ta OPTIONS[-e regex|-f file|-i input file|-o output file]\n");
    //             return 1;
    //             break;  
    //         case '?':  
    //             printf("unknown option: %c\n", optopt); 
    //             return 1;
    //             break;  
    //     }  
    // }

    
    // std::string line;
    // std::getline(std::cin, line);

    // printf("Read line %s\n", line.c_str());

    std::vector<TA::Filter> filters;
    filters.push_back(TA::Filter(".*add.*"));
    
    //std::string test = "    <add key=\"nuget.org\" value=\"https://api.nuget.org/v3/index.json\" />";
    //std::regex rx(".*add.*");

    //printf("%d\n", std::regex_match(test, rx));

    TextAnalysis::Instance()->DefineFilters(filters);
    TextAnalysis::Instance()->Process(std::cin, std::cout);
    
    // // this is sloppy, I know
    // delete TextAnalysis::Instance();
}
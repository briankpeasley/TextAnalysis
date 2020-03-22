#include <stdio.h>  
#include <unistd.h>  
#include "TextAnalysis.h"

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

    printf("opening stdin\n");
    TextAnalysis::Instance()->Open("stdin");
    while(true)
    {
        if(static_cast<int>(getchar()) == 27)
        {
            break;
        }
    }

    // // this is sloppy, I know
    // delete TextAnalysis::Instance();
}
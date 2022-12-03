#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <string>
#include "console.h"
using namespace std;
console::console(int argc,char **argv){
    int opt;
    while((opt = getopt(argc, argv, "i:p:o:r:h")) != -1) {
        switch(opt) {
        case 'i': // ip- adress
            ipLen=strtol(optarg,nullptr,10);
            if(ipLen>9 ) {
                ip = optarg;
            } else {
                std::cerr<<"ipLen must be more 9\n";
                help(argv[0]);
            }
            break;
        case 'p': // port adress
            portLen = char(strtol(optarg,nullptr,10));
            if (portLen=0 ) {
                port=33333;
            } else if (portLen=5) {
                port=char(*optarg);
            } else {
                std::cerr<<"portLen must be equal to 5\n";
                help(argv[0]);
            }
            break;
        case 'a': // name auth file
            NameLen = strtol(optarg,nullptr,10);
            if (NameLen=0) {
                auth="~/.config/vclient.conf";
            } else if (NameLen <= 6) {
               auth=optarg;
            } else {
                std::cerr<<"NameLen must be more 6";
                help(argv[0]);
            }
            break;
        case 'o': // name original file
            NameLen = strtol(optarg,nullptr,10);
            if (NameLen <=6) {
               original=optarg;
            } else {
                std::cerr<<"NameLen must be more 6\n";
                help(argv[0]);
            }
            break;
        case 'r': // name result file
            NameLen = strtol(optarg,nullptr,10);
            if(NameLen<=6 ) {
               Result = optarg;
            } else{
                std::cerr<<"NameLen must be more 6\n";
                help(argv[0]);
            }
            break;
        case 'h': // help
        case '?': // неверный параметр
        case ':': // нет значения у параметра
            help(argv[0]);
        }        
    }
}

void console::help(const char* progName){
    cout<<"Usage: "<< progName<< "\n -i server address, \n -o name original file, \n -r name result file,\n [-p port servera],\n [-a name auth file]\n";
    exit(1);
}

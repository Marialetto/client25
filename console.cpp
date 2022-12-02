#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <string>
#include "console.h"
using namespace std;
console::console(int argc,char **argv){
int in_string;
while((in_string = getopt(argc, argv, "i:p:o:r:h")) != -1) {  
    switch(in_string) { 
    case 'i': // ip- adress
        help(argv[0]);
        break;
    case 'p': // port adress
        port="33333";
        help(argv[0]);
        break;
    case 'a': // name auth file
        auth="vclient.vonf";
        help(argv[0]);
        break;
    case 'o': // name original file
        help(argv[0]);
        break;
    case 'r': // name result file
        help(argv[0]);
        break;
    case 'h': //  help 
        help(argv[0]);
        break;
    default:
        cout <<"-h:" << endl;
        help(argv[0]);
        }
    } 
}
void console::help(const char* progName){
    cout<<"Usage: "<< progName << " [-i ip adress servera][-p port servera][-a name auto file][-o name original file][-r name result file]/n";
    exit(1);
}
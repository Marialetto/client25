#include "console.h"
using namespace std;
console::console(int argc,char **argv){
    int opt;
    while((opt = getopt(argc, argv, "i:p:o:r:a:h")) != -1) {
        switch(opt) {
        case 'i': // ip- adress
                ip = string(optarg);
            break;
        case 'p': // port adress
                port=strtol(optarg,nullptr,10);
            break;
        case 'a': // name auth file
                auth=string(optarg);
            break;
        case 'o': // name original file
               original=string(optarg);
           break;
        case 'r': // name result file
               Result= string(optarg);
            break;
        case 'h': // help
        case '?': // неверный параметр
        case ':': // нет значения у параметра
            help(argv[0]);
        }
    }
        //если не установлен не один из обязательных параметраметров - выход
        if (!useIp || !useOriginal || !useResult) {
        	useIp  = useOriginal  = useResult =  false;
        	help(argv[0]);    
    } 
}

// краткая справки и досрочное завершение программы
void console::help(const char* progName){
    cout<<"Usage: "<< progName<< "\n -i server address, \n -o name original file, \n -r name result file,\n [-p port servera],\n [-a name auth file]\n";
    exit(1);
}

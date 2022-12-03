#pragma once
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <string>
using namespace std;
class console{
private:
    unsigned short int port=33333;
    int portLen;
    int ipLen;
    int NameLen;
    string auth="~/.config/vclient.conf";
    string ip;
    string original;
    string Result;
    void help(const char *progName);
public:
    console()=delete;
    console (int argc,char **argv);
    string getIP(){return ip;}
    string getPort(){return port;}
    string getAuth(){return auth;}
    string getOriginal(){return original;}
    string getResult(){return Result;}
};

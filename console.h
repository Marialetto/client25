#pragma once
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <string>
using namespace std;
class console{
private:
    string port="33333";
    string auth="vclient.vonf";
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

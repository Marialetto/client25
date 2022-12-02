#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <string>
#include "console.h"
//#include "conect.h"
//#include "operator.h"
using namespace std;
int main(int argc, char **argv){
    console op(argc,argv);
    cout<<op.getIP()<<endl;
    cout<<op.getPort()<<endl;
    cout<<op.getAuth()<<endl;
    cout<<op.getOriginal()<<endl;
    cout<<op.getResult()<<endl;
    return(0);
}

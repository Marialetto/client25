#include "console.h"
#include "connect.h"
#include "operator.h"
using namespace std;
int main(int argc, char **argv){
//concole.h
    console op(argc,argv);
    cout<<op.getIP()<<endl;
    cout<<op.getPort()<<endl;
    cout<<op.getAuth()<<endl;
    cout<<op.getOriginal()<<endl;
    cout<<op.getResult()<<endl;
//operator.h
    Operator o(const char *original,const char *Result);
//connect.h
    connect c(unsigned short int port, string ip);
return 0;
}

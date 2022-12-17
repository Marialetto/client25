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

//connect.h
    connect c;

    //connect to host
    c.conn(host , port);
     
    //send some data
    c.send_data(".....");
     
    //receive and echo reply
    cout<<"----------------------------\n\n";
    cout<<c.receive(1024);
    cout<<"\n\n----------------------------\n\n";
   
    return 0;
}

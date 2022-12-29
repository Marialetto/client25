#include "console.h"
//#include "connect.h"
#include "operator.h"
using namespace std;

int main(int argc, char **argv)
{
console a(argc,argv);
/* concole.h
	cout<<a.getIP()<<endl;
	cout<<a.getPort()<<endl;
	cout<<a.getAuth()<<endl;
	cout<<a.getOriginal()<<endl;
	cout<<a.getResult()<<endl;*/
Filer op(a);
/* operator.h
	op.Write(1);
	op.Write(2)
	op.Write(3));*/
cout<<op.getAmount()<<endl;
for (int i=0; i < op.getAmount(); i++)
{
	uint16_t * v = op.getVector(i);
	uint32_t s = op.getVectorSize(i);
	cout<<s<<endl;
	for (int i=0; i < s; i++)
	    cout<<'\t'<<v[i]<<endl;
	    }
cout<<"login: "<<op.getLogin()<<endl;	
cout<<"pswd: "<<op.getPswd()<<endl;	   
//connect.h
//Web m(a,op);
return 0;
}

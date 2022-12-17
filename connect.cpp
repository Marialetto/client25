#include "connect.h"
using namespace std;

//Connect to a host on a certain port number
bool connect::conn(string address , unsigned short int port)
{
    if(sock == -1)
    {
        sock = socket(AF_INET , SOCK_STREAM , 0);
        if (sock == -1)
        {
            perror("Could not create socket");
        }
         
        cout<<"Socket created\n";
    }  
    if(inet_addr(address.c_str()) == -1)
    {
        struct hostent *he;
        struct in_addr **addr_list;
         
        if ( (he = gethostbyname( address.c_str() ) ) == NULL)
        {
            herror("gethostbyname");
            cout<<"Failed to resolve hostname\n";
            return false;
        }
         
        addr_list = (struct in_addr **) he->h_addr_list;
 
        for(int i = 0; addr_list[i] != NULL; i++)
        {
            server.sin_addr = *addr_list[i];
             
            cout<<address<<" resolved to "<<inet_ntoa(*addr_list[i])<<endl;
             
            break;
        }
    }
     
    else
    {
        server.sin_addr.s_addr = inet_addr( address.c_str() );
    }
    server.sin_family = AF_INET;
    server.sin_port = htons( port );
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        perror("connect failed. Error");
        return 1;
    }
    cout<<"Connected\n";
    return true;
}
    //Отправить данные на подключенный хост
bool connect::send_data(vector<uint16_t>in)
{
    if( send(sock , data.c_str() , strlen( data.c_str() ) , 0) < 0)
    {
        perror("Send failed : ");
        return false;
    }
    cout<<"Data send\n";
     
    return true;
}

string connect::receive(int size=512,vector<uint16_t>out)
{
    char buffer[size];
    string reply;
     
    if( recv(sock , buffer , sizeof(buffer) , 0) < 0)
    {
        puts("recv failed");
    }
     
    reply =vector<uint16_t>out;
    return reply;
}
 

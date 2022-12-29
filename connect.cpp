#include "connect.h"
using namespace std;

#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
using namespace CryptoPP;

Web::Web(const console & a,const Filer& op):caddr(new sockaddr_in),saddr(new sockaddr_in) {
   	caddr->sin_port = htons(a.getPort());
    caddr->sin_addr.s_addr = inet_addr(a.getIP().c_str());
    
    saddr->sin_family = AF_INET;
   	saddr->sin_port = 0;
    saddr->sin_addr.s_addr =0;
    
    Socket = socket(AF_INET, SOCK_STREAM, 0);
    if (Socket == -1) {
        cerr << "Error open socket\n";
        close(Socket);
        exit(1);
    }
    
    login=op.getLogin();
    pswd=op.getPswd();
}

void Web::Install(){
    int rc = bind(Socket, (const sockaddr *) saddr, sizeof (sockaddr_in));
    if (rc == -1) {
        cerr <<"Error bind socket with local address\n";
        close(Socket);
        exit(1);
    }

    rc = connect(Socket, (const sockaddr*) caddr, sizeof(sockaddr_in));
    if (rc == -1) {
        cerr <<"Error connect socket with server\n";
        close(Socket);
        exit(1);
    }
}

void Web::Auth() {
    char *buf = new char[2048];
    msg = login.copy(buf,login.length()); // копируем строку c login
    send(Socket, buf, login.length(), 0);//отправляем login

    recv(Socket, buf, sizeof(buf), 0);//получаем ответ
    if (string(buf) == "ERR") {
        cerr <<"Not found login\n";
        close(Socket);
        exit(1);
    }
	msg=string(buf)+pswd;
    Weak::MD5 hash;
    StringSource(msg, true,new HashFilter(hash,new HexEncoder(new StringSink (Hash))));
    msg = Hash.copy(buf,Hash.length()); // копируем строку c hash
    send(Socket, buf, Hash.length(), 0); // отправляем  hash
    if (string(buf)== "ERR") {
        cerr <<"Error of auth\n";
        close(Socket);
        exit(1);
    }
   delete[] buf;  
}

void Web::Sending(int Socket,char* buf, size_t size) {
    int rc = send(Socket, (const void*) &buf, sizeof(buf), 0);
    if (rc == -1) {
        cerr <<"Error send message\n";
        close(Socket);
        exit(1);
    }
}

int Web::Receiving(int Socket) {
uint16_t piece;
    int rc = recv(Socket,(void*) &piece, sizeof(piece), 0);
    if (rc == -1) {
        cerr <<"Error receive answer\n";
        close(Socket);
        exit(1);
    }
    
    return piece;
}

Web::~Web() {
	delete caddr;
	delete saddr;
    }

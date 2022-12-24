#include "connect.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
using namespace std;
#define bufSize 512 

#include <cryptopp/cryptlib.h>
#include <cryptopp/hex.h>
#include <cryptopp/files.h>
#include <cryptopp/md5.h>
using namespace CryptoPP;
#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
   
void connect::connect(int Socket,unsigned short int port, string ip)
{
    //Адрес программы-клиента
    sockaddr_in *cAddr = new (sockaddr_in);
    cAddr->sin_family = AF_INET; 
   	cAddr->sin_port = 0; 
    cAddr->sin_addr.s_addr = 0;
    
    //Адрес программы-сервера
    sockaddr_in * sAddr = new (sockaddr_in);
    sAddr->sin_family = AF_INET; 
    sAddr->sin_port = htons(port); 
    sAddr->sin_addr.s_addr = inet_addr(ip); // все адреса нашего пк
    
    //буфер для передачи и приема данных
  	char *buf = new char[bufSize];
    
    // создание сокета
    Socket = socket(AF_INET, SOCK_STREAM, 0);//TCP 
    if (Socket == -1) {
    	cerr << "Error open socket\n";
        close(Socket);
        exit(1);
    }
    int rc = bind(Socket, (const sockaddr *) cAddr, sizeof (sockaddr_in));
    if (rc == -1) {
    	cerr <<"Error bind socket with local address\n";
        close(Socket);
        exit(1);
    }
    //установка соединения
    rc = connect(Socket, (const sockaddr*) sAddr, sizeof(sockaddr_in));
    if (rc == -1) {
        cerr <<"Error connect socket with server\n";
        close(Socket);
        exit(1);
    }
 }`
 
void connect::Auth(string auth)
{
char buf [bufSize];
int msgLen = auth.length(); // вычисляем длину строки
size_t length = auth.copy(buf,msgLen); // копируем строку
rc=send(Socket, buf, sizeof(buf), 0);// Отправляем файл для аутентификации
delete[] buf;
int msgLen = username.length(); // вычисляем длину строки
size_t length = username.copy(buf,msgLen); // копируем строку
rc=send(Socket, buf, sizeof(buf), 0);// Отправляем файл для аутентификации
delete[] buf;
bytes_read = recv(sock, buf, sizeof(buf), 0); //Принимаем строку с SALT или ошибку ERR
buf[bytes_read] = '\0';
string s1 = string(buf);
 if (s1 == "ERR")
 {
    cerr << "Identification error" << endl;
    close(Socket);
    exit(1);
 }
 else 
 {
 string s2 = s1 + pswd;
 int msgLen = s2.length(); // вычисляем длину строки
 size_t length = s2.copy(buf,msgLen); // копируем строку
 string hash,Hash;
 Weak::MD5 hash;
StringSource(hash, true, new HashFilter(hash, new HexEncoder(new StringSink (Hash))));

 int msgLen = Hash.length(); // вычисляем длину строки
 size_t length = Hash.copy(buf,msgLen); // копируем строку
 send(Socket, buf, sizeof(buf), 0);// Отправка хэша-кода от SALT+PASSWORD
 delete[] buf;
 bytes_read = recv(sock, buf, sizeof(buf), 0);// Получене ответа об аутентификации
 buf[bytes_read] = '\0';
 string s3 = string(buf);
 if (s3 == "ERR")
 	{
    cerr << "Identification error" << endl;
    close(Socket);
    exit(1);
    } 
 }
} 


void connect::Send()//Отправка данных на сервер
{ 
void Operator::read(const char *original, vector<uint16_t>in);
char buf [bufSize];
int msgLen = in.size().length(); // вычисляем длину строки
size_t length = str.copy(buf,msgLen); // копируем строку
while (true)
 {
 rc = send(Socket, buf,msgLen,0);
 if (rc == -1) {
     cerr <<"Error send message\n";
     close(Socket);
     exit(1);
    }
 	cout << "Data from " << origunal << " send" <<endl;
 }
 delete[] buf;
}

void connect::Receive()  //Получение данных от сервера
{
 char buf [bufSize];
 int msgLen = str.length(); // вычисляем длину строки
 size_t length = str.copy(buf,msgLen); // копируем строку
 while (true) {
 rc = recv(Socket, buf, bufSize,0);
 if (rc == -1) {
      cerr <<"Error receive answer\n";
      close(Socket);
      exit(1);
    }
 	buf[rc]='\0';
 	void Operator::write(const char *Result, vector<uint16_t>out)
 	cout << "Data receive from  server write " << Result<<endl;
 	delete cAddr;
	delete sAddr;
 	delete[] buf;
 	close(Socket);
}

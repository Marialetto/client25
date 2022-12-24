#pragma once
#include <iostream>    //cout
#include <string>  //string
#include <sys/socket.h>    //socket
#include <arpa/inet.h> //inet_addr
#include <cstdlib>
#include <unistd.h>
#include <netinet/in.h>
using namespace std;
#define bufSize 512 

#include <cryptopp/cryptlib.h>
#include <cryptopp/hex.h>
#include <cryptopp/files.h>
#include <cryptopp/md5.h>
using namespace CryptoPP;
#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
class connect{
private:
	int sock;
	string ip;
	unsigned short int port;	
	string username;
	string auth;
	string hash,Hash;
public:
	connect()=delete;
	connect(int Socket,unsigned short int port, string ip);//установка соединения
   	void Auth(string auth);//авторизация
    	void Send();//Отправка данных на сервер
    	void Receive(); //Получение данных от сервера
};

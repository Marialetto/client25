#pragma once
#include<iostream>    //cout
#include<stdio.h> //printf
#include<string.h>    //strlen
#include<string>  //string
#include<sys/socket.h>    //socket
#include<arpa/inet.h> //inet_addr
#include<netdb.h> //hostent
 
using namespace std;

class connect{
private:
vector<uint16_t>out;
vector<uint16_t>out;
   int sock;
   string address;
   unsigned short int port;
   struct sockaddr_in server;
   string username;
public:
	connect()=delete;
 	connect()=delite;
    connect(sock, port ,ip);
    bool conn(string, int);
    bool send_data(vector<uint16_t>out);
    string receive(int);
};

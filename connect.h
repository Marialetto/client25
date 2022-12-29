#pragma once
#include "console.h"
#include "operator.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
using namespace std;

#include <cryptopp/cryptlib.h>
#include <cryptopp/hex.h>
#include <cryptopp/files.h>
#include <cryptopp/filters.h>
#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
#include <cryptopp/md5.h>

using namespace CryptoPP;

/**
@brief Класс, обеспечивающий авторизацию и взоимодействие между клиентом и сервером
*/

class Web
{
private:
    sockaddr_in * saddr;///<Cтруктура с адресом программы клиента
    sockaddr_in * caddr;///<Cтруктура с адресом программы сервера
    int Socket; ///< Основной сокет
    string login;///< Логин для авторизации
    string pswd;///< Пароль для авторизации
    string msg;///< Сообщение для отправки данных 
    string hash;///< Данные для шифрованич
    string Hash;///< Зашифрованный пароль
public:
    Web()=delete;///<запрет конструктора без параметров

    /**
    *@brief Конструктор
    *@details Устанавливает порт IP и авторизациооные данные, инициализирует основной сокет и структуры sockaddr_in
     **/
    Web(const console & a,const Filer& op);
    ~Web();//<дecтруктор
    void Install();///<Установка соединения между клиентом и сервером
    void Auth();///<Авторизация клиента на сервере

    /**
    *@brief Приём данных
    *@param [in] socket, сокет
    **/
    int Receiving(int Socket);

    /**
    *@brief Отправка данных
    *@param [in] socket, сокет
    *@param [in] buf, буфер с данными
    *@param [in] size, количество отправляемых байт
    **/
    void Sending(int Socket, char* buf, size_t size);
};

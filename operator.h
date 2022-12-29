#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "console.h"

using namespace std;
//@brief Структура,для хранения данных записанных из исходного файла
struct VectData{
    uint32_t VecSize;///<размер вектора
    vector<uint16_t> *vec;///<вектор со значениями
};

//@brief Класс, обеспечивающий работу с файлами
class Filer
{
private:
    ifstream orFileName;///<Открытие оригинального файла для чтения
    ifstream authFileName;//<Открытие файла с авторизациооными данными для чтения
    ofstream resFileName;///<Открытие файла для записи результатов
    uint32_t amount;///<количество векторов
    vector<VectData>all_data;///<вектор с данными из структуры
    string login;///< Логин для авторизации
   	string pswd;///< Пароль для авторизации
    
public:
    Filer()=delete;///<запрет конструктора без параметров
    /**
    * @brief Конструктор, внутри которого инцелизируются параметры из командной строки
    * @param [in] ifstream original - Открытие файла c исходными данными для чтения
    * @param [in] ofstream Result -Открытие файла c результатами для записи
    * @param [in] authFileName, путь к файлу, на котором находятся
    **/
    Filer(const console & a);
    ~Filer();///<дecтруктор
    void Write(uint16_t piece){resFileName<<' '<<piece; }///<Запись результатов в файл
    uint32_t getVectorSize(unsigned int numVec){return all_data[numVec].VecSize;}///<Размер одного вектора
    uint16_t* getVector(unsigned int numVec){return all_data[numVec].vec->data();}///<Номер вектора
    uint32_t getAmount(){return amount;}///<Логин для авторизации
    string getLogin()const {return login;}///<Колличество векторов
    string getPswd()const {return pswd;}///<Пароль для авторизации
};

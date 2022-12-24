#pragma once
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
class Operator{
private:
	const char *original;
	const char *Result;
	uint16_t line;
   	vector<uint16_t>in;
    	vector<uint16_t>out;
public:
    	Operator()=delete;
	Operator(const char *original,const char *Result);
	void read(const char *original, vector<uint16_t>in, uint16_t line);
   	void write(const char *Result, vector<uint16_t>out, uint16_t line);
};

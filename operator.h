#pragma once
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
class Operator{
private:
	uint16_t n;
    vector<uint16_t>in;
    vector<uint16_t>out;
    uint16_t num_vectors;
    uint16_t vectorLen;
    uint16_t num_vector;
    void read();
    void write();
public:
    Operator()=delete;
    Operator(uint16_t);
};

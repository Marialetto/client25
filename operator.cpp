#include "operator.h"
using namespace std;
const char *original="original.txt";
void Operator::read(const char *original, vector<uint16_t>in, uint16_t line){
ifstream file(original);
if (!file) {
	cerr<<"No open original file\n";
	exit(1);
}
while (!file.eof()){
	file >> line;
	in.push_back(line);
}
	file.close();
}

const char *Result="Result.txt";
void Operator::write(const char *Result, vector<uint16_t>out, uint16_t line){
ofstream file(Result);
if (!file) {
    cerr<<"No open result file\n";
    exit(1);
}
while (!file.eof()) {
       file << line;
       out.push_back(line);
}
       file.close();
}

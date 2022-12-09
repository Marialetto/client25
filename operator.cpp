#include "operator.h"
using namespace std;
void Operator::read(){
    //uint16_t n;
    //vector<uint16_t> in;
    ifstream file(original);
	if (!file) {
        std::cerr<<"No open original file\n";
        exit(1);
}
    while (!file.eof())
    {
        file >> n;
        in.push_back(n);
    }
    file.close();
	}


void Operator::write() {
	//uint16_t n;
 	//vector<uint16_t> out;
    ifstream file(Result);
    if (!file) {
        std::cerr<<"No open result file\n";
        exit(1);
    } else {
         cout <<"File is open for write\n";
         while (!file.eof()) {
         		file << n;
               	out.push_back(n);
         }
        file.close();
        }
    }

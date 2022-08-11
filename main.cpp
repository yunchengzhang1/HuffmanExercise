#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    std::cout << "Trying to read binary file" << std::endl;

    return 0;
}


void readBinaryFile(string const& filename)
{
    ifstream input(filename.c_str(), ios::in | ios::binary);
    char c;
    while (input.get(c)) {
        cout<<c<<endl;
    }
}
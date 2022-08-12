
#include "Runner.h"
// source for reading binary file: https://cplusplus.com/forum/beginner/21548/

using std::string;
using std::ifstream;
using std::ios;


int main() {
    std::cout << "Trying to read binary file" << std::endl;
    ifstream inFile;
    size_t size = 0; // here

    inFile.open( "test.txt", ios::in|ios::binary|ios::ate );
    char* oData = 0;

    inFile.seekg(0, ios::end); // set the pointer to the end
    size = inFile.tellg() ; // get the length of the file
    std::cout << "Size of file: " << size;
    inFile.seekg(0, ios::beg); // set the pointer to the beginning

    oData = new char[ size+1 ]; //  for the '\0'
    inFile.read( oData, size );
    oData[size] = '\0' ; // set '\0'
    std::cout << " oData size: " << strlen(oData) << "\n";

    //print data
    for ( size_t i = 0; i < strlen(oData); i++ )
    {
        std::cout << "oData["<<i<<"] ";
        std::cout <<"["<< oData[i];
        std::cout << "]\n\n";
    }
    getchar();

    return 0;
}


void readBinaryFile(string const& filename)
{

}
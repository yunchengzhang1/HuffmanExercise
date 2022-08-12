//
// Created by AZ on 8/11/2022.
//

#include "Runner.h"
void Runner::run(string const& filename){
    readBinaryFile(filename);
    print_vec();
}

void Runner::readBinaryFile(string const& filename){
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
        std::cout <<"["<< oData[i]<<"]"<<std::endl;
        insert_to_vec(oData[i]);
    }
    sort(nodes.begin(), nodes.end()); //after shuffling in all characters, sort the vector
}

void Runner::insert_to_vec(char const& c){
    // if find the current c in nodes, freq++
    auto itr = std::find(nodes.begin(), nodes.end(), c);
    if( itr != nodes.end()){
//        std::cout<<"found"<<std::endl;
        itr->inc_freq();
    }
    else{//else insert a new node to vector
        Node tempNode(c);
        nodes.push_back(tempNode);
    }
}

void Runner::print_vec(){
    for (auto x : nodes){
        std::cout<< x.c <<" "<<x.freq<<std::endl;
    }
}

bool comparator(const Node& lhs, const Node& rhs) {
    return lhs.freq < rhs.freq;
}

//
// Created by AZ on 8/11/2022.
//

#ifndef HUFFMANEXERCISE_RUNNER_H
#define HUFFMANEXERCISE_RUNNER_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm> //find
#include <cstring> // for std::strlen
#include "Node.h"

using std::string;
using std::vector;
using std::ifstream;
using std::ios;

class Runner {
private:
    vector<Node> nodes;
public:
    void run(string const& filename);
    void readBinaryFile(string const& filename);
    void insert_to_vec(char const& rhs);
    //for testing
    void print_vec();
};


#endif //HUFFMANEXERCISE_RUNNER_H

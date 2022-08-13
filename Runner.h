//
// Created by AZ on 8/11/2022.
//

#ifndef HUFFMANEXERCISE_RUNNER_H
#define HUFFMANEXERCISE_RUNNER_H

#include <vector>
#include <list>
#include <iostream>
#include <fstream>
#include <algorithm> //find
#include <cstring> // for std::strlen
#include "Node.h"

using std::string;
using std::vector;
using std::ifstream;
using std::ios;
using std::list;

class Runner {
private:
    vector<Node> nodes;
    vector<Node> nodes_tree; //the set of nodes that updates as building the tree
    list<Node> leaves;

public:
    void run(string const& filename);
    void readBinaryFile(string const& filename);
    void insert_to_vec(string const& rhs);
    Node * tree_building();
    Node * get_leaf(); //pop a node from nodes_tree, put this node into leaves, and get its address
    void print_vec( vector<Node>* ); //for testing
};


#endif //HUFFMANEXERCISE_RUNNER_H

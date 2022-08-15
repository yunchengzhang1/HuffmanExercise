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
#include <bits/stdc++.h>
#include <map>

#define M 16 //use for bitset

using std::string;
using std::vector;
using std::ifstream;
using std::ios;
using std::list;
using std::map;

class Runner {
private:
    vector<Node> nodes;
    vector<Node> nodes_tree; //the set of nodes that updates as building the tree
    list<Node> leaves;
//    std::bitset<M> init_bits; // paused, finding a way to append bits to bitse
    string init_bits;
    map<string, string> bits; //to keep track of all the bits
    vector<string> bytes; //to keep track of all the bytes in file
    vector<Node> full_nodes; //vector of nodes ordered by depth-first post order traversing the Node tree
public:

    void run(string const& filename);
    void readBinaryFile(string const& filename);
    void insert_to_vec(string const& rhs);
    Node * tree_building();
    Node * get_leaf(); //pop a node from nodes_tree, put this node into leaves, and get its address
    void print_vec( vector<Node>* ); //for testing
//    void traverse_tree(Node, std::bitset<M>); //paused, finding a way to append bits to bitset
    void traverse_tree(Node, string);
    void store_bits(); //convert bytes to bits and export
    void store_tree(); //store the Node tree in the file for later decompress
};


#endif //HUFFMANEXERCISE_RUNNER_H

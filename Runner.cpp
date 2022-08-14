//
// Created by AZ on 8/11/2022.
//

#include "Runner.h"
void Runner::run(string const& filename){
    readBinaryFile(filename);
    print_vec(&nodes);
    tree_building();
    traverse_tree(nodes_tree[0], init_bits);
    std::cout << "tree traverse done" << std::endl;
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
        string s(1, oData[i]);
        insert_to_vec(s);
    }
    sort(nodes.begin(), nodes.end()); //after shuffling in all characters, sort the vector in descending order for POP_BACK
}

Node * Runner::tree_building() {
    std::cout<<"now begin building the tree"<<std::endl;
    nodes_tree = nodes; //update empty nodes_tree to nodes as a default
    while (nodes_tree.size() > 1){ //while there are more than 1 node in nodes_tree, couple up nodes
        Node *lhs = get_leaf();
        Node *rhs = get_leaf();
        Node parent(lhs, rhs);
        std::cout<<parent.freq<<std::endl;
        nodes_tree.push_back(parent); //push back the new parent node
        sort(nodes.begin(), nodes.end()); //again sort the vector in descending order
    }//the last remaining node becomes the root of this tree
    std::cout<<"end of tree building"<<std::endl;
}

Node * Runner::get_leaf() {
    Node n = nodes_tree.back();
    nodes_tree.pop_back(); //getting and popping the last element of nodes_tree
    leaves.push_back(n);
    return &leaves.back(); //insert and getting the new element in leaves
}

void Runner::traverse_tree(Node n,string bitset){
    //traverse through nodes_tree

    if (n.left != NULL){
        bitset.append("0");
        traverse_tree(* n.left, bitset);
        bitset.pop_back();
    }
    if (n.right != NULL){
        bitset.append("1");
        traverse_tree(* n.right, bitset);
        bitset.pop_back();
    }
    if (n.c.length() ==1){
        std::cout<<n.c <<" " <<bitset <<std::endl;
    }
    return;
}


void Runner::insert_to_vec(string const& c){
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

void Runner::print_vec( vector<Node>* n){
    for (auto x : *n){
        std::cout<< x.c <<" "<<x.freq<<std::endl;
    }
}


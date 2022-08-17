//
// Created by AZ on 8/11/2022.
//

#include "Runner.h"
void Runner::run(string const& inputFile, string const& treeFile, string const& bitsFile){
    readBinaryFile(inputFile);
    tree_building();
    traverse_tree(nodes_tree[0], init_bits);
    std::cout << "tree traverse done" << std::endl;
    store_bits(bitsFile);
    store_tree(treeFile);
    reconstruct_tree(treeFile);
    decompress(bitsFile);
}

void Runner::readBinaryFile(string const& filename){
    std::cout << "Trying to read binary file" << std::endl;
    ifstream inFile;
    size_t size = 0; // here

    inFile.open( "test.txt", ios::in|ios::binary|ios::ate );
    char* oData = 0;

    inFile.seekg(0, ios::end); // set the pointer to the end
    size = inFile.tellg() ; // get the length of the file
//    std::cout << "Size of file: " << size;
    inFile.seekg(0, ios::beg); // set the pointer to the beginning

    oData = new char[ size+1 ]; //  for the '\0'
    inFile.read( oData, size );
    oData[size] = '\0' ; // set '\0'
//    std::cout << " oData size: " << strlen(oData) << "\n";

    //print data
    for ( size_t i = 0; i < strlen(oData); i++ )
    {
//        std::cout << "oData["<<i<<"] ";
//        std::cout <<"["<< oData[i]<<"]"<<std::endl;
        string s(1, oData[i]);
        bytes.push_back(s);
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

Node * Runner::get_rec_leaf() {
    Node n = leaf_stack.top();
    leaf_stack.pop();
    reconstruct_leaves.push_back(n);
    return &reconstruct_leaves.back(); //insert and getting the new element in leaves
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
        bits.insert({n.c, bitset});
    }
    full_nodes.push_back(n);
    return;
}

void Runner::store_bits(string const& bitsFile){
    std::ofstream ofile;
    if (bitsFile =="")
        ofile.open( "bits.txt");
    else {ofile.open(bitsFile);}
    for (int i=0; i<bytes.size(); i++){
        string bitlist = bits.find(bytes[i])->second;
        ofile<<bitlist<<std::endl;
    }
    std::cout<<"bits file stored"<<std::endl;
}

void Runner::store_tree(string const& treeFile){
    std::ofstream ofile;
    if (treeFile =="")
        ofile.open( "tree.txt");
    else {ofile.open(treeFile);}
    if (ofile.is_open()){
        for (int i=0; i<full_nodes.size(); i++){
            string bitlist = full_nodes[i].c;
            bitlist.push_back('\0');
            ofile<<bitlist;
        }
        std::cout<<"tree file stored"<<std::endl;
    }
}

void Runner::reconstruct_tree(string const& treeFile) {
    std::cout << "Trying to reconstruct tree" << std::endl;
    ifstream inFile;
    size_t size = 0; // here
    if (treeFile =="")
        inFile.open( "tree.txt");
    else {inFile.open(treeFile);}
    string line;
    while (std::getline(inFile, line, '\0')){
        if (line.size() == 1){ //if is a leaf: one character EX: a
            leaf_stack.push(Node(line));
        }
        else{//if is a node: more than one char, ex: abc
            Node tempNode(line);
            tempNode.right = get_rec_leaf(); //set tempNode's right to a reference
            tempNode.left = get_rec_leaf(); //set tempNode's left to a reference
            leaf_stack.push(tempNode); //push the new node to stack as leaf until reach the root
        }
    }
    reconstructed = leaf_stack.top();
    std::cout<<"reconstruction done"<<std::endl;
}

void Runner::insert_to_vec(string const& c){
    // if find the current c in nodes, freq++
    auto itr = std::find(nodes.begin(), nodes.end(), c);
    if( itr != nodes.end()){
        itr->inc_freq();
    }
    else{//else insert a new node to vector
        Node tempNode(c);
        nodes.push_back(tempNode);
    }
}

void Runner::decompress(string const& bitsFile){
    std::cout << "Trying to decompress file" << std::endl;
    ifstream inFile;
    size_t size = 0; // here
    string decomp;
    if (bitsFile =="")
        inFile.open( "bits.txt");
    else {inFile.open(bitsFile);}
    string code;
    while (inFile >> code){
        string character =convert(code);
        decomp.append(character);
    }
    std::cout << "Decompress finished: " << std::endl;
    std::cout << "============================================== " << std::endl;
    std::cout<<decomp<<std::endl;
    std::cout << "============================================== " << std::endl;
}

string Runner::convert(string s){
    Node* it = &reconstructed;
    for (int i =0; i<s.length(); i++){
        if(s[i] == '0'){
            it = it->left;
        }
        else if (s[i]=='1'){
            it = it->right;
        }
    }
    return it->c;
}

void Runner::print_vec( vector<Node>* n){
    for (auto x : *n){
        std::cout<< x.c <<" "<<x.freq<<std::endl;
    }
}


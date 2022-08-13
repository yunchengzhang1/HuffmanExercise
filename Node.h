//
// Created by AZ on 8/11/2022.
//

#ifndef HUFFMANEXERCISE_NODE_H
#define HUFFMANEXERCISE_NODE_H
#include <string>

using std::string;

struct Node {
    //character itself
    string c;
    //frequency
    int freq;
    //left right nodes
    Node* left;
    Node* right;

    Node();
    Node(Node *, Node *);
    Node(string character);
    Node(string character, int f);

    void set_children(Node &, Node &);
    void inc_freq();

    bool operator==(const Node &) const;
    bool operator>(const Node &) const;
    bool operator<(const Node &) const;
};


#endif //HUFFMANEXERCISE_NODE_H

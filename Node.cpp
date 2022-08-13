//
// Created by AZ on 8/11/2022.
//

#include "Node.h"

Node::Node(){
    c = "";
    freq = 0;
    left = NULL;
    right = NULL;
}

Node::Node(string character){
    c = character;
    freq = 1;
    left = NULL;
    right = NULL;
}

Node::Node(string character, int f){
    c = character;
    freq = f;
    left = NULL;
    right = NULL;
}

Node::Node(Node* lhs, Node* rhs){
    c = lhs->c;
    c.append(rhs->c);
    freq = lhs->freq + rhs->freq;
    left = lhs;
    right = rhs;
}


void Node::inc_freq(){
    freq ++;
}

bool Node::operator==(const Node  &f) const {return c == f.c;} //Node.c == Node.c
bool Node::operator>(const Node  &f) const {return freq < f.freq;} //Node.freq > Node.freq
bool Node::operator<(const Node  &f) const {return freq > f.freq;} //Node.freq < Node.freq



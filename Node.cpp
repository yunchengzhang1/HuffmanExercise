//
// Created by AZ on 8/11/2022.
//

#include "Node.h"

Node::Node(char character){
    c = character;
    freq = 1;
}

void Node::inc_freq(){
    freq ++;
}

bool Node::operator==(const Node  &f) const {return c == f.c;} //Node.c == Node.c
bool Node::operator>(const Node  &f) const {return freq > f.freq;} //Node.freq > Node.freq
bool Node::operator<(const Node  &f) const {return freq < f.freq;} //Node.freq < Node.freq



//
// Created by AZ on 8/11/2022.
//

#include "Node.h"

Node::Node(char character){
    c = character;
}

char Node::get_c(){
    return c;
}
int Node::get_freq(){
    return freq;
}

void Node::set_freq(int i){
    freq += i;
}

void Node::inc_freq(){
    freq ++;
}

//comparison operators
bool operator>(const Node &lhs, const Node &rhs) {
    return lhs.freq > rhs.freq;
}

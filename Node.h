//
// Created by AZ on 8/11/2022.
//

#ifndef HUFFMANEXERCISE_NODE_H
#define HUFFMANEXERCISE_NODE_H


class Node {
private:
    //character itself
    char c;
    //frequency
    int freq;
public:
    Node(char character);
    ~Node() {}

    char get_c();
    int get_freq();

    void set_freq(int i);
    void inc_freq();

    friend bool operator> (const Node& lhs, const Node& rhs);

};


#endif //HUFFMANEXERCISE_NODE_H

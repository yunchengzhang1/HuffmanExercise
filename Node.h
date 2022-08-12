//
// Created by AZ on 8/11/2022.
//

#ifndef HUFFMANEXERCISE_NODE_H
#define HUFFMANEXERCISE_NODE_H


struct Node {
    //character itself
    char c;
    //frequency
    int freq;

    Node(char character);

    void inc_freq();

    bool operator==(const Node &) const;
    bool operator>(const Node &) const;
    bool operator<(const Node &) const;

};


#endif //HUFFMANEXERCISE_NODE_H

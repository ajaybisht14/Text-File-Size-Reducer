#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

struct node {
    char ch;
    int freq;
    node *left, *right;

    node(char c, int f);
};

struct compare {
    bool operator()(node* a, node* b);
};

node* buildTree(unordered_map<char,int>& freq);
void generateCodes(node* root, string s, unordered_map<char,string>& mp);
void deleteTree(node* root);

#endif
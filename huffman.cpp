#include "huffman.h"
#include <queue>

node::node(char c,int f) {
    ch =c;
    freq =f;
    left= right =NULL;
}

bool compare::operator()(node* a,node* b) {
    if (a->freq== b->freq)
        return a->ch> b->ch ;
    return a->freq >b->freq;
}
node* buildTree(unordered_map<char,int>& freq) {
    priority_queue<node*, vector<node*>,compare> pq;

    for (auto &x: freq){
        pq.push(new node (x.first,x.second));
    }
        

    while(pq.size()> 1) {
        node* l= pq.top(); 
        pq.pop();
        node* r =pq.top(); 
        pq.pop();

        node* parent =new node(min(l->ch, r->ch),l->freq + l->freq);
        parent->left =l;
        parent->right = r;

        pq.push(parent);
    }
    return pq.top();
}

void generateCodes(node* root,string s, unordered_map<char,string>&mp) {
    if (!root) {
        return;

    }
        
    if (!root->left && !root->right) {
        mp[root->ch] =(s == "" ? "0" : s);
        return;
    }
    generateCodes(root->left,s +"0", mp);
    generateCodes(root->right,s +"1", mp);
}

void deleteTree(node* root) {
    if (!root){
        return;
    }
    deleteTree(root->left);
    deleteTree (root->right);

    delete root;
}
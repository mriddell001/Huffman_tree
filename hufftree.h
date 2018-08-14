//Matthew Riddell

#ifndef HUFFTREE_H
#define HUFFTREE_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Hufftree
{
    public:
        Hufftree();
        void prep(string key, int quant);
        void join(string s_pare, int i_pare, string s_left, int i_left, string s_righ, int i_righ);
        void root(string key, int quant, string s_left, int i_left, string s_righ, int i_righ);

        void test();

    private:
        class Node
        {
            public:
                Node(string child, string encode, int value, Node *parent) {m_self = child; m_value = value; m_parent = parent; m_left = 0; m_right = 0; code = encode;}
                ~Node();
                string m_self;
                string code;
                int m_value;
                Node *m_left;
                Node *m_right;
                Node *m_parent;
        };
        Node *m_root;
        std::vector<Node*> data;
        void print(Node *parent);
};
#endif // HUFFTREE_H

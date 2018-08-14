//Matthew Riddell

#include <iostream>
#include <vector>
#include "hufftree.h"

Hufftree::Hufftree()
{

}

Hufftree::Node::~Node()
{
    delete m_left;
    delete m_right;
}

void Hufftree::prep(string key, int quant) {
    string none = "";
    Node *temp = new Node (key, none, quant, temp);
    data.push_back(temp);
}

void Hufftree::join(string s_pare, int i_pare, string s_left, int i_left, string s_righ, int i_righ)
{
    string none = "";
    Node *temp = new Node (s_pare, none, i_pare, temp);
    Node *tmp1;
    Node *tmp2;

    data.push_back(temp);

    for (std::vector<Node*>::iterator it = data.begin(); it != data.end(); ++it)
    {
        if ((*it)->m_self == s_left) {
            tmp1 = (*it);
        }
        if ((*it)->m_self == s_righ) {
            tmp2 = (*it);
        }
    }

    tmp1->m_parent = temp;
    tmp2->m_parent = temp;
    temp->m_left = tmp1;
    temp->m_right = tmp2;
}

void Hufftree::root(string key, int quant, string s_left, int i_left, string s_righ, int i_righ)
{
    Node *tmp1;
    Node *tmp2;
    Node *n_it;

    for (std::vector<Node*>::iterator it = data.begin(); it != data.end(); ++it)
    {
        n_it = *it;
        if (n_it->m_self == s_left) {
            tmp1 = n_it;
        }
        if (n_it->m_self == s_righ) {
                tmp2 = n_it;
        }
    }
    string none = "";
    Node *temp = new Node (key, none, quant, temp);
    m_root = temp;
    temp->m_left = tmp1;
    temp->m_right = tmp2;
    tmp1->m_parent = temp;
    tmp2->m_parent = temp;
    data.push_back(temp);
    print(m_root);
}

void Hufftree::print(Node *parent)
{
    Node *n_root = parent;

    /***Print left***/
    if (n_root->m_left != 0)
    {
        n_root->m_left->code = n_root->code + "0";
        print(n_root->m_left);
    }
    /***Print self***/
    if (!isdigit(n_root->m_self[0])) {cout << n_root->m_self << " " << n_root->code << endl;}
    /***Print right***/
    if (n_root->m_right != 0)
    {
        n_root->m_right->code = n_root->code + "1";
        print(n_root->m_right);
    }

}

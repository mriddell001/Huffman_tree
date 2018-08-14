//Matthew Riddell

#include <fstream>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <queue>
#include <sstream>
#include <string>
#include <utility>
#include "hufftree.h"

using namespace std;

int main(int argc, char *argv[])
{
	ifstream m_file(argv[1], ios::in);
	Hufftree tree;
	char letter;
	map<char, int> huff_map;
	map<char, int>::iterator it;
	std::priority_queue<std::pair<int, std::string> > pq;
	int imax = std::numeric_limits<int>::max();

	while (m_file >> letter)
	{
		it = huff_map.find(letter);
		if (it == huff_map.end())
		{
			huff_map.insert(pair<char, int>(letter, 1));
		}
		else
		{
			(*it).second++;
		}
	}
	for (map<char,int>::iterator itt = huff_map.begin(); itt!=huff_map.end(); ++itt)
	{
	    stringstream out;
	    string tmp;
	    out << (*itt).first;
	    tmp = out.str();
	    int inverse_size = imax - (*itt).second;
	    tree.prep(tmp, (*itt).second);
	    /**************/
	    /**Confirmed that values are in map.**/
	    /**************/
	    //cout << "Key: " << tmp << "\tValue: " << (*itt).second << endl;
		pq.push(std::make_pair(inverse_size, tmp));
	}

	/************/
	//cout << "Huff_map size: " << huff_map.size() << endl;
	//tree.test();
	/************/

	while (!pq.empty()) {
        std::pair<int, std::string> smaller = pq.top();
        pq.pop();
        std::pair<int, std::string> larger = pq.top();
        pq.pop();

        int tmp1 = imax - larger.first;
        int tmp2 = imax - smaller.first;
        int small_total = tmp1 + tmp2;
        int inverse_size = imax - small_total;

        string small_string, stmp1, stmp2;
        stringstream out, out1, out2;
        out << small_total;
        out1 << larger.second;
        out2 << smaller.second;
        small_string = out.str();
        stmp1 = out1.str();
        stmp2 = out2.str();

        pq.push(std::make_pair(inverse_size, small_string));
        //If size equals one, you've found the root node.
        if (pq.size() == 1) {
            tree.root(small_string, small_total, stmp1, tmp1, stmp2, tmp2);
            pq.pop();
        }
        else
        {
            tree.join(small_string, small_total, stmp1, tmp1, stmp2, tmp2);
        }
	}
}

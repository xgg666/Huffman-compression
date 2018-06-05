#ifndef HUFFTREE_H
#define HUFFTREE_H

#include "MinHeap.h"
#include "TreeNode.h"

#define MAXCODELENGTH 256
#define BYTESIZE 8

using namespace std;

class HuffTree
{
	private:
	    TreeNode *root;
	    vector<int> buff[MAXCODELENGTH];
	    vector<int> cur_buff;
	   // map<string, unsigned char> de_huff;
		//Add class members and methods

	public:
		HuffTree();

		//build a hiffman  tree  give a minheap
		void buildTree(MinHeap * mh);

		//generate codes by traversing the huffman tree
		//and store them in an internal data structure (array of strings for example)
		void generateCodes();

		//returns root of the tree
		TreeNode * getRoot();
		void get(TreeNode *cur_root);

		//returns huffman code from  the ascii code
		string getCharCode(int c);

		void free_space(TreeNode *Node);
		//~HuffTree();

};


#endif

#ifndef MINHEAP_H
#define MINHEAP_H
#include <vector>
#include "TreeNode.h"


using namespace std;

class MinHeap
{
	private:
        int size;
		vector <TreeNode*> heap;
	public:
		MinHeap();
		TreeNode * removeMin(); //returns root of heap
		void insert(TreeNode * val); //adds element to heap
		int getSize(); //returns size of heap
		//~MinHeap();
};

#endif

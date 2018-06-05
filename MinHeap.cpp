#include "MinHeap.h"

//implement the methods in MinHeap.h

MinHeap::MinHeap()
{
	heap.push_back(NULL);
    size = 0;
}

void MinHeap::insert(TreeNode * val)
{
   size++;
   heap.push_back(val);
   int p = size;
   if(p == 1) return ;
   while(p > 1)
   {
   	 if(val->getFrequency() < heap[p >> 1]->getFrequency())
   	 {
   	 	TreeNode * t = heap[p];
   	 	heap[p] = heap[p >> 1];
   	 	heap[p >> 1] = t;
   	 	p >>= 1;
		}
	 else break;
   }
}

int MinHeap::getSize()
{
	return size;
}

TreeNode * MinHeap::removeMin()
{

	if(size == 0)
	return NULL;
	else
	{
		int p = 1;
		TreeNode * t = heap[size];
		heap[size] = heap[p];
		heap[p] = t;
		TreeNode * ret = heap[size];
		heap.erase(heap.end()-1);
		size--;
		while((p << 1) <= size)
		{
			int swp = p << 1;
			if(swp + 1 <= size && heap[swp]->getFrequency() > heap[swp+1]->getFrequency())
			 swp++;
		    if(heap[swp]->getFrequency() >= heap[p]->getFrequency())
		    break;
			t = heap[swp];
			heap[swp] = heap[p];
			heap[p] = t;
			p = swp;
		}
		return ret;
	}

}



#include "TreeNode.h"


TreeNode::TreeNode(unsigned _val, unsigned _frequency)
{
    val = _val;
    frequency = _frequency;
    left = right = NULL;
}

bool TreeNode::isLeafNode()
{
	return left == NULL && right == NULL;
}

TreeNode * TreeNode::getLeft()
{
	return left;
}

void TreeNode::join(TreeNode * l, TreeNode * r) {
    left = l;
    right = r;
}

TreeNode * TreeNode::getRight()
{
  return right;
}

unsigned TreeNode::getFrequency()
{
	return frequency;
}
unsigned TreeNode::getVal()
{
	return val;
}

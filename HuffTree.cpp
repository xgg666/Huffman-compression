#include "HuffTree.h"


void HuffTree::buildTree(MinHeap *mh) {
    while (mh -> getSize() > 1) {
        TreeNode *l = mh -> removeMin();
        TreeNode *r = mh -> removeMin();
        TreeNode *cur_root = new TreeNode(' ', l -> getFrequency() + r -> getFrequency());
        cur_root -> join(l, r);
        mh -> insert(cur_root);
        if (mh -> getSize() == 1) {
            root = cur_root;
        }
    }
}

HuffTree::HuffTree() {
    cur_buff.clear();
}

TreeNode * HuffTree::getRoot() {
    return root;
}

void HuffTree::get(TreeNode *cur_root) {
    if(cur_root -> isLeafNode() == true){
        buff[cur_root -> getVal()] = cur_buff;
        cur_buff.pop_back();
        return;
    }
    cur_buff.push_back('1');
    get(cur_root -> getLeft());
    cur_buff.push_back('0');
    get(cur_root -> getRight());
    cur_buff.pop_back();
}

void HuffTree::generateCodes() {
    get(getRoot());
}

void HuffTree::free_space(TreeNode *Node) {
    if(Node -> isLeafNode() != true){
        free_space(Node -> getLeft());
        free_space(Node -> getRight());
    }
    delete Node;
}

string HuffTree::getCharCode(int c) {
    string Buff = "";
    for (int i = 0; i < buff[c].size(); i++) {
        Buff += buff[c][i];
    }
    return Buff;
}


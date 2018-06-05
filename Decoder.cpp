#include "Decoder.h"

Decoder::Decoder(string huff_file_path) {
    un_num = 0;
    input_file_path = huff_file_path;
}


ifstream fin;

int bitread1() {
    unsigned char a;
    fin.read(reinterpret_cast<char*>(&a), 1);
    return a;
}

int bitread2() {
    short int a;
    fin.read(reinterpret_cast<char*>(&a), 2);
    return a;
}

int bitread4() {
    int a;
    fin.read(reinterpret_cast<char*>(&a), 4);
    return a;
}

string ToBits(int hex) {
    string bit;
    for (int i = 1; i <= 8; i++) {
        bit += (hex & 1) + '0';
        hex >>= 1;
    }
    reverse(bit.begin(), bit.end());
    return bit;
}

void Decoder::buildFrequencyTableFromFile() {
	fin.open(input_file_path.c_str(), std::ifstream::binary);
	for(int i = 0; i < 256; i++)
        frequency_table[i] = 0;
    un_char = bitread2();
    for (int i = 1; i <= un_char; i++) {
        int c = bitread1();
        int tim = bitread4();
        frequency_table[c] = tim;
        un_num += tim;
    }
    int codes;
    while ((codes = fin.get()) != EOF) {
        huff_str.append(ToBits(codes));
    }
    fin.close();
}

void Decoder::decode() {
    mh = new MinHeap();
    for (int i = 0; i < 256; i++) {
        if (frequency_table[i] != 0) {
            TreeNode *Node = new TreeNode(i, frequency_table[i]);
            mh -> insert(Node);
        }
    }
    Huf = new HuffTree();
    Huf -> buildTree(mh);
    Huf -> generateCodes();
    TreeNode *cur_Node = Huf -> getRoot();
    for (int i = 0; i < huff_str.size(); i++) {
        if (huff_str[i] == '1') {
            cur_Node = cur_Node -> getLeft();
        }
        else {
            cur_Node = cur_Node -> getRight();
        }
        if (cur_Node -> isLeafNode() == true) {
            dehuff.push_back(cur_Node -> getVal());
            cur_Node = Huf -> getRoot();
            if (dehuff.size() == un_num) break;
        }
    }
    Huf -> free_space(Huf -> getRoot());
    delete Huf;
    delete mh;
}

void Decoder::writeUncompressedFile(string file_path) {
    ofstream out;
    out.open(file_path.c_str());

    for (int i = 0; i < dehuff.size(); i++) {
        out << dehuff[i];
    }
    out.close();
}


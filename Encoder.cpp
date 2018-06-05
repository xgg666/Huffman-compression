#include "Encoder.h"

Encoder::Encoder(string file_path)
{
    num_char = 0;
	input_file_path = file_path;
}

void Encoder::buildFrequencyTable()
{
	FILE *fin;
	fin = fopen(input_file_path.c_str(), "r");
	for(int i = 0; i < 256; i++)
        frequency_table[i] = 0;
	int ch;

	while(1) {
        ch = fgetc(fin);
        if (feof(fin)) break;
        str.push_back(ch);
        frequency_table[ch]++;
	}
	fclose(fin);
}

void Encoder::encode() {
    MinHeap *mh = new MinHeap();
    for (int i = 0; i < 256; i++) {
        if (frequency_table[i] != 0) {
            num_char++;
            TreeNode *Node = new TreeNode(i, frequency_table[i]);
            mh -> insert(Node);
        }
    }
    Huff = new HuffTree();
    Huff -> buildTree(mh);
    Huff -> generateCodes();
}

ofstream out;

void bitpri1(int x) {
    int a[1];
    a[0] = x;
    out.write(reinterpret_cast<const char*>(a), 1);
}

void bitpri2(int x) {
    int a[1];
    a[0] = x;
    out.write(reinterpret_cast<const char*>(a), 2);
}

void bitpri4(int x) {
    int a[1];
    a[0] = x;
    out.write(reinterpret_cast<const char*>(a), 4);
}

void Encoder::writeCode(vector<int> binaryData, string output_file_path) {
    if (binaryData.size() == 0) return;
    int bits = 0;
    int buffer = 0;
    vector<int> codes;
    string code;
    for (int i = 0; i < binaryData.size(); ++i) {
        code.append(Huff -> getCharCode(binaryData[i]));
    }
    int num = (8 - code.size() % 8) % 8;
    while (num--) {
        code += "0";
    }
    for (int j = 0; j < code.size(); j++) {
        buffer <<= 1;
        if (code[j] == '1')
            buffer += 1;
        bits++;
        if (bits % 8 == 0) {
            codes.push_back(buffer);
            buffer = 0;
        }
    }
    for (int i = 0; i < codes.size(); i++){
        out.put(codes[i]);
    }
}

void Encoder::writeEncodedFile(string output_file_path) {
    out.open(output_file_path.c_str(), std::ofstream::binary);
    bitpri2(num_char);
    for (int i = 0; i < 256; i++) {
        if (frequency_table[i] != 0) {
            int tmp = i;
            bitpri1(tmp);
            bitpri4(frequency_table[i]);
        }
    }
    writeCode(str, output_file_path);
    out.close();
}





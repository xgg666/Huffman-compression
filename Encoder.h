
#include "HuffTree.h"
#ifndef ENCODER_H
#define ENCODER_H


#include <string>

using namespace std;

class Encoder
{
	private:
		int frequency_table[256];
		string input_file_path, output_file_path;
		vector<int> str;
		int num_char;
        HuffTree *Huff;
		// You need to add more class memeber and methods
	public:
		//test_file_path is the input (decoded) file
		Encoder(string file_path);

		//Fills up the frequency_table array where frequency_table[i]
		//will contain the frequency of char with ASCII code i
		void buildFrequencyTable();

		//Builds the min head and run the encoding algorithm
		void encode();

        void writeCode(vector<int> binaryData, string output_file_path);

		//Generates the encoded file and save it as output_file_path
		void writeEncodedFile(string output_file_path);

		//~Encoder();
};

#endif


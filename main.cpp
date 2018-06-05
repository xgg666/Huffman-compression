#include "Encoder.h"
#include "Decoder.h"

using namespace std;

int main (int argc, char**argv){
	if (argv[1][1] == 'e') {
        Encoder *enc = new Encoder(argv[2]);
        enc -> buildFrequencyTable();
        enc -> encode();
        enc -> writeEncodedFile(argv[3]);
        delete enc;
	}
	if (argv[1][1] == 'd') {
        Decoder *dec = new Decoder(argv[2]);
        dec -> buildFrequencyTableFromFile();
        dec -> decode();
        dec -> writeUncompressedFile(argv[3]);
        delete dec;
	}
	return 0;
}

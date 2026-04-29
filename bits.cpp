#include "bits.h"
void writeBits(ofstream &out,string encoded ) {
    unsigned char byte =0;
    int bitCount= 0;
    int edge =0;

    
    for ( char bit:encoded){
        byte = (byte <<1) |(bit -'0');
        bitCount++;
        if (bitCount== 8 ){

            out.write( (char*)&byte, 1);
            byte =0;
            bitCount = 0;
        }
    }

    if (bitCount >0) {
        edge= 8- bitCount;
        byte <<=edge;
        out.write((char*)&byte, 1);
    }
    out.put( edge);
}

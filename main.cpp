#include <iostream>

#include "file_handler.h"

using namespace std;

int main() {

    int choice;
    while (choice!= 3){
        cout <<"Huffman Compressor -\n";
        cout<< "1.Compress\n" ;
        cout <<"2.Decompress\n";
        cout<< "3.Exit\n";

        cout <<"Choice: ";

        cin>>choice;

        switch(choice){
            case 1: compressFile(); 
                    break;

            case 2:decompressFile(); 
                    break;
            case 3: cout<<"Exiting the program.\n"; 
                    break;

            default:cout <<"Invalid\n";
        }
    } 


    return 0;
}
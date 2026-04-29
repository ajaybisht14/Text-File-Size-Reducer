#include "file_handler.h"


void compressFile(){
    string inFile,outFile;
    cout <<"Input file:";
    cin>> inFile;
    cout <<"Output file: ";
    cin>> outFile;

    ifstream in(inFile,ios::binary);

    ofstream out(outFile, ios::binary);

    if (!in ||!out) {
        cout <<"File error\n";
        return;
    }
    string text((istreambuf_iterator<char>(in)),{} );

    unordered_map<char,int> freq;
    for(char c: text){
        freq[c]++;


    }
    cout << "\nCharacter Frequencies:\n";
    for (auto &x : freq) {
        cout <<x.first<< " = " << x.second << endl;
    }
    node* root= buildTree(freq);

    unordered_map<char, string>codes;
    generateCodes(root,"", codes);

    string encoded= "";
    for (char c: text)
        encoded+= codes[c];

    int n =freq.size();
    out.write((char*)&n ,sizeof(n));

    for(auto &x: freq ) {
        out.write((char*)&x.first, sizeof(x.first));
        out.write((char*)&x.second,sizeof(x.second));
    }

    writeBits(out,encoded);
    deleteTree(root);
    cout << "Compression done!\n";
}

void decompressFile() {
    string inFile, outFile;

    cout << "Input file: ";
    cin >>inFile;

    cout << "Output file: ";
    cin >> outFile;

    ifstream in(inFile, ios::binary);
    ofstream out(outFile, ios::binary);

    int n;
    in.read((char*)&n, sizeof(n));

    unordered_map<char,int> freq;

    for (int i = 0; i < n; i++) {
        char c;
        int f;
        in.read((char*)&c, sizeof(c));
        in.read((char*)&f, sizeof(f));
        freq[c] = f;
    }
    cout << "\nCharacter Frequencies:\n";
    for (auto &x : freq) {
        cout << x.first << " = " << x.second << endl;
    }
    node* root = buildTree(freq);

    vector<char> buffer((istreambuf_iterator<char>(in)), {});
    int padding = (unsigned char)buffer.back();
    buffer.pop_back();

    string bits = "";

    for (unsigned char byte : buffer) {
        for (int i = 7; i >= 0; i--)
            bits += ((byte >> i) & 1) ? '1' : '0';
    }

    bits.erase(bits.end() - padding, bits.end());

    node* curr = root;

    for (char bit : bits) {
        curr = (bit == '0') ? curr->left : curr->right;

        if (!curr->left && !curr->right) {
            out.put(curr->ch);
            curr = root;
        }
    }

    deleteTree(root);
    cout << "Decompression done!\n";
}

















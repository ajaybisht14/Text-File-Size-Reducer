#  Huffman File Compression Tool

A C++ implementation of **Huffman Coding Algorithm** to compress and decompress files efficiently.

---

##  Overview

This project implements **lossless data compression** using Huffman Encoding. It reduces file size by assigning variable-length binary codes to characters based on their frequency.

* More frequent characters → shorter codes
* Less frequent characters → longer codes

---

##  Concepts Used

* Greedy Algorithms
* Binary Trees
* Priority Queue (Min Heap)
* File Handling in C++

---

## Features

* Compress text files into encoded format
*  Decompress encoded files back to original
*  Efficient memory usage
* Custom file handling implementation
* Download compressed and decompressed file
* Structured ui

---

## Project Structure

```
copy/
│── main.cpp            # Entry point
│── huffman.cpp         # Core Huffman logic
│── huffman.h
│── file_handler.cpp    # File read/write operations
│── file_handler.h
│── bits.cpp            # Bit-level operations
│── bits.h
│── test_file.txt       # Sample input file
│── huffman.exe         # Compiled executable
```

---

##  How It Works

1. Read input file
2. Calculate frequency of each character
3. Build Huffman Tree
4. Generate binary codes
5. Encode and compress file

For decompression:

* Rebuild tree → decode → restore original file

---

##  How to Run

###  Compile

```bash
g++ main.cpp huffman.cpp file_handler.cpp bits.cpp -o huffman
```

### Run

```bash
./huffman
```
```bash
streamlit run app.py
```

---

##  Example

Input:

```
aaabbc
```

Encoded Output (example):

```
0 0 0 10 10 11
```

Compressed size < Original size 

---



## 🤝 Contributing

Feel free to fork this repo and submit pull requests.

---



Star this repo if you found it useful!

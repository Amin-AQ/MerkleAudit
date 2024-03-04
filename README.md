# Merkel Audit 📁

Welcome to Merkel Audit, a project for auditing and tracking changes in data using Merkle trees!

## Overview

The Merkel Audit project consists of C++ code to handle file chunking, hash calculations, Merkle tree creation, and detecting modified chunks.

### ChunkFile.cpp 📄

```cpp
// ChunkFile.cpp

#pragma once
#include<iostream>
#include<string>
#include"ChunkFile.h"
#include"SHA256.h"
using namespace std;

Chunk::Chunk()
{
    chunk = nullptr;
    hash = nullptr;
}

char* Chunk::CalculateHash() // Calculates the hash of the chunk
{
    return nullptr;
}

File::File()
{
    ChunkSize = 0;
    AllBits = nullptr;
    MerkelRoot = nullptr;
}

void File::ChunkifyFile() // Populates AllBits array with Chunk Object.
{
    string data = "10100101011101010101001010101011";
    if (AllBits != nullptr)
    {
        delete[]AllBits;
        AllBits = nullptr;
    }

    int size = data.size();
    if(size>4)  // power of 2 greater than 4
        ChunkSize = 4;
    else
        ChunkSize = 1;

    noOfChunks = size / ChunkSize;
    AllBits = new Chunk[noOfChunks];
    int j = 0;      // iterator for input bits
    // for all chunks: initialize them, add chunksize bits from the string and place null at end
    for (int i = 0; i < noOfChunks; i++)
    {
        AllBits[i].chunk = new char[ChunkSize+1];
        for (int k = 0; j < size && k < ChunkSize; j++, k++)
        {
            AllBits[i].chunk[k] = data[j];
            AllBits[i].chunk[k + 1] = '\0';
        }
        AllBits[i].hash = new char[500];
        string s = sha256(string(AllBits[i].chunk));
        strcpy_s(AllBits[i].hash,500, s.c_str());
        cout << "Chunk " << i << ": " << AllBits[i].chunk << "\nHash " << i << AllBits[i].hash << endl << endl;
    }
}

char* File::CreateMerkelTree(Chunk* AllBits)  // Creates MerkelRoot.
{
    return nullptr;
}

void File::ModifyRandomChunk() // This function will modify Single Chunk in AllBits array.
{

}

int File::FindDirtyChunk()  // This will create the Merkel Tree again and will find the
{                           // dirty/Modified Chunk in Top Down approach as studied in class.
    return 0;
}
```

### main.cpp 🚀

```cpp
// main.cpp

#include<iostream>
using namespace std;
#include"ChunkFile.h"

int main()
{
    File F1;
    F1.ChunkifyFile();
    cout << endl;
    system("pause");
    return 0;
}
```

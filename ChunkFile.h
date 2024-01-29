#pragma once
class Chunk 
{	
public:
	char* chunk; // This array will contain bits like 000100101010101
	char* hash; // Hash of the chunk , you may implement any good hash function.
	Chunk();
	char*CalculateHash(); // Calculates the hash of the chunk
};
class File {
	int ChunkSize; 
	int noOfChunks;
	Chunk*AllBits; 
	char* MerkelRoot;
public:
	File();
	void ChunkifyFile();					// Populates AllBits array with Chunk Object. 
	char*CreateMerkelTree(Chunk*AllBits);  // Creates MerkelRoot.
	void ModifyRandomChunk(); // This function will modify Single Chunk in AllBits array. 
	int FindDirtyChunk();	  // This will create the Merkel Tree again and will find the
							  // dirty/Modified Chunk in Top Down approach as studied in class.
};
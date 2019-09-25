// DESAlgorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int INITIAL_PERMUTATION[64] = {
	58, 50, 42, 34, 26, 18, 10, 2,
	60, 52, 44, 36, 28, 20, 12, 4,
	62, 54, 46, 38, 30, 22, 14, 6,
	64, 56, 48, 40, 32, 24, 16, 8,
	67, 49, 41, 33, 25, 17, 9, 1,
	59, 51, 43, 35, 27, 19, 11, 3,
	61, 53, 45, 37, 29, 21, 13, 5,
	63, 55, 47, 39, 31, 23, 15, 7
};

const int INVERSE_INITIAL_PERMUTATION[64] = {
	40, 8, 48, 16, 56, 24, 64, 32,
	39, 7, 47, 15, 55, 23, 63, 31,
	38, 6, 46, 14, 54, 22, 62, 30,
	37, 5, 45, 13, 53, 21, 61, 29,
	36, 4, 44, 12, 52, 20, 60, 28,
	35, 3, 43, 11, 51, 19, 59, 27,
	34, 2, 42, 10, 50, 18, 58, 26,
	33, 1, 41, 9, 49, 17, 57, 25
};

const int PERMUTED_CHOICE_1[56] = {
	57, 49, 41, 33, 25, 17, 9,
	1, 58, 50, 42, 34, 26, 18,
	10, 2, 59, 51, 43, 35, 27,
	19, 11, 3, 60, 52, 44, 36,
	63, 55, 47, 39, 31, 23, 15,
	7, 62, 54, 46, 38, 30, 22,
	14, 6, 61, 53, 45, 37, 29,
	21, 13, 5, 28, 20, 12, 4
};

const int PERMUTED_CHOICE_2[48] = {
	14, 17, 11, 24, 1, 5, 3, 28,
	15, 6, 21, 10, 23, 19, 12, 4,
	26, 8, 16, 7, 27, 20, 13, 2,
	41, 52, 31, 37, 47, 55, 30, 40,
	51, 45, 33, 48, 44, 49, 39, 56,
	34, 53, 46, 42, 50, 36, 29, 32
};

const int ONE_BIT_SHIFT_ROUNDS[4] = {
	1, 2, 9, 16
};

const int TWO_BIT_SHIFT_ROUNDS[12] = {
	3, 4, 5, 6, 7, 8, 10 ,11, 12, 13, 14, 15
};

class SubKey { 
    public:
    string Ci;
    string Di;
};

const string hex_char_to_binary(char c);
const string hex_string_to_binary_string(const string hexString);
const string removeParityBits(string binaryString);
const string permutedChoiceOne(string originalBinaryKey);
vector<SubKey> subKeys;


int main()
{
	string plainText = "0123456789ABCDEF";
	string key = "133457799BBCDFF1";
	string keyInBinary = hex_string_to_binary_string(key);

	string permutedKey = permutedChoiceOne(keyInBinary);
	cout << subKeys[0].Ci << endl << subKeys[0].Di << endl;
	return 0;
}

const string hex_char_to_binary(char c) {
	switch (toupper(c)) {
	case '0': return "0000";
	case '1': return "0001";
	case '2': return "0010";
	case '3': return "0011";
	case '4': return "0100";
	case '5': return "0101";
	case '6': return "0110";
	case '7': return "0111";
	case '8': return "1000";
	case '9': return "1001";
	case 'A': return "1010";
	case 'B': return "1011";
	case 'C': return "1100";
	case 'D': return "1101";
	case 'E': return "1110";
	case 'F': return "1111";
	}
	return "fail";
};

const string hex_string_to_binary_string(const string hexString) {
	string result; 

	for (char c : hexString) {
		result += hex_char_to_binary(c);
	};
	
	//Remove parity bits
	//return removeParityBits(result);
	return result;
};

const string permutedChoiceOne(string originalBinaryKey) {
	string permutedBinaryKey;

	for (int pos : PERMUTED_CHOICE_1) {
		permutedBinaryKey += originalBinaryKey[pos - 1];
	};

	SubKey k1;
	// k1.Ci = "test";
	// k1.Di = "test2";
	k1.Ci = permutedBinaryKey.substr(0, permutedBinaryKey.length()/2);
	k1.Di = permutedBinaryKey.substr(permutedBinaryKey.length()/2);
	
	subKeys.push_back(k1);

	return permutedBinaryKey;
};

const string removeParityBits(string binaryString) {
	binaryString.erase(binaryString.begin() + 63);
	binaryString.erase(binaryString.begin() + 55);
	binaryString.erase(binaryString.begin() + 47);
	binaryString.erase(binaryString.begin() + 39);
	binaryString.erase(binaryString.begin() + 31);
	binaryString.erase(binaryString.begin() + 23);
	binaryString.erase(binaryString.begin() + 15);
	binaryString.erase(binaryString.begin() + 7);
	return binaryString;
};



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

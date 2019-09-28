#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int INITIAL_PERMUTATION[64] = {
	58,50,42,34,26,18,10,2,
		60,52,44,36,28,20,12,4,
		62,54,46,38,30,22,14,6,
		64,56,48,40,32,24,16,8,
		57,49,41,33,25,17,9,1,
		59,51,43,35,27,19,11,3,
		61,53,45,37,29,21,13,5,
		63,55,47,39,31,23,15,7
};

const int INVERSE_INITIAL_PERMUTATION[64] = {
	 40,8,48,16,56,24,64,32,
		39,7,47,15,55,23,63,31,
		38,6,46,14,54,22,62,30,
		37,5,45,13,53,21,61,29,
		36,4,44,12,52,20,60,28,
		35,3,43,11,51,19,59,27,
		34,2,42,10,50,18,58,26,
		33,1,41,9,49,17,57,25
};

const int PERMUTED_CHOICE_1[56] = {
	 57,49,41,33,25,17,9,
		1,58,50,42,34,26,18,
		10,2,59,51,43,35,27,
		19,11,3,60,52,44,36,
		63,55,47,39,31,23,15,
		7,62,54,46,38,30,22,
		14,6,61,53,45,37,29,
		21,13,5,28,20,12,4
};

const int PERMUTED_CHOICE_2[48] = {
	14,17,11,24,1,5,
		3,28,15,6,21,10,
		23,19,12,4,26,8,
		16,7,27,20,13,2,
		41,52,31,37,47,55,
		30,40,51,45,33,48,
		44,49,39,56,34,53,
		46,42,50,36,29,32
};

const int EXPANSION_PERMUTATION[48] = {
	32,1,2,3,4,5,4,5,
		6,7,8,9,8,9,10,11,
		12,13,12,13,14,15,16,17,
		16,17,18,19,20,21,20,21,
		22,23,24,25,24,25,26,27,
		28,29,28,29,30,31,32,1
};


const int PERMUTATION_FUNCTION[32] = {
	 16,7,20,21,
		29,12,28,17,
		1,15,23,26,
		5,18,31,10,
		2,8,24,14,
		32,27,3,9,
		19,13,30,6,
		22,11,4,25
};

const int S1[4][16] =
{
	14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7,
		0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8,
		4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0,
		15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13
};

const int S2[4][16] =
{
	15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10,
		3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5,
		0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15,
		13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9
};

const int S3[4][16] =
{
	10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8,
		13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1,
		13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7,
		1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12
};

const int S4[4][16] =
{
	7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15,
		13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9,
		10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4,
		3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14
};

const int S5[4][16] =
{
	2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9,
		14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6,
		4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14,
		11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3
};

const int S6[4][16] =
{
	 12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11,
		10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8,
		9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6,
		4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13
};

const int S7[4][16] =
{
	4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1,
		13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6,
		1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2,
		6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12
};

const int S8[4][16] =
{
	 13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7,
		1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2,
		7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8,
		2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11
};

const int ONE_BIT_SHIFT_ROUNDS[4] = {
	1,  2,  9,  16
};

class SubKey { 
    public:
		string C,  D,  PC2Key;
};

class PlainText {
	public: 
		string L,  R,  LR;
};

const string hexCharToBinary(char c);
const string hexCharToBinary(const string hexString);

int binaryToDecimalRow(string binary);
int binaryToDecimalCol(string binary);
string decimalToBinary(int decimal);

string binaryToDecimal(char c);
string binaryStringToDecimalString(string binaryString);


const string permutedChoiceOne(string originalBinaryKey);
const string permutedChoiceTwo(string key);

vector<SubKey> subKeys;
vector<SubKey> generateSubKeys(string permutedBinaryKey);



vector<PlainText> plainTexts;

string DESEncrypt(string PC1Text);
string DESDecrypt(string cipherTextHex);

char binaryXOR(char a,  char b);

const string initialPermutation(string originalBinaryText);
const string roundsFunction(string initialPermutationResult);

string initializeRound0(string LR);

string expansionPermutation(string r);
string substitution(string EResult);
string permutationFunction(string prePermutation);

string swap32Bit(PlainText pt);
string inversePermutation(string prePermutation);





int main()
{
	// plaintext from online
	string plainText = "0123456789ABCDEF";
	string key = "133457799BBCDFF1";
	string keyInBinary = hexCharToBinary(key);


	string permutedKey = permutedChoiceOne(keyInBinary);
	generateSubKeys(permutedKey);

	string cipherText = DESEncrypt(plainText);
	DESDecrypt(cipherText);


	return 0;
}

char binaryXOR(char a,  char b) {
	if (a == b) {
		return '0';
	};
	return '1';
};

const string hexCharToBinary(char c) {
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

const string hexCharToBinary(const string hexString) {
	string result; 

	for (char c : hexString) {
		result += hexCharToBinary(c);
	};

	return result;
};

const string permutedChoiceOne(string originalBinaryKey) {
	string permutedBinaryKey;

	for (int pos : PERMUTED_CHOICE_1) {
		permutedBinaryKey += originalBinaryKey[pos - 1];
	};

	return permutedBinaryKey;
};

const string permutedChoiceTwo(string key) {
	string permutedChoice2BinaryKey;

	for (int pos : PERMUTED_CHOICE_2) {
		permutedChoice2BinaryKey += key[pos - 1];
	};

	return permutedChoice2BinaryKey;
};

const string initialPermutation(string originalBinaryText) {
	string permutedBinaryText;

	for (int pos : INITIAL_PERMUTATION) {
		permutedBinaryText += originalBinaryText[pos - 1];
	};

	return permutedBinaryText;
};

vector<SubKey> generateSubKeys(string permutedBinaryKey) {
	// Generate the first subkey C0 and D0
	SubKey k1;
	k1.C = permutedBinaryKey.substr(0,  permutedBinaryKey.length() / 2);
	k1.D = permutedBinaryKey.substr(permutedBinaryKey.length() / 2);
	subKeys.push_back(k1);

	// Generate subsequent keys using C0 and D0
	for (int i = 1; i < 17; i++) {
		SubKey k;
		string preShiftC = subKeys[i - 1].C;
		string preShiftD = subKeys[i - 1].D;
		string CD;

		if (*find(begin(ONE_BIT_SHIFT_ROUNDS),  end(ONE_BIT_SHIFT_ROUNDS),  i) == i) {
			k.C = preShiftC.substr(1,  preShiftC.length()) + preShiftC[0];
			k.D = preShiftD.substr(1,  preShiftD.length()) + preShiftD[0];
		}
		else {
			k.C = preShiftC.substr(2,  preShiftC.length()) + preShiftC.substr(0,  2);
			k.D = preShiftD.substr(2,  preShiftD.length()) + preShiftD.substr(0,  2);
		};

		CD = k.C + k.D;

		// Apply PC2 on all keyss
		k.PC2Key = permutedChoiceTwo(CD);

		subKeys.push_back(k);
	};

	return subKeys;
};

string DESDecrypt(string cipherText) {

	// Clear existing vectors
	plainTexts = {};

	string cipherTextInBinary = hexCharToBinary(cipherText);
	string PC1Text = initialPermutation(cipherTextInBinary);

	//Create L0 R0
	PlainText pt0;
	pt0.L = PC1Text.substr(0, PC1Text.length() / 2);
	pt0.R = PC1Text.substr(PC1Text.length() / 2);
	pt0.LR = PC1Text;
	plainTexts.push_back(pt0);

	int keys = 16;
	// Do subsequent rounds using pt0
	for (int i = 1; i < 17; i++) {
		PlainText pt;
		string EP = expansionPermutation(plainTexts[i - 1].R);
		string EPResult;
		string Ri;

		for (int j = 0; j < 48; j++) {
			EPResult += binaryXOR(EP[j], subKeys[keys].PC2Key[j]);
			
		};

		string sboxResults = substitution(EPResult);
		if (i == 1) { cout << sboxResults << endl; }
		string permutationFunctionResult = permutationFunction(sboxResults);
		if (i == 1) {
			cout << permutationFunctionResult << endl;
		};
		for (int j = 0; j < 32; j++) {
			Ri += binaryXOR(plainTexts[i - 1].L[j], permutationFunctionResult[j]);
		};
		if (i == 1) {
			cout << "R1: " << Ri << endl;
		};

		pt.L = plainTexts[i - 1].R;
		pt.R = Ri;
		pt.LR = pt.L + pt.R;
		plainTexts.push_back(pt);
		keys--;
	};
	cout << "before swap: " << "L16: " << plainTexts[plainTexts.size() - 1].L << endl << "R16: " << plainTexts[plainTexts.size() - 1].R << endl;
	string swap32BitResult = swap32Bit(plainTexts[plainTexts.size() - 1]);
	cout << "after swap: " << swap32BitResult << endl;
	string cipherTextBinary = inversePermutation(swap32BitResult);

	string cipherTextDecimal = binaryStringToDecimalString(cipherTextBinary);
	cout << "Final Result" << cipherTextDecimal << endl;
	return cipherTextDecimal;
};


string DESEncrypt(string plainText) {

	string plainTextInBinary = hexCharToBinary(plainText);
	string initialPermutationResult = initialPermutation(plainTextInBinary);

	string initializeRound0Result = initializeRound0(initialPermutationResult);
	string roundsEncrypt = roundsFunction(initialPermutationResult);

	string swap32BitResult = swap32Bit(plainTexts[plainTexts.size()-1]);
	string cipherTextBinary = inversePermutation(swap32BitResult);

	string cipherTextDecimal = binaryStringToDecimalString(cipherTextBinary);
	return cipherTextDecimal;
};

string initializeRound0(string initialPermutationResult) {

	//Create L0 R0
	PlainText pt0;
	pt0.L = initialPermutationResult.substr(0, initialPermutationResult.length() / 2);
	pt0.R = initialPermutationResult.substr(initialPermutationResult.length() / 2);
	pt0.LR = initialPermutationResult;
	plainTexts.push_back(pt0);
};

const string roundsFunction(const string PC1Text) {

	initializeRound(PC1Text;
	//Create L0 R0
	PlainText pt0;
	pt0.L = PC1Text.substr(0, PC1Text.length() / 2);
	pt0.R = PC1Text.substr(PC1Text.length() / 2);
	pt0.LR = PC1Text;
	plainTexts.push_back(pt0);

	//TODO: ADD ROUNDS FUNCTION


	// Do subsequent rounds using pt0
	for (int i = 1; i < 17; i++) {
		PlainText pt;
		string EP = expansionPermutation(plainTexts[i - 1].R);
		string EPResult;
		string Ri;

		for (int j = 0; j < 48; j++) {
			EPResult += binaryXOR(EP[j], subKeys[i].PC2Key[j]);
		};

		string sboxResults = substitution(EPResult);

		//if (i == 1) { cout << sboxResults << endl; }

		string permutationFunctionResult = permutationFunction(sboxResults);

		//if (i == 1) {
		//	cout << permutationFunctionResult << endl;
		//};


		for (int j = 0; j < 32; j++) {
			Ri += binaryXOR(plainTexts[i - 1].L[j], permutationFunctionResult[j]);
		};

		//if (i == 1) {
		//	cout << "R1: " << Ri << endl;
		//};

		pt.L = plainTexts[i - 1].R;
		pt.R = Ri;
		pt.LR = pt.L + pt.R;
		plainTexts.push_back(pt);
	};

};

string swap32Bit(PlainText pt) {
	pt.LR = pt.R + pt.L;
	return pt.LR;
};

string inversePermutation(string prePermutation) {
	string postPermutation;

	for (int pos : INVERSE_INITIAL_PERMUTATION) {
		postPermutation += prePermutation[pos - 1];
	};

	return postPermutation;
};

string expansionPermutation(string R) {
	string expandedR;

	for (int pos : EXPANSION_PERMUTATION) {
		expandedR += R[pos - 1];
	};
	
	return expandedR;
};

string substitution(string EResult) {
	vector<string> EResultSplit;
	string temp;
	string resultFromSboxes;

	for (int i = 0; i <= EResult.length(); i++) {
		if (i % 6 == 0 && i != 0) {
			EResultSplit.push_back(temp);
			temp = "";
		};
		temp += EResult[i];
	};

	for (int i = 0; i < 8; i++) {
		int row = binaryToDecimalRow(EResultSplit[i].substr(0,  1) + EResultSplit[i].substr(5,  1));
		int column = binaryToDecimalCol(EResultSplit[i].substr(1,  4));
		switch (i+1) {
		case 1: resultFromSboxes += decimalToBinary(S1[row][column]);
			break;
		case 2: resultFromSboxes += decimalToBinary(S2[row][column]);
			break;
		case 3: resultFromSboxes += decimalToBinary(S3[row][column]);
			break;
		case 4: resultFromSboxes += decimalToBinary(S4[row][column]);
			break;
		case 5: resultFromSboxes += decimalToBinary(S5[row][column]);
			break;
		case 6: resultFromSboxes += decimalToBinary(S6[row][column]);
			break;
		case 7: resultFromSboxes += decimalToBinary(S7[row][column]);
			break;
		case 8: resultFromSboxes += decimalToBinary(S8[row][column]);
			break;
		};
	};

	return resultFromSboxes; 
};


int binaryToDecimalRow(string binary) {
	if (binary == "00") return 0;
	if (binary == "01") return 1;
	if (binary == "10") return 2;
	if (binary == "11") return 3;
};

int binaryToDecimalCol(string binary) {
	if (binary == "0000") return 0;
	if (binary == "0001") return 1;
	if (binary == "0010") return 2;
	if (binary == "0011") return 3;
	if (binary == "0100") return 4;
	if (binary == "0101") return 5;
	if (binary == "0110") return 6;
	if (binary == "0111") return 7;
	if (binary == "1000") return 8;
	if (binary == "1001") return 9;
	if (binary == "1010") return 10;
	if (binary == "1011") return 11;
	if (binary == "1100") return 12;
	if (binary == "1101") return 13;
	if (binary == "1110") return 14;
	if (binary == "1111") return 15;

};

string decimalToBinary(int decimal) {
	switch (decimal) {
	case 0:
		return "0000";
	case 1:
		return "0001";
	case 2:
		return "0010";
	case 3:
		return "0011";
	case 4:
		return "0100";
	case 5:
		return "0101";
	case 6:
		return "0110";
	case 7:
		return "0111";
	case 8:
		return "1000";
	case 9:
		return "1001";
	case 10:
		return "1010";
	case 11:
		return "1011";
	case 12:
		return "1100";
	case 13:
		return "1101";
	case 14:
		return "1110";
	case 15:
		return "1111";
	};
};

string binaryToDecimal(string b) {
	if (b == "0000") return "0";
	if (b == "0001") return "1";
	if (b == "0010") return "2";
	if (b == "0011") return "3";
	if (b == "0100") return "4";
	if (b == "0101") return "5";
	if (b == "0110") return "6";
	if (b == "0111") return "7";
	if (b == "1000") return "8";
	if (b == "1001") return "9";
	if (b == "1010") return "A";
	if (b == "1011") return "B";
	if (b == "1100") return "C";
	if (b == "1101") return "D";
	if (b == "1110") return "E";
	if (b == "1111") return "F";
};

string binaryStringToDecimalString(string binaryString) {
	string binary4BitString;
	string decimalString;

	for (int i = 0; i < binaryString.length() + 1; i++) {
		if (i % 4 == 0 && i != 0) {
			decimalString += binaryToDecimal(binary4BitString);
			binary4BitString = "";
		};

		binary4BitString += binaryString[i];
	};

	return decimalString;
};

string permutationFunction(string prePermutation) {
	string postPermutation;
	
	for (int pos : PERMUTATION_FUNCTION) {
		postPermutation += prePermutation[pos - 1];
	};

	return postPermutation;
};
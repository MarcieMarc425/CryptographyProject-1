#include <iostream>
#include <iterator>
#include <vector>
#include <cstdlib>
#include <fstream>

using namespace std;

int writeIntToFile(const vector<int>& cyphText, ofstream& outFile) {
	//ofstream outFile("cypherText.txt");
	if (!outFile) return 0; // if failed
	for (const auto &e : cyphText) outFile << "\'" << e << "\'" << ", ";
	outFile << "\n";
	//outFile.close();
	return 1; //if succeeded
}

int writeCharToFile(const vector<char>& cyphText, ofstream& outFile) {
	//ofstream outFile("cypherText.txt");
	if (!outFile) return 0; // if failed
	for (const auto &e : cyphText) outFile << "\'" << e << "\'" << ", ";
	outFile << "\n";
	//outFile.close();
	return 1; //if succeeded
}


//table holding letter, frequency, and key vals for cypher. just initialize; constructor handles everything
struct CyphTable {
	int freqs[27] = { 19,7,1,2,4,10,2,2,5,6,1,1,3,2,6,6,2,1,5,5,7,2,1,2,1,2,1 };
	vector<vector<int>> keys;
	CyphTable() {
		vector<int> seeds = {};
		for (int i = 0; i < 106; i++) {
			seeds.push_back(i);
		}
		for (int i = 0; i < 27; i++) {
			vector<int> alph;
			keys.push_back(alph);
			for (int j = 0; j < freqs[i]; j++) {
				int r = rand() % seeds.size();
				keys[i].push_back(seeds[r]);
				seeds.erase(seeds.begin() + r);
			}
		}
	}
};

// i couldnt find a way to enuerate chars so i made a function
int enumChars(const char& enumee) {
	if (enumee == ' ')
		return 0;
	else
		return enumee - 96;
}

// takes vector of chars as plaintext, simple cyphertext, and an empty int vect as cyphertext (will append cypher to end if not empty), scheduling algorithm is encoded in here, it is completely random rn but if we need to test other scheduling algorithms i would change it. 
void encypher(const vector<char>& plainText, const CyphTable& ct, vector<int>& cyphertext) {
	vector<vector<int>> keys = ct.keys;
	for (int i = 0; i < plainText.size(); i++) {
		int let = enumChars(plainText[i]);
		cyphertext.push_back(keys[let][rand() % keys[let].size()]);
		//keys[let].pop_back(); did this so values wouldnt repeat but it meant a letter cannot be used more often than its avg freq (eg. b could only be used once in plaintext) which is stupid
	}
}

void constructRandText(const vector<char>& letterSpace, vector<char>& plainText, int size) {
	for (int i = 0; i < size; i++) {
		plainText.push_back(letterSpace[rand() % letterSpace.size() ]);
	}
}

int main() {
	vector<char> charSpace = { ' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	vector<vector<char>> plainTexts;
	vector<vector<int>> cyphTexts;
	CyphTable ct;
	vector<char> letterSpace;
	for (int i = 0; i < 27; i++) {
		for (int j = 0; j < ct.freqs[i]; j++) {
			letterSpace.push_back(charSpace[i]);
		}
	}
	
	for (int i = 0; i < 5; i++) {
		vector<char> plainText;
		constructRandText(letterSpace, plainText, 50);
		plainTexts.push_back(plainText);
	}

	for (int i = 0; i < plainTexts.size(); i++) {
		for (int j = 0; j < 5; j++) {
			vector<int> cyphtext;
			encypher(plainTexts[i], ct, cyphtext);
			cyphTexts.push_back(cyphtext);
		}
	}

	ofstream outFile("SampleTexts.txt");
	if (!outFile) cerr << "output file not working";
	
	outFile << "size: 50\nPlaintexts: 5\nCyphtexts per PT: 5\n\n";

	for (int i = 0; i < plainTexts.size(); i++) {
		outFile << "Plain Text:\n";
		writeCharToFile(plainTexts[i], outFile);
		outFile << "\n Corresponding Cyph Texts:\n" ;
		for (int j = 5 * i; j < ((i + 1) * 5) - 1; j++) {
			writeIntToFile(cyphTexts[j], outFile);
		}
		outFile << "\n";
	}
	outFile.close();
}

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

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
		cyphertext.push_back(keys[let][keys[let].size() - 1]);
		//keys[let].pop_back(); did this so values wouldnt repeat but it meant a letter cannot be used more often than its avg freq (eg. b could only be used once in plaintext) which is stupid
	}
}
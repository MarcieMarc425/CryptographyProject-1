#include <iostream>
#include <iterator>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int enumChars(const char& enumee) {
	if (enumee == ' ')
		return 0;
	else
		return enumee - 96;
}

//bigram in cyphers space
struct CyphBi {
	int a;
	int b;

	bool operator==(const CyphBi& other) {
		return ((a == other.a) && (b == other.b)) ;
	}

	friend ostream& operator<<(ostream& osh, const CyphBi& cb);
};

ostream& operator<<(ostream& osh, const CyphBi& cb) {
	osh << cb.a << "," << cb.b;
	return osh;
}


//gets the absolute freqs of bigrams in cypher space 
void cyphBigramfreq(const vector<int>& cyphText, vector<float>& cyphBigramFreqs, vector<CyphBi>& cyphBigrams) {
	for (int i = 0; i < cyphText.size() - 1; i++) {
		//string bi = plainText.substr(i, 2);
		CyphBi bi;
		bi.a = cyphText[i];//to_string(cyphText[i]) + to_string(cyphText[i + 1]);
		bi.b = cyphText[i + 1];
		int pres = 0;
		for (int j = 0; j < cyphBigrams.size(); j++) {
			if (bi == cyphBigrams[j]) {
				cyphBigramFreqs[j]++;
				pres = 1;
				break;
			}
			if (pres == 1) break;
		}
		if (pres == 0) {
			cyphBigrams.push_back(bi);
			cyphBigramFreqs.push_back(1);
		}
	}

	//turns absolute freqs to fractional
	
	float sum = 0;
	for (float e : cyphBigramFreqs) {
		sum = sum + e;
	}

	for (int i = 0; i < cyphBigramFreqs.size(); i++) {
		cyphBigramFreqs[i] = cyphBigramFreqs[i] / sum;
	}
	
}

//gets the absolute frequency of bigrams in plaintext space
void plainBigramFreq( string& plainText, vector<float>& plainBigramFreqs, vector<string>& plainBigrams) {
	for (int i = 0; i < plainText.size() - 1; i++) {
		string bi = plainText.substr(i, 2); //plainText[i] + plainText[i + 1];
		int pres = 0;
		for (int j = 0; j < plainBigrams.size(); j++) {
			if (bi == plainBigrams[j]) {
				plainBigramFreqs[j]++;
				pres = 1;
				break;
			}
			if (pres == 1) break;
		}
		if (pres == 0) {
			plainBigrams.push_back(bi);
			plainBigramFreqs.push_back(1);
		}
	}

	//turns absolute freqs to fractional
	/*
	float sum = 0;
	for (float e : plainBigramFreqs) {
		sum = sum + e;
	}

	for (int i = 0; i < plainBigramFreqs.size(); i++) {
		plainBigramFreqs[i] = plainBigramFreqs[i] / sum;
	}
	*/
}

//alters absolute frequency of bigrams in plainspace to expected fractional frequency of bigrams in the cypher space
void augmentPlainBiFreqDist(vector<float>& plainBigramFreqs,const vector<string>& plainBigrams, vector<int>& letterFreqs) {
	
	//reduces for cypherperms
	vector<int> bigramPerms;
	for (int i = 0; i < plainBigrams.size(); i++) {
		bigramPerms.push_back(letterFreqs[enumChars(plainBigrams[i][0])] * letterFreqs[enumChars(plainBigrams[i][1])]);
	}

	for (int i = 0; i < plainBigramFreqs.size(); i++) {
		plainBigramFreqs[i] = plainBigramFreqs[i] / bigramPerms[i];
	}

	//turns absolute freq to fractional freq
	float sum = 0;
	for (float e : plainBigramFreqs) {
		sum = sum + e;
	}

	for (int i = 0; i < plainBigramFreqs.size(); i++) {
		plainBigramFreqs[i] = plainBigramFreqs[i] / sum;
	}
}
//old code starts

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

void encypher(const string& plainText, const CyphTable& ct, vector<int>& cyphertext) {
	vector<vector<int>> keys = ct.keys;
	vector<int> letIter;
	for (int i = 0; i < keys.size(); i++) {
		letIter.push_back(0);
	}
	for (int i = 0; i < plainText.size(); i++) {
		int let = enumChars(plainText[i]);
		cyphertext.push_back(keys[let][letIter[let]]);
		letIter[let]++;
		letIter[let] = letIter[let] % keys[let].size();
		//cyphertext.push_back(keys[let][rand() % keys[let].size()]);
	}
}

//old code ends

int main() {
	vector<string> plainSpace = {"stovepipes", "nested", "gibbousness", "cottoned", "hope", "energize", "dextrins", "travestied", "jeopardous", "nymphal", "finale", "brisking", "expatiations", "meaningless", "sampling", "freelancing", "swells", "maturates", "violators", "rankly"};
	string plainText;//" stovepipes nested gibbousness cottoned hope energize dextrins travestied jeopardous nymphal finale brisking expatiations meaningless sampling freelancing swells maturates violators rankly ";
	
	int seed;
	for (int i = 0; i < 500; i++) {
		seed = rand() % plainSpace.size();
		plainText = plainText + " ";
		plainText.append(plainSpace[seed]);
	}
	vector<int> cypherText = {};
	CyphTable ct;
	encypher(plainText, ct, cypherText);
	
	vector<float> plainBigramFreqs = {};
	vector<float> cyphBigramFreqs = {};
	vector<string> plainBigrams = {};
	vector<CyphBi> cyphBigrams = {};

	vector<int> letterFreqs = { 19,7,1,2,4,10,2,2,5,6,1,1,3,2,6,6,2,1,5,5,7,2,1,2,1,2,1 };
	vector<char> charSpace = { ' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };


	plainBigramFreq(plainText, plainBigramFreqs, plainBigrams);

	cyphBigramfreq(cypherText, cyphBigramFreqs, cyphBigrams);

	augmentPlainBiFreqDist(plainBigramFreqs, plainBigrams, letterFreqs);

	sort(plainBigramFreqs.begin(), plainBigramFreqs.end());
	sort(cyphBigramFreqs.begin(), cyphBigramFreqs.end());

	ofstream ofh("test2.txt");

	for (int i = plainBigramFreqs.size() - 1; i > -1; i--) {
		ofh << plainBigrams[i][0] << "," << plainBigrams[i][1] << ": " << plainBigramFreqs[i] << ",\t";
	}

	ofh << endl << endl;

	for (int i = cyphBigramFreqs.size() - 1; i > -1; i--) {
		ofh << cyphBigrams[i] << ": " << cyphBigramFreqs[i] << ",\t";
	}

	ofh << endl << endl << endl;

	for (int i = 0; i < ct.keys.size(); i++) {
	 	ofh << charSpace[i] << ": ";
		for (int j = 0; j < ct.keys[i].size(); j++) {
			ofh << ct.keys[i][j] << ", ";
		}
		ofh << endl;
	}

	/*
	for (int i = 0; i < plainBigrams.size(); i++) {
		cout << plainBigrams[i] << ": " << plainBigramFreqs[i] << '\t' << cyphBigramFreqs[i] << endl;
	}
	*/
}

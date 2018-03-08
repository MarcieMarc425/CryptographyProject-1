#include <iostream>
#include <iterator>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

int writeIntToFile(const vector<int>& cyphText, ofstream& outFile) {
	//ofstream outFile("cypherText.txt");
	if (!outFile) return 0; // if failed
	for (const auto &e : cyphText) outFile << e << ", ";
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
void encypher(const string& plainText, const CyphTable& ct, vector<int>& cyphertext) {
	vector<vector<int>> keys = ct.keys;
	for (int i = 0; i < plainText.size(); i++) {
		int let = enumChars(plainText[i]);
		cyphertext.push_back(keys[let][rand() % keys[let].size()]);
		//keys[let].pop_back(); did this so values wouldnt repeat but it meant a letter cannot be used more often than its avg freq (eg. b could only be used once in plaintext) which is stupid
	}
}

void constructRandText(const vector<char>& letterSpace, vector<char>& plainText, int size) {
	for (int i = 0; i < size; i++) {
		plainText.push_back(letterSpace[rand() % letterSpace.size()]);
	}
}

int main() {
	vector<char> charSpace = { ' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	//vector<vector<char>> plainTexts;
	vector<vector<int>> cyphTexts;
	CyphTable ct;
	vector<char> letterSpace;
	for (int i = 0; i < 27; i++) {
		for (int j = 0; j < ct.freqs[i]; j++) {
			letterSpace.push_back(charSpace[i]);
		}
	}
	
	/*for (int i = 0; i < 5; i++) {
		vector<char> plainText;
		constructRandText(letterSpace, plainText, 50);
		plainTexts.push_back(plainText);
	}*/
	
	string a = "dipped ligatured cannier cohabitation cuddling coiffeuses pursuance roper eternizes nullo framable paddlings femur bebop demonstrational tuberculoid theocracy women reappraise oblongatae aphasias loftiness consumptive lip neurasthenically dutchmen grift discredited resourcefulness malfeasants swallowed jogger sayable lewder editorials demimondaine tzaritza arrogations wish indisputable reproduces hygrometries gamuts alight borderlines draggle reconsolidated anemometer rowels staggerers grands nu";
	string b = "rereads predestines equippers cavitation bimolecular lucubrations cabin bettas quiverer prussians cosigner dressier bended dethronement inveigled davenport establish ganges rebroadcast supered bastiles willable abetted motionlessness demonic flatter bunyan securely tippiest tongue aw cotyledonal roomettes underlies miffs inducement overintellectually fertilize spasmodic bacchanal birdbrains decoct snakebite galliard boson headmistress unextended provence weakling pirana fiend lairds argils comma";
	string c = "trawling responsiveness tastiest pulsed restamps telescoping pneuma lampoonist divas theosophists pustules checkrowed compactor conditionals envy hairball footslogs wasteful conjures deadfall stagnantly procure barked balmier bowery vagary beaten capitalized undersized towpath envisages thermoplastic rationalizers professions workbench underarm trudger icicled incisive oilbirds citrins chambrays ungainliness weazands prehardened dims determinants fishskin cleanable henceforward misarranges fine ";
	string d = "dean iller playbooks resource anesthetic credibilities nonplus tzetzes incursions stooged envelopments girdling risibility thrum repeaters catheterizing misbestowed cursing malingerers ensconces lippiest accost superannuate slush opinionated rememberer councils mishandling drivels juryless slashers tangent roistering scathing apprenticing fleabite sault achier quantize registrable nobbler sheaf natantly kashmirs dittoes scanned emissivity iodize dually refunded portliest setbacks eureka needines";
	string e = "mammate punners octette asylum nonclinically trotters slant collocation cardiology enchants ledge deregulated bottommost capsulate biotechnologies subtended cloddiest training joneses catafalque fieldmice hostels affect shrimper differentiations metacarpus amebas sweeter shiatsu oncoming tubeless menu professing apostatizing moreover eumorphic casked euphemistically programmability campaniles chickpea inactivates crossing defoggers reassures tableland doze reassembled striate precocious noncomba";

	vector<string> plainTexts = {a,b,c,d,e};


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
		//writeCharToFile(plainTexts[i], outFile);
		outFile << plainTexts[i];
		outFile << "\n Corresponding Cyph Texts:\n";
		for (int j = 5 * i; j < ((i + 1) * 5) - 1; j++) {
			writeIntToFile(cyphTexts[j], outFile);
		}
		outFile << "\n";
	}
	outFile.close();
}

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <time.h>
#include <sstream>
using namespace std;

void readPlainText(const vector<string>& plaintext, vector<vector<int>>& vec) {
	int i = 0;
	for (size_t ptext_num = 0; ptext_num < plaintext.size(); ptext_num++) {
		for (size_t char_pos = 0; char_pos < plaintext[ptext_num].length(); char_pos++) {
			if (plaintext[ptext_num][char_pos] != 32) {
				if (vec[(plaintext[ptext_num][char_pos] - 96) + 27 * i].empty())
					vec[(plaintext[ptext_num][char_pos] - 96) + 27 * i].push_back(0);
				vec[(plaintext[ptext_num][char_pos] - 96) + 27 * i][0]++;
				vec[(plaintext[ptext_num][char_pos] - 96) + 27 * i].push_back(char_pos);
			}
			else {
				if (vec[0 + 27 * i].empty())
					vec[0 + 27 * i].push_back(0);
				vec[0][0]++;
				vec[0].push_back(char_pos);
			}
		}
		i++;
	}
	return;
}

// Function for delimiting ',' in cipher input and storing result to string vector
//
void processCipher(const string& cipher, vector<string>& cipher_vc) {
	istringstream ss(cipher);
	string ciphertext;
	while (getline(ss, ciphertext, ',')) {
		cipher_vc.push_back(ciphertext);
	}
}

// Function for reading cipher text vector and writing occurrences and positions for each int in cipher
// vector[x] contain each int (from 0 - 105)
// vector[x][y] contain the info for each int x (occurences, positions)
// vector[x][0] to access occurrence for int x
// vector[x][i] = positions of int x where i > 0
//
void freq_analysis(const vector<string>& cipher_vc, vector<vector<int>>& frequency) {
	for (size_t pos = 0; pos < cipher_vc.size(); pos++) {
		int num = atoi(cipher_vc[pos].c_str());
		frequency[num][0]++;
		frequency[num].push_back(pos);
	}
}

// Function for comparing plaintext frequency table to cipher text int frequency
// 'b' occurs 9, 16, 9, 10, 9 times in plaintext text 1, 2, 3, 4, 5 respectively
// If int x from cipher_freq[x] occurs 9 times (cipher_freq[x][0] = 9), then int x is a candidate for char 'b' in plaintext 1, 3, 5
// Compare positions of int x from cipher to plaintext (plain_freq == cipher_freq)
//
int compare_freq(const vector<vector<int>>& plain_freq, const vector<vector<int>>& cipher_freq) {

	for (size_t i = 0; i < cipher_freq.size(); i++) {
		if (cipher_freq[i][0] == 9) {
			for (int j = 0; j <= 4; j += 2) {
				if (plain_freq[2 + 27 * j] == cipher_freq[i])
					return j;
			}

		}
		else if (cipher_freq[i][0] == 16) {
			if (plain_freq[2 + 27 * 1] == cipher_freq[i])
				return 1;
		}
		else if (cipher_freq[i][0] == 10) {
			if (plain_freq[2 + 27 * 3] == cipher_freq[i])
				return 3;
		}
	}

	return -1;
}

int decypherTest1(){
	/* <========== Ask user input for cipher text, thus beginning deciphering process ==========> */
	string cipher;
	cout << "Enter the comma separated ciphertext:" << endl;
	cin >> cipher;

	/* <========== Find occurrences and positions of chars in plaintext ==========> */
	vector<string> plaintext = { "dipped ligatured cannier cohabitation cuddling coiffeuses pursuance roper eternizes nullo framable paddlings femur bebop demonstrational tuberculoid theocracy women reappraise oblongatae aphasias loftiness consumptive lip neurasthenically dutchmen grift discredited resourcefulness malfeasants swallowed jogger sayable lewder editorials demimondaine tzaritza arrogations wish indisputable reproduces hygrometries gamuts alight borderlines draggle reconsolidated anemometer rowels staggerers grands nu","rereads predestines equippers cavitation bimolecular lucubrations cabin bettas quiverer prussians cosigner dressier bended dethronement inveigled davenport establish ganges rebroadcast supered bastiles willable abetted motionlessness demonic flatter bunyan securely tippiest tongue aw cotyledonal roomettes underlies miffs inducement overintellectually fertilize spasmodic bacchanal birdbrains decoct snakebite galliard boson headmistress unextended provence weakling pirana fiend lairds argils comma",	"trawling responsiveness tastiest pulsed restamps telescoping pneuma lampoonist divas theosophists pustules checkrowed compactor conditionals envy hairball footslogs wasteful conjures deadfall stagnantly procure barked balmier bowery vagary beaten capitalized undersized towpath envisages thermoplastic rationalizers professions workbench underarm trudger icicled incisive oilbirds citrins chambrays ungainliness weazands prehardened dims determinants fishskin cleanable henceforward misarranges fine ",	"dean iller playbooks resource anesthetic credibilities nonplus tzetzes incursions stooged envelopments girdling risibility thrum repeaters catheterizing misbestowed cursing malingerers ensconces lippiest accost superannuate slush opinionated rememberer councils mishandling drivels juryless slashers tangent roistering scathing apprenticing fleabite sault achier quantize registrable nobbler sheaf natantly kashmirs dittoes scanned emissivity iodize dually refunded portliest setbacks eureka needines",	"mammate punners octette asylum nonclinically trotters slant collocation cardiology enchants ledge deregulated bottommost capsulate biotechnologies subtended cloddiest training joneses catafalque fieldmice hostels affect shrimper differentiations metacarpus amebas sweeter shiatsu oncoming tubeless menu professing apostatizing moreover eumorphic casked euphemistically programmability campaniles chickpea inactivates crossing defoggers reassures tableland doze reassembled striate precocious noncomba" };
	vector<vector<int>> candidate_text(135);

	readPlainText(plaintext, candidate_text);

	/* <========== Delimit comma from cipher text and store in string vector ==========> */
	vector<string> cipher_vc;
	processCipher(cipher, cipher_vc);

	/* <========== Find occurrences and positiosn of int in ciphertext ==========> */
	vector<vector<int>> cipher_text(106);
	for (size_t i = 0; i < cipher_text.size(); i++) {
		cipher_text[i].push_back(0);
	}
	freq_analysis(cipher_vc, cipher_text);

	/* <========== Compare occurences and positions of 'b' in ciphertext to plaintext ==========> */
	int result = compare_freq(candidate_text, cipher_text);
	cout << "My plaintext guess is: " << result + 1 << endl;

	return 0;
}

void find_and_replace(string& source, string const& find, string const& replace){
	if(source == find){
		source = replace;
	}
}

void find_and_replace_old(string& source, string const& find, string const& replace)
{
    for(string::size_type i = 0; (i = source.find(find, i)) != string::npos;)
    {
        source.replace(i, find.length(), replace);
        i += replace.length();
    }
}

vector<string> test2(vector<string> ciphertext_vc_copy){
	string temp_val[146];
	string temp_char[146];
	vector<string> ciphertext;
	ciphertext = ciphertext_vc_copy;
	string characters[] = {" ","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
	bool flag = false;
	for (int i = 4; i < ciphertext_vc_copy.size()-7;i++){
		if(ciphertext_vc_copy[i] == ciphertext_vc_copy[i-1]){
			flag = true;
			temp_val[0] = ciphertext[i];
			temp_char[0] = "b";					
			ciphertext[i] = 'b';
			
			temp_val[51] = ciphertext[i-4];
			temp_char[51] = " ";
			ciphertext[i-4] = ' ';

			temp_val[1] = ciphertext[i-3];
			temp_char[1] = "g";
			ciphertext[i-3] = 'g';
			
			temp_val[2] = ciphertext[i-2];
			temp_char[2] = "i";
			ciphertext[i-2] = 'i';
			
			temp_val[3] = ciphertext[i-1];
			temp_char[3] = "b";
			ciphertext[i-1] = 'b';
				
			temp_val[4] = ciphertext[i+1];
			temp_char[4] = "o";
			ciphertext[i+1] = 'o';
			
			temp_val[5] = ciphertext[i+2];
			temp_char[5] = "u";
			ciphertext[i+2] = 'u';
			
			temp_val[6] = ciphertext[i+3];
			temp_char[6] = "s";
			ciphertext[i+3] = 's';
			
			temp_val[7] = ciphertext[i+4];
			temp_char[7] = "n";
			ciphertext[i+4] = 'n';
			
			temp_val[8] = ciphertext[i+5];
			temp_char[8] = "e";
			ciphertext[i+5] = 'e';
			
			temp_val[9] = ciphertext[i+6];
			temp_char[9] = "s";
			ciphertext[i+6] = 's';
			
			temp_val[10] = ciphertext[i+7];
			temp_char[10] = "s";
			ciphertext[i+7] = 's';

			if(i != ciphertext_vc_copy.size()-8){
				temp_val[11] = ciphertext[i+8];
				temp_char[11] = " ";
				ciphertext[i+8] = ' ';
			}
		}

	}
	//cout<<"After 1st for loop"<<endl;
	for (int i = 2; i < ciphertext_vc_copy.size()-1;i++){
		if ((ciphertext_vc_copy[i] != ciphertext_vc_copy[i-1])&&(ciphertext_vc_copy[i] != ciphertext_vc_copy[i+1])&&(ciphertext_vc_copy[i-2] != ciphertext_vc_copy[i-1])){
			if((ciphertext_vc_copy[i-1] == temp_val[0])){
				ciphertext[i-1] = 'b';
					
				temp_val[50] = ciphertext[i-2];
				temp_char[50] = " ";
				ciphertext[i-2] = ' ';
				
				temp_val[12] = ciphertext[i];
				temp_char[12] = "r";
				ciphertext[i]   = 'r';
				
				temp_val[13] = ciphertext[i+1];
				temp_char[13] = "i";
				ciphertext[i+1] = 'i';
				
				temp_val[14] = ciphertext[i+2];
				temp_char[14] = "s";
				ciphertext[i+2] = 's';
				
				temp_val[15] = ciphertext[i+3];
				temp_char[15] = "k";
				ciphertext[i+3] = 'k';
				
				temp_val[16] = ciphertext[i+4];
				temp_char[16] = "i";
				ciphertext[i+4] = 'i';
				
				temp_val[17] = ciphertext[i+5];
				temp_char[17] = "n";
				ciphertext[i+5] = 'n';
				
				temp_val[18] = ciphertext[i+6];
				temp_char[18] = "g";
				ciphertext[i+6] = 'g';
				
				temp_val[19] = ciphertext[i+7];
				temp_char[19] = " ";
				ciphertext[i+7] = ' ';
			}
		}
	}
	//cout<<"After 2nd for loop"<<endl;
	for (int i = 4; i < ciphertext_vc_copy.size()-2;i++){
		if((ciphertext_vc_copy[i] == temp_val[15]) && ciphertext_vc_copy[i-4] != temp_val[0]){
			
			temp_val[49] = ciphertext[i-4];
			temp_char[49] = " ";
			ciphertext[i-4] = ' ';
			
			temp_val[20] = ciphertext[i-3];
			//cout<<"r:	"<<ciphertext[i-3]<<endl;
			temp_char[20] = "r";
			ciphertext[i-3]   = 'r';
			
			temp_val[21] = ciphertext[i-2];
			temp_char[21] = "a";
			ciphertext[i-2] = 'a';
			
			temp_val[22] = ciphertext[i-1];
			//cout<<"n:	"<<ciphertext[i-1]<<endl;
			temp_char[22] = "n";
			ciphertext[i-1] = 'n';
						
			temp_val[23] = ciphertext[i+1];
			temp_char[23] = "l";
			ciphertext[i+1] = 'l';
			
			temp_val[24] = ciphertext[i+2];
			//cout<<"y:	"<<ciphertext[i+2]<<endl;
			temp_char[24] = "y";
			ciphertext[i+2] = 'y';
			if(i != ciphertext_vc_copy.size()-3){
				temp_val[25] = ciphertext[i+3];
				temp_char[25] = " ";
				ciphertext[i+3] = ' ';
			}
		}
	}
	//cout<<"After 3rd for loop"<<endl;
	if(ciphertext_vc_copy[3] == temp_val[15]){
		//cout<<"entered IF"<<endl;
		temp_val[26] = ciphertext[0];
		//cout<<"r:	"<<ciphertext[0]<<endl;
		temp_char[26] = "r";
		ciphertext[0]   = 'r';
		
		temp_val[27] = ciphertext[1];
		temp_char[27] = "a";
		ciphertext[1] = 'a';
		
		temp_val[28] = ciphertext[2];
		//cout<<"n:	"<<ciphertext[2]<<endl;
		temp_char[28] = "n";
		ciphertext[2] = 'n';
					
		temp_val[29] = ciphertext[4];
		temp_char[29] = "l";
		ciphertext[4] = 'l';
		
		temp_val[30] = ciphertext[5];
		//cout<<"y:	"<<ciphertext[5]<<endl;
		temp_char[30] = "y";
		ciphertext[5] = 'y';
		
		temp_val[31] = ciphertext[6];
		temp_char[31] = " ";
		ciphertext[6] = ' ';
	}	
	//cout<<"After 4th for loop"<<endl;
	for (int i = 2; i < ciphertext_vc_copy.size()-5;i++){
		if((ciphertext_vc_copy[i] == temp_val[24])||(ciphertext_vc_copy[i] == temp_val[30])){
			if(ciphertext_vc_copy[i-2] != temp_val[15]){
				temp_val[48] = ciphertext[i-2];
				temp_char[48] = " ";
				ciphertext[i-2] = ' ';
				
				temp_val[41] = ciphertext[i-1];
				temp_char[41] = "n";
				ciphertext[i-1] = 'n';
				
				temp_val[42] = ciphertext[i+1];
				temp_char[42] = "m";
				ciphertext[i+1] = 'm';
				
				temp_val[43] = ciphertext[i+2];
				temp_char[43] = "p";
				ciphertext[i+2] = 'p';
				
				temp_val[44] = ciphertext[i+3];
				temp_char[44] = "h";
				ciphertext[i+3] = 'h';
				
				temp_val[45] = ciphertext[i+4];
				temp_char[45] = "a";
				ciphertext[i+4] = 'a';
				
				temp_val[46] = ciphertext[i+5];
				temp_char[46] = "l";
				ciphertext[i+5] = 'l';
				
				if(i != ciphertext_vc_copy.size()-6){
					temp_val[47] = ciphertext[i+6];
					temp_char[47] = " ";
					ciphertext[i+6] = ' ';
				}
			}
		}
	}
	//cout<<"After 5th for loop"<<endl;
	if(ciphertext_vc_copy[0] == temp_val[0]){
		temp_val[32] = ciphertext[0];
		temp_char[32] = "b";
		ciphertext[0] = 'b';
		
		temp_val[33] = ciphertext[1];
		temp_char[33] = "r";
		ciphertext[1] = 'r';
		
		temp_val[34] = ciphertext[2];
		temp_char[34] = "i";
		ciphertext[2] = 'i';
		
		temp_val[35] = ciphertext[3];
		temp_char[35] = "s";
		ciphertext[3] = 's';
		
		temp_val[36] = ciphertext[4];
		temp_char[36] = "k";
		ciphertext[4] = 'k';
		
		temp_val[37] = ciphertext[5];
		temp_char[37] = "i";
		ciphertext[5] = 'i';
		
		temp_val[38] = ciphertext[6];
		temp_char[38] = "n";
		ciphertext[6] = 'n';
		
		temp_val[39] = ciphertext[7];
		temp_char[39] = "g";
		ciphertext[7] = 'g';
		
		temp_val[40] = ciphertext[8];
		temp_char[40] = "l";
		ciphertext[8] = ' ';
	}
	//cout<<"After 6th for loop"<<endl;
	
	if(ciphertext_vc_copy[2] == ciphertext_vc_copy[3]){
		temp_val[52] = ciphertext[0];
		temp_char[52] = "g";
		ciphertext[0] = 'g';
		
		temp_val[53] = ciphertext[1];
		temp_char[53] = "i";
		ciphertext[1] = 'i';
		
		temp_val[54] = ciphertext[4];
		temp_char[54] = "o";
		ciphertext[4] = 'o';
		
		temp_val[55] = ciphertext[5];
		temp_char[55] = "u";
		ciphertext[5] = 'u';
		
		temp_val[56] = ciphertext[6];
		temp_char[56] = "s";
		ciphertext[6] = 's';
		
		temp_val[57] = ciphertext[7];
		temp_char[57] = "n";
		ciphertext[7] = 'n';
		
		temp_val[58] = ciphertext[8];
		temp_char[58] = "e";
		ciphertext[8] = 'e';
		
		temp_val[59] = ciphertext[9];
		temp_char[59] = "s";
		ciphertext[9] = 's';
		
		temp_val[60] = ciphertext[10];
		temp_char[60] = "s";
		ciphertext[10] = 's';

		temp_val[61] = ciphertext[11];
		temp_char[61] = " ";
		ciphertext[11] = ' ';
		
		temp_val[62] = ciphertext[2];
		temp_char[62] = "b";
		ciphertext[2] = 'b';
		
		temp_val[63] = ciphertext[3];
		temp_char[63] = "b";
		ciphertext[3] = 'b';

	}
		
	//cout<<"After 7th for loop"<<endl;
	for(int i = 0; i < ciphertext_vc_copy.size();i++){
		if(flag == true){
			for (int j = 0; j<64; j++){
				find_and_replace(ciphertext[i], temp_val[j], temp_char[j]);
			}
		}
	}
	//cout<<"After 8th for loop"<<endl;
	
	for (int j = 0; j<5; j++){
		for (int i=0; i<ciphertext_vc_copy.size();i++){
			if(ciphertext[i] == characters[0]){
				if(ciphertext[i+1] == characters[8]){
					temp_val[64] = ciphertext[i+2];
					temp_char[64] = "o";
					ciphertext[i+2] = 'o';
					temp_val[65] = ciphertext[i+3];
					temp_char[65] = "p";
					ciphertext[i+3] = 'p';
					temp_val[66] = ciphertext[i+4];
					temp_char[66] = "e";
					ciphertext[i+4] = 'e';
					if(i != ciphertext_vc_copy.size()-5){
					temp_val[67] = ciphertext[i+5];
					temp_char[67] = " ";
					ciphertext[i+5] = ' ';}
				}
				if(ciphertext[i+1] == characters[14]){
					if(ciphertext[i+2] != characters[25]){
						temp_val[68] = ciphertext[i+2];
						temp_char[68] = "e";
						ciphertext[i+2] = 'e';
						temp_val[69] = ciphertext[i+3];
						temp_char[69] = "s";
						ciphertext[i+3] = 's';
						temp_val[70] = ciphertext[i+4];
						temp_char[70] = "t";
						ciphertext[i+4] = 't';
						temp_val[71] = ciphertext[i+5];
						temp_char[71] = "e";
						ciphertext[i+5] = 'e';
						temp_val[72] = ciphertext[i+6];
						temp_char[72] = "d";
						ciphertext[i+6] = 'd';
						if(i != ciphertext_vc_copy.size()-7){
						temp_val[73] = ciphertext[i+7];
						temp_char[73] = " ";
						ciphertext[i+7] = ' ';}
					}
				}
				if(ciphertext[i+1] == characters[5]){
					//cout<<"entered E"<<endl;
					if((ciphertext[i+2] == characters[14])||(ciphertext[i+3] == characters[4])||(ciphertext[i+4] == characters[18])||(ciphertext[i+5] == characters[7])||(ciphertext[i+7] == characters[26])||(ciphertext[i+8] == characters[5])){
						//cout<<"entered energize"<<endl;
						temp_val[74] = ciphertext[i+2];
						temp_char[74] = "n";
						ciphertext[i+2] = 'n';
						temp_val[75] = ciphertext[i+3];
						temp_char[75] = "e";
						ciphertext[i+3] = 'e';
						temp_val[76] = ciphertext[i+4];
						temp_char[76] = "r";
						ciphertext[i+4] = 'r';
						temp_val[77] = ciphertext[i+5];
						temp_char[77] = "g";
						ciphertext[i+5] = 'g';
						temp_val[78] = ciphertext[i+6];
						temp_char[78] = "i";
						ciphertext[i+6] = 'i';
						temp_val[79] = ciphertext[i+7];
						temp_char[79] = "z";
						ciphertext[i+7] = 'z';
						temp_val[80] = ciphertext[i+8];
						temp_char[80] = "e";
						ciphertext[i+8] = 'e';
						if(i != ciphertext_vc_copy.size()-9){
						temp_val[81] = ciphertext[i+9];
						temp_char[81] = " ";
						ciphertext[i+9] = ' ';}				
					}
					else {
						temp_val[82] = ciphertext[i+2];
						temp_char[82] = "x";
						ciphertext[i+2] = 'x';
						temp_val[83] = ciphertext[i+3];
						temp_char[83] = "p";
						ciphertext[i+3] = 'p';
						temp_val[84] = ciphertext[i+4];
						temp_char[84] = "a";
						ciphertext[i+4] = 'a';
						temp_val[85] = ciphertext[i+5];
						temp_char[85] = "t";
						ciphertext[i+5] = 't';
						temp_val[86] = ciphertext[i+6];
						temp_char[86] = "i";
						ciphertext[i+6] = 'i';
						temp_val[87] = ciphertext[i+7];
						temp_char[87] = "a";
						ciphertext[i+7] = 'a';
						temp_val[88] = ciphertext[i+8];
						temp_char[88] = "t";
						ciphertext[i+8] = 't';
						temp_val[89] = ciphertext[i+9];
						temp_char[89] = "i";
						ciphertext[i+9] = 'i';
						temp_val[90] = ciphertext[i+10];
						temp_char[90] = "o";
						ciphertext[i+10] = 'o';
						temp_val[91] = ciphertext[i+11];
						temp_char[91] = "n";
						ciphertext[i+11] = 'n';
						temp_val[92] = ciphertext[i+12];
						temp_char[92] = "s";
						ciphertext[i+12] = 's';
						if(i != ciphertext_vc_copy.size()-13){
						temp_val[93] = ciphertext[i+13];
						temp_char[93] = " ";
						ciphertext[i+13] = ' ';		}			
					}
				//cout<<"Exit E"<<endl;
				}	
				if(ciphertext[i+1] == characters[13]){
					//cout<<"entered if"<<endl;
					if((ciphertext[i+2] == characters[5])||(ciphertext[i+3] == characters[1])||(ciphertext[i+4] == characters[14])||(ciphertext[i+5] == characters[9])||(ciphertext[i+6] == characters[14])||(ciphertext[i+7] == characters[7])||(ciphertext[i+8] == characters[12])||(ciphertext[i+9] == characters[5])||(ciphertext[i+10] == characters[19])){
						temp_val[94] = ciphertext[i+2];
						temp_char[94] = "e";
						ciphertext[i+2] = 'e';
						temp_val[95] = ciphertext[i+3];
						temp_char[95] = "a";
						ciphertext[i+3] = 'a';
						temp_val[96] = ciphertext[i+4];
						temp_char[96] = "n";
						ciphertext[i+4] = 'n';
						temp_val[97] = ciphertext[i+5];
						temp_char[97] = "i";
						ciphertext[i+5] = 'i';
						temp_val[98] = ciphertext[i+6];
						temp_char[98] = "n";
						ciphertext[i+6] = 'n';
						temp_val[99] = ciphertext[i+7];
						temp_char[99] = "g";
						ciphertext[i+7] = 'g';
						temp_val[100] = ciphertext[i+8];
						temp_char[100] = "l";
						ciphertext[i+8] = 'l';
						temp_val[101] = ciphertext[i+9];
						temp_char[101] = "e";
						ciphertext[i+9] = 'e';
						temp_val[102] = ciphertext[i+10];
						temp_char[102] = "s";
						ciphertext[i+10] = 's';
						temp_val[103] = ciphertext[i+11];
						temp_char[103] = "s";
						ciphertext[i+11] = 's';
						if(i != ciphertext_vc_copy.size()-12){
						temp_val[104] = ciphertext[i+12];
						temp_char[104] = " ";
						ciphertext[i+12] = ' ';}
					}
					else{
						temp_val[105] = ciphertext[i+2];
						temp_char[105] = "a";
						ciphertext[i+2] = 'a';
						temp_val[106] = ciphertext[i+3];
						temp_char[106] = "t";
						ciphertext[i+3] = 't';
						temp_val[107] = ciphertext[i+4];
						temp_char[107] = "u";
						ciphertext[i+4] = 'u';
						temp_val[108] = ciphertext[i+5];
						temp_char[108] = "r";
						ciphertext[i+5] = 'r';
						temp_val[109] = ciphertext[i+6];
						temp_char[109] = "a";
						ciphertext[i+6] = 'a';
						temp_val[110] = ciphertext[i+7];
						temp_char[110] = "t";
						ciphertext[i+7] = 't';
						temp_val[111] = ciphertext[i+8];
						temp_char[111] = "e";
						ciphertext[i+8] = 'e';
						temp_val[112] = ciphertext[i+9];
						temp_char[112] = "s";
						ciphertext[i+9] = 's';
						if(i != ciphertext_vc_copy.size()-10){
						temp_val[113] = ciphertext[i+10];
						temp_char[113] = " ";
						ciphertext[i+10] = ' ';}
					}
				}
				
				if(ciphertext[i+1] == characters[19]){
					//if((ciphertext[i+2] == characters[20])||(ciphertext[i+3] == characters[15])||(ciphertext[i+4] == characters[22])||(ciphertext[i+5] == characters[5])||(ciphertext[i+6] == characters[16])||(ciphertext[i+7] == characters[9])||(ciphertext[i+8] == characters[16])||(ciphertext[i+9] == characters[5])||(ciphertext[i+10] == characters[19])){
					if((ciphertext[i+3] == characters[15])||(ciphertext[i+2] == characters[20])){
						temp_val[114] = ciphertext[i+2];
						temp_char[114] = "t";
						ciphertext[i+2] = 't';
						temp_val[115] = ciphertext[i+3];
						temp_char[115] = "o";
						ciphertext[i+3] = 'o';
						temp_val[116] = ciphertext[i+4];
						temp_char[116] = "v";
						ciphertext[i+4] = 'v';
						temp_val[117] = ciphertext[i+5];
						temp_char[117] = "e";
						ciphertext[i+5] = 'e';
						temp_val[118] = ciphertext[i+6];
						temp_char[118] = "p";
						ciphertext[i+6] = 'p';
						temp_val[119] = ciphertext[i+7];
						temp_char[119] = "i";
						ciphertext[i+7] = 'i';
						temp_val[120] = ciphertext[i+8];
						temp_char[120] = "p";
						ciphertext[i+8] = 'p';
						temp_val[121] = ciphertext[i+9];
						temp_char[121] = "e";
						ciphertext[i+9] = 'e';
						temp_val[122] = ciphertext[i+10];
						temp_char[122] = "s";
						ciphertext[i+10] = 's';
						if(i != ciphertext_vc_copy.size()-11){
						temp_val[123] = ciphertext[i+11];
						temp_char[123] = " ";
						ciphertext[i+11] = ' ';}
					}
					//else if((ciphertext[i+2] == characters[1])||(ciphertext[i+3] == characters[13])||(ciphertext[i+4] == characters[16])||(ciphertext[i+5] == characters[12])||(ciphertext[i+6] == characters[9])||(ciphertext[i+7] == characters[14])){
					else if((ciphertext[i+2] == characters[1])){
						temp_val[124] = ciphertext[i+2];
						temp_char[124] = "a";
						ciphertext[i+2] = 'a';
						temp_val[125] = ciphertext[i+3];
						temp_char[125] = "m";
						ciphertext[i+3] = 'm';
						temp_val[126] = ciphertext[i+4];
						temp_char[126] = "p";
						ciphertext[i+4] = 'p';
						temp_val[127] = ciphertext[i+5];
						temp_char[127] = "l";
						ciphertext[i+5] = 'l';
						temp_val[128] = ciphertext[i+6];
						temp_char[128] = "i";
						ciphertext[i+6] = 'i';
						temp_val[129] = ciphertext[i+7];
						temp_char[129] = "n";
						ciphertext[i+7] = 'n';
						temp_val[130] = ciphertext[i+8];
						temp_char[130] = "g";
						ciphertext[i+8] = 'g';
						if(i != ciphertext_vc_copy.size()-9){
						temp_val[131] = ciphertext[i+9];
						temp_char[131] = " ";
						ciphertext[i+9] = ' ';}
					}
					//else if((ciphertext[i+2] == characters[23])||(ciphertext[i+3] == characters[5])||(ciphertext[i+4] == characters[12])||(ciphertext[i+5] == characters[12])||(ciphertext[i+6] == characters[19])){
					else if((ciphertext[i+3] == characters[5]) || (ciphertext[i+2] == characters[23])){
						temp_val[132] = ciphertext[i+2];
						temp_char[132] = "w";
						ciphertext[i+2] = 'w';
						temp_val[133] = ciphertext[i+3];
						temp_char[133] = "e";
						ciphertext[i+3] = 'e';
						temp_val[134] = ciphertext[i+4];
						temp_char[134] = "l";
						ciphertext[i+4] = 'l';
						temp_val[135] = ciphertext[i+5];
						temp_char[135] = "l";
						ciphertext[i+5] = 'l';
						temp_val[136] = ciphertext[i+6];
						temp_char[136] = "s";
						ciphertext[i+6] = 's';
						if(i != ciphertext_vc_copy.size()-7){
						temp_val[137] = ciphertext[i+7];
						temp_char[137] = " ";
						ciphertext[i+7] = ' ';}
					}
					
				}
				if(ciphertext[i+1] == characters[22]){
					temp_val[138] = ciphertext[i+2];
					temp_char[138] = "i";
					ciphertext[i+2] = 'i';
					temp_val[139] = ciphertext[i+3];
					temp_char[139] = "o";
					ciphertext[i+3] = 'o';
					temp_val[140] = ciphertext[i+4];
					temp_char[140] = "l";
					ciphertext[i+4] = 'l';
					temp_val[141] = ciphertext[i+5];
					temp_char[141] = "a";
					ciphertext[i+5] = 'a';
					temp_val[142] = ciphertext[i+6];
					temp_char[142] = "t";
					ciphertext[i+6] = 't';
					temp_val[143] = ciphertext[i+7];
					temp_char[143] = "o";
					ciphertext[i+7] = 'o';
					temp_val[144] = ciphertext[i+8];
					temp_char[144] = "r";
					ciphertext[i+8] = 'r';
					temp_val[145] = ciphertext[i+9];
					temp_char[145] = "s";
					ciphertext[i+9] = 's';
					if(i != ciphertext_vc_copy.size()-10){
					temp_val[146] = ciphertext[i+10];
					temp_char[146] = " ";
					ciphertext[i+10] = ' ';}

				}
			}
		}
		
		for(int i = 0; i < ciphertext_vc_copy.size();i++){
			if(flag == true){
				for (int j = 64; j<146; j++){
					find_and_replace(ciphertext[i], temp_val[j], temp_char[j]);
				}
			}
		}	
		
	}
	return ciphertext;
}

int decypherTest2(){
	string cipher_input;
	vector<string> plaintext;
	vector<string> ciphertext_vc_copy;
	string english_words[20] = {"stovepipes" , "sampling" , "swells", "nested", "nymphal", "gibbousness", "cottoned", "hope", "energize", "expatiations", "dextrins", "travested","jeopardous","finale","freelancing" , "briskling", "meaningless", "maturates" , "violates", "rankly"};


	// Takes care of comma-separated values
	cout << "Enter your ciphertext" << endl;
	cin>>cipher_input;
	
	std::istringstream ss(cipher_input);
	std::string ciphertext;
	vector<string> ciphertext_vc;
	while(std::getline(ss, ciphertext, ',')) {
		ciphertext_vc.push_back(ciphertext);
		ciphertext_vc_copy.push_back(ciphertext);
	}
	//cout<<"Size of ciphertext vector is:	"<<ciphertext_vc.size()<<endl;
	plaintext = test2(ciphertext_vc_copy);
	
	//cout<<"Size of plaintext vector is:	"<<plaintext.size()<<endl;
	cout<<endl;
	cout<<"My plaintext guess is:	";
	for(int i = 0;i<plaintext.size();i++){
		cout<<plaintext[i]<<"";
	}
	cout<<endl;
	return 0;
}

int main() {
	int test;
	cout << "Enter test number to conduct:";
	cin >> test;

	if (test == 1) decypherTest1();
	if (test == 2) decypherTest2();


}
/*
	Cryptography Project 1 Test 1 Solution
	Date Due: March 10
	Authors: Dayan Siddiqui, Nimisha Limaye, Marc Tse, Michael Zhou
*/

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <time.h>
#include <sstream>
using namespace std;

/* <========================================= ENCRYPTION =========================================> */

void encrypt(string plaintext) {
	int key_space[106];
	int encrypt_space[19];
	int encrypt_a[7];
	int encrypt_b[1];
	int encrypt_c[2];
	int encrypt_d[4];
	int encrypt_e[10];
	int encrypt_f[2];
	int encrypt_g[2];
	int encrypt_h[5];
	int encrypt_i[6];
	int encrypt_j[1];
	int encrypt_k[1];
	int encrypt_l[3];
	int encrypt_m[2];
	int encrypt_n[6];
	int encrypt_o[6];
	int encrypt_p[2];
	int encrypt_q[1];
	int encrypt_r[5];
	int encrypt_s[5];
	int encrypt_t[7];
	int encrypt_u[2];
	int encrypt_v[1];
	int encrypt_w[2];
	int encrypt_x[1];
	int encrypt_y[2];
	int encrypt_z[1];
	int ciphertext[550] = { 0 };
	int i;
	for (int i = 0; i<106; i++) {
		key_space[i] = i;
		//cout<<key_space[i]<<endl;		
	}
	srand(time(0));
	random_shuffle(&key_space[0], &key_space[106]);
	//for (int i =0; i<106; i++){
	//	cout<<key_space[i]<<endl;
	//}
	//spliting key_space into corresponding groups for alphabets and space.
	//cout<<"first for loop"<<endl;
	for (int i = 0; i<19; i++) {
		encrypt_space[i] = key_space[i];
	}
	//cout<<"second for loop"<<endl;
	for (int i = 0; i<7; i++) {
		encrypt_a[i] = key_space[i + 19];
	}
	//cout<<"third for loop"<<endl;
	for (int i = 0; i<1; i++) {
		//cout<<"entered"<<endl;
		//cout<<i<<endl;
		encrypt_b[i] = key_space[i + 26];
	}
	//cout<<"fourth for loop"<<endl;
	for (int i = 0; i<2; i++) {
		encrypt_c[i] = key_space[i + 27];
	}
	//cout<<"fifth for loop"<<endl;
	for (int i = 0; i<4; i++) {
		encrypt_d[i] = key_space[i + 29];
		//cout<<encrypt_d[i]<<endl;
	}
	//cout<<"sixth for loop"<<endl;
	for (int i = 0; i<10; i++) {
		encrypt_e[i] = key_space[i + 33];
	}
	//cout<<"seventh for loop"<<endl;
	for (i = 0; i<2; i++) {
		//cout<<"entered"<<endl;
		//cout<<i<<endl;	
		encrypt_f[i] = key_space[i + 43];
	}
	//cout<<"eight for loop"<<endl;
	for (int i = 0; i<2; i++) {
		encrypt_g[i] = key_space[i + 45];
	}
	//cout<<"ninth for loop"<<endl;
	for (int i = 0; i<5; i++) {
		encrypt_h[i] = key_space[i + 47];
	}
	//cout<<"10th for loop"<<endl;
	for (int i = 0; i<6; i++) {
		encrypt_i[i] = key_space[i + 52];
	}
	//cout<<"11th for loop"<<endl;
	for (int i = 0; i<1; i++) {
		encrypt_j[i] = key_space[i + 58];
	}
	//cout<<"12th for loop"<<endl;
	for (int i = 0; i<1; i++) {
		encrypt_k[i] = key_space[i + 59];
	}
	//cout<<"13th for loop"<<endl;
	for (int i = 0; i<3; i++) {
		encrypt_l[i] = key_space[i + 60];
	}
	//cout<<"14th for loop"<<endl;
	for (int i = 0; i<2; i++) {
		encrypt_m[i] = key_space[i + 63];
	}
	//cout<<"15th for loop"<<endl;
	for (int i = 0; i<6; i++) {
		encrypt_n[i] = key_space[i + 65];
	}
	//cout<<"16th for loop"<<endl;
	for (int i = 0; i<6; i++) {
		encrypt_o[i] = key_space[i + 71];
	}
	//cout<<"17th for loop"<<endl;
	for (int i = 0; i<2; i++) {
		encrypt_p[i] = key_space[i + 77];
	}
	//cout<<"18th for loop"<<endl;
	for (int i = 0; i<1; i++) {
		encrypt_q[i] = key_space[i + 79];
	}
	//cout<<"19th for loop"<<endl;
	for (int i = 0; i<5; i++) {
		encrypt_r[i] = key_space[i + 80];
	}
	//cout<<"20th for loop"<<endl;
	for (int i = 0; i<5; i++) {
		encrypt_s[i] = key_space[i + 85];
	}
	//cout<<"21st for loop"<<endl;
	for (int i = 0; i<7; i++) {
		encrypt_t[i] = key_space[i + 90];
	}
	//cout<<"22nd for loop"<<endl;
	for (int i = 0; i<2; i++) {
		encrypt_u[i] = key_space[i + 97];
	}
	//cout<<"23rd for loop"<<endl;
	for (int i = 0; i<1; i++) {
		encrypt_v[i] = key_space[99];
	}
	//cout<<"24th for loop"<<endl;
	for (int i = 0; i<2; i++) {
		encrypt_w[i] = key_space[i + 100];
	}
	//cout<<"25th for loop"<<endl;
	for (int i = 0; i<1; i++) {
		encrypt_x[i] = key_space[i + 102];
	}
	//cout<<"26th for loop"<<endl;
	for (int i = 0; i<2; i++) {
		encrypt_y[i] = key_space[i + 103];
	}
	//cout<<"27th for loop"<<endl;
	for (int i = 0; i<1; i++) {
		encrypt_z[i] = key_space[i + 105];
	}

	cout << "For Plaintext:	" << plaintext << endl;
	cout << "Corresponding ciphertext is:	" << endl;
	for (int i = 0; i<plaintext.length(); i++) {
		//cout<<"plaintext["<<i<<"]:	"<<plaintext[i]<<endl;
		if (plaintext[i] == 'a') {
			ciphertext[i] = encrypt_a[i % ((sizeof(encrypt_a) / sizeof(*encrypt_a)))];
			cout << ciphertext[i] << ",";
		}
		if (plaintext[i] == 'b') {
			ciphertext[i] = encrypt_b[i % ((sizeof(encrypt_b) / sizeof(*encrypt_b)))];
			cout << ciphertext[i] << ",";
		}
		if (plaintext[i] == 'c') {
			ciphertext[i] = encrypt_c[i % ((sizeof(encrypt_c) / sizeof(*encrypt_c)))];
			cout << ciphertext[i] << ",";
		}
		if (plaintext[i] == 'd') {
			//cout<<"entered D"<<endl;
			ciphertext[i] = encrypt_d[i % ((sizeof(encrypt_d) / sizeof(*encrypt_d)))];
			cout << ciphertext[i] << ",";
		}
		if (plaintext[i] == 'e') {
			ciphertext[i] = encrypt_e[i % ((sizeof(encrypt_e) / sizeof(*encrypt_e)))];
			cout << ciphertext[i] << ",";
		}
		if (plaintext[i] == 'f') {
			ciphertext[i] = encrypt_f[i % ((sizeof(encrypt_f) / sizeof(*encrypt_f)))];
			cout << ciphertext[i] << ",";
		}
		if (plaintext[i] == 'g') {
			ciphertext[i] = encrypt_g[i % ((sizeof(encrypt_g) / sizeof(*encrypt_g)))];
			cout << ciphertext[i] << ",";
		}
		if (plaintext[i] == 'h') {
			ciphertext[i] = encrypt_h[i % ((sizeof(encrypt_h) / sizeof(*encrypt_h)))];
			cout << ciphertext[i] << ",";
		}
		if (plaintext[i] == 'i') {
			ciphertext[i] = encrypt_i[i % ((sizeof(encrypt_i) / sizeof(*encrypt_i)))];
			cout << ciphertext[i] << ",";
		}
		if (plaintext[i] == 'j') {
			ciphertext[i] = encrypt_j[i % ((sizeof(encrypt_j) / sizeof(*encrypt_j)))];
			cout << ciphertext[i] << ",";
		}
		if (plaintext[i] == 'k') {
			ciphertext[i] = encrypt_k[i % ((sizeof(encrypt_k) / sizeof(*encrypt_k)))];
			cout << ciphertext[i] << ",";
		}
		if (plaintext[i] == 'l') {
			ciphertext[i] = encrypt_l[i % ((sizeof(encrypt_l) / sizeof(*encrypt_l)))];
			cout << ciphertext[i] << ",";
		}
		if (plaintext[i] == 'm') {
			ciphertext[i] = encrypt_m[i % ((sizeof(encrypt_m) / sizeof(*encrypt_m)))];
			cout << ciphertext[i] << ",";
		}
		if (plaintext[i] == 'n') {
			ciphertext[i] = encrypt_n[i % ((sizeof(encrypt_n) / sizeof(*encrypt_n)))];
			cout << ciphertext[i] << ",";
		}
		if (plaintext[i] == 'o') {
			ciphertext[i] = encrypt_o[i % ((sizeof(encrypt_o) / sizeof(*encrypt_o)))];
			cout << ciphertext[i] << ",";
		}
		if (plaintext[i] == 'p') {
			ciphertext[i] = encrypt_p[i % ((sizeof(encrypt_p) / sizeof(*encrypt_p)))];
			cout << ciphertext[i] << ",";
		}
		if (plaintext[i] == 'q') {
			ciphertext[i] = encrypt_q[i % ((sizeof(encrypt_q) / sizeof(*encrypt_q)))];
			cout << ciphertext[i] << ",";
		}
		if (plaintext[i] == 'r') {
			ciphertext[i] = encrypt_r[i % ((sizeof(encrypt_r) / sizeof(*encrypt_r)))];
			cout << ciphertext[i] << ",";
		}
		if (plaintext[i] == 's') {
			ciphertext[i] = encrypt_s[i % ((sizeof(encrypt_s) / sizeof(*encrypt_s)))];
			cout << ciphertext[i] << ",";
		}
		if (plaintext[i] == 't') {
			ciphertext[i] = encrypt_t[i % ((sizeof(encrypt_t) / sizeof(*encrypt_t)))];
			cout << ciphertext[i] << ",";
		}
		if (plaintext[i] == ' ') {
			ciphertext[i] = encrypt_space[i % ((sizeof(encrypt_space) / sizeof(*encrypt_space)))];
			cout << ciphertext[i] << ",";
		}
		if (plaintext[i] == 'u') {
			ciphertext[i] = encrypt_u[i % ((sizeof(encrypt_u) / sizeof(*encrypt_u)))];
			cout << ciphertext[i] << ",";
		}
		if (plaintext[i] == 'v') {
			ciphertext[i] = encrypt_v[i % ((sizeof(encrypt_v) / sizeof(*encrypt_v)))];
			cout << ciphertext[i] << ",";
		}
		if (plaintext[i] == 'w') {
			ciphertext[i] = encrypt_w[i % ((sizeof(encrypt_w) / sizeof(*encrypt_w)))];
			cout << ciphertext[i] << ",";
		}
		if (plaintext[i] == 'x') {
			ciphertext[i] = encrypt_x[i % ((sizeof(encrypt_x) / sizeof(*encrypt_x)))];
			cout << ciphertext[i] << ",";
		}
		if (plaintext[i] == 'y') {
			ciphertext[i] = encrypt_y[i % ((sizeof(encrypt_y) / sizeof(*encrypt_y)))];
			cout << ciphertext[i] << ",";
		}
		if (plaintext[i] == 'z') {
			ciphertext[i] = encrypt_z[i % ((sizeof(encrypt_z) / sizeof(*encrypt_z)))];
			cout << ciphertext[i] << ",";
		}
	}
	cout << endl;
}

/* <========================================= DECRYPTION =========================================> */

// Function for reading plaintext file and writing char info to vectors of vectors
// vec[x] contain the characters for each candidate text (space, a-z)
// vec[x][y] contain the info of chars for each candidate text (occurrences, positions)
// vec[char_num+27j] to access the characters of candidate text j (from j = 0)
// vec[char_num+27j][0] = # of occurrences of the character in candidate text j
// vec[char_num+27j][n] = positions of occurrences where 0 < n < vec[].size()
//
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


int main() {

	/* <========== Encryption ==========> */
	string plain_text[5] = { "dipped ligatured cannier cohabitation cuddling coiffeuses pursuance roper eternizes nullo framable paddlings femur bebop demonstrational tuberculoid theocracy women reappraise oblongatae aphasias loftiness consumptive lip neurasthenically dutchmen grift discredited resourcefulness malfeasants swallowed jogger sayable lewder editorials demimondaine tzaritza arrogations wish indisputable reproduces hygrometries gamuts alight borderlines draggle reconsolidated anemometer rowels staggerers grands nu","rereads predestines equippers cavitation bimolecular lucubrations cabin bettas quiverer prussians cosigner dressier bended dethronement inveigled davenport establish ganges rebroadcast supered bastiles willable abetted motionlessness demonic flatter bunyan securely tippiest tongue aw cotyledonal roomettes underlies miffs inducement overintellectually fertilize spasmodic bacchanal birdbrains decoct snakebite galliard boson headmistress unextended provence weakling pirana fiend lairds argils comma",	"trawling responsiveness tastiest pulsed restamps telescoping pneuma lampoonist divas theosophists pustules checkrowed compactor conditionals envy hairball footslogs wasteful conjures deadfall stagnantly procure barked balmier bowery vagary beaten capitalized undersized towpath envisages thermoplastic rationalizers professions workbench underarm trudger icicled incisive oilbirds citrins chambrays ungainliness weazands prehardened dims determinants fishskin cleanable henceforward misarranges fine ",	"dean iller playbooks resource anesthetic credibilities nonplus tzetzes incursions stooged envelopments girdling risibility thrum repeaters catheterizing misbestowed cursing malingerers ensconces lippiest accost superannuate slush opinionated rememberer councils mishandling drivels juryless slashers tangent roistering scathing apprenticing fleabite sault achier quantize registrable nobbler sheaf natantly kashmirs dittoes scanned emissivity iodize dually refunded portliest setbacks eureka needines",	"mammate punners octette asylum nonclinically trotters slant collocation cardiology enchants ledge deregulated bottommost capsulate biotechnologies subtended cloddiest training joneses catafalque fieldmice hostels affect shrimper differentiations metacarpus amebas sweeter shiatsu oncoming tubeless menu professing apostatizing moreover eumorphic casked euphemistically programmability campaniles chickpea inactivates crossing defoggers reassures tableland doze reassembled striate precocious noncomba" };
	string ciphertext[5];
	for (int i = 0; i<5; i++) {
		encrypt(plain_text[i]);
	}

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
// cipher_num is the number between 0 to 105 which occurs 9 times in the ciphertext.
// plaintext is the output of the plain_cipher_cmp function which returns the number of the plaintext.
 
#include <iostream>
#include <string>
using namespace std;

int plain_cipher_cmp(int cipher_num[], string ciphertext, string plaintext[], int plaintext_num){
	// First find the location of the cipher_num in the ciphertext
	int i,j,k;
	
	for (k=0; k < sizeof(cipher_num)/sizeof(int); k++){
		for (j = 0; j<5;j++){
			int count = 0; // count keeps track of how many of the cipher_num character matches with plaintext.
			for (i=0 ; i<500 ; i++){
				if(ciphertext[i] == cipher_num[k]){
					if(plaintext[j][i] = 'b')
						count++;
				}
			}
			if (count == 9 && (j = 0 || 2 || 4)){
				plaintext_num = j;
				break;
			}
			else if (count == 16 && (j = 1)){
				plaintext_num = j;
				break;
			}
			else if (count == 10 && (j = 3)){
				plaintext_num = j;
				break;
			}
		}
	//cout<<"The corresponding plaintext is:	"<<plaintext[j]<<endl;
	}
	return plaintext_num;
}

int main(){
	const string plaintext[5] = {"dipped ligatured cannier cohabitation cuddling coiffeuses pursuance roper eternizes nullo framable paddlings femur bebop demonstrational tuberculoid theocracy women reappraise oblongatae aphasias loftiness consumptive lip neurasthenically dutchmen grift discredited resourcefulness malfeasants swallowed jogger sayable lewder editorials demimondaine tzaritza arrogations wish indisputable reproduces hygrometries gamuts alight borderlines draggle reconsolidated anemometer rowels staggerers grands nu","rereads predestines equippers cavitation bimolecular lucubrations cabin bettas quiverer prussians cosigner dressier bended dethronement inveigled davenport establish ganges rebroadcast supered bastiles willable abetted motionlessness demonic flatter bunyan securely tippiest tongue aw cotyledonal roomettes underlies miffs inducement overintellectually fertilize spasmodic bacchanal birdbrains decoct snakebite galliard boson headmistress unextended provence weakling pirana fiend lairds argils comma",	"trawling responsiveness tastiest pulsed restamps telescoping pneuma lampoonist divas theosophists pustules checkrowed compactor conditionals envy hairball footslogs wasteful conjures deadfall stagnantly procure barked balmier bowery vagary beaten capitalized undersized towpath envisages thermoplastic rationalizers professions workbench underarm trudger icicled incisive oilbirds citrins chambrays ungainliness weazands prehardened dims determinants fishskin cleanable henceforward misarranges fine ",	"dean iller playbooks resource anesthetic credibilities nonplus tzetzes incursions stooged envelopments girdling risibility thrum repeaters catheterizing misbestowed cursing malingerers ensconces lippiest accost superannuate slush opinionated rememberer councils mishandling drivels juryless slashers tangent roistering scathing apprenticing fleabite sault achier quantize registrable nobbler sheaf natantly kashmirs dittoes scanned emissivity iodize dually refunded portliest setbacks eureka needines",	"mammate punners octette asylum nonclinically trotters slant collocation cardiology enchants ledge deregulated bottommost capsulate biotechnologies subtended cloddiest training joneses catafalque fieldmice hostels affect shrimper differentiations metacarpus amebas sweeter shiatsu oncoming tubeless menu professing apostatizing moreover eumorphic casked euphemistically programmability campaniles chickpea inactivates crossing defoggers reassures tableland doze reassembled striate precocious noncomba"};
	string ciphertext = "";
	int plaintext_num;
	int cipher_num[1] = {104};
	//cout<<"6th character in plaintext 1 is:"<<plaintext[0][5]<<endl;
	plain_cipher_cmp(cipher_num, ciphertext, plaintext, plaintext_num);
	cout<<"My plaintext guess is:	"<<plaintext[plaintext_num]<<endl;
}
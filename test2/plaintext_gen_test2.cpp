#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <numeric>
#include <time.h>
using namespace std;
vector<string> gen_plaintext(string english_words[]){
	int l=0;
	vector<string> plaintext;
	srand(time(0));
	int words = 0;
	while(l<500){		
		int i = rand() % 20;
		plaintext.push_back(english_words[i]);
		words = words + 1;
		l = l + english_words[i].length() + 1;
	}
	cout<<"length of plaintext:	"<<l<<endl;
	return plaintext;
}
int main(){
	string cipher_input;
	vector<string> plaintext;
	int ciphertext_copy;
	string english_words[20] = {"stovepipes" , "sampling" , "swells", "nested", "nymphal", "gibbousness", "cottoned", "hope", "energize", "expatiations", "dextrins", "travested","jeopardous","finale","freelancing" , "brisking", "meaningless", "maturates" , "violators", "rankly"};
	std::istringstream ss(cipher_input);
	std::string ciphertext;
	vector<string> ciphertext_vc;
	while(std::getline(ss, ciphertext, ',')) {
		ciphertext_vc.push_back(ciphertext);
	}
	
	/* ============== Creating Plaintext from the english words ==================*/
	plaintext = gen_plaintext(english_words);
	for(int i = 0;i<plaintext.size();i++){
		cout<<plaintext[i]<<" ";	
	}
	return 0;
		
}
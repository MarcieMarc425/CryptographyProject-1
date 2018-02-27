// cipher_num is the number between 0 to 105 which occurs 9 times in the ciphertext.
// plaintext is the output of the plain_cipher_cmp function which returns the number of the plaintext.
 
#include <iostream>
#include <string>
using namespace std;

int plain_cipher_cmp(int cipher_num[], string ciphertext, string plaintext[], int plaintext_num){
	// First find the location of the cipher_num in the ciphertext
	int i,j,k;
	
	for (k=0;k<len(cipher_num;k++){
		for (j = 0; j<5;j++){
			int count = 0; // count keeps track of how many of the cipher_num character matches with plaintext.
			for (i=0 ; i<500 ; i++){
				if(ciphertext[i] == cipher_num[k]){
					if(plaintext[j][i] = "b")
						count++;
				}
			}
			if (count == 9 && (j = 0 || 2 || 4)){
				plaintext_num = j;
				break;
			}
			else if (count == 16 && (j = 1)){
				plaintext_num = j
				break;
			}
			else if (count == 10 && (j = 3)){
				plaintext_num = j
				break;
			}
		}
	//cout<<"The corresponding plaintext is:	"<<plaintext[j]<<endl;
	}
	return plaintext_num;
}

int main(){
	const string plaintext[5];
	plaintext[0] = "";
	plaintext[1] = "";
	plaintext[2] = "";
	plaintext[3] = "";
	plaintext[4] = "";

	string ciphertext = "";
	int plaintext_num;
	int cipher_num[] = 104;
	plain_cipher_cmp(cipher_num, ciphertext, plaintext, plaintext_num);
	cout<<"My plaintext guess is:	"<<plaintext[plaintext_num]<<endl;
}
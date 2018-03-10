#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <numeric>
#include <time.h>
using namespace std;

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
	string temp_val[60];
	string temp_char[60];
	vector<string> ciphertext;
	ciphertext = ciphertext_vc_copy;
	string characters[] = {" ","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
	bool flag = false;
	for (int i = 4; i < ciphertext_vc_copy.size();i++){
		if(ciphertext_vc_copy[i] == ciphertext_vc_copy[i-1]){
			flag = true;
			//cout<<"Entered IF"<<endl;
			/*
			temp_val[50] = ciphertext[i-4];
			temp_char[50] = " ";
			ciphertext[i-4] = ' ';
			*/
			temp_val[0] = ciphertext[i];
			temp_char[0] = "b";					
			ciphertext[i] = 'b';
			
			temp_val[1] = ciphertext[i-3];
			temp_char[1] = "g";
			ciphertext[i-3] = 'g';
			
			//string& str = ciphertext[i];
			//string& str = ciphertext[i-3];
			//find_and_replace(str, ciphertext[i-3], "g");
			
			temp_val[2] = ciphertext[i-2];
			temp_char[2] = "i";
			ciphertext[i-2] = 'i';
			
			//string& str1 = ciphertext[i-2];
			//find_and_replace(str, ciphertext[i-2], "i");
			
			temp_val[3] = ciphertext[i-1];
			temp_char[3] = "b";
			ciphertext[i-1] = 'b';
			
			//string& str2 = ciphertext[i-1];
			//find_and_replace(str, ciphertext[i-1], "b");
			
			temp_val[4] = ciphertext[i+1];
			temp_char[4] = "o";
			ciphertext[i+1] = 'o';
			
			//string& str3 = ciphertext[i+1];
			//find_and_replace(str, ciphertext[i+1], "o");
			
			temp_val[5] = ciphertext[i+2];
			temp_char[5] = "u";
			ciphertext[i+2] = 'u';
			
			//string& str4 = ciphertext[i+2];
			//find_and_replace(str, ciphertext[i+2], "u");
			
			temp_val[6] = ciphertext[i+3];
			temp_char[6] = "s";
			ciphertext[i+3] = 's';
			
			//string& str5 = ciphertext[i+3];
			//find_and_replace(str, ciphertext[i+3], "s");
			
			temp_val[7] = ciphertext[i+4];
			temp_char[7] = "n";
			ciphertext[i+4] = 'n';
			
			//string& str6 = ciphertext[i+4];
			//find_and_replace(str, ciphertext[i+4], "n");
			
			temp_val[8] = ciphertext[i+5];
			temp_char[8] = "e";
			ciphertext[i+5] = 'e';
			
			//string& str7 = ciphertext[i+5];
			//find_and_replace(str, ciphertext[i+5], "e");
			
			temp_val[9] = ciphertext[i+6];
			temp_char[9] = "s";
			ciphertext[i+6] = 's';
			
			//string& str8 = ciphertext[i+6];
			//find_and_replace(str, ciphertext[i+6], "s");
			
			temp_val[10] = ciphertext[i+7];
			temp_char[10] = "s";
			ciphertext[i+7] = 's';
			
			//string& str9 = ciphertext[i+7];
			//find_and_replace(str, ciphertext[i+7], "s");
			if(i != ciphertext_vc_copy.size()-8){
				temp_val[11] = ciphertext[i+8];
				temp_char[11] = " ";
				ciphertext[i+8] = ' ';
				//string& str10 = ciphertext[i+8];
				//find_and_replace(str, ciphertext[i+8], " ");
			}
		}

	}
	cout<<"After 1st for loop"<<endl;
	for (int i = 2; i < ciphertext_vc_copy.size()-1;i++){
		if ((ciphertext_vc_copy[i] != ciphertext_vc_copy[i-1])&&(ciphertext_vc_copy[i] != ciphertext_vc_copy[i+1])&&(ciphertext_vc_copy[i-2] != ciphertext_vc_copy[i-1])){
			if((ciphertext_vc_copy[i-1] == temp_val[0])){
				ciphertext[i-1] = 'b';
				/*	
				temp_val[50] = ciphertext[i-2];
				temp_char[50] = " ";
				ciphertext[i-2] = ' ';
				*/
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
	cout<<"After 2nd for loop"<<endl;
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
	cout<<"After 3rd for loop"<<endl;
	if(ciphertext_vc_copy[3] == temp_val[15]){
		cout<<"entered IF"<<endl;
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
	cout<<"After 4th for loop"<<endl;
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
	cout<<"After 5th for loop"<<endl;
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
	cout<<"After 6th for loop"<<endl;
	/*
	for (int i = 4; i < ciphertext_vc_copy.size()-3;i++){
		if((ciphertext_vc_copy[i] == temp_val[44])){ //h
			if((ciphertext_vc_copy[i-3] != temp_val[24])||(ciphertext_vc_copy[i-3] != temp_val[30])){
				cout<<temp_val[24]<<"\t"<<temp_val[30]<<endl;
				cout<<"entered if"<<endl;
				temp_val[50] = ciphertext[i+1]; ///nymphal rankly hope nymphope ankly
				temp_char[50] = "o";
				ciphertext[i+1] = 'o';
				
				temp_val[51] = ciphertext[i+2];
				temp_char[51] = "p";
				ciphertext[i+2] = 'p';
				
				temp_val[52] = ciphertext[i+3];
				temp_char[52] = "e";
				ciphertext[i+3] = 'e';
				
				if(i != ciphertext_vc_copy.size()-4){
					temp_val[53] = ciphertext[i+4];
					temp_char[53] = " ";
					ciphertext[i+4] = ' ';
					
				}
			}
		}
	}
	*/
	
	// trying something here
	/*
	for (int i=0; i<ciphertext_vc_copy.size();i++){
		for (int j = 0; j<27;j++){
			if(ciphertext[i] == characters[j]){
				//write code here;
			}
		}
	}
	*/
		
	cout<<"After 7th for loop"<<endl;
	for(int i = 0; i < ciphertext_vc_copy.size();i++){
		if(flag == true){
			for (int j = 0; j<54; j++){
				find_and_replace(ciphertext[i], temp_val[j], temp_char[j]);
			}
		}
	}
	cout<<"After 8th for loop"<<endl;
	
	for (int i=0; i<ciphertext_vc_copy.size();i++){
		if(ciphertext[i] == characters[0]){
			if(ciphertext[i+1] == characters[8]){
				ciphertext[i+2] = 'o';
				ciphertext[i+3] = 'p';
				ciphertext[i+4] = 'e';
				ciphertext[i+5] = ' ';
			}
			if(ciphertext[i+1] == characters[14]){
				if(ciphertext[i+2] != characters[25]){
					ciphertext[i+2] = 'e';
					ciphertext[i+3] = 's';
					ciphertext[i+4] = 't';
					ciphertext[i+5] = 'e';
					ciphertext[i+6] = 'd';
					ciphertext[i+7] = ' ';
				}
			}
			if(ciphertext[i+1] == characters[5]){
				if((ciphertext[i+2] == characters[14])||(ciphertext[i+3] == characters[4])||(ciphertext[i+4] == characters[18])||(ciphertext[i+5] == characters[7])||(ciphertext[i+6] == characters[9])||(ciphertext[i+7] == characters[26])||(ciphertext[i+8] == characters[5])){
					ciphertext[i+2] = 'n';
					ciphertext[i+3] = 'e';
					ciphertext[i+4] = 'r';
					ciphertext[i+5] = 'g';
					ciphertext[i+6] = 'i';
					ciphertext[i+7] = 'z';
					ciphertext[i+8] = 'e';
					ciphertext[i+9] = ' ';				
				}
				else {
					ciphertext[i+2] = 'x';
					ciphertext[i+3] = 'p';
					ciphertext[i+4] = 'a';
					ciphertext[i+5] = 't';
					ciphertext[i+6] = 'i';
					ciphertext[i+7] = 'a';
					ciphertext[i+8] = 't';
					ciphertext[i+9] = 'i';
					ciphertext[i+10] = 'o';
					ciphertext[i+11] = 'n';
					ciphertext[i+12] = 's';
					ciphertext[i+13] = ' ';					
				}
			}	
			if(ciphertext[i+1] == characters[13]){
				cout<<"entered if"<<endl;
				if((ciphertext[i+2] == characters[5])||(ciphertext[i+3] == characters[1])||(ciphertext[i+4] == characters[14])||(ciphertext[i+5] == characters[9])||(ciphertext[i+6] == characters[14])||(ciphertext[i+7] == characters[7])||(ciphertext[i+8] == characters[12])||(ciphertext[i+9] == characters[5])||(ciphertext[i+10] == characters[19])||(ciphertext[i+11] == characters[19])){
					ciphertext[i+2] = 'e';
					ciphertext[i+3] = 'a';
					ciphertext[i+4] = 'n';
					ciphertext[i+5] = 'i';
					ciphertext[i+6] = 'n';
					ciphertext[i+7] = 'g';
					ciphertext[i+8] = 'l';
					ciphertext[i+9] = 'e';
					ciphertext[i+10] = 's';
					ciphertext[i+11] = 's';
					ciphertext[i+12] = ' ';
				}
				else{
					ciphertext[i+2] = 'a';
					ciphertext[i+3] = 't';
					ciphertext[i+4] = 'u';
					ciphertext[i+5] = 'r';
					ciphertext[i+6] = 'a';
					ciphertext[i+7] = 't';
					ciphertext[i+8] = 'e';
					ciphertext[i+9] = 's';
					ciphertext[i+10] = ' ';
				}
			}
			
			if(ciphertext[i+1] == characters[19]){
				if((ciphertext[i+2] == characters[20])||(ciphertext[i+3] == characters[15])||(ciphertext[i+4] == characters[22])||(ciphertext[i+5] == characters[5])||(ciphertext[i+6] == characters[16])||(ciphertext[i+7] == characters[9])||(ciphertext[i+8] == characters[16])||(ciphertext[i+9] == characters[5])||(ciphertext[i+10] == characters[19])){
					ciphertext[i+2] = 't';
					ciphertext[i+3] = 'o';
					ciphertext[i+4] = 'v';
					ciphertext[i+5] = 'e';
					ciphertext[i+6] = 'p';
					ciphertext[i+7] = 'i';
					ciphertext[i+8] = 'p';
					ciphertext[i+9] = 'e';
					ciphertext[i+10] = 's';
					ciphertext[i+11] = ' ';
				}
				else if((ciphertext[i+2] == characters[1])||(ciphertext[i+3] == characters[13])||(ciphertext[i+4] == characters[16])||(ciphertext[i+5] == characters[12])||(ciphertext[i+6] == characters[9])||(ciphertext[i+7] == characters[14])||(ciphertext[i+8] == characters[7])){
					ciphertext[i+2] = 'a';
					ciphertext[i+3] = 'm';
					ciphertext[i+4] = 'p';
					ciphertext[i+5] = 'l';
					ciphertext[i+6] = 'i';
					ciphertext[i+7] = 'n';
					ciphertext[i+8] = 'g';
					ciphertext[i+9] = ' ';
				}
				else if((ciphertext[i+2] == characters[23])||(ciphertext[i+3] == characters[5])||(ciphertext[i+4] == characters[12])||(ciphertext[i+5] == characters[12])||(ciphertext[i+6] == characters[19])){
					ciphertext[i+2] = 'w';
					ciphertext[i+3] = 'e';
					ciphertext[i+4] = 'l';
					ciphertext[i+5] = 'l';
					ciphertext[i+6] = 's';
					ciphertext[i+7] = ' ';
				}
			}
		}
	}
	return ciphertext;
}

int main(){
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
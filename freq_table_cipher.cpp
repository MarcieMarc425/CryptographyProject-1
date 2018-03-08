//
//  freq_table_cipher.cpp

/*
 Cryptography Project 1 Ciphertext Frequency Analysis
 */

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Function for reading ciphertext file and writing number info to vector of ints
// vec[x] contain the numbers for each cipher text (0-105)
// vec[x][0] contain the occurrences of numbers for each cipher text
// vec[char_num+106j] to access the characters of cipher text j (from j = 0)
// vec[char_num+106j][0] = # of occurrences of the character in cipher text j
//
void readCiphertext(const ifstream& ifs, vector<int>& vec, vector<int>& highs) {
    string cipherline;
    
    int count;
    int i = 0;
    int j = 0;
    while (ifs) {
        if (i > 0 && (i+5) % 9 == 0) {
            for (int k = 0; k < 4; k++) {
                getline(ifs, cipherline);
                vector<int> cont;
                size_t current, previous = 0;
                current = cipherline.find(', ');
                while (current != string::npos) {
                    cont.push_back(cipherline.substr(previous, current - previous));
                    previous = current + 1;
                    current = cipherline.find(', ', previous);
                }
                cont.push_back(cipherline.substr(previous, current - previous));
                for (size_t pos = 0; pos < cont.length(); pos++) {
                    if (vec[cont[pos] + 106*j].empty())
                        vec[cont[pos] + 106*j].push_back(0);
                    vec[cont[pos] + 106*j][0]++;
                    count = vec[cont[pos] + 106*j][0];
                    if (count == 9 || count == 10 || count == 16) {
                        if (find(highs.begin(), highs.end(), cont[pos] + 106*j) == highs.end())
                            highs.push_back(cont[pos] + 106*j);
                    }
                }
            }
            j++;
            i += 4;
        }
        i++;
    }
    return;
}

int main() {
    
    // Read ciphertext and write frequency table to vector cipher_text
    ifstream ifs("SampleTexts.txt");
    if (!ifs) {
        cerr << "Could not open file. \n";
        exit(1);
    }
    vector<int> cipher_texts(530);
    vector<int> special_nums(530);
    readCiphertext(ifs, cipher_texts, special_nums);
    
    // TEST CASE: Find occurrences of '61' in all cipher texts
    for (int i = 0; i < 5; i++) {
        cout << "Cipher Text " << i + 1 << " for '61':" << endl;
        cout << "\tOccurrences: " << cipher_texts[61 + 106 * i][0] << endl;
        cout << endl;
    }
    return 0;
}

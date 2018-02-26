/*
	Cryptography Project 1 Test 1 Solution
	Date Due: March 10
	Authors: Dayan Siddiqui, Nimisha Limaye, Marc Tse, Michael Zhou
*/

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Function for reading plaintext file and writing char info to vectors of vectors
// vec[x] contain the characters for each candidate text (space, a-z)
// vec[x][y] contain the info of chars for each candidate text (occurrences, positions)
// vec[char_num+27j] to access the characters of candidate text j (from j = 0)
// vec[char_num+27j][0] = # of occurrences of the character in candidate text j
// vec[char_num+27j][n] = positions of occurrences where 0 < n < vec[].size()
//
void readPlaintext(const ifstream& ifs, vector<vector<int>>& vec) {
	string candidate;
	int i = 0;
	int j = 0;
	while (getline(ifs, candidate)) {
		if (i > 1 && i % 4 == 0) {
			for (size_t pos = 0; pos < candidate.length(); pos++) {
				if (candidate[pos] != 32) {
					if (vec[(candidate[pos] - 96) + 27 * j].empty())
						vec[(candidate[pos] - 96) + 27 * j].push_back(0);
					vec[(candidate[pos] - 96) + 27 * j][0]++;
					vec[(candidate[pos] - 96) + 27 * j].push_back(pos);
				}
				else {
					if (vec[0 + 27 * j].empty())
						vec[0 + 27 * j].push_back(0);
					vec[0][0]++;
					vec[0].push_back(pos);
				}
			}
			j++;
		}
		i++;
	}
	return;
}

int main() {

	// Read plaintext and write frequency table to vector candidate_text
	ifstream ifs("test1_candidate_5_plaintexts.txt");
	if (!ifs) {
		cerr << "Could not open file. \n";
		exit(1);
	}
	vector<vector<int>> candidate_text(135);
	readPlaintext(ifs, candidate_text);

	// TEST CASE: Find occurrences and positions of 'b' in all candidate texts
	for (int i = 0; i < 5; i++) {
		cout << "Candidate Text " << i + 1 << " for 'b':" << endl;
		cout << "\tOccurrences: " << candidate_text[2 + 27 * i][0] << endl;
		cout << "\tPositions: ";
		for (size_t j = 1; j < candidate_text[2 + 27 * i].size(); j++) {
			cout << candidate_text[2 + 27 * i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

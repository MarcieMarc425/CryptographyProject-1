#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{

	ifstream ifs("test1_candidate_5_plaintexts.txt");

	if (!ifs) {
		cerr << "Could not open file. \n";
		exit(1);
	}

	string line;
	vector<string> candidate_text;

	int i = 0;
	while (getline(ifs, line)) {
		if (i > 1 && i % 4 == 0)
			candidate_text.push_back(line);
		i++;
	}

	for (size_t i = 0; i < candidate_text.size(); i++) {
		cout << candidate_text[i] << endl;
	}

	return 0;
}
#define CTR_SECURE_NO_WARINGS
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	ifstream source("source.txt"); 
	ofstream result("result.txt");
	string words;
	if (!source.is_open()) {
		cerr << "Could not open input file!"; 
		return 1;
	}
	else
	{
		if (!result.is_open()) {
			cerr << "Could not create output file!";
			return 1;
		}
		else
		{
			while (getline(source, words)) {
				char * word = strtok((char*)words.c_str(), ":;!?&,.-"); 
				while (word != NULL)
				{
					if (strlen(word) >= 7) {
						result << word << "";
					}
					word = strtok(NULL, ":;!?&,.-");
				}
			}
			result.close();
		}
		source.close();
	}
	return 0;
}
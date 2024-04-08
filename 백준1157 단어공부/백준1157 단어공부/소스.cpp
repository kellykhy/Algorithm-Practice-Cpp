#include <iostream>
#include <string.h>
using namespace std;

string word;
int cnt[200];
string max_letter;
int max_;

int main() {
	cin >> word;
	for (int i = 0; i < word.length(); i++) {
		int upper_case = word[i];
		if (word[i] >= 'a')
			upper_case = 'A' + word[i] - 'a';

		cnt[upper_case] ++;
		if (max_ < cnt[upper_case]) {
			max_letter = upper_case;
			max_ = cnt[upper_case];
		}
	}

	int tie = 0;
	for (int i = 'A'; i < 'Z'+1 ; i++) {
		if (cnt[i] == max_) {
			tie++;
		}
	}
	if (tie > 1)
		cout << "?";
	else
		cout << max_letter;
}
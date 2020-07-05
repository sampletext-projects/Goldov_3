#include <iostream>
#include <string>

using namespace std;

void swap_letters(string& word)
{
	swap(word[word.length() - 1], word[0]);
}

string* split(string& line, int& n)
{
	string* words = new string[line.length()];
	int index = 0;
	int start = 0;
	while (start < line.length())
	{
		int next_space = line.find(' ', start);
		if (next_space == -1)
		{
			next_space = line.length();
		}

		string word = line.substr(start, next_space - start);
		words[index] = word;
		index++;
		start = next_space + 1;
	}
	n = index;
	return words;
}

int main()
{
	setlocale(LC_ALL, "russian");

	string line;

	getline(cin, line);

	int n;
	string* words = split(line, n);

	string last = words[n - 1];

	swap_letters(last);

	for (int i = 0; i < n; i++)
	{
		swap_letters(words[i]);
	}

	for (int i = 0; i < n; i++)
	{
		if (words[i] != last)
		{
			cout << words[i] << "\n";
		}
	}

	delete[] words;

	system("pause");
}

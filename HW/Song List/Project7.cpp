#include "Song.h"

int main()
{
	int index;
	string a;
	string b;
	string c;
	int d;
	int e;

	cout << "How many songs will you list? " << endl;
	cin >> index;
	
	Song s[index];

	for (int i = 0; i < index; i++)
{
	cout << "Enter data for Song #" << i + 1  << endl;
	cout << "Song name: ";
	cin >> a;
	cout << "Artist name: ";
	cin >> b;
	cout << "Song genre: ";
	cin >> c;
	cout << "Year song was written: ";
	cin >> d;
	cout << "Runtime (in seconds): ";
	cin >> e;

	s[i].set(a, b, c, d, e);
}

	for (int j = 0; j < index; j++)
{
	cout << "Song #" << j + 1 << " information:" << endl;
	s[j].print();
}

return 0;
}

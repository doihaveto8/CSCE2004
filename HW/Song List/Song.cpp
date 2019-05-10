#include "Song.h"

Song::Song()
{
	name = "";
	artist = "";
	genre = "";
	year = 0;
	seconds = 0;
}

void Song::set(string n, string a, string g, int y, int s)
{
	name = n;
	artist = a;
	genre = g;
	year = y;
	seconds = s;
}

void Song::get(string &n, string &a, string &g, int &y, int &s)
{
	n = name;
	a = artist;
	g = genre;
	y = year;
	s = seconds;
}

void Song::print()
{
	int min;
	int sec;
	int zero = 0;
	min = seconds / 60;
	sec = seconds - (min * 60);
	
	cout << "Name: " << name << endl;
	cout << "artist: " << artist << endl;
	cout << "genre: " << genre << endl;
	cout << "year: " << year << endl;

	if (sec <= 9) cout << "runtime: " << min << ":" << zero << sec << endl;
	else cout << "runtime: " << min << ":" << sec << endl;

	cout << " " << endl;
}

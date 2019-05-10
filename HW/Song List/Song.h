#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

class Song
{
public:
	Song();
	void set(string n, string a, string g, int y, int s);
	void get(string &n, string &a, string &g, int &y, int &s);
	void print();
private:
	string name;
	string artist;
	string genre;
	int year;
	int seconds;
};

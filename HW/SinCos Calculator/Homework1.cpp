#include <cmath>
#include <iostream>
using namespace std;

int main()
{
//Declaring our integers

float x = 0;
float xsquared = 0;
float xcubed = 0;
float xtofour = 0;
float xtofive = 0;
int twofact = 2;
int threefact = 6;
int fourfact = 24;
int fivefact = 120;
float estsinx = 0;
float truesinx = 0;
float errsinx = 0;
float estcosx = 0;
float truecosx = 0;
float errcosx = 0;

//Enter a value for x

cout << "Enter a value for x ";
cin >> x;

//This is where the math happens

xsquared = x*x;
xcubed = xsquared*x;
xtofour = xcubed*x;
xtofive = xtofour*x;
estsinx = (x - (xcubed / threefact) + (xtofive / fivefact));
truesinx = sin(x);
errsinx = estsinx - truesinx;
estcosx = (1 - (xsquared / twofact) + (xtofour / fourfact));
truecosx = cos(x);
errcosx = estcosx - truecosx;

//Declare values

cout << "Sin(x) is estimated to be " << estsinx << endl;
cout << "Sin(x) is calculated to be " << truesinx << endl;
cout << "This produces an error of " << errsinx << endl;
cout << "Cos(x) is estimated to be " << estcosx << endl;
cout << "Cos(x) is calculated to be " << truecosx << endl;
cout << "This produces an error of " << errcosx << endl;

return 0;
}

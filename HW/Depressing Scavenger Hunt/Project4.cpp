//------------------------------------------------------------
// Purpose: Program to implement a UofA scavenger hunt game.
//          Locations on campus are described by separate functions.
//          The user finds "UofA items" and gains "karma points" 
//          as they move from location to location on campus.  
//
// Author:  Caleb Board
// Date:    Fall 2017
//------------------------------------------------------------

#include <cstdlib>
#include <iostream>
using namespace std;

// Functions for actions
int FindItem(const string item_name, int max_value);
void GainKarma(const string activity, int max_karma, int & karma_gained);
char GetDirection();

// Functions for locations
void Start(int &items, int &karma); 
void End(int &items, int &karma); 
void Location1(int &items, int &karma); 
void Location2(int &items, int &karma); 
void Location3(int &items, int &karma); 
void Location4(int &items, int &karma); 
void Location5(int &items, int &karma);
void Location6(int &items, int &karma);
void Location7(int &items, int &karma);
void Location8(int &items, int &karma);

//------------------------------------------------------------
// Purpose: To give user choice in picking up item.
// Input:   Item name (string).
//          Maximum value of item (int -100..100).
// Output:  Actual value of item picked up (int -100..100).
//------------------------------------------------------------
int FindItem(const string item_name, int max_value)
{
   // Range checking of parameters
   if (max_value < -100) max_value = -100;
   if (max_value >  100) max_value =  100;

   // Print first message
   if (random() % 2 == 0)
      cout << "\nYou see \n" << item_name << endl;
   else
      cout << "\nWhile in the trash you find \n" << item_name << endl;

   // Print second message
   cout << "Do you want to pick this item up? (yes/no)" << endl; 
   string answer;
   cin >> answer;

   // Handle yes answer
   int value = 0;
   if (answer == "yes")
   {
      float fraction = (1.0 + random() % 100) / 100.0;
      value = fraction * max_value;
      if (value > 0)
         cout << "Great, you just earned " << value << " points for that item" << endl;
      else
         cout << "This thing is so awful you gained " << value << " points getting it" << endl;
   } 

   // Handle no answer
   else if (answer == "no")
   { 
      if (max_value > 0)
         cout << "Too bad, this would have added to your scavenger hunt score" << endl;
      else      
         cout << "Good thing you didn't get it, it smells like a dead fish" << endl;
   }

   // Handle wrong answer
   else 
   { 
      cout << "A simple 'yes' or 'no' would be nice..." << endl;
      cout << "Better luck next time you see an item" << endl;
   }
   return value;
}

//------------------------------------------------------------
// Purpose: To give user choice in performing activity.
// Input:   Activity description (string).
//          Maximum karma points possible (int 1..100).
// Output:  Actual karma points gained (int 1..100).
//------------------------------------------------------------
void GainKarma(const string activity, int max_karma, int & karma_gained)
{
   // Range checking of parameters
   if (max_karma < 1)  max_karma = 1;
   if (max_karma > 100) max_karma = 100;

   // Print first message
   if (random() % 2 == 0)
      cout << "\nNot much is happening until you notice\n" << activity << endl;
   else
      cout << "\nWhile you are standing around you see\n" << activity << endl;

   // Print second message
   cout << "What do you want to do? (help/ignore)" << endl; 
   string answer;
   cin >> answer;

   // Handle help answer
   if (answer == "help")
   {
      karma_gained = 1 + random() % max_karma;
      cout << "(slow clap)" << endl;
      cout << "Conglaturation, you gained " << karma_gained << " karma points" << endl;
   } 

   // Handle other answers
   else 
   { 
      karma_gained = -(1 + random() % max_karma);
      if (random() % 2 == 0)
         cout << "Huh, how about that...?" << endl;
      else
         cout << "Boo..." << endl;
      cout << "You lose " << karma_gained << " karma points" << endl;
   }
}

//------------------------------------------------------------
// Purpose: To get direction from user
// Input:   None
// Output:  Character code for N,S,E,W direction
//------------------------------------------------------------
char GetDirection()
{
   cout << "\nWhat direction would you like to go (N,S,E,W): ";
   char direction;
   cin >> direction;
   direction = toupper(direction);
   while ((direction != 'N') && (direction != 'S') &&
          (direction != 'E') && (direction != 'W'))
   {
      cout << "No\n";
      cout << "What direction would you like to go (N,S,E,W): ";
      cin >> direction;
      direction = toupper(direction);
   }
   return direction;
}

//------------------------------------------------------------
// Purpose: The starting location for the game
// Input:   The items and karma variables 
// Output:  None
//------------------------------------------------------------
void Start(int &items, int &karma)
{
   cout << "\n------------------------------------------------------------\n";
   cout << "\nWelcome to the depressing scavenger hunt, go find some\n";
   cout << "stuff otherwise you suck.\n";

char choice = GetDirection();
switch (choice)
{
   case 'N':
       Location1(items, karma);
       break;
   case 'S':
       Location3(items, karma);
       break;
   case 'E':
       Location6(items, karma);
       break;
   case 'W':
       Location7(items, karma);
       break;
   default:
       break;
}
}
//------------------------------------------------------------
// Purpose: The ending location for the game
// Input:   The items and karma variables 
// Output:  None
//------------------------------------------------------------
void End(int &items, int &karma)
{
   cout << "\n------------------------------------------------------------\n";
   cout << "\nYou done?\n";
   cout << "My verdict is...\n";

   
   // Give prizes
   if (items <= 0) 
   {
      cout << "\nYou suck at this.\n";
      cout << "Now go do something else.\n";
   }
   else if (karma <= 0)
   {
      cout << "\nYou suck in general.\n";
      cout << "Now go do something else.\n";
   }
   else if ((items > 100) && (karma > 100))
   {
      cout << "\nYou are awesome. Yay. Your reward is happiness.\n";
      cout << "Now go do something else.\n";
   }
   else if ((items > 10) && (karma > 10))
   {
      cout << "\nMeh...\n";
      cout << "Now go do something else.\n";
   }
   else 
   {
      cout << "\nYou kinda suck.\n";
      cout << "Now go do something else.\n";
   }

   // Leave program
   exit(0);
}

//------------------------------------------------------------
// Purpose: To visit a location on campus
// Input:   The items and karma variables 
// Output:  None
//------------------------------------------------------------
void Location1(int &items, int &karma) 
{
   cout << "\n------------------------------------------------------------\n";
   cout << "\nYou have entered the main hallway of Bell Engineering.\n";

   // ADD CODE HERE
   char choice;
   string activity = " a child who spilled their ice cream ";
   int karmaworth = 0;
   string item = " your lost sense of individuality ";
   int value = 0;
   
   GainKarma(activity, 50, karmaworth);
   karma = karma + karmaworth;
   items = items + FindItem(item, 35);
    

   cout << "\nItems: " << items << " Karma: " << karma << endl;
   choice = GetDirection();
   while (choice == 'N')
{
   cout << "No." << endl;
   choice = GetDirection();
}
   switch (choice)
{
   case 'S':
   Location3(items, karma);
   break;
   case 'E':
   Location5(items, karma);
   break;
   case 'W':
   Location4(items, karma);
   default:
   break;
}
}

//------------------------------------------------------------
// Purpose: To visit a location on campus
// Input:   The items and karma variables 
// Output:  None
//------------------------------------------------------------
void Location2(int &items, int &karma)
{
   cout << "\n------------------------------------------------------------\n";
   cout << "\nYou have entered the second floor lobby of JB Hunt building.\n";

   // ADD CODE HERE
   char choice;
   string activity = " the Emoji Movie being played for children ";
   int karmaworth = 0;
   string item = " your childhood innocence ";
   int value = 0;
   
   GainKarma(activity, 25, karmaworth);
   karma = karma + karmaworth;
   items = items + FindItem(item, 15);

   cout << "\nItems: " << items << " Karma: " << karma << endl;
   choice = GetDirection();
   while ((choice != 'S') && (choice != 'E'))
{
   cout << "No." << endl;
   choice = GetDirection();
}
   switch (choice)
{
   case 'S':
       Location4(items, karma);
       break;
   case 'E':
       Location8(items, karma);
       break;
   default:
       break;
}
   
}

//------------------------------------------------------------
// Purpose: To visit a location on campus
// Input:   The items and karma variables 
// Output:  None
//------------------------------------------------------------
void Location3(int &items, int &karma) 
{
   cout << "\n------------------------------------------------------------\n";
   cout << "\nYou are now on the stage of the Greek Theatre.\n";

   // ADD CODE HERE
   char choice;
   string activity = " endless death ";
   int karmaworth = 0;
   
   GainKarma(activity, 50, karmaworth);
   karma = karma + karmaworth;
   cout << "\nItems: " << items << " Karma: " << karma << endl;
   
   choice = GetDirection();
   while (choice != 'N')
{
   cout << "No." << endl;
   choice = GetDirection();
}
   Location1(items, karma);
}

//------------------------------------------------------------
// Purpose: To visit a location on campus
// Input:   The items and karma variables 
// Output:  None
//------------------------------------------------------------
void Location4(int &items, int &karma) 
{
   cout << "\n------------------------------------------------------------\n";
   cout << "\nYou are in front of the Harman garage.\n";

   // ADD CODE HERE
   char choice;
   string activity = " people trying to end Tobey Maguire's existence ";
   int karmaworth = 0;
   
   GainKarma(activity, 50, karmaworth);
   karma = karma + karmaworth;
   cout << "\nItems: " << items << " Karma: " << karma << endl;
   choice = GetDirection();
   while (choice == 'W')
{
   cout << "No." << endl;
   choice = GetDirection();
}
   switch (choice)
{
   case 'N':
   Location2(items, karma);
   break;
   case 'S':
   Location6(items, karma);
   break;
   case 'E':
   Location1(items, karma);
   default:
   break;
}
}

void Location5(int &items, int &karma)
{
   cout << "\n------------------------------------------------------------\n";
   cout << "\nYou are in that one theatre place in the Union.\n";

  // ADD CODE HERE
   char choice;
   string activity = " college students suffering from senioritis ";
   int karmaworth = 0;
   
   GainKarma(activity, 50, karmaworth);
   karma = karma + karmaworth;
   cout << "\nItems: " << items << " Karma: " << karma << endl;
   choice = GetDirection();
   while (choice != 'W')
{
   cout << "No." << endl;
   choice = GetDirection();
}
   Location1(items, karma);
}

void Location6(int &items, int &karma)
{
   cout << "\n------------------------------------------------------------\n";
   cout << "\nYou are at Slim Chickens.\n";

  // ADD CODE HERE
   char choice;
   string item = " a means of resurrecting the dead ";
   int value = 0;
   
   items = items + FindItem(item, 45);

   cout << "\nItems: " << items << " Karma: " << karma << endl;
   choice = GetDirection();

   while ((choice != 'N') && (choice != 'E'))
{
   cout << "No." << endl;
   choice = GetDirection();
}
   switch (choice)
{
   case 'N':
   Location4(items, karma);
   break;
   case 'E':
   Location7(items, karma);
   default:
   break;
}
}

void Location7(int &items, int &karma)
{
   cout << "\n------------------------------------------------------------\n";
   cout << "\nYou are at the Yocum Dorms.\n";

  // ADD CODE HERE
   char choice;
   string item = " a collection of every tear you ever shed ";
   
   items = items + FindItem(item, 30);
   cout << "\nItems: " << items << " Karma: " << karma << endl;
   choice = GetDirection();
   while (choice != 'W')
{
   cout << "No." << endl;
   choice = GetDirection();
}
   Location6(items, karma);
}

void Location8(int &items, int &karma)
{
   cout << "\n------------------------------------------------------------\n";
   cout << "\nYou are at the graveyard where all the students who died from boredom lie.\n";

  // ADD CODE HERE
   char choice;
   string item = " an ordinary and lonely kitten ";
   
   items = items + FindItem(item, 75);
   cout << "\nItems: " << items << " Karma: " << karma << endl;
   
   choice = GetDirection()
   while ((choice != 'N') && (choice != 'W')) 
{
   cout << "No." << endl;
   choice = GetDirection();
}
   switch (choice)
{
   case 'N':
   break;
   case 'W':
   Location2(items, karma);
   break;
   default:
   break;
}
}
//------------------------------------------------------------
// Purpose: The main program
// Input:   None
// Output:  None
//------------------------------------------------------------
int main()
{
   // Initialize game
   srandom(time(NULL));
   int items = 0;
   int karma = 0;

   // Test two functions
   Start(items, karma);
   End(items, karma);

   // ADD CODE HERE

   return 0;
}

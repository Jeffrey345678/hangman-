#include <stdio.h>
#include <iostream>

using namespace std;

const char solution[] = "quattro"; // put your solution word in here
// bool is true false 
bool check_char(char word[], char input, int* replacements) // 
{
	bool exists = false; // initiating the boolian default as a false

	for (int i=0;i<(int)sizeof(solution);i++)
	{
		if (solution[i]==input)
		{
			word[i*2] = input;
			exists = true;
			(*replacements)++;
		}
	}

	return exists;
}


int main(void)
{
	int tries = 6;
	int replacements = 1;
	char word[sizeof(solution)*2];
	char input_character;

	// Initialize word template
	for (int i=0;i<(int)sizeof(solution)-1;i++)
	{
		word[i*2] = '_';
		word[i*2 + 1] = ' ';
	}

	cout << "\033[2J\033[1;1H"; // clears screen

	while (tries > 0 && replacements<(int)sizeof(solution))
	{
		// Print word status
		cout << endl << word << endl << endl;
char preval; //-- prevalidation of legit char
		 char input_character;
		cout << "Enter a character: ";
		cin >> input_character;
		//preval;    1 
		
		
		

		cout << "\033[2J\033[1;1H"; // clear screen

		// Check input against each character of the solution
		if (!check_char(word, input_character, &replacements))
		{
			tries--;
			cout << "Character not found. " << endl;
		}

		cout << tries << " lives remaining." << endl;
	}

	// Clear terminal
	cout << "\033[2J\033[1;1H";
// Two statements below check number of tries if there are none it tells fail if more than one success
	if (tries==0)	
	{
		cout << "Fail!!!!!!!!" << endl; // added more exclamation marks 
		cout << "The word was \"" << solution << "\"." << endl;
	}
	else
	{
		cout << "Success!" << endl;
		cout << "The word was \"" << solution << "\"." << endl;
		cout << "You had ";
		cout << tries << " tries left!" << endl;
	}

	return 0;
}
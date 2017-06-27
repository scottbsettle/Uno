#include "Human.h"

// Default ctor
Human::Human(const char* _name)
{
	/* TODO Lab2:
	Implement this method.

	Send back the appropriate information to the parent/base class.
	*/
	
	Player::SetName(_name);
	
	
}

// Display the computer's name and card backs
void Human::Show() const
{
	/* TODO Lab2:
	Implement this method.

	Should display the name of the player as well as their card faces

	Example:		Human
					7♥ 3♣ 5♦ 9♥

	*/
	Console::ResetColor();
	cout << Player::GetName() << endl;
	for (int loop = 0; loop < Player::GetNumCards(); loop++)
	{

		//Console::BackgroundColor(White);
		Card crd;
		
			Console::BackgroundColor(White);
	   Player::GetCard(loop, crd);
	   cout << crd;
       Console::ResetColor();
		cout << " ";

	}
}
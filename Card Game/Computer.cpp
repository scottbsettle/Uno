#include "Computer.h"

// Default ctor
Computer::Computer(const char* _name)
{
	/* TODO Lab2:
			Implement this method.
	
			Send back the appropriate information to the parent/base class.
	*/
	
	Player::SetName(_name);

}

// Display the computer's name and card backs
void Computer::Show() const
{
	/* TODO Lab2:
			Implement this method.
	
			Should display the name of the player as well as their card backs.

			Example:		Computer
							XX XX XX XX

	*/
	Console::ResetColor();
	cout << Player::GetName() << endl;
	Card crd;
	for (int loop = 0; loop < Player::GetNumCards(); loop++)
	{
		//Console::BackgroundColor(White);
		// Show their cards
		Console::BackgroundColor(White);
		
		/*Player::GetCard(loop, crd);
		cout << crd;
		Console::ResetColor();
		cout << " ";*/
		// Print out xx
		Console::ForegroundColor(Black);
		cout << "XX";
		Console::ResetColor();
		cout << " ";
	}
}

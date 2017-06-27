#include "Card.h"

// Default constructor
// In:	_face			The face value of the card
//		_suit			The suit of the card
Card::Card(int _face, char _suit)
{
	/* TODO Lab1:
			Fill out the constructor body
	*/
	m_face = _face;
	m_suit = _suit;
}

Card::~Card()
{

}


/* Accessors */

/* TODO Lab1:
		Define the two accessors if they were not inlined.
*/


/* Mutators */

/* TODO Lab1:
		Define the two mutators if they were not inlined.
*/

// Display a card to the screen
void Card::Show() const
{
	/* TODO Lab1:
			Display the Card object.  

			Make sure that "face" cards (Jack-Ace) display as 'J', 'Q', 'K', 'A'
			or something similar instead of their numeric value.

			*Note - This unit test is not automated, so make sure you verify 
			the face card is displaying correctly.
	*/
	//Console::BackgroundColor(White);
	if (m_suit == 'B')
		Console::ForegroundColor(Blue);
	else if (m_suit == 'G')
		Console::ForegroundColor(Green);
	else if (m_suit == 'Y')
		Console::ForegroundColor(DarkYellow);
	else
		Console::ForegroundColor(Red);
	//cout << m_suit;
	/*8 Draw 2 cards(two in each color) - Face value 10
		8 Reverse cards(two in each color) - Face value 11
		8 Skip cards(two in each color) - Face value 12
		4 Wild cards(even though these are "colorless," making one each color is easier) - Face value 13
		4 Wild Draw 4 cards(even though these are "colorless," making one in each color is easier) - Face value 14*/

	if (m_face == 12)
		cout << " S";
	else if (m_face == 11)
		cout << " R";
	else if (m_face == 13)
	{
		Console::ForegroundColor(Black);
		cout << " W";
	}
	else if (m_face == 14)
	{
		Console::ForegroundColor(Black);
		cout << "W4";
	}
	else if (m_face == 10)
		cout << "D2";
	else
	cout << " " << m_face;
}

// Relational operators

/* TODO Lab1:
		Define the six relational operators if they were not inlined.
		*/

// Insertion operator to display Cards with cout (or any other ostream object)

/* TODO Lab1:
		Define the insertion operator to display a card.

		Make sure that "face" cards (Jack-Ace) display as 'J', 'Q', 'K', 'A'
		or something similar instead of their numeric value.

		*Note - This unit test is not automated, so make sure you verify
		the face card is displaying correctly.
*/
ostream& operator<<(ostream& _lhs, const Card &_rhs)
{
	Console::BackgroundColor(White);
	if (_rhs.GetSuit() == 'B')
		Console::ForegroundColor(Blue);
	else if (_rhs.GetSuit() == 'G')
		Console::ForegroundColor(Green);
	else if (_rhs.GetSuit() == 'Y')
		Console::ForegroundColor(DarkYellow);
	else
		Console::ForegroundColor(Red);
	/*8 Draw 2 cards(two in each color) - Face value 10
		8 Reverse cards(two in each color) - Face value 11
		8 Skip cards(two in each color) - Face value 12
		4 Wild cards(even though these are "colorless," making one each color is easier) - Face value 13
		4 Wild Draw 4 cards(even though these are "colorless," making one in each color is easier) - Face value 14*/
	
	 if (_rhs.GetFace() == 12)
		cout << " S";
	else if (_rhs.GetFace() == 11)
		cout << " R";
	else if (_rhs.GetFace() == 13)
	{
		
			if (_rhs.GetSuit() == 'B')
				Console::BackgroundColor(Blue);
			else if (_rhs.GetSuit() == 'R')
				Console::BackgroundColor(Red);
			else if (_rhs.GetSuit() == 'G')
				Console::BackgroundColor(Green);
			else
				Console::BackgroundColor(DarkYellow);

		
		Console::ForegroundColor(Black);
		cout << " W";
	}
	else if (_rhs.GetFace() == 14)
	{
		if (_rhs.GetSuit() == 'B')
			Console::BackgroundColor(Blue);
		else if (_rhs.GetSuit() == 'R')
			Console::BackgroundColor(Red);
		else if (_rhs.GetSuit() == 'G')
			Console::BackgroundColor(Green);
		else
			Console::BackgroundColor(DarkYellow);
		

		Console::ForegroundColor(Black);
		cout << "W4";
	}
	else if (_rhs.GetFace() == 10)
		cout << "D2";
	else 
	{
		
		_lhs << " " << _rhs.GetFace();
	}
	Console::ResetColor();
	return _lhs;
}
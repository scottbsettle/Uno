#include "Deck.h"
#include "Stack.h"

// Default ctor
Deck::Deck()
{
	/* TODO Lab3:
			Implement this method.

			Get everything set up by calling Initialize.
	*/
	Initialize();
}

// Sets up the array of cards to be a unique deck
void Deck::Initialize()
{
	/* TODO Lab3:
			Implement this method.
	
			Set the values in the m_cards array to be the appropriate values for your game.

			For Go Fish: 13 cards of each of the 4 suits

			For UNO: 19 (B)lue cards (one 0, two each 1-9)
					 19 (G)reen cards (one 0, two each 1-9)
					 19 (R)ed cards (one 0, two each 1-9)
					 19 (Y)ellow cards (one 0, two each 1-9)
					  8 Draw 2 cards (two in each color) - Face value 10
					  8 Reverse cards (two in each color) - Face value 11
					  8 Skip cards (two in each color) - Face value 12
					  4 Wild cards (even though these are "colorless," making one each color is easier) - Face value 13
					  4 Wild Draw 4 cards (even though these are "colorless," making one in each color is easier) - Face value 14
	*/
	int counter = 0;
	int num = 0;
	Card temp;
	for (int loop = 0; loop < 4; loop++)
	{
		temp.SetFace(0);
		if (loop == 0)
		{
			temp.SetSuit('B');
		}
		else if (loop == 1)
		{
			temp.SetSuit('G');
		}
		else if (loop == 2)
		{
			temp.SetSuit('R');
		}
		else
			temp.SetSuit('Y');

		m_cards[loop] = temp;
		counter++;
	}
	
	for (int loop = 1; loop <= 8; loop++)
	{
		for (int loop2 = 1; loop2 < 13; loop2++)
		{
			temp.SetFace(loop2);
			if (loop == 1 || loop == 2)
			{
				temp.SetSuit('B');
			}
			else if (loop == 3 || loop == 4)
			{
				temp.SetSuit('G');
			}
			else if (loop == 5 || loop == 6)
			{
				temp.SetSuit('R');
			}
			else
				temp.SetSuit('Y');

			m_cards[counter] = temp;
			counter++;
		   
		}
	}
	for (int loop = 0; loop < 4; loop++)
	{
		temp.SetFace(13);
		if (loop == 0)
		{
			temp.SetSuit('B');
		}
		else if (loop == 1)
		{
			temp.SetSuit('G');
		}
		else if (loop == 2)
		{
			temp.SetSuit('R');
		}
		else
			temp.SetSuit('Y');

		m_cards[counter] = temp;
		counter++;
	}
	for (int loop = 0; loop < 4; loop++)
	{
		temp.SetFace(14);
		if (loop == 0)
		{
			temp.SetSuit('B');
		}
		else if (loop == 1)
		{
			temp.SetSuit('G');
		}
		else if (loop == 2)
		{
			temp.SetSuit('R');
		}
		else
			temp.SetSuit('Y');

		m_cards[counter] = temp;
		counter++;
	}
	
}

// Clears any cards that are already in the stack, shuffles the array, and then pushes
// all of the shuffled cards onto the stack.
void Deck::Shuffle()
{
	/* TODO Lab3:
			Implement this method.
	*/
	if (m_Stack.GetCurrSize() != 0)
	m_Stack.Clear();
	int tem1, tem2;
	for (int loop = 0; loop < 1000; loop++)
	{
		tem1 = rand() % 108;
		
		tem2 = rand() % 108; 
		while (tem1 == tem2)
		{
			tem2 = rand() % 108;
		}
		swap(m_cards[0], m_cards[107]);
		swap(m_cards[tem1], m_cards[tem2]);
	}
	for (int loop = 0; loop < 108; loop++)
	{
		m_Stack.Push(m_cards[loop]);
	}
}
void Deck::ReShuffle()
{
   int tem1, tem2;
	for (int loop = 0; loop < 1000; loop++)
	{
		tem1 = rand() % Stack::GetCurrSize();
		
		tem2 = rand() % Stack::GetCurrSize();
		while (tem1 == tem2)
		{
			tem2 = rand() % Stack::GetCurrSize();
		}
		swap(m_cards[0], m_cards[Stack::GetCurrSize() - 1]);
		swap(m_cards[tem1], m_cards[tem2]);
	}
	for (int loop = 0; loop < 108; loop++)
	{
		m_Stack.Push(m_cards[loop]);
	}
}

// Draw the top-most card off of the stack
// In:	_card			A reference to store the drawn card
//
// Return: True if a card was removed
//		   False if the deck was empty
bool Deck::Draw(Card& _card)
{
	/* TODO Lab3:
			Implement this method.
	*/

	// Just here for compilation
	if (m_Stack.GetCurrSize() == 0)
		return false;

	m_Stack.Pop(_card);
	return true;
}

// Clear the stack for re-use
void Deck::Clear()
{
	m_Stack.Clear();
	/* TODO Lab3:
			Implement this method.
	*/
}

// Check to see if there are any cards left in the stack
//
// Return: True if the stack is empty
//		   False if there are any cards left in the stack
bool Deck::IsEmpty() const
{

	/* TODO Lab3:
			Implement this method.
	*/

	// Just here for compilation
	if (m_Stack.GetCurrSize() == 0)
		return true;
	else
		return false;
}
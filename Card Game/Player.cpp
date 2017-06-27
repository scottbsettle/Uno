#include "Player.h"

/* TODO Lab5:
		Initialize m_maxCards in all constructors
*/

// Default ctor
// In:	_name			The player's name
//		_maxCards		The maximum number of cards they can store

Player::Player(const char* _name, int _maxCards) : m_maxCards(_maxCards)
{
	/* TODO Lab2/4:
			Fill out the constructor body.

			Keep in mind that there are more than two data members.
	*/
	//m_maxCards = _maxCards;
	////m_maxCards = 13;
	//m_name = new char[strlen(_name) + 1];
	//strcpy_s(m_name, strlen(_name) + 1, _name);
	//m_numCards = 0;
	//m_score = 0;
	//m_maxCards = _maxCards;
	m_name = new char[strlen(_name) + 1];
	strcpy_s(m_name, strlen(_name) + 1, _name);
	m_numCards = 0;
	
	m_hand = new Card[24];
				
	m_score = 0;
	
	

}

/* TODO Lab4:
		Define and implement the copy constructor.

		Make sure to copy all data members (using deep copies when necessary).
*/
Player::Player(const Player& _obj) : m_maxCards(_obj.m_maxCards)
{

	m_name = new char[strlen(_obj.m_name) + 1];
	strcpy_s(m_name, strlen(_obj.m_name) + 1, _obj.m_name);
	m_numCards = _obj.m_numCards;
	//m_maxCards = _obj.m_maxCards;
	m_score = _obj.m_score;
	
	m_hand = new Card[24];

	for (int card = 0; card < _obj.m_numCards; card++)
	{
		m_hand[card] = _obj.m_hand[card];
	}


}

// Dtor
Player::~Player()
{
	/* TODO Lab4:
			Clean up any dynamic memory
	*/
	delete[] m_name;
	delete[] m_hand;
}

/* TODO Lab4:
		Define and implement the assignment operator.

		Make sure to copy all data members (using deep copies when necessary).

		* There will be a small change to this in Lab5 where you will have to comment out
		  the m_maxCards assignment, but go ahead and make the copy for now.
*/
Player& Player::operator=(const Player& _assign)
{
	// The built-in assignment operator does shallow copies
	// of all data members

	// Check for self-assignment
	if (this != &_assign)
	{
		// Clean up the existing memory
		delete[] m_name;
		delete[] m_hand;
		// We need to deep copy dynamic data member
		m_name = new char[strlen(_assign.m_name) + 1];
		strcpy_s(m_name, strlen(_assign.m_name) + 1, _assign.m_name);
		m_numCards = _assign.m_numCards;
		//m_maxCards = _assign.m_maxCards;
		m_score = _assign.m_score;
		m_hand = new Card[m_maxCards];

		for (int card = 0; card < m_numCards; card++)
		{
			m_hand[card] = _assign.m_hand[card];
		}
		// We can shallow copy non-dynamic data members


	}
	return *this;
}
/* Accessors */

/* TODO Lab2:
		Define the accessors if they were not inlined.
*/

// Access a Card from the player's hand
// In:	_index		The index of the card being accessed
//		_card		A reference to store that value in
//
// Return: True if there was a card actually stored at that index.
//		   False if the index was "empty"
bool Player::GetCard(int _index, Card& _card) const
{
	/* TODO Lab2:
			Implement this method.
	*/

	// Just here for compilation
	if (_index >= m_numCards)
	{
		return false;
	}
	_card = m_hand[_index];
	return true;

}

/* Mutators */

// Change the player's name to the value passed in
void Player::SetName(const char* _name)
{
	/* TODO Lab2/4:
			Implement this method.
	*/
	delete[] m_name;
	m_name = new char[strlen(_name) + 1];
	strcpy_s(m_name, strlen(_name) + 1, _name);
}

// Update the player's score by some amount
void Player::AddToScore(int _add)
{
	/* TODO Lab2:
			Implement this method.

			Increase their score by the amount passed in.
	*/
	m_score += _add;
}

// Add a Card to the player's hand
// In:	_card		The card being added
//
// Return: True if the card was successfully added to their hand
//		   False if the player's hand was already full
bool Player::AddCard(const Card& _card)
{
	/* TODO Lab2:
			Implement this method.

			Should store the passed card in the next available empty index (if there is one).
			You should know how many cards are in the hand to know where that
			index will be.
			*/

	// Just here for compilation'
	if (m_numCards >= m_maxCards)
		return false;
	m_hand[m_numCards] = _card;
	m_numCards++;
	return true;
}

// Remove a Card from the player's hand
// In:	_index		The index of the card to remove from the array
//		_card		A reference to store that value in
//
// Return: True if there was a card actually stored at that index.
//		   False if the index was "empty"
bool Player::Discard(int _index, Card& _discard)
{
	/* TODO Lab2:
			Implement this method.
	
			Should store the requested card into the reference being passed in.
			After that, "shift" the array back to show this card has been removed.

			Example:
			[ 7♥ 3♣ 5♦ 9♥ ]		m_numCards: 4

					* discarding index 1 (the 3♣) *

			[ 7♥ 5♦ 9♥ 9♥ ]		m_numCards: 3

					* Even though it looks like there are two 9♥, we won't ever be displaying
					  that to the user, and it will be the first one that gets overwritten if 
					  another card is added to the hand. *
	*/

	// Just here for compilation
	if (_index >= m_numCards)
	{
		return false;
	}
	if (m_numCards <= 0)
	{
		return false;
	}
	_discard = m_hand[_index];
	if (_index != m_numCards)
	{
		for (int loop = _index; loop < m_numCards; loop++)
		{
			m_hand[loop] = m_hand[loop + 1];
		}
	}
	m_numCards--;
	// Just here for compilation
	return true;
}

// Clear the player's hand so that they are holding 0 cards
void Player::Clear()
{
	/* TODO Lab2:
			Implement this method.
	*/
	delete[] m_hand;
	
}

// Display method (empty for this class)
void Player::Show() const
{

}
#pragma once
#include <iostream>
using namespace std;

#include "Player.h"
#include "Human.h"
#include "Computer.h"
#include "Deck.h"

// Enum of gamestates, you can add and remove from this if you need additional ones (examples include: GAME_TITLE, GAME_MENU, GAME_OPTIONS, etc).
enum GAMESTATE { GAME_INIT, GAME_TITLE, GAME_MENU, GAME_PLAY, GAME_END, ROUND_INIT, ROUND_END};
#define SLEEP 1500
class Game
{
	// Necessary data members
	Card temp, top, change;
	Human m_Real;
	Computer m_Computers[3];
	Player* m_players[4];	// The players in the game
	Deck m_Deck, m_Discard;   // The deck of cards
	int m_currPlayer;		// Keeps track of which index is currently taking their turn
	int m_numPlayers, m_Allplayers;		// The number of players playing in the game
	char m_name[20];
	int choose, count = 0, count2 = 0;
	char playagain;
	

	// If you're coding UNO, this data member is necessary as well
	
		bool m_reversed = false;			// Keeps track of the order of play
		bool m_skip = false;                // Check to see if skip is true;
		bool m_Draw2 = false;
		bool m_Draw4 = false;

	// GAMESTATE object to store the game's current state.
	GAMESTATE m_state;

	// Add game data members as necessary

public:
	// Default ctor
	Game();

	// Dtor
	~Game();

	// The main function of the game, this loops until a certain gamestate is set.
	void Run();

	// Modifier for the gamestate data member.
	void SetState(GAMESTATE _state) { m_state = _state; }

	// Get the score for the game
	//	For Go Fish, this will take care of pairing
	//  For UNO, this will be used for end of round scoring.
	 int Score(Player* _player);
	Card redraw();
	void display();
	bool CheckHand(const Player& _player);
	bool CheckCard(const Card _card);
	void Discardbot(Player& _player);
	void Update(Player& _player);
	void Choose();
	void Uno(Player& _player, Card& _card);
	void Draw2();
	 void Skip();
	 void Wild(Card& _card);
	void Wild4(Card& _card);
	void Wild4Com(Card& _card);
  void Reverse(Card& _card);
  void WildCom(Card& _card);
  void ReShuffle();
  bool Winner();
  void points(Player& _player, Player& _Winner);
  void intro();
};
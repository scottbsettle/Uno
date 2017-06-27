#include "Game.h"
#include "Stack.h"
// Default ctor
Game::Game()
{
	m_state = GAME_INIT;
}

// Dtor
Game::~Game()
{

}

void Game::Run()
{
	// Bool to control whether the game should continue to run.
	bool bRun = true;
	
	// Loop while our bool remains true.
	while(bRun)
	{
		switch(m_state)
		{
		case GAME_INIT:
			// Insert initialization code here.
			m_Deck.Initialize();
			m_Deck.Shuffle();
			

			m_Computers[0].SetName("Prophet");
			m_Computers[1].SetName("One Man");
			m_Computers[2].SetName("Salty Taco");
			m_state = GAME_MENU;
			break;
		case GAME_MENU:
			system("cls");
			intro();
			cout << "---------------\n";
			cout << "1.) Play Game |\n";
			cout << "2.) Rules     |\n";
			cout << "3.) Cheats    |\n";
			cout << "4.) Quit      |\n";
			cout << "---------------\n";
			cout << "Uno : ";
			cin >> choose;
			while (!cin.good())
			{
				cin.clear();
				cin.ignore(LLONG_MAX, '\n');
				cout << "1-4 only";
				cin >> m_numPlayers;
			}
			while (choose < 1 && choose > 4)
			{
				cin.clear();
				cin.ignore(LLONG_MAX, '\n');
				cout << "1-4 only";
				cin >> m_numPlayers;
				while (!cin.good())
				{
					cin.clear();
					cin.ignore(LLONG_MAX, '\n');
					cout << "1-4 only";
					cin >> m_numPlayers;
				}
			}
			switch (choose)
			{
			case 1:
			{
				if (count2 == 0)
				{
					system("cls");
					intro();
					cin.clear();
					cin.ignore(LLONG_MAX, '\n');
					cout << "Enter your name : ____________________\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
					cin.getline(m_name, 20);

					system("cls");
					intro();
					m_Real.SetName(m_name);
					cout << "How many other players do you want 1-3 : ";
					cin >> m_numPlayers;
					while (!cin.good())
					{
						system("cls");
						intro();
					cin.clear();
					cin.ignore(LLONG_MAX, '\n');
					cout << "How many other players do you want 1-3 : ";
					cin >> m_numPlayers;
					}
					while (m_numPlayers < 1 || m_numPlayers > 4)
					{
						system("cls");
						intro();
					cin.clear();
					cin.ignore(LLONG_MAX, '\n');
					cout << "How many other players do you want 1-3 : ";
					cin >> m_numPlayers;
					while (!cin.good())
					{
						system("cls");
						intro();
					cin.clear();
					cin.ignore(LLONG_MAX, '\n');
					cout << "How many other players do you want 1-3 : ";
					cin >> m_numPlayers;
					}
					}
					m_numPlayers++;
					m_Allplayers = m_numPlayers;
					m_currPlayer = 1;
					count2++;
				}
				m_state = GAME_PLAY;
				break;
			}
			case 2:
			{
				system("cls");
				cout << "\t\t---------\n";
				cout << "\t\t| Rules |\n";
				cout << "\t\t---------\n";
				Console::ForegroundColor(Green);
				cout << "1.)  The first person to 500 points wins!\n"
					<< "2.)  A person goes out by having no cards left.\n"
					<< "3.)  The person who goes out gets all points from all other players cards.\n"
					<< "4.)  Points face cards 0-9 are worth the number that they are.\n"
					<< "     Skips Reverse Draw-two are worth 20 points.\n"
					<< "     Wild cards including wild-draw-four are worth 50 points.\n";
				Console::ForegroundColor(Red);
				cout << "5.)  When someone has one card let they say UNO.\n"
					<< "6.)  If a person cannot set down a card they draw from the deck.\n"
					<< "7.)  If a draw two or wild draw 4\n"
					<< "     is played the person that draws turn is skipped\n";
				Console::ForegroundColor(Yellow);
				cout << "8.)  When there are no more cards to draw from, the discard pile is\n     shuffled back and the top the card is left.\n"
					<< "9.)  On Your turn hit Escape to go back to the menue!\n"
					<< "10.) The card must be of the same suit or face to set down.\n"
					<< "11.) Wild cards can be set down at any time, and that player picks the color\n"
					<< "12.) S - Skip, R - Reverse, D2 - Draw 2, W - Wild card, W4- Wild draw 4\n";
				    
				Console::ForegroundColor(Blue);
				system("pause");
				Console::ResetColor();
				break;
			}
			case 3:
			{
				break;
			}
			case 4:
			{
				system("cls");
				Console::ForegroundColor(Green);
				cout << "\n\t----------------------\n";
				cout << "\t| Have nice day! 0_0 |\n";
				cout << "\t----------------------\n";
				Console::ResetColor();
				bRun = false;
				break;
			}
			}
		
			
			break;
		case GAME_PLAY:
			if (count == 0)
			{
				
				for (int loop = 0; loop < m_numPlayers; loop++)
				{
					for (int i = 0; i < 7; i++)
					{
						if (loop == 0)
						{
							m_Deck.Draw(temp);
							m_Real.AddCard(temp);
						}
						else
						{
							m_Deck.Draw(temp);
							m_Computers[loop - 1].AddCard(temp);
						}
					}
				}

				m_Deck.Draw(temp);


				if (temp.GetFace() == 12)
				{
					m_skip = true;
				}
				if (temp.GetFace() == 10)
				{
					m_Draw2 = true;
				}
				Reverse(temp);
				if (m_reversed == true)
				{
					//system("pause");
					Sleep(SLEEP);
					m_currPlayer = m_numPlayers;
				}
				WildCom(temp);
				Wild4Com(temp);
				top = temp;
				m_Discard.Push(top);
				count = 1;
			}
// Player 1
			if (m_currPlayer == 1)
			{
				display();
				Console::ForegroundColor(Yellow);
				cout << "---------------------------------------\n";
				cout << "| Hit escape to go back to the menue! |\n";
				cout << "---------------------------------------\n";
				Console::ResetColor();
				Sleep(SLEEP);
				if (GetAsyncKeyState(VK_ESCAPE))
				{
					m_state = GAME_MENU;
					break;
				}
				display();
				
				if (m_skip == false && m_Draw2 == false && m_Draw4 == false)
				{
					if (CheckHand(m_Real))
					{
						
						cout << "what card would you like to set down 1 -" << m_Real.GetNumCards() << " :";
						cin >> choose;
						
						while (!cin.good())
						{
							cin.sync();
							cin.clear();
							cout << "what card would you like to set down 1 -" << m_Real.GetNumCards() << " :";
							cin >> choose;
						}
						while (choose <= 0 || choose > m_Real.GetNumCards())
						{
							cin.sync();
							cin.clear();
							cout << "what card would you like to set down 1 -" << m_Real.GetNumCards() << " :";
							cin >> choose;
						}
						m_Real.GetCard(choose - 1, temp);

						if (CheckCard(temp))
						{
							//temp = Wild(temp);
							if (temp.GetFace() == 12)
							{
								m_skip = true;
							}
							if (temp.GetFace() == 10)
							{
								m_Draw2 = true;
							}
							Wild(temp);
							Wild4(temp);
							Reverse(temp);
							top = temp;
							m_Discard.Push(top);
							m_Real.Discard(choose - 1, temp);
							Uno(m_Real, top);
							Choose();
							//	m_currPlayer++;

						}
						else if (!CheckCard(temp))
						{
							Console::ForegroundColor(Red);
							cout << "------------------------------------------\n";
							cout << "| Card must be of the same suit or face! |\n";
							cout << "------------------------------------------\n";
							Sleep(SLEEP);
						}

					}
					else if (!CheckHand(m_Real))
					{
						cout << "Player "; Console::ForegroundColor(Green); cout << m_Real.GetName();
						Console::ResetColor(); cout << " does not have any cards to set down!\n";
						//system("pause");
						Sleep(SLEEP);
						if (m_Real.GetMaxCards() != m_Real.GetNumCards())
						{
							if (m_Deck.IsEmpty())
							{
								ReShuffle();
							}
							m_Deck.Draw(temp);
							m_Real.AddCard(temp);
							display();
							if (CheckCard(temp))
							{
								
								if (temp.GetFace() == 12)
								{
									m_skip = true;
								}
								if (temp.GetFace() == 10)
								{
									m_Draw2 = true;
								}
							    /* Wild(temp);
								 Wild4(temp);*/
								Reverse(temp);
								m_Real.GetCard((m_Real.GetNumCards() - 1), temp);
								Wild(temp);
								Wild4(temp);
								top = temp;
								m_Discard.Push(top);
								m_Real.Discard((m_Real.GetNumCards() - 1), temp);
								cout << "Player "; Console::ForegroundColor(Green); cout << m_Real.GetName();
								Console::ResetColor(); cout << " drew a card that they could set down!\n";
								cout << temp << "\n";
								//system("pause");
								Sleep(1500);
							}
						}
						else if (m_Real.GetMaxCards() == m_Real.GetNumCards())
						{
							Console::ForegroundColor(Red);
							cout << "Cards have reached there Max\n";
							Console::ResetColor();
							//system("pause");
							Sleep(SLEEP);
						}
						Uno(m_Real, top);
						Choose();
						//m_currPlayer++;
					}
					//Uno(m_Real, top);
					//Choose();
				}
				 else if (m_skip == true || m_Draw2 == true || m_Draw4 == true)
				 {

					 cout << "Player ";
					 Console::ForegroundColor(Red);
					 cout << m_Real.GetName();
					 Console::ResetColor();
					 if (m_Draw2 == true)
					 {
						 cout << " has to draw 2 cards and there";
						 for (int loop = 0; loop < 2; loop++)
						 {
							
							 if (m_Deck.IsEmpty())
							 {
								 ReShuffle();
							 }
							 m_Deck.Draw(temp);
							 m_Real.AddCard(temp);
						 }
						 m_Draw2 = false;
					 }
					 if (m_Draw4 == true)
					 {
						 cout << " has to draw 4 cards and there";
						 for (int loop = 0; loop < 4; loop++)
						 {
							 
							 if (m_Deck.IsEmpty())
							 {
								 ReShuffle();
							 }
							 m_Deck.Draw(temp);
							 m_Real.AddCard(temp);
						 }
						 m_Draw4 = false;
					 }
					 cout << " turn has been skipped.\n";
					 //system("pause");
					 Sleep(SLEEP);
					 Choose();
					 m_skip = false;
				 }
				
			}
// player 2
			else if (m_currPlayer == 2 )
			{
				if (m_skip == false && m_Draw2 == false && m_Draw4 == false)
				{
					display();
					Update(m_Computers[0]);
				
				}
				else if (m_skip == true || m_Draw2 == true || m_Draw4 == true)
				{
					cout << "Player ";
					Console::ForegroundColor(Red);
					cout << m_Computers[0].GetName();
					Console::ResetColor();
					if (m_Draw2 == true)
					{
						cout << " has to draw 2 cards and there";
						for (int loop = 0; loop < 2; loop++)
						{
							
							if (m_Deck.IsEmpty())
							{
								ReShuffle();
							}
							m_Deck.Draw(temp);
							m_Computers[0].AddCard(temp);
						}
						m_Draw2 = false;
					}
					if (m_Draw4 == true)
					{
						cout << " has to draw 4 cards and there";
						for (int loop = 0; loop < 4; loop++)
						{
							
							if (m_Deck.IsEmpty())
							{
								ReShuffle();
							}
							m_Deck.Draw(temp);
							m_Computers[0].AddCard(temp);
						}
						m_Draw4 = false;
					}
					cout << " turn has been skipped.\n";
					//system("pause");
					Sleep(SLEEP);
					Choose();
					m_skip = false;
				}
			}
// player 3
			else if (m_currPlayer == 3)
			{
				if (m_skip == false && m_Draw2 == false && m_Draw4 == false)
				{
					display();
					Update(m_Computers[1]);
					
				}
				else if (m_skip == true || m_Draw2 == true || m_Draw4 == true)
				{
					cout << "Player ";
					Console::ForegroundColor(Red);
					cout << m_Computers[1].GetName();
					Console::ResetColor();
					if (m_Draw2 == true)
					{
						cout << " has to draw 2 cards and there";
						for (int loop = 0; loop < 2; loop++)
						{
							
							if (m_Deck.IsEmpty())
							{
								ReShuffle();
							}
							m_Deck.Draw(temp);
							m_Computers[1].AddCard(temp);
						}
						m_Draw2 = false;
					}
					if (m_Draw4 == true)
					{
						cout << " has to draw 4 cards and there";
						for (int loop = 0; loop < 4; loop++)
						{
							
							if (m_Deck.IsEmpty())
							{
								ReShuffle();
							}
							m_Deck.Draw(temp);
							m_Computers[1].AddCard(temp);
						}
						m_Draw4 = false;
					}
					cout << " turn has been skipped.\n";
					//system("pause");
					Sleep(SLEEP);
					Choose();
					m_skip = false;
				}
			}
// player 4
			else if (m_currPlayer == 4)
			{
				if (m_skip == false && m_Draw2 == false && m_Draw4 == false)
				{
					display();
					Update(m_Computers[2]);
				}
				else if (m_skip == true || m_Draw2 == true || m_Draw4 == true)
				{
					cout << "Player ";
					Console::ForegroundColor(Red);
					cout << m_Computers[2].GetName();
					Console::ResetColor();
					if (m_Draw2 == true)
					{
						cout << " has to draw 2 cards and there";
						for (int loop = 0; loop < 2; loop++)
						{
							
							if (m_Deck.IsEmpty())
							{
								ReShuffle();
							}
							m_Deck.Draw(temp);
							m_Computers[2].AddCard(temp);
						}
						m_Draw2 = false;
					}
					if (m_Draw4 == true)
					{
						cout << " has to draw 4 cards and there";
						for (int loop = 0; loop < 4; loop++)
						{
							
							if (m_Deck.IsEmpty())
							{
								ReShuffle();
							}
							m_Deck.Draw(temp);
							m_Computers[2].AddCard(temp);
						}
						m_Draw4 = false;
					}
					cout << " turn has been skipped.\n";
					//system("pause");
					Sleep(SLEEP);
					Choose();
					m_skip = false;
				}
			}
			// Insert game play code here.
			break;
		case GAME_END:
			// The game is over, change the bool to stop the loop.
			if (!Winner())
			{
				display();
				Console::ForegroundColor(Green);
				cout << "---------------------\n";
				cout << "| New game starting |\n";
				cout << "---------------------\n";
				Console::ResetColor();
				system("pause");
				count = 0;
				m_state = GAME_PLAY;
				m_Discard.Clear();
				m_Deck.Clear();
				m_Deck.Initialize();
				m_Deck.Shuffle();
				m_reversed = false;
				m_skip = false;
				m_Draw2 = false;
				m_Draw4 = false;
				if (m_Real.GetNumCards() != 0)
				{
					int x = m_Real.GetNumCards();
					for (int loop = 0; loop < x; loop++)
					{
						m_Real.Discard(m_Real.GetNumCards() - 1, temp);
					}
				}
				for (int loop = 0; loop < 3; loop++)
				{
					if (m_Computers[loop].GetNumCards() != 0)
					{
						int x = m_Computers[loop].GetNumCards();
						for (int i = 0; i < x; i++)
						{
							m_Computers[loop].Discard(m_Computers[loop].GetNumCards() - 1, temp);
						}
					}
				}
				m_currPlayer = 1;
			}
			else if (Winner())
			{
				display();
				if (m_Real.GetScore() >= 500)
				{
					cout << m_Real.GetName() << " Has won the game and reached 500 points!\n";
				}
				for (int loop = 0; loop < 3; loop++)
				{
					if (m_Computers[loop].GetScore() >= 500)
					{
						cout << m_Computers[loop].GetName() << " Wins the game and reached 500 points!\n";
					}

				}
				cout << "Do you want to play again? Y/N :";
				cin >> playagain;
				while (!cin.good())
				{
					cin.clear();
					cin.ignore(LLONG_MAX, '\n');
					cout << "Do you want to play again? Y/N :";
					cin >> playagain;
				}
				while (toupper(playagain) != 'Y' && toupper(playagain) != 'N')
				{
					cout << "Do you want to play again? Y/N :";
					cin >> playagain;
					while (!cin.good())
					{
						cin.clear();
						cin.ignore(LLONG_MAX, '\n');
						cout << "Do you want to play again? Y/N :";
						cin >> playagain;
					}
				}
				if (toupper(playagain) == 'Y')
				{
					count2 = 0;
					count = 0;
					m_state = GAME_MENU;
					m_Discard.Clear();
					m_Deck.Clear();
					m_Deck.Initialize();
					m_Deck.Shuffle();
					m_reversed = false;
					m_skip = false;
					m_Draw2 = false;
					m_Draw4 = false;
					if (m_Real.GetNumCards() != 0)
					{
						int x = m_Real.GetNumCards();
						for (int loop = 0; loop < x; loop++)
						{
							m_Real.Discard(m_Real.GetNumCards() - 1, temp);
						}
					}
					for (int loop = 0; loop < 3; loop++)
					{
						if (m_Computers[loop].GetNumCards() != 0)
						{
							int x = m_Computers[loop].GetNumCards();
							for (int i = 0; i < x; i++)
							{
								m_Computers[loop].Discard(m_Computers[loop].GetNumCards() - 1, temp);
							}
						}
					}
				}
				else if (toupper(playagain) == 'N')
				{
					bRun = false;
				}
			}

			break;
		}
	}
}




void Game::display()
{
	system("cls");
	cout << "Score  \n";
	cout << m_Real.GetName() << " :" << m_Real.GetScore() << "\t    ";
	cout << m_Computers[0].GetName() << " :" << m_Computers[0].GetScore() << "\t   ";
	if (m_numPlayers >= 3)
		cout << m_Computers[1].GetName() << " :" << m_Computers[1].GetScore() << "         ";
	if (m_numPlayers == 4)
		cout << m_Computers[2].GetName() << " :" << m_Computers[2].GetScore();
	cout << "\n\n";
	if (m_currPlayer == 1)
	{
		Console::ForegroundColor(Green);
		cout << "*";
		Console::ResetColor();
	}
	m_Real.Show();
	cout << endl << endl;
	if (m_currPlayer == 2)
	{
		Console::ForegroundColor(Green);
		cout << "*";
		Console::ResetColor();
	}
		m_Computers[0].Show();
		cout << "\n\n";
		if (m_numPlayers >= 3)
		{
			if (m_currPlayer == 3)
			{
				Console::ForegroundColor(Green);
				cout << "*";
				Console::ResetColor();
			}
			m_Computers[1].Show();
			cout << "\n\n";
		}
		if (m_numPlayers == 4)
		{
			if (m_currPlayer == 4)
			{
				Console::ForegroundColor(Green);
				cout << "*";
				Console::ResetColor();
			}
			m_Computers[2].Show();
		}
			
		cout << "\n";
	
	m_Discard.Draw(top);
	cout << "\n\n\tDiscard pile    :";
	 cout  << top << endl;
	m_Discard.Push(top);
} 
bool Game::CheckHand(const Player& _player)
{
	
	  
	for (int loop = 0; loop < _player.GetNumCards(); loop++)
	{
		_player.GetCard(loop, temp);
		m_Discard.Draw(top);
		if (temp.GetFace() == top.GetFace() || temp.GetFace() == 13 || temp.GetFace() == 14)
		{
			m_Discard.Push(top);
			return true;
		}
		else if (temp.GetSuit() == top.GetSuit() || temp.GetFace() == 13 || temp.GetFace() == 14)
		{
			m_Discard.Push(top);
			return true;
		}
	}
	m_Discard.Push(top);
	return false;
}
bool Game::CheckCard(const Card _card)
{
	m_Discard.Draw(top);
	if (_card.GetFace() == top.GetFace() || _card.GetFace() == 13 || _card.GetFace() == 14)
	{
		
		m_Discard.Push(top);
		return true;
	}
	else if (_card.GetSuit() == top.GetSuit() || _card.GetFace() == 13 || _card.GetFace() == 14)
	{
		
		m_Discard.Push(top);
		return true;
	}
	else
	{
		m_Discard.Push(top);
		return false;
	}
}
void Game::Discardbot(Player& _player)
{
	for (int loop = 0; loop < _player.GetNumCards(); loop++)
	{
		_player.GetCard(loop, temp);
		m_Discard.Draw(top);
		if (temp.GetFace() == top.GetFace() || temp.GetFace() == 13 || temp.GetFace() == 14)
		{
			
			 WildCom(temp);
			Wild4Com(temp);
			if (temp.GetFace() == 12)
			{
				m_skip = true;
			}
			if (temp.GetFace() == 10)
			{
				m_Draw2 = true;
			}
			Reverse(temp);
			top = temp;
			
			cout << "\nPlayer "; Console::ForegroundColor(Green);
			cout << _player.GetName(); Console::ResetColor();
			cout <<" sets down " << temp << "\n";
			//system("pause");
			Sleep(SLEEP);
			m_Discard.Push(top);
			_player.Discard(loop, temp);
			m_Discard.Push(top);
			break;
		}
		else if (temp.GetSuit() == top.GetSuit())
		{
			
			WildCom(temp);
			Wild4Com(temp);
			if (temp.GetFace() == 12)
			{
				m_skip = true;
			}
			if (temp.GetFace() == 10)
			{
				m_Draw2 = true;
			}
			Reverse(temp);
			top = temp;
			cout << "\nPlayer "; Console::ForegroundColor(Green);
			cout << _player.GetName(); Console::ResetColor();
			cout << " sets down " << temp << "\n";
			//system("pause");
			Sleep(SLEEP);
			 m_Discard.Push(top);
			
			_player.Discard(loop, temp);
			m_Discard.Push(top);
			break;
		}
	}
}
void Game::Update(Player& _player)
{
	if (CheckHand(_player))
	{
		Discardbot(_player);
		//m_currPlayer = 1;
		//Choose();
	}
	// if players has no cards to put down
	else if (!CheckHand(_player))
	{
		cout << "Player "; Console::ForegroundColor(Green); cout << _player.GetName();
			Console::ResetColor(); cout << " does not have any cards to set down!\n";
		//system("pause");
			Sleep(SLEEP);
		if (_player.GetMaxCards() != _player.GetNumCards())
		{
			if (m_Deck.IsEmpty())
			{
				ReShuffle();
			}
			m_Deck.Draw(temp);
			_player.AddCard(temp);
			display();
			if (CheckCard(temp))
			{
				
				if (temp.GetFace() == 12)
				{
					m_skip = true;
				}
				if (temp.GetFace() == 10)
				{
					m_Draw2 = true;
				}
				Reverse(temp);
				_player.GetCard((_player.GetNumCards() - 1), temp);
				WildCom(temp);
				Wild4Com(temp);
				top = temp;
				m_Discard.Push(top);
				_player.Discard((_player.GetNumCards() - 1), temp);
				cout << "Player "; Console::ForegroundColor(Green); cout << _player.GetName();
				Console::ResetColor(); cout << " drew card that they could set down! " << temp << " \n";
				//system("pause");
				Sleep(SLEEP);
			}
		}
		else if (_player.GetMaxCards() == _player.GetNumCards())
		{
			Console::ForegroundColor(Red);
			cout << "Cards have reached there Max\n";
			Console::ResetColor();
			//system("pause");
			Sleep(SLEEP);
		}
	//	Choose();
		//m_currPlayer = 1;
	}
	Uno(_player, top);
	Choose();
}
void Game::Choose()
{
	if (m_reversed == false)
	{
		if (m_currPlayer == m_Allplayers)
		{
			m_currPlayer = 1;
		}
		else
			m_currPlayer++;
	}
	if (m_reversed == true)
	{
		if (m_currPlayer == 1)
		{
			m_currPlayer = m_Allplayers;
		}
		else
			m_currPlayer--;
	}
}
void Game::Uno( Player& _player, Card& _card)
{
	for (int loop = 0; loop < 1; loop++)
	{
		if (_player.GetNumCards() == 0)
		{
			if (_card.GetFace() == 10)
			{
				if (m_reversed == false)
				{
					if (m_currPlayer == 1)
					{
						for (int loop = 0; loop < 2; loop++)
						{
							if (m_Deck.IsEmpty())
							{
								ReShuffle();
							}
							m_Deck.Draw(temp);
							m_Computers[0].AddCard(temp);
						}
					}
					if (m_currPlayer == 2)
					{
						for (int loop = 0; loop < 2; loop++)
						{
							if (m_Deck.IsEmpty())
							{
								ReShuffle();
							}
							m_Deck.Draw(temp);
							m_Computers[1].AddCard(temp);
						}
					}
					if (m_currPlayer == 3)
					{
						for (int loop = 0; loop < 2; loop++)
						{
							if (m_Deck.IsEmpty())
							{
								ReShuffle();
							}
							m_Deck.Draw(temp);
							m_Computers[2].AddCard(temp);
						}
					}
					if (m_currPlayer == 3)
					{
						for (int loop = 0; loop < 2; loop++)
						{
							if (m_Deck.IsEmpty())
							{
								ReShuffle();
							}
							m_Deck.Draw(temp);
							m_Real.AddCard(temp);
						}
					}
				}
				if (m_reversed == true)
				{
					if (m_currPlayer == 1)
					{
						for (int loop = 0; loop < 2; loop++)
						{
							if (m_Deck.IsEmpty())
							{
								ReShuffle();
							}
							m_Deck.Draw(temp);
							m_Computers[3].AddCard(temp);
						}
					}
					if (m_currPlayer == 2)
					{
						for (int loop = 0; loop < 2; loop++)
						{
							if (m_Deck.IsEmpty())
							{
								ReShuffle();
							}
							m_Deck.Draw(temp);
							m_Real.AddCard(temp);
						}
					}
					if (m_currPlayer == 3)
					{
						for (int loop = 0; loop < 2; loop++)
						{
							if (m_Deck.IsEmpty())
							{
								ReShuffle();
							}
							m_Deck.Draw(temp);
							m_Computers[0].AddCard(temp);
						}
					}
					if (m_currPlayer == 3)
					{
						for (int loop = 0; loop < 2; loop++)
						{
							if (m_Deck.IsEmpty())
							{
								ReShuffle();
							}
							m_Deck.Draw(temp);
							m_Computers[1].AddCard(temp);
						}
					}
				}
			}
			if (_card.GetFace() == 14)
			{
				if (m_reversed == false)
				{
					if (m_currPlayer == 1)
					{
						for (int loop = 0; loop < 4; loop++)
						{
							if (m_Deck.IsEmpty())
							{
								ReShuffle();
							}
							m_Deck.Draw(temp);
							m_Computers[0].AddCard(temp);
						}
					}
					if (m_currPlayer == 2)
					{
						for (int loop = 0; loop < 4; loop++)
						{
							if (m_Deck.IsEmpty())
							{
								ReShuffle();
							}
							m_Deck.Draw(temp);
							m_Computers[1].AddCard(temp);
						}
					}
					if (m_currPlayer == 3)
					{
						for (int loop = 0; loop < 4; loop++)
						{
							if (m_Deck.IsEmpty())
							{
								ReShuffle();
							}
							m_Deck.Draw(temp);
							m_Computers[2].AddCard(temp);
						}
					}
					if (m_currPlayer == 3)
					{
						for (int loop = 0; loop < 4; loop++)
						{
							if (m_Deck.IsEmpty())
							{
								ReShuffle();
							}
							m_Deck.Draw(temp);
							m_Real.AddCard(temp);
						}
					}
				}
				if (m_reversed == true)
				{
					if (m_currPlayer == 1)
					{
						for (int loop = 0; loop < 4; loop++)
						{
							if (m_Deck.IsEmpty())
							{
								ReShuffle();
							}
							m_Deck.Draw(temp);
							m_Computers[3].AddCard(temp);
						}
					}
					if (m_currPlayer == 2)
					{
						for (int loop = 0; loop < 4; loop++)
						{
							if (m_Deck.IsEmpty())
							{
								ReShuffle();
							}
							m_Deck.Draw(temp);
							m_Real.AddCard(temp);
						}
					}
					if (m_currPlayer == 3)
					{
						for (int loop = 0; loop < 4; loop++)
						{
							if (m_Deck.IsEmpty())
							{
								ReShuffle();
							}
							m_Deck.Draw(temp);
							m_Computers[0].AddCard(temp);
						}
					}
					if (m_currPlayer == 3)
					{
						for (int loop = 0; loop < 4; loop++)
						{
							if (m_Deck.IsEmpty())
							{
								ReShuffle();
							}
							m_Deck.Draw(temp);
							m_Computers[1].AddCard(temp);
						}
					}
				}
			}
			display();
			Console::ForegroundColor(Green);
			cout << _player.GetName(); Console::ResetColor(); cout << " Has Won the round!\n";
			m_state = GAME_END;
			//system("pause");
			Sleep(SLEEP);
			points(m_Real, _player);
			for (int loop = 0; loop < 3; loop++)
			points(m_Computers[loop], _player);
			break;

		}
		else if (_player.GetNumCards() == 1)
		{
			Console::ForegroundColor(Yellow);
			cout << _player.GetName(); Console::ResetColor(); cout << " says UNO\n";
			//system("pause");
			Sleep(SLEEP);
			break;
		}
	}
	
}
void Game::Wild(Card& _card)
{
	char buffer;
	if (_card.GetFace() == 13)
	{
		Start:
		cout << "What suit would you like to set B , Y , R , G : ";
		cin >> buffer;

		if (toupper(buffer) == 'B')
		{
			_card.SetSuit('B');
			
		}
		else if (toupper(buffer) == 'Y')
		{
			
			_card.SetSuit('Y');
			
		}
		else if (toupper(buffer) == 'G')
		{
			_card.SetSuit('G');
			
		}
		else if (toupper(buffer) == 'R')
		{
			_card.SetSuit('R');
			
		}
		else
		{
			cout << "Only B Y R G!\n";
			goto Start;
		}
		
	}
	
}
void Game::Wild4(Card& _card)
{
	char buffer;
	if (_card.GetFace() == 14)
	{
	Start:
		cout << "What suit would you like to set B , Y , R , G : ";
		cin >> buffer;

		if (toupper(buffer) == 'B')
		{
			_card.SetSuit('B');

		}
		else if (toupper(buffer) == 'Y')
		{

			_card.SetSuit('Y');

		}
		else if (toupper(buffer) == 'G')
		{
			_card.SetSuit('G');

		}
		else if (toupper(buffer) == 'R')
		{
			_card.SetSuit('R');

		}
		else
		{
			cout << "Only B Y R G!\n";
			goto Start;
		}
		m_Draw4 = true;
	}
}
void Game::Reverse(Card& _card)
{
	if (_card.GetFace() == 11)
	{
		Console::ForegroundColor(Yellow);
		cout << "Game has been reversed!\n";
		Console::ResetColor();
		//system("pause");
		if (m_reversed == true)
			m_reversed = false;
		else
			m_reversed = true;
		
	}
}
void Game::WildCom(Card& _card)
{
	if (_card.GetFace() == 13)
	{
		char pick[4];
		int x = 0;
		pick[0] = 'B';
		pick[1] = 'R';
		pick[2] = 'Y';
		pick[3] = 'G';
		x = rand() % 4;
		_card.SetSuit(pick[x]);
		if (x == 0)
			Console::ForegroundColor(Blue);
		else if (x == 1)
			Console::ForegroundColor(Red);
		else if (x == 2)
			Console::ForegroundColor(DarkYellow);
		else if (x == 3)
			Console::ForegroundColor(Green);
		cout << "picked  " << pick[x] << " for the suit!\n";
		//system("pause");
		Console::ResetColor();
		
	}
	
}
void Game::Wild4Com(Card & _card)
{
	if (_card.GetFace() == 14)
	{
		char pick[4];
		int x = 0;
		pick[0] = 'B';
		pick[1] = 'R';
		pick[2] = 'Y';
		pick[3] = 'G';
		x = rand() % 4;
		_card.SetSuit(pick[x]);
		if (x == 0)
			Console::ForegroundColor(Blue);
		else if (x == 1)
			Console::ForegroundColor(Red);
		else if (x == 2)
			Console::ForegroundColor(DarkYellow);
		else if (x == 3)
			Console::ForegroundColor(Green);
		cout << "picked  " << pick[x] << " for the suit!\n";
		//system("pause");
		Console::ResetColor();
		m_Draw4 = true;
	}
	
}
void Game::ReShuffle()
{
	Console::ForegroundColor(Yellow);
	cout << "Discard pile is being reshuffled!\n";
	Console::ResetColor();
		system("pause");
	m_Discard.Draw(top);
	for (int loop = 0; loop < m_Discard.GetCurrSize(); loop++)
	{
		m_Discard.Draw(change);
		m_Deck.Push(change);

	}
	m_Deck.ReShuffle();
	m_Discard.Push(top);
	display();
}
void Game::points(Player& _player, Player& _Winner)
{
	if (_player.GetNumCards() != 0)
	{
		for (int loop = 0; loop < _player.GetNumCards(); loop++)
		{
			_player.GetCard(loop, temp);
			if (temp.GetFace() >= 0 && temp.GetFace() <= 9)
			{
				_Winner.AddToScore(temp.GetFace());
			}
			else if (temp.GetFace() >= 10 && temp.GetFace() <= 12)
			{
				_Winner.AddToScore(20);
			}
			else if (temp.GetFace() == 13 || temp.GetFace() == 14)
			{
				_Winner.AddToScore(50);
			}
		}
	}
}
bool Game::Winner()
{
	if (m_Real.GetScore() >= 500)
	{
		return true;
	}
	else if (m_Computers[0].GetScore() >= 500)
	{
		return true;
	}
	else if (m_Computers[1].GetScore() >= 500)
	{
		return true;
	}
	else if (m_Computers[2].GetScore() >= 500)
	{
		return true;
	}
	else
		return false;
}
void Game::intro()
{

	Console::BackgroundColor(Green);
	Console::ForegroundColor(Black);
	cout << "                           ___                   \n";
	cout << "        |    |   |\\   |   |   |                  \n";
	Console::BackgroundColor(Yellow);
	cout << "        |    |   | \\  |   |   |                  \n";
	cout << "        |    |   |  \\ |   |   |                  \n";
	Console::BackgroundColor(Red);
	cout << "        |____|   |   \\|   |___|                  \n";
	cout << "                                                 \n";
	Console::BackgroundColor(Blue);
	cout << "                                                 \n";
	cout << "0 1 2 3 4 5 6 7 8 9 S R D2 W W4                  \n";
	Console::ResetColor();
}
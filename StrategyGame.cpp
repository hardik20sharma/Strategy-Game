#include<bits/stdc++.h>
#include "board.h"
using namespace std;

int main()
{
    Game game;
    
    string userInput;
    
    cout<<"player1 Input: ";
    for(int i = 0; i < 5; i++)
    {
        cin >> userInput;
        game.addPlayer("A", userInput, 4, i);
    }

    cout<<"Player2 Input: ";
    for(int i = 0; i < 5; i++)
    {
        cin >> userInput;
        game.addPlayer("B", userInput, 0, i);
    }

    game.displayBoard();

    bool playerA_playing = true;

    while(true)
    {
        if(playerA_playing)
        {
            cout << "Player A's Move: "; cin >> userInput;

            if(game.movePlayer("A", userInput.substr(0, 2), userInput.substr(3) ) == 1)
                playerA_playing = !playerA_playing;

            cout << "Current Grid:" << endl;
            game.displayBoard();
        }
        else
        {
            cout << "Player B's Move: "; cin >> userInput;

            if(game.movePlayer("B", userInput.substr(0, 2), userInput.substr(3) )  == 1)
                playerA_playing = !playerA_playing;

            cout << "Current Grid:" << endl;
            game.displayBoard();
        }
    }

    return 0;
}
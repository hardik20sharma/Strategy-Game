#include<bits/stdc++.h>
using namespace std;

class P
{
    bool isMovePossible(vector<vector<string>> &board, string player, string move)
    {
        if(curr_x == 100 || curr_y == 100)
            return false;

        if (move == "F" && (curr_x == 0 || board[curr_x - 1][curr_y][0] == player[0]) )
            return false;
        
        if( move == "B" && (curr_x == 4 || board[curr_x + 1][curr_y][0] == player[0]) )
            return false;

        if (move == "L" && (curr_y == 0 || board[curr_x][curr_y - 1][0] == player[0]) )
            return false;
        
        if( move == "R" && (curr_y == 4 || board[curr_x][curr_y + 1][0] == player[0]) )
            return false;

        return true;
    }

public:
    int curr_x, curr_y;

    int move(vector<vector<string>> &board, string player, string move)
    {
        if(isMovePossible(board, player, move) == false)
            return -1;
        
        // If res is 1, that means we don't have to remove any player. If its 100, that means we have to remove a player
        int res = 1;

        if (move == "F")
        {
            if(board[curr_x - 1][curr_y] != "-")
            {
                // Remove the other player
                res = 100;
            }

            board[curr_x - 1][curr_y] = board[curr_x][curr_y];
            curr_x--;
        }

        else if (move == "B")
        {
            if(board[curr_x + 1][curr_y] != "-")
            {
                // Remove the other player
                res = 100;
            }

            board[curr_x + 1][curr_y] = board[curr_x][curr_y];
            curr_x++;
        }

        else if (move == "L")
        {
            if(board[curr_x][curr_y - 1] != "-")
            {
                // Remove the other player
                res = 100;
            }

            board[curr_x][curr_y - 1] = board[curr_x][curr_y];
            curr_y--;
        }

        else if (move == "R")
        {
            if(board[curr_x][curr_y + 1] != "-")
            {
                // Remove the other player
                res = 100;
            }

            board[curr_x][curr_y + 1] = board[curr_x][curr_y];
            curr_y++;
        }

        board[curr_x][curr_y] = "-";

        return res;
    }
};

class Game
{
    vector<vector<string>> board;
    vector<P> playerA, playerB;

public:
    Game()
    {
        board.resize(5, vector<string> (5, "-") );

        playerA.resize(5);
        playerB.resize(5);
    }

    void displayBoard()
    {
        for(int i = 0; i < board.size(); i++, cout << endl)
            for(int j = 0; j < board[i].size(); j++)
                cout << board[i][j] << " \t ";
        
        cout << endl << endl;
    }

    void addPlayer(string player, string p, int x, int y)
    {
        if(player == "A")
        {
            board[x][y] = "A-" + p;
            
            int index = p[1] - '1';
            playerA[index].curr_x = x;
            playerA[index].curr_y = y;
        }
        else
        {
            board[x][y] = "B-" + p;

            int index = p[1] - '1';
            playerB[index].curr_x = x;
            playerB[index].curr_y = y;
        }
    }

    int movePlayer(string player, string p, string move)
    {
        if(player == "A")
        {
            int res = playerA[ (p[1] - '1') ].move(board, player, move);
            
            if( res == 100 )    // This means we gotta remove opposite player
            {
                int x = playerA[ (p[1] - '1') ].curr_x;
                int y = playerA[ (p[1] - '1') ].curr_y;

                if(move == "F")
                    x--;
                else if(move == "B")
                    x++;
                else if(move == "L")
                    y--;
                else if(move == "R")
                    y++;
                
                int opp_char = board[x][y][ board[x][y].size() - 1 ] - '1';
                playerB[opp_char].curr_x = 100;
                playerB[opp_char].curr_y = 100;

                res = 1;
            }

            return res;
        }
        else
        {
            int res = playerB[ (p[1] - '1') ].move(board, player, move);

            if( res == 100 )    // This means we gotta remove opposite player
            {
                int x = playerB[ (p[1] - '1') ].curr_x;
                int y = playerB[ (p[1] - '1') ].curr_y;

                if(move == "F")
                    x--;
                else if(move == "B")
                    x++;
                else if(move == "L")
                    y--;
                else if(move == "R")
                    y++;
                
                int opp_char = board[x][y][board[x][y].size() - 1] - '1';
                playerA[opp_char].curr_x = 100;
                playerA[opp_char].curr_y = 100;

                res = 1;
            }

            return res;
        }
    }
};
//
//  main.cpp
//  CPP-PRG-11-06-Soccer-Scores
//
//  Created by Keith Smith on 11/7/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  Write a program that stores the following data about a soccer player in a structure:
//
//      Player's Name
//      Player's Number
//      Points Scored by Player
//
//  The program should keep an array of 12 of these structures. Each element is for a different
//  player on a team. When the program runs, it should ask the user to enter the data
//  for each player. It should then show a table that lists each player's number, name, and
//  points scored. The program should also calculate and display the total points earned by
//  the team. The number and name of the player who has earned the most points should
//  also be displayed.
//
//  Input Validation: Do not accept negative values for players' numbers or points scored.
//

#include <iostream>

using namespace std;

struct StcPlayerInfo
{
    string strPlayerName = "null";
    int intPlayerNumber = 0;
    int intPointsScored = 0;
};

struct StcTeamInfo
{
    int intTotalPoints;
    string strPlayerName;
    int intPlayerNumber;
    int intHighestPoints;
};

StcPlayerInfo *getPlayerInfo(StcPlayerInfo *, int);
StcTeamInfo *calculateTeamInfo(StcPlayerInfo *, int);
void displayInfo(StcPlayerInfo *, StcTeamInfo *, int);

int main()
{
    const int INT_NUM_PLAYERS = 3;
    
    StcPlayerInfo *spiPlayersTeam = nullptr;
    spiPlayersTeam = new StcPlayerInfo[INT_NUM_PLAYERS];
    
    StcTeamInfo *stiTeamInfo = nullptr;
    stiTeamInfo = new StcTeamInfo;
    
    for (int i = 0 ; i < INT_NUM_PLAYERS ; i++)
    {
        spiPlayersTeam[i] = *getPlayerInfo(spiPlayersTeam, INT_NUM_PLAYERS);
    }
    
    stiTeamInfo = calculateTeamInfo(spiPlayersTeam, INT_NUM_PLAYERS);
    
    displayInfo(spiPlayersTeam, stiTeamInfo, INT_NUM_PLAYERS);
    
    return 0;
}

StcPlayerInfo *getPlayerInfo(StcPlayerInfo *spiPlayers, int INT_SIZE)
{
    StcPlayerInfo *spiPlayer = nullptr;
    spiPlayer = new StcPlayerInfo;
    
    cout << "Enter the player's name: ";
    cin.clear();
    cin.ignore();
    getline(cin, spiPlayer->strPlayerName);
    
    cout << "Enter the player's number: ";
    cin.clear();
    cin.ignore();
    cin >> spiPlayer->intPlayerNumber;
    while(!cin || spiPlayer->intPlayerNumber <= 0 || spiPlayer->intPlayerNumber >= 100)
    {
        cout << "Please enter a player number between 1 and 99: ";
        cin.clear();
        cin.ignore();
        cin >> spiPlayer->intPlayerNumber;
    }
    for (int i = 0 ; i < INT_SIZE ; i++)
    {
        while (spiPlayer->intPlayerNumber == spiPlayers[i].intPlayerNumber)
        {
            cout << "That number has already been selected: ";
            cin.clear();
            cin.ignore();
            cin >> spiPlayer->intPlayerNumber;
            while(!cin || spiPlayer->intPlayerNumber <= 0 || spiPlayer->intPlayerNumber >= 100)
            {
                cout << "Please enter a player number between 1 and 99: ";
                cin.clear();
                cin.ignore();
                cin >> spiPlayer->intPlayerNumber;
            }
        }
    }
    
    cout << "Enter the points score by this player: ";
    cin.clear();
    cin.ignore();
    cin >> spiPlayer->intPointsScored;
    while(!cin || spiPlayer->intPointsScored < 0 || spiPlayer->intPointsScored > 20)
    {
        cout << "Please enter a player number between 0 and 20: ";
        cin.clear();
        cin.ignore();
        cin >> spiPlayer->intPointsScored;
    }
    
    return spiPlayer;
}

StcTeamInfo *calculateTeamInfo(StcPlayerInfo *spiPlayers, int INT_PLAYERS)
{
    StcTeamInfo *stiTeamStats = nullptr;
    stiTeamStats = new StcTeamInfo;
    
    stiTeamStats->intHighestPoints = INT_MIN;
    
    for (int i = 0 ; i < INT_PLAYERS ; i++)
    {
        stiTeamStats->intTotalPoints += spiPlayers[i].intPointsScored;
        
        if (spiPlayers[i].intPointsScored > stiTeamStats->intHighestPoints)
        {
            stiTeamStats->intHighestPoints = spiPlayers[i].intPointsScored;
            stiTeamStats->strPlayerName = spiPlayers[i].strPlayerName;
            stiTeamStats->intPlayerNumber = spiPlayers[i].intPlayerNumber;
        }
    }
    
    return stiTeamStats;
}

void displayInfo(StcPlayerInfo *spiPlayers, StcTeamInfo *stiTeam, int INT_SIZE)
{
    cout << "\nHere is the team's information:\n\n";
    
    for (int i = 0 ; i < INT_SIZE ; i++)
    {
        cout << "\t\tPlayer #" << (i + 1) << "\'s name: ";
        cout << spiPlayers[i].strPlayerName << endl;
        
        cout << "\t\tPlayer #" << (i + 1) << "\'s number: ";
        cout << spiPlayers[i].intPlayerNumber << endl;
        
        cout << "\t\tPlayer #" << (i + 1) << "\'s points scored: ";
        cout << spiPlayers[i].intPointsScored << endl << endl;
    }
    
    cout << "\t\tTeam's total score: " << stiTeam->intTotalPoints << endl;
    cout << "\n\t\tHighest scoring player: " << stiTeam->strPlayerName << endl;
    cout << "\t\tHighest scoring player's number: " << stiTeam->intPlayerNumber << endl;
    cout << "\t\tHighest player's score: " << stiTeam->intHighestPoints << endl << endl;
}

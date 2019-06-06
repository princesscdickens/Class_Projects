// CS1300 Spring 2019
// Author: Princess Dickens
// Recitation: 207 - Shipra Behera
// Cloud9 Workspace Editor Link: https://ide.c9.io/pdickens/csci1300_pdickens
// Project 3

// Game of Thrones Game driver

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include "Game.h"
using namespace std;

////////////////////////////////////////////////////////////////////////////////
/////////                   CLASS DEFINITIONS                            ////////
////////////////////////////////////////////////////////////////////////////////

// Hero
// Warrior
// City
// Place
// Game

////////////////////////////////////////////////////////////////////////////////
/////////                   OTHER FUNCTIONS                             ////////
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/////////                   MENUS                                       ////////
////////////////////////////////////////////////////////////////////////////////
void heroesMenu()
{
    cout << "By what name shall Your Grace be called?: " << endl;
    cout << "1. Cersei Lannister " << endl;
    cout << "2. Stannis Baratheon " << endl;
    cout << "3. Jon Snow " << endl;
    cout << "4. Sansa Stark " << endl;
    cout << "5. Euron Greyjoy " << endl;
    cout << "6. Daenerys Targaryen " << endl;
}

void encounterMenu()
{
	cout << "How would Your Grace wish to proceed?: " << endl;
	cout << "1. Give a speech " << endl;
	cout << "2. Buy them outright " << endl;
	cout << "3. Battle " << endl;
}
////////////////////////////////////////////////////////////////////////////////
/////////                                                               ////////
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/////////                   DRIVER                                      ////////
////////////////////////////////////////////////////////////////////////////////

int main(int argc, char const *argv[]) 
{
    // temp variables
    string choice;
    Game game1;
        
    //Create Game object --> .txt files initialized inside of here.
    game1.loadFiles(); // will load .txt files for map, heroes, warriors, cities
    
    //Start GAME
    cout << "When You Play The Game of Thrones..."; //how do I center this text?*********************
        
    usleep(1000000);
    cout << " You Win Or You Die" << endl << endl;
    usleep(1000000);
    game1.printBigMap();

    cout << endl;
    usleep(1000000);
    cout << "Welcome to the  G  A  M  E   of   T  H  R  O  N  E  S" << endl;
    usleep(1000000);
    cout << "State your name, Your Grace: ";
    string userName;
    getline(cin, userName);
    game1.setPlayerUsername(userName);
    bool hasChosenHero = false;
    while(hasChosenHero == false)
    {
        cout << "Would you like to choose a hero " << userName << ", Your Grace? (Y/N):" << endl;
        string chooseHero;
        getline(cin, chooseHero);
        if(chooseHero == "Y" || chooseHero == "y")
        {
            string heroChoice;
            heroesMenu(); //prints choices of 6 Heroes
            getline(cin, heroChoice);
            int heroChoiceNumber = stoi(heroChoice);
            int result1 = game1.setPlayerHero(heroChoiceNumber);
            if(result1 == 1)
            {
                hasChosenHero = true;
            }
        }
        else if(chooseHero == "N" || chooseHero == "n")
        {
            string wantShip;
            bool hasMadeHero = false;
            bool playerGetsShip;
            cout << "Your Grace " << userName << ", you have chosen to go on this journey alone." << endl;
            usleep(1000000);
            cout << "Please provide starting values for your adventure." << endl;
                
            while(hasMadeHero == false)
            {
                cout << "Money (0-10000): ";
                string money;
                getline(cin, money);
                while(stoi(money) < 0 || stoi(money) > 10000)
                {
                        cout << "Please provide a valid starting amount for money." << endl;
                        cout << "Money (0-10000): ";
                        getline(cin, money);
                    }
                cout << "Influence (0-10000): ";
                string influence;
                getline(cin, influence);
                while(stoi(influence) < 0 || stoi(influence) > 10000)
                {
                        cout << "Please provide a valid starting amount for influence." << endl;
                        cout << "Influence (0-10000): ";
                        getline(cin, influence);
                    }
                cout << "Army Size (0-10000): ";
                string army;
                getline(cin, army);
                while(stoi(army) < 0 || stoi(army) > 10000)
                {
                        cout << "Please provide a valid starting amount for army size." << endl;
                        cout << "Army Size (0-10000): ";
                        getline(cin, army);
                    }
                bool decisionMadeForShip = false;
                while(decisionMadeForShip == false)
                {
                    cout << "Would you like to start with a ship?(Y/N): ";
                    getline(cin, wantShip);
                    if(wantShip == "Y" || wantShip == "y")
                    {
                        playerGetsShip = true;
                        decisionMadeForShip = true;
                    }
                    else if(wantShip == "N" || wantShip == "n")
                    {
                        playerGetsShip = false;
                        decisionMadeForShip = true;
                    }
                    else
                    {
                        cout << "Please say yes (Y) or no (N)." << endl;
                    }
                }
                //make hero
                ////<Name>,<$>,<influence>,<army_size>,<w1>,<w2>,<w3>,<w4>,<r>,<c>,<ship>
                //Hero::Hero(string inputName, int inputMoney, int inputInfluence, int inputArmySize, int inputNumWarriors, bool inputHasShip)
                Hero hero1(userName, stoi(money), stoi(influence), stoi(army), 0, playerGetsShip); //parameterized construction for Hero
                game1.setMadePlayerHero(hero1);
                hasMadeHero = true;
                hasChosenHero = true;
            }
        }
    }
    game1.setIsPlayerTurn(true);
    while(game1.getWonOrLost() == "")
    {
        while(game1.getIsPlayerTurn() == true && game1.getWonOrLost() == "") //while it's the player's turn 
        {
            cout << endl << "It's the player's turn" << endl;
            game1.playersTurn(); 
            // Asks if player wants to 1)Travel 2)Rest or 3)Consult gods
            // Updates location, strength(W), and morale(W)
            // Checks for City to acquire points(H), Warrior(H), and armySize(H)
            // flips isPlayersTurn to FALSE at the end
        }
        while(game1.getIsPlayerTurn() == false && game1.getWonOrLost() == "") //while it's the computer's turn
        {
            cout << endl << "It's the computer's turn now" << endl << endl;
            // Checks for nearby Hero for ENCOUNTER
            string result3 = game1.checkForEncounter(); //returns a string, name of the Hero who is near
            if(result3 != "no encounter") //if there IS an encounter
            {
                cout << endl << "WHO GOES THERE? SHOW YOURSELF!" << endl;
    	        cout << "There appears to be someone lurking nearby." << endl;
    	        usleep(1000000);
    	        cout << "It's... " << result3 << "!!" << endl << endl;
                bool hasChosenEncounter = false;
                while(hasChosenEncounter == false)
                {
                    //      --> Gives option for A)Give speech B)Buy them outright and C)Battle 
                    //      --> Updates values according to outcome
                    encounterMenu(); // gives choices a) speech, b) buy outright or c) battle
                    string choiceEncounter;
                    getline(cin, choiceEncounter); //check for valid input
                    if(stoi(choiceEncounter) == 1 || stoi(choiceEncounter) == 2 || stoi(choiceEncounter) == 3)
                    {
                        //computerTurn(result3, int getChoiceEncounter); //heroes[i].getNameHero OR "no encounter"
                        // later, random event is decided and realized inside computerTurn()
                        game1.computerTurn(result3, stoi(choiceEncounter));
                        hasChosenEncounter = true;
                        //check for White Walkers
                        //set playerTurn to TRUE
                    }
                }
            }
            else if(result3 == "no encounter") //no encounter
            {
                game1.computerTurn(result3, 4); 
            }
        }
    }
    game1.printScoreBoard();
}
// CS1300 Spring 2019
// Author: Princess Dickens
// Recitation: 207 - Shipra Behera
// Cloud9 Workspace Editor Link: https://ide.c9.io/pdickens/csci1300_pdickens
// Project 3

// game class header

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>
#include <math.h>
#include <bits/stdc++.h> 
#include <algorithm> 

#include "Hero.h"
#include "Warrior.h" 
#include "City.h"
#include "Place.h"
#include "Playerscore.h"

using namespace std;

class Game
{
    private:
    char bigMap[25][16];
    City cities[26];
    Place places[25][16]; //contains bool for which tiles Player controls and City objects
    Warrior warriors[14];
    vector<Hero> heroes;
    Hero playerHero[1]; //the Hero the User chooses 
    vector<Playerscore> scoreBoard; //vector of scores for Game Over printing
    
    string playerUsername;
    int pointsTotal;
    int turnCounter;
    int tilesControlled;
    bool playerHasDragonglass;
    
    bool isPlayersTurn; 
    string wonOrLost;
    int timesDeniedWhiteWalkerBattle;
    
    //trigger White Walker battle
    bool whiteWalkersComing;

////////////////////////////////////////////////////////////////////////////////
    public:
    Game();
    Game(string inputPlayerUsername);
    
    // Game class setters
    void setPlayerUsername(string inputPlayerUsername);
    int setPlayerHero(int numHero);
    int setMadePlayerHero(Hero nameHero);
    void setPointsTotal(int inputPoints);
    void setTurns(int inputTurnCount); //turn counter
    void setTilesControlled(int inputTiles);
    void setPlayerDragonglass(bool inputPlayerDragonglass);
    void setWinOrLose(string setOutcome);
    
    // Game class getters
    string getPlayerUsername();
    string getPlayerHero();
    int getPointsTotal();
    int getTurns(); //turn counter
    
    //bool getPlayerHasBeenHere(int row, int column); add this
    int getTilesControlled();
    bool getPlayerDragonglass();
    
//////////// Initialization functions --> Can these be consolidated?  //////////
    void loadFiles();
    void loadMap(); 
    void loadHeroes(); 
    Warrior getWarriorByName(string warriorName);
    void addExtraHero(Hero inputHeroHere); //for if player choose to make their own
    void loadWarriors(); 
    void loadCities(); 
    void loadPlaces();
    int split(string stringToBeSplit, char delimiter, char newArray[16], int lengthNewArray);
    void setAllOwnedWarriorLocations();
    
    void printBigMap(); 
    void printSmallMap(); 
    // void printHeroes(heroes); 
    // void printWarriors(warriors); 
    // void printCities(cities); 
    
////////////  Turn functions  //////////////////////////////////////////////////
    void setIsPlayerTurn(bool inputIsPlayerTurn);
    bool getIsPlayerTurn();
    void playersTurn();
    void turnMenu();
    bool checkIfValidTilePlayer(string inputDirection); //updates location
    void computerTurn(string nameHeroEncounter, int getChoiceEncounter); // resolves encounter
    bool checkIfValidTileCharacter(); //more generic for ANY HERO or WARRIOR

    string checkForEncounter(); //after playerHero and all other characters' locations have been updated 
    int checkForFreeWarrior(); //return index of free Warrior from warriors[14] --> addOwnedWarrior(Warrior warriorObject);
    void setIsGameWarriorFree(int indexFreeWarriorNear);
    bool getIsGameWarriorFree(int indexFreeWarriorNear);
    int checkIfInCity(); // returns index of City in the places[26] array --> acquire armySize and points 
    int checkIfInCityOtherHeroes(int indexHero);
    int getPointsCity(char letterCity);

    void setWhiteWalkersComing();
    void setFiftyTurnsCompleted(bool inputResult);
    void setArmySizeOver2000(bool inputResult);
    void setPlayerControls200Tiles(bool inputResult);
    void setPlayerHas400Points(bool inputResult);
    void setPlayerIsOnlyHeroLeft(bool inputResult);
    
    bool getWhiteWalkersAreComing();
    
    // Game Over functions
    void whiteWalkerBattle();
    void setTimesDeniedWhiteWalkerBattle(int inputTimes);
    int getTimesDeniedWhiteWalkerBattle();
    void setWonOrLost(string inputWinOrLose);
    string getWonOrLost();
    void writeToScoreBoard(); //after Game Over, writes player's stats to a .txt file // <username> <Hero> <points score> <won or lost>
    void printScoreBoard();
};

#endif
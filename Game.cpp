// CS1300 Spring 2019
// Author: Princess Dickens
// Recitation: 207 - Shipra Behera
// Cloud9 Workspace Editor Link: https://ide.c9.io/pdickens/csci1300_pdickens
// Project 3

// game implementation

#include "Game.h"

using namespace std;

    // private:
    // char bigMap[25][16];
    // City cities[26];
    // Place places[25][16]; //contains bool for which tiles Player controls and City objects
    // Warrior warriors[14];
    // vector<Hero> heroes;
    // Hero playerHero[1]; //the Hero the User chooses 
    
    // string playerUsername;
    // int pointsTotal;
    // int turnCounter;
    // int tilesControlled;
    // bool playerHasDragonglass;
    
    // bool isPlayersTurn; //add this??
    // string wonOrLost;
    // int timesDeniedWhiteWalkerBattle;
    
    // //trigger White Walker battle
    // bool whiteWalkersComing;
    // bool fiftyTurnsCompleted;
    // bool armySizeOver2000;
    // bool playerControls200Tiles;
    // bool playerHas400Points;
    // bool playerIsOnlyHeroLeft;
 
Game::Game()
{
    playerUsername = "";
    pointsTotal = 0;
    turnCounter = 0;
    tilesControlled = 0;
    playerHasDragonglass = false;
    
    isPlayersTurn = false;
    wonOrLost = ""; //will get printed to final scoreboard
    timesDeniedWhiteWalkerBattle = 0;
    
    whiteWalkersComing = false;
}

Game::Game(string inputPlayerUsername)
{
    playerUsername = inputPlayerUsername;
    pointsTotal = 0;
    turnCounter = 0;
    tilesControlled = 0;
    playerHasDragonglass = false;
    
    isPlayersTurn = false;
    wonOrLost = ""; //will get printed to final scoreboard
    timesDeniedWhiteWalkerBattle = 0;
    
    whiteWalkersComing = false;
}
    
////////// setters ///////////////////////////////////////////////////////////////////
void Game::setPlayerUsername(string inputPlayerUsername)
{
    playerUsername = inputPlayerUsername;
}

int Game::setPlayerHero(int numHero)
{
    int successfullySetHero = 0;
    switch(numHero)
    {
        case 1:
        {
            for(int i = 0; i < heroes.size(); i++) //iterate through the Heroes vector
            {
                if(heroes[i].getNameHero() == "Cersei Lannister")
                {
                    playerHero[0] = heroes[i]; //set player's Hero to be Cersei Lannister
                    successfullySetHero = 1;
                }
            }
            break; 
        }
        case 2:
        {
            for(int i = 0; i < heroes.size(); i++) //iterate through the Heroes vector
            {
                if(heroes[i].getNameHero() == "Stannis Baratheon")
                {
                    playerHero[0] = heroes[i]; //set player's Hero to be Stannis Baratheon
                    successfullySetHero = 1;
                }
            }
            break; 
        }
        case 3:
        {
            for(int i = 0; i < heroes.size(); i++) //iterate through the Heroes vector
            {
                if(heroes[i].getNameHero() == "Jon Snow")
                {
                    playerHero[0] = heroes[i]; //set player's Hero to be Jon Snow
                    successfullySetHero = 1;
                }
            }
            break; 
        }
        case 4:
        {
            for(int i = 0; i < heroes.size(); i++) //iterate through the Heroes vector
            {
                if(heroes[i].getNameHero() == "Sansa Stark")
                {
                    playerHero[0] = heroes[i]; //set player's Hero to be Sansa Stark
                    successfullySetHero = 1;
                }
            }
            break; 
        }
        case 5:
        {
            for(int i = 0; i < heroes.size(); i++) //iterate through the Heroes vector
            {
                if(heroes[i].getNameHero() == "Euron Greyjoy")
                {
                    playerHero[0] = heroes[i]; //set player's Hero to be Euron Greyjoy
                    successfullySetHero = 1;
                }
            }
            break; 
        }
        case 6:
        {
            for(int i = 0; i < heroes.size(); i++) //iterate through the Heroes vector
            {
                if(heroes[i].getNameHero() == "Daenerys Targaryen")
                {
                    playerHero[0] = heroes[i]; //set player's Hero to be Daenerys Targaryen
                    successfullySetHero = 1;
                }
            }
            break; 
        }
        default:
        {
            successfullySetHero = 0;
            break;
        }
    }
    return successfullySetHero;
}

int Game::setMadePlayerHero(Hero nameHero)
{
    playerHero[0] = nameHero;
    return 1;
}

void Game::setPointsTotal(int inputPoints)
{
    pointsTotal = pointsTotal + inputPoints;
}

void Game::setTurns(int inputTurnCount) //turn counter
{
    turnCounter = turnCounter + inputTurnCount; //this looks funny
}

void Game::setTilesControlled(int inputTiles)
{
    tilesControlled = tilesControlled + inputTiles;
}

void Game::setPlayerDragonglass(bool inputPlayerDragonglass)
{
    if(inputPlayerDragonglass == true)
    {
        playerHasDragonglass = true;
    }
}
    
////////// getters ///////////////////////////////////////////////////////////////////
string Game::getPlayerUsername()
{
    return playerUsername;
}

string Game::getPlayerHero()
{
    return playerHero[0].getNameHero();
}

int Game::getPointsTotal()
{
    return pointsTotal;
}

int Game::getTurns() //turn counter
{
    return turnCounter;
}

int Game::getTilesControlled()
{
    return tilesControlled;
}

bool Game::getPlayerDragonglass()
{
    return playerHasDragonglass;
}

///////////other functions////////////////////////////////////////////////////////////////////////////
void Game::setIsPlayerTurn(bool inputIsPlayerTurn)
{
    isPlayersTurn = inputIsPlayerTurn;
}

bool Game::getIsPlayerTurn()
{
    return isPlayersTurn;
}

void Game::playersTurn() // can I make this a member function of Game and just call it?
{
    while(getIsPlayerTurn() == true)
    {
        string turnChoice;
        printSmallMap(); //print current location of player at the start of the turn
        bool turnChoiceValid = false;
        while(turnChoiceValid == false)
        {
            turnMenu(); //print Menu from member function Game::turnMenu()
            getline(cin, turnChoice);
            if(turnChoice == "1" || turnChoice == "2" || turnChoice == "3")
            {
                turnChoiceValid = true;
                int turnChoiceInt = stoi(turnChoice);
                switch(turnChoiceInt)
                {
            case 1: //travel
            {
                cout << endl << "Your Grace has chosen to travel.";
                
                string directionChoice;
                bool directionIsValid = false;
                while(directionIsValid == false)
                {
                    cout << " In which direction would Your Grace wish to proceed?(N/E/S/W): ";
                    getline(cin, directionChoice);
                    //check if Hero can travel in that direction --> hasShip = true?, location on the map?
                    bool result = checkIfValidTilePlayer(directionChoice); //location updated inside checkIfValidTile
                    directionIsValid = result;
                }
                cout << endl;
                if(directionIsValid == true) //playerHero's location has already been updated. Need to update all other Heroes and free warriors
                {
                    bool othersDirectionValid = false;
                    while(othersDirectionValid == false) // other Hero and Warrior locations successfully updated?
                    {
                        bool result2 = checkIfValidTileCharacter();
                        othersDirectionValid = result2; // all other Heroes and Warrior locations have been updated
                    }
                }
                /** Update FOR ALL OTHER HEROES   */
                // check for City, free Warriors, buy knight for computer heroes and free warriors??*****************
                
                //setTurns(1); //add 1 turn to the counter --> do THIS during Computer turn
                cout << endl;
                setIsPlayerTurn(false);
                break;
            }
            case 2: //rest
            {
                cout << "Your Grace has chosen to rest. ";
                if(playerHero[0].getOwnedWarriorVectorSize() > 0)
                {
                    playerHero[0].setAllOwnedWarriorsStrength(1);
                    cout << "Your warriors' strength was increased by one." << endl;
                }
                
                bool othersDirectionValid = false;
                while(othersDirectionValid == false) // other Hero and Warrior locations successfully updated?
                {
                    bool result2 = checkIfValidTileCharacter();
                    othersDirectionValid = result2; // all other Heroes and Warrior locations have been updated
                }
                //check for encounter********************
                cout << endl;
                setIsPlayerTurn(false);
                break;
            }
            case 3: //consult the gods
            {
                cout << "Your Grace has chosen to consult the gods. ";
                if(playerHero[0].getOwnedWarriorVectorSize() > 0)
                {
                    playerHero[0].setAllOwnedWarriorsMorale(1);
                    cout << endl << "Your warriors' morale was increased by one." << endl;
                }
                else
                {
                    cout << endl << "You have no warriors. God is not with you." << endl;
                }
                bool othersDirectionValid = false;
                while(othersDirectionValid == false) // other Hero and Warrior locations successfully updated?
                {
                    bool result2 = checkIfValidTileCharacter();
                    othersDirectionValid = result2; // all other Heroes and Warrior locations have been updated
                }
                cout << endl;
                setIsPlayerTurn(false);
                break;
            }
        }
            }
        }
    }
}

void Game::turnMenu()
{
	cout << "How would Your Grace wish to proceed?: " << endl;
	cout << "1. Travel" << endl;
	cout << "2. Rest" << endl;
	cout << "3. Consult with the gods" << endl;
}
  
bool Game::checkIfValidTilePlayer(string inputDirection) //just for Player
{
    int currentRow = playerHero[0].getRowHero();
    int currentColumn = playerHero[0].getColumnHero();
    bool IsDirectionValid = false;
    
    if(inputDirection == "N" || inputDirection == "n") //move NORTH = row - 1
    {
        if(currentRow - 1 < 0) ////////// check if out of bounds ////////
        {
            cout << "Your Grace cannot travel further North at this time. It is your destiny to conquer these lands first." << endl;
        }
        /////////////////////////// check for ship for water tile /////////////////////
        else if(bigMap[currentRow - 1][currentColumn] == 'w' && playerHero[0].doesHeroHaveShip() == false && playerHero[0].getDoesAnyOwnedWarriorHaveShip() == false)
        {
            cout << "Invalid direction. A ship is required for travel on water." << endl;
        }
        else //valid location
        {
            playerHero[0].setRowLocation(currentRow - 1);
            //playerHero[0].setColumnLocation(currentColumn);
            printSmallMap();
            places[currentRow - 1][currentColumn].setHeroControlsTile(true); //owns this tile now
            setTilesControlled(1);
            if(bigMap[playerHero[0].getRowHero()][playerHero[0].getColumnHero()] == 'w')
            {
                // add 1 point
                setPointsTotal(1);
            }
            else if(bigMap[playerHero[0].getRowHero()][playerHero[0].getColumnHero()] == 'p')
            {
                // add 2 points
                setPointsTotal(2);
            }
            //update owned Warrior locations
            playerHero[0].setAllOwnedWarriorLocations();
            // check if playerHero is in City, update points, money, and army
            checkIfInCity();
            IsDirectionValid = true;
        }
    }
    else if(inputDirection == "E" || inputDirection == "e") //move EAST = column + 1
    {
        if(currentColumn + 1 > 15) //check if out of bounds 
        {
            cout << "Your Grace cannot travel further East at this time. It is your destiny to conquer these lands first." << endl;
        }
        else if(bigMap[currentRow][currentColumn + 1] == 'w' && playerHero[0].doesHeroHaveShip() == false && playerHero[0].getDoesAnyOwnedWarriorHaveShip() == false) // check for ship
        {
            cout << "Invalid direction. A ship is required for travel on water." << endl;
        }
        else
        {
            playerHero[0].setRowLocation(currentRow);
            playerHero[0].setColumnLocation(currentColumn + 1);
            printSmallMap();
            places[currentRow][currentColumn + 1] = true; //owns this tile now
            setTilesControlled(1);
            //update points
            if(bigMap[playerHero[0].getRowHero()][playerHero[0].getColumnHero()] == 'w')
            {
                // add 1 point
                setPointsTotal(1);
            }
            else if(bigMap[playerHero[0].getRowHero()][playerHero[0].getColumnHero()] == 'p')
            {
                // add 2 points
                setPointsTotal(2);
            }
            //update owned Warrior locations
            playerHero[0].setAllOwnedWarriorLocations();
            // check if playerHero is in City, update points, money, and army
            checkIfInCity();
            IsDirectionValid = true;
        }
    }
    else if(inputDirection == "S" || inputDirection == "s") //move SOUTH = row + 1
    {
        if(currentRow + 1 > 24) //check if out of bounds 
        {
            cout << "Your Grace cannot travel further South at this time. It is your destiny to conquer these lands first." << endl;
        }
        else if(bigMap[currentRow + 1][currentColumn] == 'w' && playerHero[0].doesHeroHaveShip() == false && playerHero[0].getDoesAnyOwnedWarriorHaveShip() == false) // check for ship
        {
            cout << "Invalid direction. A ship is required for travel on water." << endl;
        }
        else
        {
            playerHero[0].setRowLocation(currentRow + 1);
            playerHero[0].setColumnLocation(currentColumn);
            printSmallMap();
            places[currentRow + 1][currentColumn] = true; //owns this tile now
            setTilesControlled(1);
            //update points
            if(bigMap[playerHero[0].getRowHero()][playerHero[0].getColumnHero()] == 'w')
            {
                // add 1 point
                setPointsTotal(1);
            }
            else if(bigMap[playerHero[0].getRowHero()][playerHero[0].getColumnHero()] == 'p')
            {
                // add 2 points
                setPointsTotal(2);
            }
            //update owned Warrior locations
            playerHero[0].setAllOwnedWarriorLocations();
            // check if playerHero is in City, update points, money, and army
            checkIfInCity();
            IsDirectionValid = true;
        }
    }
    else if(inputDirection == "W" || inputDirection == "w") //move WEST = column - 1
    {
        if(currentColumn - 1 < 0) //check if out of bounds 
        {
            cout << "Your Grace cannot travel further West at this time. It is your destiny to conquer these lands first." << endl;
        }
        else if(bigMap[currentRow][currentColumn - 1] == 'w' && playerHero[0].doesHeroHaveShip() == false  && playerHero[0].getDoesAnyOwnedWarriorHaveShip() == false) // check for ship
        {
            cout << "Invalid direction. A ship is required for travel on water." << endl;
        }
        else
        {
            playerHero[0].setRowLocation(currentRow);
            playerHero[0].setColumnLocation(currentColumn - 1);
            printSmallMap();
            places[currentRow][currentColumn - 1] = true; //owns this tile now
            setTilesControlled(1);
            //update points
            if(bigMap[playerHero[0].getRowHero()][playerHero[0].getColumnHero()] == 'w')
            {
                // add 1 point
                setPointsTotal(1);
            }
            else if(bigMap[playerHero[0].getRowHero()][playerHero[0].getColumnHero()] == 'p')
            {
                // add 2 points
                setPointsTotal(2);
            }
            //update owned Warrior locations
            playerHero[0].setAllOwnedWarriorLocations();
            // check if playerHero is in City, update points, money, and army
            checkIfInCity();
            IsDirectionValid = true;
        }
    }
    else //invalid input
    {
        cout << "North (N) - East (E) - South (S) - West (W)" << endl;
        IsDirectionValid = false;
    }
    return IsDirectionValid;
}

int Game::checkIfInCity() // returns index of City in the places[26] array --> acquire armySize and points
{
    // need to add check to make sure Hero can acquire things only once for each City
    int indexCurrentCity = -1;
    // if player's current location is a CITY
    if(bigMap[playerHero[0].getRowHero()][playerHero[0].getColumnHero()] >= 'A' && bigMap[playerHero[0].getRowHero()][playerHero[0].getColumnHero()] <= 'Z')
    {
        // which city?
        for(int i = 0; i < 26; i++) //iterate through cities array
        {
            if(cities[i].getLetterCity() == bigMap[playerHero[0].getRowHero()][playerHero[0].getColumnHero()])
            {
                indexCurrentCity = i;
                cout << "Your Grace is in the city of " << cities[i].getNameCity() << endl;
                setPointsTotal(cities[i].getPointsCity()); //acquire points from city
                playerHero[0].setMoney(cities[i].getMoneyCity()); //acquire money from city
                cout << "Your Grace has acquired " << cities[i].getPointsCity() << " points"; 
                cout << " and " << cities[i].getMoneyCity() << " in money" << endl;
                
                cout << endl << "You now have $" << playerHero[0].getMoney() << endl;
                bool madeKnightsDecision = false;
                string buyKnights;
                while(madeKnightsDecision == false)
                {
                    cout << "Would you like to purchase up to " << cities[i].getArmySizeCity() << " knights? (Y/N): ";
                    getline(cin, buyKnights);
                    if(buyKnights == "Y" || buyKnights == "y")
                    {
                        bool madeNumberKnightsDecision = false;
                        string howManyKnightsString;
                        while(madeNumberKnightsDecision == false) // need check to make sure input is a number
                        {
                            cout << "How many knights would you like to add to your army? (1 knight = $10): ";
                            getline(cin, howManyKnightsString);
                            bool itsANumber = true;
                            for(int n = 0; n < howManyKnightsString.length(); n++)
                            {
                                if(howManyKnightsString[n] < '0' || howManyKnightsString[n] > '9') //not a number
                                {
                                    itsANumber = false;
                                }
                            }
                            if(itsANumber == true)
                            {
                                if(stoi(howManyKnightsString) <= cities[i].getArmySizeCity() && stoi(howManyKnightsString) * 10 <= playerHero[0].getMoney())
                                {
                                    playerHero[0].setArmySize(stoi(howManyKnightsString)); //acquire knights from city
                                    playerHero[0].setMoney(0 - (stoi(howManyKnightsString) * 10)); //pay for knights 1:1
                                    cout << "You now have " << playerHero[0].getArmySize() << " knights and $" << playerHero[0].getMoney() << endl;
                                    madeNumberKnightsDecision = true;
                                    madeKnightsDecision = true;
                                }
                                else
                                {
                                    cout << "Please give a valid number" << endl;
                                }
                            }
                            else
                            {
                                cout << "Please enter a valid number." << endl;
                            }
                        }
                    }
                    else if(buyKnights == "N" || buyKnights == "n")
                    {
                        madeKnightsDecision = true;
                    }
                    else
                    {
                        cout << "Please say yes (Y) or no (N)." << endl;
                    }
                }
            }
        }
    }
    return indexCurrentCity;
}

int Game::checkIfInCityOtherHeroes(int indexHero)
{
    // need to add check to make sure Hero can acquire things only once for each City
    int indexCurrentCity = -1;
    // if heroe's current location is a CITY
    if(bigMap[heroes[indexHero].getRowHero()][heroes[indexHero].getColumnHero()] >= 'A' && bigMap[heroes[indexHero].getRowHero()][heroes[indexHero].getColumnHero()] <= 'Z')
    {
        // which city?
        for(int i = 0; i < 26; i++) //iterate through cities array
        {
            if(cities[i].getLetterCity() == bigMap[heroes[indexHero].getRowHero()][heroes[indexHero].getColumnHero()])
            {
                indexCurrentCity = i;
                heroes[indexHero].setMoney(cities[i].getMoneyCity()); //acquire money from city
                if(heroes[indexHero].getMoney() > cities[i].getArmySizeCity()) //if hero has enough money to buy knights
                {
                    int amountKnightsToBuy = cities[i].getArmySizeCity() / 2;
                    heroes[indexHero].setArmySize(amountKnightsToBuy); //acquire knights from city
                    heroes[indexHero].setMoney(0 - amountKnightsToBuy); //pay for knights 1:1
                }
            }
        }
    }
    return indexCurrentCity;
}

void Game::computerTurn(string nameHeroEncounter, int getChoiceEncounter) // resolve encounters 
{
    if(nameHeroEncounter != "no encounter") //--> if there IS encounter
    {
        //find Hero by the name provided
        int EnemyHeroIndex;
        for(int i = 0; i < heroes.size(); i++)
        {
            if(heroes[i].getNameHero() == nameHeroEncounter)
            {
                EnemyHeroIndex = i;
            }
        }
        
        //how many warriors does the enemy have?
        int numberUpForGrabs = heroes[EnemyHeroIndex].getOwnedWarriorVectorSize();
        
        if(getChoiceEncounter == 1) //give speech
        {
            cout << "You have chosen to give a speech" << endl << endl;
            double probabilityWinSpeech;
            double firstWarriorsMorale = heroes[EnemyHeroIndex].getFirstWarriorsMorale();
            double playersInfluence = playerHero[0].getInfluence();
            probabilityWinSpeech = ((1 - (firstWarriorsMorale / 100)) * (playersInfluence / 1600));
            if(probabilityWinSpeech <= 0) //Player definitely loses
            {
                cout << endl << "Your speech wasn't very useful. You lost half your influence." << endl;
                playersInfluence = playersInfluence / 2;
                playerHero[0].setInfluence(0 - playersInfluence); //loses HALF their influence
            }
            else if(probabilityWinSpeech == 1) //Player definitely wins
            {
                cout << "..." << endl << "Your speech was very effective!" << endl;
                //acquire Warriors, choose if you end up with more than 4
                cout << "Your Grace has defeated " << heroes[EnemyHeroIndex].getNameHero() << endl;
                int spaceForWarriors = 4 - playerHero[0].getOwnedWarriorVectorSize();
                string warriorChoice;
                int timesSaidNo = 0;
                    
                cout << heroes[EnemyHeroIndex].getNameHero() << " has " << heroes[EnemyHeroIndex].getOwnedWarriorVectorSize() << " Warriors ";
                cout << "and Your Grace has space for " << spaceForWarriors << " Warriors." << endl;
                    
                if(spaceForWarriors > 0 && heroes[EnemyHeroIndex].getOwnedWarriorVectorSize() > 0) //if hero has room for warriors and there are warriors to take
                {
                        // print a list of the warriors first
                        cout << endl << heroes[EnemyHeroIndex].getNameHero() << "'s warriors:" << endl;
                        int ownedWarriorNumber = 1;
                        for(int enemyWarriors = 0; enemyWarriors < heroes[EnemyHeroIndex].getOwnedWarriorVectorSize(); enemyWarriors++)
                        {
                            cout << ownedWarriorNumber << ". " << heroes[EnemyHeroIndex].getOwnedWarriorName(enemyWarriors) << endl;
                            ownedWarriorNumber++;
                        }
                        cout << endl;
                        // now ask one-by-one
                        for(int enemyWarriors2 = 0; enemyWarriors2 < heroes[EnemyHeroIndex].getOwnedWarriorVectorSize(); enemyWarriors2++)
                        {
                            while(playerHero[0].getOwnedWarriorVectorSize() < 4 && timesSaidNo < numberUpForGrabs)
                            {
                                bool validAnswer = false;
                                while(validAnswer == false)
                                {
                                    cout << "Would you like to take " << heroes[EnemyHeroIndex].getOwnedWarriorName(enemyWarriors2) << "?(Y/N) ";
                                    getline(cin, warriorChoice);
                                    if(warriorChoice == "Y" || warriorChoice == "y")
                                    {
                                        Warrior warriorObject = heroes[EnemyHeroIndex].getOwnedWarriorObject(enemyWarriors2);
                                        playerHero[0].addOwnedWarrior(warriorObject);
                                        cout << "You have acquired the warrior, " << heroes[EnemyHeroIndex].getOwnedWarriorName(enemyWarriors2) << endl;
                                        validAnswer = true;
                                    }
                                    else if(warriorChoice == "N" || warriorChoice == "n")
                                    {
                                        timesSaidNo++;
                                        validAnswer = true;
                                    }
                                    else
                                    {
                                        cout << "Was that a yes(Y) or a no(N)?" << endl;
                                    }
                                }
                            }
                        }
                    }
                else
                {
                    //if enemy hero has no warriors to offer or space if already full for player's warriors
                    cout << "Your Grace cannot acquire any Warriors at this time" << endl;
                }
                // take ALL their money, influence, armySize
                playerHero[0].setMoney(heroes[EnemyHeroIndex].getMoney()); 
                playerHero[0].setInfluence(heroes[EnemyHeroIndex].getInfluence()); 
                playerHero[0].setArmySize(heroes[EnemyHeroIndex].getArmySize()); 
                // retire opposing Hero
                //http://www.cplusplus.com/reference/vector/vector/erase/
                heroes.erase(heroes.begin() + EnemyHeroIndex);  
            }
            else if(probabilityWinSpeech > 0 && probabilityWinSpeech < 1) // 
            {
                //generate Boolean for win with probability of Player winning = probabilityWinSpeech
                double speechResult = (random() % 100 + 1) / 100; //generate random number 0 to 1
                if(speechResult <= probabilityWinSpeech) //Player wins speech
                {
                    //acquire Warriors, choose if you end up with more than 4
                    cout << "Your Grace has defeated " << heroes[EnemyHeroIndex].getNameHero() << endl;
                    int spaceForWarriors = 4 - playerHero[0].getOwnedWarriorVectorSize();
                    string warriorChoice;
                    int timesSaidNo = 0;
                    
                    cout << heroes[EnemyHeroIndex].getNameHero() << " has " << heroes[EnemyHeroIndex].getOwnedWarriorVectorSize() << " Warriors ";
                    cout << "and Your Grace has space for " << spaceForWarriors << " Warriors." << endl;
                    
                    if(spaceForWarriors > 0 && heroes[EnemyHeroIndex].getOwnedWarriorVectorSize() > 0) //if hero has room for warriors and there are warriors to take
                    {
                        // print a list of the warriors first
                        cout << endl << heroes[EnemyHeroIndex].getNameHero() << "'s warriors:" << endl;
                        int ownedWarriorNumber = 1;
                        for(int enemyWarriors = 0; enemyWarriors < heroes[EnemyHeroIndex].getOwnedWarriorVectorSize(); enemyWarriors++)
                        {
                            cout << ownedWarriorNumber << ". " << heroes[EnemyHeroIndex].getOwnedWarriorName(enemyWarriors) << endl;
                            ownedWarriorNumber++;
                        }
                        cout << endl;
                        // now ask one-by-one
                        for(int enemyWarriors2 = 0; enemyWarriors2 < heroes[EnemyHeroIndex].getOwnedWarriorVectorSize(); enemyWarriors2++)
                        {
                            while(playerHero[0].getOwnedWarriorVectorSize() < 4 && timesSaidNo < numberUpForGrabs)
                            {
                                bool validAnswer = false;
                                while(validAnswer == false)
                                {
                                    cout << "Would you like to take " << heroes[EnemyHeroIndex].getOwnedWarriorName(enemyWarriors2) << "?(Y/N) ";
                                    getline(cin, warriorChoice);
                                    if(warriorChoice == "Y" || warriorChoice == "y")
                                    {
                                        Warrior warriorObject = heroes[EnemyHeroIndex].getOwnedWarriorObject(enemyWarriors2);
                                        playerHero[0].addOwnedWarrior(warriorObject);
                                        cout << "You have acquired the warrior, " << heroes[EnemyHeroIndex].getOwnedWarriorName(enemyWarriors2) << endl;
                                        validAnswer = true;
                                    }
                                    else if(warriorChoice == "N" || warriorChoice == "n")
                                    {
                                        timesSaidNo++;
                                        validAnswer = true;
                                    }
                                    else
                                    {
                                        cout << "Was that a yes(Y) or a no(N)?" << endl;
                                    }
                                }
                            }
                        }
                    }
                    else
                    {
                        //if enemy hero has no warriors to offer or space if already full for player's warriors
                        cout << "Your Grace cannot acquire any Warriors at this time" << endl;
                    }
                    // take ALL their money, influence, armySize
                    playerHero[0].setMoney(heroes[EnemyHeroIndex].getMoney()); 
                    playerHero[0].setInfluence(heroes[EnemyHeroIndex].getInfluence()); 
                    playerHero[0].setArmySize(heroes[EnemyHeroIndex].getArmySize()); 
                    cout << "You have taken all of " << heroes[EnemyHeroIndex].getNameHero() << "'s money, influence, and knights." << endl;
                    // retire opposing Hero
                    //http://www.cplusplus.com/reference/vector/vector/erase/
                    cout << heroes[EnemyHeroIndex].getNameHero() << " has retired." << endl;
                    heroes.erase(heroes.begin() + EnemyHeroIndex); // pop the Hero object at EnemyHeroIndex from heroes vector
                }
                else //Player loses speech
                {
                    cout << endl << "Your speech wasn't very useful. You lost half your influence." << endl;
                    playersInfluence = playersInfluence / 2;
                    playerHero[0].setInfluence(0 - playersInfluence); //loses HALF their influence
                }
            }
        }
        else if(getChoiceEncounter == 2) //buy them outright
        {
            cout << "You have chosen to try and buy the enemy outright " << endl << endl;
            double probabilityWinBuyingOutright;
            double firstWarriorsLoyalty = playerHero[0].getFirstWarriorsLoyalty(); 
            double playersMoney = playerHero[0].getMoney();
            probabilityWinBuyingOutright = ((1 - (firstWarriorsLoyalty / 100)) * (playersMoney / 17800));
            if(probabilityWinBuyingOutright <= 0) //Hero loses buying outright
            {
                //player hero loses half their money
                cout << endl << "Try to buy them out wasn't very useful. You lost half your money." << endl;
                playersMoney = playersMoney / 2;
                playerHero[0].setMoney(0 - playersMoney);
            }
            else if(probabilityWinBuyingOutright == 1) //Hero definitely wins
            {
                //acquire Warriors, choose if you end up with more than 4
                cout << "Your Grace has defeated " << heroes[EnemyHeroIndex].getNameHero() << endl;
                int spaceForWarriors = 4 - playerHero[0].getOwnedWarriorVectorSize();
                string warriorChoice;
                int timesSaidNo = 0;
                    
                cout << heroes[EnemyHeroIndex].getNameHero() << " has " << heroes[EnemyHeroIndex].getOwnedWarriorVectorSize() << " Warriors ";
                cout << "and Your Grace has space for " << spaceForWarriors << " Warriors." << endl;
                    
                if(spaceForWarriors > 0 && heroes[EnemyHeroIndex].getOwnedWarriorVectorSize() > 0) //if hero has room for warriors and there are warriors to take
                {
                        // print a list of the warriors first
                        cout << endl << heroes[EnemyHeroIndex].getNameHero() << "'s warriors:" << endl;
                        int ownedWarriorNumber = 1;
                        for(int enemyWarriors = 0; enemyWarriors < heroes[EnemyHeroIndex].getOwnedWarriorVectorSize(); enemyWarriors++)
                        {
                            cout << ownedWarriorNumber << ". " << heroes[EnemyHeroIndex].getOwnedWarriorName(enemyWarriors) << endl;
                            ownedWarriorNumber++;
                        }
                        cout << endl;
                        // now ask one-by-one
                        for(int enemyWarriors2 = 0; enemyWarriors2 < heroes[EnemyHeroIndex].getOwnedWarriorVectorSize(); enemyWarriors2++)
                        {
                            while(playerHero[0].getOwnedWarriorVectorSize() < 4 && timesSaidNo < numberUpForGrabs)
                            {
                                bool validAnswer = false;
                                while(validAnswer == false)
                                {
                                    cout << "Would you like to take " << heroes[EnemyHeroIndex].getOwnedWarriorName(enemyWarriors2) << "?(Y/N) ";
                                    getline(cin, warriorChoice);
                                    if(warriorChoice == "Y" || warriorChoice == "y")
                                    {
                                        Warrior warriorObject = heroes[EnemyHeroIndex].getOwnedWarriorObject(enemyWarriors2);
                                        playerHero[0].addOwnedWarrior(warriorObject);
                                        cout << "You have acquired the warrior, " << heroes[EnemyHeroIndex].getOwnedWarriorName(enemyWarriors2) << endl;
                                        validAnswer = true;
                                    }
                                    else if(warriorChoice == "N" || warriorChoice == "n")
                                    {
                                        timesSaidNo++;
                                        validAnswer = true;
                                    }
                                    else
                                    {
                                        cout << "Was that a yes(Y) or a no(N)?" << endl;
                                    }
                                }
                            }
                        }
                    }
                else
                {
                    //if enemy hero has no warriors to offer or space if already full for player's warriors
                    cout << "Your Grace cannot acquire any Warriors at this time" << endl;
                }
                // take ALL their money, influence, armySize
                playerHero[0].setMoney(heroes[EnemyHeroIndex].getMoney()); 
                playerHero[0].setInfluence(heroes[EnemyHeroIndex].getInfluence()); 
                playerHero[0].setArmySize(heroes[EnemyHeroIndex].getArmySize()); 
                // retire opposing Hero
                cout << heroes[EnemyHeroIndex].getNameHero() << " has retired." << endl;
                heroes.erase(heroes.begin() + EnemyHeroIndex);
            }
            else if(probabilityWinBuyingOutright > 0 && probabilityWinBuyingOutright < 1)
            {
                //generate Boolean for win with probability of Player winning = probabilityWinBuyingOutright
                double buyResult = (random() % 100 + 1) / 100; //random number 0 to 1
                if(buyResult <= probabilityWinBuyingOutright) //Player wins buying outright
                {
                    //acquire Warriors, choose if you end up with more than 4
                    cout << "Your Grace has defeated " << heroes[EnemyHeroIndex].getNameHero() << endl;
                    int spaceForWarriors = 4 - playerHero[0].getOwnedWarriorVectorSize();
                    string warriorChoice;
                    int timesSaidNo = 0;
                    
                    cout << heroes[EnemyHeroIndex].getNameHero() << " has " << heroes[EnemyHeroIndex].getOwnedWarriorVectorSize() << " Warriors ";
                    cout << "and Your Grace has space for " << spaceForWarriors << " Warriors." << endl;
                    
                    if(spaceForWarriors > 0 && heroes[EnemyHeroIndex].getOwnedWarriorVectorSize() > 0) //if hero has room for warriors and there are warriors to take
                    {
                        // print a list of the warriors first
                        cout << endl << heroes[EnemyHeroIndex].getNameHero() << "'s warriors:" << endl;
                        int ownedWarriorNumber = 1;
                        for(int enemyWarriors = 0; enemyWarriors < heroes[EnemyHeroIndex].getOwnedWarriorVectorSize(); enemyWarriors++)
                        {
                            cout << ownedWarriorNumber << ". " << heroes[EnemyHeroIndex].getOwnedWarriorName(enemyWarriors) << endl;
                            ownedWarriorNumber++;
                        }
                        cout << endl;
                        // now ask one-by-one
                        for(int enemyWarriors2 = 0; enemyWarriors2 < heroes[EnemyHeroIndex].getOwnedWarriorVectorSize(); enemyWarriors2++)
                        {
                            while(playerHero[0].getOwnedWarriorVectorSize() < 4 && timesSaidNo < numberUpForGrabs)
                            {
                                bool validAnswer = false;
                                while(validAnswer == false)
                                {
                                    cout << "Would you like to take " << heroes[EnemyHeroIndex].getOwnedWarriorName(enemyWarriors2) << "?(Y/N) ";
                                    getline(cin, warriorChoice);
                                    if(warriorChoice == "Y" || warriorChoice == "y")
                                    {
                                        Warrior warriorObject = heroes[EnemyHeroIndex].getOwnedWarriorObject(enemyWarriors2);
                                        playerHero[0].addOwnedWarrior(warriorObject);
                                        cout << "You have acquired the warrior, " << heroes[EnemyHeroIndex].getOwnedWarriorName(enemyWarriors2) << endl;
                                        validAnswer = true;
                                    }
                                    else if(warriorChoice == "N" || warriorChoice == "n")
                                    {
                                        timesSaidNo++;
                                        validAnswer = true;
                                    }
                                    else
                                    {
                                        cout << "Was that a yes(Y) or a no(N)?" << endl;
                                    }
                                }
                            }
                        }
                    }
                    else
                    {
                        //if enemy hero has no warriors to offer or space if already full for player's warriors
                        cout << "Your Grace cannot acquire any Warriors at this time" << endl;
                    }
                    // take ALL their money, influence, armySize
                    playerHero[0].setMoney(heroes[EnemyHeroIndex].getMoney()); 
                    playerHero[0].setInfluence(heroes[EnemyHeroIndex].getInfluence()); 
                    playerHero[0].setArmySize(heroes[EnemyHeroIndex].getArmySize()); 
                    // retire opposing Hero
                    heroes.erase(heroes.begin() + EnemyHeroIndex);
                }
                else //Player loses buying outright
                {
                    //player hero loses half their money
                    cout << endl << "Try to buy them out wasn't very useful. You lost half your money." << endl;
                    playersMoney = playersMoney / 2;
                    playerHero[0].setMoney(0 - playersMoney);
                }
            }
        }
        else if(getChoiceEncounter == 3) //battle
        {
            cout << "You have chosen to engage in battle." << endl << endl;
            // if either Hero has no Warriors, that Hero automatically loses
            if(playerHero[0].getOwnedWarriorVectorSize() == 0) //player loses battle
            {
                // game over --> void gameOver(string inputUserName, Hero onputHeroObject, int inputPointsScore);
                cout << "Oh no! You have no warriors and the enemy is much stronger than you..." << endl;
                setWonOrLost("lost");
                return;
            }
            else if(heroes[EnemyHeroIndex].getOwnedWarriorVectorSize() == 0) // enemy Hero loses battle
            {
                //acquire Warriors, choose if you end up with more than 4
                cout << "Your warriors fought well. ";
                cout << "Your Grace has defeated " << heroes[EnemyHeroIndex].getNameHero() << endl;
                int spaceForWarriors = 4 - playerHero[0].getOwnedWarriorVectorSize();
                string warriorChoice;
                int timesSaidNo = 0;
                    
                cout << heroes[EnemyHeroIndex].getNameHero() << " has " << heroes[EnemyHeroIndex].getOwnedWarriorVectorSize() << " Warriors ";
                cout << "and Your Grace has space for " << spaceForWarriors << " Warriors." << endl;
                    
                if(spaceForWarriors > 0 && heroes[EnemyHeroIndex].getOwnedWarriorVectorSize() > 0) //if hero has room for warriors and there are warriors to take
                {
                        // print a list of the warriors first
                        cout << endl << heroes[EnemyHeroIndex].getNameHero() << "'s warriors:" << endl;
                        int ownedWarriorNumber = 1;
                        for(int enemyWarriors = 0; enemyWarriors < heroes[EnemyHeroIndex].getOwnedWarriorVectorSize(); enemyWarriors++)
                        {
                            cout << ownedWarriorNumber << ". " << heroes[EnemyHeroIndex].getOwnedWarriorName(enemyWarriors) << endl;
                            ownedWarriorNumber++;
                        }
                        cout << endl;
                        // now ask one-by-one
                        for(int enemyWarriors2 = 0; enemyWarriors2 < heroes[EnemyHeroIndex].getOwnedWarriorVectorSize(); enemyWarriors2++)
                        {
                            while(playerHero[0].getOwnedWarriorVectorSize() < 4 && timesSaidNo < numberUpForGrabs)
                            {
                                bool validAnswer = false;
                                while(validAnswer == false)
                                {
                                    cout << "Would you like to take " << heroes[EnemyHeroIndex].getOwnedWarriorName(enemyWarriors2) << "?(Y/N) ";
                                    getline(cin, warriorChoice);
                                    if(warriorChoice == "Y" || warriorChoice == "y")
                                    {
                                        Warrior warriorObject = heroes[EnemyHeroIndex].getOwnedWarriorObject(enemyWarriors2);
                                        playerHero[0].addOwnedWarrior(warriorObject);
                                        cout << "You have acquired the warrior, " << heroes[EnemyHeroIndex].getOwnedWarriorName(enemyWarriors2) << endl;
                                        validAnswer = true;
                                    }
                                    else if(warriorChoice == "N" || warriorChoice == "n")
                                    {
                                        timesSaidNo++;
                                        validAnswer = true;
                                    }
                                    else
                                    {
                                        cout << "Was that a yes(Y) or a no(N)?" << endl;
                                    }
                                }
                            }
                        }
                    }
                else
                {
                    //if enemy hero has no warriors to offer or space if already full for player's warriors
                    cout << "Your Grace cannot acquire any Warriors at this time" << endl;
                }
                // take ALL their money, influence, armySize
                playerHero[0].setMoney(heroes[EnemyHeroIndex].getMoney()); 
                playerHero[0].setInfluence(heroes[EnemyHeroIndex].getInfluence()); 
                playerHero[0].setArmySize(heroes[EnemyHeroIndex].getArmySize()); 
                // retire opposing Hero
                cout << heroes[EnemyHeroIndex].getNameHero() << " has retired." << endl;
                heroes.erase(heroes.begin() + EnemyHeroIndex);
            }
            else //battle time
            {
                // ask player to choose which Warrior will battle
                bool choseWarriorBattle = false;
                int battleWarriorIndex = -1;
                int enemyWarriorIndex = -1;
                int newBattleWarriorIndex = -1;
                string warriorBattleNumber;
                while(choseWarriorBattle == false)
                {
                    bool validNumber = false;
                    bool validNumber2 = false;
                    while(validNumber == false || validNumber2 == false)
                    {
                        cout << "Which Warrior shall represent you?" << endl;
                        int battleWarriorIndex = 0;
                        for(int b = 0; b < playerHero[0].getOwnedWarriorVectorSize(); b++) 
                        {
                            cout << battleWarriorIndex + 1 << ". " << playerHero[0].getOwnedWarriorName(battleWarriorIndex) << endl;
                            battleWarriorIndex++;
                        }
                        getline(cin, warriorBattleNumber);
                        if(warriorBattleNumber == "1" || warriorBattleNumber == "2" || warriorBattleNumber == "3" || warriorBattleNumber == "4")
                        {
                            if(stoi(warriorBattleNumber) > 0 && stoi(warriorBattleNumber) <= playerHero[0].getOwnedWarriorVectorSize())
                            {
                                validNumber = true;
                                validNumber2 = true;
                            }
                        }
                    }
                    newBattleWarriorIndex = stoi(warriorBattleNumber) - 1;
                    choseWarriorBattle = true;
                }
                // for opposing Hero, choose random warrior
                enemyWarriorIndex = random() % heroes[EnemyHeroIndex].getOwnedWarriorVectorSize() + 1;
                // hero with highest value for (armySize) * (strengthChosenWarrior) wins
                double playerBattleStrength = playerHero[0].getArmySize() * playerHero[0].getChosenWarriorStrength(newBattleWarriorIndex);
                double enemyBattleStrength = heroes[EnemyHeroIndex].getArmySize() * heroes[EnemyHeroIndex].getChosenWarriorStrength(enemyWarriorIndex);
                if(playerBattleStrength > enemyBattleStrength) //player wins battle
                {
                    //acquire Warriors, choose if you end up with more than 4
                    cout << "Your Grace has defeated " << heroes[EnemyHeroIndex].getNameHero() << endl;
                    int spaceForWarriors = 4 - playerHero[0].getOwnedWarriorVectorSize();
                    string warriorChoice;
                    int timesSaidNo = 0;
                    
                    cout << heroes[EnemyHeroIndex].getNameHero() << " has " << heroes[EnemyHeroIndex].getOwnedWarriorVectorSize() << " Warriors ";
                    cout << "and Your Grace has space for " << spaceForWarriors << " Warriors." << endl;
                    
                    if(spaceForWarriors > 0 && heroes[EnemyHeroIndex].getOwnedWarriorVectorSize() > 0) //if hero has room for warriors and there are warriors to take
                    {
                        // print a list of the warriors first
                        cout << endl << heroes[EnemyHeroIndex].getNameHero() << "'s warriors:" << endl;
                        int ownedWarriorNumber = 1;
                        for(int enemyWarriors = 0; enemyWarriors < heroes[EnemyHeroIndex].getOwnedWarriorVectorSize(); enemyWarriors++)
                        {
                            cout << ownedWarriorNumber << ". " << heroes[EnemyHeroIndex].getOwnedWarriorName(enemyWarriors) << endl;
                            ownedWarriorNumber++;
                        }
                        cout << endl;
                        // now ask one-by-one
                        for(int enemyWarriors2 = 0; enemyWarriors2 < heroes[EnemyHeroIndex].getOwnedWarriorVectorSize(); enemyWarriors2++)
                        {
                            while(playerHero[0].getOwnedWarriorVectorSize() < 4 && timesSaidNo < numberUpForGrabs)
                            {
                                bool validAnswer = false;
                                while(validAnswer == false)
                                {
                                    cout << "Would you like to take " << heroes[EnemyHeroIndex].getOwnedWarriorName(enemyWarriors2) << "?(Y/N) ";
                                    getline(cin, warriorChoice);
                                    if(warriorChoice == "Y" || warriorChoice == "y")
                                    {
                                        Warrior warriorObject = heroes[EnemyHeroIndex].getOwnedWarriorObject(enemyWarriors2);
                                        playerHero[0].addOwnedWarrior(warriorObject);
                                        cout << "You have acquired the warrior, " << heroes[EnemyHeroIndex].getOwnedWarriorName(enemyWarriors2) << endl;
                                        validAnswer = true;
                                    }
                                    else if(warriorChoice == "N" || warriorChoice == "n")
                                    {
                                        timesSaidNo++;
                                        validAnswer = true;
                                    }
                                    else
                                    {
                                        cout << "Was that a yes(Y) or a no(N)?" << endl;
                                    }
                                }
                            }
                        }
                    }
                    else
                    {
                        //if enemy hero has no warriors to offer or space if already full for player's warriors
                        cout << "Your Grace cannot acquire any Warriors at this time" << endl;
                    }
                    // take ALL their money, influence, armySize
                    playerHero[0].setMoney(heroes[EnemyHeroIndex].getMoney()); 
                    playerHero[0].setInfluence(heroes[EnemyHeroIndex].getInfluence()); 
                    playerHero[0].setArmySize(heroes[EnemyHeroIndex].getArmySize()); 
                    // retire opposing Hero
                    cout << heroes[EnemyHeroIndex].getNameHero() << " has retired." << endl;
                    heroes.erase(heroes.begin() + EnemyHeroIndex);
                }
                else // player loses battle
                {
                    // if player loses --> GAME OVER
                    cout << "Oh no! It doesn't seem like you're strong enough..." << endl;
                    setWonOrLost("lost");
                    return;
                }
            }
        }
        setAllOwnedWarriorLocations();
    }
    
    // check if free-roaming warriors are near
    int isFreeWarriorNear = checkForFreeWarrior(); //returns the warriors[] index of the close, free-roaming warrior
    if(isFreeWarriorNear != -1) //there is a free warrior near
    {
        // acquire the free warrior (there is a check inside to see if there's room in the ownedWarriors vector)
        playerHero[0].addOwnedWarrior(warriors[isFreeWarriorNear]);
    }
    
    bool eventHappens;
    int randomEvent = random() % 100 + 1; // 30% random event
    if(randomEvent <= 30)
    {
        eventHappens = true;
    }
    if(eventHappens == true)
    {
        int oneOfFour = random() % 4 + 1; // equally likely events if Random Event happens
        switch(oneOfFour)
        {
            case 1:
            {
                //drought
                cout << "Oh no! There has been no rain in days and the army has very little food left." << endl;
                cout << "Your warriors have lost 10 points in strength and morale" << endl;
                playerHero[0].setAllOwnedWarriorsMorale(-10);
                playerHero[0].setAllOwnedWarriorsStrength(-10);
                eventHappens = false;
                break;
            }
            case 2:
            {
                // deserters
                cout << "Oh no! This campaign is taking a very long time and the soliders are tired and sad." << endl;
                cout << "10 of your knights decided to leave and your warriors' loyalty has decreased by 10" << endl;
                playerHero[0].setArmySize(-10);
                playerHero[0].setAllOwnedWarriorLoyalty(-10);
                eventHappens = false;
                break;
            }
            case 3:
            {
                // jackpot
                cout << "Good news! Your heroic cause has won the hearts of many noble and wealthy benefactors!" << endl;
                cout << "They generously donate funds to your cause" << endl;
                playerHero[0].setMoney(playerHero[0].getMoney() * 2);
                cout << "Your money has increased to " << playerHero[0].getMoney() << endl;
                eventHappens = false;
                break;
            }
            case 4:
            {
                // kindness
                cout << "How kind! You decide to offer shelter to some refugees" << endl;
                cout << "You have gained 10 knights for your army and your warriors' loyalty has increased by 10" << endl;
                playerHero[0].setArmySize(10);
                playerHero[0].setAllOwnedWarriorLoyalty(10);
                eventHappens = false;
                break;
            }
        }
    }
    setTurns(1); // increment turn counter
    cout << endl << "Turns played: " << turnCounter << endl;
    cout << "Total points: " << pointsTotal << endl;
    cout << "Tiles controlled: " << tilesControlled << endl;
    cout << "Money: " << playerHero[0].getMoney() << endl;
    cout << "Army size: " << playerHero[0].getArmySize() << endl;
    cout << "Influence: " << playerHero[0].getInfluence() << endl;
    
    if(getTurns() == 10)
    {
        //Hero Daenerys acquires dragons (as Warrior object)
        int daeIndex = -1;
        for(int d = 0; d < heroes.size(); d++)
        {
            if(heroes[d].getNameHero() == "Daenerys Targaryen")
            {
                daeIndex = d;
                //Warrior(string inputNameWarrior, int inputStrength, int inputLoyalty, int inputMorale, bool inputIsFree, bool inputHasShipWarrior, bool inputHasDragonglass);
                Warrior Dragons("Dragons", 180, 100, 80, false, false, false);
                if(heroes[daeIndex].getOwnedWarriorVectorSize() == 4)
                {
                    heroes[daeIndex].deleteOwnedWarrior(3); //make room for Dragons 
                    // add Dragons as a Warrior object
                    heroes[daeIndex].addOwnedWarrior(Dragons);
                }
                else
                {
                    // add Dragons as a Warrior object
                    heroes[daeIndex].addOwnedWarrior(Dragons);
                }
                cout << endl << "Breaking news! Daenerys Targaryen has just acquired Dragons" << endl;
                heroes[daeIndex].setArmySize(5000);
            }
        }
        //Stannis gets consumed by his demons and dies
        int stanIndex = -1;
        for(int s = 0; s < heroes.size(); s++)
        {
            if(heroes[s].getNameHero() == "Stannis Baratheon")
            {
                stanIndex = s;
                // set all his warriors free****
                for(int stansWarriors = 0; stansWarriors < heroes[stanIndex].getOwnedWarriorVectorSize(); stansWarriors++) //go through Stannis' owned warriors
                {
                    for(int allWarriors = 0; allWarriors < 14; allWarriors++) //go through all 14 warriors in the game
                    {
                        if(warriors[allWarriors].getName() == heroes[stanIndex].getOwnedWarriorName(stansWarriors))
                        {
                            warriors[allWarriors].setIsFree(true);
                        }
                    }
                }
                // retire him
                heroes.erase(heroes.begin() + stanIndex); //retire him
                if(playerHero[0].getNameHero() == "Stannis Baratheon")
                {
                    cout << endl << "Oh no! Your dragons are attacking" << endl;
                    setWonOrLost("lost");
                    return;
                }
                bool hasPaidRespects = false;
                string paidRespects;
                cout << "Stannis has retired. Press F to pay respects: ";
                getline(cin, paidRespects);
                while(hasPaidRespects == false)
                {
                    if(paidRespects == "F" || paidRespects == "f")
                    {
                        cout << endl << "Mood." << endl;
                        hasPaidRespects = true;
                    }
                    else
                    {
                        cout << endl << "Have you no respect?! ";
                        cout << "Stannis has retired. Press F to pay respects: ";
                        getline(cin, paidRespects);
                    }
                }
            }
        }
        //Sansa acquires warrior Arya
        int sansaIndex = -1;
        int aryaIndexOwned = -1;
        for(int heroIndex = 0; heroIndex < heroes.size(); heroIndex++) //go through all the heroes
        {
            for(int ar = 0; ar < heroes[heroIndex].getOwnedWarriorVectorSize(); ar++) //go through all current heroe's warriors
            {
                if(heroes[heroIndex].getOwnedWarriorName(ar) == "Arya Stark") //if that hero owns Arya, delete her
                {
                    aryaIndexOwned = ar;
                    heroes[heroIndex].deleteOwnedWarrior(ar);
                }
            }
            if(heroes[heroIndex].getNameHero() == "Sansa Stark") //if the current hero is Sansa
            {
                sansaIndex = heroIndex;
                cout << endl << "Breaking: Arya has just joined Sansa's army" << endl;
                for(int w = 0; w < 14; w++)
                {
                    if(warriors[w].getName() == "Arya Stark")
                    {
                        heroes[sansaIndex].addOwnedWarrior(warriors[w]); //add Arya as a warrior of Sansa.
                        
                    }
                }
            }
        }
        //Cersei loses warrior Jaime (Jaime becomes free)
        int cerIndex = -1;
        for(int c = 0; c < heroes.size(); c++) //go through all the heroes in the game
        {
            if(heroes[c].getNameHero() == "Cersei Lannister") //find hero Cersei
            {
                cerIndex = c;
                for(int j = 0; j < heroes[cerIndex].getOwnedWarriorVectorSize(); j++) //go through Cersei's warriors
                {
                    if(heroes[cerIndex].getOwnedWarriorName(j) == "Jaime Lannister") //find Jaime
                    {
                        heroes[cerIndex].deleteOwnedWarrior(j); //delete him
                    }
                    for(int k = 0; k < 14; k++)
                    {
                        if(warriors[k].getName() == "Jaime Lannister") //find Jaime in the big warriors array
                        {
                            warriors[k].setIsFree(true);
                            cout << "Breaking: Jaime Lannister has left Cersei Lannister's army!" << endl;
                        }
                    }
                }
            }
        }
    }
    // check if White Walkers are coming !!!
    
    setWhiteWalkersComing();
    if(getWhiteWalkersAreComing() == true)
    {
        // --> if yes, then prompts User for decision to battle or not (updates counter)
        cout << endl << "Sad news! The White Walkers are approaching your location."; 
        bool decisionBattleWhiteWalkers = false;
        while(decisionBattleWhiteWalkers == false)
        {
            cout << " Would you like to battle them now? (Y/N): ";
            string battleWhiteWalkers;
            getline(cin, battleWhiteWalkers);
            if(battleWhiteWalkers == "Y" || battleWhiteWalkers == "y")
            {
                // battle now!!
                whiteWalkerBattle();
                decisionBattleWhiteWalkers = true;
            }
            else if(battleWhiteWalkers == "N" || battleWhiteWalkers == "n")
            {
                // increment the counter of times battle denied
                setTimesDeniedWhiteWalkerBattle(1);
                if(getTimesDeniedWhiteWalkerBattle() == 5)
                {
                    // GAME OVER
                    cout << endl << "You have avoided the White Walkers for too long. They're closing in on you." << endl;
                    setWonOrLost("lost");
                    return;
                }
                decisionBattleWhiteWalkers = true;
            }
            else
            {
                cout << endl << "Make up your mind!" << endl;
            }
        }
    }
    setIsPlayerTurn(true);
}

bool Game::checkIfValidTileCharacter() //for all other Heroes and Warriors
{
    bool allHeroesUpdated = false;
    bool allWarriorsUpdated = false;
    bool allCharactersUpdated = false;
    bool successfullyUpdatedLocation;
    int oneDirection = -1;
    int currentRowCharacter = -1;
    int currentColumnCharacter = -1;
    
    for(int i = 0; i < heroes.size(); i++) //iterate through heroes vector
    {
        if(heroes[i].getNameHero() != playerHero[0].getNameHero()) //skip player's Hero
        {
            currentRowCharacter = heroes[i].getRowHero();
            currentColumnCharacter = heroes[i].getColumnHero();
            // cout << "value of i: " << i << endl;
            // cout << "Name current hero: " << heroes[i].getNameHero() << endl;
            // cout << "current row: " << currentRowCharacter << endl;
            // cout << "current col: " << currentColumnCharacter << endl;
            // cout << "map location: " << bigMap[currentRowCharacter][currentColumnCharacter] << endl;
            // cout << "has ship?: " << heroes[i].doesHeroHaveShip() << endl;
            // cout << "warriors have ship?: " << heroes[i].getDoesAnyOwnedWarriorHaveShip() << endl;
            successfullyUpdatedLocation = false;
            
            while(successfullyUpdatedLocation == false)
            {
                oneDirection = random() % 4; // generate random direction
                //oneDirection = 0;
                //cout << "value of oneDirection: " << oneDirection << endl;
                switch(oneDirection)
                {
                    case 0: //move NORTH = row - 1
                    {
                        //cout << "inside case 0" << endl;
                        // if new location would be a land tile, or a City, or a water when either the Hero or one of the Hero's owned warriors has a ship AND the new tile would be in bounds
                        if(
                            currentRowCharacter - 1 >= 0 &&
                            (
                                bigMap[currentRowCharacter - 1][currentColumnCharacter] == 'p' || 
                                (bigMap[currentRowCharacter - 1][currentColumnCharacter] >= 'A' && bigMap[currentRowCharacter - 1][currentColumnCharacter] <= 'Z') ||
                                (bigMap[currentRowCharacter - 1][currentColumnCharacter] == 'w' && (heroes[i].doesHeroHaveShip() == true || heroes[i].getDoesAnyOwnedWarriorHaveShip() == true )) 
                            )
                        )
                        {
                            heroes[i].setRowLocation(currentRowCharacter - 1);
                            //heroes[i].setColumnLocation(currentColumnCharacter);
                            heroes[i].setAllOwnedWarriorLocations(); //update Owned Warrior locations
                            successfullyUpdatedLocation = true;
                            //cout << "successfully updated?: " << successfullyUpdatedLocation << endl;
                        }
                        break;
                    }
                    case 1: //move EAST = column + 1
                    {
                        //cout << "inside case 1" << endl;
                        // if new location would be a land tile, or a City, or a water when either the Hero or one of the Hero's owned warriors has a ship AND the new tile would be in bounds
                        if(
                            currentColumnCharacter + 1 < 15 &&
                            (
                                bigMap[currentRowCharacter][currentColumnCharacter + 1] == 'p' || 
                                (bigMap[currentRowCharacter][currentColumnCharacter + 1] >= 'A' && bigMap[currentRowCharacter][currentColumnCharacter + 1] <= 'Z') || 
                                (bigMap[currentRowCharacter][currentColumnCharacter + 1] == 'w' && (heroes[i].doesHeroHaveShip() == true || heroes[i].getDoesAnyOwnedWarriorHaveShip() == true))
                            )
                        )
                        {
                            //heroes[i].setRowLocation(currentRowCharacter);
                            heroes[i].setColumnLocation(currentColumnCharacter + 1);
                            heroes[i].setAllOwnedWarriorLocations(); //update Owned Warrior locations
                            successfullyUpdatedLocation = true;
                            //cout << "successfully updated?: " << successfullyUpdatedLocation << endl;
                        }
                        break;
                    }
                    case 2: //move SOUTH = row + 1
                    {
                        //cout << "inside case 2" << endl;
                        if(
                            currentRowCharacter + 1 <= 24 &&
                            (
                                bigMap[currentRowCharacter + 1][currentColumnCharacter] == 'p' || 
                                (bigMap[currentRowCharacter + 1][currentColumnCharacter] >= 'A' && bigMap[currentRowCharacter + 1][currentColumnCharacter] <= 'Z') || 
                                (bigMap[currentRowCharacter + 1][currentColumnCharacter] == 'w' && (heroes[i].doesHeroHaveShip() == true || heroes[i].getDoesAnyOwnedWarriorHaveShip() == true))
                            )
                        )
                        {
                            heroes[i].setRowLocation(currentRowCharacter + 1);
                            //heroes[i].setColumnLocation(currentColumnCharacter);
                            heroes[i].setAllOwnedWarriorLocations(); //update Owned Warrior locations
                            successfullyUpdatedLocation = true;
                            //cout << "successfully updated?: " << successfullyUpdatedLocation << endl;
                        }
                        break;
                    }
                    case 3: //move WEST = column - 1
                    {
                        //cout << "inside case 3" << endl;
                        if(
                            currentColumnCharacter - 1 >= 0 &&
                            (
                                bigMap[currentRowCharacter][currentColumnCharacter - 1] == 'p' || 
                                (bigMap[currentRowCharacter][currentColumnCharacter - 1] >= 'A' && bigMap[currentRowCharacter][currentColumnCharacter - 1] <= 'Z') || 
                                (bigMap[currentRowCharacter][currentColumnCharacter - 1] == 'w' && (heroes[i].doesHeroHaveShip() == true || heroes[i].getDoesAnyOwnedWarriorHaveShip() == true))
                            )
                        )
                        {
                            //heroes[i].setRowLocation(currentRowCharacter);
                            heroes[i].setColumnLocation(currentColumnCharacter - 1);
                            heroes[i].setAllOwnedWarriorLocations(); //update Owned Warrior locations
                            successfullyUpdatedLocation = true;
                            //cout << "successfully updated?: " << successfullyUpdatedLocation << endl;
                        }
                        break;
                    }
                }
            }
            checkIfInCityOtherHeroes(i);
        }
    }
    allHeroesUpdated = true;
    //cout << "All heroes updated? " << endl;

    for(int j = 0; j < 14; j++) // now free warriors
    {
        if(warriors[j].getIsFree() == true)
        {
            // cout << "value of j: " << endl;
            // cout << "Name of warrior: " << warriors[j].getName() << endl;
            currentRowCharacter = warriors[j].getRowWarrior();
            currentColumnCharacter = warriors[j].getColumnWarrior();
            
            // cout << "warrior row" << currentRowCharacter << endl;
            // cout << "warrior col" << currentColumnCharacter << endl;
            // cout << "Map value of warrior " << bigMap[currentRowCharacter][currentColumnCharacter] << endl;
            // cout << "Does warrior have ship? " << warriors[j].doesWarriorHaveShip() << endl;
            
            bool successfullyUpdatedLocationWarrior = false;
            
            while(successfullyUpdatedLocationWarrior == false)
            {
                oneDirection = random() % 4; // generate random direction
                //cout << "value of oneDirection Warrior: " << oneDirection << endl;
                
                if(oneDirection == 0) //move NORTH = row - 1
                {
                    if(currentRowCharacter - 1 < 0) ////////// check if out of bounds ////////
                    {
                        //oneDirection = random() % 4 + 1;
                    }
                    /////////////////////////// check for ship for water tile /////////////////////
                    else if(bigMap[currentRowCharacter - 1][currentColumnCharacter] == 'w' && warriors[j].doesWarriorHaveShip() == false)
                    {
                        //oneDirection = random() % 4 + 1;
                    }
                    else
                    {
                        warriors[j].setRowWarrior(currentRowCharacter - 1);
                        //warriors[j].setColumnWarrior(currentColumnCharacter);
                        successfullyUpdatedLocationWarrior = true;
                    }
                }
                else if(oneDirection == 1) //move EAST = column + 1
                {
                    if(currentColumnCharacter + 1 > 15) //check if out of bounds 
                    {
                        //oneDirection = random() % 4 + 1;
                    }
                    else if(bigMap[currentRowCharacter][currentColumnCharacter + 1] == 'w' && warriors[j].doesWarriorHaveShip() == false) // check for ship
                    {
                        //oneDirection = random() % 4 + 1;
                    }
                    else
                    {
                        warriors[j].setRowWarrior(currentRowCharacter);
                        warriors[j].setColumnWarrior(currentColumnCharacter + 1);
                        successfullyUpdatedLocationWarrior = true;
                    }
                }
                else if(oneDirection == 2) //move SOUTH = row + 1
                {
                    if(currentRowCharacter + 1 > 24) //check if out of bounds 
                    {
                        //oneDirection = random() % 4 + 1;
                    }
                    else if(bigMap[currentRowCharacter + 1][currentColumnCharacter] == 'w' && warriors[j].doesWarriorHaveShip() == false) // check for ship
                    {
                        //oneDirection = random() % 4 + 1;
                    }
                    else
                    {
                        warriors[j].setRowWarrior(currentRowCharacter + 1);
                        //warriors[j].setColumnWarrior(currentColumnCharacter);
                        successfullyUpdatedLocationWarrior = true;
                    }
                }
                else if(oneDirection == 3) //move WEST = column - 1
                {
                    if(currentColumnCharacter - 1 < 0) //check if out of bounds 
                    {
                        //oneDirection = random() % 4 + 1;
                    }
                    else if(bigMap[currentRowCharacter][currentColumnCharacter - 1] == 'w' && warriors[j].doesWarriorHaveShip() == false) // check for ship
                    {
                        //oneDirection = random() % 4 + 1;
                    }
                    else
                    {
                        //warriors[j].setRowWarrior(currentRowCharacter);
                        warriors[j].setColumnWarrior(currentColumnCharacter - 1);
                        successfullyUpdatedLocationWarrior = true;
                    }
                }
            }
        }
    }
    allWarriorsUpdated = true;
    //cout << "All warriors updated? " << allWarriorsUpdated << endl;
    if(allHeroesUpdated == true && allWarriorsUpdated == true)
    {
        allCharactersUpdated = true;
        return allCharactersUpdated;
    }
}

string Game::checkForEncounter() //after playerHero and all other characters' locations have been updated 
{
    string nameHeroNear;
    int currentRowPlayer = playerHero[0].getRowHero();
    int currentColumnPlayer = playerHero[0].getColumnHero();
    
    for(int i = 0; i < heroes.size(); i++) //go through all the heroes in the game
    {
        if(heroes[i].getNameHero() != playerHero[0].getNameHero()) //if not the same hero as player
        {
            if(
                heroes[i].getRowHero() > (currentRowPlayer - 3) && 
                heroes[i].getRowHero() < (currentRowPlayer + 3) && 
                heroes[i].getColumnHero() > (currentColumnPlayer - 3) && 
                heroes[i].getColumnHero() < (currentColumnPlayer + 3)
            )
            {
                nameHeroNear = heroes[i].getNameHero();
                // otherHeroIsNear = true
                return nameHeroNear;
            }        
        }
    }
    return "no encounter";
    // feeds into computerTurn()
}

int Game::checkForFreeWarrior() //return index of free Warrior from warriors[14]
{
    // if there's a free Warrior within 2 tiles, playerHero automatically acquires Warrior
    //--> addOwnedWarrior(Warrior warriorObject);
    int indexFreeWarriorNear;
    int currentRowPlayer = playerHero[0].getRowHero();
    int currentColumnPlayer = playerHero[0].getColumnHero();
    
    for(int j = 0; j < playerHero[0].getOwnedWarriorVectorSize(); j++) //go through all of player's owned warriors
    {
        for(int i = 0; i < 14; i++) //go through all the warriors in the game
        {
            //warriors[i].isFree()
            if(warriors[i].getName() != playerHero[0].getOwnedWarriorName(j)) // if Warrior not the same as player's Warrior
            {
                if(
                    (warriors[i].getRowWarrior() > (currentRowPlayer - 3)) && 
                    (warriors[i].getRowWarrior() < (currentRowPlayer + 3)) && 
                    (warriors[i].getColumnWarrior() > (currentColumnPlayer - 3)) && 
                    (warriors[i].getColumnWarrior() < (currentColumnPlayer + 3))
                )
                {
                    if(warriors[i].getIsFree() == true)
                    {
                        indexFreeWarriorNear = i;
                        // freeWarriorNear = true
                        return indexFreeWarriorNear;
                    }
                }        
            }
            else //no other Hero near
            {
                return -1;
            }
        }
    }
}

void Game::setIsGameWarriorFree(int indexFreeWarriorNear)
{
    warriors[indexFreeWarriorNear].setIsFree(false);
}

bool Game::getIsGameWarriorFree(int indexFreeWarriorNear)
{
    return warriors[indexFreeWarriorNear].getIsFree();
}

void Game::setWhiteWalkersComing() //call this at the end of every turn
{
    if(turnCounter > 49 || playerHero[0].getArmySize() > 2000 || tilesControlled > 199 || pointsTotal > 400 || heroes.size() == 1)
    {
        whiteWalkersComing = true; 
    }
}

bool Game::getWhiteWalkersAreComing()
{
    return whiteWalkersComing;
}

void Game::loadFiles()
{
    //just call game1.loadFiles(); when game starts
    loadMap();
    loadCities(); 
    loadWarriors();
    loadHeroes(); 
    //loadPlaces();
    //setAllOwnedWarriorLocations();
}

void Game::loadMap()
{
    string fileName = "mapGOT.txt";
    int rowIndex = 0;
    
    ifstream myFile; //create an input file stream, called myFile, for writing to file
    myFile.open(fileName); //open the file mapGOT.txt with the file stream
    
    if (myFile.is_open() == true) //if the file was successfully opened
    {
        string currentLine = "";
            
        while(getline(myFile, currentLine)) //read line by line and store line in a string 
        {
            if(currentLine.length() > 0) //if there's something on the line
            {
                char smallTemporaryArray[16];
                //int Game::split(string stringToBeSplit, char delimiter, char newArray[], int lengthNewArray)
                split(currentLine, ',', smallTemporaryArray, 16);
                for(int i = 0; i <  16; i++)
                {
                    bigMap[rowIndex][i] = smallTemporaryArray[i];
                }
                rowIndex++;
            }
        }
    }
    else if(myFile.fail()) //if file failed to open
    {
        cout << "ERROR: Map failed to load." << endl;
    }
    myFile.close();
}

void Game::loadHeroes() 
{
    string fileName = "heroesGOT.txt";
    
    ifstream myFile; 
    myFile.open(fileName); 
    
    if (myFile.is_open() == true) //if the file was successfully opened
    {
        string currentLine = "";
            
        while(getline(myFile, currentLine)) //read line by line and store line in a string 
        {
            Hero hero1; //create Hero object
            
            if(currentLine.length() > 0) //if there's something on the line
            {
                //<Name>,<$>,<influence>,<army_size>,<w1>,<w2>,<w3>,<w4>,<r>,<c>,<ship>
                //Cersei Lannister,8000,300,300,Jaime Lannister,The Mountain,NULL,NULL,16,7,no
                string temporaryString;
                int numberCommas = 0;
                    
                for(int i = 0; i < currentLine.length(); i++)
                {
                    if(currentLine[i] == ',') //reached delimiter
                    {
                        if(numberCommas == 0) //name complete
                        {
                            hero1.setName(temporaryString);
                        }
                        else if(numberCommas == 1) //money
                        {
                            hero1.setMoney(stoi(temporaryString));
                        }
                        else if(numberCommas == 2) //influence
                        {
                            hero1.setInfluence(stoi(temporaryString));
                        }
                        else if(numberCommas == 3) //army size
                        {
                            hero1.setArmySize(stoi(temporaryString));
                        }
                        else if(numberCommas == 4) //w1
                        {
                            //need to check if it says "NULL" or if there's a string
                            if(temporaryString != "NULL")
                            {
                                // Warrior warrior1;
                                // warrior1.setNameWarrior(temporaryString);
                                // hero1.addWarrior(warrior1);
                                hero1.addWarrior(getWarriorByName(temporaryString));
                            }
                        }
                        else if(numberCommas == 5) //w2
                        {
                            if(temporaryString != "NULL")
                            {
                                hero1.addWarrior(getWarriorByName(temporaryString));
                            }
                        }
                        else if(numberCommas == 6) //w3
                        {
                            if(temporaryString != "NULL")
                            {
                                hero1.addWarrior(getWarriorByName(temporaryString));
                            }
                        }
                        else if(numberCommas == 7) //w4
                        {
                            if(temporaryString != "NULL")
                            {
                                hero1.addWarrior(getWarriorByName(temporaryString));
                            }
                        }
                        else if(numberCommas == 8) //row
                        {
                            hero1.setRowLocation(stoi(temporaryString) - 1);
                        }
                        else if(numberCommas == 9) //column
                        {
                            hero1.setColumnLocation(stoi(temporaryString) - 1);
                        }
                        temporaryString = "";
                        numberCommas++;
                    }
                    else
                    {
                        temporaryString = temporaryString + currentLine[i];
                    }
                }
                if(numberCommas == 10) //has ship
                {
                    if(temporaryString == "yes")
                    {
                        hero1.addShip(true);
                    }
                }
                heroes.push_back(hero1);
            }
        }
    }
    else if(myFile.fail()) //if file failed to open
    {
        cout << "ERROR: " << fileName << " failed to load." << endl;
    }
    myFile.close();
}

Warrior Game::getWarriorByName(string warriorName)
{
    for(int i = 0; i < 14; i++)
    {
        if(warriors[i].getName() == warriorName)
        {
            return warriors[i];
        }
    }
}

void Game::addExtraHero(Hero inputHeroHere) //for if player choose to make their own
{
    heroes.push_back(inputHeroHere); //add to heroes vector
    playerHero[0] = inputHeroHere; //set this Hero to be playerHero
    cout << "Values applied. May they serve you well on your journey." << endl;
}

void Game::loadWarriors()
{
    string fileName = "warriorsGOT.txt";
    int warriorIndex = 0;
    
    ifstream myFile; 
    myFile.open(fileName); 
    
    if (myFile.is_open() == true) //if the file was successfully opened
    {
        string currentLine = "";
            
        while(getline(myFile, currentLine)) //read line by line and store line in a string 
        {
            if(currentLine.length() > 0) //if there's something on the line
            {
                Warrior warrior1; // create Warrior object
                
                //<Name>,<strength>,<loyalty>,<morale>,<free>,<ship>,<has_dragonglass>
                //Brienne of Tarth,100,100,50,no,no,no
                string temporaryString;
                int numberCommas = 0;
                    
                for(int i = 0; i < currentLine.length(); i++)
                {
                    if(currentLine[i] == ',') //reached delimiter
                    {
                        if(numberCommas == 0) //name complete
                        {
                            warrior1.setNameWarrior(temporaryString);
                        }
                        else if(numberCommas == 1) //strength
                        {
                            warrior1.setStrength(stoi(temporaryString));
                        }
                        else if(numberCommas == 2) //loyalty
                        {
                            warrior1.setLoyalty(stoi(temporaryString));
                        }
                        else if(numberCommas == 3) //morale
                        {
                            warrior1.setMorale(stoi(temporaryString));
                        }
                        else if(numberCommas == 4) //isFree yes/no
                        {
                            if(temporaryString == "yes")
                            {
                                warrior1.setIsFree(true);
                            }
                        }
                        else if(numberCommas == 5) //has ship?
                        {
                            if(temporaryString == "yes")
                            {
                                warrior1.addShipWarrior(true);
                            }
                        }
                        temporaryString = "";
                        numberCommas++;
                    }
                    else //haven't reached delimiter yet
                    {
                        temporaryString = temporaryString + currentLine[i]; //concatenate chars
                    }
                }
                if(numberCommas == 6) //has Dragonglass?
                {
                    if(temporaryString == "yes")
                    {
                        warrior1.addDragonglass(true);
                    }
                }
                // set random valid locations for row and column
                int rowRandom = random() % 25;
                int colRandom = random() % 15;
                bool locationIsSet = false;
                while(locationIsSet == false)
                {
                    if(bigMap[rowRandom][colRandom] == 'w' && warrior1.doesWarriorHaveShip() == false)
                    {
                        rowRandom = random() % 25;
                        colRandom = random() % 15;
                    }
                    else
                    {
                        warrior1.setRowWarrior(rowRandom);
                        warrior1.setColumnWarrior(colRandom);
                        locationIsSet = true;
                    }
                }
                warriors[warriorIndex] = warrior1;
                warriorIndex++;
            }
        }
    }
    else if(myFile.fail()) //if file failed to open
    {
        cout << "ERROR: " << fileName << " failed to load." << endl;
    }
    myFile.close();
}

void Game::setAllOwnedWarriorLocations()
{
    // set owned warrior locations to be the same as their heroes
    for(int h = 0; h < heroes.size(); h++) //go through the 6 heroes in the game
    {
        for(int w = 0; w < 14; w++) //go through the 14 warriors in the game
        {
            if(heroes[h].getOwnedWarriorVectorSize() > 0) //if current hero has owned warriors
            {
                for(int o = 0; o < heroes[h].getOwnedWarriorVectorSize(); o++) // go through the owned warriors vector for that hero
                {
                    if(heroes[h].getOwnedWarriorName(o) == warriors[w].getName()) //find the owned warrior in the big warriors array
                    {
                        warriors[w].setRowWarrior(heroes[h].getRowHero()); //set the owned warrior's location the same as the heroe's
                        warriors[w].setColumnWarrior(heroes[h].getColumnHero());
                    }
                }
            }
        }
    }
}

void Game::loadCities()
{
    string fileName = "citiesGOT.txt";
    int cityIndex = 0;
    
    ifstream myFile; 
    myFile.open(fileName); 
    
    if (myFile.is_open() == true) //if the file was successfully opened
    {
        string currentLine = "";
            
        while(getline(myFile, currentLine)) //read line by line and store line in a string 
        {
            City city1; // create City object
            string temporaryString = "";
            
            if(currentLine.length() > 0) //if there's something on the line
            {
                //<Letter>,<Name>,<$>,<army_size>,<points>
                //A,Castle Black,15,15,3
                int countCommas = 0;
                    
                for(int i = 0; i < currentLine.length(); i++)
                {
                    if(currentLine[i] == ',') //delimiter reached
                    {
                        if(countCommas == 0) //char of the city
                        {
                            city1.setLetterCity(temporaryString[0]);
                        }
                        else if(countCommas == 1) //name
                        {
                            city1.setNameCity(temporaryString);
                        }
                        else if(countCommas == 2) //money
                        {
                            city1.setMoneyCity(stoi(temporaryString));
                        }
                        else if(countCommas == 3) //army size
                        {
                            city1.setArmySize(stoi(temporaryString));
                        }
                        countCommas++;
                        temporaryString = "";
                    }
                    else
                    {
                        temporaryString = temporaryString + currentLine[i]; //concatenate chars
                    }
                }
                if(countCommas == 4) //points
                {
                    city1.setPointsCity(stoi(temporaryString));
                }
                cities[cityIndex] = city1;
                cityIndex++;
            }
        }
    }
    else if(myFile.fail()) //if file failed to open
    {
        cout << "ERROR: " << fileName << " failed to load." << endl;
    }
    myFile.close();
}

void Game::loadPlaces() 
{
    for(int i = 0; i < 26; i++)
    {
        for(int j = 0; j < 15; j++)
        {
            if(bigMap[i][j] >= 'A' && bigMap[i][j] <= 'Z') //if this location is a CITY
            {
                for(int k = 0; k < 26; k++)
                {
                    if(cities[k].getLetterCity() == bigMap[i][j])
                    {
                        places[i][j].addCityObject(cities[k]); //add City object to THIS location of places[][]
                    }
                }
            }
        }
    }
}

int Game::getPointsCity(char letterCity)
{
    for(int i = 0; i < 26; i++)
    {
        if(letterCity == cities[i].getLetterCity())
        {
            return cities[i].getPointsCity();
        }
    }
}

int Game::split(string stringToBeSplit, char delimiter, char newArray[16], int lengthNewArray)
{
    int countSubStrings = 0;
    int arrayIndex = 0;
    char currentChar;
    
    for(int i = 0; i < stringToBeSplit.length(); i++) //traverse stringToBeSplit
    {
        if(stringToBeSplit == "") //if input string is empty
        {
            countSubStrings = 0;
            return countSubStrings;
        }
        if(arrayIndex < lengthNewArray) //if new array's capacity isn't full yet
        {
            currentChar = stringToBeSplit[i];
        
            if(currentChar != delimiter) //current char isn't a delimiter
            {
                newArray[arrayIndex] = currentChar; 
                arrayIndex++;
            }
        }
    }
    countSubStrings = arrayIndex;
    return countSubStrings;
}

void Game::printBigMap() //do only once at the beginning
{
    for(int i = 0; i < 25; i++)
    {
        for(int j = 0; j < 16; j++)
        {
            char currentChar = bigMap[i][j];
            if(currentChar == 'w')
            {
                cout << " ~ ";
            }
            else if(currentChar == 'p')
            {
                cout << " * ";
            }
            else if(currentChar >= 'A' && currentChar <= 'Z')
            {
                cout << " " << currentChar << " ";
            }
        }
        cout << endl;
    }
}

void Game::printSmallMap() //at the beginning of every turn
{
    int rowHero = playerHero[0].getRowHero();
    int columnHero = playerHero[0].getColumnHero();
    char currentLocation = bigMap[rowHero][columnHero];
    bool validPosition = false;
    cout << endl << "Consulting map... " << endl << endl;
    
    for(int i = rowHero - 3; i < rowHero + 4; i++) //row
    {
        for(int j = columnHero - 3; j < columnHero + 4; j++) //column
        {
            if(i >= 0 && i <= 24 && j >= 0 && j <= 15)
            {
                validPosition = true;
                if(i == rowHero && j == columnHero)
                {
                    cout << "[+]";
                }
                else
                {
                    if(bigMap[i][j] == 'w')
                    {
                        cout << " ~ ";
                    }
                    else if(bigMap[i][j] == 'p')
                    {
                        cout << " * ";
                    }
                    else if(bigMap[i][j] >= 'A' && bigMap[i][j] <= 'Z')
                    {
                        cout << " " << bigMap[i][j] << " ";
                    }
                }
            }
        }
        if(validPosition == true)
        {
            cout << endl;
        }
    }
    cout << endl << "Your Grace ";
    if(currentLocation == 'w')
    {
        cout << "conquers the seas" << endl << endl;
    }
    else if(currentLocation == 'p')
    {
        cout << "explores the unbridled land" << endl << endl;
    }
    if(currentLocation >= 'A' && currentLocation <= 'Z')
    {
        string currentCity;
        for(int k = 0; k < 26; k++)
        {
            if(cities[k].getLetterCity() == currentLocation)
            {
                currentCity = cities[k].getNameCity();
            }
        }
        cout << "blesses the city of " << currentCity << " (" << currentLocation << ")" << endl << endl;
    }
}

// Game Over functions
void Game::whiteWalkerBattle()
{
    // BATTTTTTLEEEE
    cout << endl << "You have chosen to battle the White Walkers" << endl;
    double playerPowerScore = playerHero[0].getPowerScore();
    playerPowerScore = playerPowerScore + ((getTilesControlled() + 1) * (playerHero[0].getInfluence() / 4)); //should this be Cities controlled, not tiles??
    if(playerHero[0].getHasDragonglassHero() == true)
    {
        playerPowerScore = playerPowerScore + 10000;
    }
    double probabilityWinGame = 1 - exp((-1 * playerPowerScore) / 30000);
    cout << "probability winning against White Walkers: " << probabilityWinGame << endl;
    int timesWon = 0;
    double randomNumber = (random() % 100 + 1) / 100;
    for(int i = 0; i < 3; i++)
    {
        // calculate random score??
        randomNumber = (random() % 100 + 1) / 100;
        if(randomNumber <= probabilityWinGame)
        {
            timesWon++;
        }
    }
    if(timesWon >= 1)
    {
        setWonOrLost("won");
        return;
    }
    else
    {
        cout << endl << "Oh no! The White Walkers are surrounding you. There's no escape..." << endl;
        setWonOrLost("lost");
        return;
    }
}

void Game::setTimesDeniedWhiteWalkerBattle(int inputTimes)
{
    timesDeniedWhiteWalkerBattle = timesDeniedWhiteWalkerBattle + inputTimes;
}

int Game::getTimesDeniedWhiteWalkerBattle()
{
    return timesDeniedWhiteWalkerBattle;
}
    
void Game::setWonOrLost(string inputWinOrLose)
{
    wonOrLost = inputWinOrLose;
    if(wonOrLost == "lost")
    {
        cout << endl << "GAME OVER. Your Grace has been defeated." << endl;
    }
    else if(wonOrLost == "won")
    {
        cout << endl << "You did it! You defeated the White Walkers. The throne is yours. ";
        cout << "May you rule for a thousand years. " << endl;
    }
    writeToScoreBoard();
}

string Game::getWonOrLost()
{
    return wonOrLost;
}
    
void Game::writeToScoreBoard() //after Game Over, writes player's stats to a .txt file // <username> <Hero> <points score> <won/lost>
{
    ofstream outputPlayerResults;
    outputPlayerResults.open("resultsGOT.txt", ios_base::app); //I got this from Telly on Piazza
    outputPlayerResults << playerUsername << " <" << playerHero[0].getNameHero() << "> " << pointsTotal << " " << wonOrLost << endl;
    outputPlayerResults.close();
}

void Game::printScoreBoard()
{
    //use file stream to open Scoreboard text, create Playerscore objects, sort by points, find the top 5 scores, and print them to the screen
    //vector<Playerscore> scoreBoard; //vector of scores for Game Over printing
    cout << endl << "THE NORTH REMEMBERS" << endl << endl;
    cout << "USERNAME " << "   HERO PLAYED " << " SCORE " << " OUTCOME " << endl << endl;
    ifstream playerResults;
    playerResults.open("resultsGOT.txt");
    if(playerResults.is_open() == true)
    {
        string results;
        while(getline(playerResults, results))
        {
            cout << results << endl;
        }
        /**
        while(getline(playerResults, results))
        {
            Playerscore player1; //create Playerscore object
            int numDashes = 0;
            string tempString;
            if(results.length() > 0) //if there's something on the line
            {
                // parse the text and sort the results --> <username>-<Hero>-<points score>-<won/lost>
                for(int i = 0; i < results.length(); i++)
                {
                    if(results[i] == '-')
                    {
                        numDashes++;
                        if(numDashes == 1) //the username
                        {
                            player1.setUsername(tempString);
                            tempString = "";
                        }
                        else if(numDashes == 2) //the Hero name
                        {
                            player1.setHeroName(tempString);
                            tempString = "";
                        }
                        else if(numDashes == 3) //the points
                        {
                            player1.setPointsScore(stoi(tempString));
                            tempString = "";
                        }
                        else if(numDashes == 4) // won or lost?
                        {
                            player1.setWonLost(tempString);
                            tempString = "";
                        }
                    }
                    else
                    {
                        tempString = tempString + results[i];
                    }
                }
            }
            scoreBoard.push_back(player1); //add Playerscore object to vector
        }
        int highestScore;
        int highestScoreIndex = 0;
        Playerscore scoreBoard2[5]; //an array of Playerscore objects
        
        for(int k = 0; k < 5; k++)
        {
            for(int j = 0; j < scoreBoard.size(); j++)
            {
                if(scoreBoard[j].getPointsScore() > highestScore)
                {
                    highestScore = scoreBoard[j].getPointsScore();
                    highestScoreIndex = j;
                }
            }
            scoreBoard2[k] = scoreBoard[highestScoreIndex]; //add object with the highest score to array
            //heroes.erase(heroes.begin() + EnemyHeroIndex);
            scoreBoard.erase(scoreBoard.begin() + highestScoreIndex); //remove highest score from vector
        }
        
        cout << fixed << setw(10) << "THE NORTH REMEMBERS" << endl << endl;
        cout << fixed << setw(5) << "USERNAME" << "HERO PLAYED" << "SCORE" << "OUTCOME" << endl << endl;
        for(int numScores = 0; numScores < 5; numScores++)
        {
            //<username>-<Hero>-<points score>-<won/lost>
            cout << fixed << setw(5) << scoreBoard2[numScores].getUsername() << scoreBoard2[numScores].getHeroName() << scoreBoard2[numScores].getPointsScore() << scoreBoard2[numScores].getWonLost() << endl;
        }
        */
    }
    exit(0);
}
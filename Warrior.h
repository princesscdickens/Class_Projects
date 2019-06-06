// CS1300 Spring 2019
// Author: Princess Dickens
// Recitation: 207 - Shipra Behera
// Cloud9 Workspace Editor Link: https://ide.c9.io/pdickens/csci1300_pdickens
// Project 3

// WARRIOR header

#ifndef WARRIOR_H
#define WARRIOR_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;

class Warrior
{
    private:
    string nameWarrior;
    int strength;
    int loyalty;
    int morale;
    bool isFree;
    bool hasShipWarrior;
    bool hasDragonglass;
    int rowWarrior;
    int columnWarrior;
    
    public:
    //constructors
    Warrior();
    Warrior(string inputNameWarrior, int inputStrength, int inputLoyalty, int inputMorale, bool inputIsFree, bool inputHasShipWarrior, bool inputHasDragonglass);
    
    //setters
    void setNameWarrior(string inputNameWarrior);
    void setStrength(int inputStrength);
    void setLoyalty(int inputLoyalty);
    void setMorale(int inputMorale);
    void setIsFree(bool inputIsFree);
    void addShipWarrior(bool inputHasShipWarrior);
    void addDragonglass(bool inputHasDragonglass);
    void setRowWarrior(int inputRowWarrior);
    void setColumnWarrior(int inputColumnWarrior);
    
    //getters
    string getName();
    int getStrength();
    int getLoyalty();
    int getMorale();
    bool getIsFree();
    bool doesWarriorHaveShip();
    bool doesWarriorHaveDragonglass();
    int getRowWarrior();
    int getColumnWarrior();
};
#endif
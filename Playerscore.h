#ifndef PLAYERSCORE_H
#define PLAYERSCORE_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Playerscore
{
    private:
    // <username>-<Hero>-<points score>-<won/lost>
    string username;
    string heroName;
    int pointsScore;
    string wonLost;
    
    public:
    //constructor
    Playerscore();
    Playerscore(string inputUsername, string inputHeroName, int inputPointsScore, string inputWonLost);
    
    //setters
    void setUsername(string inputUsername);
    void setHeroName(string inputHeroName);
    void setPointsScore(int inputPointsScore);
    void setWonLost(string inputWonLost);
    
    //getters
    string getUsername();
    string getHeroName();
    int getPointsScore();
    string getWonLost();
};
#endif
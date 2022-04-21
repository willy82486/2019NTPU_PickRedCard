#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>
#include <ctime>
#include <cmath>
#include <cstring>
#include <windows.h>
#include <algorithm>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <utility>

#define CODE 724
#define CODE2 724

using namespace std;

bool comp(pair<int,int> a,pair<int,int> b);
bool comp2(pair<int,int> a,pair<int,int> b);

class Card{
    friend ostream &operator<<(ostream &,const Card &);
private:
    map<string,int> Suit;
    //-----------------------------------------------------------------
    string Spade[9]={
                  "|             |",
                  "|      *      |",
                  "|    *****    |",
                  "|  *********  |",
                  "| *********** |",
                  "|  *** * ***  |",
                  "|     ***     |",
                  "|    *****    |",
                  "|             |"
    };
    string Heart[9]={
                  "|             |",
                  "|   **   **   |",
                  "|  **** ****  |",
                  "| *********** |",
                  "|  *********  |",
                  "|   *******   |",
                  "|     ***     |",
                  "|      *      |",
                  "|             |"
    };
    string Diamond[9]={
                  "|             |",
                  "|      *      |",
                  "|     ***     |",
                  "|    *****    |",
                  "|   *******   |",
                  "|    *****    |",
                  "|     ***     |",
                  "|      *      |",
                  "|             |"
    };
    string Club[9]={
                  "|             |",
                  "|     ***     |",
                  "|    *****    |",
                  "|  ** *** **  |",
                  "| **** * **** |",
                  "|  **  *  **  |",
                  "|     ***     |",
                  "|    *****    |",
                  "|             |"
    };


    string Number[14]={" ","A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    string Asuit[5]={" ","Spade","Heart","Diamond","Club"};
    //-------------------------------------------------------------------------------------
    vector<pair<int,int> > player[4],groundcard,underseacard,canthrow[4],canthrowunder,NumberOfCard,secretplayer[4],secretgroundcard,secretunderseacard;
    vector<int> tmpcount,tmpsuit,tmpnum,tmpusuit,tmpunum;
    int PlayerNum,bestposition,total[4],checktotal[4];
    int checkflag;
//-----------------------------------------------------------------------------
public:
    Card();
    Card(int);
    void SetColor(int = 7);
    bool Deal(int);//�P�_��e��P�O�X�P�٬O�\�P
    void flip(int,pair<int,int>);
    void Run();//Ū���C����J
    bool ChooseCard(pair<int,int> ,pair<int,int>);//�H���X�P�P�_
    void PrintHuman();//�H����P
    void drawpair(pair<int,int>,pair<int,int>);
    void drawsingle(pair<int,int>);
    void PrintField();//���W���P
    int read();//Ū��
    int ERR(int );
};



#endif // CARD_H_INCLUDED


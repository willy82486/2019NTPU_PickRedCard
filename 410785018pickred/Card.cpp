#include "Card.h"

ostream &operator<<(ostream &out,const Card &a){

    out<<"Player has "<<a.total[0]<<" points."<<endl;
    for(int i=1;i<a.PlayerNum;i++){
        out<<"Computer "<<i<<" has "<<a.total[i]<<" points."<<endl;
    }
    int Max=a.total[0];
    for(int i=1;i<a.PlayerNum;i++){
        if(a.total[i]>Max){
            Max=a.total[i];
        }
    }
    for(int i=0;i<a.PlayerNum;i++){
        if(a.total[i]==Max&&i==0){
            out<<"Player wins!!!"<<endl;
        }
        else if(a.total[i]==Max&&i!=0){
            out<<"Computer "<<i<<" wins!!!"<<endl;
        }
    }
    return out;
}

bool comp(pair<int,int> a,pair<int,int> b){
	if(a.first==b.first){
		return a.second<b.second;
	}
	return a.first<b.first;
}
bool comp2(pair<int,int> a,pair<int,int> b){
	if(a.second==b.second){
		return a.first<b.first;
	}
	return a.second<b.second;
}
//---------------------------------------------------------------------------------------------------------
void Card::SetColor(int color){
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,color);
}
//---------------------------------------------------------------------------------------------------------

Card::Card(int playerNum){
    srand(time(NULL));
    //-----------------------------------------------------------------------------------------------------
    PlayerNum=playerNum;
    //-----------------------------------------------------------------------------------------------------
    memset(total,0,sizeof(total));
    //-----------------------------------------------------------------------------------------------------
    Suit["Spade"]=1;
    Suit["Heart"]=2;
    Suit["Diamond"]=3;
    Suit["Club"]=4;
    //-----------------------------------------------------------------------------------------------------
    for(int i=0;i<13;i++){
        NumberOfCard.push_back(make_pair(1,i%13+1));
    }
    for(int i=13;i<26;i++){
        NumberOfCard.push_back(make_pair(2,i%13+1));
    }
    for(int i=26;i<39;i++){
        NumberOfCard.push_back(make_pair(3,i%13+1));
    }
    for(int i=39;i<52;i++){
        NumberOfCard.push_back(make_pair(4,i%13+1));
    }
    //----------------------------------------------------------------------------------------------------

    random_shuffle(NumberOfCard.begin(),NumberOfCard.end());
    //----------------------------------------------------------------------------------------------------
    for(int i=0;i<24;i++){
        player[i%PlayerNum].push_back(NumberOfCard[i]);
    }
    for(int i=24;i<28;i++){
        underseacard.push_back(NumberOfCard[i]);
    }
    for(int i=28;i<52;i++){
        groundcard.push_back(NumberOfCard[i]);
    }
    //----------------------------------------------------------------------------------------------------
    for(int i=0;i<PlayerNum;i++){
        sort(player[i].begin(),player[i].end(),comp);
    }
    sort(underseacard.begin(),underseacard.end(),comp);

    cout<<"Card on the field :"<<endl;
    PrintField();

    if(!player[0].empty()){
            cout<<"Card that you have :"<<endl;
            PrintHuman();
    }
    //----------------------------------------------------------------------------------------------------
    Run();
    //----------------------------------------------------------------------------------------------------
}

Card::Card(){
    checkflag=0;
    Suit["Spade"]=1;
    Suit["Heart"]=2;
    Suit["Diamond"]=3;
    Suit["Club"]=4;

    memset(total,0,sizeof(total));
    read();
    if(checkflag==1){
    }
    else{
        Run();
    }
}

bool Card::Deal(int num_player){
        //*****--------------------------------------------------------------------------------------------------------------------------------
        for(int idx = 0 ; idx < player[num_player].size() ; idx++){
            int tmpvalue = 0;
            for(int idx2=0;idx2<underseacard.size();idx2++){
                //***--------------------------------------------------------------------------------------------------------------------1 and 9
                if(  (player[num_player][idx].second== 1&&underseacard[idx2].second==9) || (player[num_player][idx].second==9&&underseacard[idx2].second==1)  ){

                    //------------------------------------------------------------------------------------------------------1/9 computer Spade 1
                    if( (player[num_player][idx].second== 1&&player[num_player][idx].first== 1) && (underseacard[idx2].first==2||underseacard[idx2].first==3) ){
                        tmpvalue=30+9;
                        tmpcount.push_back(tmpvalue);
                        tmpsuit.push_back(player[num_player][idx].first);
                        tmpnum.push_back(player[num_player][idx].second);
                        tmpusuit.push_back(underseacard[idx2].first);
                        tmpunum.push_back(underseacard[idx2].second);
                        tmpvalue=0;

                    }

                    else if( (player[num_player][idx].second== 1&&player[num_player][idx].first== 1) && (underseacard[idx2].first==1||underseacard[idx2].first==4) ){
                        tmpvalue=30;
                        tmpcount.push_back(tmpvalue);
                        tmpsuit.push_back(player[num_player][idx].first);
                        tmpnum.push_back(player[num_player][idx].second);
                        tmpusuit.push_back(underseacard[idx2].first);
                        tmpunum.push_back(underseacard[idx2].second);
                        tmpvalue=0;

                    }
                    //------------------------------------------------------------------------------------------------------1/9 computer red 1
                    else if( (player[num_player][idx].second== 1&&( player[num_player][idx].first== 2 || player[num_player][idx].first== 3) ) && (underseacard[idx2].first==2||underseacard[idx2].first==3)   ) {
                        tmpvalue=20+9;
                        tmpcount.push_back(tmpvalue);
                        tmpsuit.push_back(player[num_player][idx].first);
                        tmpnum.push_back(player[num_player][idx].second);
                        tmpusuit.push_back(underseacard[idx2].first);
                        tmpunum.push_back(underseacard[idx2].second);
                        tmpvalue=0;

                    }
                    else if( (player[num_player][idx].second== 1&&( player[num_player][idx].first== 2 || player[num_player][idx].first== 3) ) && (underseacard[idx2].first==1||underseacard[idx2].first==4)   ) {
                        tmpvalue=20+0;
                        tmpcount.push_back(tmpvalue);
                        tmpsuit.push_back(player[num_player][idx].first);
                        tmpnum.push_back(player[num_player][idx].second);
                        tmpusuit.push_back(underseacard[idx2].first);
                        tmpunum.push_back(underseacard[idx2].second);
                        tmpvalue=0;

                    }
                    //------------------------------------------------------------------------------------------------------1/9 computer Club 1
                    else if( (player[num_player][idx].second== 1&& player[num_player][idx].first== 4)  && (underseacard[idx2].first==2||underseacard[idx2].first==3)  ) {
                        tmpvalue=9;
                        tmpcount.push_back(tmpvalue);
                        tmpsuit.push_back(player[num_player][idx].first);
                        tmpnum.push_back(player[num_player][idx].second);
                        tmpusuit.push_back(underseacard[idx2].first);
                        tmpunum.push_back(underseacard[idx2].second);
                        tmpvalue=0;

                    }
                    else if( (player[num_player][idx].second== 1&& player[num_player][idx].first== 4)  && (underseacard[idx2].first==1||underseacard[idx2].first==4)  ) {
                        tmpvalue=0;
                        tmpcount.push_back(tmpvalue);
                        tmpsuit.push_back(player[num_player][idx].first);
                        tmpnum.push_back(player[num_player][idx].second);
                        tmpusuit.push_back(underseacard[idx2].first);
                        tmpunum.push_back(underseacard[idx2].second);
                        tmpvalue=0;

                    }
                    //------------------------------------------------------------------------------------------------------9/1 computer red 9
                    else if( (player[num_player][idx].second== 9&& ( player[num_player][idx].first== 2 || player[num_player][idx].first== 3) )  && (underseacard[idx2].first==2||underseacard[idx2].first==3)   ) {
                        tmpvalue=9+20;
                        tmpcount.push_back(tmpvalue);
                        tmpsuit.push_back(player[num_player][idx].first);
                        tmpnum.push_back(player[num_player][idx].second);
                        tmpusuit.push_back(underseacard[idx2].first);
                        tmpunum.push_back(underseacard[idx2].second);
                        tmpvalue=0;

                    }
                    else if( (player[num_player][idx].second== 9&& ( player[num_player][idx].first== 2 || player[num_player][idx].first== 3) )  && underseacard[idx2].first==1 ) {
                        tmpvalue=9+30;
                        tmpcount.push_back(tmpvalue);
                        tmpsuit.push_back(player[num_player][idx].first);
                        tmpnum.push_back(player[num_player][idx].second);
                        tmpusuit.push_back(underseacard[idx2].first);
                        tmpunum.push_back(underseacard[idx2].second);
                        tmpvalue=0;

                    }
                    else if( (player[num_player][idx].second== 9&& ( player[num_player][idx].first== 2 || player[num_player][idx].first== 3) )  && underseacard[idx2].first==4 ) {
                        tmpvalue=9+0;
                        tmpcount.push_back(tmpvalue);
                        tmpsuit.push_back(player[num_player][idx].first);
                        tmpnum.push_back(player[num_player][idx].second);
                        tmpusuit.push_back(underseacard[idx2].first);
                        tmpunum.push_back(underseacard[idx2].second);
                        tmpvalue=0;

                    }
                    //------------------------------------------------------------------------------------------------------9/1 computer black 9
                    else if( (player[num_player][idx].second== 9&& ( player[num_player][idx].first== 1 || player[num_player][idx].first== 4) )  && (underseacard[idx2].first==2||underseacard[idx2].first==3)   ) {
                        tmpvalue=0+20;
                        tmpcount.push_back(tmpvalue);
                        tmpsuit.push_back(player[num_player][idx].first);
                        tmpnum.push_back(player[num_player][idx].second);
                        tmpusuit.push_back(underseacard[idx2].first);
                        tmpunum.push_back(underseacard[idx2].second);
                        tmpvalue=0;

                    }
                    else if( (player[num_player][idx].second== 9&& ( player[num_player][idx].first== 1 || player[num_player][idx].first== 4) )  && underseacard[idx2].first==1 ) {
                        tmpvalue=0+30;
                        tmpcount.push_back(tmpvalue);
                        tmpsuit.push_back(player[num_player][idx].first);
                        tmpnum.push_back(player[num_player][idx].second);
                        tmpusuit.push_back(underseacard[idx2].first);
                        tmpunum.push_back(underseacard[idx2].second);
                        tmpvalue=0;

                    }
                    else if( (player[num_player][idx].second== 9&& ( player[num_player][idx].first== 1 || player[num_player][idx].first== 4) )  && underseacard[idx2].first==4 ) {
                        tmpvalue=0+0;
                        tmpcount.push_back(tmpvalue);
                        tmpsuit.push_back(player[num_player][idx].first);
                        tmpnum.push_back(player[num_player][idx].second);
                        tmpusuit.push_back(underseacard[idx2].first);
                        tmpunum.push_back(underseacard[idx2].second);
                        tmpvalue=0;

                    }
                }
                //***---------------------------------------------------------------------------------------------------------------------13 and 13
                else if(  player[num_player][idx].second== 13 && underseacard[idx2].second==13 ){

                    //-----------------------------------------------------------------------------------------------------red 13 red 13
                    if(  (player[num_player][idx].first== 2||player[num_player][idx].first== 3) && (underseacard[idx2].first==2||underseacard[idx2].first==3)  ){
                        tmpvalue=13+13;
                        tmpcount.push_back(tmpvalue);
                        tmpsuit.push_back(player[num_player][idx].first);
                        tmpnum.push_back(player[num_player][idx].second);
                        tmpusuit.push_back(underseacard[idx2].first);
                        tmpunum.push_back(underseacard[idx2].second);
                        tmpvalue=0;

                    }
                    //-----------------------------------------------------------------------------------------------------red 13 black 13
                    else if(  (player[num_player][idx].first== 2||player[num_player][idx].first== 3) && (underseacard[idx2].first==1||underseacard[idx2].first==4)){
                        tmpvalue=13+0;
                        tmpcount.push_back(tmpvalue);
                        tmpsuit.push_back(player[num_player][idx].first);
                        tmpnum.push_back(player[num_player][idx].second);
                        tmpusuit.push_back(underseacard[idx2].first);
                        tmpunum.push_back(underseacard[idx2].second);
                        tmpvalue=0;

                    }
                    //-----------------------------------------------------------------------------------------------------black 13 red 13
                    else if(  (player[num_player][idx].first== 1||player[num_player][idx].first== 4) && (underseacard[idx2].first==2||underseacard[idx2].first==3)){
                        tmpvalue=0+13;
                        tmpcount.push_back(tmpvalue);
                        tmpsuit.push_back(player[num_player][idx].first);
                        tmpnum.push_back(player[num_player][idx].second);
                        tmpusuit.push_back(underseacard[idx2].first);
                        tmpunum.push_back(underseacard[idx2].second);
                        tmpvalue=0;

                    }
                    //-----------------------------------------------------------------------------------------------------black 13 black 13
                    else if(  (player[num_player][idx].first== 1||player[num_player][idx].first== 4) && (underseacard[idx2].first==1||underseacard[idx2].first==4)){
                        tmpvalue=0+0;
                        tmpcount.push_back(tmpvalue);
                        tmpsuit.push_back(player[num_player][idx].first);
                        tmpnum.push_back(player[num_player][idx].second);
                        tmpusuit.push_back(underseacard[idx2].first);
                        tmpunum.push_back(underseacard[idx2].second);
                        tmpvalue=0;

                    }
                }
                //***---------------------------------------------------------------------------------------------------------------------12 and 12
                else if(  player[num_player][idx].second== 12&&underseacard[idx2].second==12 ){

                    //-----------------------------------------------------------------------------------------------------red 12 red 12
                    if(  (player[num_player][idx].first== 2||player[num_player][idx].first== 3) && (underseacard[idx2].first==2||underseacard[idx2].first==3)  ){
                        tmpvalue=12+12;
                        tmpcount.push_back(tmpvalue);
                        tmpsuit.push_back(player[num_player][idx].first);
                        tmpnum.push_back(player[num_player][idx].second);
                        tmpusuit.push_back(underseacard[idx2].first);
                        tmpunum.push_back(underseacard[idx2].second);
                        tmpvalue=0;

                    }
                    //-----------------------------------------------------------------------------------------------------red 12 black 12
                    else if(  (player[num_player][idx].first== 2||player[num_player][idx].first== 3) && (underseacard[idx2].first==1||underseacard[idx2].first==4)){
                        tmpvalue=12+0;
                        tmpcount.push_back(tmpvalue);
                        tmpsuit.push_back(player[num_player][idx].first);
                        tmpnum.push_back(player[num_player][idx].second);
                        tmpusuit.push_back(underseacard[idx2].first);
                        tmpunum.push_back(underseacard[idx2].second);
                        tmpvalue=0;

                    }
                    //-----------------------------------------------------------------------------------------------------black 12 red 12
                    else if(  (player[num_player][idx].first== 1||player[num_player][idx].first== 4) && (underseacard[idx2].first==2||underseacard[idx2].first==3)){
                        tmpvalue=0+12;
                        tmpcount.push_back(tmpvalue);
                        tmpsuit.push_back(player[num_player][idx].first);
                        tmpnum.push_back(player[num_player][idx].second);
                        tmpusuit.push_back(underseacard[idx2].first);
                        tmpunum.push_back(underseacard[idx2].second);
                        tmpvalue=0;

                    }
                    //-----------------------------------------------------------------------------------------------------black 12 black 12
                    else if(  (player[num_player][idx].first== 1||player[num_player][idx].first== 4) && (underseacard[idx2].first==1||underseacard[idx2].first==4)){
                        tmpvalue=0+0;
                        tmpcount.push_back(tmpvalue);
                        tmpsuit.push_back(player[num_player][idx].first);
                        tmpnum.push_back(player[num_player][idx].second);
                        tmpusuit.push_back(underseacard[idx2].first);
                        tmpunum.push_back(underseacard[idx2].second);
                        tmpvalue=0;

                    }

                }
                //***---------------------------------------------------------------------------------------------------------------------11 and 11
                else if(  player[num_player][idx].second== 11&&underseacard[idx2].second==11 ){

                    //-----------------------------------------------------------------------------------------------------red 11 red 11
                    if(  (player[num_player][idx].first== 2||player[num_player][idx].first== 3) && (underseacard[idx2].first==2||underseacard[idx2].first==3)  ){
                        tmpvalue=11+11;
                        tmpcount.push_back(tmpvalue);
                        tmpsuit.push_back(player[num_player][idx].first);
                        tmpnum.push_back(player[num_player][idx].second);
                        tmpusuit.push_back(underseacard[idx2].first);
                        tmpunum.push_back(underseacard[idx2].second);
                        tmpvalue=0;

                    }
                    //-----------------------------------------------------------------------------------------------------red 11 black 11
                    else if(  (player[num_player][idx].first== 2||player[num_player][idx].first== 3) && (underseacard[idx2].first==1||underseacard[idx2].first==4)){
                        tmpvalue=11+0;
                        tmpcount.push_back(tmpvalue);
                        tmpsuit.push_back(player[num_player][idx].first);
                        tmpnum.push_back(player[num_player][idx].second);
                        tmpusuit.push_back(underseacard[idx2].first);
                        tmpunum.push_back(underseacard[idx2].second);
                        tmpvalue=0;

                    }
                    //-----------------------------------------------------------------------------------------------------black 11 red 11
                    else if(  (player[num_player][idx].first== 1||player[num_player][idx].first== 4) && (underseacard[idx2].first==2||underseacard[idx2].first==3)){
                        tmpvalue=0+11;
                        tmpcount.push_back(tmpvalue);
                        tmpsuit.push_back(player[num_player][idx].first);
                        tmpnum.push_back(player[num_player][idx].second);
                        tmpusuit.push_back(underseacard[idx2].first);
                        tmpunum.push_back(underseacard[idx2].second);
                        tmpvalue=0;

                    }
                    //-----------------------------------------------------------------------------------------------------black 11 black 11
                    else if(  (player[num_player][idx].first== 1||player[num_player][idx].first== 4) && (underseacard[idx2].first==1||underseacard[idx2].first==4)){
                        tmpvalue=0+0;
                        tmpcount.push_back(tmpvalue);
                        tmpsuit.push_back(player[num_player][idx].first);
                        tmpnum.push_back(player[num_player][idx].second);
                        tmpusuit.push_back(underseacard[idx2].first);
                        tmpunum.push_back(underseacard[idx2].second);
                        tmpvalue=0;

                    }
                }
                //***---------------------------------------------------------------------------------------------------------------------10 and 10
                else if(  player[num_player][idx].second== 10&&underseacard[idx2].second==10 ){

                    //-----------------------------------------------------------------------------------------------------red 10 red 10
                    if(  (player[num_player][idx].first== 2||player[num_player][idx].first== 3) && (underseacard[idx2].first==2||underseacard[idx2].first==3)  ){
                        tmpvalue=10+10;
                        tmpcount.push_back(tmpvalue);
                        tmpsuit.push_back(player[num_player][idx].first);
                        tmpnum.push_back(player[num_player][idx].second);
                        tmpusuit.push_back(underseacard[idx2].first);
                        tmpunum.push_back(underseacard[idx2].second);
                        tmpvalue=0;

                    }
                    //-----------------------------------------------------------------------------------------------------red 10 black 10
                    else if(  (player[num_player][idx].first== 2||player[num_player][idx].first== 3) && (underseacard[idx2].first==1||underseacard[idx2].first==4)){
                        tmpvalue=10+0;
                        tmpcount.push_back(tmpvalue);
                        tmpsuit.push_back(player[num_player][idx].first);
                        tmpnum.push_back(player[num_player][idx].second);
                        tmpusuit.push_back(underseacard[idx2].first);
                        tmpunum.push_back(underseacard[idx2].second);
                        tmpvalue=0;

                    }
                    //-----------------------------------------------------------------------------------------------------black 10 red 10
                    else if(  (player[num_player][idx].first== 1||player[num_player][idx].first== 4) && (underseacard[idx2].first==2||underseacard[idx2].first==3)){
                        tmpvalue=0+10;
                        tmpcount.push_back(tmpvalue);
                        tmpsuit.push_back(player[num_player][idx].first);
                        tmpnum.push_back(player[num_player][idx].second);
                        tmpusuit.push_back(underseacard[idx2].first);
                        tmpunum.push_back(underseacard[idx2].second);
                        tmpvalue=0;

                    }
                    //-----------------------------------------------------------------------------------------------------black 10 black 10
                    else if(  (player[num_player][idx].first== 1||player[num_player][idx].first== 4) && (underseacard[idx2].first==1||underseacard[idx2].first==4)){
                        tmpvalue=0+0;
                        tmpcount.push_back(tmpvalue);
                        tmpsuit.push_back(player[num_player][idx].first);
                        tmpnum.push_back(player[num_player][idx].second);
                        tmpusuit.push_back(underseacard[idx2].first);
                        tmpunum.push_back(underseacard[idx2].second);
                        tmpvalue=0;

                    }
                }
                //***---------------------------------------------------------------------------------------------------------------------less than 8 more then 2
                else if(  player[num_player][idx].second>= 2 && underseacard[idx2].second>=2 && player[num_player][idx].second<= 8 && underseacard[idx2].second<=8 && player[num_player][idx].second+underseacard[idx2].second==10){
                    //-----------------------------------------------------------------------------------------------------red red
                    if(  (player[num_player][idx].first== 2||player[num_player][idx].first== 3) && (underseacard[idx2].first==2||underseacard[idx2].first==3)  ){
                        tmpvalue=player[num_player][idx].second + underseacard[idx2].second;
                        tmpcount.push_back(tmpvalue);
                        tmpsuit.push_back(player[num_player][idx].first);
                        tmpnum.push_back(player[num_player][idx].second);
                        tmpusuit.push_back(underseacard[idx2].first);
                        tmpunum.push_back(underseacard[idx2].second);
                        tmpvalue=0;

                    }
                    //-----------------------------------------------------------------------------------------------------red black
                    else if(  (player[num_player][idx].first== 2||player[num_player][idx].first== 3) && (underseacard[idx2].first==1||underseacard[idx2].first==4)){
                        tmpvalue=player[num_player][idx].second+0;
                        tmpcount.push_back(tmpvalue);
                        tmpsuit.push_back(player[num_player][idx].first);
                        tmpnum.push_back(player[num_player][idx].second);
                        tmpusuit.push_back(underseacard[idx2].first);
                        tmpunum.push_back(underseacard[idx2].second);
                        tmpvalue=0;

                    }
                    //-----------------------------------------------------------------------------------------------------black red
                    else if(  (player[num_player][idx].first== 1||player[num_player][idx].first== 4) && (underseacard[idx2].first==2||underseacard[idx2].first==3)){
                        tmpvalue=0+underseacard[idx2].second;
                        tmpcount.push_back(tmpvalue);
                        tmpsuit.push_back(player[num_player][idx].first);
                        tmpnum.push_back(player[num_player][idx].second);
                        tmpusuit.push_back(underseacard[idx2].first);
                        tmpunum.push_back(underseacard[idx2].second);
                        tmpvalue=0;

                    }
                    //-----------------------------------------------------------------------------------------------------black black
                    else if(  (player[num_player][idx].first== 1||player[num_player][idx].first== 4) && (underseacard[idx2].first==1||underseacard[idx2].first==4)){
                        tmpvalue=0+0;
                        tmpcount.push_back(tmpvalue);
                        tmpsuit.push_back(player[num_player][idx].first);
                        tmpnum.push_back(player[num_player][idx].second);
                        tmpusuit.push_back(underseacard[idx2].first);
                        tmpunum.push_back(underseacard[idx2].second);
                        tmpvalue=0;

                    }
                }
            }
        }
        //*****----------------------------------------------------------------------------------------------------------------------------
        if(tmpcount.empty()){
            return false;
        }
        else if(!tmpcount.empty()&&num_player!=0){
            int Max=tmpcount[0];
            bestposition=0;
            for(int i=1;i<tmpcount.size();i++){
                if(tmpcount[i]>Max){
                    Max=tmpcount[i];
                    bestposition=i;
                }
            }


            canthrow[num_player].push_back( make_pair(tmpsuit[bestposition],tmpnum[bestposition]) );
            canthrowunder.push_back( make_pair(tmpusuit[bestposition],tmpunum[bestposition]) );
            total[num_player]+=tmpcount[bestposition];
            bestposition=0;
            tmpcount.clear();
            tmpsuit.clear();
            tmpnum.clear();
            tmpusuit.clear();
            tmpunum.clear();

            return true;
        }
        else if(!tmpcount.empty()&&num_player==0){
            for(int i=0;i<tmpcount.size();i++){
                canthrow[num_player].push_back( make_pair(tmpsuit[i],tmpnum[i]) );
            }
            tmpcount.clear();
            tmpsuit.clear();
            tmpnum.clear();
            tmpusuit.clear();
            tmpunum.clear();
            return true;
        }
}
void Card::flip(int a,pair<int,int> b){
    int flag=0;
    for(int idx = 0 ; idx < underseacard.size() ; idx++){
        int tmpvalue=0;
    //***--------------------------------------------------------------------------------------------------------------------1 and 9
            if(  (b.second== 1&&underseacard[idx].second==9) || (b.second==9&&underseacard[idx].second==1)  ){
                //------------------------------------------------------------------------------------------------------1/9 computer Spade 1
                if( (b.second== 1&&b.first== 1) && (underseacard[idx].first==2||underseacard[idx].first==3) ){
                    cout<<" and eats "<<Asuit[underseacard[idx].first]<<" "<<underseacard[idx].second<<" from the undersea!!!!"<<endl;
                    pair<int,int> tmp3(underseacard[idx].first,underseacard[idx].second);
                    drawsingle(tmp3);
                    tmpvalue=30+9;
                    total[a]+=tmpvalue;
                    underseacard.erase(underseacard.begin()+idx);
                    tmpvalue=0;
                    flag=1;
                    break;
                }

                else if( (b.second== 1&&b.first== 1) && (underseacard[idx].first==1||underseacard[idx].first==4) ){
                    cout<<" and eats "<<Asuit[underseacard[idx].first]<<" "<<underseacard[idx].second<<" from the undersea!!!!"<<endl;
                    pair<int,int> tmp3(underseacard[idx].first,underseacard[idx].second);
                    drawsingle(tmp3);
                    tmpvalue=30;
                    total[a]+=tmpvalue;
                    underseacard.erase(underseacard.begin()+idx);
                    tmpvalue=0;
                    flag=1;
                    break;
                }
                //------------------------------------------------------------------------------------------------------1/9 computer red 1
                else if( (b.second== 1&&( b.first== 2 || b.first== 3) ) && (underseacard[idx].first==2||underseacard[idx].first==3)   ) {
                    cout<<" and eats "<<Asuit[underseacard[idx].first]<<" "<<underseacard[idx].second<<" from the undersea!!!!"<<endl;
                    pair<int,int> tmp3(underseacard[idx].first,underseacard[idx].second);
                    drawsingle(tmp3);
                    tmpvalue=20+9;
                    total[a]+=tmpvalue;
                    underseacard.erase(underseacard.begin()+idx);
                    tmpvalue=0;
                    flag=1;
                    break;
                }
                else if( (b.second== 1&&( b.first== 2 || b.first== 3) ) && (underseacard[idx].first==1||underseacard[idx].first==4)   ) {
                    cout<<" and eats "<<Asuit[underseacard[idx].first]<<" "<<underseacard[idx].second<<" from the undersea!!!!"<<endl;
                    pair<int,int> tmp3(underseacard[idx].first,underseacard[idx].second);
                    drawsingle(tmp3);
                    tmpvalue=20+0;
                    total[a]+=tmpvalue;
                    underseacard.erase(underseacard.begin()+idx);
                    tmpvalue=0;
                    flag=1;
                    break;
                }
                //------------------------------------------------------------------------------------------------------1/9 computer Club 1
                else if( (b.second== 1&&b.first== 4)  && (underseacard[idx].first==2||underseacard[idx].first==3)  ) {
                    cout<<" and eats "<<Asuit[underseacard[idx].first]<<" "<<underseacard[idx].second<<" from the undersea!!!!"<<endl;
                    pair<int,int> tmp3(underseacard[idx].first,underseacard[idx].second);
                    drawsingle(tmp3);
                    tmpvalue=9;
                    total[a]+=tmpvalue;
                    underseacard.erase(underseacard.begin()+idx);
                    tmpvalue=0;
                    flag=1;
                    break;
                }
                else if( (b.second== 1&& b.first== 4)  && (underseacard[idx].first==1||underseacard[idx].first==4)  ) {
                    cout<<" and eats "<<Asuit[underseacard[idx].first]<<" "<<underseacard[idx].second<<" from the undersea!!!!"<<endl;
                    pair<int,int> tmp3(underseacard[idx].first,underseacard[idx].second);
                    drawsingle(tmp3);
                    tmpvalue=0;
                    total[a]+=tmpvalue;
                    underseacard.erase(underseacard.begin()+idx);
                    tmpvalue=0;
                    flag=1;
                    break;

                }
                //------------------------------------------------------------------------------------------------------9/1 computer red 9
                else if( (b.second== 9&& ( b.first== 2 || b.first== 3) )  && (underseacard[idx].first==2||underseacard[idx].first==3)   ) {
                    cout<<" and eats "<<Asuit[underseacard[idx].first]<<" "<<underseacard[idx].second<<" from the undersea!!!!"<<endl;
                    pair<int,int> tmp3(underseacard[idx].first,underseacard[idx].second);
                    drawsingle(tmp3);
                    tmpvalue=9+20;
                    total[a]+=tmpvalue;
                    underseacard.erase(underseacard.begin()+idx);
                    tmpvalue=0;
                    flag=1;
                    break;
                }
                else if( (b.second== 9&& ( b.first== 2 || b.first== 3) )  && underseacard[idx].first==1 ) {
                    cout<<" and eats "<<Asuit[underseacard[idx].first]<<" "<<underseacard[idx].second<<" from the undersea!!!!"<<endl;
                    pair<int,int> tmp3(underseacard[idx].first,underseacard[idx].second);
                    drawsingle(tmp3);
                    tmpvalue=9+30;
                    total[a]+=tmpvalue;
                    underseacard.erase(underseacard.begin()+idx);
                    tmpvalue=0;
                    flag=1;
                    break;
                }
                else if( (b.second== 9&& ( b.first== 2 || b.first== 3) )  && underseacard[idx].first==4 ) {
                    cout<<" and eats "<<Asuit[underseacard[idx].first]<<" "<<underseacard[idx].second<<" from the undersea!!!!"<<endl;
                    pair<int,int> tmp3(underseacard[idx].first,underseacard[idx].second);
                    drawsingle(tmp3);
                    tmpvalue=9+0;
                    total[a]+=tmpvalue;
                    underseacard.erase(underseacard.begin()+idx);
                    tmpvalue=0;
                    flag=1;
                    break;
                }
                //------------------------------------------------------------------------------------------------------9/1 computer black 9
                else if( (b.second== 9&& ( b.first== 1 || b.first== 4) )  && (underseacard[idx].first==2||underseacard[idx].first==3)   ) {
                    cout<<" and eats "<<Asuit[underseacard[idx].first]<<" "<<underseacard[idx].second<<" from the undersea!!!!"<<endl;
                    pair<int,int> tmp3(underseacard[idx].first,underseacard[idx].second);
                    drawsingle(tmp3);
                    tmpvalue=0+20;
                    total[a]+=tmpvalue;
                    underseacard.erase(underseacard.begin()+idx);
                    tmpvalue=0;
                    flag=1;
                    break;
                }
                else if( (b.second== 9&& ( b.first== 1 || b.first== 4) )  && underseacard[idx].first==1 ) {
                    cout<<" and eats "<<Asuit[underseacard[idx].first]<<" "<<underseacard[idx].second<<" from the undersea!!!!"<<endl;
                    pair<int,int> tmp3(underseacard[idx].first,underseacard[idx].second);
                    drawsingle(tmp3);
                    tmpvalue=0+30;
                    total[a]+=tmpvalue;
                    underseacard.erase(underseacard.begin()+idx);
                    tmpvalue=0;
                    flag=1;
                    break;
                }
                else if( (b.second== 9&& ( b.first== 1 || b.first== 4) )  && underseacard[idx].first==4 ) {
                    cout<<" and eats "<<Asuit[underseacard[idx].first]<<" "<<underseacard[idx].second<<" from the undersea!!!!"<<endl;
                    pair<int,int> tmp3(underseacard[idx].first,underseacard[idx].second);
                    drawsingle(tmp3);
                    tmpvalue=0+0;
                    total[a]+=tmpvalue;
                    underseacard.erase(underseacard.begin()+idx);
                    tmpvalue=0;
                    flag=1;
                    break;
                }
            }
            //***---------------------------------------------------------------------------------------------------------------------13 and 13
            else if(  b.second== 13&&underseacard[idx].second==13 ){
                //-----------------------------------------------------------------------------------------------------red 13 red 13
                if(  (b.first== 2||b.first== 3) && (underseacard[idx].first==2||underseacard[idx].first==3)  ){
                    cout<<" and eats "<<Asuit[underseacard[idx].first]<<" "<<underseacard[idx].second<<" from the undersea!!!!"<<endl;
                    pair<int,int> tmp3(underseacard[idx].first,underseacard[idx].second);
                    drawsingle(tmp3);
                    tmpvalue=13+13;
                    total[a]+=tmpvalue;
                    underseacard.erase(underseacard.begin()+idx);
                    tmpvalue=0;
                    flag=1;
                    break;
                }
                //-----------------------------------------------------------------------------------------------------red 13 black 13
                else if(  (b.first== 2||b.first== 3) && (underseacard[idx].first==1||underseacard[idx].first==4)){
                    cout<<" and eats "<<Asuit[underseacard[idx].first]<<" "<<underseacard[idx].second<<" from the undersea!!!!"<<endl;
                    pair<int,int> tmp3(underseacard[idx].first,underseacard[idx].second);
                    drawsingle(tmp3);
                    tmpvalue=13+0;
                    total[a]+=tmpvalue;
                    underseacard.erase(underseacard.begin()+idx);
                    tmpvalue=0;
                    flag=1;
                    break;
                }
                //-----------------------------------------------------------------------------------------------------black 13 red 13
                else if(  (b.first== 1||b.first== 4) && (underseacard[idx].first==2||underseacard[idx].first==3)){
                    cout<<" and eats "<<Asuit[underseacard[idx].first]<<" "<<underseacard[idx].second<<" from the undersea!!!!"<<endl;
                    pair<int,int> tmp3(underseacard[idx].first,underseacard[idx].second);
                    drawsingle(tmp3);
                    tmpvalue=0+13;
                    total[a]+=tmpvalue;
                    underseacard.erase(underseacard.begin()+idx);
                    tmpvalue=0;
                    flag=1;
                    break;
                }
                //-----------------------------------------------------------------------------------------------------black 13 black 13
                else if(  (b.first== 1||b.first== 4) && (underseacard[idx].first==1||underseacard[idx].first==4)){
                    cout<<" and eats "<<Asuit[underseacard[idx].first]<<" "<<underseacard[idx].second<<" from the undersea!!!!"<<endl;
                    pair<int,int> tmp3(underseacard[idx].first,underseacard[idx].second);
                    drawsingle(tmp3);
                    tmpvalue=0+0;
                    total[a]+=tmpvalue;
                    underseacard.erase(underseacard.begin()+idx);
                    tmpvalue=0;
                    flag=1;
                    break;
                }
            }
            //***---------------------------------------------------------------------------------------------------------------------12 and 12
            else if(  b.second== 12&&underseacard[idx].second==12 ){
                //-----------------------------------------------------------------------------------------------------red 11 red 12
                if(  (b.first== 2||b.first== 3) && (underseacard[idx].first==2||underseacard[idx].first==3)  ){
                    cout<<" and eats "<<Asuit[underseacard[idx].first]<<" "<<underseacard[idx].second<<" from the undersea!!!!"<<endl;
                    pair<int,int> tmp3(underseacard[idx].first,underseacard[idx].second);
                    drawsingle(tmp3);
                    tmpvalue=12+12;
                    total[a]+=tmpvalue;
                    underseacard.erase(underseacard.begin()+idx);
                    tmpvalue=0;
                    flag=1;
                    break;
                }
                //-----------------------------------------------------------------------------------------------------red 12 black 12
                else if(  (b.first== 2||b.first== 3) && (underseacard[idx].first==1||underseacard[idx].first==4)){
                    cout<<" and eats "<<Asuit[underseacard[idx].first]<<" "<<underseacard[idx].second<<" from the undersea!!!!"<<endl;
                    pair<int,int> tmp3(underseacard[idx].first,underseacard[idx].second);
                    drawsingle(tmp3);
                    tmpvalue=12+0;
                    total[a]+=tmpvalue;
                    underseacard.erase(underseacard.begin()+idx);
                    tmpvalue=0;
                    flag=1;
                    break;
                }
                //-----------------------------------------------------------------------------------------------------black 12 red 12
                else if(  (b.first== 1||b.first== 4) && (underseacard[idx].first==2||underseacard[idx].first==3)){
                    cout<<" and eats "<<Asuit[underseacard[idx].first]<<" "<<underseacard[idx].second<<" from the undersea!!!!"<<endl;
                    pair<int,int> tmp3(underseacard[idx].first,underseacard[idx].second);
                    drawsingle(tmp3);
                    tmpvalue=0+12;
                    total[a]+=tmpvalue;
                    underseacard.erase(underseacard.begin()+idx);
                    tmpvalue=0;
                    flag=1;
                    break;
                }
                //-----------------------------------------------------------------------------------------------------black 12 black 12
                else if(  (b.first== 1||b.first== 4) && (underseacard[idx].first==1||underseacard[idx].first==4)){
                    cout<<" and eats "<<Asuit[underseacard[idx].first]<<" "<<underseacard[idx].second<<" from the undersea!!!!"<<endl;
                    pair<int,int> tmp3(underseacard[idx].first,underseacard[idx].second);
                    drawsingle(tmp3);
                    tmpvalue=0+0;
                    total[a]+=tmpvalue;
                    underseacard.erase(underseacard.begin()+idx);
                    tmpvalue=0;
                    flag=1;
                    break;
                }
            }
            //***---------------------------------------------------------------------------------------------------------------------11 and 11
            else if( b.second== 11&&underseacard[idx].second==11 ){
                //-----------------------------------------------------------------------------------------------------red 11 red 11
                if(  (b.first== 2||b.first== 3) && (underseacard[idx].first==2||underseacard[idx].first==3)  ){
                    cout<<" and eats "<<Asuit[underseacard[idx].first]<<" "<<underseacard[idx].second<<" from the undersea!!!!"<<endl;
                    pair<int,int> tmp3(underseacard[idx].first,underseacard[idx].second);
                    drawsingle(tmp3);
                    tmpvalue=11+11;
                    total[a]+=tmpvalue;
                    underseacard.erase(underseacard.begin()+idx);
                    tmpvalue=0;
                    flag=1;
                    break;
                }
                //-----------------------------------------------------------------------------------------------------red 11 black 11
                else if(  (b.first== 2||b.first== 3) && (underseacard[idx].first==1||underseacard[idx].first==4)){
                    cout<<" and eats "<<Asuit[underseacard[idx].first]<<" "<<underseacard[idx].second<<" from the undersea!!!!"<<endl;
                    pair<int,int> tmp3(underseacard[idx].first,underseacard[idx].second);
                    drawsingle(tmp3);
                    tmpvalue=11+0;
                    total[a]+=tmpvalue;
                    underseacard.erase(underseacard.begin()+idx);
                    tmpvalue=0;
                    flag=1;
                    break;
                }
                //-----------------------------------------------------------------------------------------------------black 11 red 11
                else if(  (b.first== 1||b.first== 4) && (underseacard[idx].first==2||underseacard[idx].first==3)){
                    cout<<" and eats "<<Asuit[underseacard[idx].first]<<" "<<underseacard[idx].second<<" from the undersea!!!!"<<endl;
                    pair<int,int> tmp3(underseacard[idx].first,underseacard[idx].second);
                    drawsingle(tmp3);
                    tmpvalue=0+11;
                    total[a]+=tmpvalue;
                    underseacard.erase(underseacard.begin()+idx);
                    tmpvalue=0;
                    flag=1;
                    break;
                }
                //-----------------------------------------------------------------------------------------------------black 11 black 11
                else if(  (b.first== 1||b.first== 4) && (underseacard[idx].first==1||underseacard[idx].first==4)){
                    cout<<" and eats "<<Asuit[underseacard[idx].first]<<" "<<underseacard[idx].second<<" from the undersea!!!!"<<endl;
                    pair<int,int> tmp3(underseacard[idx].first,underseacard[idx].second);
                    drawsingle(tmp3);
                    tmpvalue=0+0;
                    total[a]+=tmpvalue;
                    underseacard.erase(underseacard.begin()+idx);
                    tmpvalue=0;
                    flag=1;
                    break;
                }
            }
            //***---------------------------------------------------------------------------------------------------------------------10 and 10
            else if(  b.second== 10&&underseacard[idx].second==10 ){
                //-----------------------------------------------------------------------------------------------------red 10 red 10
                if(  (b.first== 2||b.first== 3) && (underseacard[idx].first==2||underseacard[idx].first==3)  ){
                    cout<<" and eats "<<Asuit[underseacard[idx].first]<<" "<<underseacard[idx].second<<" from the undersea!!!!"<<endl;
                    pair<int,int> tmp3(underseacard[idx].first,underseacard[idx].second);
                    drawsingle(tmp3);
                    tmpvalue=10+10;
                    total[a]+=tmpvalue;
                    underseacard.erase(underseacard.begin()+idx);
                    tmpvalue=0;
                    flag=1;
                    break;
                }
                //-----------------------------------------------------------------------------------------------------red 10 black 10
                else if(  (b.first== 2||b.first== 3) && (underseacard[idx].first==1||underseacard[idx].first==4)){
                    cout<<" and eats "<<Asuit[underseacard[idx].first]<<" "<<underseacard[idx].second<<" from the undersea!!!!"<<endl;
                    pair<int,int> tmp3(underseacard[idx].first,underseacard[idx].second);
                    drawsingle(tmp3);
                    tmpvalue=10+0;
                    total[a]+=tmpvalue;
                    underseacard.erase(underseacard.begin()+idx);
                    tmpvalue=0;
                    flag=1;
                    break;
                }
                //-----------------------------------------------------------------------------------------------------black 10 red 10
                else if(  (b.first== 1||b.first== 4) && (underseacard[idx].first==2||underseacard[idx].first==3)){
                    cout<<" and eats "<<Asuit[underseacard[idx].first]<<" "<<underseacard[idx].second<<" from the undersea!!!!"<<endl;
                    pair<int,int> tmp3(underseacard[idx].first,underseacard[idx].second);
                    drawsingle(tmp3);
                    tmpvalue=0+10;
                    total[a]+=tmpvalue;
                    underseacard.erase(underseacard.begin()+idx);
                    tmpvalue=0;
                    flag=1;
                    break;
                }
                //-----------------------------------------------------------------------------------------------------black 10 black 10
                else if(  (b.first== 1||b.first== 4) && (underseacard[idx].first==1||underseacard[idx].first==4)){
                    cout<<" and eats "<<Asuit[underseacard[idx].first]<<" "<<underseacard[idx].second<<" from the undersea!!!!"<<endl;
                    pair<int,int> tmp3(underseacard[idx].first,underseacard[idx].second);
                    drawsingle(tmp3);
                    tmpvalue=0+0;
                    total[a]+=tmpvalue;
                    underseacard.erase(underseacard.begin()+idx);
                    tmpvalue=0;
                    flag=1;
                    break;
                }
            }
            //***---------------------------------------------------------------------------------------------------------------------less than 8 more then 2
            else if(  b.second>= 2 && underseacard[idx].second>=2 && b.second<= 8 && underseacard[idx].second<=8 && b.second+underseacard[idx].second==10){
                //-----------------------------------------------------------------------------------------------------red red
                if(  (b.first== 2||b.first== 3) && (underseacard[idx].first==2||underseacard[idx].first==3)  ){
                    cout<<" and eats "<<Asuit[underseacard[idx].first]<<" "<<underseacard[idx].second<<" from the undersea!!!!"<<endl;
                    pair<int,int> tmp3(underseacard[idx].first,underseacard[idx].second);
                    drawsingle(tmp3);
                    tmpvalue=b.second + underseacard[idx].second;
                    total[a]+=tmpvalue;
                    underseacard.erase(underseacard.begin()+idx);
                    tmpvalue=0;
                    flag=1;
                    break;
                }
                //-----------------------------------------------------------------------------------------------------red black
                else if(  (b.first== 2||b.first== 3) && (underseacard[idx].first==1||underseacard[idx].first==4)){
                    cout<<" and eats "<<Asuit[underseacard[idx].first]<<" "<<underseacard[idx].second<<" from the undersea!!!!"<<endl;
                    pair<int,int> tmp3(underseacard[idx].first,underseacard[idx].second);
                    drawsingle(tmp3);
                    tmpvalue=b.second+0;
                    total[a]+=tmpvalue;
                    underseacard.erase(underseacard.begin()+idx);
                    tmpvalue=0;
                    flag=1;
                    break;
                }
                //-----------------------------------------------------------------------------------------------------black red
                else if(  (b.first== 1||b.first== 4) && (underseacard[idx].first==2||underseacard[idx].first==3)){
                    cout<<" and eats "<<Asuit[underseacard[idx].first]<<" "<<underseacard[idx].second<<" from the undersea!!!!"<<endl;
                    pair<int,int> tmp3(underseacard[idx].first,underseacard[idx].second);
                    drawsingle(tmp3);
                    tmpvalue=0+underseacard[idx].second;
                    total[a]+=tmpvalue;
                    underseacard.erase(underseacard.begin()+idx);
                    tmpvalue=0;
                    flag=1;
                    break;
                }
                //-----------------------------------------------------------------------------------------------------black black
                else if(  (b.first== 1||b.first== 4) && (underseacard[idx].first==1||underseacard[idx].first==4)){
                    cout<<" and eats "<<Asuit[underseacard[idx].first]<<" "<<underseacard[idx].second<<" from the undersea!!!!"<<endl;
                    pair<int,int> tmp3(underseacard[idx].first,underseacard[idx].second);
                    drawsingle(tmp3);
                    tmpvalue=0+0;
                    total[a]+=tmpvalue;
                    underseacard.erase(underseacard.begin()+idx);
                    tmpvalue=0;
                    flag=1;
                    break;
                }
            }
        }
        if(flag==0){
            underseacard.push_back(make_pair(b.first,b.second));
        }
}

//*******----------------------------------------------------------------------------------------------------------------------------------
void Card::Run(){
    while(!player[0].empty()){
//--------------------------------------------------------------------------------------------------------------save file
            fstream file("Card.txt",ios::out);
            fstream secret("secret.txt",ios::out);
            if(!file||!secret)
            {
                cerr << "Can't open file!\n";
                exit(1);
            }
            file<<PlayerNum<<endl;
            secret<<(PlayerNum+CODE2)*CODE<<endl;
            for(int i=0;i<PlayerNum;i++){
                for(int j=0;j<player[i].size();j++){
                    file<<player[i][j].first<<" "<<player[i][j].second;
                    secret<<(player[i][j].first+CODE2)*CODE<<" "<<(player[i][j].second+CODE2)*CODE;
                    if(j==player[i].size()-1){
                        continue;
                    }
                    else{
                        file<<" ";
                        secret<<" ";
                    }
                }
                file<<endl;
                secret<<endl;
            }
            for(int i=0;i<underseacard.size();i++){
                file<<underseacard[i].first<<" "<<underseacard[i].second;
                secret<<(underseacard[i].first+CODE2)*CODE<<" "<<(underseacard[i].second+CODE2)*CODE;
                file<<" ";
                secret<<" ";
            }
            file<<endl;
            secret<<endl;

            for(int i=0;i<groundcard.size();i++){
                file<<groundcard[i].first<<" "<<groundcard[i].second;
                secret<<(groundcard[i].first+CODE2)*CODE<<" "<<(groundcard[i].second+CODE2)*CODE;
                file<<" ";
                secret<<" ";
            }
            file<<endl;
            secret<<endl;
            for(int i=0;i<PlayerNum;i++){
                file<<total[i]<<endl;
                secret<<(total[i]+CODE2)*CODE<<endl;
            }
            file.close();
            secret.close();
//--------------------------------------------------------------------------------------------------------------

        //------------------------------------------------------------------------------------------------Human
        string a,c;
        int b,d;

        if(Deal(0)){
            cout<<"Eat a card from the field!!!"<<endl;
        //-----------------------------------------------------------------------------------------------Human eats
            cout<<"Player sends(Suit:Spade,Heart,Diamond,Club) OR input 0 to end game :"<<endl;
            while(1){
                cin>>a;
                if(a=="0"){
                    system("TASKKILL /F /IM 410785018pickred.exe ");
                }
                cout<<"(Number:1-13) OR input 0 to end game :"<<endl;
                cin>>b;
                while(cin.fail()){
                    cin.clear();
                    cin.ignore();
                    cin>>b;
                }
                if(b==0){
                    system("TASKKILL /F /IM 410785018pickred.exe");
                }

                pair<int,int> tmp(Suit[a],b);
        //-------------------------------------------------------------------------------------------------
                cout<<"Player selects(Suit:Spade,Heart,Diamond,Club) from the field OR input 0 to end game :"<<endl;
                cin>>c;
                if(c=="0"){
                    system("TASKKILL /F /IM 410785018pickred.exe ");
                }
                cout<<"(Number:1-13) OR input 0 to end game :"<<endl;
                cin>>d;
                while(cin.fail()){
                    cin.clear();
                    cin.ignore();
                    cin>>d;
                }
                if(d==0){
                system("TASKKILL /F /IM 410785018pickred.exe");
                }

                pair<int,int> tmp2(Suit[c],d);
                if(ChooseCard(tmp,tmp2)){
                    system("cls");
                    cout<<"Player sends "<<a<<" "<<b<<" and eat "<<c<<" "<<d<<endl;
                    drawpair(tmp,tmp2);
                    for(unsigned int i=0;i<player[0].size();i++){
                        if(tmp.first==player[0][i].first&&tmp.second==player[0][i].second){
                            player[0].erase(player[0].begin()+i);
                        }
                    }
                    for(unsigned int i=0;i<underseacard.size();i++){
                        if(tmp2.first==underseacard[i].first&&tmp2.second==underseacard[i].second){
                           underseacard.erase(underseacard.begin()+i);
                        }
                    }
                    canthrow[0].clear();
                    canthrowunder.clear();
                    break;
                }
                else{
                    cout<<"You cannot send that card !"<<endl;
                    cout<<"Player sends(Suit:Spade,Heart,Diamond,Club) :"<<endl;
                }
            }
            //-----------------------------------------------------------------------------------------------Human flips
            cout<<"Player flips "<<Asuit[groundcard[0].first]<<" "<<groundcard[0].second<<" to the undersea!!!"<<endl;
            pair<int,int> tmpg(groundcard[0].first,groundcard[0].second);
            drawsingle(tmpg);
            flip(0,tmpg);
            groundcard.erase(groundcard.begin());
        }
        //---------------------------------------------------------------------------------------------------------------------Human cannot eat
        else{
            cout<<"Send a card to the field!!!"<<endl;
            cout<<"Player sends(Suit:Spade,Heart,Diamond,Club) OR input 0 to end game "<<endl;
            while(1){
                int flag=0;
                cin>>a;
                if(a=="0"){
                    system("TASKKILL /F /IM 410785018pickred.exe ");
                }
                cout<<"(Number:1-13) OR input 0 to end game  :"<<endl;
                cin>>b;
                    while(cin.fail()){
                    cin.clear();
                    cin.ignore();
                    cin>>b;
                }
                if(b==0){
                    system("TASKKILL /F /IM 410785018pickred.exe ");
                }

                pair<int,int> tmp(Suit[a],b);

                for(int i=0;i<player[0].size();i++){
                    if(tmp.first==player[0][i].first&&tmp.second==player[0][i].second){
                        system("cls");

                        underseacard.push_back(make_pair(player[0][i].first,player[0][i].second));
                        player[0].erase(player[0].begin()+i);

                        flag=1;
                        break;
                    }
                }

                if(flag==1){
                    cout<<"Player sends "<<a<<" "<<b<<" to the undersea "<<endl;
                    drawsingle(tmp);
                //--------------------------------------------------------------------------------------------------------Human flips
                    cout<<"Player flips "<<Asuit[groundcard[0].first]<<" "<<groundcard[0].second<<" to the undersea!!!"<<endl;
                    pair<int,int> tmpg(groundcard[0].first,groundcard[0].second);
                    drawsingle(tmpg);
                    flip(0,tmpg);
                    groundcard.erase(groundcard.begin());
                    break;
                }
                else{
                    cout<<"You cannot send that card !"<<endl;
                    cout<<"Player sends(Suit:Spade,Heart,Diamond,Club) OR input 0 to end game :"<<endl;
                }
            }


        }

        //------------------------------------------------------------------------------------------------Computer eats
        for(int i=1;i<PlayerNum;i++){
            if(Deal(i)){
                cout<<"Computer"<<i<<" sends "<<Asuit[canthrow[i][0].first]<<" "<<canthrow[i][0].second;
                cout<<" and eats "<< Asuit[canthrowunder[0].first]<<" "<< canthrowunder[0].second<<endl;
                pair<int,int> tmp(canthrow[i][0].first,canthrow[i][0].second);
                pair<int,int> tmp2(canthrowunder[0].first,canthrowunder[0].second);
                drawpair(tmp,tmp2);

                for(unsigned int index=0;index<player[i].size();index++){
                    if((player[i][index].first)==canthrow[i][0].first&&(player[i][index].second)==canthrow[i][0].second){
                        player[i].erase(player[i].begin()+index);
                    }
                }
                for(unsigned int index=0;index<underseacard.size();index++){
                    if(underseacard[index].first==canthrowunder[0].first&&underseacard[index].second==canthrowunder[0].second){
                        underseacard.erase( underseacard.begin()+index);
                    }
                }
                canthrow[i].clear();
                canthrowunder.clear();
                //----------------------------------------------------------------------------------------Computer flips
                cout<<"Computer"<<i<<" flips "<<Asuit[groundcard[0].first]<<" "<<groundcard[0].second<<" to the undersea!!!"<<endl;
                pair<int,int> tmpg(groundcard[0].first,groundcard[0].second);
                drawsingle(tmpg);
                flip(i,tmpg);
                groundcard.erase(groundcard.begin());
            }

            //---------------------------------------------------------------------------------------------Computer cannot eat
            else{
                cout<<"Computer"<<i<<" cannot eat the card from the undersea,so he sends "<<Asuit[player[i][0].first]<<" "<<player[i][0].second<<" to the undersea!!!"<<endl;
                pair<int,int> tmp(player[i][0].first,player[i][0].second);
                drawsingle(tmp);
                underseacard.push_back(make_pair(player[i][0].first,player[i][0].second));
                player[i].erase(player[i].begin());
                //----------------------------------------------------------------------------------------Computer flips
                cout<<"Computer"<<i<<" flips "<<Asuit[groundcard[0].first]<<" "<<groundcard[0].second<<" to the undersea!!!"<<endl;
                pair<int,int> tmpg(groundcard[0].first,groundcard[0].second);
                drawsingle(tmpg);
                flip(i,tmpg);
                groundcard.erase(groundcard.begin());
            }
        }

    //-----------------------------------------------------------------------------------------------------
        for(int i=0;i<PlayerNum;i++){
            sort(player[i].begin(),player[i].end(),comp);
        }
        sort(underseacard.begin(),underseacard.end(),comp);
        cout<<"***************************************************************************************************************************************************************************"<<endl;
        cout<<"Card on the field :"<<endl;
        PrintField();

        if(!player[0].empty()){
                cout<<"Card that you have :"<<endl;
                PrintHuman();
                cout<<"***************************************************************************************************************************************************************************"<<endl;
        }
    }
}
//----------------------------------------------------------------------------------------------------------

bool Card::ChooseCard(pair<int,int> b,pair<int,int> a){
    int flag=0;
    int flag2=0;
    for(unsigned int i=0;i<player[0].size();i++){
        if(b.first==player[0][i].first&&b.second==player[0][i].second){
            flag=1;
            break;
        }
    }
    for(unsigned int i=0;i<underseacard.size();i++){
        if(a.first==underseacard[i].first&&a.second==underseacard[i].second){
            flag2=1;
            break;
        }
    }

    if(flag==0){
        return false;
    }

    if(flag2==0){
        return false;
    }
    //---------------------------------------------------------------------------------------------
    int tmpvalue=0;
    if(  (b.second== 1&&a.second==9) || (b.second==9&&a.second==1)  ){
        //------------------------------------------------------------------------------------------------------1/9 computer Spade 1
        if( (b.second== 1&&b.first== 1) && (a.first==2||a.first==3) ){
            tmpvalue=30+9;
            total[0]+=tmpvalue;
            tmpvalue=0;
            cout<<"Player"<<" sends "<<Asuit[b.first]<<" "<<b.second<<" and eats "<<Asuit[a.first]<<" and "<<a.second<<" from the undersea!!!!"<<endl;
            return true;
        }

        else if( (b.second== 1&&b.first== 1) && (a.first==1||a.first==4) ){
            tmpvalue=30;
            total[0]+=tmpvalue;
            tmpvalue=0;
            cout<<"Player"<<" sends "<<Asuit[b.first]<<" "<<b.second<<" and eats "<<Asuit[a.first]<<" and "<<a.second<<" from the undersea!!!!"<<endl;
            return true;
        }
        //------------------------------------------------------------------------------------------------------1/9 computer red 1
        else if( (b.second== 1&&( b.first== 2 || b.first== 3) ) && (a.first==2||a.first==3)   ) {
            tmpvalue=20+9;
            total[0]+=tmpvalue;
            tmpvalue=0;
            cout<<"Player"<<" sends "<<Asuit[b.first]<<" "<<b.second<<" and eats "<<Asuit[a.first]<<" and "<<a.second<<" from the undersea!!!!"<<endl;
            return true;
        }
        else if( (b.second== 1&&( b.first== 2 || b.first== 3) ) && (a.first==1||a.first==4)   ) {
            tmpvalue=20+0;
            total[0]+=tmpvalue;
            tmpvalue=0;
            cout<<"Player"<<" sends "<<Asuit[b.first]<<" "<<b.second<<" and eats "<<Asuit[a.first]<<" and "<<a.second<<" from the undersea!!!!"<<endl;
            return true;
        }
        //------------------------------------------------------------------------------------------------------1/9 computer Club 1
        else if( (b.second== 1&&b.first== 4)  && (a.first==2||a.first==3)  ) {
            tmpvalue=9;
            total[0]+=tmpvalue;
            tmpvalue=0;
            cout<<"Player"<<" sends "<<Asuit[b.first]<<" "<<b.second<<" and eats "<<Asuit[a.first]<<" and "<<a.second<<" from the undersea!!!!"<<endl;
            return true;
        }
        else if( (b.second== 1&& b.first== 4)  && (a.first==1||a.first==4)  ) {
            tmpvalue=0;
            total[0]+=tmpvalue;
            tmpvalue=0;
            cout<<"Player"<<" sends "<<Asuit[b.first]<<" "<<b.second<<" and eats "<<Asuit[a.first]<<" and "<<a.second<<" from the undersea!!!!"<<endl;
            return true;

        }
        //------------------------------------------------------------------------------------------------------9/1 computer red 9
        else if( (b.second== 9&& ( b.first== 2 || b.first== 3) )  && (a.first==2||a.first==3)   ) {
            tmpvalue=9+20;
            total[0]+=tmpvalue;
            tmpvalue=0;
            cout<<"Player"<<" sends "<<Asuit[b.first]<<" "<<b.second<<" and eats "<<Asuit[a.first]<<" and "<<a.second<<" from the undersea!!!!"<<endl;
            return true;
        }
        else if( (b.second== 9&& ( b.first== 2 || b.first== 3) )  && a.first==1 ) {
            tmpvalue=9+30;
            total[0]+=tmpvalue;
            tmpvalue=0;
            cout<<"Player"<<" sends "<<Asuit[b.first]<<" "<<b.second<<" and eats "<<Asuit[a.first]<<" and "<<a.second<<" from the undersea!!!!"<<endl;
            return true;
        }
        else if( (b.second== 9&& ( b.first== 2 || b.first== 3) )  && a.first==4 ) {
            tmpvalue=9+0;
            total[0]+=tmpvalue;
            tmpvalue=0;
            cout<<"Player"<<" sends "<<Asuit[b.first]<<" "<<b.second<<" and eats "<<Asuit[a.first]<<" and "<<a.second<<" from the undersea!!!!"<<endl;
            return true;
        }
        //------------------------------------------------------------------------------------------------------9/1 computer black 9
        else if( (b.second== 9&& ( b.first== 1 || b.first== 4) )  && (a.first==2||a.first==3)   ) {
            tmpvalue=0+20;
            total[0]+=tmpvalue;
            tmpvalue=0;
            cout<<"Player"<<" sends "<<Asuit[b.first]<<" "<<b.second<<" and eats "<<Asuit[a.first]<<" and "<<a.second<<" from the undersea!!!!"<<endl;
            return true;
        }
        else if( (b.second== 9&& ( b.first== 1 || b.first== 4) )  && a.first==1 ) {
            tmpvalue=0+30;
            total[0]+=tmpvalue;
            tmpvalue=0;
            cout<<"Player"<<" sends "<<Asuit[b.first]<<" "<<b.second<<" and eats "<<Asuit[a.first]<<" and "<<a.second<<" from the undersea!!!!"<<endl;
            return true;
        }
        else if( (b.second== 9&& ( b.first== 1 || b.first== 4) )  && a.first==4 ) {
            tmpvalue=0+0;
            total[0]+=tmpvalue;
            tmpvalue=0;
            cout<<"Player"<<" sends "<<Asuit[b.first]<<" "<<b.second<<" and eats "<<Asuit[a.first]<<" and "<<a.second<<" from the undersea!!!!"<<endl;
            return true;
        }
    }
    //***---------------------------------------------------------------------------------------------------------------------13 and 13
    else if(  b.second== 13&&a.second==13 ){
        //-----------------------------------------------------------------------------------------------------red 13 red 13
        if(  (b.first== 2||b.first== 3) && (a.first==2||a.first==3)  ){
            tmpvalue=13+13;
            total[0]+=tmpvalue;
            tmpvalue=0;
            cout<<"Player"<<" sends "<<Asuit[b.first]<<" "<<b.second<<" and eats "<<Asuit[a.first]<<" and "<<a.second<<" from the undersea!!!!"<<endl;
            return true;
        }
        //-----------------------------------------------------------------------------------------------------red 13 black 13
        else if(  (b.first== 2||b.first== 3) && (a.first==1||a.first==4)){
            tmpvalue=13+0;
            total[0]+=tmpvalue;
            tmpvalue=0;
            cout<<"Player"<<" sends "<<Asuit[b.first]<<" "<<b.second<<" and eats "<<Asuit[a.first]<<" and "<<a.second<<" from the undersea!!!!"<<endl;
            return true;
        }
        //-----------------------------------------------------------------------------------------------------black 13 red 13
        else if(  (b.first== 1||b.first== 4) && (a.first==2||a.first==3)){
            tmpvalue=0+13;
            total[0]+=tmpvalue;
            tmpvalue=0;
            cout<<"Player"<<" sends "<<Asuit[b.first]<<" "<<b.second<<" and eats "<<Asuit[a.first]<<" and "<<a.second<<" from the undersea!!!!"<<endl;
            return true;
                }
        //-----------------------------------------------------------------------------------------------------black 13 black 13
        else if(  (b.first== 1||b.first== 4) && (a.first==1||a.first==4)){
            tmpvalue=0+0;
            total[0]+=tmpvalue;
            tmpvalue=0;
            cout<<"Player"<<" sends "<<Asuit[b.first]<<" "<<b.second<<" and eats "<<Asuit[a.first]<<" and "<<a.second<<" from the undersea!!!!"<<endl;
            return true;
        }
    }
    //***---------------------------------------------------------------------------------------------------------------------12 and 12
    else if(  b.second== 12&&a.second==12 ){
        //-----------------------------------------------------------------------------------------------------red 12 red 12
        if(  (b.first== 2||b.first== 3) && (a.first==2||a.first==3)  ){
            tmpvalue=12+12;
            total[0]+=tmpvalue;
            tmpvalue=0;
            cout<<"Player"<<" sends "<<Asuit[b.first]<<" "<<b.second<<" and eats "<<Asuit[a.first]<<" and "<<a.second<<" from the undersea!!!!"<<endl;
            return true;
        }
        //-----------------------------------------------------------------------------------------------------red 12 black 12
        else if(  (b.first== 2||b.first== 3) && (a.first==1||a.first==4)){
            tmpvalue=12+0;
            total[0]+=tmpvalue;
            tmpvalue=0;
            cout<<"Player"<<" sends "<<Asuit[b.first]<<" "<<b.second<<" and eats "<<Asuit[a.first]<<" and "<<a.second<<" from the undersea!!!!"<<endl;
            return true;
        }
        //-----------------------------------------------------------------------------------------------------black 12 red 12
        else if(  (b.first== 1||b.first== 4) && (a.first==2||a.first==3)){
            tmpvalue=0+12;
            total[0]+=tmpvalue;
            tmpvalue=0;
            cout<<"Player"<<" sends "<<Asuit[b.first]<<" "<<b.second<<" and eats "<<Asuit[a.first]<<" and "<<a.second<<" from the undersea!!!!"<<endl;
            return true;
                }
        //-----------------------------------------------------------------------------------------------------black 12 black 12
        else if(  (b.first== 1||b.first== 4) && (a.first==1||a.first==4)){
            tmpvalue=0+0;
            total[0]+=tmpvalue;
            tmpvalue=0;
            cout<<"Player"<<" sends "<<Asuit[b.first]<<" "<<b.second<<" and eats "<<Asuit[a.first]<<" and "<<a.second<<" from the undersea!!!!"<<endl;
            return true;
        }
    }
    //***---------------------------------------------------------------------------------------------------------------------11 and 11
    else if(  b.second== 11&&a.second==11 ){
        //-----------------------------------------------------------------------------------------------------red 11 red 11
        if(  (b.first== 2||b.first== 3) && (a.first==2||a.first==3)  ){
            tmpvalue=11+11;
            total[0]+=tmpvalue;
            tmpvalue=0;
            cout<<"Player"<<" sends "<<Asuit[b.first]<<" "<<b.second<<" and eats "<<Asuit[a.first]<<" and "<<a.second<<" from the undersea!!!!"<<endl;
            return true;
        }
        //-----------------------------------------------------------------------------------------------------red 11 black 11
        else if(  (b.first== 2||b.first== 3) && (a.first==1||a.first==4)){
            tmpvalue=11+0;
            total[0]+=tmpvalue;
            tmpvalue=0;
            cout<<"Player"<<" sends "<<Asuit[b.first]<<" "<<b.second<<" and eats "<<Asuit[a.first]<<" and "<<a.second<<" from the undersea!!!!"<<endl;
            return true;
        }
        //-----------------------------------------------------------------------------------------------------black 11 red 11
        else if(  (b.first== 1||b.first== 4) && (a.first==2||a.first==3)){
            tmpvalue=0+11;
            total[0]+=tmpvalue;
            tmpvalue=0;
            cout<<"Player"<<" sends "<<Asuit[b.first]<<" "<<b.second<<" and eats "<<Asuit[a.first]<<" and "<<a.second<<" from the undersea!!!!"<<endl;
            return true;
                }
        //-----------------------------------------------------------------------------------------------------black 11 black 11
        else if(  (b.first== 1||b.first== 4) && (a.first==1||a.first==4)){
            tmpvalue=0+0;
            total[0]+=tmpvalue;
            tmpvalue=0;
            cout<<"Player"<<" sends "<<Asuit[b.first]<<" "<<b.second<<" and eats "<<Asuit[a.first]<<" and "<<a.second<<" from the undersea!!!!"<<endl;
            return true;
        }
    }
    //***---------------------------------------------------------------------------------------------------------------------10 and 10
    else if(  b.second== 10&&a.second==10 ){
        //-----------------------------------------------------------------------------------------------------red 10 red 10
        if(  (b.first== 2||b.first== 3) && (a.first==2||a.first==3)  ){
            tmpvalue=10+10;
            total[0]+=tmpvalue;
            tmpvalue=0;
            cout<<"Player"<<" sends "<<Asuit[b.first]<<" "<<b.second<<" and eats "<<Asuit[a.first]<<" and "<<a.second<<" from the undersea!!!!"<<endl;
            return true;
        }
        //-----------------------------------------------------------------------------------------------------red 10 black 10
        else if(  (b.first== 2||b.first== 3) && (a.first==1||a.first==4)){
            tmpvalue=10+0;
            total[0]+=tmpvalue;
            tmpvalue=0;
            cout<<"Player"<<" sends "<<Asuit[b.first]<<" "<<b.second<<" and eats "<<Asuit[a.first]<<" and "<<a.second<<" from the undersea!!!!"<<endl;
            return true;
        }
        //-----------------------------------------------------------------------------------------------------black 10 red 10
        else if(  (b.first== 1||b.first== 4) && (a.first==2||a.first==3)){
            tmpvalue=0+10;
            total[0]+=tmpvalue;
            tmpvalue=0;
            cout<<"Player"<<" sends "<<Asuit[b.first]<<" "<<b.second<<" and eats "<<Asuit[a.first]<<" and "<<a.second<<" from the undersea!!!!"<<endl;
            return true;
                }
        //-----------------------------------------------------------------------------------------------------black 10 black 10
        else if(  (b.first== 1||b.first== 4) && (a.first==1||a.first==4)){
            tmpvalue=0+0;
            total[0]+=tmpvalue;
            tmpvalue=0;
            cout<<"Player"<<" sends "<<Asuit[b.first]<<" "<<b.second<<" and eats "<<Asuit[a.first]<<" and "<<a.second<<" from the undersea!!!!"<<endl;
            return true;
        }
    }
    //***---------------------------------------------------------------------------------------------------------------------less than 8 more then 2
    else if(  b.second>= 2 && a.second>=2 && b.second<= 8 && a.second<=8 && b.second+a.second==10){
        //-----------------------------------------------------------------------------------------------------red red
        if(  (b.first== 2||b.first== 3) && (a.first==2||a.first==3)  ){
            tmpvalue=b.second + a.second;
            total[0]+=tmpvalue;
            tmpvalue=0;
            cout<<"Player"<<" sends "<<Asuit[b.first]<<" "<<b.second<<" and eats "<<Asuit[a.first]<<" and "<<a.second<<" from the undersea!!!!"<<endl;
            return true;
        }
        //-----------------------------------------------------------------------------------------------------red black
        else if(  (b.first== 2||b.first== 3) && (a.first==1||a.first==4)){
            tmpvalue=b.second+0;
            total[0]+=tmpvalue;
            tmpvalue=0;
            cout<<"Player"<<" sends "<<Asuit[b.first]<<" "<<b.second<<" and eats "<<Asuit[a.first]<<" and "<<a.second<<" from the undersea!!!!"<<endl;
            return true;
        }
        //-----------------------------------------------------------------------------------------------------black red
        else if(  (b.first== 1||b.first== 4) && (a.first==2||a.first==3)){
            tmpvalue=0+a.second;
            total[0]+=tmpvalue;
            tmpvalue=0;
            cout<<"Player"<<" sends "<<Asuit[b.first]<<" "<<b.second<<" and eats "<<Asuit[a.first]<<" and "<<a.second<<" from the undersea!!!!"<<endl;
            return true;
        }
        //-----------------------------------------------------------------------------------------------------black black
        else if(  (b.first== 1||b.first== 4) && (a.first==1||a.first==4)){
            tmpvalue=0+0;
            total[0]+=tmpvalue;
            tmpvalue=0;
            cout<<"Player"<<" sends "<<Asuit[b.first]<<" "<<b.second<<" and eats "<<Asuit[a.first]<<" and "<<a.second<<" from the undersea!!!!"<<endl;
            return true;
        }
    }
    else{
        return false;
    }
}


void Card::PrintHuman(){
    unsigned int linetotal=0;
    unsigned int linecount=0;
    unsigned int cardtotal=0;
    if(6<player[0].size()){
        linetotal=6;
    }
    else{
        linetotal=player[0].size();
    }
    //------------------------------------------------------------------------------------------------------
    while(cardtotal<player[0].size()){
        for(unsigned int i=0;i<linetotal;i++){
            if(player[0][i+6*linecount].first==2||player[0][i+6*linecount].first==3){
                SetColor(12);
                cout<<left<<setw(13)<<setfill('=')<<Number[player[0][i+6*linecount].second];
                cout<<right<<setw(2)<<Number[player[0][i+6*linecount].second]<<" ";
                SetColor(7);
            }
            else{
                cout<<left<<setw(13)<<setfill('=')<<Number[player[0][i+6*linecount].second];
                cout<<right<<setw(2)<<Number[player[0][i+6*linecount].second]<<" ";
            }
        }
        cout<<endl;
        //-------------------------------------------------------------------------------
        for(int line=0;line<9;line++){
            for(unsigned int i=0;i<linetotal;i++){
                    switch(player[0][i+6*linecount].first)
                    {
                    case 1:
                        cout<<Spade[line];
                        break;
                    case 2:
                        SetColor(12);
                        cout<<Heart[line];
                        SetColor(7);
                        break;
                    case 3:
                        SetColor(12);
                        cout<<Diamond[line];
                        SetColor(7);
                        break;
                    case 4:
                        cout<<Club[line];
                        break;
                    }
                    cout<<" ";
            }
             cout<<endl;
        }
        //-------------------------------------------------------------------------------
         for(unsigned int i=0;i<linetotal;i++){
            if(player[0][i+6*linecount].first==2||player[0][i+6*linecount].first==3){
                SetColor(12);
                cout<<left<<setw(13)<<setfill('=')<<Number[player[0][i+6*linecount].second];
                cout<<right<<setw(2)<<Number[player[0][i+6*linecount].second]<<" ";
                SetColor(7);
            }
             else{
                cout<<left<<setw(13)<<setfill('=')<<Number[player[0][i+6*linecount].second];
                cout<<right<<setw(2)<<Number[player[0][i+6*linecount].second]<<" ";
            }
        }
        cout<<endl;
    //-----------------------------------------------------------------------------------
        cardtotal+=linetotal;
        if(cardtotal+6<player[0].size()){
            linetotal=6;
            linecount++;
        }
        else{
        linetotal=player[0].size()-cardtotal;
        linecount++;
        }
    }

}

void Card::PrintField(){
    unsigned int linetotal=0;
    unsigned int linecount=0;
    unsigned int cardtotal=0;
    if(6<underseacard.size()){
        linetotal=6;
    }
    else{
        linetotal=underseacard.size();
    }
    //------------------------------------------------------------------------------------------------------
    while(cardtotal<underseacard.size()){
        for(unsigned int i=0;i<linetotal;i++){
            if(underseacard[i+6*linecount].first==2||underseacard[i+6*linecount].first==3){
                SetColor(12);
                cout<<left<<setw(13)<<setfill('=')<<Number[underseacard[i+7*linecount].second];
                cout<<right<<setw(2)<<Number[underseacard[i+7*linecount].second]<<" ";
                SetColor(7);
            }
            else{
                cout<<left<<setw(13)<<setfill('=')<<Number[underseacard[i+6*linecount].second];
                cout<<right<<setw(2)<<Number[underseacard[i+6*linecount].second]<<" ";
            }
        }
        cout<<endl;
        //-------------------------------------------------------------------------------
        for(int line=0;line<9;line++){
            for(unsigned int i=0;i<linetotal;i++){
                    switch(underseacard[i+6*linecount].first)
                    {
                    case 1:
                        cout<<Spade[line];
                        break;
                    case 2:
                        SetColor(12);
                        cout<<Heart[line];
                        SetColor(7);
                        break;
                    case 3:
                        SetColor(12);
                        cout<<Diamond[line];
                        SetColor(7);
                        break;
                    case 4:
                        cout<<Club[line];
                        break;
                    }
                    cout<<" ";
            }
             cout<<endl;
        }
        //-------------------------------------------------------------------------------
         for(unsigned int i=0;i<linetotal;i++){
            if(underseacard[i+6*linecount].first==2||underseacard[i+6*linecount].first==3){
                SetColor(12);
                cout<<left<<setw(13)<<setfill('=')<<Number[underseacard[i+6*linecount].second];
                cout<<right<<setw(2)<<Number[underseacard[i+6*linecount].second]<<" ";
                SetColor(7);
            }
             else{
                cout<<left<<setw(13)<<setfill('=')<<Number[underseacard[i+6*linecount].second];
                cout<<right<<setw(2)<<Number[underseacard[i+6*linecount].second]<<" ";
            }
        }
        cout<<endl;
    //-----------------------------------------------------------------------------------
        cardtotal+=linetotal;
        if(cardtotal+6<underseacard.size()){
            linetotal=6;
            linecount++;
        }
        else{
        linetotal=underseacard.size()-cardtotal;
        linecount++;
        }
    }
}

void Card::drawsingle(pair<int,int> a){
    if(a.first==2||a.first==3){
        SetColor(12);
        cout<<left<<setw(13)<<setfill('=')<<Number[a.second];
        cout<<right<<setw(2)<<Number[a.second]<<" ";
        SetColor(7);
    }
    else{
        cout<<left<<setw(13)<<setfill('=')<<Number[a.second];
        cout<<right<<setw(2)<<Number[a.second]<<" ";
    }
    cout<<endl;
        //-------------------------------------------------------------------------------
    for(int line=0;line<9;line++){
        switch(a.first)
        {
            case 1:
                cout<<Spade[line];
                break;
            case 2:
                SetColor(12);
                cout<<Heart[line];
                SetColor(7);
                break;
            case 3:
                SetColor(12);
                cout<<Diamond[line];
                SetColor(7);
                break;
            case 4:
                cout<<Club[line];
                break;
        }
        cout<<" ";
        cout<<endl;
    }
    //-------------------------------------------------------------------------------
    if(a.first==2||a.first==3){
        SetColor(12);
        cout<<left<<setw(13)<<setfill('=')<<Number[a.second];
        cout<<right<<setw(2)<<Number[a.second]<<" ";
        SetColor(7);
    }
    else{
        cout<<left<<setw(13)<<setfill('=')<<Number[a.second];
        cout<<right<<setw(2)<<Number[a.second]<<" ";
    }

    cout<<endl;
}

void Card::drawpair(pair<int,int> a,pair<int,int> b){
    if(a.first==2||a.first==3){
        SetColor(12);
        cout<<left<<setw(13)<<setfill('=')<<Number[a.second];
        cout<<right<<setw(2)<<Number[a.second]<<" ";
        SetColor(7);
    }
    else{
        cout<<left<<setw(13)<<setfill('=')<<Number[a.second];
        cout<<right<<setw(2)<<Number[a.second]<<" ";
    }

    if(b.first==2||b.first==3){
        SetColor(12);
        cout<<left<<setw(13)<<setfill('=')<<Number[b.second];
        cout<<right<<setw(2)<<Number[b.second]<<" ";
        SetColor(7);
    }
    else{
        cout<<left<<setw(13)<<setfill('=')<<Number[b.second];
        cout<<right<<setw(2)<<Number[b.second]<<" ";
    }


    cout<<endl;
        //-------------------------------------------------------------------------------
        for(int line=0;line<9;line++){
                switch(a.first)
                    {
                    case 1:
                        cout<<Spade[line];
                        break;
                    case 2:
                        SetColor(12);
                        cout<<Heart[line];
                        SetColor(7);
                        break;
                    case 3:
                        SetColor(12);
                        cout<<Diamond[line];
                        SetColor(7);
                        break;
                    case 4:
                        cout<<Club[line];
                        break;
                    }
                    cout<<" ";

                switch(b.first)
                {
                    case 1:
                        cout<<Spade[line];
                        break;
                    case 2:
                        SetColor(12);
                        cout<<Heart[line];
                        SetColor(7);
                        break;
                    case 3:
                        SetColor(12);
                        cout<<Diamond[line];
                        SetColor(7);
                        break;
                    case 4:
                        cout<<Club[line];
                        break;
                }
                cout<<" ";
                cout<<endl;
        }
        //-------------------------------------------------------------------------------
    if(a.first==2||a.first==3){
        SetColor(12);
        cout<<left<<setw(13)<<setfill('=')<<Number[a.second];
        cout<<right<<setw(2)<<Number[a.second]<<" ";
        SetColor(7);
    }
    else{
        cout<<left<<setw(13)<<setfill('=')<<Number[a.second];
        cout<<right<<setw(2)<<Number[a.second]<<" ";
    }

    if(b.first==2||b.first==3){
        SetColor(12);
        cout<<left<<setw(13)<<setfill('=')<<Number[b.second];
        cout<<right<<setw(2)<<Number[b.second]<<" ";
        SetColor(7);
    }
    else{
        cout<<left<<setw(13)<<setfill('=')<<Number[b.second];
        cout<<right<<setw(2)<<Number[b.second]<<" ";
    }


    cout<<endl;
}

int Card::read(){
    fstream file("Card.txt",ios::in);
    fstream secret("secret.txt",ios::in);
    if(!file||!secret)
    {
        cerr << "Can't open file!\n";
        exit(1);
    }
    string line,sline;
    int substring,ssubstring;
    stringstream token,stoken;
    //-------------------------------------------------
    getline(file,line);
    token.str(line);

    getline(secret,sline);
    stoken.str(sline);
    //-------------------------------------------------PlayerNum
    while(token>>substring){
        PlayerNum=substring;
    }

    while(stoken>>ssubstring){
        if(ssubstring/CODE-CODE2!= PlayerNum){
            cout<<"!!!!!!!"<<endl;
            system("pause");
            ERR(1);
            file.close();
            secret.close();
            return 0;
        }
    }


    //-------------------------------------------------Card
    for(int i=0;i<PlayerNum;i++){
        token.str("");
        token.clear();
        getline(file,line);
        token.str(line);
        int a,b;
        int flag=1;
        while(token>>substring){
            if(flag==1){
                a=substring;
                flag=2;
            }
            else{
                b=substring;
                player[i].push_back(make_pair(a,b));
                flag=1;
            }
        }
    }

    for(int i=0;i<PlayerNum;i++){
        stoken.str("");
        stoken.clear();
        getline(secret,sline);
        stoken.str(sline);
        int a,b;
        int flag=1;
        while(stoken>>ssubstring){
            if(flag==1){
                a=ssubstring/CODE-CODE2;
                flag=2;
            }
            else{
                b=ssubstring/CODE-CODE2;
                secretplayer[i].push_back(make_pair(a,b));
                flag=1;
            }
        }
    }


    for(int i=0;i<PlayerNum;i++){
        for(int j=0;j<player[i].size();j++){
            if(player[i][j].first!=secretplayer[i][j].first||player[i][j].second!=secretplayer[i][j].second){
                cout<<"@@@@@@@"<<endl;
                system("pause");
                ERR(1);
                file.close();
                secret.close();
                return 0;
            }
        }
    }
    //------------------------------------------------undersea

    token.str("");
    token.clear();
    getline(file,line);
    token.str(line);
    int a,b;
    int flag=1;
    while(token>>substring){
        if(flag==1){
            a=substring;
            flag=2;
        }
        else{
            b=substring;
            underseacard.push_back(make_pair(a,b));
            flag=1;
        }
    }



    stoken.str("");
    stoken.clear();
    getline(secret,sline);
    stoken.str(sline);
    int c,d;
    flag=1;
    while(stoken>>ssubstring){
        if(flag==1){
            c=ssubstring/CODE-CODE2;
            flag=2;
        }
        else{
            d=ssubstring/CODE-CODE2;
            secretunderseacard.push_back(make_pair(c,d));
            flag=1;
        }
    }




    for(int j=0;j<underseacard.size();j++){
        if(underseacard[j].first!=secretunderseacard[j].first||underseacard[j].second!=secretunderseacard[j].second){
            cout<<"###########"<<endl;
            system("pause");
            ERR(1);
            file.close();
            secret.close();
            return 0;
        }
    }

    //------------------------------------------------ground
    token.str("");
    token.clear();
    getline(file,line);
    token.str(line);
    int e,f;
    flag=1;
    while(token>>substring){
        if(flag==1){
            e=substring;
            flag=2;
        }
        else{
            f=substring;
            groundcard.push_back(make_pair(e,f));
            flag=1;
        }
    }



    stoken.str("");
    stoken.clear();
    getline(secret,sline);
    stoken.str(sline);
    int g,h;
    flag=1;
    while(stoken>>ssubstring){
        if(flag==1){
            g=ssubstring/CODE-CODE2;
            flag=2;
        }
        else{
            h=ssubstring/CODE-CODE2;
            secretgroundcard.push_back(make_pair(g,h));
            flag=1;
        }
    }




    for(int j=0;j<groundcard.size();j++){
        if(groundcard[j].first!=secretgroundcard[j].first||groundcard[j].second!=secretgroundcard[j].second){
            cout<<"$$$$$$$$$$$$$$$$$"<<endl;
            system("pause");
            ERR(1);
            file.close();
            secret.close();
            return 0;
        }
    }

    //------------------------------------------------point
    for(int i=0;i<PlayerNum;i++){
        token.str("");
        token.clear();
        getline(file,line);
        token.str(line);
        while(token>>substring){
            total[i]=substring;
        }
    }

    for(int i=0;i<PlayerNum;i++){
        stoken.str("");
        stoken.clear();
        getline(secret,sline);
        stoken.str(sline);
        while(stoken>>ssubstring){
            checktotal[i]=ssubstring/CODE-CODE2;
        }
    }

    for(int i=0;i<PlayerNum;i++){
        if(total[i]!=checktotal[i]){
            cout<<"%%%%%%%%%%%%%%%%%%"<<endl;
            system("pause");
            ERR(1);
            file.close();
            secret.close();
            return 0;
        }
    }
    file.close();
    secret.close();
    //-----------------------------------------------------------------------------------
    cout<<"Card on the field :"<<endl;
    PrintField();
    if(!player[0].empty()){
        cout<<"Card that you have :"<<endl;
        PrintHuman();
    }
}

int Card::ERR(int a){
    if(a==1){
        cout<<"Data has already been destroyed!!!"<<endl;
        checkflag=1;
        return 1;
    }
}


#include<bits/stdc++.h>
using namespace std;

class Player{
    private:
        string name;
        int score;
    public:
        Player(string name){
            this->name = name;
            score = 0;
        }
        void updateScore(int hand){
            score += hand;
        }    
        int getScore(){
            return score;
        }
        void displayScore(){
            cout<<name<<"'s Score is: "<<this->score<<endl<<endl;
        }
        void throwHand(int hand){
            cout<<name<<" Throws "<<hand<<endl;
        }
};

class Game{
    private:
        Player *player1,*player2;
        int round;
    public:
        Game(){
            string name;
            int turn;

            cout<<"Enter the name of the first player: ";
            getline(cin,name);
            this->player1 = new Player(name);
            
            cout<<"Enter the name of the second player: ";
            getline(cin,name);
            this->player2 = new Player(name);

            cout<<"Enter which player is going first: Player 1(Press 1) or Player 2(Press 2) :";
            cin>> turn;

            if(turn == 1)
                turnToRound(player1,player2);
            else if(turn == 2)
                turnToRound(player2,player1);

            compareScores();
        }

        void turnToRound(Player *player1, Player *player2){
                this->round = 1; 
                cout<<"Round 1"<<endl;   
                rounds(player1,player2);
                this->round = 2;
                cout<<"Round 2"<<endl;   
                rounds(player2,player1);
        }
        void rounds(Player *player1, Player *player2){
            int hand1,hand2;
            int possible_hands[] = {0,1,2,3,4,6};
            for(int i = 0; i < 6; i++){
                hand1 = possible_hands[rand()%6];
                player1->throwHand(hand1);
                hand2 = possible_hands[rand()%6];
                player2->throwHand(hand2);
                cout<<endl;
                if(hand1 == hand2){
                    player1->displayScore();
                    break;
                }
                player1->updateScore(hand1);
                player1->displayScore();
                if(this->round == 2 && player1->getScore() > player2->getScore())
                    break;
            }
        }
        void compareScores(){
            if(player1->getScore() > player2->getScore())
                cout<<"Player 1 is the winner with score: "<<player1->getScore();
            else if(player1->getScore() < player2->getScore())
                cout<<"Player 2 is the winner with score: "<<player2->getScore();
            else
                cout<<"It is a tie";
        }

};
int main(){
    srand(time(0));
    Game G;
    return 0;
}
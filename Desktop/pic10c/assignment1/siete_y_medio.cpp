#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "cards.h"
using namespace std;

// Global constants (if any)


// Non member functions declarations (if any)
void oneRound(Player& player, Hand& playerhand, Hand& dealerHand, ofstream& fout){
	int currentBet;
	string wannaBet;
	cout << "You have $" << player.getMoney() << ". Enter bet: ";
    cin >> currentBet;
    currentBet = player.makeBet(currentBet);
    playerHand.takeCard(new Card);
    cout << "Your cards: " << endl;
    playerHand.printCards();
    
    cout << "Your total is " << playerHand.total() <<". Do you want another card (y/n)? ";
    cin >> wannaBet;
    if(wannaBet == "y"){ 
        while(wannaBet == "y" && playerHand.total() <= 7.5){
    		playerHand.takeCard(new Card);
    		playerHand.takeCard(new Card);
    		cout << "New Cards: " << endl;
    		playerHand.takeCard(new Card);
    		playerHand.getNew().printNewCard();
    		cout << endl;
    		cout << "Your cards: "<<endl;
    	    playerHand.printCards();
    		cout << "Your total is " << playerHand.total << ". Do you want another card (y/n)? ";
    	    cin >> wannaBet;
    	}
    }else{
    	dealerHand.takeCard(new Card);
    	cout << "Dealer's cards: "<<endl;
    	dealerHand.printCards();
    	cout << "The dealer's total is " << dealerHand.total << "." <<endl;
    	cout << endl;
    	while(dealHand.total() < 5.5){
    		dealerHand.takeCard(new Card);
    		cout << "New Cards: " << endl;
    		dealerHand.takeCard(new Card);
    		dealerHand.getNew().printNewCard();
    		cout << endl;
    		cout << "Dealer's cards: "<<endl;
    	    dealerHand.printCards();
    		cout << "The dealer's total is " << dealerHand.total << "." <<endl;
    	    cout << endl;
    	}
    }
    
    if(playerHand > dealerHand || dealerHand > 7.5){
        player.win(currentBet)
        cout << "You win " << currentBet << "." <<endl << endl;
    }else{
    	cout << "Too bad. You lose " << currentBet << "." <<endl << endl;
    }
}

// Non member functions implementations (if any)


// Stub for main
int main(){
   Player player(100);
   Hand playerHand;
   Hand dealerHand;
   ofstream fout;
   fout.open("log.txt");
   
   
   
   
   
   return 0;
}

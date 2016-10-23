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
void oneRound(Player& player, Hand& playerHand, Hand& dealerHand, int& currentBet){
	string wannaBet;
	cout << "You have $" << player.getMoney() << ". Enter bet: ";
    cin >> currentBet;
    currentBet = player.makeBet(currentBet);
    playerHand.takeCard(Card());
    cout << "Your cards: " << endl;
    playerHand.printCards();
    
    cout << "Your total is " << playerHand.total() <<". Do you want another card (y/n)? ";
    cin >> wannaBet;
    while(wannaBet == "y" && playerHand.total() <= 7.5){
    		playerHand.takeCard(Card());
    		cout << "New Cards: " << endl;
    		playerHand.getNew().printNewCard();
    		cout << endl;
    		cout << "Your cards: "<<endl;
    	    playerHand.printCards();
    		cout << "Your total is " << playerHand.total() << ". Do you want another card (y/n)? ";
    	    cin >> wannaBet;
    }
    dealerHand.takeCard(Card());
    cout << "Dealer's cards: "<<endl;
    dealerHand.printCards();
    cout << "The dealer's total is " << dealerHand.total() << "." <<endl;
    cout << endl;
    while(dealerHand.total() < 5.5){
        dealerHand.takeCard(Card());
        cout << "New Cards: " << endl;
        dealerHand.getNew().printNewCard();
        cout << endl;
        cout << "Dealer's cards: "<<endl;
        dealerHand.printCards();
        cout << "The dealer's total is " << dealerHand.total() << "." <<endl;
        cout << endl;
    }
    
    if(dealerHand < playerHand && playerHand.total() <= 7.5){
        player.win(currentBet);
        cout << "You win " << currentBet << "." <<endl << endl;
    }else if(dealerHand.total() > 7.5 && playerHand.total() <= 7.5){
        player.win(currentBet);
        cout << "You win " << currentBet << "." <<endl << endl;
    }else{
    	cout << "Too bad. You lose $" << currentBet << "." <<endl << endl;
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
   int currentBet;
   int count = 0;
   while(player.getMoney() > 0){
   		count++;
   		oneRound(player,playerHand,dealerHand,currentBet);
   		fout << "-----------------------------------------------" << endl;
   		fout << "Game number: " << count << "		Money left: $" << player.getMoney() << endl;
   		fout << "Bet: " << currentBet << endl << endl;
   		fout << "Your cards:" << endl;
   		playerHand.printCardsfile(fout);
   		fout << "Your total: " << playerHand.total() << "." << endl;
   		fout << endl << "Dealer's cards: "<<endl;
   		dealerHand.printCardsfile(fout);
   		fout << "Dealer's total is " << playerHand.total() << "." << endl << endl;
        playerHand.zero();
        dealerHand.zero();
   }
    cout << "You have $0. GAME OVER!" << endl <<"Come back when you have more money." << endl <<endl <<"Bye!" << endl;
    fout.close();
   
   
   
   return 0;
}

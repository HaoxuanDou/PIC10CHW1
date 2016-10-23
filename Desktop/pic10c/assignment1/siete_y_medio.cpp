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
void oneRound(Player& player, Hand& playerhand, Hand& dealerHand){
	cout << "You have $" << player.getMoney() << ". Enter bet: ";
    int currentBet;
    cin >> currentBet;
    player.makeBet(currentBet);
    cout << "Your cards"
}

// Non member functions implementations (if any)


// Stub for main
int main(){
   Player player(100);
   Hand playerHand;
   Hand dealerHand;
   
  
   
   
   
   
   return 0;
}

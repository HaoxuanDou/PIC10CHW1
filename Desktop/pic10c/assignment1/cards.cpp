#include "cards.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <ctime>
/* 
You might or might not need these two extra libraries 

*/


/* *************************************************
   Card class
   ************************************************* */

/* 
   Default constructor for the Card class.
   It could give repeated cards. This is OK.
   Most variations of Blackjack are played with 
   several decks of cards at the same time.
*/

Card::Card(){
   srand(time(0));
   int r = 1 + rand() % 4;
   switch (r) {
      case 1: suit = OROS; break;
      case 2: suit = COPAS; break; 
      case 3: suit = ESPADAS; break;
      case 4: suit = BASTOS; break; 
      default: break;
   }

   r = 1 + rand() % 10;  
   switch (r) {
      case  1: rank = AS; break; 
      case  2: rank = DOS; break; 
      case  3: rank = TRES; break; 
      case  4: rank = CUATRO; break; 
      case  5: rank = CINCO; break; 
      case  6: rank = SEIS; break; 
      case  7: rank = SIETE; break; 
      case  8: rank = SOTA; break; 
      case  9: rank = CABALLO; break; 
      case 10: rank = REY; break; 
      default: break;
   }
}

// Accessor: returns a string with the suit of the card in Spanish 
string Card::get_spanish_suit() const { 
   string suitName;
   switch (suit) {
      case OROS: 
         suitName = "oros"; 
	 break;
      case COPAS: 
         suitName = "copas"; 
	 break; 
      case ESPADAS: 
         suitName = "espadas"; 
	 break;
      case BASTOS: 
         suitName = "bastos"; 
	 break; 
      default: break;
   }
   return suitName;
}

// Accessor: returns a string with the rank of the card in Spanish 
string Card::get_spanish_rank() const { 
   string rankName;
   switch (rank) {
      case AS:
         rankName = "As"; 
	 break; 
      case DOS: 
         rankName = "Dos"; 
	 break; 
      case TRES: 
         rankName = "Tres"; 
	 break; 
      case CUATRO: 
         rankName = "Cuatro"; 
	 break; 
      case CINCO: 
         rankName = "Cinco"; 
	 break; 
      case SEIS: 
         rankName = "Seis"; 
	 break; 
      case SIETE: 
         rankName = "Siete"; 
	 break; 
      case SOTA: 
         rankName = "Sota"; 
	 break; 
      case CABALLO: 
         rankName = "Caballo"; 
	 break; 
      case REY: 
         rankName = "Rey"; 
	 break; 
      default: break;
   }
   return rankName;
}

string Card::getEnglishCard() const{
    return get_english_rank() + " of " + get_english_suit();
}
string Card::getSpanishCard() const{
	return get_spanish_rank() + " of " + get_spanish_suit();
}
void Card::printCard() const{
	std::cout << "        ";
    std::cout <<std::left<< std::setw(21) << getSpanishCard();
	std::cout << "(" << getEnglishCard() << ")." << std::endl; 
}
void Card::printNewCard() const{
	std::cout << "        ";
	std::cout << getSpanishCard() << " ";
	std::cout << "(" << getEnglishCard() << ")." << std::endl; 
}

void Card::printCardfile(ofstream& fout) const{
	fout << "        ";
	fout <<std::left<< std::setw(21) << getSpanishCard();
	fout << "(" << getEnglishCard() << ")." << std::endl; 
}
void Card::printNewCardfile(ofstream& fout) const{
	fout << "        ";
	fout << getSpanishCard() << " ";
	fout << "(" << getEnglishCard() << ")." << std::endl; 
}


// Accessor: returns a string with the suit of the card in English 
// This is just a stub! Modify it to your liking.
string Card::get_english_suit() const { 
   string suitName;
   switch (suit) {
      case OROS: 
         suitName = "golds"; 
	 break;
      case COPAS: 
         suitName = "cups"; 
	 break; 
      case ESPADAS: 
         suitName = "swords"; 
	 break;
      case BASTOS: 
         suitName = "clubs"; 
	 break; 
      default: break;
   }
   return suitName;
}

// Accessor: returns a string with the rank of the card in English 
// This is just a stub! Modify it to your liking.
string Card::get_english_rank() const { 
    string rankName;
   switch (rank) {
      case AS:
         rankName = "One"; 
	 break; 
      case DOS: 
         rankName = "Two"; 
	 break; 
      case TRES: 
         rankName = "Three"; 
	 break; 
      case CUATRO: 
         rankName = "Four"; 
	 break; 
      case CINCO: 
         rankName = "Five"; 
	 break; 
      case SEIS: 
         rankName = "Six"; 
	 break; 
      case SIETE: 
         rankName = "Seven"; 
	 break; 
      case SOTA: 
         rankName = "Jack"; 
	 break; 
      case CABALLO: 
         rankName = "Knight"; 
	 break; 
      case REY: 
         rankName = "King"; 
	 break; 
      default: break;
   }
   return rankName;
}



// Assigns a numerical value to card based on rank.
// AS=1, DOS=2, ..., SIETE=7, SOTA=10, CABALLO=11, REY=12
int Card::get_rank() const {
   return static_cast<int>(rank) + 1 ;
}
double Card::getValue() const {
	if(get_rank() < 8) return get_rank();
	else return 0.5;
}

// Comparison operator for cards
// Returns TRUE if card1 < card2
bool Card::operator < (Card card2) const {
   return rank < card2.rank;
}



/* *************************************************
   Hand class
   ************************************************* */
// Implemente the member functions of the Hand class here.
Hand::Hand(){
    vector<Card> hand;
}


void Hand::takeCard(Card newCard){
	hand.push_back(newCard);
}

void Hand::printCardsfile(ofstream& fout) const{
    for(int i=0;i< hand.size();i++){
		hand[i].printCardfile(fout);
	}
}

void Hand::printCards() const{
	for(int i=0;i< hand.size();i++){
		hand[i].printCard();
	}
}

double Hand::total() const{
	double tot = 0;
	for(size_t i=0; i<hand.size(); i++){
		tot += hand[i].getValue();
	}
	return tot;
}
Card Hand::getNew() const {
    return hand[hand.size()-1];
}
bool Hand::operator < (Hand hand2) const{
	return total() < hand2.total();
}
void Hand::zero(){
    hand.clear();
}

/* *************************************************
   Player class
   ************************************************* */
// Implemente the member functions of the Player class here.

Player::Player(int m){
	money = m;
}
int Player::getMoney() const {return money;}

int Player::makeBet(int bet){
	if(money > bet){
		money -= bet;
		return bet;
	}else{
		bet = money;
		money =0;
		return bet;
	}
}

void Player::win(int bet){
	money += bet*2;
}




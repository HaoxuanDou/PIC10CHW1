/* *************************************
   Ricardo Salazar, February 26, 2015

   Interface of a simple Card class
   ************************************* */

#include <string>
#include <vector>
#include <fstream>

#ifndef CARDS_H
#define CARDS_H

using namespace std;

enum suit_t {OROS, COPAS, ESPADAS, BASTOS};

   /*
   The values for this type start at 0 and increase by one 
   afterwards until they get to SIETE. 
   The rank reported by the function Card::get_rank() below is 
   the value listed here plus one.
   E.g: 
   The rank of AS is reported as    static_cast<int>(AS) + 1   = 0 + 1 =  1
   The rank of SOTA is reported as  static_cast<int>(SOTA) + 1 = 9 + 1 = 10
   */
enum rank_t {AS, DOS, TRES, CUATRO, CINCO, SEIS, SIETE, SOTA=9, CABALLO=10, REY=11};

class Card {
   public: 
      // Constructor assigns random rank & suit to card.
      Card();
      
      // Accessors 
      string get_spanish_suit() const;
      string get_spanish_rank() const; 
	  string getEnglishCard() const;
	  string getSpanishCard() const;
	  void printCard() const;
	  void printNewCard() const;
	  void printCardfile(ofstream& fout) const;
	  void printNewCardfile(ofstream& fout) const;
      /* 
         These are the only functions you'll need to code 
         for this class. See the implementations of the two 
	 functions above to get an idea of how to proceed.
      */
      string get_english_suit() const;
      string get_english_rank() const; 
	  //string toString() const;
      // Converts card rank to number.
      // The possible returns are: 1, 2, 3, 4, 5, 6, 7, 10, 11 and 12
      int get_rank() const;
      double getValue() const;
      // Compare rank of two cards. E.g: Eight<Jack is true.
      // Assume Ace is always 1. 
      // Useful if you want to sort the cards.
      bool operator < (Card card2) const;

private:
      suit_t suit;
      rank_t rank;
};


class Hand {
   public:
      // A vector of Cards
      Hand();
      Card getNew() const;
      void takeCard(Card newCard);
      void printCardsfile(ofstream& fout) const;
      double total() const;
      void printCards() const;
      bool operator < (Hand hand2) const;
      void zero();
      // You decide what functions you'll need...

   private:
       vector<Card> hand;
      // You decide what fields you'll need...
};


class Player {
   public:
      // Constructor. 
      //    Assigns initial amount of money
      Player(int m);
      int getMoney() const;
      int makeBet(int bet);
      void win(int bet);
      void printCards() const;
      // You decide what functions you'll need...
      
      
      
   private:
      int money;
      // You decide what extra fields (if any) you'll need...
};

#endif

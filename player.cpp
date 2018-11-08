//File Name: player.cpp
//
//Player program
//Reid Lindemann & Ricky Guzman 10/30/2018
//EE 312

/* Student information for project:
 *
 * On my honor, Reid Lindemann and Ricky Guzman, this programming project is our own work
 * and I have not provided this code to any other student.
 *
 * Name: Reid Lindemann
 * email address: lindemannreid@yahoo.com
 * UTEID: rhl542
 * Section 5 digit ID: 16200
 *
 * Name: Ricardo Guzman
 * email address: r.guzman@utexas.edu
 * UTEID: rg43989
 * Section 5 digit ID: 16200
 *
 */

#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include "card.h"
#include "deck.h"
#include "player.h"
using namespace std;

//FUNCTION: addCard
// adds a card to the hand
// INPUT: card to be added
// OUTPUT: N/A
void Player::addCard(Card c) {
   myHand.push_back(c);
}

//FUNCTION: bookCards
// add pair of cards to the book
// INPUT: card1, card2 to be added
// OUTPUT: N/A
void Player::bookCards(Card c1, Card c2) {
   myBook.push_back(c1);
   myBook.push_back(c2);
}

//FUNCTION: rankInHand
// Does the player have a card with the same rank as c in her hand?
// INPUT: card (rank is only important characteristic
// OUTPUT: boolean
bool Player::rankInHand(Card c) const {
    for (int i = 0; i < getHandSize(); i++) {
        if (myHand[i].getRank() == c.getRank()) {
            return true;
        }
    }
    return false;
}

//FUNCTION: chooseCardFromHand
// randomly picks a card to ask
// hand so they can say "Do you have a 4?"
// INPUT: N/A
// OUTPUT: card randomly chosen from hand
Card Player::chooseCardFromHand() const {
    int idx = (rand() % myHand.size()); //random valid idx value
    return myHand[idx];
}

//FUNCTION: cardInHand
// Does the player have the card c in her hand?
// INPUT: card to check if present
// OUTPUT: boolean
bool Player::cardInHand(Card c) const {
    for(int i = 0; i < myHand.size(); i++) {
        if(myHand[i] == c) {
            return true;
        }
    }
    return false;
}

//FUNCTION: removeCardFromHand
// Remove the card c from the hand and return it to the caller
// Precondition: card must be known to be in hand.
// INPUT: card to be removed
// OUTPUT: card that is removed
Card Player::removeCardFromHand(Card c) {
    int idx;
    Card temp;
    for(int i = 0; i < getHandSize(); i++) {
        if(myHand[i] == c){
            idx = i;
        }
    }
    temp = myHand[idx];
    myHand.erase(myHand.begin() + idx); //delete card at idx
    return temp;
}

//FUNCTION: showHand
// return string displaying the contents of the hand
// INPUT: N/A
// OUTPUT: string concatenation of cards in hand
string Player::showHand() const {
    string output = "";
    for (int i = 0; i < myHand.size(); i++) {
        output = output + myHand[i].toString() + "\n";
    }
    return output;
}

//FUNCTION: showBooks
// string displaying the books and their contents
// INPUT: N/A
// OUTPUT: string concatenation of the books
string Player::showBooks() const {
    string output = "";
    for (int i = 0; i < myBook.size(); i = i + 2) {
        output = output + myBook[i].toString() + ", " + myBook[i + 1].toString() + "\n";
    }
    return output;
}

//FUNCTION:: getHandSize
// integer of the number of cards in the hand
// INPUT: N/A
// OUTPUT: integer of amount of cards in hand
int Player::getHandSize() const {
    return myHand.size();
}

//FUNCTION: getBookSize
// integer of the number of pairs in the book
// INPUT: N/A
// OUTPUT: integer of amount of books (pairs)
int Player::getBookSize() const {
    return (myBook.size() / 2);
}

//FUNCTION: checkHandForPair
// true if there are two cards of the same rank (pair)
// Cards c1 and c2 contain the pair of equal cards if true
// INPUT: card1, card2 to be populated with the pair
// OUTPUT: boolean
bool Player::checkHandForPair(Card &c1, Card &c2) {
    Card check;
    for (int i = 0; i < myHand.size(); i++) {
        check = myHand[i];
        for (int j = i + 1; j < myHand.size(); j++) {
           if (check.getRank() == myHand[j].getRank()) {
               c1 = check;
               c2 = myHand[j];
               return true;
           }
        }
    }
    return false;
}

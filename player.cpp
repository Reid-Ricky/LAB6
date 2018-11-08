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
void Player::addCard(Card c) {
   myHand.push_back(c);
}

//FUNCTION: bookCards
// 
void Player::bookCards(Card c1, Card c2) {
   myBook.push_back(c1);
   myBook.push_back(c2);
}

//FUNCTION: checkHandForBook
// checks a players hand for a pair. 
// If a pair is found, it returns true and populates the
// two variables with the cards tha make the pair.
bool Player::checkHandForBook(Card &c1, Card &c2) {
    Card check;
    for (int i = 0; i < myHand.size(); i++) {
        check = myHand[i];
        for (int j = i + 1; j < myHand.size(); j++) {
            if (check == myHand[j]) {
                c1 = check;
                c2 = myHand[j];
                return true;
            }
        }
    }
    return false;
}

//FUNCTION: rankInHand
// Does the player have a card with the same rank as c in her hand?
bool Player::rankInHand(Card c) const {
    for (int i =0;i < getHandSize();i++){
        if (myHand[i].getRank() == c.getRank()){
            return true;
        }
    }
    return false;
   
}

//FUNCTION: chooseCardFromHand
// uses some strategy to choose one card from the player's
// hand so they can say "Do you have a 4?"
Card Player::chooseCardFromHand() const {

}

//FUNCTION: cardInHand
// Does the player have the card c in her hand?
bool Player::cardInHand(Card c) const {
    for(int i=0;i< getHandSize();i++){
        if(myHand[i] == c){
            return true;
        }
    }
    return false;
}

//FUNCTION: removeCardFromHand
// Remove the card c from the hand and return it to the caller
// precondition: card must be known to be in hand.
Card Player::removeCardFromHand(Card c) {
    int idx = -1;
    for(int i=0;i<getHandSize();i++){
        if(myHand[i] == c){
            idx = i;
        }
    }


}

//FUNCTION: showHand
// return string displaying the contents of the hand
string Player::showHand() const {
    for (int i = 0; i < myHand.size(); i++) {
        cout << myHand[i].toString() << endl;
    }
}

//FUNCTION: showBooks
// string displaying the books and their contents
string Player::showBooks() const {
    for (int i = 0; i < myBook.size(); i++) {
        cout << myBook[i].toString() << endl;
    }
}

//FUNCTION:: getHandSize
// integer of the number of cards in the hand
int Player::getHandSize() const {
    myHand.size();
}

//FUNCTION: getBookSize
// integer of the number of cards in the book
int Player::getBookSize() const {
    myBook.size();
}

//FUNCTION:
// true if there are two cards of the same rank
// Cards c1 and c2 contain the pair of equal cards if true
bool Player::checkHandForPair(Card &c1, Card &c2) {
    Card check;
    for (int i = 0; i < myHand.size(); i++) {
        check = myHand[i];
        for (int j = i + 1; j < myHand.size(); j++) {
           if (check == myHand[j]) {
               c1 = check;
               c2 = myHand[j];
               return true;
           }
        }
    }
    return false;
}

//FUNCTION: sameRankInHand
// does the player have a card with the same rank as c in her hand?
// e.g. will return true if the player has a 7d and the parameter is 7c
bool Player::sameRankInHand(Card c) const {
    for (int i = 0; i < myHand.size(); i++) {
        if (myHand[i] == c) {
            return true;
        }
    }
    return false;
}


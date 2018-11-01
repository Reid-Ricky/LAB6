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
   
}

//FUNCTION: rankInHand
// Does the player have a card with the same rank as c in her hand?
bool Player::rankInHand(Card c) const {
   
}

//FUNCTION: chooseCardFromHand
// uses some strategy to choose one card from the player's
// hand so they can say "Do you have a 4?"
Card Player::chooseCardFromHand() const {

}

//FUNCTION: cardInHand
// Does the player have the card c in her hand?
bool Player::cardInHand(Card c) const {

}

//FUNCTION: removeCardFromHand
// Remove the card c from the hand and return it to the caller
Card Player::removeCardFromHand(Card c) {

}

//FUNCTION: showHand
// return string displaying the contents of the hand
string Player::showHand() const {

}

//FUNCTION: showBooks
// string displaying the books and their contents
string Player::showBooks() const {

}

//FUNCTION:: getHandSize
// integer of the number of cards in the hand
int Player::getHandSize() const {

}

//FUNCTION: getBookSize
// integer of the number of cards in the book
int Player::getBookSize() const {

}

//FUNCTION:
// true if there are two cards of the same rank
bool Player::checkHandForPair(Card &c1, Card &c2) {

}

//FUNCTION: sameRankInHand
// does the player have a card with the same rank as c in her hand?
// e.g. will return true if the player has a 7d and the parameter is 7c
bool Player::sameRankInHand(Card c) const {
   
}


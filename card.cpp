//File Name: card.cpp
//
//Card program
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
 *
 */

#include "card.h"
#include <iostream>
#include <string>
using namespace std;

//Default Constructor
// default card is ace of spades
Card::Card() {
}

//Parameter Constructor
Card::Card(int rank, Suit s) {
   mySuit = s;
   myRank = rank;
}

//FUNCTION: toString
// converts a card to a string, e.g. Ac 4h Js, to print
string Card::toString() const {
   
}

//FUNCTION: sameSuitAs
// returns true if same suit as Card c
bool Card::sameSuitAs(const Card &c) const {

    if(this->mySuit == c.mySuit){
        return true;
    }
    else {
        return false;
    }

   
}

//FUNCTION: getRank
// returns 1, 2, ..., 13 for ace, two, ..., king
int Card::getRank() const {
   return myRank;
}

//FUNCTION: suitString
// returns "s", "h", "d" or "c"
string Card::suitString(Suit s) const {
   
}

//FUNCTION: rankString
// returns "A", "2", ..."Q"
string Card::rankString(int r) const {
   
}

//OPERATOR:: ==
bool Card::operator == (const Card &rhs) const {
   
}

//OPERATOR:: !=
bool Card::operator != (const Card &rhs) const {
   
}

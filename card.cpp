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
    mySuit = spades;
    myRank = 1;
}

//Parameter Constructor
Card::Card(int rank, Suit s) {
   mySuit = s;
   myRank = rank;
}

//FUNCTION: toString
// converts a card to a string, e.g. Ac 4h Js, to print
string Card::toString() const {
    string s;
    s = rankString(myRank) + suitString(mySuit);
    return s;
}

//FUNCTION: sameSuitAs
// returns true if same suit as Card c
bool Card::sameSuitAs(const Card &c) const {
     if (this->mySuit == c.mySuit){
        return true;
    } else {
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
// Precondition: passed a valid suit
string Card::suitString(Suit s) const {
    string suit;
    if (s == spades) {
        suit = "s";
    } else if (s == hearts) {
        suit = "h";
    } else if (s == diamonds) {
        suit = "d";
    } else if (s == clubs){
        suit = "c";
    }
    return suit;
}

//FUNCTION: rankString
// returns "A", "2", ..."Q"
// Precondition: passed a valid rank
string Card::rankString(int r) const {
    string rank;
    if (r == 1) {
        rank = "A";
    } else if (r == 2) {
        rank = "2";
    } else if (r == 3) {
        rank = "3";
    } else if (r == 4) {
        rank = "4";
    } else if (r == 5) {
        rank = "5";
    } else if (r == 6) {
        rank = "6";
    } else if (r == 7) {
        rank = "7";
    } else if (r == 8) {
        rank = "8";
    } else if (r == 9) {
        rank = "9";
    } else if (r == 10) {
        rank = "10";
    } else if (r == 11) {
        rank = "J";
    } else if (r == 12) {
        rank = "Q";
    } else if (r == 13){
        rank = "K";
    }
    return rank;
}

//OPERATOR:: Equality
bool Card::operator == (const Card &rhs) const {
   if (myRank == rhs.getRank() && this->sameSuitAs(rhs) ) {
       return true;
   } else {
       return false;
   }
}

//OPERATOR:: Inequality
bool Card::operator != (const Card &rhs) const {
    if (myRank != rhs.getRank() && !(this->sameSuitAs(rhs))) {
        return true;
    } else {
        return false;
    }
}

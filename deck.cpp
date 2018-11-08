//File Name: deck.cpp
//
//Deck program
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
 */

#include "deck.h"
#include <cstdlib>
#include <ctime>
#include "card.h"
using namespace std;

//Default Constructor
// pristine, sorted deck
Deck::Deck() {
    //Random Seeder using the clock
    unsigned int currentTime = (unsigned) time(0);
    srand(currentTime);
    //creates 52 cards (13*4)
    int idx = 0;
    for (int rank = 1; rank <= 13; rank++) {
        for (int suit = 0; suit <= 3; suit++) {
            if (suit == 0) {
                myCards[idx] = Card(rank, Card::spades);
            } else if (suit == 1) {
                myCards[idx] = Card(rank, Card::hearts);
            } else if (suit == 2) {
                myCards[idx] = Card(rank, Card::diamonds);
            } else {
                myCards[idx] = Card(rank, Card::clubs);
            }
            idx++;
        }
    }
    myIndex = 0;
}

//FUNCTION: shuffle
// shuffle the deck of any valid size
// Precondition: deck must not be empty
// INPUT: N/A
// OUTPUT: N/A
void Deck::shuffle() {
    Card temp;
    int randIdx1 = 0;
    int randIdx2 = 0;
    for(int i =0; i < SIZE; i++){
        randIdx1 =  (rand() % size());
        randIdx2 =  (rand() % size());
        temp = myCards[myIndex + randIdx1];
        myCards[myIndex + randIdx1] = myCards[myIndex + randIdx2];
        myCards[myIndex + randIdx2] = temp;
    }
}

//FUNCTION: dealCard
// get a card, after 52 are dealt, fail
// Precondition: deck is not empty
// INPUT: N/A
// OUTPUT: card at "top" of deck
Card Deck::dealCard() {
    Card c;
    if (myIndex < SIZE) {
        c = myCards[myIndex];
        myIndex++;
    }
    return c;
}

//FUNCTION: size
// number of cards left in the deck
// INPUT: N/A
// OUTPUT: integer of cards left
int Deck::size() const {
    int size = SIZE - myIndex;
    if (size > 0) {
        return size;
    } else {
        return 0;
    }
}

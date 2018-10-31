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
// shuffle the deck, all 52 cards present
// *calling shuffle again replenishes the deck
void Deck::shuffle() {
    unsigned int currentTime = (unsigned) time(0);
    srand(currentTime);
    Card temp;
    int randLength1 = 0;
    int randLegth2 = 0;
    for(int i =0; i < SIZE; i++){
        randLength1 =  (rand() % SIZE);
        randLegth2 =  (rand() % SIZE);
        temp = myCards[randLength1];
        myCards[randLength1] = myCards[randLegth2];
        myCards[randLegth2] = temp;
    }
}

//FUNCTION: dealCard
// get a card, after 52 are dealt, fail
Card Deck::dealCard() {
    Card c;
    if (myIndex >= 52) {
        c = myCards[myIndex];
        myIndex++;
    } else {
        cout << "FAIL";
    }
    return c;
}

//FUNCTION: size
// # cards left in the deck
int Deck::size() const {
    int size = SIZE - myIndex;
    if (size > 0) {
        return size;
    } else {
        return 0;
    }
}

//FILE: go_fish.cpp
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

#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;

// PROTOTYPES for functions used for go_fish

//FUNCTION: dealHand
void dealHand(Deck &d, Player &p, int numCards);

int main()
{
    int numCards = 7; //standard # cards per player

    Player p1("Joe"); //player 1
    Player p2("Jane"); //player 2

    Deck d;  //create a deck of cards
    //d.shuffle();

    Card test(1, Card::spades);
    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);
    p1.removeCardFromHand(test);
    cout << p2.getHandSize() << endl;
    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << p2.getName() <<" has : " << p2.showHand() << endl;

    return EXIT_SUCCESS;
}

void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}
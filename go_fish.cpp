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

//FUNCTION: print hands
void printHands(Player &p1, Player &p2);

int main()
{
    int numCards = 7; //standard # cards per player

    Player p1("Reid"); //player 1
    Player p2("Ricky"); //player 2

    Deck d;  //create a deck of cards
    d.shuffle();

    //deal each player their cards
    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);
    printHands(p1, p2);

    //check for starting pairs
    Card c1; //card1 to help store
    Card c2; //card2 to help store
    //player 1
    if (p1.checkHandForPair(c1, c2)) {
        p1.bookCards(c1, c2);
        p1.removeCardFromHand(c1);
        p1.removeCardFromHand(c2);
    }
    if (p1.checkHandForPair(c1, c2)) {
        p1.bookCards(c1, c2);
        p1.removeCardFromHand(c1);
        p1.removeCardFromHand(c2);
    }
    if (p1.checkHandForPair(c1, c2)) {
        p1.bookCards(c1, c2);
        p1.removeCardFromHand(c1);
        p1.removeCardFromHand(c2);
    }
    //player 2
    if (p2.checkHandForPair(c1, c2)) {
        p2.bookCards(c1, c2);
        p2.removeCardFromHand(c1);
        p2.removeCardFromHand(c2);
    }
    if (p2.checkHandForPair(c1, c2)) {
        p2.bookCards(c1, c2);
        p2.removeCardFromHand(c1);
        p2.removeCardFromHand(c2);
    }
    if (p2.checkHandForPair(c1, c2)) {
        p2.bookCards(c1, c2);
        p2.removeCardFromHand(c1);
        p2.removeCardFromHand(c2);
    }

    printHands(p1,p2);
    //BEGIN GAME
    unsigned long counter = 0;
    while (((p1.getBookSize() + p2.getBookSize()) != 26)) {
        printHands(p1,p2);
        bool turn = (counter % 2); //0 (Ricky) or 1 (Reid) depending on who's turn
        //Reid's Turn
        if (turn) {
            //prompt player
            Card prompt = p1.chooseCardFromHand();
            cout << "Reid asks - Do you have a " << prompt.rankString(prompt.getRank()) << endl;
            if (p2.rankInHand(prompt)) {
                //response
                cout << "Ricky says - Yes, I have a " << prompt.rankString(prompt.getRank()) << endl;
                //remove cards from hands and book cards
                Card c1 = p1.removeCardFromHand(prompt); //card1 to help store
                Card c2; //card2 to help store
                Card checkSpades(prompt.getRank(), Card::spades); //card2 to help store
                Card checkClubs(prompt.getRank(), Card::clubs);
                Card checkHearts(prompt.getRank(), Card::hearts);
                Card checkDiamonds(prompt.getRank(), Card::diamonds);
                if (p2.cardInHand(checkSpades)) {
                    c2 = p2.removeCardFromHand(checkSpades);
                } else if (p2.cardInHand(checkClubs)) {
                    c2 = p2.removeCardFromHand(checkClubs);
                } else if (p2.cardInHand(checkHearts)) {
                    c2 = p2.removeCardFromHand(checkHearts);
                } else {
                    c2 = p2.removeCardFromHand(checkDiamonds);
                }
                p1.bookCards(c1, c2);
            } else {
                //response
                cout << "Ricky says - Go Fish." << endl;
                //draw
                if (d.size() > 0) {
                    p1.addCard(d.dealCard());
                    //immediately check for pair
                    Card c1; //card1 to help store
                    Card c2; //card2 to help store
                    if (p1.checkHandForPair(c1, c2)) {
                        p1.bookCards(c1, c2);
                        p1.removeCardFromHand(c1);
                        p1.removeCardFromHand(c2);
                    }
                }
                counter++;
            }
        }
        //Ricky's Turn
        if (!turn) {
            //prompt player
            Card prompt = p2.chooseCardFromHand();
            cout << "Ricky asks - Do you have a " << prompt.rankString(prompt.getRank()) << endl;
            if (p1.rankInHand(prompt)) {
                //response
                cout << "Reid says - Yes, I have a " << prompt.rankString(prompt.getRank()) << endl;
                //remove cards from hands and book cards
                Card c1 = p2.removeCardFromHand(prompt); //card1 to help store
                Card c2; //card2 to help store
                Card checkSpades(prompt.getRank(), Card::spades); //card2 to help store
                Card checkClubs(prompt.getRank(), Card::clubs);
                Card checkHearts(prompt.getRank(), Card::hearts);
                Card checkDiamonds(prompt.getRank(), Card::diamonds);
                if (p1.cardInHand(checkSpades)) {
                    c2 = p1.removeCardFromHand(checkSpades);
                } else if (p1.cardInHand(checkClubs)) {
                    c2 = p1.removeCardFromHand(checkClubs);
                } else if (p1.cardInHand(checkHearts)) {
                    c2 = p1.removeCardFromHand(checkHearts);
                } else {
                    c2 = p1.removeCardFromHand(checkDiamonds);
                }
                p2.bookCards(c1, c2);
            } else {
                //response
                cout << "Reid says - Go Fish." << endl;
                //draw
                if (d.size() > 0) {
                    p2.addCard(d.dealCard());
                    //immediately check for pair
                    Card c1; //card1 to help store
                    Card c2; //card2 to help store
                    if (p2.checkHandForPair(c1, c2)) {
                        p2.bookCards(c1, c2);
                        p2.removeCardFromHand(c1);
                        p2.removeCardFromHand(c2);
                    }
                }
                counter++;
            }
        }
    }

    return EXIT_SUCCESS;
}

void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}

void printHands(Player &p1, Player &p2) {
    cout << p1.getName() <<" has : \n" << p1.showHand() << endl;
    cout << p2.getName() <<" has : \n" << p2.showHand() << endl;
}
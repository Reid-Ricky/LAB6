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

/*


#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;

// PROTOTYPES for functions used for go_fish

//FUNCTION: dealHand
void dealHand(Deck &d, Player &p, int numCards);

//FUNCTION: printHands
void printHands(Player &p1, Player &p2);

//FUNCTION: getBooked
string getBooked(Card &c1, Card &c2);

//FUNCTION: getDrawn
string getDrawn(Card &c1);

int main()
{
    cout << "***GO FISH***" << endl << endl;
    int numCards = 7; //standard # cards per player

    Player p1("Reid"); //player 1
    Player p2("Ricky"); //player 2

    Deck d;  //create a deck of cards
    d.shuffle();
    cout << "Shuffling cards..." << endl;

    //deal each player their cards
    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);
    //printHands(p1, p2);
    cout << "Dealing cards..." << endl << endl;

    //check for starting pairs
    Card c1; //card1 to help store
    Card c2; //card2 to help store
    //player 1
    if (p1.checkHandForPair(c1, c2)) {
        p1.bookCards(c1, c2);
        p1.removeCardFromHand(c1);
        p1.removeCardFromHand(c2);
        cout << p1.getName() << " " << getBooked(c1, c2) << endl;
    }
    if (p1.checkHandForPair(c1, c2)) {
        p1.bookCards(c1, c2);
        p1.removeCardFromHand(c1);
        p1.removeCardFromHand(c2);
        cout << p1.getName() << " " << getBooked(c1, c2) << endl;
    }
    if (p1.checkHandForPair(c1, c2)) {
        p1.bookCards(c1, c2);
        p1.removeCardFromHand(c1);
        p1.removeCardFromHand(c2);
        cout << p1.getName() << " " << getBooked(c1, c2) << endl;
    }
    //player 2
    if (p2.checkHandForPair(c1, c2)) {
        p2.bookCards(c1, c2);
        p2.removeCardFromHand(c1);
        p2.removeCardFromHand(c2);
        cout << p2.getName() << " " << getBooked(c1, c2) << endl;
    }
    if (p2.checkHandForPair(c1, c2)) {
        p2.bookCards(c1, c2);
        p2.removeCardFromHand(c1);
        p2.removeCardFromHand(c2);
        cout << p2.getName() << " " << getBooked(c1, c2) << endl;
    }
    if (p2.checkHandForPair(c1, c2)) {
        p2.bookCards(c1, c2);
        p2.removeCardFromHand(c1);
        p2.removeCardFromHand(c2);
        cout << p2.getName() << " " << getBooked(c1, c2) << endl;
    }

    cout << endl << "LET THE GAME BEGIN!!!!!" << endl << endl;

    //printHands(p1,p2);
    //BEGIN GAME
    unsigned long counter = 0;
    while (((p1.getBookSize() + p2.getBookSize()) != 26)) {
        //printHands(p1,p2);
        bool turn = (counter % 2); //0 (Ricky) or 1 (Reid) depending on who's turn
        //Reid's Turn
        if (turn) {
            //prompt player
            Card prompt = p1.chooseCardFromHand();
            cout << p1.getName() << " asks - Do you have a " << prompt.rankString(prompt.getRank()) << endl;
            if (p2.getHandSize() > 0 && p2.rankInHand(prompt)) {
                //response
                cout << p2.getName() << " says - Yes, I have a " << prompt.rankString(prompt.getRank()) << endl;
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
                cout << p1.getName() << " " << getBooked(c1, c2) << endl;
            } else {
                //response
                cout << p2.getName() << " says - Go Fish." << endl;
                //draw
                if (d.size() > 0) {
                    Card deal = d.dealCard();
                    p1.addCard(deal);
                    cout << p1.getName() << " " << getDrawn(deal) << endl;
                    //immediately check for pair
                    Card c1; //card1 to help store
                    Card c2; //card2 to help store
                    if (p1.checkHandForPair(c1, c2)) {
                        p1.bookCards(c1, c2);
                        p1.removeCardFromHand(c1);
                        p1.removeCardFromHand(c2);
                        cout << p1.getName() << " " << getBooked(c1, c2) << " because he drew a pair." << endl;
                    }
                }
                counter++;
            }
        }
        //Ricky's Turn
        if (!turn) {
            //prompt player
            Card prompt = p2.chooseCardFromHand();
            cout << p2.getName() << " asks - Do you have a " << prompt.rankString(prompt.getRank()) << endl;
            if (p2.getHandSize() > 0 && p1.rankInHand(prompt)) {
                //response
                cout << p1.getName() << " says - Yes, I have a " << prompt.rankString(prompt.getRank()) << endl;
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
                cout << p2.getName() << " " << getBooked(c1, c2) << endl;
            } else {
                //response
                cout << p1.getName() << " says - Go Fish." << endl;
                //draw
                if (d.size() > 0) {
                    Card deal = d.dealCard();
                    p2.addCard(deal);
                    cout << p2.getName() << " " << getDrawn(deal) << endl;
                    //immediately check for pair
                    Card c1; //card1 to help store
                    Card c2; //card2 to help store
                    if (p2.checkHandForPair(c1, c2)) {
                        p2.bookCards(c1, c2);
                        p2.removeCardFromHand(c1);
                        p2.removeCardFromHand(c2);
                        cout << p2.getName() << " " << getBooked(c1, c2) << " because he drew a pair." << endl;
                    }
                }
                counter++;
            }
        }
        if (p1.getHandSize() == 0 && d.size() > 0) {
            Card deal = d.dealCard();
            p1.addCard(deal);
            cout << p1.getName() << " " << getDrawn(deal) << " because his hand was empty." << endl;
            counter++;
        }
        if (p2.getHandSize() == 0 && d.size() > 0) {
            Card deal = d.dealCard();
            p2.addCard(deal);
            cout << p2.getName() << " " << getDrawn(deal) << " because his hand was empty." << endl;
            counter++;
        }
        cout << endl;
    }

    //END OF GAME and DECIDE WINNER
    cout << "Reid's Books: \n" << p1.showBooks() << endl;
    cout << "Ricky's Books: \n" << p2.showBooks() << endl;
    if (p1.getBookSize() > p2.getBookSize()) {
        cout << "REID has " << p1.getBookSize() << " books" << endl;
        cout << "RICKY has " << p2.getBookSize() << " books" << endl;
        cout << "***REID WINS***";
    } else if (p1.getBookSize() < p2.getBookSize()) {
        cout << "REID has " << p1.getBookSize() << " books" << endl;
        cout << "RICKY has " << p2.getBookSize() << " books" << endl;
        cout << "***RICKY WINS***";
    } else {
        cout << "REID has " << p1.getBookSize() << " books" << endl;
        cout << "RICKY has " << p2.getBookSize() << " books" << endl;
        cout << "***TIE***";
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

string getBooked(Card &c1, Card &c2) {
    return "books the " + c1.toString() + ", " + c2.toString();
}

string getDrawn(Card &c1) {
    return "draws the " + c1.toString();
}

*/
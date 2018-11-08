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

#include <iostream>    // Provides file and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <string.h>
#include <fstream>
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;

// PROTOTYPES for functions used for go_fish

//FUNCTION: dealHand
// deals numCards amount of cards from deck d to player p
// INPUT: deck, player, integer of desired hand size
// OUTPUT: N/A
void dealHand(Deck &d, Player &p, int numCards);

//FUNCTION: getBooked
// returns string concatenation of booking cards
// INPUT: card1, card2
// OUTPUT: string
string getBooked(Card &c1, Card &c2);

//FUNCTION: getDrawn
// returns string concatenation of drawing cards
// INPUT: card1, card2
// OUTPUT: string concatenation
string getDrawn(Card &c1);

int main(int agrc, char* argv[]) {
    //LINUX COMMANDS
    //char fName[BUFSIZ];
    //strcpy(fName, argv[1]);

    //CLION COMMANDS
    string fName = "gofish_results.txt";

    //FILE SETUP
    ofstream file (fName);
    file << "***GO FISH***" << endl << endl;

    //standard # cards per player
    int numCards = 7;

    Player p1("Reid"); //player 1
    Player p2("Ricky"); //player 2

    //create a deck of cards and shuffle it
    Deck d;
    d.shuffle();
    file << "Shuffling cards..." << endl;

    //deal each player their cards
    file << "Dealing cards..." << endl << endl;
    dealHand(d, p1, numCards);
    file << p1.getName() << "'s initial hand:\n" << p1.showHand() << endl;
    dealHand(d, p2, numCards);
    file << p2.getName() << "'s initial hand:\n" << p2.showHand() << endl;

    //check for starting pairs (three times each player)
    Card c1; //card1 to help store
    Card c2; //card2 to help store
    //player 1
    if (p1.checkHandForPair(c1, c2)) {
        p1.bookCards(c1, c2);
        p1.removeCardFromHand(c1);
        p1.removeCardFromHand(c2);
        file << p1.getName() << " " << getBooked(c1, c2) << endl;
    }
    if (p1.checkHandForPair(c1, c2)) {
        p1.bookCards(c1, c2);
        p1.removeCardFromHand(c1);
        p1.removeCardFromHand(c2);
        file << p1.getName() << " " << getBooked(c1, c2) << endl;
    }
    if (p1.checkHandForPair(c1, c2)) {
        p1.bookCards(c1, c2);
        p1.removeCardFromHand(c1);
        p1.removeCardFromHand(c2);
        file << p1.getName() << " " << getBooked(c1, c2) << endl;
    }
    //player 2
    if (p2.checkHandForPair(c1, c2)) {
        p2.bookCards(c1, c2);
        p2.removeCardFromHand(c1);
        p2.removeCardFromHand(c2);
        file << p2.getName() << " " << getBooked(c1, c2) << endl;
    }
    if (p2.checkHandForPair(c1, c2)) {
        p2.bookCards(c1, c2);
        p2.removeCardFromHand(c1);
        p2.removeCardFromHand(c2);
        file << p2.getName() << " " << getBooked(c1, c2) << endl;
    }
    if (p2.checkHandForPair(c1, c2)) {
        p2.bookCards(c1, c2);
        p2.removeCardFromHand(c1);
        p2.removeCardFromHand(c2);
        file << p2.getName() << " " << getBooked(c1, c2) << endl;
    }

    //BEGIN GAME
    file << endl << "LET THE GAME BEGIN!!!!!" << endl << endl;
    unsigned long counter = 0; //used to keep track of turn
    //game is over when the total book size is 26
    while (((p1.getBookSize() + p2.getBookSize()) != 26)) {
        bool turn = (counter % 2); //0 (Player 2) or 1 (Player 1) depending on who's turn
        //Player 1's Turn
        if (turn) {
            //prompt opposing player
            Card prompt = p1.chooseCardFromHand();
            file << p1.getName() << " asks - Do you have a " << prompt.rankString(prompt.getRank()) << endl;
            //SUCCESSFUL ask
            if (p2.getHandSize() > 0 && p2.rankInHand(prompt)) {
                //response of opposing player
                file << p2.getName() << " says - Yes, I have a " << prompt.rankString(prompt.getRank()) << endl;
                //remove cards from hands and book cards
                Card c1 = p1.removeCardFromHand(prompt); //card1 to help store
                Card c2; //card2 to help store
                Card checkSpades(prompt.getRank(), Card::spades); //spades version to check equality
                Card checkClubs(prompt.getRank(), Card::clubs); //clubs version to check equality
                Card checkHearts(prompt.getRank(), Card::hearts); //hearts version to check equality
                Card checkDiamonds(prompt.getRank(), Card::diamonds); //diamonds version to check equality
                //determine which suit the card in hand is
                if (p2.cardInHand(checkSpades)) {
                    c2 = p2.removeCardFromHand(checkSpades);
                } else if (p2.cardInHand(checkClubs)) {
                    c2 = p2.removeCardFromHand(checkClubs);
                } else if (p2.cardInHand(checkHearts)) {
                    c2 = p2.removeCardFromHand(checkHearts);
                } else {
                    c2 = p2.removeCardFromHand(checkDiamonds);
                }
                //BOOK CARDS to Player 1
                p1.bookCards(c1, c2);
                file << p1.getName() << " " << getBooked(c1, c2) << endl;
            } else {
                //response of opposing player
                file << p2.getName() << " says - Go Fish." << endl;
                //draw with valid deck
                if (d.size() > 0) {
                    //DEAL CARD to Player 1
                    Card deal = d.dealCard();
                    p1.addCard(deal);
                    file << p1.getName() << " " << getDrawn(deal) << endl;
                    //immediately check for pair
                    Card c1; //card1 to help store
                    Card c2; //card2 to help store
                    //check for pairs in hand
                    if (p1.checkHandForPair(c1, c2)) {
                        p1.bookCards(c1, c2);
                        p1.removeCardFromHand(c1);
                        p1.removeCardFromHand(c2);
                        file << p1.getName() << " " << getBooked(c1, c2) << " because he drew a pair." << endl;
                    }
                }
                counter++;
            }
        }
        //Player 2's Turn
        if (!turn) {
            //prompt opposing player
            Card prompt = p2.chooseCardFromHand();
            file << p2.getName() << " asks - Do you have a " << prompt.rankString(prompt.getRank()) << endl;
            //SUCCESSFUL ask
            if (p2.getHandSize() > 0 && p1.rankInHand(prompt)) {
                //response of opposing player
                file << p1.getName() << " says - Yes, I have a " << prompt.rankString(prompt.getRank()) << endl;
                //remove cards from hands and book cards
                Card c1 = p2.removeCardFromHand(prompt); //card1 to help store
                Card c2; //card2 to help store
                Card checkSpades(prompt.getRank(), Card::spades); //spades version to check equality
                Card checkClubs(prompt.getRank(), Card::clubs); //clubs version to check equality
                Card checkHearts(prompt.getRank(), Card::hearts); //hearts version to check equality
                Card checkDiamonds(prompt.getRank(), Card::diamonds); //diamonds version to check equality
                //determine which suit the card in hand is
                if (p1.cardInHand(checkSpades)) {
                    c2 = p1.removeCardFromHand(checkSpades);
                } else if (p1.cardInHand(checkClubs)) {
                    c2 = p1.removeCardFromHand(checkClubs);
                } else if (p1.cardInHand(checkHearts)) {
                    c2 = p1.removeCardFromHand(checkHearts);
                } else {
                    c2 = p1.removeCardFromHand(checkDiamonds);
                }
                //BOOK CARDS to Player 2
                p2.bookCards(c1, c2);
                file << p2.getName() << " " << getBooked(c1, c2) << endl;
            } else {
                //response of opposing player
                file << p1.getName() << " says - Go Fish." << endl;
                //draw with valid deck
                if (d.size() > 0) {
                    Card deal = d.dealCard();
                    p2.addCard(deal);
                    file << p2.getName() << " " << getDrawn(deal) << endl;
                    //immediately check for pair
                    Card c1; //card1 to help store
                    Card c2; //card2 to help store
                    //check for pairs in hand
                    if (p2.checkHandForPair(c1, c2)) {
                        p2.bookCards(c1, c2);
                        p2.removeCardFromHand(c1);
                        p2.removeCardFromHand(c2);
                        file << p2.getName() << " " << getBooked(c1, c2) << " because he drew a pair." << endl;
                    }
                }
                counter++;
            }
        }
        //DO NOT CONTINUE IF EMPTY HAND!!!
        //Player 1 will draw if empty hand AND change turn
        if (p1.getHandSize() == 0 && d.size() > 0) {
            Card deal = d.dealCard();
            p1.addCard(deal);
            file << p1.getName() << " " << getDrawn(deal) << " because his hand was empty." << endl;
            counter++;
        }
        //Player 2 will draw if empty hand AND change turn
        if (p2.getHandSize() == 0 && d.size() > 0) {
            Card deal = d.dealCard();
            p2.addCard(deal);
            file << p2.getName() << " " << getDrawn(deal) << " because his hand was empty." << endl;
            counter++;
        }
        file << endl;
    }

    //END OF GAME and DECIDE WINNER
    file << p1.getName() << "'s Books: \n" << p1.showBooks() << endl; //Player 1 book contents
    file << p2.getName() << "'s Books: \n" << p2.showBooks() << endl; //Player 2 book contents
    if (p1.getBookSize() > p2.getBookSize()) {
        file << p1.getName() << " has " << p1.getBookSize() << " books" << endl; //Player 1 # books
        file << p2.getName() << " has " << p2.getBookSize() << " books" << endl; //Player 2 # books
        file << "***REID WINS***";
    } else if (p1.getBookSize() < p2.getBookSize()) {
        file << p1.getName() << " has " << p1.getBookSize() << " books" << endl; //Player 1 # books
        file << p2.getName() << " has " << p2.getBookSize() << " books" << endl; //Player 2 # books
        file << "***RICKY WINS***";
    } else {
        file << p1.getName() << " has " << p1.getBookSize() << " books" << endl; //Player 1 # books
        file << p2.getName() << " has " << p2.getBookSize() << " books" << endl; //Player 2 # books
        file << "***TIE***";
    }


    file.close();
    return EXIT_SUCCESS;
}

//FUNCTION: dealHand
// deals numCards amount of cards from deck d to player p
// INPUT: deck, player, integer of desired hand size
// OUTPUT: N/A
void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}

//FUNCTION: getBooked
// returns string concatenation of booking cards
// INPUT: card1, card2
// OUTPUT: string concatenation
string getBooked(Card &c1, Card &c2) {
    return "books the " + c1.toString() + ", " + c2.toString();
}

//FUNCTION: getDrawn
// returns string concatenation of drawing cards
// INPUT: card1, card2
// OUTPUT: string concatenation
string getDrawn(Card &c1) {
    return "draws the " + c1.toString();
}
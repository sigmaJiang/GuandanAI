/******************************************************************************
 *
 * GuandanAI 1.0 Created by SigmaJ, in 2016.04.20.
 *
 * v1.1 add shuffle function, in 2016.04.29
 * 
 * ***************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CARDNUM 108

typedef struct PokerCard{
   	int Name;
	int Kind;
	int KingKind;
	int SequenceNum;
}CARD;

enum CardName{
	Ace,
	Two,
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eight,
	Nine,
	Ten,
	Jack,
	Queen,
	King,
	Joker,
	CardNameNum
};

enum CardKind{
    DefaultKind,
	Spade,
	Heart,
	Club,
	Diamond,
	CardKindNum
};

enum CardKingKind{
    DefaultKingKind,
    RedJoker,
	BlackJoker,
	CardKingKindNum
};

void init_cards( CARD t_cards[]);

void shuffle_cards( CARD t_cards[]);


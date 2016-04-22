/******************************************************************************
 *
 * GuandanAI 1.0 Created by SigmaJ, in 2016.04.20.
 *
 *
 * 
 * ***************************************************************************/


#include <stdio.h>
#include <stdlib.h>

typedef struct PokerCard
{
    char PokerCardName[20];
	int PokerNum;
	int PokerKind;
	int PokerKingKind;
}poker_card;

enum PokerNum
{
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
	TotalNum
};

enum PokerKind
{
	spade,
	heart,
	club,
	diamond
};

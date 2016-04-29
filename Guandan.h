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
#define PLAYERNUM 4
#define HANDCARDMAX 27

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

enum RoundResult{
	DefaultResult,
	LoseGame,
	WinGame
};

enum Tribute{
	DefaultTribute,
	TributeSend,
	TributeReceive
};

typedef struct GDPlayer{
	char name[64];
	int seat;
	CARD hand_cards[HANDCARDMAX];
	int LastRoundResult;
	int Tributary;
}PLAYER;

typedef struct ScoreIndicator{
	int partnerA;
	int partnerB;
	int round;
}SCOREIND;

void init_cards( CARD t_cards[]);

void shuffle_cards( CARD t_cards[]);

void deal_cards(CARD t_cards[], PLAYER *t_player1, PLAYER *t_player2, PLAYER *t_player3, PLAYER *t_player4);

/******************************************************************************
  * Guandan main C program
  * 
  * 
  * 
  * ***************************************************************************/

#include "Guandan.h"


void init_cards( CARD t_cards[])
{
    CARD *ptr_t_card = t_cards;
    int i, j;
	int k = 0;
	while(k < CARDNUM)
	{
		for(i = 0; i < CardNameNum; i++){
			for(j = 0; j < CardKindNum - 1; j++){
				if(i < CardNameNum - 1){
					(ptr_t_card+k)->Name = i;
					(ptr_t_card+k)->Kind = j + 1;
					(ptr_t_card+k)->KingKind = DefaultKingKind;
					(ptr_t_card+k)->SequenceNum = k;
					k++;
				}
				else{
                    if(j < CardKindNum - 3){
				    	(ptr_t_card+k)->Name = Joker;
					    (ptr_t_card+k)->Kind = DefaultKind;
					    (ptr_t_card+k)->KingKind = k % 2 + 1;
                        (ptr_t_card+k)->SequenceNum = k;
                        k++;
                    }
				}
			}
		}
	}
}

void switch_card( CARD *a, CARD *b)
{
    CARD temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void shuffle_cards( CARD t_cards[])
{
    CARD *ptr_t_card = t_cards;
	int exc_num1, exc_num2;
	int cnt = CARDNUM * 4;

    srand((unsigned)time(NULL)); 
	while(cnt--){
		exc_num1 = rand() % CARDNUM;
		exc_num2 = rand() % CARDNUM;
        switch_card(&ptr_t_card[exc_num1], &ptr_t_card[exc_num2]);
	}
}

void deal_cards(CARD t_cards[], PLAYER *t_player1, PLAYER *t_player2, PLAYER *t_player3, PLAYER *t_player4)
{
	CARD *ptr_t_card = t_cards;
	int i;
	for(i = 0; i < HANDCARDMAX; i++){
		t_player1->hand_cards[i] = ptr_t_card[4*i];
		t_player2->hand_cards[i] = ptr_t_card[4*i+1];
		t_player3->hand_cards[i] = ptr_t_card[4*i+2];
		t_player4->hand_cards[i] = ptr_t_card[4*i+3];
	}
}

int main(void)
{
	//init all
	CARD t_poker_card[CARDNUM];
	CARD hand_cards1[HANDCARDMAX], hand_cards2[HANDCARDMAX], hand_cards3[HANDCARDMAX], hand_cards4[HANDCARDMAX];

	PLAYER t_card_player[HANDCARDMAX] = {
		{{"Alice"}, 0, {hand_cards1[HANDCARDMAX]}}, 
		{{"Ben"}, 1, {hand_cards2[HANDCARDMAX]}}, 
		{{"Clark"}, 2, {hand_cards3[HANDCARDMAX]}}, 
		{{"Durant"}, 3, {hand_cards4[HANDCARDMAX]}}};

	SCOREIND t_indicator = {2, 2, 1};
	int game_level = 2;

	while(t_indicator.partnerA < 14|| t_indicator.partnerB < 14){
			//start one game
		init_cards(t_poker_card);
		shuffle_cards(t_poker_card);

		if(t_indicator.round != 1){
			//

		}
		else{
			//first game
			deal_cards(t_poker_card, &t_card_player[0], &t_card_player[1], &t_card_player[2], &t_card_player[3]);

		}
	}



	return 0;
}

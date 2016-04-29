/******************************************************************************
  * Guandan main C program
  * 
  * 
  * 
  * ***************************************************************************/

#include "Guandan.h"



CARD t_card_pile[CARDNUM];

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

int main(void)
{
    CARD t_poker_card[CARDNUM];

	init_cards(t_poker_card);
    shuffle_cards(t_poker_card);


    int i;
    for(i = 0; i < CARDNUM; i++){
		printf("%d %d %d %d \n", t_poker_card[i].Name, t_poker_card[i].Kind, t_poker_card[i].KingKind, t_poker_card[i].SequenceNum);

	}

	return 0;
}

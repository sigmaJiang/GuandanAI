/******************************************************************************
  * Guandan main C program
  *
  * 
  *
  * ***************************************************************************/

#include "Guandan.h"


CARD t_poker_card[CARDNUM];

void init_cards(void)
{
    memset(t_poker_card, 0, sizeof(t_poker_card));
    int i;
    int j;
	int k = 0;
	while(k < CARDNUM)
	{
		for(i = 0; i < CardNameNum; i++){
			for(j = 0; j < CardKindNum - 1; j++){
				if(i < CardNameNum - 1){
					t_poker_card[k].Name = i;
					t_poker_card[k].Kind = j + 1;
					t_poker_card[k].KingKind = DefaultKingKind;
					t_poker_card[k].SequenceNum = k;
					k++;
				}
				else{
                    if(j < CardKindNum - 3){
				    	t_poker_card[k].Name = Joker;
					    t_poker_card[k].Kind = DefaultKind;
					    t_poker_card[k].KingKind = k % 2 + 1;
                        t_poker_card[k].SequenceNum = k;
                        k++;
                    }
				}
			}
		}
	}
}

void shuffle_cards(CARD *t_card[])
{
    CARD temp;
	int exc_num1, exc_num2;
	int cnt = CARDNUM * 4;
	while(cnt--){
		exc_num1 = rand() % CARDNUM;
		exc_num2 = rand() % CARDNUM;
		temp = *t_card[exc_num1];
		*t_card[exc_num1] = *t_card[exc_num2];
		*t_card[exc_num2] = temp;
	}
}

int main(void)
{
	init_cards();

    shuffle_cards(t_poker_card);
    int i;
    for(i = 0; i < CARDNUM; i++){
		printf("%d %d %d %d \n", t_poker_card[i].Name, t_poker_card[i].Kind, t_poker_card[i].KingKind, t_poker_card[i].SequenceNum);

	}

	return 0;
}

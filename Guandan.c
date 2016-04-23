/******************************************************************************
  * Guandan main C program
  *
  * 
  *
  * ***************************************************************************/

#include "Guandan.h"


CARD t_poker_card[CARDNUM];


void init_card(void)
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
					k++;
				}
				else{
                    if(j < CardKindNum - 3){
				    	t_poker_card[k].Name = Joker;
					    t_poker_card[k].Kind = DefaultKind;
					    t_poker_card[k].KingKind = k % 2 + 1;
                        k++;
                    }
				}
			}
		}
	}
	for(i = 0; i < k; i++){
		printf("%d %d %d \n", t_poker_card[i].Name, t_poker_card[i].Kind, t_poker_card[i].KingKind);
	}
	//printf("k = %d\n", k);
}

int main(void)
{
	init_card();


	return 0;
}

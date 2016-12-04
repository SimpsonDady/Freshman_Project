#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void move (int money[],int location[],int i)
{
    srand(time(NULL));
    int dice1=rand()%6+1,dice2=rand()%6+1,total;
    total=dice1+dice2;
    printf("The dice point:%d+%d=%d",dice1,dice2,total);
    location[i]+=total;
    if(location[i]>=20){
        location[i]-=20;
        if(location[i]==0){
        }
        else{
            money[i]+=2000;
        }
    }
}

#include <stdio.h>
#include <stdlib.h>

void broke(int player,int level[],int type[])
{
    int i;
    for(i=0;i<=20;i++)
    {
        if(type[i]==player)
        {
            type[i]=0;
            level[i]=1;
        }
    }
}
void toll(int player,int type[],int money[],int level[],int tolls[][4],int location)
{
    printf("You must pay to %c for %d dollars\n",type[location]+65,tolls[location][level[location]-1]);
    money[player]-=tolls[location][level[location]-1];
    money[type[location]]+=tolls[location][level[location]-1];
}
void land(int player,int money[],int price[][4],int type[],int level[],int location)
{
    char decide;
    printf("Do you want to buy this land?(y/n):");
    do{
        scanf(" %c",&decide);
        if(decide!='y'&&decide!='n')
        {
            printf("Please enter again\n");
        }
    }while(decide!='y'&&decide!='n');
    if(decide=='y')
    {
        if(money[player]<price[location][0])
        {
            printf("Your money is not enough\n");
        }
        else
        {
            money[player]-=price[location][0];
            type[location]=player;
        }
    }
}
void prison(int player,int stay[])
{
    printf("You must stay here 5 day\n");
    stay[player]=stay[player]+5;
}
void hospital(int player,int money[],int stay[])
{
    printf("You must stay here 3 day and must pay 1000 dollars\n");
    money[player]-=1000;
    stay[player]=stay[player]+3;
}
void upgrade(int player,int money[],int price[][4],int type[],int level[],int location)
{
    char decide;
    printf("Do you want to upgrade this land?(y/n):");
    do{
        scanf(" %c",&decide);
        if(decide!='y'&&decide!='n')
        {
            printf("Please enter again\n");
        }
    }while(decide!='y'&&decide!='n');
    if(decide=='y'){
        if(money[player]<price[location][level[location]])
        {
            printf("Your money is not enough\n");
        }
        else
        {
            money[player]-=price[location][level[location]];
            level[location]+=1;
        }
    }
    else if(decide=='n');
}
int main()
{
    return 0;
}

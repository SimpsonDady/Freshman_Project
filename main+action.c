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
    int money[4],out[4],location[4],level[20],stay[4],type[20]/*0~3:有人地,4:無人地6:監獄,8:醫院,5:起點7:商店*/;
    int people,i,j,flag=0,price[20][4],tolls[20][4];
    char name[20][7],player_name[4][50];
    srand(time(NULL));
    do
    {
        printf("How many player:");
        scanf("%d",&people);
    }
    while(people<2||people>4);
    printf("player name:\n");
    for(i=0;i<people;i++)
    {
        printf("P%d:",i+1);
        scanf(" %s",player_name[i]);
    }
    for(i=0;i<=3;i++)
    {
        stay[i]=0;
        money[i]=50000;
        out[i]=0;
        location[i]=0;
    }
    for(i=0;i<=19;i++)
    {
        if(i%5==0)
        {
            type[i]=i/5+5;
            level[i]=0;
        }
        else
        {
            level[i]=1;
            type[i]=4;
        }
    }
    FILE *file=fopen("map.txt","r");
    for(i=0;!feof(file);i++)
    {
        fscanf(file,"%s",name[i]);
        for(j=0;j<=3;j++)
        {
            fscanf(file,"%d",&price[i][j]);
        }
        for(j=0;j<=3;j++)
        {
            fscanf(file,"%d",&tolls[i][j]);
        }
    }
    fclose(file);
    for(i=0;i<=19;i++)
    {
        printf("%s\t",name[i]);
    }
    printf("\n");
    while(flag!=people-1)
    {
        for(i=0;i<people;i++)
        {
            printf("\n");
            if(money[i]>=0&&out[i]==0)
            {
                printf("turn %c\n",65+i);
                if(stay[i]>0)
                {
                    printf("%c need to stay %d\n",65+i,stay[i]);
                    stay[i]-=1;
                }
                else
                {
                    move(money,location,i);
                    printf("Location:%d\n",location[i]);
                    if(type[location[i]]==6)
                    {
                        prison(i,stay);
                    }
                    else if(type[location[i]]==8)
                    {
                        hospital(i,money,stay);
                    }
                    else if(type[location[i]]!=i&&type[location[i]]!=4&&type[location[i]]!=5&&type[location[i]]!=6&&type[location[i]]!=7&&type[location[i]]!=8)
                    {
                        toll(i,type,money,level,tolls,location[i]);
                    }
                    else if(type[location[i]]==4)
                    {
                        land(i,money,price,type,level,location[i]);
                    }
                    else if(type[location[i]]==i)
                    {
                        upgrade(i,money,price,type,level,location[i]);
                    }
                }
                for(j=0;j<people;j++)
                {
                    printf("%c:",65+j);
                    printf("%d\t",money[j]);
                }
                printf("\n");
            }
            if(money[i]<0&&out[i]==0)
            {
                broke(i,level,type);
                out[i]=1;
                flag++;
            }
        }
    }
    for(i=0;i<people;i++)
    {
        if(money[i]>=0)
        {
            printf("%c win",65+i);
        }
    }
	return 0;
}

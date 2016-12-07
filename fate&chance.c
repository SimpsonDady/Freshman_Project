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
void chance(int player,int money[],int price[][4],int type[],int stay[],int level[],int tolls[],int location[],int protection[],int allplayer)
{
    int dice,i,j,choice,flag=0;
    char playerchoice;
    dice=rand()%10+1;
    switch(dice)
    {
        case 1:
            money[player]+=1000;
            printf("獲得1000元\n");
            break;
        case 2:
            printf("選擇一塊地(輸入1~20 起點為1 處理器為20)level+1:");
            do{
                scanf("%d",&choice);
                choice-=1;
                if(level[choice]==4)
                {
                    choice=100;
                }
                else
                {
                    level[choice]+=1;
                }
            }while(choice>19||choice<0);
            printf("已升級\n");
            break;
        case 3:
            printf("選擇一塊地(輸入1~20 起點為1 處理器為20)level-1:");
            do{
                scanf("%d",&choice);
                choice-=1;
                if(level[choice]==0)
                {
                    choice=100;
                }
                else
                {
                    level[choice]-=1;
                }
            }while(choice>19||choice<0);
            printf("已降級\n");
            break;
        case 4:
            printf("選擇一地(輸入1~20 起點為1 處理器為20)到達該地點:");
            do{
                scanf("%d",&choice);
                choice-=1;
            }while(choice>19||choice<0);
            location[player]=choice;
            printf("已到達\n");
            break;
        case 5:
            printf("直接到達該起點(加2000)\n");
            location[player]=0;
            money[player]+=2000;
            break;
        case 6:
            printf("選擇一塊無人地(輸入1~20 起點為1 處理器為20)獲得擁有權:");
            do{
                scanf("%d",&choice);
                choice-=1;
                if(type[choice]!=0)
                {
                    choice=100;
                }
                else
                {
                    type[choice]=player;
                }
            }while(choice>19||choice<0);
            printf("已獲得\n");
            break;
        case 7:
            printf("銘謝惠顧\n");
            break;
        case 8:
            printf("選擇一名玩家(輸入英文代號)使他停留3回合:");
            do{
                scanf("%c",&playerchoice);
                if(65<=playerchoice&&playerchoice<=64+allplayer)
                {
                    choice=playerchoice-65;
                    flag=1;
                }
                else if(97<=playerchoice&&playerchoice<=96+allplayer)
                {
                    choice=playerchoice-97;
                    flag=1;
                }
            }while(flag==0);
            stay[choice]+=3;
            printf("%c玩家停留3回合\n",playerchoice);
            break;
        case 9:
            money[player]+=5000;
            printf("獲得5000元\n");
        case 10:
            protection[player]++;
            printf("免疫一次入獄或住院\n");
            break;
    }
}
void fate(int player,int money[],int price[][4],int type[],int stay[],int level[],int tolls[],int location[],int allplayer)
{
    int dice,corner[4]={0,5,10,15},i,j,sum=0,temp,playerstay[3];
    dice=rand()%10+1;
    switch(dice)
    {
        case 1:
            stay[player]+=7;
            location[player]=15;
            money[player]-=4000;
            printf("住院7天且付醫藥費4000元\n");
            break;
        case 2:
            do
            {
                dice=rand()%19+0;
            }while(level[dice]==0);
            level[dice]-=1;
            printf("違建所以隨機降低一棟土地的等級\n");
            break;
        case 3:
            stay[player]+=3;
            printf("外星人入侵 所以隨機一名玩家被綁架(待在原地3天)\n");
            break;
        case 4:
            money[player]-=5000;
            dice=rand()%allplayer+1;
            money[dice-1]+=5000;
            printf("你必須付%c玩家5000元(有可能為自己)\n",dice-1+65);
            break;
        case 5:
            dice=rand()%3+0;
            for(i=corner[dice];i<=corner[dice]+4;i++)
            {
                if(level[i]!=1)
                {
                    level[i]-=1;
                }
                else
                {
                    level[i]=1;
                }
            }
            printf("連續四塊地會被降低一等\n");
            break;
        case 6:
            for(i=0;i<4;i++)
            {
                sum+=money[i];
            }
            sum=sum/allplayer;
            for(i=0;i<4;i++)
            {
                money[i]=sum;
            }
            printf("大家資產平分\n");
            break;
        case 7:
            stay[player]+=10;
            location[player]=5;
            money[player]-=4000;
            printf("在公共場所裸奔加性騷擾 進監獄10天和被罰4000元\n");
            break;
        case 8:
            for(i=0;i<4;i++)
            {
                money[i]-=2000;
            }
            printf("每個人都少2000元\n");
            break;
        case 9:
            do{
                dice=rand()%allplayer+1;
            }while(dice-1==player);
            temp=money[dice-1];
            money[dice-1]=money[player];
            money[player]=temp;
            printf("%c的金額和你互換\n",dice-1+65);
            break;
        case 10:
            for(i=0;i<allplayer-1;i++)
            {
                playerstay[i]=(rand()%allplayer+1)-1;
                for(j=0;j<i;j++)
                {
                    if(playerstay[i]==playerstay[j])
                    {
                        playerstay[i]=(rand()%allplayer+1)-1;
                        i--;
                    }
                }
            }
            for(i=0;i<allplayer-1;i++)
            {
                stay[playerstay[i]]+=3;
                printf("%c ",playerstay[i]+65);
            }
            printf("玩家因暴雨而停止3天\n");
            break;
    }
}
int main()
{
	return 0;
}

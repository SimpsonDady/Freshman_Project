#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
void move_display(char Mname[][7],int level[],int owner[],int location[],int num_gamer,int money[],char Pname[][50],int temp,int turn)
{
        int i;
    location[turn]-=temp;

    system("CLS");

    for(i=0;i<=temp;i++)
    {
        display(Mname,level,owner,location,num_gamer,money,Pname);
        location[turn]++;
        Sleep(500);
        system("CLS");
        if(location[turn]>19)
        {
            location[turn]-=20;
            money[turn]+=2000;
        }

    }
    display(Mname,level,owner,location,num_gamer,money,Pname);
}
void display(char Mname[][7],int level[],int owner[],int location[],int num_gamer,int money[],char Pname[][50])
{
    int i,j,count=7,c;
    char code[5]={'A','B','C','D','L'};
    printf("%d",owner[12]);
    printf("\n\t\t");

    for(i=0;i<6;i++)
    {
        for(j=0;j<num_gamer;j++)
        {
            if(location[j]==10+i)
                {
                    printf("%c",code[j]);
                }

        }
        printf("\t\t");

    }

    printf("\n");
    for(i=10;i>=5;i--)
    {
        if(i==10)
        {
            for(j=i;j<16;j++)
            {
                printf("\t\t%s",Mname[j]);
            }
            printf("\n\t\t\t\t");
            for(j=11;j<=14;j++)
            {
                printf("  %c.%d\t\t",code[owner[j]],level[j]);
            }
            printf("\n");
        }
        else if(i<=9&&i>5)
        {
            printf("\t");
            for(j=0;j<num_gamer;j++)
            {
                if(location[j]==i)
                {
                    printf("%c",code[j]);
                }

            }

            printf("\t%s\t%c.%d\t\t\t\t\t\t\t\t%c.%d\t%s\t",Mname[i],code[owner[i]],level[i],code[owner[i+count]],level[i+count],Mname[i+count]);
            for(j=0;j<num_gamer;j++)
            {
                if(location[j]==i+count)
                {
                    printf("%c",code[j]);
                }
            }
            count+=2;
            if(i==6)
            {
                printf("\n\t\t\t\t");
            }
            else
            {
                printf("\n\n");
            }
        }
        else
        {
            for(j=4;j>=1;j--)
            {
                printf("  %c.%d\t\t",code[owner[j]],level[j]);
            }
            printf("\n\t\t");
            for(j=0;j<6;j++)
            {
                printf("%s\t\t",Mname[i-j]);
            }
            printf("\n\t\t");
            for(c=5;c>=0;c--)
            {
                for(j=0;j<num_gamer;j++)
                {
                    if(location[j]==c)
                    {
                        printf("%c",code[j]);
                    }

                }
                printf("\t\t");
            }
            printf("\n\n");
        }

    }
    count=5;
    printf("========================================================================================================================\n\t\t\t\t\t\t\t排行榜\n\n\n");
    printf("\t\t\t代號：\t");
    for(i=0;i<num_gamer;i++)
    {
        printf("\t%c\t",code[i]);
    }
    printf("\n\t\t\t名字：\t");
    for(i=0;i<num_gamer;i++)
    {

        printf("\t%s\t",Pname[i]);
    }
    printf("\n\t\t\t金錢：\t");
    for(i=0;i<num_gamer;i++)
    {

        printf("\t%d\t",money[i]);
    }


}

void move (int name[][7],int level[],int type[],int location[],int people,int money[],int player_name[][50],int i)
{
    int dice1 = rand()%6+1, dice2 = rand()%6+1, total;
    total = dice1+dice2;
    printf("The dice point is %d + %d = %d\n",dice1, dice2, total);
    system("pause");
    location[i]+=total;

    move_display(name,level,type,location,people,money,player_name,total,i);
}

void broke(int player,int level[],int type[])
{
    int i;
    for(i=0;i<=20;i++)
    {
        if(type[i]==player)
        {
            type[i]=4;
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
    printf("Do you want to buy this land $:%d?(y/n):",price[location][0]);
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
    printf("Do you want to upgrade this land $:%d?(y/n):",price[location][level[location]]);
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
    int dice,i,j,choice,flag=0,sum=0;
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
                if(level[choice]==1)
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
            location[player]=0;
            money[player]+=2000;
            printf("直接到達該起點(加2000)\n");
            break;
        case 6:
            for(i=0;i<20;i++)
            {
                if(type[i]<4)
                {
                    flag++;
                }
            }
            if(flag!=16)
            {
                printf("選擇一塊無人地(輸入1~20 起點為1 處理器為20)獲得擁有權:");
                do{
                    scanf("%d",&choice);
                    choice-=1;
                    if(type[choice]<4)
                    {
                        choice=100;
                    }
                    else
                    {
                        type[choice]=player;
                    }
                }while(choice>19||choice<0);
                printf("已獲得\n");
            }
            else if(flag==16)
            {
                money[player]+=5487;
                printf("都有人了幫你QQ，送你5487元\n");
            }
            break;
        case 7:
            printf("選擇一個人和你資產2:3分配(可以為自己):");
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
            if(choice!=player)
            {
                sum=(sum+money[player]+money[choice])/10;
                money[choice]=sum*4;
                money[player]=sum*6;
            }
            printf("已分配\n");
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
            break;
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
            }while(level[dice]==1);
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
            for(i=0;i<allplayer;i++)
            {
                sum+=money[i];
            }
            sum=sum/allplayer;system("pause");
            for(i=0;i<allplayer;i++)
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
    int money[4],out[4],location[4],level[20],stay[4],type[20]/*0~3:有人地,4:無人地6:監獄,8:醫院,5:起點7:機會命運*/;
    int people,i,j,flag=0,price[20][4],tolls[20][4],protection[4],dice;
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
        protection[i]=0;
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
    system("pause");
    while(flag!=people-1)
    {
        for(i=0;i<people;i++)
        {
            display(name,level,type,location,people,money,player_name);
            printf("\n");
            if(money[i]>=0&&out[i]==0)
            {
                printf("turn %c\n",65+i);
                if(stay[i]>0)
                {
                    printf("%c need to stay %d\n",65+i,stay[i]);
                    system("pause");
                    stay[i]-=1;
                }
                else
                {
                    system("pause");
                    move(name,level,type,location,people,money,player_name,i);
                    printf("\nLocation:%d\n",location[i]);

                    if(type[location[i]]==6&&protection[i]==0)
                    {
                        if(protection[i]==0)
                        {
                            prison(i,stay);
                        }
                        else if(protection[i]==1)
                        {
                            protection[i]-=1;
                        }
                    }
                    else if(type[location[i]]==8)
                    {
                        if(protection[i]==0)
                        {
                            hospital(i,money,stay);
                        }
                        else if(protection[i]==1)
                        {
                            protection[i]-=1;
                        }
                    }
                    else if(type[location[i]]==7)
                    {
                        dice=rand()%2;
                        if(dice==1)
                        {
                            fate(i,money,price,type,stay,level,tolls,location,people);
                        }
                        else if(dice==0)
                        {
                            chance(i,money,price,type,stay,level,tolls,location,people,protection);
                        }
                    }
                    else if(type[location[i]]!=i&&type[location[i]]!=4&&type[location[i]]!=5&&type[location[i]]!=6&&type[location[i]]!=7&&type[location[i]]!=8)
                    {
                        toll(i,type,money,level,tolls,location[i]);
                    }
                    else if(type[location[i]]==4)
                    {
                        land(i,money,price,type,level,location[i]);
                    }
                    else if(type[location[i]]==i&&level[location[i]]<=4)
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
            if(money[i]>=0)
            {
                system("pause");
                system("CLS");
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

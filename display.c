#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void display(char Mname[][7],int level[],int owner[],int location[],int num_gamer,int money[],char Pname[][7])
{
    int i,j,count=7,c;
    char code[5]={'L','A','B','C','D'};
    printf("%d",owner[12]);
    printf("\n\t\t");

    for(i=0;i<6;i++)
    {
        for(j=1;j<=num_gamer;j++)
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
            for(j=1;j<=num_gamer;j++)
            {
                if(location[j]==i+1)
                {
                    printf("%c",code[j]);
                }

            }

            printf("\t%s\t%c.%d\t\t\t\t\t\t\t\t%c.%d\t%s\t",Mname[i],code[owner[i]],level[i],code[owner[i+count]],level[i+count],Mname[i+count]);
            for(j=1;j<=num_gamer;j++)
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
            for(c=6;c>=0;c--)
            {
                for(j=1;j<=num_gamer;j++)
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
        printf("\t   %c\t",code[i]);
    }
    printf("\n\t\t\t名字：\t");
    for(i=0;i<num_gamer;i++)
    {
        printf("\t%s\t",Pname[i]);
    }
    printf("\n\t\t\t金錢：\t");
    for(i=0;i<num_gamer;i++)
    {
        printf("\t%6d\t",money[i]);
    }


}

int main(void){
	int i,j;
	FILE *file=fopen("map.txt","r");
	//Map's data
	char Mname[20][7];
	int price[20][4], tolls[20][4], type[20], level[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, owner[20]={4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4},num_gamer=4;
	//Player's data
	char Pname[4][7]={"李建興","李香蘭","林品侑","柯博瀚"};
	int stay[4], location[4]={13,17,8,9},money[4]={1000,2000,3000,4000};
    //reader


	for(i = 0; !feof(file); i++){
		fscanf(file,"%s",Mname[i]);
		for(j = 0; j < 4; j++)  fscanf(file,"%d",&price[i][j]);
		for(j = 0; j < 4; j++)  fscanf(file,"%d",&tolls[i][j]);
        if(i % 5 == 0){ type[i] = i / 5;    level[i] = -1;  owner[i] = -1;  }
        else{   type[i] = 0;    level[i] = 0;   owner[i] = 0;   }
	}
    display(Mname,level,owner,location,num_gamer,money,Pname);
	for(i = 0; i < 4; i++){ stay[i] = 0;    location[i] = 0;    }
	/* Display
	for(i = 0; i < 20; i++){
		printf("%s\t%d\t%d\t%d\n\t",Mname[i], type[i], level[i], owner[i]);
		for(j = 0; j < 4; j++)  printf("%d\t",price[i][j]);
		for(j = 0; j < 4; j++)  printf("%d\t",tolls[i][j]);
		printf("\n\n");
	}
	for(i = 0; i < 4; i++){
        printf("%s\t%d\t%d\n", Pname[i], stay[i], location[i]);
	}*/

	fclose(file);
	return 0;
}

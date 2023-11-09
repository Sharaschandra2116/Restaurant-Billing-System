#include <stdio.h>
#include <string.h>
#include<stdlib.h>

int token = 0,tokens[50];
int arID[10],arqty[10],counter=0;
void Bill_Payment();
void menu_order();
void bill();
int main(){
    int choice;
    do{
    	system("cls");
    	 printf("\n\t                    WELCOME TO RESTAURANT OKRA \n\n");
         printf("\n\t               (^_^).GOOD FOOD.GOOO MOOD. (^_^)\n\n   ");
         printf("\n");
         printf("                                             \n");
         printf("            Select any of them -\n");
         printf("                                             \n");
         printf("                         1. New Order.       \n");
         printf("                                             \n");
         printf("                         2. Bill pay         \n");
    	 printf("                                             \n");
    	 printf("                         3. Exit.              ");
    	 printf("\n\n");
    	 printf("                         GRAB NOW !!!     ");
    	 printf("\n\n                 Enter Your Choice: ");
    	 scanf("%d",&choice);
    	switch(choice){
    		case 1:
    			menu_order();
    			break;
    		case 2:
    			Bill_Payment();
    			break;
    		case 3:
    			printf("Exit");
    			break;
    		default :
    			printf("Enter number from 1-3");
		}
	}while(choice!=3);
}
void menu_order()
{
    system("cls");
    printf("\n\tFOOD MENU\n\t");
    printf("\n\t...SNACKS... :\n\n");
    printf("\t1. chicken Burger .......................120/=\t  \n");
    printf("\t2. pizza(4pcs) .........................240/=\n");
    printf("\t3. Donuts ............................ 50/=\t \n");
    printf("\t4. French Fries (FnF Pack) .......... 90/=\t \n");
    printf("\n\t..CHICKEN... :\n\n");
    printf("\t5. Chicken lollypop(4pcs).............. 150/=\n");
    printf("\t6. Chicken Wings (3pcs)..............  100/=\n");
    printf("\n\t...DESSERTS... :\n\t \n");
    printf("\t7. Ice Cream ..........................  40/=\t  \n");
    printf("\t8. pastries ........................... 50/=\t \n");
    printf("\n\t...DRINKS... :\n\n");
    printf("\t9.  fizz..................... 25/=\n");
    printf("\t10. sprite   ............... 25/=\n");
    printf("\n\n\tOrder your dish: (Enter 0 to finish order)\n");
    while(1){
        counter++;
        printf("\t Enter Food ID: ");
        scanf("%d",&arID[counter-1]);
        if(arID[counter-1]==0){
        	break;
		}
        printf("\t Enter Quantity: ");
        scanf("%d",&arqty[counter-1]);
    }
    printf("\n\n");
    counter--;
    bill();
}
void bill()
{
    int n,i,sum=0;
    FILE *file;
    file = fopen("D:\\billing.txt","a");
    system("cls");
    int costs[10]={120,240,50,90,150,100,40,50,25,25};
    char items[10][16]={"chicken burger","pizza","donuts","french fries","chicken", "wings" ,"ice cream","pastries","fizz","sprite"};
    printf("\n\t Your token number: %d",token+1);
    fprintf(file,"\n Token number: %d \n",token +1);
    printf("\n\n Your Bill:  \n\t Item(s)\t\t      Quantity \t\t    Cost \n\n");
    fprintf(file,"\n\n Your Bill:  \n\t Item(s)\t\t      Quantity \t\t    Cost \n\n");

    for(i=0;i<counter;i++)
   {
        printf("\t%d. %s ________\t%d piece(s) ____ \t%d\n",i+1,items[arID[i]-1],arqty[i],arqty[i]*costs[arID[i]-1]);
        fprintf(file,"\t%d. %s ________\t%d piece(s) ____ \t%d\n",i+1,items[arID[i]-1],arqty[i],arqty[i]*costs[arID[i]-1]);
	    sum=sum+(costs[arID[i]-1]*arqty[i]);
    }

    printf("\n\t  Total = %d\n",sum);
    fprintf(file,"Total =%d\n",sum);
    token ++;
    counter=0;
    tokens[token]=sum;
    fclose(file);
    printf("Enter 1 to go to main");
    scanf("%d",&n);
    if(n=1){
    	return;
	}
}

void Bill_Payment()
{

    int i,n;
    system("cls");
    printf("\n\tEnter your token number: ");
    scanf("%d",&i);
    printf("\t\t\tYour Total Bill is = %d\n",tokens[i]);
    printf("Enter 1 to go to main");
    scanf("%d",&n);
    if(n=1){
    	return;
	}
}

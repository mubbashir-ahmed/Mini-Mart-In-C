#include<stdio.h>
#include<string.h>
void itemListFunction();
void billCheck(char pro[], int paisa);
char* product[20] = {
						"Coca Cola 500ML", "Coca Cola 1.5LTR", "Coca Cola 2.25LTR",
						"Pepsi 500ML", "Pepsi 1.5LTR", "Pepsi 2.25LTR",
						"7UP 500ML", "7UP 1.5LTR", "7UP 2.25LTR",
						"Sprite 500ML", "Sprite 1.5LTR", "Sprite 2.25LTR",
						"Marinda 500ML", "Marinda 1.5LTR", "Marinda 2.25LTR",
						"Fanta 500ML", "Fanta 1.5LTR", "Fanta 2.25LTR",
						"Aquafina Water 500ML", "Aquafina Water 1.5LTR"
					};
						
int prices[20] = 	{60,100,140,60,100,140,60,100,140,60,100,140,60,100,140,60,100,140,30,50};

int product_qnty, product_num, total;
float final_total, discount;

int main()
{
	int op = 0;
	printf("\t\t\t\t\tWELCOME TO MUBBASHIR BEVERAGES MINI MART");
	printf("\n\t\t\t\t\t========================================");
	printf("\n==>1. Item List\n==>2. Exit");
	printf("\nKindly Choose from the givien Options: ");
	scanf("%d", &op);
	if(op == 1 || op == 2)
	{
		switch(op)
		{
			case 1:
				system("cls");
				itemListFunction();
				break;
			case 2:
				system("cls");
				printf("Thank You for Shopping! Have a Great Day! Allah Hafiz");
				exit(0);
				break;
		}
	}
	else
	{
		system("cls");
		main();
	}
}

void itemListFunction()
{	
	int x;
	char pro[50];
	printf("\t\t\t\t\t\tITEMS LIST");
	printf("\n\t\t\t\t\t\t==========");
	printf("\nITEMS:\t\t\t\tPRICES:");
	for(x=0;x<20;x++)
	{
		printf("\n%d %s\t\t%d", x+1, product[x], prices[x]);
	}
	
	printf("\n\n==>Enter the Product Number that you want to buy: ");
	scanf("%d", &product_num);
	for(x=0;x<20;x++)
	{	
		if(product_num == x+1)
		{
			char choice;
			printf("==>Enter Quantity: ");
			scanf("%d", &product_qnty);
			total = prices[x] * product_qnty;
			strcpy(pro, product[x]);
			billCheck(pro,prices[x]);
		}
	}
}

void billCheck(char pro[],int paisa)
{
	int x;
	char returnTOMenu_char;
	printf("\t\t\t\t\t\tBILL CHECK");
	printf("\n\t\t\t\t\t\t==========");
	printf("\n==>PRODUCT ID: %d", product_num);
	
	printf("\n==>PRODUCT NAME: %s", pro);
	printf("\n==>PRODUCT PRICE: %d", paisa);

	printf("\n==>QUANTITY: %d", product_qnty);
	printf("\n==>TOTAL: %d", total);
	if(product_qnty > 5)
	{
		final_total = (total * 10) / 100;
		printf("\n==>DISCOUNT OF: 10%%");
		printf("\n==>TOTAL AFTER DISCOUNT: %0.1f", final_total);
	}
	
	printf("\n\n==>Enter \'R\' to Pay and Return to Main Menu OR 'ENTER' to Don't Pay and Leave: ");
	returnTOMenu_char = getche();
	if(returnTOMenu_char == 'R' || returnTOMenu_char == 'r')
	{
		system("cls");
		main();
	}
}

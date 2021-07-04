#include <stdio.h>
#include<stdlib.h>
#include<conio.h>

struct 
{
	long id;
	char name[60];
	float price;
	int quantity;
	char date[10];
	int expiresIn;
	char producer[60];
	char taxNumber[11];
}typedef Item;

void drawMenu();
Item addNewItem();

void main() {
	
	drawMenu();	
}


void drawMenu(){
	

	#define OPTIONSCOUNT (6)
	char options[OPTIONSCOUNT][20] = {"Add new Item","Take items","See Expired Items","See Producers","See Item details", "See all items"};
	int selected = 0;
	char input;
	while (1)
	{
		printf("\n");
		printf("|========================================|\n");
		printf("|                                        |\n");
		printf("|         Skladovo Stopanstvo - Menu     |\n");
		printf("|                                        |\n");
		printf("|========================================|\n");
		printf("\n");
		for (int i = 0; i < OPTIONSCOUNT; i++)
		{
			if (i == selected) {
				printf("> %s\n", options[i]);
			}
			else {
				printf("%s\n", options[i]);
			}

		}
		printf("\n");
		input = _getch();
		//Enter is 13
		if (input == 13) {
			system("cls");
			switch (selected) {
			case 0: addNewItem();
			case 1: printf("TAKE AN ITEM");
			
			default:
				break;
			}
			selected = 0;
		}


		if (input == -32) {
			input = _getch();

			switch (input)
			{
			case 72: selected--; break;
			case 80: selected++; break;
			default:
				break;
			}
			if (selected > OPTIONSCOUNT-1) {
				selected = 0;
			}
			if (selected < 0) {
				selected = OPTIONSCOUNT-1;
			}
		}

		system("cls");
	}
}


Item addNewItem() {

	Item item;
	printf("ADDDING A NEW ITEM: ");
	printf("Enter Item name: ");
	scanf_s("%s", item.name, 60);
	item.id = 00000001;
	printf("Enter Item price: ");
	scanf_s("%f", &item.price);
	printf("Enter Item quantity: ");
	scanf_s("%d", &item.quantity);
	printf("Enter Item date(DD.MM.YYYY): ");
	scanf_s("%s", &item.date, 10);
	printf("Enter Item expiresIn: ");
	scanf_s("%d", &item.expiresIn);

	printf("Enter Item producer: ");
	scanf_s("%s", item.producer, 60);

	printf("Enter Item taxNumber: ");
	scanf_s("%s", item.taxNumber, 11);

	FILE* fpt;
	char fileText[100];



	fopen_s(&fpt, "ProductsDb.csv", "r");
	fgets(fileText, 100, fpt);
	fclose(fpt);
	if (strcmp(fileText, "Name, Quantity, Price, Date, ExpiresIn, Producer, TaxNumber\n")) {
		fopen_s(&fpt, "ProductsDb.csv", "w+");

		fprintf(fpt, "Name, Quantity, Price, Date, ExpiresIn, Producer, TaxNumber\n");
		fclose(fpt);
	}
	fopen_s(&fpt, "ProductsDb.csv", "a");

	fprintf(fpt, "%s, %d, %f, %s, %d, %s, %s\n", item.name, item.quantity,
		item.price, item.date, item.expiresIn, item.producer, item.taxNumber);


	fclose(fpt);

	printf("Item %s created with price: %f, quantity = %d, ", item.name, item.price, item.quantity);
	printf("date: %s expires in: %d, from producer: %s, tax number: %s", item.date, item.expiresIn, item.producer, item.taxNumber);

}

void changeQuantity(char *name[60]) {


}
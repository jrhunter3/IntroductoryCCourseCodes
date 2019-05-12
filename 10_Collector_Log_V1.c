/*********************************************
 * Joseph R. Hunter - CS 239 - Assignment 10 *
 ********************************************/
#include <stdio.h>
#include <string.h>

struct game{
	int list_number;
	char name[24];
	float used_value;
	float new_value;
};
typedef struct game Game;

void print_header(void);
char get_menu(void);
void enter_data(void);
void display(Game item);
Game create(float used_value, float new_value, char *str);

int game_count = 0;
Game bin[10];

main(void){

	char menu;
	int i, quit = 0;

	print_header();

	bin[game_count++] = create(19.40, 341.00, "Legend of Zelda");
	bin[game_count++] = create(6.49, 310.00, "Super Mario Bros.");
	bin[game_count++] = create(4.75, 52.50, "Sonic The Hedgehog");
	bin[game_count++] = create(77.75, 2150.00, "Chrono Trigger");

	while ( quit == 0 ){
		menu = get_menu();
		switch (menu){
			case 'a':
			case 'A':
				puts("GameLog v. 1.0 was produced and released in 2014 by Joseph R. Hunter");
				break;
			case 'c':
			case 'C':
				enter_data();
				break;
			case 'd':
			case 'D':
				puts("List Number\tName\t\t\tUsed Value\tNew Value");
				for (i = 0; i < game_count; i++){
					display(bin[i]);
				}	//End of For Loop
				break;
			case 's':
			case 'S':
				print_header();
				break;
			case 'q':
			case 'Q':
				quit = 1;
				puts("Quitting...");
				usleep(1000000);
				puts("Thank you for using GameLog v. 1.0!");
				break;
		}	//End of Switch
	}	//End of While
}	//End of Main

void print_header(void){

	puts("/********************************************");
	puts("* Joseph R. Hunter - CS 239 - Assignment 10 *");
	puts("********************************************/\n");

	puts("|-------------------------------------------|");
	puts("|---------------Game Log v 1.0--------------|");
	puts("|-------------------------------------------|");
	puts(" [A]bout\t\t[Q]uit");
	puts(" [S]how Menu\t\t[D]isplay Parts");
	puts(" [C]reate Entry");
	puts("|-------------------------------------------|");
	puts("|        Thank you for using GameLog        |");
	puts("|-------------------------------------------|");
}	//End of Function

char get_menu(void){

	char line[10];

	puts("Enter your choice: ");
	fgets(line, sizeof(line), stdin);

	return line[0];
}	//End of Function

void enter_data(void){

	char uline[10];
	char nline[10];
	char name[24];
	float used_value, new_value;

	puts("Enter the used value of the game: ");
	fgets(uline, sizeof(uline), stdin);
	sscanf(uline, "%f", &used_value);
	puts("Enter the new value of the game: ");
	fgets(nline, sizeof(nline), stdin);
	sscanf(nline, "%f", &new_value);
	puts("Enter the name of the game: ");
	fgets(name, sizeof(name), stdin);
	sscanf(name, "%[^\n]", name);
	
	bin[game_count++] = create(used_value, new_value, name);
}

Game create(float used_value, float new_value, char *str){

	static int ln = 100;
	ln++;
	Game item;
	item.list_number = ln;
	item.used_value = used_value;
	item.new_value = new_value;
	strcpy(item.name, str);
	return item;
}

void display(Game item){
	printf("%d\t\t%-24s$%-5.2f\t\t$%-5.2f\n", item.list_number, item.name, item.used_value, item.new_value);
}

/*********************************************
 * Joseph R. Hunter - CS 239 - Assignment 10 *
 ********************************************/
#include <stdio.h>
#include <string.h>
#define FILENAME "./game_log.txt"

struct game{
	int list_number;
	char name[24];
	float used_value;
	float new_value;
};
typedef struct game Game;

void splash_screen(void);
void print_header(void);
char get_menu(void);
void enter_data(void);
void display(Game item);
Game create(float used_value, float new_value, char *str);
int game_count;
Game bin[10];
static int ln;

FILE *log_read, *log_append;
int fclose(FILE *log_read);
int fclose(FILE *log_append);
char buffer[1000];

int main(void){
	system("clear");
	splash_screen();
	usleep(1500000);

	char menu, name[24];
	int i, quit = 0;
	Game item;

	print_header();

		while (quit == 0){
		menu = get_menu();
/***********************************************
* Joseph R. Hunter - CS 239 - Final Assignment *
***********************************************/
/***********************************************
* Joseph R. Hunter - CS 239 - Final Assignment *
***********************************************/

		switch (menu){

			case 'a':
			case 'A':
				puts("GameLog v. 1.0 was produced and released in 2014 by Joseph R. Hunter");
				break;

			case 'c':
			case 'C':
				log_append = fopen(FILENAME, "a");
				if (!log_append){
					puts("Could not open file for writing");
					return 1;
				}	//End If Statement
				enter_data();
				fclose(log_append);
				break;

			case 'd':
			case 'D':
				log_read = fopen(FILENAME, "r");
				if (!log_read){
					puts("Could not open file for reading");
				}	//End If Statement
				game_count = 0;
				ln = 0;
				puts("List Number\tName\t\t\tUsed Value\tNew Value");
				while (fgets(buffer, sizeof(buffer), log_read) != NULL){
					strcpy (item.name, buffer);
					item.name[strlen(item.name)-1] = '\0';
					fgets(buffer, sizeof(buffer), log_read);
					sscanf(buffer, "%f %f", &item.used_value, &item.new_value);
					bin[game_count++] = create(item.used_value, item.new_value, item.name);
//					printf("%-20s\t$%.2f\t\t$%.2f\n", item.name, item.used_value, item.new_value);
				}	//End While Statement
				for (i = 0; i < game_count; i++){
					display(bin[i]);
				}	//End of For Loop

				fclose(log_read);
				break;

			case 's':
			case 'S':
				print_header();
				break;

			case 'q':
			case 'Q':
				system("clear");
				puts("Quitting...");
				usleep(1000000);
				puts("Thank you for using GameLog v. 1.0!");
				return 0;

		}	//End of Switch
	}	//End of While
}	//End of Main

void splash_screen(void){

	puts("GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG");usleep(150000);
	puts("GGGGGGGGGGGGGGGGGGG       GGGGGGGGG     GGGGGGGG   GGGGGGGGGG   GGG         GGG   GGGGGGGGGGGGGG        GGGGGGGGGG       GGGGGGGGGGGGGGGGGGGGGGGGG");usleep(150000);
	puts("GGGGGGGGGGGGGGGGG    GGG   GGGGGG   GGG   GGGGGG     GGGGGG     GGG   GGGGGGGGG   GGGGGGGGGGGGG   GGGG   GGGGGGG    GGG   GGGGGGGGGGGGGGGGGGGGGGGG");usleep(150000);
	puts("GGGGGGGGGGGGGGGG    GGGG   GGGGG   GGGGG   GGGGG   G   GG   G   GGG   GGGGGGGGG   GGGGGGGGGGGG   GGGGGG   GGGGG    GGGG   GGGGGGGGGGGGGGGGGGGGGGGG");usleep(150000);
	puts("GGGGGGGGGGGGGGG    GGGGGGGGGGGG   GGGGGGG   GGGG   GG     GGG   GGG   GGGGGGGGG   GGGGGGGGGGG   GGGGGGGG   GGG    GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG");usleep(150000);
	puts("GGGGGGGGGGGGGGG    GGGGGGGGGGG   GGGGGGGGG   GGG   GGG   GGGG   GGG      GGGGGG   GGGGGGGGGGG   GGGGGGGG   GGG    GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG");usleep(150000);
	puts("GGGGGGGGGGGGGGG    GG      GGG               GGG   GGGGGGGGGG   GGG   GGGGGGGGG   GGGGGGGGGGG   GGGGGGGG   GGG    GG      GGGGGGGGGGGGGGGGGGGGGGGG");usleep(150000);
	puts("GGGGGGGGGGGGGGG    GGGGG   GGG   GGGGGGGGG   GGG   GGGGGGGGGG   GGG   GGGGGGGGG   GGGGGGGGGGGG   GGGGGG   GGGG    GGGGG   GGGGGGGGGGGGGGGGGGGGGGGG");usleep(150000);
	puts("GGGGGGGGGGGGGGGG    GGGG   GGG   GGGGGGGGG   GGG   GGGGGGGGGG   GGG   GGGGGGGGG   GGGGGGGGGGGGG   GGGG   GGGGGG    GGGG   GGGGGGGGGGGGGGGGGGGGGGGG");usleep(150000);
	puts("GGGGGGGGGGGGGGGGGG        GGGG   GGGGGGGGG   GGG   GGGGGGGGGG   GGG         GGG           GGGGGGG      GGGGGGGGG         GGGGGGGGGGGGGGGGGGGGGGGGG");usleep(150000);
	puts("GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG");usleep(150000);
	puts("GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG");usleep(150000);
	puts("GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG____________________________________________________GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG");usleep(150000);
	puts("GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG| GameLog version 1.0 is a product of NextGen Inc. |GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG");usleep(150000);
	puts("GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG|    Coded by Joseph R. Hunter in November 2014    |GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG");usleep(150000);
	puts("GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG____________________________________________________GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG");usleep(150000);
	puts("GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG|    GameLog uses a text-based file in order to    |GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG");usleep(150000);
	puts("GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG|   track and record the used and new collector's  |GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG");usleep(150000);
	puts("GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG|   value for games.  Entries may be displayed or  |GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG");usleep(150000);
	puts("GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG|     created through the user-friendly menu.      |GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG");usleep(150000);
	puts("GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG____________________________________________________GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG");usleep(150000);
	puts("GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG| Required filepath: ./game_log.txt                |GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG");usleep(150000);
	puts("GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG___________________________________________________|GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG");usleep(150000);
	puts("GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG");usleep(150000);
}	//End of Function

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
t

	char uline[10];
	char nline[10];
	char name[24];
	float used_value, new_value;
	memset(uline, 0, sizeof(uline));
	memset(nline, 0, sizeof(nline));
	memset(name, 0, sizeof(name));

	puts("Enter the name of the game: ");
	fgets(name, sizeof(name), stdin);
	sscanf(name, "%[^\n]", name);
	fprintf(log_append, "%s", name);

	puts("Enter the used value of the game: ");
	fgets(uline, sizeof(uline), stdin);
	sscanf(uline, "%f", &used_value);
	puts("Enter the new value of the game: ");
	fgets(nline, sizeof(nline), stdin);
	sscanf(nline, "%f", &new_value);
	fprintf(log_append, "%.2f %.2f", used_value, new_value);
	
//	bin[game_count++] = create(used_value, new_value, name);
}

Game create(float used_value, float new_value, char *str){

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

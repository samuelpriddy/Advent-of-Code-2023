#include <stdio.h>
#include <stdlib.h>

#define EOL "\n"
#define RED_COUNT 12
#define GREEN_COUNT 13
#define BLUE_CUBES 14

void append(char* s, char c){
	int len = strlen(s);
	s[len] = c;
	s[len+1] = '\0';
}

int main(){
	FILE* fp;
	char line[60];
	int id_sum = 0;
	char id[4];
	char count[3];
	char color[10];

	fp = fopen("input", "r");

	if(fp == NULL){
		printf("No File Found\n");
		return -1;
	}

	while(fgets(line, 60, fp)){
		int ptr = 5;
		
		while(line[ptr] != ":")
			append(id, line[ptr]);

               	ptr+=2;

		while(line[ptr] != EOL){
			while(line[ptr] != " ")
				append(count, line[ptr]);		
			ptr++;
			while(line[ptr] != "," && line[ptr] != ";")
				append(color, line[ptr]);
			ptr+=2;	
		}
	}
}

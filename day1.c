#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define EOL '\n'

int main(){
	FILE* fp;
	char line[100];
	int cal_value = 0;

	fp = fopen("input", "r");

	if(fp == NULL){
		printf("No File Found\n");
		return 1;
	}

	while(fgets(line, sizeof(line), fp)){
		int p1 = 0;
		int p2 = sizeof(line);
		
		while(!(isdigit(line[p1]) && isdigit(line[p2]))){
			if(!isdigit(line[p1]))
				p1++;
			if(!isdigit(line[p2]))
				p2--;
		}
			
		cal_value += (line[p1]-'0')*10 + (line[p2]-'0');
		printf("Num1: %d, Num2: %d\n", (line[p1]-'0'),  (line[p2]-'0'));
		memset(line, 0, sizeof(line));
	}

	fclose(fp);
	printf("Calibration Value: %d\n", cal_value);
	return 0;
}

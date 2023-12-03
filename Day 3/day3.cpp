#include <iostream>
#include <fstream>
#include <ctype.h>
#include <string>

using namespace std;

int ispunct(int c){
	return c != '.' && !isdigit(c);
}

int get_num(int i, int* j, char input[140][140]){
	string num = "";
	while(*j < 140 && isdigit(input[i][*j])){
		num += input[i][*j];
		*j += 1;
	}
	return stoi(num);
}

int check_adj_sym(int i, int j, char input[140][140]){
	int end_idx = j;
	int k;
	while(end_idx < 140 && isdigit(input[i][end_idx]))
			end_idx++;

	//Check Row Above
	if(i > 0){
		k = (j > 0) ? j - 1 : 0;
		
		while(k < 140 && k <= end_idx){
			if(ispunct(input[i-1][k]))
				return 1;
			k++;
		}
	}
	//Check Left and Right
	if(j > 0 && ispunct(input[i][j-1]))
		return 1;
	if(j < 139 && ispunct(input[i][end_idx]))
		return 1;
	//Check Row Below
	if(i < 139){
                k = (j > 0) ? j - 1 : j;
                
                while(k < 140 && k <= end_idx){
                        if(ispunct(input[i+1][k]))
                                return 1;
                        k++;
                }
        }
	return 0;

}

int main(){
	ifstream file("input");
	char input[140][140];
	int sum = 0;
	
	// Store input text into input array
	if(file.is_open()){
		for(int i=0; i<140; i++){
			for(int j=0; j<140; j++){
				input[i][j] = file.get();
			}
			file.get();
		}
	}

	// Add part numbers adjacent to a symbol
	for(int i=0; i<140; i++){
                        for(int j=0; j<140; j++){
				// Find numbers
                                if(isdigit(input[i][j])){
					// Check if adjacent symbol
					if(check_adj_sym(i, j, input)){
						if(i==1 && j==0)
							cout << "PASS TEST" << "\n";
						int num = get_num(i, &j, input);
						sum += num;
						cout << num << "\n";
					}
				}
                        }
                }
	cout << "Sum of Part Numbers with Adjacent Symbols: " << sum << "\n";
	return 0;
}

#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

int main(){
	ifstream file("input");

	if(file.is_open()){
		string line;
		string lineSeg;
		int id;

		while(file){
			getline(file, line);	
			stringstream ss(line);
			getline(ss, lineSeg, ':');

			//GET GAME ID

		}
	}
	return 0;
}

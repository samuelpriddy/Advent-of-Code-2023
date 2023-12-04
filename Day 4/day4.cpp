#include <iostream>
#include <fstream>
#include <unordered_set>
#include <bits/stdc++.h>

using namespace std;

int main(){
	ifstream file("input");
	string line;
	int score = 0;

	if(file.is_open()){
		while(file){
			int pos;
			unordered_set<int> winning_nums;
			int winning_nums_set = 0;
			string s;
			int line_score = 0;

			getline(file, line);
			pos = line.find(":") + 2;
			if(line.empty()) continue;
			stringstream ss(line.substr(pos));
			
			while(getline(ss, s, ' ')){
				//Past winning numbers flag
				if(s == "|"){
				       	winning_nums_set = 1;
					cout << "Winning Nums Set\n";
					continue;
				}

				//Cleanup white spaces
				if(s.find_first_not_of(' ') == string::npos) continue;

				//Checking my nums for winning nums
				if(winning_nums_set){
					if(winning_nums.count(stoi(s))){
						line_score = (line_score<=0) ? 1 : line_score*=2;
						cout << "WIN\n";
					}
				}
				//Adding to winning nums
				else{
					winning_nums.insert(stoi(s));
				}
				cout << stoi(s) << "\n";
			}	
			//Add to Total Score
			score += line_score;
		}
		cout << "Score: " << score << "\n";
	}
}

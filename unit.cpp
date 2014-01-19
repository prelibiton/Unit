#include <iostream>
#include <queue>
#include <fstream>
#include <string>

using namespace std;

struct Unit2{

    string name;
    int budget;
};

class Unit{

	string name;
	int id;
	int budget;
	queue<Unit*> q;

public:

	Unit(){
		name = "";
		id = 0;
		budget = 0;
	}

	Unit(string n,int bd){
		name = n;
		budget = bd;
	}
 
bool addSubBudget(Unit* unit){
	int temp = q.size();              
	q.push(unit);
	if(temp == q.size()) return false;
	budget = budget + (*q.back()).getBudget();
	return true;
}

string getName(){
	return name;
}

int getBudget(){
	return budget;
}

};

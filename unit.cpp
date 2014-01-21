#include <iostream>
#include <queue>
#include <fstream>
#include <string>

using namespace std;

class Unit{

	char name[100];
	int id;
	int budget;
	queue<Unit*> q;

public:

	Unit(char* n,int i,int bd){
		strcpy_s(name,n);
		id = i;
		budget = bd;
	}
 
bool addSubUnit(Unit* unit){
	int temp = q.size();              
	q.push(unit);
	if(temp + 1 == q.size()) return true;   //is unit added?

	return false;
}

char* getName() const{
    char* n=new char[strlen(name)+1];
    int i;
    for( i=0;name[i]!='\0';i++)
         n[i]=name[i];
         n[i] = '\0';
           return n;
}

int getBudget(){
	int bd = 0;
	if(q.empty()) {
		bd = budget;
		return bd;}
	else {
		while(!q.empty()){
			bd += (*q.front()).budget;
			q.pop();
		}
	}
		return bd + this->budget;
}
	
	


};


void writeBudgets(Unit unit,int i){
	ofstream file("budgets.bin",ios::out|ios::binary);
	char* n = unit.getName();
	int bd = unit.getBudget();
	
	file.seekp( (i-1) * (sizeof(100)+sizeof(bd)),ios::beg );
    	file.write( reinterpret_cast<char*>(&n), sizeof(n) );
	file.write( reinterpret_cast<char*>(&bd), sizeof(bd) );
	file.close();
}

void readBudgets(int i){
    int bd2;
    char* n2;
    ifstream file2("budgets.bin", ios::in);
    file2.seekg( (i-1) * (sizeof(100)+sizeof(bd2)),ios::beg );
    file2.read( reinterpret_cast<char*>(&n2), sizeof(n2) );
    file2.read( reinterpret_cast<char*>(&bd2), sizeof(bd2) );
    file2.close();

	cout<<n2<<" "<<bd2<<endl;
}

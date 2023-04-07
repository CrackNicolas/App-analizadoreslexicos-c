#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdio.h>
using namespace std;

#define counts_states 4  //Macro

int matriz[4][4] = {
//   E N L P 
	{0,1,2,7}, //state 0
	{5,1,7,3}, //state 1 
	{6,7,2,7}, //state 2
	{4,3,7,7}  //state 3
};
int states_ends[] = {4,5,6,7};

int transform_entrance(char chain);
int verify_ends(int state);
void print_output(int character, int state);

int main(){
	int state = 0;
	char chain[100];

	cout<<endl<<" Digite una secuencia: ";
	gets(chain);
	
	cout<<endl<<" Detalles del analisis";
	cout<<endl<<"------------------------------------------";
	for(int character = 0 ; character < strlen(chain) ; character++){
		state = matriz[state][transform_entrance(chain[character])];
		print_output(character,state);
		if(verify_ends(state)){
			state = 0;
		}
	}
	cout<<endl<<"------------------------------------------";
	getch();
}
int transform_entrance(char chain){	
	return  (isdigit(chain)? 1:
			((isupper(chain) || islower(chain))? 2:
			(chain == '.' || chain == '-')? 3:
			(chain == ' ')? 0:7));
}
int verify_ends(int state){
	for(int i = 0 ; i < counts_states ; i++){
		if(state == states_ends[i]){
			return 1;
		}
	}
	return 0;
}
void print_output(int character, int state){
	switch(state){
		case 4:
			cout<<endl<<" Caracter numero "<<character<<" es un numero decimal";
		break;
		case 5:
			cout<<endl<<" Caracter numero "<<character<<" es un numero entero";
		break;
		case 6:
			cout<<endl<<" Caracter numero "<<character<<" es una letra";
		break;
		case 7:
			cout<<endl<<" Caracter numero "<<character<<" error";
		break;
	}
}

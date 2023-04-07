#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

#define max 400

FILE*arch, *fin;

void Operadores(FILE*,FILE*);
void Parentesis(FILE*,FILE*);
void Numero_entero(FILE*,FILE*);
void Numero_real(FILE*,FILE*);
int Cantidad_lineas(FILE*);
void Caracteres_especiales(FILE*);
void Palabras_reservadas(FILE*);
void Error_lexico(FILE*,FILE*);

struct Datos{
	char cadena[max];
}dat;

struct Analizador{
	char Titulo[18]={32,'T','o','k','e','n','-','T','y','p','e',32,'L','e','x','e','m','a'},Parent[max],Operad[max],Real[max],Enteros[max],Error_lexico[max];
}lex;

int i=0,lin=0,linn=0;

int main(){
	cout<<endl<<"  ___________________________________________________________________________";
	cout<<endl<<"  ESTE SISTEMA REALIZA EL ANALISIS LEXICO DEL ARCHIVO ExpresionesAlgebraicas";
	cout<<endl<<"     Y LO ANALIZA Y GUARDA LOS RESULTADOS EN EL ARCHIVO AnalizadorLexico";
	cout<<endl<<"  ---------------------------------------------------------------------------";
	cout<<endl<<endl<<"  Para usar el analizador lexico ->> Presione una tecla...";
	getch();
	system("cls");
	cout<<endl<<" -------------------";
	cout<<endl<<" |ANALIZADOR LEXICO|";
	cout<<endl<<" -------------------";
	cout<<endl<<" ---------------------------------------------------------------------------------------------------------------";
	fin=fopen("AnalizadorLexico.dat","w");
	Parentesis(arch,fin);
	Operadores(arch,fin);
	Numero_entero(arch,fin);
	Numero_real(arch,fin);
	fclose(arch);
	cout<<endl<<endl<<"  - Otros simbolos encontrados  ";
	Caracteres_especiales(arch);
	if(Cantidad_lineas(arch)>0){
		Palabras_reservadas(arch);
	}else{
		cout<<endl<<endl<<"  - Palabras Reservadas: Sin resultados";
	}
	Error_lexico(arch,fin);
	getch();
}
void Caracteres_especiales(FILE*arch){
	char carac[100];
	int o=0,q1=0,q2=0,q3=0,q4=0,q5=0,q6=0,q7=0,q8=0,q9=0,q10=0,q11=0,q12=0,q13=0;
	rewind(arch);
	arch = fopen("ExpresionesAlgebraicas.dat","r+b");
	fread(&dat,sizeof(Datos),1,arch);
	while(!feof(arch)){
		for(int i=0;i<strlen(dat.cadena);i++){
			if((q1==0)&&(dat.cadena[i]==34)){
				carac[o] = dat.cadena[i];
				o++;
				q1=1;
			}
			if((q2==0)&&(dat.cadena[i]==35)){
				carac[o] = dat.cadena[i];
				o++;
				q2=1;
			}
			if((q3==0)&&(dat.cadena[i]==38)){
				carac[o] = dat.cadena[i];
				o++;
				q3=1;
			}
			if((q4==0)&&(dat.cadena[i]==37)){
				carac[o] = dat.cadena[i];
				o++;
				q4=1;
			}
			if((q5==0)&&(dat.cadena[i]==59)){
				carac[o] = dat.cadena[i];
				o++;
				q5=1;
			}
			if((q6==0)&&(dat.cadena[i]==61)){
				carac[o] = dat.cadena[i];
				o++;
				q6=1;
			}
			if((q7==0)&&(dat.cadena[i]==60)){
				carac[o] = dat.cadena[i];
				o++;
				q7=1;
			}
			if((q8==0)&&(dat.cadena[i]==62)){
				carac[o] = dat.cadena[i];
				o++;
			    q8=1;
			}
			if((q9==0)&&(dat.cadena[i]==123)){
				carac[o] = dat.cadena[i];
				o++;
				q9=1;
			}
			if((q10==0)&&(dat.cadena[i]==125)){
				carac[o] = dat.cadena[i];
				o++;
			    q10=1;
			}
			if((q11==0)&&(dat.cadena[i]==91)){
				carac[o] = dat.cadena[i];
				o++;
			    q11=1;
			}
			if((q12==0)&&(dat.cadena[i]==93)){
				carac[o] = dat.cadena[i];
				o++;
			    q12=1;
			}
			if((q13==0)&&(dat.cadena[i]==124)){
				carac[o] = dat.cadena[i];
				o++;
			    q13=1;
			}
		}
		fread(&dat,sizeof(Datos),1,arch);
	}
	fclose(arch);
	if(o>0){
		for(int h=0;h<o;h++){
			printf(" %c ",carac[h]);
		}
	}else{
		cout<<" Sin resultados";
	}
}
int Cantidad_lineas(FILE*arch){
	int contador=0,i=0,exit=0;
	rewind(arch);
	arch = fopen("ExpresionesAlgebraicas.dat","r+b");
	fread(&dat,sizeof(Datos),1,arch);
	while(!feof(arch)){
		for(int i=0;i<=strlen(dat.cadena);i++){
			if(dat.cadena[i]==36){
				lin=contador+1;
			}else if(dat.cadena[i]==64){
				linn=contador+1;
			}else if(dat.cadena[i]=='\n'){
				contador++;
			}
		}
		fread(&dat,sizeof(Datos),1,arch);
	}
	fclose(arch);
	for(int i=0;i<strlen(dat.cadena);i++){
		if(dat.cadena[i]>=33&&dat.cadena[i]<=125){
			exit++;
		}
	}
	cout<<endl<<endl<<"  - Cantidad de lineas  ";
	if(exit>0){
		cout<<contador+1;
	}else{
		cout<<" No tiene nada escrito en su archivo";
	}
	return exit;
}
void Numero_entero(FILE*arch,FILE*fin){
	int y=0,s1=0,s2=0,s3=0,s4=0,s5=0,s6=0,s7=0,s8=0,s9=0,s10=0;
	char Numero[max];
	rewind(arch);
	arch = fopen("ExpresionesAlgebraicas.dat","r+b");
	fread(&dat,sizeof(Datos),1,arch);
	while(!feof(arch)){
		for(int i=0;i<strlen(dat.cadena);i++){
			
			if((s1==0)&&(dat.cadena[i]==48)){
				Numero[y]=48;
				y++;
				s1=1;
			}
			if((s2==0)&&(dat.cadena[i]==49)){
				Numero[y]=49;
				y++;
				s2=1;
			}
			if((s3==0)&&(dat.cadena[i]==50)){
				Numero[y]=50;
				y++;
				s3=1;
			}
			if((s4==0)&&(dat.cadena[i]==51)){
				Numero[y]=51;
				y++;
				s4=1;
			}
			if((s5==0)&&(dat.cadena[i]==52)){
				Numero[y]=52;
				y++;
				s5=1;
			}
			if((s6==0)&&(dat.cadena[i]==53)){
				Numero[y]=53;
				y++;
				s6=1;
			}
			if((s7==0)&&(dat.cadena[i]==54)){
				Numero[y]=54;
				y++;
				s7=1;
			}
			if((s8==0)&&(dat.cadena[i]==55)){
				Numero[y]=55;
				y++;
				s8=1;
			}
			if((s9==0)&&(dat.cadena[i]==56)){
				Numero[y]=56;
				y++;
				s9=1;
			}
			if((s10==0)&&(dat.cadena[i]==57)){
				Numero[y]=57;
				y++;
				s10=1;
			}
		}
		fread(&dat,sizeof(Datos),1,arch);
	}
	fclose(arch);
	if(y>0){
		char tokenE[12]= {10,10,32,'E','n','t','e','r','o','s',32,32};
		for(int j=0;j<12;j++){
			lex.Enteros[j]=tokenE[j];
		}
		int oo=12,i=0;
		lex.Enteros[oo]=Numero[i];
		lex.Enteros[oo+1] = 32;
		lex.Enteros[oo+2] = Numero[i+1];
		lex.Enteros[oo+3] = 32;
		lex.Enteros[oo+4] = Numero[i+2];
		lex.Enteros[oo+5] = 32;
		lex.Enteros[oo+6] = Numero[i+3];
		lex.Enteros[oo+7] = 32;
		lex.Enteros[oo+8] = Numero[i+4];
		lex.Enteros[oo+9] = 32;
		lex.Enteros[oo+10] = Numero[i+5];
		lex.Enteros[oo+11] = 32;
		lex.Enteros[oo+12] = Numero[i+6];
		lex.Enteros[oo+13] = 32;
		lex.Enteros[oo+14] = Numero[i+7];
		lex.Enteros[oo+15] = 32;
		lex.Enteros[oo+16] = Numero[i+8];
		lex.Enteros[oo+17] = 32;
		lex.Enteros[oo+18] = Numero[i+9];
		fin = fopen("AnalizadorLexico.dat","r+");
		for(int i=0;i<oo+19;i++){
			if(i==0){
				cout<<endl<<endl<<"  -";
			}else if(lex.Enteros[i]!=10){
				printf("%c",lex.Enteros[i]);
			}
		}
		fwrite(&lex,sizeof(Analizador),1,fin);
		fclose(fin);
	}else{
		cout<<endl<<endl<<"  - Enteros: Sin resultados";
	}
}
void Numero_real(FILE * arch, FILE * fin){
	char Real[200];
	int k=0,pos=0;
	bool val=false;
	rewind(arch);
	arch = fopen("ExpresionesAlgebraicas.dat","r+b");
	fread(&dat,sizeof(Datos),1,arch);
	while(!feof(arch)){
		for(int i=0;i<strlen(dat.cadena);i++){
			if((dat.cadena[i]>=48 && dat.cadena[i]<=57) || dat.cadena[i]==46){			
				if(dat.cadena[i]==46){
					Real[k] = 46;
					k++;
					pos=k;
					if(Real[pos+1]==(dat.cadena[i]>=48&&dat.cadena[i]<=57)){
						val=true;
					}
				}else{
					Real[k] = dat.cadena[i];
					k++;
				}
			}
		}
		fread(&dat,sizeof(Datos),1,arch);
	}
	fclose(arch);
	if(val==true){
		char tokenR[11]= {10,10,32,'R','e','a','l','e','s',32,32};
		int o=11;
		for(int j=0;j<o;j++){
			lex.Real[j]=tokenR[j];
		}
		for(int a=0;a<k;a++){
			if(Real[a]==46){
				lex.Real[o]=Real[a-2];
				lex.Real[o+1]=Real[a-1];
				lex.Real[o+2]=Real[a];
				lex.Real[o+3]=Real[a+1];
				lex.Real[o+4]=32;
				o+=5;
			}
		}
		fin=fopen("AnalizadorLexico.dat","r+");
		for(int i=0;i<o+11;i++){
			if(i==0){
				cout<<endl<<endl<<"  -";
			}else if(lex.Real[i]!=10){
				printf("%c",lex.Real[i]);
			}
		}
		fwrite(&lex,sizeof(Analizador),1,fin);
		fclose(fin);
	}else{
		cout<<endl<<endl<<"  - Reales: Sin resultados";
	}
}
void Parentesis(FILE * arch, FILE * fin){
	char Parentesis[max];
	int jj=0,x1=0,x2=0,f=0,s=0;
	rewind(arch);
	arch=fopen("ExpresionesAlgebraicas.dat","r+b");
	fread(&dat,sizeof(Datos),1,arch);
	while(!feof(arch)){
		for(int i=0;i<strlen(dat.cadena);i++){
			if((x1==0)&&(dat.cadena[i]==40)){
				Parentesis[jj] = dat.cadena[i];
				jj++;
				x1=1;
			}if((x2==0)&&(dat.cadena[i]==41)){
				Parentesis[jj] = dat.cadena[i];
				jj++;
				x2=1;
			}
		}
		fread(&dat,sizeof(Datos),1,arch);
	}
	fclose(arch);
	if(jj>0){
		char tokenP[14]= {10,10,32,'P','a','r','e','n','t','e','s','i','s',32};
		for(int i=0;i<14;i++){
			lex.Parent[i]=tokenP[i];
			if(tokenP[i]==32){
				f=i+1;
				lex.Parent[f+1] = Parentesis[s];
				lex.Parent[f+2] = 32;
				lex.Parent[f+3] = Parentesis[s+1];
			}
		}
		fin=fopen("AnalizadorLexico.dat","r+");
		for(int f=0;f<18;f++){
			if(f==2){
				cout<<"  - ";
			}if(lex.Parent[f]!=32){
				printf("%c",lex.Parent[f]);
			}
		}
		fwrite(&lex,sizeof(Analizador),1,fin);
		fclose(fin);
	}else{
		cout<<endl<<endl<<"  - Parentesis: Sin resultados";
	}
}
void Operadores(FILE * arch, FILE * fin){
	char Operadores[max];
	int j=0,p1=0,p2=0,p3=0,p4=0,xx=0;
	rewind(arch);
	arch = fopen("ExpresionesAlgebraicas.dat","r+b");
	fread(&dat,sizeof(Datos),1,arch);
	while(!feof(arch)){
		for(int i=0;i<strlen(dat.cadena);i++){
			if((p1==0)&&(dat.cadena[i]==43)){
				Operadores[j] = dat.cadena[i];
				j++;
				p1=1;
			}if((p2==0)&&(dat.cadena[i]==45)){
				Operadores[j] = dat.cadena[i];
				j++;
				p2=1;
			}if((p3==0)&&(dat.cadena[i]==47)){
				Operadores[j] = dat.cadena[i];
				j++;
				p3=1;
			}if((p4==0)&&(dat.cadena[i]==42)){
				Operadores[j] = dat.cadena[i];
				j++;
				p4=1;
			}
		}
		fread(&dat,sizeof(Datos),1,arch);	
	}
	fclose(arch);
	if(j>0){
		char tokenO[14]= {10,10,32,'O','p','e','r','a','d','o','r','e','s',32};
		for(int i=0;i<14;i++){
			lex.Operad[i]=tokenO[i];
			if((tokenO[i]=='s')&&(tokenO[i+1]==32)){
				lex.Operad[i+3]=Operadores[xx];
				lex.Operad[i+4]=32;
				lex.Operad[i+5]=Operadores[xx+1];
				lex.Operad[i+6]=32;
				lex.Operad[i+7]=Operadores[xx+2];
				lex.Operad[i+8]=32;
				lex.Operad[i+9]=Operadores[xx+3];
			}
		}
		fin=fopen("AnalizadorLexico.dat","r+");
		for(int x=0;x<24;x++){
			if(x==2){
				cout<<"  -";
			}	
			printf("%c",lex.Operad[x]);
		}
		fwrite(&lex,sizeof(Analizador),1,fin);
		fclose(fin);
	}else{
		cout<<endl<<endl<<"  - Operadores: Sin resultados";
	}
}
void Error_lexico(FILE * arch, FILE * fin){
	char Error[100];
	int e=0,q1=0,q2=0;
	rewind(arch);
	arch = fopen("ExpresionesAlgebraicas.dat","r+b");
	fread(&dat,sizeof(Datos),1,arch);
	while(!feof(arch)){
		for(int i=0;i<strlen(dat.cadena);i++){
			if((q1==0)&&(dat.cadena[i]==64)){
				Error[e]=dat.cadena[i];
				e++;
				q1=1;
			}if((q2==0)&&(dat.cadena[i]==36)){
				Error[e]=dat.cadena[i];
				e++;
				q2=1;
			}
		}
		fread(&dat,sizeof(Datos),1,arch);
	}
	fclose(arch);
	if(e>0){
		char tokenError[16]={10,10,32,'E','r','r','o','r',32,'L','e','x','i','c','o',32};
		int ee=16,w=0;
		for(int i=0;i<ee;i++){
			lex.Error_lexico[i]=tokenError[i];
		}
		fin=fopen("AnalizadorLexico.dat","r+");
		for(int u=ee;u<(ee+e+2);u++){
			if(u%2==0){
				lex.Error_lexico[u]=32;
			}else{
				lex.Error_lexico[u]=Error[w];
				w++;
			}
		}
		for(int j=0;j<(ee+w+2);j++){
			if(j==0){
				cout<<endl<<endl<<"  -";
			}else if(lex.Error_lexico[j]!=10){
				printf("%c",lex.Error_lexico[j]);
			}
		}
		fwrite(&lex,sizeof(Analizador),1,fin);
		fclose(fin);
		cout<<endl<<endl<<" ---------------------------------------------------------------------------------------------------------------"<<endl<<endl;
		if(lin!=0){
			cout<<endl<<"  |--Error lexico $ en la linea numero "<<lin;
		}if(linn!=0){
			cout<<endl<<"  |--Error lexico @ en la linea numero "<<linn;	
		}
	}else{
		cout<<endl;
		cout<<endl<<" -----------------------------------";
		cout<<endl<<" |No se encontraron errores lexicos|";
		cout<<endl<<" -----------------------------------";
	}
}
void Palabras_reservadas(FILE * arch){
	int x=0,z=0,w=0,validar=0,x1=0,x2=0,x3=0,x4=0,x5=0,x6=0,x7=0,x8=0,x9=0,x10=0,x11=0,x12=0,x13=0,x14=0,x15=0,x16=0;
	char Resultados[100];
	do{
		char busqueda[50];x=0;z=0;w=0;validar=0;
		if(i==0) strcpy(busqueda,"if");
		if(i==1) strcpy(busqueda,"using");
		if(i==2) strcpy(busqueda,"namespace");
		if(i==3) strcpy(busqueda,"return");
		if(i==4) strcpy(busqueda,"int");
		if(i==5) strcpy(busqueda,"float");
		if(i==6) strcpy(busqueda,"double");
		if(i==7) strcpy(busqueda,"char");
		if(i==8) strcpy(busqueda,"void");
		if(i==9) strcpy(busqueda,"bool");
		if(i==10) strcpy(busqueda,"false");
		if(i==11) strcpy(busqueda,"true");
		if(i==12) strcpy(busqueda,"cout");
		if(i==13) strcpy(busqueda,"cin");
		if(i==14) strcpy(busqueda,"std");
		if(i==15) strcpy(busqueda,"include");
		rewind(arch);
		arch=fopen("ExpresionesAlgebraicas.dat","r+b");
		fread(&dat,sizeof(Datos),1,arch);
		while(!feof(arch)){
			while(dat.cadena[x]!='\0'){
				x++;
			};
			while(busqueda[w]!='\0'){
				w++;	
			};
			for(int y=0;y<x;y++){
				z=0;
				while(busqueda[z]!='\0'){
					if(busqueda[z]==dat.cadena[y+z]){
						validar+=1;
					}
					z++;
				};
				if(validar==w){
					y=x;
				}else{
					validar=0;
				}
			}
			fread(&dat,sizeof(Datos),1,arch);
		}
		fclose(arch);
		if(validar==w){
			if(i==0) x1=1;
			if(i==1) x2=1;
			if(i==2) x3=1;
			if(i==3) x4=1;
			if(i==4) x5=1;
			if(i==5) x6=1;
			if(i==6) x7=1;
			if(i==7) x8=1;
			if(i==8) x9=1;
			if(i==9) x10=1;
			if(i==10) x11=1;
			if(i==11) x12=1;
			if(i==12) x13=1;
			if(i==13) x14=1;
			if(i==14) x15=1;
			if(i==15) x16=1;
		}
		i++;
	}while(i!=16);

	cout<<endl<<endl<<"  - Palabras Reservadas: ";
	if(x1==1) cout<<" if ";
	if(x2==1) cout<<" using ";
	if(x3==1) cout<<" namespace ";
	if(x4==1) cout<<" return ";
	if(x5==1) cout<<" int ";
	if(x6==1) cout<<" float ";
	if(x7==1) cout<<" double ";
	if(x8==1) cout<<" char ";
	if(x9==1) cout<<" void ";
	if(x10==1) cout<<" bool ";
	if(x11==1) cout<<" false ";
	if(x12==1) cout<<" true ";
	if(x13==1) cout<<" cout ";
	if(x14==1) cout<<" cin ";
	if(x15==1) cout<<" std ";
	if(x16==1) cout<<" include ";
}

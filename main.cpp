 #include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <conio.h> 
#include<locale.h>
#include<time.h>
#include<iostream>
#define TAM 10
char titulo[TAM][100];
char autor[TAM][100];
char editora[TAM][50];
int op; //receber opção sair ou continuar
int opc; //para escolher opção de menu
int count, con, codigoliv[5];
void cadastro();
int main(void){
for (int i=0; i<5;i++){
	codigoliv[i]=0;
	}
	
	do{
			printf("\n-----------------------Menu.-----------------------\n");
			printf("1. Cadastrar.\n");
			printf("2. Cadastros.\n");
			printf("0. Encerrar.\n");
			printf("\n \nEscolha uma opção:",setlocale(LC_ALL,"Portuguese"));
			scanf("%d",&opc);
			
			switch(opc){
				case 1:
						cadastro();
					break;
				case 2: 
					system("cls");
					if (codigoliv[0]==0){
						printf("\n \nLISTA VAZIA!!\n \n");
					}else{
						for (count=0; count<5; count++){
							if (codigoliv[count] > 0){
								printf("codigo= %d. Titulo= %s. Autor= %s. Editora= %s.\n", codigoliv[count], titulo[count], autor[count], editora[count]);
							}else{
								printf("ESPAÇO VAZIO\n",setlocale(LC_ALL,"Portuguese"));
							}
						}
					}
					break;
				}
		}while(opc!=0);
}

void cadastro(){
	static int linha;
		do{
			if(codigoliv[4]==0){
				printf("\nDigite o titulo: ");
				scanf("%s", titulo[linha]);
				fflush(stdin);
				printf("\nDigite o autor: ");
				scanf("%s", autor[linha]);
				fflush(stdin);
				printf("\nDigite o editora: ");
				scanf("%s", editora[linha]);
				fflush(stdin);
				printf("\nDigite 1 para continuar ou outro valor para sair: ");
				scanf("%d", &op);
				fflush(stdin);
				codigoliv[linha]=rand()%1700+500;
				linha++;
			}else{
				printf("Lista cheia");
				op=5;
			}
		}while(op==1);
}

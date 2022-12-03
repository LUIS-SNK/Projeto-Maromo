#include <stdio.h>
#include <stdlib.h>
#include "conta.h"
#define MAX 1000

/******************************************
*                                         *
*      Atividade Final - Linguagem C      *
*                                         *
* ---> Luigi Cordeiro de Oliveira         *
* ---> Luis Gustavo Castiglioni Raimundo  *
*                                         *
******************************************/

void depositar(c_conta cConta[1000], int p);

int main() {
    c_conta vtrContas[MAX];
    int p = 0; //indica posicao (quantidade)
    inicializar(vtrContas, MAX);
    //montar o menu
    int opcao;
    do{
        system("cls");
        printf("========= Cadastro de contas bancarias =========\n\n");
        printf("1. Cadastrar Conta \n");
        printf("2. Alterar Conta \n");
        printf("3. Procurar Conta \n");
        printf("4. Listar Contas \n");
        printf("5. Depositar \n");
        printf("6. Sacar \n");
        printf("7. Imprimir Conta\n");
        printf("8. Saldo Geral das Contas\n");
        printf("9. Sair \n\n\n");
        printf("Digite sua opcao:  \n");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                system("cls");
                inserir(vtrContas, p);
                p++;
                break;
            case 2:
                system("cls");
                alterar(vtrContas, p);
                break;
            case 3:
                system("cls");
                procurar(vtrContas, p);
                break;
            case 4:
                system("cls");
                listar(vtrContas, p);
                break;
            case 5:
                system("cls");
                depositar(vtrContas, p);
                break;
            case 6:
                system("cls");
                sacar(vtrContas, p);
                break;
            case 7:
                system("cls");
                imprimir(vtrContas, p);
                break;
            case 8:
                system("cls");
                saldoGeral(vtrContas, p);
                break;
            case 9:
                system("cls");
                printf("Fim do programa \n");
                exit(0);
        }
    }while(opcao!=9);

    return 0;
}

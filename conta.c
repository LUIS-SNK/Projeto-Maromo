#include <stdio.h>
#include <stdlib.h>
#include "conta.h"

struct Conta{
    int numero;
    char cliente[51];
    int especial;
    double saldo;
};

void inicializar(c_conta cConta[], int tamanho){
    for(int i=0; i<tamanho; i++){
        cConta[i] = NULL;
    }
}

void inserir(c_conta cConta[], int posicao){
    printf("========= CADASTRO DE CONTAS =========\n\n");
    //reservar 1 (um) espaco na memoria para um produto
    cConta[posicao] = (c_conta) malloc(sizeof(struct Conta));

    printf("\nDigite o numero da conta: \n");
    scanf("%d", &cConta[posicao]->numero);

    fflush(stdin);
    printf("\nDigite o nome do cliente: \n");
    gets(cConta[posicao]->cliente);

    printf("\nConta especial? - (1) Sim | (0) Nao: \n");
    scanf("%d", &cConta[posicao]->especial);

    cConta[posicao]->saldo = 0.0;
    printf("\nCadastro da conta efetuado com sucesso. \n\n");
    system("pause");
}

void listar(c_conta cConta[], int tamanho){
    //passar pelo vetor, listando cada item pelo ponteiro
    printf("============== RELATORIO DE CONTAS ==============\n");
    for(int i=0; i<tamanho; i++){
        printf("\n");
        imprimirConta(cConta, i);
        printf("\n=================================================\n");
    }
    printf("\n");
    system("pause");
}

void alterar(c_conta cConta[], int tamanho){
    printf("=============== ALTERAR CONTA ===============\n\n");
    int numProcurado = procurarConta();
    for(int i = 0; i<tamanho; i++){
        if(numProcurado == cConta[i]->numero){
            fflush(stdin);
            printf("\nDigite o novo nome do cliente: \n");
            gets(cConta[i]->cliente);
            printf("\nConta atualizada com sucesso \n");
            system("pause");
            return; //sai da funcao
        }
    }
    printf("\nConta nao encontrada\n\n\n");
    system("pause");
}


void saldoGeral(c_conta cConta[], int tamanho){
    printf("================== SALDO GERAL ==================\n\n");
    double total = 0.0;
    for(int i=0; i<tamanho; i++){
        total+= cConta[i]->saldo;
    }
    listar(cConta, tamanho);
    printf("\nTotal do saldo geral R$%.2lf \n\n", total);
    system("pause");
}

void depositar(c_conta cConta[], int tamanho) {
    printf("================= DEPOSITAR =================\n\n");
    int numProcurado = procurarConta();
    for(int i = 0; i<tamanho; i++){
        if(numProcurado == cConta[i]->numero){
            fflush(stdin);
            printf("\nDigite o valor que deseja depositar: R$");
            double valor;
            scanf("%lf", &valor);
            if(valor <=0 ){
                printf("\nValor indevido. Informar corretamente\n");
                system("pause");
                return;
            }
            cConta[i]->saldo += valor;
            printf("\n\nDeposito efetuado com sucesso!\n\n");
            system("pause");
            return; //sai da funcao
        }
    }
    printf("\nConta nao encontrada!\n\n\n");
    system("pause");

}

void sacar(c_conta cConta[], int tamanho) {
    printf("=================== SACAR ===================\n\n");
    int numProcurado = procurarConta();
    for(int i = 0; i<tamanho; i++){
        if(numProcurado == cConta[i]->numero){
            fflush(stdin);
            printf("\n\nDigite o valor que deseja sacar: R$");
            double valor;
            scanf("%lf", &valor);
            if(valor > cConta[i]->saldo){
                printf("\n\nSaldo indisponivel!\n");
                printf("Voce possui R$%.2lf  na conta \n\n\n", cConta[i]->saldo);
                system("pause");
                return;
            }
            cConta[i]->saldo -= valor;
            printf("\n\nSaque realizado com sucesso!\n\n");
            system("pause");
            return; //sai da funcao
        }
    }
    printf("\nConta nao encontrada!\n\n\n");
    system("pause");

}

void procurar(c_conta cConta[], int tamanho){
    printf("=============== PROCURAR CONTA ===============\n\n");
    int numProcurado = procurarConta();
    for(int i = 0; i<tamanho; i++){
        if(numProcurado == cConta[i]->numero){
            system("cls");
            printf("============ Dados da Conta ============\n\n");
            imprimirConta(cConta, i);
            printf("\n========================================\n\n");
            system("pause");
            return;
        }
    }
    printf("\nConta nao encontrada!\n\n\n");
    system("pause");
}

void imprimir(c_conta cConta[], int tamanho){
    printf("=============== IMPRIMIR CONTA ===============\n\n");
    int numProcurado = procurarConta();
    for(int i = 0; i<tamanho; i++){
        if(numProcurado == cConta[i]->numero){
            system("cls");
            printf("============ Dados da Conta ============\n\n");
            imprimirConta(cConta, i);
            printf("\n========================================\n\n");
            system("pause");
            return;
        }
    }
    printf("\nConta nao encontrada!\n\n\n");
    system("pause");
}

void imprimirConta(c_conta const *cConta, int i) {
    printf("    Numero: %d \n", cConta[i]->numero);
    printf("    Cliente: %s \n", cConta[i]->cliente);
    if(cConta[i]->especial == 0){
        printf("    Conta especial: NAO \n");
    }else{
        printf("    Conta especial: SIM \n");
    }
    printf("    Saldo: R$%.2lf \n", cConta[i]->saldo);
}

int procurarConta() {
    int numProcurado;
    printf("Digite o numero da conta a ser procurada: \n");
    scanf("%d", &numProcurado);
    return numProcurado;
}

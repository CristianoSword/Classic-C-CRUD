/* Um exemplo simples de lista postal em C usando matrizes com estruturas. */

#include <stdio.h>
#include <stdlib.h>

#define MAX 100 //limite de 100 contatos

struct addr {
    char name[30];          //nome
    char street[40];        //rua
    char city[20];          //cidade
    char state[3];          //estado
    unsigned long int zip;  //cep
} addr_info[MAX];

//proto
void init_list(void), enter (void);
void delet(void), list(void);
int menu_select(void), find_free(void);

int main(void)
{
    char choice;

    init_list(); //inicializa matriz de structs
    for (;;){
        choice = menu_select();
            switch (choice) {
            case 1: enter();
                break;
            case 2: delet();
                break;
            case 3: list();
                break;
            case 4: //system("pause");
                    return 0;
                break;
                }
            }
}

//inicializa a lista
void init_list(void)
{
    register int t;

    for(t=0; t<MAX; ++t) addr_info[t].name[0] = '\0';
}

//obtem a selecao
menu_select(void)
{
    char s[80];
    int c;

    printf("1. Inserir um nome\n");
    printf("2. Excluir um nome\n");
    printf("3. Listar o arquivo\n");
    printf("4. Sair\n");

    do{
        printf("\n Digite sua escolha: ");
        gets(s);
        c = atoi(s);
    }while (c<0 || c>4);
    return c;
}

//Insere os endereços na lista
void enter(void)
{
    int slot;
    char s[80];

    slot = find_free();
    if(slot==-1) {
        printf("\nlista cheia");
        return;
    }

    printf("\nDigite seu nome: ");
    gets(addr_info[slot].name);

    printf("\nDigite a rua: ");
    gets(addr_info[slot].street);

    printf("\nDigite a cidade: ");
    gets(addr_info[slot].city);

    printf("\nDigite o estado: ");
    gets(addr_info[slot].state);

    printf("\nDigite o cep: ");
    gets(s);
    addr_info[slot].zip = strtoul(s, '\0', 10);
}

//Encontra uma estrutura nao usada
find_free(void)
{
    register int t;
    for(t=0; addr_info[t].name[0] && t<MAX; ++t);

    if(t==MAX) return -1; //nenhum elemento livre
    return t;
}

//apaga um endereço
void delet(void)
{
    register int slot;
    char s[80];

    printf("digite o registro #: ");
    gets(s);
    slot = atoi(s);
    if(slot>=0 && slot < MAX)
        addr_info[slot].name[0] = '\0';
}

//mostra a lista na tela
void list(void)
{
    register int t;

    for(t=0; t<MAX; ++t){
        if(addr_info[t].name[0]){
            printf("\nNome: %s\n", addr_info[t].name);
            printf("Rua: %s\n", addr_info[t].street);
            printf("Cidade: %s\n", addr_info[t].city);
            printf("Estado: %s\n", addr_info[t].state);
            printf("Cep: %lu\n", addr_info[t].zip);
        }
    }
    printf("\n\n");
}




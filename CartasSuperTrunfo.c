#include <stdlib.h>
#include <stdio.h>

struct Carta{
    char Estado[3];
    char Codigo[5];
    char Cidade[50];
    int Populacao;
    float Area;
    float Pib;
    int Turistico;
};

void preecherCarta(struct Carta *carta){
    printf("Informe o Estado: ");
    scanf("%2s", carta->Estado);

    printf("Informe o Codigo: ");
    scanf("%4s", carta->Codigo);

    printf("Informe a Cidade: ");
    scanf(" %49[^\n]", carta->Cidade);

    printf("Informe a Populacao: ");
    scanf("%d", &carta->Populacao);

    printf("Informe a Area: ");
    scanf("%f", &carta->Area);

    printf("Informe o Pib: ");
    scanf("%f", &carta->Pib);

    printf("Informe o Ponto Turistico: ");
    scanf("%d", &carta->Turistico);

    printf(" \n");
}

void mostrarCarta(struct Carta carta, int numero){
    printf(" \n");
    printf("Carta %d:\n", numero);
    printf("Estado:%s\n", carta.Estado);
    printf("Codigo:%s\n", carta.Codigo);
    printf("Cidade:%s\n", carta.Cidade);
    printf("Populacao:%d\n", carta.Populacao);
    printf("Area:%.2f\n", carta.Area);
    printf("PIB:%.2f\n", carta.Pib);
    printf("Pontos Turisticos:%d\n", carta.Turistico);
    printf(" \n");
}

int main(){
    struct Carta carta1, carta2;

    printf("Cadastro da Carta 1:\n");
    preecherCarta(&carta1);

    printf("Cadastro da Carta 1:\n");
    preecherCarta(&carta2);

    printf("=== Dados das Cartas Cadastradas ===\n\n");
    mostrarCarta(carta1, 1);
    mostrarCarta(carta2, 2);

    return 0;
}

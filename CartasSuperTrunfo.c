#include <stdlib.h>
#include <stdio.h>

struct Carta{
    char estado[3];
    char codigo[5];
    char cidade[50];
    unsigned long int populacao;
    float area;
    float pib;
    int turistico;
    float densidade;
    float per_capita;
    float super_power;
};

void preecherCarta(struct Carta *carta){
    printf("Informe o Estado: ");
    scanf(" %2s", carta->estado);

    printf("Informe o Codigo: ");
    scanf(" %4s", carta->codigo);

    printf("Informe a Cidade: ");
    scanf(" %49[^\n]", carta->cidade);

    printf("Informe a Populacao: ");
    scanf("%lu", &carta->populacao);

    printf("Informe a Area em km: ");
    scanf("%f", &carta->area);

    printf("Informe o Pib: ");
    scanf("%f", &carta->pib);

    printf("Informe a quantidade de pontos turisticos: ");
    scanf("%d", &carta->turistico);

    printf(" \n");
}

float calcDensidadePopulacional(struct Carta *carta){
    carta->densidade = carta->populacao / carta->area;
    return carta->densidade;
}

float calcPib(struct Carta *carta){
    carta->per_capita = (carta->pib * 1e6) / carta->populacao;
    return carta->per_capita;
}

void mostrarCarta(struct Carta carta, int numero){
    printf(" \n");
    printf("Carta %d:\n", numero);
    printf("Estado:%s\n", carta.estado);
    printf("Codigo:%s\n", carta.codigo);
    printf("Cidade:%s\n", carta.cidade);
    printf("Populacao:%lu\n", carta.populacao);
    printf("Area: %.2f \n", carta.area);
    printf("PIB: %.2f milhoes de reais\n", carta.pib);
    printf("Numero de Pontos Turisticos: %d\n", carta.turistico);
    printf("Densidade Populacional: %.2f hab/km\n", carta.densidade);
    printf("PIB per Capita: %.2f reais\n", carta.per_capita);  
    printf("Super Poder: %.2f\n", carta.super_power);
    printf(" \n");
}

void calculaSuperPower(struct Carta *carta){
    carta->super_power =
    (float)carta->populacao +
    carta->area +
    carta->pib +
    carta->turistico +
    (1.0f / carta->densidade) +
    carta->per_capita;
}

void compararAtributos(struct Carta c1, struct Carta c2){

    printf("População: Carta %d venceu (%d)\n", 
        (c1.populacao > c2.populacao) ? 1 : 2,
        (c1.populacao > c2.populacao) ? 1 : 0);

    printf("Área: Carta %d venceu (%d)\n", 
        (c1.area > c2.area) ? 1 : 2,
        (c1.area > c2.area) ? 1 : 0);

    printf("PIB: Carta %d venceu (%d)\n", 
        (c1.pib > c2.pib) ? 1 : 2,
        (c1.pib > c2.pib) ? 1 : 0);

    printf("Pontos Turísticos: Carta %d venceu (%d)\n", 
        (c1.turistico > c2.turistico) ? 1 : 2,
        (c1.turistico > c2.turistico) ? 1 : 0);

    printf("Densidade Populacional: Carta %d venceu (%d)\n", 
        (c1.densidade < c2.densidade) ? 1 : 2,
        (c1.densidade < c2.densidade) ? 1 : 0);

    printf("PIB per Capita: Carta %d venceu (%d)\n", 
        (c1.per_capita > c2.per_capita) ? 1 : 2,
        (c1.per_capita > c2.per_capita) ? 1 : 0);

    printf("Super Poder: Carta %d venceu (%d)\n", 
        (c1.super_power > c2.super_power) ? 1 : 2,
        (c1.super_power > c2.super_power) ? 1 : 0);
        
    printf(" \n");
}



int main(){
    struct Carta carta1, carta2;

    printf("Cadastro da Carta 1:\n");
    preecherCarta(&carta1);
    calcDensidadePopulacional(&carta1);
    calcPib(&carta1);
    calculaSuperPower(&carta1);

    printf("Cadastro da Carta 2:\n");
    preecherCarta(&carta2);
    calcDensidadePopulacional(&carta2);
    calcPib(&carta2);
    calculaSuperPower(&carta2);

    printf("=== Dados das Cartas Cadastradas ===\n\n");
    mostrarCarta(carta1, 1);
    mostrarCarta(carta2, 2);

    printf("=== Comparando as Cartas ===\n\n");
    compararAtributos(carta1, carta2);

    return 0;
}

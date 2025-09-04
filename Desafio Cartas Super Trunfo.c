#include<stdio.h>

int main(){

    /*Este exercício só utiliza os conceitos básicos de variáveis.
    Primeiro é realizado a declaração das variáveis, posteriormente utilizado o
    scanf para receber os valores do usuário, e por fim a impressão na ordem dada pelo exercício.
    */
   
    // declarar variáveis
    char estado1, estado2, cod1[5], cod2[5], cidade1[20], cidade2[20];
    int pop1, pop2, pt1, pt2;
    float area1, area2, pib1, pib2, densidadepop1, densidadepop2, pibpercap1, pibpercap2, superpoder1, superpoder2;
    
    // cadastrar carta 1
    printf("Cadastramento da primeira carta \n");
    printf("Digite uma letra de 'A' a 'H' para cadastrar o estado\n");
    scanf("%c", &estado1);
    
    printf("Digite um código para a carta - 01 a 04 (ex: A01, B03)\n");
    scanf("%s", &cod1);
    
    printf("Digite o nome da cidade: \n");
    scanf("%s", &cidade1);
    
    printf("Digite o número de habitantes: \n");
    scanf("%d", &pop1);
    
    printf("Digite a area da cidade: \n");
    scanf("%f", &area1);
    
    printf("Digite o PIB da cidade: \n");
    scanf("%f", &pib1);
    
    printf("Digite o número de pontos turisticos: \n");
    scanf("%d", &pt1);
    
    
    // cadastrar carta 2
    printf("\nCadastramento da segunda carta \n\n");
    
    printf("Digite uma letra de 'A' a 'H' para cadastrar o estado\n");
    scanf(" %c", &estado2);
    
    printf("Digite um código para a carta - 01 a 04 (ex: A01, B03)\n");
    scanf("%s", &cod2);
    
    printf("Digite o nome da cidade: \n");
    scanf("%s", &cidade2);
    
    printf("Digite o número de habitantes: \n");
    scanf("%d", &pop2);
    
    printf("Digite a area da cidade: \n");
    scanf("%f", &area2);
    
    printf("Digite o PIB da cidade: \n");
    scanf("%f", &pib2);
    
    printf("Digite o número de pontos turisticos: \n");
    scanf("%d", &pt2);
    
    // calculos

    densidadepop1= (float)pop1/area1;
    densidadepop2=(float)pop2/area2;
    pibpercap1=(float)pib1/pop1;
    pibpercap2=(float)pib2/pop2;
    superpoder1 = (float)(pop1+area1+pib1+pt1+pibpercap1+(1/densidadepop1));
    superpoder2 = (float)(pop2+area2+pib2+pt2+pibpercap2+(1/densidadepop2));
    
    // imprimir as informações de forma organizada
    
    //carta 1
    
    printf("Informações das cartas cadastradas: \n");
    
    printf("\nCarta 1: \n");
    printf("Estado: %c \n", estado1);
    printf("Código: %s \n", cod1);
    printf("Nome da Cidade: %s \n", cidade1);
    printf("População: %d \n", pop1);
    printf("Área: %.3f km^2\n", area1);
    printf("PIB: %.3f \n", pib1);
    printf("Número de Pontos Turisticos: %d \n", pt1);
    printf("Densidade Populacional: %.2f \n", densidadepop1);
    printf("PIB per Capita: %.2f \n", pibpercap1);
    
    
    printf("\nCarta 2: \n");
    printf("Estado: %c \n", estado2);
    printf("Código: %s \n", cod2);
    printf("Nome da Cidade: %s \n", cidade2);
    printf("População: %d \n", pop2);
    printf("Área: %.3f km^2\n", area2);
    printf("PIB: %.3f \n", pib2);
    printf("Número de Pontos Turisticos: %d \n", pt2);
    printf("Densidade Populacional: %.2f \n", densidadepop2);
    printf("PIB per Capita: %.2f \n", pibpercap2);


    /* Comparação: aqui farei com a condicional if, pois não sei a melhor forma de fazer escolher a carta
    sem o uso da condicional e sem saber previamente quem vai ganhar.
    */

    printf("\nComparação de Cartas\n\n");
    if(pop1>pop2){
        printf("População: Carta 1 venceu! \n");
    } else {
        printf("População: Carta 2 venceu! \n");
    }

    if(area1>area2){
        printf("Área: Carta 1 venceu! \n");
    } else {
        printf("Área: Carta 2 venceu! \n");
    }

    if(pib1>pib2){
        printf("PIB: Carta 1 venceu! \n");
    } else {
        printf("PIB: Carta 2 venceu! \n");
    }

    if(pt1>pt2){
        printf("Pontos Turisticos: Carta 1 venceu! \n");
    } else {
        printf("Pontos Turisticos: Carta 2 venceu! \n");
    }

    if(densidadepop1<densidadepop2){
        printf("Densidade Populacional: Carta 1 venceu! \n");
    } else {
        printf("Densidade Populacional: Carta 2 venceu! \n");
    }

    if(pibpercap1>pibpercap2){
        printf("PIB per Capita: Carta 1 venceu! \n");
    } else {
        printf("PIB per Capita: Carta 2 venceu! \n");
    }

    if(superpoder1>superpoder2){
        printf("Super Poder: Carta 1 venceu! \n");
    } else {
        printf("Super Poder: Carta 2 venceu! \n");
    }


    return 0;
}

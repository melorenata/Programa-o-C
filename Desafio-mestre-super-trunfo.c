#include <stdio.h>

int main() {
    // declarar variáveis
    char estado1, estado2, cod1[5], cod2[5], cidade1[20], cidade2[20];
    int pop1, pop2, pt1, pt2;
    float area1, area2, pib1, pib2, densidadepop1, densidadepop2, pibpercap1, pibpercap2, superpoder1, superpoder2;

    int atributo1, atributo2;   // escolhas do jogador
    int pontosCarta1 = 0, pontosCarta2 = 0; // fará a contagem de pontos, para cada vitória 1 ponto

    // chamadas para cadastrar carta 1
    printf("Cadastramento da primeira carta \n");
    printf("Digite uma letra de 'A' a 'H' para cadastrar o estado: ");
    scanf(" %c", &estado1);

    printf("Digite um código para a carta - 01 a 04 (ex: A01, B03): ");
    scanf("%s", cod1);

    printf("Digite o nome da cidade: ");
    scanf("%s", cidade1);

    printf("Digite o número de habitantes: ");
    scanf("%d", &pop1);

    printf("Digite a area da cidade: ");
    scanf("%f", &area1);

    printf("Digite o PIB da cidade: ");
    scanf("%f", &pib1);

    printf("Digite o número de pontos turisticos: ");
    scanf("%d", &pt1);

    // chamdas para cadastrar carta 2
    printf("\nCadastramento da segunda carta \n");
    printf("Digite uma letra de 'A' a 'H' para cadastrar o estado: ");
    scanf(" %c", &estado2);

    printf("Digite um código para a carta - 01 a 04 (ex: A01, B03): ");
    scanf("%s", cod2);

    printf("Digite o nome da cidade: ");
    scanf("%s", cidade2);

    printf("Digite o número de habitantes: ");
    scanf("%d", &pop2);

    printf("Digite a area da cidade: ");
    scanf("%f", &area2);

    printf("Digite o PIB da cidade: ");
    scanf("%f", &pib2);

    printf("Digite o número de pontos turisticos: ");
    scanf("%d", &pt2);

    // calculos
    densidadepop1 = (float)pop1 / area1;
    densidadepop2 = (float)pop2 / area2;
    pibpercap1 = (float)pib1 / pop1;
    pibpercap2 = (float)pib2 / pop2;
    superpoder1 = (float)(pop1 + area1 + pib1 + pt1 + pibpercap1 + (1 / densidadepop1));
    superpoder2 = (float)(pop2 + area2 + pib2 + pt2 + pibpercap2 + (1 / densidadepop2));

    // ---------------- MENU DE ATRIBUTOS ------------------
    printf("\nEscolha dois atributos para a comparacao:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Populacional (vence o menor)\n");
    printf("6 - PIB per Capita\n");
    printf("7 - Super Poder\n");

    // escolher primeiro atributo
    printf("\nDigite o numero do primeiro atributo: ");
    scanf("%d", &atributo1);

    // escolher segundo atributo
    do {
        printf("Digite o numero do segundo atributo (diferente do primeiro): ");
        scanf("%d", &atributo2);
        if (atributo2 == atributo1) {
            printf("Erro: O segundo atributo deve ser diferente do primeiro.\n");
        }
    } while (atributo2 == atributo1);

    // ---------------- COMPARAÇÕES ------------------
    printf("\nComparacao entre %s e %s:\n", cidade1, cidade2);

    for (int i = 1; i <= 2; i++) {
        int escolhido = (i == 1) ? atributo1 : atributo2;
        int resultado; // 1 = carta1, 2 = carta2, 0 = empate

        switch (escolhido) {
        case 1: // população
            resultado = (pop1 > pop2) ? 1 : (pop2 > pop1) ? 2 : 0;
            break;
        case 2: // area
            resultado = (area1 > area2) ? 1 : (area2 > area1) ? 2 : 0;
            break;
        case 3: // PIB
            resultado = (pib1 > pib2) ? 1 : (pib2 > pib1) ? 2 : 0;
            break;
        case 4: // pontos turísticos
            resultado = (pt1 > pt2) ? 1 : (pt2 > pt1) ? 2 : 0;
            break;
        case 5: // densidade populacional
            resultado = (densidadepop1 < densidadepop2) ? 1 : (densidadepop2 < densidadepop1) ? 2 : 0;
            break;
        case 6: // PIB per capita
            resultado = (pibpercap1 > pibpercap2) ? 1 : (pibpercap2 > pibpercap1) ? 2 : 0;
            break;
        case 7: // Super poder
            resultado = (superpoder1 > superpoder2) ? 1 : (superpoder2 > superpoder1) ? 2 : 0;
            break;
        default:
            printf("Opcao invalida!\n"); // acentos do português pode gerar conflito de inf. no print
            resultado = -1;
            break;
        }

        // soma pontos: empate = ambos ganham 1
        pontosCarta1 += (resultado == 1 || resultado == 0) ? 1 : 0;
        pontosCarta2 += (resultado == 2 || resultado == 0) ? 1 : 0;

        // exibir comparação
        printf("\nAtributo %d: ", escolhido);
        switch (escolhido) {
        case 1:
            printf("População -> %s: %d | %s: %d\n", cidade1, pop1, cidade2, pop2);
            break;
        case 2:
            printf("Área -> %s: %.2f | %s: %.2f\n", cidade1, area1, cidade2, area2);
            break;
        case 3:
            printf("PIB -> %s: %.2f | %s: %.2f\n", cidade1, pib1, cidade2, pib2);
            break;
        case 4:
            printf("Pontos Turisticos -> %s: %d | %s: %d\n", cidade1, pt1, cidade2, pt2);
            break;
        case 5:
            printf("Densidade Populacional -> %s: %.2f | %s: %.2f\n", cidade1, densidadepop1, cidade2, densidadepop2);
            break;
        case 6:
            printf("PIB per Capita -> %s: %.2f | %s: %.2f\n", cidade1, pibpercap1, cidade2, pibpercap2);
            break;
        case 7:
            printf("Super Poder -> %s: %.2f | %s: %.2f\n", cidade1, superpoder1, cidade2, superpoder2);
            break;
        }
        
        // condição para mostrar quem venceu ou empate
        if (resultado == 1) {
            printf("Resultado: Carta 1 venceu neste atributo.\n");
        } else if (resultado == 2) {
            printf("Resultado: Carta 2 venceu neste atributo.\n");
        } else if (resultado == 0) {
            printf("Resultado: Empate neste atributo (ambos ganham ponto).\n");
        }
    }

    // ---------------- RESULTADO FINAL ------------------
    printf("\nPontuacao final:\n");
    printf("%s: %d pontos\n", cidade1, pontosCarta1);
    printf("%s: %d pontos\n", cidade2, pontosCarta2);

    if (pontosCarta1 > pontosCarta2) {
        printf("\nVencedor: %s!\n", cidade1);
    } else if (pontosCarta2 > pontosCarta1) {
        printf("\nVencedor: %s!\n", cidade2);
    } else {
        printf("\nEmpate!\n");
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define MAX_CIDADES 10 


typedef struct {
    char estado[3];
    int codigo;
    char nome[50];
    long populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
} Cidade;


float calcular_densidade_populacional(long populacao, float area) {
    return populacao / area;
}

// Função para calcular o PIB per capita
float calcular_pib_per_capita(float pib, long populacao) {
    return pib / populacao;
}


void exibir_dados_cidade(Cidade cidade) {
    printf("\n--- Dados da Cidade ---\n");
    printf("Estado: %s\n", cidade.estado);
    printf("Código da Carta: %c%02d\n", cidade.estado[0], cidade.codigo);
    printf("Nome da Cidade: %s\n", cidade.nome);
    printf("População: %ld\n", cidade.populacao);
    printf("Área (km²): %.2f\n", cidade.area);
    printf("PIB: R$ %.2f bilhões\n", cidade.pib);
    printf("Pontos Turísticos: %d\n", cidade.pontos_turisticos);
    printf("Densidade Populacional (habitantes por km²): %.2f\n", cidade.densidade_populacional);
    printf("PIB per capita (R$): %.2f\n", cidade.pib_per_capita);
    printf("------------------------\n");
}

int main() {
    Cidade cidades[MAX_CIDADES];
    int num_cidades = 0;

    while (1) {
        
        if (num_cidades >= MAX_CIDADES) {
            printf("\nLimite de cidades atingido!\n");
            break;
        }

        
        printf("\nCadastro da Cidade %d:\n", num_cidades + 1);

        
        printf("Digite o estado (duas letras, ex: SP): ");
        scanf("%s", cidades[num_cidades].estado);

        
        printf("Digite o código da carta (1-4): ");
        scanf("%d", &cidades[num_cidades].codigo);

        
        printf("Digite o nome da cidade: ");
        getchar(); 
        fgets(cidades[num_cidades].nome, 50, stdin);
        cidades[num_cidades].nome[strcspn(cidades[num_cidades].nome, "\n")] = 0; // Remover a nova linha no final do nome

        
        printf("Digite a população da cidade: ");
        scanf("%ld", &cidades[num_cidades].populacao);

        
        printf("Digite a área da cidade (em km²): ");
        scanf("%f", &cidades[num_cidades].area);

        printf("Digite o PIB da cidade (em bilhões de R$): ");
        scanf("%f", &cidades[num_cidades].pib);

      
        printf("Digite o número de pontos turísticos da cidade: ");
        scanf("%d", &cidades[num_cidades].pontos_turisticos);

       
        cidades[num_cidades].densidade_populacional = calcular_densidade_populacional(cidades[num_cidades].populacao, cidades[num_cidades].area);
        cidades[num_cidades].pib_per_capita = calcular_pib_per_capita(cidades[num_cidades].pib, cidades[num_cidades].populacao);

        
        exibir_dados_cidade(cidades[num_cidades]);

        
        num_cidades++;

       
        char continuar;
        printf("\nDeseja cadastrar outra cidade? (s/n): ");
        getchar(); 
        scanf("%c", &continuar);

        if (continuar == 'n' || continuar == 'N') {
            break;
        }
    }

    printf("\nCadastro de cidades finalizado.\n");
    return 0;
}


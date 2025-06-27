#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char nome[50];
    float preco;
    int quantidade;
} Item;

typedef struct {
    Item materiais[20];
    int total_materiais;

    Item equipamentos[20];
    int total_equipamentos;

    Item mao_de_obra[20];
    int total_mao_de_obra;

    float logistica_salario_almoxarife;
    int logistica_qtd_tecnicos;
    float logistica_salario_tecnico;

    float custos_adicionais;
} Categoria;

// Funcoes
void menu_inicial(Categoria *categoria);
void menu_categorias(Categoria *categoria);
void menu_orcamento_categoria(Categoria *categoria);
void menu_orcamento_total(Categoria *categoria);
void menu_materiais(Categoria *categoria);
void menu_equipamentos(Categoria *categoria);
void menu_mao_de_obra(Categoria *categoria);
void menu_logistica(Categoria *categoria);
void salvar_orcamento_em_arquivo(Categoria *categoria);
void padronizar_string(char *str);

// Funcao principal
int main() {
    Categoria categoria = {0};
    menu_inicial(&categoria);

    return 0;
}

// Implementacao dos menus
void menu_inicial(Categoria *categoria) {
    int escolha;

    do {
        printf("\nMenu Inicial:");
        printf("\n[1] Fazer lista de valores");
        printf("\n[2] Orcamento por categoria");
        printf("\n[3] Orcamento total");
        printf("\n[4] Salvar orcamento em arquivo");
        printf("\n[0] Sair do programa\n");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                menu_categorias(categoria);
                break;
            case 2:
                menu_orcamento_categoria(categoria);
                break;
            case 3:
                menu_orcamento_total(categoria);
                break;
            case 4:
                salvar_orcamento_em_arquivo(categoria);
                break;
            case 0:
                printf("\nSaindo do programa...\n");
                break;
            default:
                printf("\nOpcaoo invalida! Tente novamente.\n");
        }
    } while (escolha != 0);
}

void menu_categorias(Categoria *categoria) {
    int escolha;

    do {
        printf("\nMenu Categorias:");
        printf("\n[1] Materiais");
        printf("\n[2] Equipamentos");
        printf("\n[3] Mao de obra");
        printf("\n[4] Logistica");
        printf("\n[0] Voltar ao menu inicial\n");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                menu_materiais(categoria);
                break;
            case 2:
                menu_equipamentos(categoria);
                break;
            case 3:
                menu_mao_de_obra(categoria);
                break;
            case 4:
                menu_logistica(categoria);
                break;
            case 0:
                printf("\nVoltando ao menu inicial...\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while (escolha != 0);
}

void menu_materiais(Categoria *categoria) {
    int escolha;

    do {
        char nome[50];
        float preco;
        int quantidade;

        printf("\nDigite o nome do material (ou 0 para voltar): ");
        scanf(" %49[^\n]", nome);  // nome que eu coloquei:0 - nome que eu quero comparar com o nome que eu coloquei: '0' ---> '0' STRING --> 0 int
        padronizar_string(nome);

        if (strcmp(nome, "0") == 0) break;  //string compare

        // Verifica duplicacao
        int encontrado = 0;
        for (int i = 0; i < categoria->total_materiais; i++) {
            if (strcmp(categoria->materiais[i].nome, nome) == 0) {
                encontrado = 1;
                printf("\nMaterial ja existe! Deseja editar? (1-Sim, 0-Nao): ");
                scanf("%d", &escolha);

                if (escolha == 1) {
                    printf("Digite o novo preco: ");
                    scanf("%f", &preco);
                    while (preco < 0){
                    printf("O preco nao pode ser negativo, digite novamente: ");
                    scanf("%f", &preco);
                    }
                    printf("Digite a nova quantidade: ");
                    scanf("%d", &quantidade);
                    while (quantidade < 0){
                    printf("A quantidade na  o pode ser negativa, digite novamente: ");
                    scanf("%d", &quantidade);
                    }

                    categoria->materiais[i].preco = preco;
                    categoria->materiais[i].quantidade = quantidade;
                    printf("\nMaterial atualizado com sucesso!\n");
                }
                break;
            }
        }

        if (!encontrado) {
            printf("Digite o preco do material: ");
            scanf("%f", &preco);
            while (preco < 0){
                printf("O preco nao pode ser negativo, digite novamente: ");
                scanf("%f", &preco);
            }
            printf("Digite a quantidade: ");
            scanf("%d", &quantidade);
            while (quantidade < 0){
                printf("A quantidade nao pode ser negativa, digite novamente: ");
                scanf("%d", &quantidade);
            }
            strcpy(categoria->materiais[categoria->total_materiais].nome, nome);
            categoria->materiais[categoria->total_materiais].preco = preco;
            categoria->materiais[categoria->total_materiais].quantidade = quantidade;
            categoria->total_materiais++;

            printf("\nMaterial adicionado com sucesso!\n");
        }
    } while (1);
}

void menu_equipamentos(Categoria *categoria) {
    int escolha;

    do {
        char nome[50];
        float preco;
        int quantidade;

        printf("\nDigite o nome do equipamento (ou 0 para voltar): ");
        scanf(" %49[^\n]", nome);
        padronizar_string(nome);

        if (strcmp(nome, "0") == 0) break;

        // Verifica duplicacao
        int encontrado = 0;
        for (int i = 0; i < categoria->total_equipamentos; i++) {
            if (strcmp(categoria->equipamentos[i].nome, nome) == 0) {
                encontrado = 1;
                printf("\nEquipamento ja existe! Deseja editar? (1-Sim, 0-Nao): ");
                scanf("%d", &escolha);

                if (escolha == 1) {
                    printf("Digite o novo preco: ");
                    scanf("%f", &preco);
                    while (preco < 0){
                    printf("O preco nao pode ser negativo, digite novamente: ");
                    scanf("%f", &preco);
                    }

                    printf("Digite a nova quantidade: ");
                    scanf("%d", &quantidade);
                    while (quantidade < 0){
                    printf("A quantidade nao pode ser negativa, digite novamente: ");
                    scanf("%d", &quantidade);

                    }
                    categoria->equipamentos[i].preco = preco;
                    categoria->equipamentos[i].quantidade = quantidade;
                    printf("\nEquipamento atualizado com sucesso!\n");
                }
                break;
            }
        }

        if (!encontrado) {
            printf("Digite o preco do equipamento: ");
            scanf("%f", &preco);
            while (preco < 0){
            printf("O preco nao pode ser negativo, digite novamente: ");
            scanf("%f", &preco);
            }
            printf("Digite a quantidade: ");
            scanf("%d", &quantidade);
            while (quantidade < 0){
            printf("A quantidade nao pode ser negativa, digite novamente: ");
            scanf("%d", &quantidade);
            }

            strcpy(categoria->equipamentos[categoria->total_equipamentos].nome, nome);
            categoria->equipamentos[categoria->total_equipamentos].preco = preco;
            categoria->equipamentos[categoria->total_equipamentos].quantidade = quantidade;
            categoria->total_equipamentos++;

            printf("\nEquipamento adicionado com sucesso!\n");
        }
    } while (1);
}
void menu_mao_de_obra(Categoria *categoria) {
    int escolha;

    do {
        char nome[50];
        float salario;
        int quantidade;

        printf("\nDigite o nome do profissional (ou 0 para voltar): ");
        scanf(" %49[^\n]", nome);
        padronizar_string(nome);

        if (strcmp(nome, "0") == 0) break;

        // Verifica duplicacao
        int encontrado = 0;
        for (int i = 0; i < categoria->total_mao_de_obra; i++) {
            if (strcmp(categoria->mao_de_obra[i].nome, nome) == 0) {
                encontrado = 1;
                printf("\nProfissional ja existe! Deseja editar? (1-Sim, 0-Nao): ");
                scanf("%d", &escolha);

                if (escolha == 1) {
                    printf("Digite o novo salario: ");
                    scanf("%f", &salario);
                    while (salario < 0){
                    printf("O salario nao pode ser negativo, digite novamente: ");
                    scanf("%f", &salario);
                    }

                    printf("Digite a nova quantidade: ");
                    scanf("%d", &quantidade);
                    while (quantidade < 0){
                    printf("A quantidade nao pode ser negativa, digite novamente: ");
                    scanf("%d", &quantidade);
                    }

                    categoria->mao_de_obra[i].preco = salario;
                    categoria->mao_de_obra[i].quantidade = quantidade;
                    printf("\nInformacoes do profissional atualizadas com sucesso!\n");
                }
                break;
            }
        }

        if (!encontrado) {
            printf("Digite o salario do profissional: ");
            scanf("%f", &salario);
            while (salario < 0){
            printf("O salario nao pode ser negativo, digite novamente: ");
            scanf("%f", &salario);
            }

            printf("Digite a quantidade de profissionais: ");
            scanf("%d", &quantidade);
            while (quantidade < 0){
            printf("A quantidade nao pode ser negativa, digite novamente: ");
            scanf("%d", &quantidade);
            }

            strcpy(categoria->mao_de_obra[categoria->total_mao_de_obra].nome, nome);
            categoria->mao_de_obra[categoria->total_mao_de_obra].preco = salario;
            categoria->mao_de_obra[categoria->total_mao_de_obra].quantidade = quantidade;
            categoria->total_mao_de_obra++;

            printf("\nProfissional adicionado com sucesso!\n");
        }
    } while (1);
}

void menu_logistica(Categoria *categoria) {
    float salario_temp; // Variavel temporaria para o salario do almoxarife

    do {
        printf("\nDigite o salario do almoxarife (ou 0 para voltar): ");
        scanf("%f", &salario_temp);

        if (salario_temp == 0) {
            printf("\nVoltando ao menu anterior...\n");
            break;
        }

        while (salario_temp < 0) {
            printf("O salario nao pode ser negativo, digite novamente: ");
            scanf("%f", &salario_temp);

            if (salario_temp == 0) {
                printf("\nVoltando ao menu anterior...\n");
                break;
            }
        }

        if (salario_temp == 0) break;

        // Salva o valor valido no campo da estrutura
        categoria->logistica_salario_almoxarife = salario_temp;

        printf("Digite a quantidade de tecnicos de seguranca: ");
        scanf("%d", &categoria->logistica_qtd_tecnicos);
        while (categoria->logistica_qtd_tecnicos < 0) {
            printf("A quantidade nao pode ser negativa, digite novamente: ");
            scanf("%d", &categoria->logistica_qtd_tecnicos);
        }

        printf("Digite o salario dos tecnicos de seguranca: ");
        scanf("%f", &categoria->logistica_salario_tecnico);
        while (categoria->logistica_salario_tecnico < 0) {
            printf("O salario nao pode ser negativo, digite novamente: ");
            scanf("%f", &categoria->logistica_salario_tecnico);
        }

        printf("\nInformacoes de logistica registradas com sucesso!\n");
        printf("Salario do almoxarife: R$%.2f\n", categoria->logistica_salario_almoxarife);
        printf("Quantidade de tecnicos de seguranca: %d\n", categoria->logistica_qtd_tecnicos);
        printf("Salario dos tecnicos de seguranca: R$%.2f\n", categoria->logistica_salario_tecnico);
    } while (1);
}

void menu_orcamento_categoria(Categoria *categoria) {
    printf("\n--- Orcamento por Categoria ---\n");

    float total_materiais = 0;
    printf("\nMateriais:\n");
    for (int i = 0; i < categoria->total_materiais; i++) {
        float subtotal = categoria->materiais[i].preco * categoria->materiais[i].quantidade;
        total_materiais += subtotal;
        printf(" - %s: R$%.2f x %d = R$%.2f\n", categoria->materiais[i].nome, categoria->materiais[i].preco, categoria->materiais[i].quantidade, subtotal);
    }
    printf("Total Materiais: R$%.2f\n", total_materiais);

    float total_equipamentos = 0;
    printf("\nEquipamentos:\n");
    for (int i = 0; i < categoria->total_equipamentos; i++) {
        float subtotal = categoria->equipamentos[i].preco * categoria->equipamentos[i].quantidade;
        total_equipamentos += subtotal;
        printf(" - %s: R$%.2f x %d = R$%.2f\n", categoria->equipamentos[i].nome, categoria->equipamentos[i].preco, categoria->equipamentos[i].quantidade, subtotal);
    }
    printf("Total Equipamentos: R$%.2f\n", total_equipamentos);

    float total_mao_de_obra = 0;
    printf("\nMao de Obra:\n");
    for (int i = 0; i < categoria->total_mao_de_obra; i++) {
        float subtotal = categoria->mao_de_obra[i].preco * categoria->mao_de_obra[i].quantidade;
        total_mao_de_obra += subtotal;
        printf(" - %s: R$%.2f x %d = R$%.2f\n", categoria->mao_de_obra[i].nome, categoria->mao_de_obra[i].preco, categoria->mao_de_obra[i].quantidade, subtotal);
    }
    printf("Total Mao de Obra: R$%.2f\n", total_mao_de_obra);

    float total_logistica = categoria->logistica_salario_almoxarife + (categoria->logistica_qtd_tecnicos * categoria->logistica_salario_tecnico);
    printf("\nLogistica:\n");
    printf(" - Almoxarife: R$%.2f\n", categoria->logistica_salario_almoxarife);
    printf(" - Tecnicos de Seguranca (%d): R$%.2f\n", categoria->logistica_qtd_tecnicos, categoria->logistica_salario_tecnico);
    printf("Total Logistica: R$%.2f\n", total_logistica);

    printf("\n-----------------------------------\n");
}

void menu_orcamento_total(Categoria *categoria) {
    float total = 0;

    for (int i = 0; i < categoria->total_materiais; i++) {
        total += categoria->materiais[i].preco * categoria->materiais[i].quantidade;
    }

    for (int i = 0; i < categoria->total_equipamentos; i++) {
        total += categoria->equipamentos[i].preco * categoria->equipamentos[i].quantidade;
    }

    for (int i = 0; i < categoria->total_mao_de_obra; i++) {
        total += categoria->mao_de_obra[i].preco * categoria->mao_de_obra[i].quantidade;
    }

    total += categoria->logistica_salario_almoxarife + (categoria->logistica_qtd_tecnicos * categoria->logistica_salario_tecnico);

    // Aplica��o dos acr�scimos
    float acrescimo_4 = total * 0.04;
    float acrescimo_2_5 =  total * 0.025;
    total += (acrescimo_4 + acrescimo_2_5);

    printf("\nOrcamento Total: R$%.2f (com descontos aplicados)\n", total);
}

void salvar_orcamento_em_arquivo(Categoria *categoria) {
    FILE *arquivo = fopen("orcamento.txt", "w");
    if (arquivo == NULL) {
        printf("\nErro ao criar o arquivo.\n");
        return;
    }

    fprintf(arquivo, "--- Orcamento por Categoria ---\n");
    float total = 0;

    fprintf(arquivo, "\nMateriais:\n");
    for (int i = 0; i < categoria->total_materiais; i++) {
        float subtotal = categoria->materiais[i].preco * categoria->materiais[i].quantidade;
        total += subtotal;
        fprintf(arquivo, " - %s: R$%.2f x %d = R$%.2f\n", categoria->materiais[i].nome, categoria->materiais[i].preco, categoria->materiais[i].quantidade, subtotal);
    }

    fprintf(arquivo, "\nEquipamentos:\n");
    for (int i = 0; i < categoria->total_equipamentos; i++) {
        float subtotal = categoria->equipamentos[i].preco * categoria->equipamentos[i].quantidade;
        total += subtotal;
        fprintf(arquivo, " - %s: R$%.2f x %d = R$%.2f\n", categoria->equipamentos[i].nome, categoria->equipamentos[i].preco, categoria->equipamentos[i].quantidade, subtotal);
    }

    fprintf(arquivo, "\nMao de Obra:\n");
    for (int i = 0; i < categoria->total_mao_de_obra; i++) {
        float subtotal = categoria->mao_de_obra[i].preco * categoria->mao_de_obra[i].quantidade;
        total += subtotal;
        fprintf(arquivo, " - %s: R$%.2f x %d = R$%.2f\n", categoria->mao_de_obra[i].nome, categoria->mao_de_obra[i].preco, categoria->mao_de_obra[i].quantidade, subtotal);
    }

    total += categoria->logistica_salario_almoxarife + (categoria->logistica_qtd_tecnicos * categoria->logistica_salario_tecnico);

    fprintf(arquivo, "\nLogistica:\n");
    fprintf(arquivo, " - Almoxarife: R$%.2f\n", categoria->logistica_salario_almoxarife);
    fprintf(arquivo, " - Tecnicos de Seguranca (%d): R$%.2f\n", categoria->logistica_qtd_tecnicos, categoria->logistica_salario_tecnico);

    fprintf(arquivo, "\nTotal Geral (com descontos): R$%.2f\n", total);
    fclose(arquivo);

    printf("\nOrcamento salvo no arquivo 'orcamento.txt'.\n");
}

void padronizar_string(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura da sala (árvore binária)
struct Sala {
    char nome[50];
    struct Sala *esq;
    struct Sala *dir;
};

// Função para criar uma sala
struct Sala* criarSala(char nome[]) {
    struct Sala *nova = (struct Sala*)malloc(sizeof(struct Sala));
    strcpy(nova->nome, nome);
    nova->esq = NULL;
    nova->dir = NULL;
    return nova;
}

// Função para explorar as salas
void explorarSalas(struct Sala *atual) {
    char opcao;

    while (atual != NULL) {
        printf("\nVocê está em: %s\n", atual->nome);
        printf("Para onde deseja ir? (e = esquerda, d = direita, s = sair): ");
        scanf(" %c", &opcao);

        if (opcao == 'e') {
            atual = atual->esq;
        }
        else if (opcao == 'd') {
            atual = atual->dir;
        }
        else if (opcao == 's') {
            printf("\nSaindo da exploração...\n");
            return;
        }
        else {
            printf("Opção inválida!\n");
        }
    }

    printf("\nVocê chegou a um cômodo sem saída.\n");
}

int main() {

    // Criando as salas (árvore fixa)
    struct Sala *hall = criarSala("Hall de Entrada");
    struct Sala *biblioteca = criarSala("Biblioteca");
    struct Sala *cozinha = criarSala("Cozinha");
    struct Sala *sotao = criarSala("Sótão");
    struct Sala *jardim = criarSala("Jardim");

    // Conectando (árvore binária simples)
    hall->esq = biblioteca;
    hall->dir = cozinha;
    biblioteca->esq = sotao;
    biblioteca->dir = jardim;
    // cozinha não aponta para nada (folha)

    printf("=== Detective Quest - Nível Novato ===\n");
    printf("Exploração da mansão iniciada!\n");

    explorarSalas(hall);

    return 0;
}


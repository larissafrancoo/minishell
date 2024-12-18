#include "../include/minishell.h"

/*
Função: word_between_spaces

Descrição:
Extrai uma palavra de uma string a partir de um índice fornecido,
retornando a palavra até o próximo espaço ou o final da string.

Parâmetros:
- char *str: A string de onde a palavra será extraída.
- int idx: O índice inicial da palavra na string.

Retorno:
- char *: A palavra extraída, ou NULL se não for possível extrair.

Observação:
A memória alocada para a palavra deve ser liberada com `free()` após o uso.
*/

void test_word_between_spaces(void)
{
    char *str1 = "Este é um exemplo de string.";
    char *str2 = "Palavra com acento: café!";
    char *str3 = "   Início com espaço";
    char *str4 = "Fim com espaço  ";
    char *str5 = "Teste de palavra única";
    char *str6 = "    ";

    printf("\nTeste 1: Palavra no meio da string\n");
    char *word1 = word_between_spaces(str1, 5);
    if (word1)
    {
        printf("Palavra extraída: '%s'|\n", word1);
        free(word1);
    }

    printf("\nTeste 2: Palavra com acento\n");
    char *word2 = word_between_spaces(str2, 20);
    if (word2) {
        printf("Palavra extraída: '%s'|\n", word2);
        free(word2);
    }

    printf("\nTeste 3: Palavra no início da string\n");
    char *word3 = word_between_spaces(str3, 3);
    if (word3) {
        printf("Palavra extraída: '%s'|\n", word3);
        free(word3);
    }

    printf("\nTeste 4: Palavra no final da string\n");
    char *word4 = word_between_spaces(str4, 0);
    if (word4) {
        printf("Palavra extraída: '%s'|\n", word4);
        free(word4);
    }

    printf("\nTeste 5: Palavra de apenas 1 caractere\n");
    char *word5 = word_between_spaces(str5, 0);
    if (word5) {
        printf("Palavra extraída: '%s'|\n", word5);
        free(word5);
    }

    printf("\nTeste 6: String com apenas espaços\n");
    char *word6 = word_between_spaces(str6, 4);
    if (word6) {
        printf("Palavra extraída: '%s'|\n", word6);
        free(word6);
    } else {
        printf("Nenhuma palavra extraída\n");
    }
}

int main() {
    test_word_between_spaces();
    return (0);
}
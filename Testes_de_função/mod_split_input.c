#include "../include/minishell.h"

/*
 Função: mod_split_input
 
 Descrição:
 Divide uma string em palavras, retornando um vetor de strings.
 Ignora espaços extras e separa as palavras corretamente. O vetor é
 terminado com um ponteiro NULL.
 
 Parâmetros:
 - char *str: A string de entrada a ser dividida.
 
 Retorno:
 - char **: Vetor de palavras extraídas da string, terminado com NULL.
            Retorna NULL em caso de erro.
 
 Observação:
 A memória alocada para o vetor de palavras e para cada palavra extraída
 deve ser liberada com `free()` após o uso.
*/

void test_mod_split_input(void)
{
    char *str1 = "Este é um exemplo";
    printf("\nTeste 1: String com palavras separadas por um único espaço\n");
    char **result1 = mod_split_input(str1);
    if (result1)
    {
        for (int i = 0; result1[i] != NULL; i++)
        {
            printf("Palavra %d: '%s'|\n", i + 1, result1[i]);
            free(result1[i]);
        }
        free(result1);
    }

    char *str2 = "Texto  com   múltiplos    espaços";
    printf("\nTeste 2: String com múltiplos espaços\n");
    char **result2 = mod_split_input(str2);
    if (result2)
    {
        for (int i = 0; result2[i] != NULL; i++)
        {
            printf("Palavra %d: '%s'|\n", i + 1, result2[i]);
            free(result2[i]);
        }
        free(result2);
    }
    char *str3 = "";//pode colocar um '\0';
    printf("\nTeste 3: String vazia\n");
    char **result3 = mod_split_input(str3);
    if (result3 == NULL || result3[0] == NULL)
    {
        printf("Resultado esperado: NULL (sem palavras)\n");
    }
    else
    {
        for (int i = 0; result3[i] != NULL; i++)
        {
            printf("Palavra %d: '%s'|\n", i + 1, result3[i]);
            free(result3[i]);
        }
        free(result3);
    }

    char *str4 = "   Início e fim com espaços   ";
    printf("\nTeste 4: String com espaços no início e no final\n");
    char **result4 = mod_split_input(str4);
    if (result4)
    {
        for (int i = 0; result4[i] != NULL; i++)
        {
            printf("Palavra %d: '%s'|\n", i + 1, result4[i]);
            free(result4[i]);
        }
        free(result4);
    }

    char *str5 = "Palavra1 Palavra2";
    printf("\nTeste 5: String com apenas um espaço no meio\n");
    char **result5 = mod_split_input(str5);
    if (result5)
    {
        for (int i = 0; result5[i] != NULL; i++)
        {
            printf("Palavra %d: '%s'|\n", i + 1, result5[i]);
            free(result5[i]);
        }
        free(result5);
    }

    char *str6 = "Café é bom!";
    printf("\nTeste 6: String com caracteres especiais (acentos, pontuação)\n");
    char **result6 = mod_split_input(str6);
    if (result6)
    {
        for (int i = 0; result6[i] != NULL; i++)
        {
            printf("Palavra %d: '%s'|\n", i + 1, result6[i]);
            free(result6[i]);
        }
        free(result6);
    }

    char *str7 = "     ";
    printf("\nTeste 7: String composta apenas por espaços\n");
    char **result7 = mod_split_input(str7);
    if (result7 == NULL || result7[0] == NULL)
    {
        printf("Resultado esperado: NULL (sem palavras)\n");
    }
    else
    {
        for (int i = 0; result7[i] != NULL; i++)
        {
            printf("Palavra %d: '%s'|\n", i + 1, result7[i]);
            free(result7[i]);
        }
        free(result7);
    }

    char *str8 = "Supercalifragilisticexpialidocious exemplo";
    printf("\nTeste 8: String com palavras grandes\n");
    char **result8 = mod_split_input(str8);
    if (result8)
    {
        for (int i = 0; result8[i] != NULL; i++)
        {
            printf("Palavra %d: '%s'|\n", i + 1, result8[i]);
            free(result8[i]);
        }
        free(result8);
    }

    char *str9 = NULL;
    printf("\nTeste 9: Ponteiro NULL como entrada\n");
    char **result9 = mod_split_input(str9);
    if (result9 == NULL)
    {
        printf("Resultado esperado: NULL (entrada NULL)\n");
    }

    char *str10 = "UmaPalavra";
    printf("\nTeste 10: String com apenas uma palavra\n");
    char **result10 = mod_split_input(str10);
    if (result10)
    {
        for (int i = 0; result10[i] != NULL; i++)
        {
            printf("Palavra %d: '%s'|\n", i + 1, result10[i]);
            free(result10[i]);
        }
        free(result10);
    }

    char *str11 = "!";
    printf("\nTeste 10: String com apenas um char\n");
    char **result11 = mod_split_input(str11);
    if (result11)
    {
        for (int i = 0; result10[i] != NULL; i++)
        {
            printf("Palavra %d: '%s'|\n", i + 1, result11[i]);
            free(result11[i]);
        }
        free(result11);
    }
}

int main() {
    test_mod_split_input();
    return (0);
}
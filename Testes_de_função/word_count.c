#include "../include/minishell.h"

void test_word_count() {
    char *str1 = "Hello";
    printf("Teste 1: ");
    printf("Resultado esperado: 1, Resultado obtido: %zu\n", word_count(str1));

    char *str2 = "Hello World";
    printf("Teste 2: ");
    printf("Resultado esperado: 2, Resultado obtido: %zu\n", word_count(str2));

    char *str3 = "Hello   World";
    printf("Teste 3: ");
    printf("Resultado esperado: 2, Resultado obtido: %zu\n", word_count(str3));

    char *str4 = "";
    printf("Teste 4: ");
    printf("Resultado esperado: 0, Resultado obtido: %zu\n", word_count(str4));

    char *str5 = "Hello World   ";
    printf("Teste 5: ");
    printf("Resultado esperado: 2, Resultado obtido: %zu\n", word_count(str5));

    char *str6 = "     ";
    printf("Teste 6: ");
    printf("Resultado esperado: 0, Resultado obtido: %zu\n", word_count(str6));

    char *str7 = "Hello  World Test";
    printf("Teste 7: ");
    printf("Resultado esperado: 3, Resultado obtido: %zu\n", word_count(str7));

    char *str8 = "    Hello    World    Test    ";
    printf("Teste 8: ");
    printf("Resultado esperado: 3, Resultado obtido: %zu\n", word_count(str8));

    char *str9 = "Hello, World! Test.";
    printf("Teste 9: ");
    printf("Resultado esperado: 3, Resultado obtido: %zu\n", word_count(str9));

    char *str10 = "Hello 'World' Test";
    printf("Teste 10: ");
    printf("Resultado esperado: 3, Resultado obtido: %zu\n", word_count(str10));

    char *str11 = "This is  a  test    string.";
    printf("Teste 11: ");
    printf("Resultado esperado: 5, Resultado obtido: %zu\n", word_count(str11));
}

int main() {
    test_word_count();
    return 0;
}
#include "../include/minishell.h"

void test_find_next_char() {
    char *str1 = "Hello World";
    printf("Teste 1: ");
    printf("Resultado esperado: 4, Resultado obtido: %d\n", find_next_char(str1, 0));

    char *str2 = "\"Hello \"World Test";
    printf("Teste 2: ");
    printf("Resultado esperado: 12, Resultado obtido: %d\n", find_next_char(str2, 0));

    char *str3 = "'Hello 'World' 'Test";
    printf("Teste 3: ");
    printf("Resultado esperado: 19, Resultado obtido: %d\n", find_next_char(str3, 0));

    char *str4 = "Hello   World";
    printf("Teste 4: ");
    printf("Resultado esperado: 4, Resultado obtido: %d\n", find_next_char(str4, 0));

    char *str5 = "Hello World ";
    printf("Teste 5: ");
    printf("Resultado esperado: 10, Resultado obtido: %d\n", find_next_char(str5, 6));

    char *str6 = "";
    printf("Teste 6: ");
    printf("Resultado esperado: -1, Resultado obtido: %d\n", find_next_char(str6, 0));

    char *str7 = "HelloWorld";
    printf("Teste 7: ");
    printf("Resultado esperado: 9, Resultado obtido: %d\n", find_next_char(str7, 0));

    char *str8 = "    ";
    printf("Teste 8: ");
    printf("Resultado esperado: -1, Resultado obtido: %d\n", find_next_char(str8, 0));

    char *str9 = "Hello World";
    printf("Teste 9: ");
    printf("Resultado esperado: 4, Resultado obtido: %d\n", find_next_char(str9, 2));

    char *str10 = "\"Hello World'\"";
    printf("Teste 10: ");
    printf("Resultado esperado: 13, Resultado obtido: %d\n", find_next_char(str10, 0));
}

int main() {
    test_find_next_char();
    return 0;
}
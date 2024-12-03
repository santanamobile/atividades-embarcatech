/*
10 - Faça um programa que leia um numero inteiro positivo de
três dígitos (de 100 a 999). Gere outro numero formado pelos
dígitos invertidos do numero lido. Exemplo: número lido: 123 e
o resultado invertido deve ser 321.
*/

#include <stdio.h>

int inverterNumero(int numero)
{
    int invertido = 0, resto;

    while (numero != 0) {
        resto = numero % 10;
        invertido = invertido * 10 + resto;
        numero /= 10;
    }

    return invertido;

}

int main()
{

    int numero, numeroInvertido;

    printf("Digite um numero de tres digitos: ");

    if (scanf("%d", &numero) != 1) {
        printf("Falha na leitura do numero\n");
        return -1;
    }

    if (numero >= 101 && numero <= 999) {
        numeroInvertido = inverterNumero(numero);
        printf("O numero invertido e: %d\n", numeroInvertido);
    } else {
        printf("Numero invalido. Digite um numero entre 101 e 999.\n");
        return -1;
    }

    return 0;
}


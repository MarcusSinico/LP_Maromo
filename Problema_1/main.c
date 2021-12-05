#include <stdio.h>
#include <stdlib.h>

struct Candidatos
{
    int numero;
    char resposta[50];
    int nota;
};

int main()
{
    int num_candidatos = 1;
    printf("Digite a quantidade de candidatos: ");
    scanf("%d", &num_candidatos);

    struct Candidatos lista[num_candidatos];

    char gabarito[50] = "abcdeedcbaabcdeedcbaabcdeedcbaabcdeedcbaabcdeedcba";

    for(int i = 0; i < num_candidatos; i++)
    {
        struct Candidatos candidato;
        printf("\nNumero do candidato: ");
        scanf("%d", &candidato.numero);
        printf("\nRespostas do candidato: ");
        scanf("%s", &candidato.resposta);
        candidato.nota = 0;
        for(int j = 0; j < 51; j++)
        {
            if(candidato.resposta[j] == gabarito[j])
            {
                candidato.nota += 1;
            }
        }
        lista[i].numero = candidato.numero;
        lista[i].nota = candidato.nota;
    }

    for(int i = 1; i < num_candidatos; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (lista[i].nota > lista[j].nota)
            {
                int temp = lista[i].nota;
                lista[i].nota = lista[j].nota;
                lista[j].nota = temp;
            }
        }
    }

    printf("\n---CLASSIFICACAO---\n");
    for(int i = 0; i < num_candidatos; i++)
    {
        printf("NUMERO DO CANDIDATO:%d \tACERTOS:%d\n", lista[i].numero, lista[i].nota);
    }
    printf("\n");
}

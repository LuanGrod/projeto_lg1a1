#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

main()
{
//cria o arquivo .txt	
FILE *quest;
quest = fopen("TESTE_SISTEMA_REPRESENTACIONAL.DAT", "w");


struct 
{
int NroFrase=1, cinestesico=2, auditivo=3, visual, digital;
char frase[100], item_1[100], item_2[100], item_3[100], item_4[100];
} questionario;

fprintf(quest, "%d", questionario.NroFrase);

fclose(quest);

}

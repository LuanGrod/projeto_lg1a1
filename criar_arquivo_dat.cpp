#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
using namespace std;

main()
{	
setlocale(LC_ALL,"");
int i;
/*
quest = nome do ponteiro do arquivo txt
data = estrutura base com as informacoes do questionario
questionario = vetor de 1 a 5 com as opcoes
*/
FILE *quest;
quest = fopen("TESTE_SISTEMA_REPRESENTACIONAL.DAT", "w");

typedef struct 
{
int NroFrase, cinestesico, auditivo, visual, digital;
char frase[100], item_1[100], item_2[100], item_3[100], item_4[100];
} data;

data questionario[6];

for (i=1;i<=5;i++) 
{
questionario[i].NroFrase=i;
questionario[i].cinestesico=0;
questionario[i].auditivo=0;
questionario[i].visual=0;
questionario[i].digital=0;
}

strcpy(questionario[1].frase, "Eu tomo decisões importantes baseado em:");
strcpy(questionario[2].frase, "Durante uma discussão eu sou mais influenciado por:");
strcpy(questionario[3].frase, "Eu comunico mais facilmente o que se passa comigo:");
strcpy(questionario[4].frase, "É muito fácil pra mim:");
strcpy(questionario[5].frase, "Eu me percebo assim:");

strcpy(questionario[1].item_1, "Intuição");
strcpy(questionario[2].item_1, "Se eu entro em contato ou não com os sentimentos reais do outro");
strcpy(questionario[3].item_1, "Pelos sentimentos que compartilho");
strcpy(questionario[4].item_1, "Escolher os móveis mais confortáveis");
strcpy(questionario[5].item_1, "Eu sou muito sensível à maneira como a roupa veste o meu corpo");

strcpy(questionario[1].item_2, "O que me soa melhor");
strcpy(questionario[2].item_2, "O tom da voz da outra pessoa");
strcpy(questionario[3].item_2, "Pelo tom da minha voz");
strcpy(questionario[4].item_2, "Achar o volume e a sintonia ideais num sistema de som");
strcpy(questionario[5].item_2, "Se estou muito em sintonia com os sons dos ambientes");

strcpy(questionario[1].item_3, "O que me parece melhor");
strcpy(questionario[2].item_3, "Se eu posso ou não ver o argumento da outra pessoa");
strcpy(questionario[3].item_3, "Do modo como me visto e aparento");
strcpy(questionario[4].item_3, "Escolher as combinações de cores mais ricas e atraentes");
strcpy(questionario[5].item_3, "Eu respondo fortemente às cores e à aparência de uma sala");

strcpy(questionario[1].item_4, "Um estudo preciso e minucioso do assunto");
strcpy(questionario[2].item_4, "A lógica do argumento da outra pessoa");
strcpy(questionario[3].item_4, "Pelas palavras que escolho");
strcpy(questionario[4].item_4, "Selecionar o ponto mais relevante relativo a um assunto interessante");
strcpy(questionario[5].item_4, "Se sou muito capaz de raciocinar com fatos e dados novos\n");

fprintf(quest, "NroFrase                                Frase                                C  Item_1                                                              A  Item_2                                                    V  Item_3                                                        D  Item_4\n");
for (i=1;i<=349;i++) fprintf(quest, "=");
fprintf(quest, "\n");

//bloco frase
fprintf(quest, "%4d", questionario[1].NroFrase);
fprintf(quest, "%68s", questionario[1].frase);
fprintf(quest, "%6d  ", questionario[1].cinestesico);
fprintf(quest, "%-68s", questionario[1].item_1);
fprintf(quest, "%d  ", questionario[1].auditivo);
fprintf(quest, "%-58s", questionario[1].item_2);
fprintf(quest, "%d  ", questionario[1].visual);
fprintf(quest, "%-62s", questionario[1].item_3);
fprintf(quest, "%d  ", questionario[1].digital);
fprintf(quest, "%s\n", questionario[1].item_4);

//bloco item_1
fprintf(quest, "%4d", questionario[2].NroFrase);
fprintf(quest, "%68s", questionario[2].frase);
fprintf(quest, "%6d  ", questionario[2].cinestesico);
fprintf(quest, "%-68s", questionario[2].item_1);
fprintf(quest, "%d  ", questionario[2].auditivo);
fprintf(quest, "%-58s", questionario[2].item_2);
fprintf(quest, "%d  ", questionario[2].visual);
fprintf(quest, "%-62s", questionario[2].item_3);
fprintf(quest, "%d  ", questionario[2].digital);
fprintf(quest, "%s\n", questionario[2].item_4);

//bloco item_2
fprintf(quest, "%4d", questionario[3].NroFrase);
fprintf(quest, "%68s", questionario[3].frase);
fprintf(quest, "%6d  ", questionario[3].cinestesico);
fprintf(quest, "%-68s", questionario[3].item_1);
fprintf(quest, "%d  ", questionario[3].auditivo);
fprintf(quest, "%-58s", questionario[3].item_2);
fprintf(quest, "%d  ", questionario[3].visual);
fprintf(quest, "%-62s", questionario[3].item_3);
fprintf(quest, "%d  ", questionario[3].digital);
fprintf(quest, "%s\n", questionario[3].item_4);

//bloco item_3
fprintf(quest, "%4d", questionario[4].NroFrase);
fprintf(quest, "%68s", questionario[4].frase);
fprintf(quest, "%6d  ", questionario[4].cinestesico);
fprintf(quest, "%-68s", questionario[4].item_1);
fprintf(quest, "%d  ", questionario[4].auditivo);
fprintf(quest, "%-58s", questionario[4].item_2);
fprintf(quest, "%d  ", questionario[4].visual);
fprintf(quest, "%-62s", questionario[4].item_3);
fprintf(quest, "%d  ", questionario[4].digital);
fprintf(quest, "%s\n", questionario[4].item_4);

//bloco item_4
fprintf(quest, "%4d", questionario[5].NroFrase);
fprintf(quest, "%68s", questionario[5].frase);
fprintf(quest, "%6d  ", questionario[5].cinestesico);
fprintf(quest, "%-68s", questionario[5].item_1);
fprintf(quest, "%d  ", questionario[5].auditivo);
fprintf(quest, "%-58s", questionario[5].item_2);
fprintf(quest, "%d  ", questionario[5].visual);
fprintf(quest, "%-62s", questionario[5].item_3);
fprintf(quest, "%d  ", questionario[5].digital);
fprintf(quest, "%s", questionario[5].item_4);

for (i=1;i<=349;i++) fprintf(quest, "=");

fclose(quest);

}

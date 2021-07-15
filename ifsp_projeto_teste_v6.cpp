#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <Windows.h>
using namespace std;

char usuario[100], prontuario[10], nome_file[100]="RESULTADO ";

fim_programa()//finaliza o programa
{
	int i;
	system("cls");
	printf("====================================================\n");
	printf("\t\tFINALIZANDO O PROGRAMA!\n");
	printf("====================================================\n");
			for (i=0;i<52;i++)
	{
	printf(".");
	Sleep(10);
	}
}

realiza_teste()
{
	
	
	
	
	
}


master_room()//ambiente do administrador
{
	inicio:
	char teste;
	int i;
	
	system("cls");
	printf("====================================================\n");
	printf("       TESTE DOS SISTEMAS REPRESENTACIONAIS         \n");
	printf("====================================================\n");
	printf("\t1. CADASTRAR QUESTIONÁRIO\n");
	printf("\t2. VISUALIZAR QUESTIONÁRIO\n");
	printf("\t3. REALIZAR TESTE\n");
	printf("\t4. SOBRE O TESTE\n");
	printf("\tF. FIM\n");
	printf("====================================================\n");
	printf("\tESCOLHA -> ");
	teste = getch();
	printf("%c", teste);
	getch();
	printf("\n");
	
	switch(teste)
	{
		case '1': //cadastra o questionario e imprimi as informacoes no arquivo .dat
			FILE *quest; //cria o arquivo .dat
			quest = fopen("TESTE_SISTEMA_REPRESENTACIONAL.DAT", "w");
			
			typedef struct //define as variaveis dentro da estrutura
			{
				int NroFrase, cinestesico, auditivo, visual, digital;
				char frase[100], item_1[100], item_2[100], item_3[100], item_4[100];
			} data;
			
			data questionario[6];
			
			//colocar a informação nas variaveis
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

			//printar a informacao das variaveis no arquivo .dat  ja formatado
			fprintf(quest, "NroFrase                                Frase                                C  Item_1                                                              A  Item_2                                                    V  Item_3                                                        D  Item_4\n");
			for (i=1;i<=349;i++) fprintf(quest, "=");
			fprintf(quest, "\n");
			
			//bloco 1
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
			
			//bloco 2
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
			
			//bloco 3
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
			
			//bloco 4
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
			
			//bloco 5
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
			
			system("cls");
			printf("QUESTIONÁRIO CADASTRADO!!\n");
			system("pause");
			goto inicio;
		break;
		
		case '2'://vizualiza questionario, copia o conteudo do arquivo .dat em um arquivo questionario_1.txt
		
			FILE *file1; //abre o arquivo .dat em modo de leitura
			file1 = fopen("TESTE_SISTEMA_REPRESENTACIONAL.DAT", "r");
		
			FILE *file2; //cria o arquivo questionario_1.txt
			file2 = fopen("QUESTIONARIO_1.TXT", "w");

			char leitor[2600];
	
			while(fgets(leitor, 2600, file1) != NULL)
			
			fputs(leitor, file2);
			
			fclose(file1);
			fclose(file2);
		
			system("QUESTIONARIO_1.TXT");
			system("pause");

			goto inicio;
		break;
		
		case '3':
			realiza_teste();
			
			
			
			
		break;
		
		case '4':
			FILE *sobre;
			sobre = fopen("REFERENCIAL_TEORICO.TXT", "r");
			if (sobre == NULL) printf("ERRO! O arquivo não foi aberto!\n");
			system("REFERENCIAL_TEORICO.TXT");
			fclose(sobre);
			system("pause");
			
			goto inicio;
		break;
		
		case 'F':
			fim_programa();
			return 0;
		break;
		
		case 'f':
			fim_programa();
			return 0;
		break;
		
		default:
			system("cls");
			printf("ERRO AO ESCOLHER!");
			getch();
			goto inicio;

	}	

	return 0;
}


cria_arquivo()//cria o arquivo onde ficarao os resultados do questionario respondido
{
//nomeia o arquivo
strcat(nome_file, usuario);
int len = strlen(nome_file);
for (int i = 0, posicao = 0; i < len; i++, posicao++) 
{
    if (nome_file[posicao]==' ') nome_file[posicao] = '_';
	nome_file[i] = nome_file[posicao];
}
strcat(nome_file, "_");
strcat(nome_file, prontuario);

	    //cria o arquivo .txt	
		FILE *arquivo;
		strcat(nome_file, ".txt");
		arquivo = fopen(nome_file, "w");
		fclose(arquivo);
		
printf("\n");

if (arquivo == NULL) printf("ERRO! ARQUIVO NÃO FOI CRIADO!\n");
else printf("ARQUIVO CRIADO COM SUCESSO!");
return 0;
}


login()//realiza o login do usuario
{
int i;

setlocale(LC_ALL,"");
	
printf("DIGITE SEU NOME.................: ");
scanf("%[^\n]s", usuario);

i = stricmp (usuario, "MASTER");
if (i == 0) master_room();
else
{
printf("DIGITE SEU PRONTUÁRIO...........: ");
scanf("%s", &prontuario);
cria_arquivo();
realiza_teste();

}



}


main ()
{
setlocale(LC_ALL,"");

login();



return 0;	
}
	

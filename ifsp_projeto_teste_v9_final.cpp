#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <Windows.h>
using namespace std;

/*
Autor: Luan Guilherme Rodrigues
Prontuário: SP307319X
Disciplina: Lógica de Programação I (A1LG1)
Professor: Francisco Veríssimo Luciano
Repositório online no Github: https://github.com/LuanGrod/projeto_lg1a1.git
*/

char usuario[100], prontuario[10], nome_file[100]="RESULTADO ";
int i;

typedef struct //define uma estrutura com o nome data
{
	int NroFrase, cinestesico, auditivo, visual, digital;
	char frase[100], item_1[100], item_2[100], item_3[100], item_4[100];
} data;
data questionario[6];

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

quest_base() //alocando a informação nas variaveis
{

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

//cinestesico
strcpy(questionario[1].item_1, "Intuição");
strcpy(questionario[2].item_1, "Se eu entro em contato ou não com os sentimentos reais do outro");
strcpy(questionario[3].item_1, "Pelos sentimentos que compartilho");
strcpy(questionario[4].item_1, "Escolher os móveis mais confortáveis");
strcpy(questionario[5].item_1, "Eu sou muito sensível à maneira como a roupa veste o meu corpo");
//auditivo
strcpy(questionario[1].item_2, "O que me soa melhor");
strcpy(questionario[2].item_2, "O tom da voz da outra pessoa");
strcpy(questionario[3].item_2, "Pelo tom da minha voz");
strcpy(questionario[4].item_2, "Achar o volume e a sintonia ideais num sistema de som");
strcpy(questionario[5].item_2, "Se estou muito em sintonia com os sons dos ambientes");
//visual
strcpy(questionario[1].item_3, "O que me parece melhor");
strcpy(questionario[2].item_3, "Se eu posso ou não ver o argumento da outra pessoa");
strcpy(questionario[3].item_3, "Do modo como me visto e aparento");
strcpy(questionario[4].item_3, "Escolher as combinações de cores mais ricas e atraentes");
strcpy(questionario[5].item_3, "Eu respondo fortemente às cores e à aparência de uma sala");
//digital
strcpy(questionario[1].item_4, "Um estudo preciso e minucioso do assunto");
strcpy(questionario[2].item_4, "A lógica do argumento da outra pessoa");
strcpy(questionario[3].item_4, "Pelas palavras que escolho");
strcpy(questionario[4].item_4, "Selecionar o ponto mais relevante relativo a um assunto interessante");
strcpy(questionario[5].item_4, "Se sou muito capaz de raciocinar com fatos e dados novos\n");	
}

escreve_arquivo() //escrever a informacao das variaveis no arquivo QUESTIONARIO_1.TXT
{
	FILE *file2; //cria o arquivo questionario_1.txt
	file2 = fopen("QUESTIONARIO_1.TXT", "w");
	fprintf(file2, "NroFrase                                Frase                                C  Item_1                                                              A  Item_2                                                    V  Item_3                                                        D  Item_4\n");
	for (i=1;i<=349;i++) fprintf(file2, "=");
	for (i=1;i<=5;i++)
	{
	fprintf(file2, "\n%4d", questionario[i].NroFrase);
	fprintf(file2, "%68s", questionario[i].frase);
	fprintf(file2, "%6d  ", questionario[i].cinestesico);
	fprintf(file2, "%-68s", questionario[i].item_1);
	fprintf(file2, "%d  ", questionario[i].auditivo);
	fprintf(file2, "%-58s", questionario[i].item_2);
	fprintf(file2, "%d  ", questionario[i].visual);
	fprintf(file2, "%-62s", questionario[i].item_3);
	fprintf(file2, "%d  ", questionario[i].digital);
	fprintf(file2, "%s", questionario[i].item_4);
	}
	for (i=1;i<=349;i++) fprintf(file2, "=");		
	fclose(file2);
}

resultado(int porcA, int porcB, int porcC, int porcD, int maior) //imprimir os resultados do questionario no arquivo RESULTADO[...].txt
{
	FILE *result;
	result = fopen(nome_file, "a");
	char aux[100]="============================== PERFIL REPRESENTACIONAL DE ";
	int len = strlen(usuario);
	for (int i = 0, posicao = 0; i < len; i++, posicao++) 
	{
		usuario[i] = toupper(usuario[i]);
		usuario[i] = usuario[posicao];
	}
	strcat(aux, usuario);
	strcat(aux, " ==============================");
	len = strlen(aux);
	fprintf(result, "%s", aux);
	fprintf(result, "\n%d%c Cinestesico\t\t", porcA, 37);
	fprintf(result, "%d%c Auditivo\t\t", porcB, 37);
	fprintf(result, "%d%c Visual\t\t", porcC, 37);
	fprintf(result, "%d%c Digital\n", porcD, 37);
	
	for (int i=1;i<=len;i++) fprintf(result, "=");
	fprintf(result,"\n\n");
	fprintf(result,"Algumas  pessoas  captam  melhor  as  mensagens  do  mundo  exterior  através  da  audição,  são  aspessoas  chamadas auditivas.\n");
	fprintf(result,"Outras  pessoas  sentem  necessidade  de  perguntar  muito,  necessitam  de  muitas  informações  e  fatos.  Estas  são  as digitais.\n");
	fprintf(result,"As  cinestésicas  aprendem  melhor  por  meio  das  sensações  táteis,  como  o  tato,  a  temperatura, a  umidade,  as sensações internas e as emoções.\n");
	fprintf(result,"Já as pessoas visuais aprendem melhor quando se valendo da visão.\n\n");
	for (int i=1;i<=len;i++) fprintf(result, "=");
	
	fprintf(result,"\nSeu perfil é ");
	if (maior == porcA) { fprintf(result,"CINESTESICO"); }
	if (maior == porcB) { fprintf(result,"AUDITIVO"); }
	if (maior == porcC) { fprintf(result,"VISUAL"); }
	if (maior == porcD) { fprintf(result,"DIGITAL"); }
	fprintf(result,"\n");
	for (int i=1;i<=len;i++) fprintf(result, "=");
	fclose(result);
}

teste_master() //realiza o teste proposto
{
	int totalA=0, totalB=0, totalC=0, totalD=0, maior=0;
	
	for (i=1;i<=5;i++)
	{
		system("cls");
		printf("NAS FRASES A SEGUIR, PONTUE COM: \n");
		printf("4. A QUE MELHOR DESCREVE VOCÊ\n");
		printf("3. A PRÓXIMA MELHOR DESCRIÇÃO\n");
		printf("2. A PRÓXIMA MELHOR\n");
		printf("1. AQUELA QUE MENOS DESCREVE VOCÊ\n\n\n\n");
		printf("%i. %s\n", i, questionario[i].frase);
		printf("A) %s\n", questionario[i].item_1);
		printf("B) %s\n", questionario[i].item_2);
		printf("C) %s\n", questionario[i].item_3);
		printf("D) %s\n\n", questionario[i].item_4);
	
		/*------------------------------A = CINESTESICO-----------------------------------*/			
		inicioa:
		printf("[a]->");
		scanf("%d", &questionario[i].cinestesico);
		if (questionario[i].cinestesico != 1 && questionario[i].cinestesico != 2 && questionario[i].cinestesico != 3 && questionario[i].cinestesico != 4)
		{
			printf("OPÇÃO NÃO DISPONÍVEL!\n");
			goto inicioa;
		}
		else
		totalA = totalA + questionario[i].cinestesico;
		/*------------------------------B = AUDITTIVO-------------------------------------*/
		iniciob:
		printf("[b]->");
		scanf("%d", &questionario[i].auditivo);
		if (questionario[i].auditivo == questionario[i].cinestesico)
		{
			printf("OPÇÃO JÁ ESCOLHIDA!\n");
			goto iniciob;
		}
		else if (questionario[i].auditivo != 1 && questionario[i].auditivo != 2 && questionario[i].auditivo != 3 && questionario[i].auditivo != 4)
		{
			printf("OPÇÃO NÃO DISPONÍVEL!\n");
			goto iniciob;
		}
		else
		totalB = totalB + questionario[i].auditivo;
		/*------------------------------C = VISUAL----------------------------------------*/
		inicioc:
		printf("[c]->");
		scanf("%d", &questionario[i].visual);
		if (questionario[i].visual == questionario[i].cinestesico || questionario[i].visual == questionario[i].auditivo)
		{
			printf("OPÇÃO JÁ ESCOLHIDA!\n");
			goto inicioc;
		}
		else if (questionario[i].visual != 1 && questionario[i].visual != 2 && questionario[i].visual != 3 && questionario[i].visual != 4)
		{
			printf("OPÇÃO NÃO DISPONÍVEL!\n");
			goto inicioc;
		}
		else
		totalC = totalC + questionario[i].visual;
		/*------------------------------D = DIGITAL----------------------------------------*/				
		iniciod:
		printf("[d]->");	
		scanf("%d", &questionario[i].digital);
		if (questionario[i].digital == questionario[i].cinestesico || questionario[i].digital == questionario[i].auditivo || questionario[i].digital == questionario[i].visual)
		{
			printf("OPÇÃO JÁ ESCOLHIDA!\n");
			goto iniciod;
		}
		else if (questionario[i].digital != 1 && questionario[i].digital != 2 && questionario[i].digital != 3 && questionario[i].digital != 4)
		{
			printf("OPÇÃO NÃO DISPONÍVEL!\n");
			goto iniciod;
		}
		else
		totalD = totalD + questionario[i].digital;
	}
	
	int porcA = totalA*2, porcB = totalB * 2, porcC = totalC * 2, porcD = totalD * 2;//cria a variavel com a porcentagem dos sentidos
	
	if (porcA > maior) {maior = porcA;}
	if (porcB > maior) {maior = porcB;}
	if (porcC > maior) {maior = porcC;}
	if (porcD > maior) {maior = porcD;}
				
	resultado(porcA, porcB, porcC, porcD, maior);
}

master_room()//ambiente do administrador
{
	setlocale(LC_ALL,"");
								inicio:
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
	char teste = getch();
	printf("%c", teste);
	printf("\n");
	system("pause");
	
	switch(teste)
	{
		case '1': //cadastra o questionario e salvar as informacoes no arquivo .dat
			FILE *quest; //cria o arquivo .dat
			quest = fopen("TESTE_SISTEMA_REPRESENTACIONAL.DAT", "w");
			
			quest_base(); //puxa a funcao que cria os dados
			
			//imprimi a informação no arquivo .dat
			fprintf(quest, "NroFrase");
			fprintf(quest, "\t%d", questionario[1].NroFrase);
			fprintf(quest, "\t%d", questionario[2].NroFrase);
			fprintf(quest, "\t%d", questionario[3].NroFrase);
			fprintf(quest, "\t%d", questionario[4].NroFrase);
			fprintf(quest, "\t%d\n", questionario[5].NroFrase);
			fprintf(quest, "Frase");
			fprintf(quest, "\t%s", questionario[1].frase);
			fprintf(quest, "\t%s", questionario[2].frase);
			fprintf(quest, "\t%s", questionario[3].frase);
			fprintf(quest, "\t%s", questionario[4].frase);
			fprintf(quest, "\t%s\n", questionario[5].frase);
			fprintf(quest, "Cinestesico");
			fprintf(quest, "\t%d", questionario[1].cinestesico);
			fprintf(quest, "\t%d", questionario[2].cinestesico);
			fprintf(quest, "\t%d", questionario[3].cinestesico);
			fprintf(quest, "\t%d", questionario[4].cinestesico);
			fprintf(quest, "\t%d\n", questionario[5].cinestesico);
			fprintf(quest, "Item_1");
			fprintf(quest, "\t%s", questionario[1].item_1);
			fprintf(quest, "\t%s", questionario[2].item_1);
			fprintf(quest, "\t%s", questionario[3].item_1);
			fprintf(quest, "\t%s", questionario[4].item_1);
			fprintf(quest, "\t%s\n", questionario[5].item_1);
			fprintf(quest, "Auditivo");
			fprintf(quest, "\t%d", questionario[1].auditivo);
			fprintf(quest, "\t%d", questionario[2].auditivo);
			fprintf(quest, "\t%d", questionario[3].auditivo);
			fprintf(quest, "\t%d", questionario[4].auditivo);
			fprintf(quest, "\t%d\n", questionario[5].auditivo);
			fprintf(quest, "Item_2");
			fprintf(quest, "\t%s", questionario[1].item_2);
			fprintf(quest, "\t%s", questionario[2].item_2);
			fprintf(quest, "\t%s", questionario[3].item_2);
			fprintf(quest, "\t%s", questionario[4].item_2);
			fprintf(quest, "\t%s\n", questionario[5].item_2);
			fprintf(quest, "Visual");
			fprintf(quest, "\t%d", questionario[1].visual);
			fprintf(quest, "\t%d", questionario[2].visual);
			fprintf(quest, "\t%d", questionario[3].visual);
			fprintf(quest, "\t%d", questionario[4].visual);
			fprintf(quest, "\t%d\n", questionario[5].visual);
			fprintf(quest, "Item_3");
			fprintf(quest, "\t%s", questionario[1].item_3);
			fprintf(quest, "\t%s", questionario[2].item_3);
			fprintf(quest, "\t%s", questionario[3].item_3);
			fprintf(quest, "\t%s", questionario[4].item_3);
			fprintf(quest, "\t%s\n", questionario[5].item_3);		
			fprintf(quest, "Digital");
			fprintf(quest, "\t%d", questionario[1].digital);
			fprintf(quest, "\t%d", questionario[2].digital);
			fprintf(quest, "\t%d", questionario[3].digital);
			fprintf(quest, "\t%d", questionario[4].digital);
			fprintf(quest, "\t%d\n", questionario[5].digital);
			fprintf(quest, "Item_3");
			fprintf(quest, "\t%s", questionario[1].item_4);
			fprintf(quest, "\t%s", questionario[2].item_4);
			fprintf(quest, "\t%s", questionario[3].item_4);
			fprintf(quest, "\t%s", questionario[4].item_4);
			fprintf(quest, "\t%s\n", questionario[5].item_4);
			fclose(quest);
			system("cls");
			printf("QUESTIONÁRIO CADASTRADO!!\n");
			system("pause");
			goto inicio;
		break;
		
		case '2'://vizualiza questionario, escreve o conteudo do arquivo .dat em um arquivo questionario_1.txt
			escreve_arquivo(); //printar a informacao das variaveis no arquivo QUESTIONARIO_1.TXT
			system("QUESTIONARIO_1.TXT");
			goto inicio;
		break;
		
		case '3':
			teste_master();
			system(nome_file);
			system("pause");
			goto inicio;
		break;
		
		case '4':
			FILE *sobre;
			sobre = fopen("REFERENCIAL_TEORICO.TXT", "r");
			if (sobre == NULL) 
			{
				system("cls");
				printf("======================================================================\n");
				printf("               ERRO! O arquivo não foi encontrado!                    \n");
				printf("Encontre o arquivo 'REFERENCIAL_TEORICO.TXT' encontrado no repositório\n");
				printf("          https://github.com/LuanGrod/projeto_lg1a1.git               \n");
				printf("======================================================================\n");
				system("pause");
			}	
			else system("REFERENCIAL_TEORICO.TXT");
			fclose(sobre);
			goto inicio;
		break;
		
		case 'F':
			fim_programa();
		break;
		
		case 'f':
			fim_programa();
		break;
		
		default:
			system("cls");
			printf("ERRO AO ESCOLHER!\n");
			system("pause");
			goto inicio;
	}	
}

cria_arquivo()//cria o arquivo onde ficarao os resultados do questionario respondido
{
	//nomeia o arquivo
	strcat(nome_file, usuario);
	int len = strlen(nome_file);
	for (int i = 0, posicao = 0; i < len; i++, posicao++) 
	{
		if (nome_file[posicao]==' ') nome_file[posicao] = '_';
		nome_file[i] = toupper(nome_file[i]);
		nome_file[i] = nome_file[posicao];
	}
	strcat(nome_file, "_");
	strcat(nome_file, prontuario);
	//cria o arquivo .txt	
	FILE *arquivo;
	strcat(nome_file, ".txt");
	arquivo = fopen(nome_file, "w");
	fclose(arquivo);
}

login()//realiza o login do usuario
{
printf("DIGITE SEU NOME.................: ");
scanf("%[^\n]s", usuario);
printf("DIGITE SEU PRONTUÁRIO...........: ");
scanf("%s", &prontuario);

int i = stricmp (usuario, "MASTER");

if (i == 0) 
{
cria_arquivo();
master_room();
}
else
{
cria_arquivo();
quest_base();	
teste_master();	
system(nome_file);
}
}

main ()
{
setlocale(LC_ALL,"");
login();
}
	

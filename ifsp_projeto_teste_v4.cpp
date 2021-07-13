#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <Windows.h>
using namespace std;

char usuario[100], prontuario[10], nome_file[100]="RESULTADO ";

fim_programa()
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


master_room()
{
	inicio:
	char teste;

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
		case '1':
			printf("CADASTRA O BAGULHO AAAAAAAAA");
		break;
		
		case '2':
			printf("VISUALIZA TUDOOOOOOOO");
		break;
		
		case '3':
			printf("REALIZA O TESTE AE PFV");
		break;
		
		case '4':
			FILE *sobre;
			sobre = fopen("REFERENCIAL_TEORICO.TXT", "r");
			if (sobre == NULL) printf("ERRO! O arquivo não foi aberto!\n");
			system("REFERENCIAL_TEORICO.TXT");
			fclose(sobre);
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


cria_arquivo()
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

}


login()
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
}

return 0;	
}


main ()
{
login();





return 0;	
}
	

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
using namespace std;

char usuario[100], prontuario[10], nome_file[100]="RESULTADO ";

master_room()
{
	char c;

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

	scanf("%c", &c);
	
	printf("%c\n", c);
	

	switch(c)
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
			printf("SOBRE O TESTE AAAAAAAAAA");
		break;
		
		case 'F':
			printf("fim");
			return 0;
		break;
		
		case 'f':
			printf("fim");
			return 0;
		break;
		
		default:
			printf("TU TINHA UM OBJETIVO\nBURRAO VOCE EM");

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
		printf("%s", nome_file);
		arquivo = fopen(nome_file, "w");
		fclose(arquivo);
//printf("O nome do arquivo sera: %s\n", nome_file);
}


login()
{
int i;

setlocale(LC_ALL,"");
	
printf("DIGITE SEU NOME: ");
scanf("%[^\n]s", usuario);
	
printf("DIGITE SEU PRONTUÁRIO: ");
scanf("%s", &prontuario);

i = stricmp (usuario, "MASTER");
if (i == 0) master_room();
else
cria_arquivo();

return 0;	
}



main ()
{
login();



return 0;	
}
	

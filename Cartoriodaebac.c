#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //bilbioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o  
#include <string.h> //biblioteca de gerenciamento das strings

int registro() //Fun��o respons�vel por registrar os usu�rios no sistema
{
	//in�cio da cria��o das vari�veis/strings
	char arquivo[40]; 
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o das vari�vies
	
	setlocale(LC_ALL, "Portuguese"); //Define o idioma
	
	printf("Digite o CPF a ser registrado: \n\n"); //coletando informa��es do usu�rio
	scanf("%s", cpf); //%s refere-se �s strings
	printf("\n");
	strcpy(arquivo, cpf); //copia os par�metros das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file,cpf); //armazerno o valor da vari�vel
	fclose(file); //fecho o arquivo
	
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);

	printf("Digite o nome do titular do CPF: \n\n");
	scanf("%s", nome);
	printf("\n");
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome do titular do CPF: \n\n");
	scanf("%s", sobrenome);
	printf("\n");
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo do titular do CPF: \n\n");
	scanf("%s", cargo);
	printf("\n");
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	printf("Usu�rio cadastrado! \n\n ");
	system("pause");
	
	}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Define o idioma
		
	char cpf[40];
	char consulta[200];
	
	printf("Digite o n�mero do CPF a ser consultado:\n\n");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Usu�rio n�o cadastrado!\n\n");
	}
	
	while(fgets(consulta, 200, file) != NULL)
	
	{
	printf("\nEstas s�o as informa��es do usu�rio: \n\n");
	printf("%s", consulta);
	printf("\n\n");	
	}
	fclose(file); // Fecha o arquivo ap�s a leitura
	system("pause");
	
}

 void apagar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio que gostaria de apagar: \n\n");
	scanf("%s",cpf);
	
 	if (remove(cpf) == 0) 
	{
        printf("O usu�rio foi apagado com sucesso!\n\n");
        system("pause");
   	} 
	else
	{
        printf("O usu�rio n�o foi encontrado no banco de dados!\n\n");
        system("pause");
    }
	
		
}

int main() 
{
	int opcao=0;
	
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	system("cls");
	
	setlocale(LC_ALL, "Portuguese"); //Define o idioma
	
		printf("### Bem-vindo ao Cart�rio da EBAC ### \n\n"); //In�cio do menu
		printf("Escolha a op��o desejada: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Apagar nomes\n\n");
		printf("Op��o: ");//Fim do menu
	
	scanf("%d", &opcao);//Armazena a op��o do usu�rio
	
		switch(opcao)
		{
		case 1:
		registro ();
		break;
		
		case 2:
		consulta();
		break;
		
		case 3:
		apagar();
		break;	
		
		default:
		printf("Esta op��o n�o est� dispon�vel. \n");
		system("pause");
		break; //Fim da sele��o
		}
	}
}


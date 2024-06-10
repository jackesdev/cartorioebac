#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //bilbioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região  
#include <string.h> //biblioteca de gerenciamento das strings

int registro() //Função responsável por registrar os usuários no sistema
{
	//início da criação das variáveis/strings
	char arquivo[40]; 
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação das variávies
	
	setlocale(LC_ALL, "Portuguese"); //Define o idioma
	
	printf("Digite o CPF a ser registrado: \n\n"); //coletando informações do usuário
	scanf("%s", cpf); //%s refere-se às strings
	printf("\n");
	strcpy(arquivo, cpf); //copia os parâmetros das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file,cpf); //armazerno o valor da variável
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
	
	printf("Usuário cadastrado! \n\n ");
	system("pause");
	
	}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Define o idioma
		
	char cpf[40];
	char consulta[200];
	
	printf("Digite o número do CPF a ser consultado:\n\n");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Usuário não cadastrado!\n\n");
	}
	
	while(fgets(consulta, 200, file) != NULL)
	
	{
	printf("\nEstas são as informações do usuário: \n\n");
	printf("%s", consulta);
	printf("\n\n");	
	}
	fclose(file); // Fecha o arquivo após a leitura
	system("pause");
	
}

 void apagar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário que gostaria de apagar: \n\n");
	scanf("%s",cpf);
	
 	if (remove(cpf) == 0) 
	{
        printf("O usuário foi apagado com sucesso!\n\n");
        system("pause");
   	} 
	else
	{
        printf("O usuário não foi encontrado no banco de dados!\n\n");
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
	
		printf("### Bem-vindo ao Cartório da EBAC ### \n\n"); //Início do menu
		printf("Escolha a opção desejada: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Apagar nomes\n\n");
		printf("Opção: ");//Fim do menu
	
	scanf("%d", &opcao);//Armazena a opção do usuário
	
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
		printf("Esta opção não está disponível. \n");
		system("pause");
		break; //Fim da seleção
		}
	}
}


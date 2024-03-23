#include <stdio.h>  //biblioteca de comunica��o com o usu�rio
#include <stdlib.h>  //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h>  //biblioteca de aloca��es de texto por regi�o
#include <string.h>  //biblioteca respons�vel pelas strings

int registro() //Fun��o respons�vel por cadastrar usu�rios no sistema
{
	char arquivo[40];  //cria��o de vari�veis/strings
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];  //fim da cria��o de vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado: ");  //coletando informa��o do usu�rio
	scanf("%s",cpf);  //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	
	file = fopen(arquivo, "w"); //cria o arquivo //"w" significa escrever
	fprintf(file, "CPF: ");
	fprintf(file,cpf); //salvando o valor da variavel
	fclose(file); //fecha o arquivo
	
	file= fopen(arquivo, "a");  //"a" significa atualizar
	fprintf(file,"\nNome: ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file= fopen(arquivo, "a");
	fprintf(file,"\nSobrenome: ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\nCargo: ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	printf("\n");
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fprintf(file, "\n\n");
	fclose(file);
	
	system("pause");
}

int consulta()
{
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	printf("\nEssas s�o as informa�oes do usu�rio: \n\n");
	
	if(file == NULL)
	{
		printf("Esse usu�rio n�o foi cadastrado.\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("%s", conteudo);
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	int certeza=0;
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	printf("\nTem certeza que deseja deletar esse usu�rio?");
	printf("\n\n\tDigite 1 para sim");
	printf("\n\tDigite 2 para n�o\n\n");
	printf("Op��o: ");
	
	scanf("%d", &certeza);
	
	FILE *file;
	file = fopen(cpf, "r");  //r para ler o arquivo
	fclose(file);
	
	if(certeza==1)
	{
		if(file == NULL)
		{
			printf("\nO usu�rio j� foi deletado ou n�o se encontra no sistema.\n\n");
			system("pause");
			return 0;
		}
		printf("\nO usu�rio foi deletado com sucesso.\n\n");
		remove(cpf);
		system("pause");
	}	
	if(certeza>=2 || certeza<=0)
	{
		printf("\nO usu�rio N�O foi deletado. Voltando ao menu.\n\n");
		system("pause");
	}	
}

int main()
{
	int opcao=0; //definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem e acentos
	
		printf("### Cart�rio da EBAC ###\n\n"); //in�cio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Op��o: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
		system("cls"); //comando que limpa a tela ap�s a sele��o
	
		switch(opcao)  //in�cio da sele��o do menu
		{
			case 1:
			registro();  //chamada de fun��o
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel.\n\n");
			system("pause");
			break;
		}	//fim da sele��o
	}
}

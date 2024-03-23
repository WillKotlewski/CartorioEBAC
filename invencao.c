#include <stdio.h>  //biblioteca de comunicação com o usuário
#include <stdlib.h>  //biblioteca de alocação de espaço em memória
#include <locale.h>  //biblioteca de alocações de texto por região
#include <string.h>  //biblioteca responsável pelas strings

int registro() //Função responsável por cadastrar usuários no sistema
{
	char arquivo[40];  //criação de variáveis/strings
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];  //fim da criação de variáveis/strings
	
	printf("Digite o CPF a ser cadastrado: ");  //coletando informação do usuário
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
	
	printf("\nEssas são as informaçoes do usuário: \n\n");
	
	if(file == NULL)
	{
		printf("Esse usuário não foi cadastrado.\n\n");
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
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	printf("\nTem certeza que deseja deletar esse usuário?");
	printf("\n\n\tDigite 1 para sim");
	printf("\n\tDigite 2 para não\n\n");
	printf("Opção: ");
	
	scanf("%d", &certeza);
	
	FILE *file;
	file = fopen(cpf, "r");  //r para ler o arquivo
	fclose(file);
	
	if(certeza==1)
	{
		if(file == NULL)
		{
			printf("\nO usuário já foi deletado ou não se encontra no sistema.\n\n");
			system("pause");
			return 0;
		}
		printf("\nO usuário foi deletado com sucesso.\n\n");
		remove(cpf);
		system("pause");
	}	
	if(certeza>=2 || certeza<=0)
	{
		printf("\nO usuário NÃO foi deletado. Voltando ao menu.\n\n");
		system("pause");
	}	
}

int main()
{
	int opcao=0; //definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem e acentos
	
		printf("### Cartório da EBAC ###\n\n"); //início do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Opção: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuário
	
		system("cls"); //comando que limpa a tela após a seleção
	
		switch(opcao)  //início da seleção do menu
		{
			case 1:
			registro();  //chamada de função
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa opção não está disponível.\n\n");
			system("pause");
			break;
		}	//fim da seleção
	}
}

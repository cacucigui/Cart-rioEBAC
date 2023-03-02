#include <stdio.h> //Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //Biblioteca de aloca��o de texto por regi�o
#include <string.h> //Biblioteca respons�vel por cuidar das string's

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//In�cio da cria��o de vari�veis/string's
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final das vari�veis/string's criadas
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se as string's
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string's
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // abre o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salvo o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o "a" significa atualizar
	fprintf(file,","); //Ir� colocar uma v�rgula ap�s escrever o cpf
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s",nome); //%s refere-se as string"S
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o "a" significa atualizar
	fprintf(file,nome); //Salva o valor da vari�vel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o "a" significa atualizar
	fprintf(file,","); //Ir� escrever a v�rgula ap�s o nome do usu�rio
	fclose(file); //Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s",sobrenome); //%s refere-se as string's
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o "a" significa atualizar
	fprintf(file,sobrenome); //Salva o valor da vari�vel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o "a" significa atualizar
	fprintf(file,","); //Ir� colocar uma v�rgula ap�s o sobrenome do usu�rio
	fclose(file); //Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s",cargo); //%s refere-se as string"s
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o "a" significa atualizar
	fprintf(file,cargo); //Salva o valor da vari�vel
	fclose(file); //Fecha o arquivo
	
    system("pause"); 
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem

	//In�cio da cria��o das vari�veis/string's
	char cpf[40];
	char conteudo[200];
	//Fim das vari�veis/string's criadas
	
	printf("Digite o CPF a ser consultado: "); //Coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se as string's/vari�veis
		
	FILE *file;
	file = fopen(cpf, "r"); //"r" = reaad
	
	if(file == NULL) //Caso o arquivo n�o exista
	{
		printf("\nN�o foi poss�vel abrir o arquivo, n�o localizado!\n\n"); //Mensagem mostrando que o usu�rio n�o existe/n�o foi localizado
	}
	
	while(fgets(conteudo, 100, file) != NULL)
	{
	printf("\nEssas s�o as informa��es do usu�rio: "); //Mostra as informa��es do usu�rio
	printf("%s", conteudo); //%s refere-se as string's/vari�veis
	printf("\n\n"); //Serve apenas para deixar um espa�o ap�s as informa��es
	}
	
	system("pause");
}

int apagar()
{
	setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem
	
	//In�cio da vari�vel/string
	char cpf[40];
	//Fim da vari�vel/string
	
	printf("\nDigite o CPF do usu�rio a ser apagado: "); //Coletando informa��o do usu�rio
	scanf("%s",cpf); //%s refere-se as vari�veis/string's
	
	FILE *file; //Cria o arquivo
	file = fopen(cpf, "r"); //Abre o arquivo e o "r" significa ler
	
	if(file == NULL) //Caso o arquivo n�o exista
	{
		printf("\nO usu�rio n�o se encontra no sistema!"); //Caso o usu�rio n�o exista/n�o foi encontrado ira aparecer essa mensagem
		printf("\n");
		system ("pause");
		fclose(file);
	}
	else 
	{
		fclose(file);
		remove(cpf);
		printf("\nUsu�rio apagado com sucesso!\n");
		printf("\n");
		system("pause");
	}
}

int main()
{
	int opcao=0; //Definindo as vari�veis 
	int x=1;
	
	for(x=1;x=1;)
	{	
		system("cls"); //Respons�vel por limpar a tela
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //In�cio do menu
		printf("Porfavor, marque a op��o que deseja no menu:\n\n");
		printf("\t1- Registrar nomes\n\n");
		printf("\t2- Consultar nomes\n\n");
		printf("\t3- Apagar nomes\n\n");
		printf("Op��o: "); //Fim do menu

		scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
		system("cls"); //Respons�vel por limpar a tela
	
		switch(opcao) //In�cio da sele��o do menu
		{
			case 1:
			registro(); //Chamada de fun��es
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			apagar();
			break;
			
			default: 
			printf("Essa op��o n�o est� dispon�vel!\n\n"); 
			system("pause");
			break;
		}
	}	
}

#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de alocação de espaço em memória
#include <locale.h> //Biblioteca de alocação de texto por região
#include <string.h> //Biblioteca responsável por cuidar das string's

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//Início da criação de variáveis/string's
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final das variáveis/string's criadas
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", cpf); //%s refere-se as string's
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string's
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // abre o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salvo o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o "a" significa atualizar
	fprintf(file,","); //Irá colocar uma vírgula após escrever o cpf
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s",nome); //%s refere-se as string"S
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o "a" significa atualizar
	fprintf(file,nome); //Salva o valor da variável
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o "a" significa atualizar
	fprintf(file,","); //Irá escrever a vírgula após o nome do usuário
	fclose(file); //Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s",sobrenome); //%s refere-se as string's
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o "a" significa atualizar
	fprintf(file,sobrenome); //Salva o valor da variável
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o "a" significa atualizar
	fprintf(file,","); //Irá colocar uma vírgula após o sobrenome do usuário
	fclose(file); //Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s",cargo); //%s refere-se as string"s
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o "a" significa atualizar
	fprintf(file,cargo); //Salva o valor da variável
	fclose(file); //Fecha o arquivo
	
    system("pause"); 
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem

	//Início da criação das variáveis/string's
	char cpf[40];
	char conteudo[200];
	//Fim das variáveis/string's criadas
	
	printf("Digite o CPF a ser consultado: "); //Coletando informação do usuário
	scanf("%s", cpf); //%s refere-se as string's/variáveis
		
	FILE *file;
	file = fopen(cpf, "r"); //"r" = reaad
	
	if(file == NULL) //Caso o arquivo não exista
	{
		printf("\nNão foi possível abrir o arquivo, não localizado!\n\n"); //Mensagem mostrando que o usuário não existe/não foi localizado
	}
	
	while(fgets(conteudo, 100, file) != NULL)
	{
	printf("\nEssas são as informações do usuário: "); //Mostra as informações do usuário
	printf("%s", conteudo); //%s refere-se as string's/variáveis
	printf("\n\n"); //Serve apenas para deixar um espaço após as informações
	}
	
	system("pause");
}

int apagar()
{
	setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem
	
	//Início da variável/string
	char cpf[40];
	//Fim da variável/string
	
	printf("\nDigite o CPF do usuário a ser apagado: "); //Coletando informação do usuário
	scanf("%s",cpf); //%s refere-se as variáveis/string's
	
	FILE *file; //Cria o arquivo
	file = fopen(cpf, "r"); //Abre o arquivo e o "r" significa ler
	
	if(file == NULL) //Caso o arquivo não exista
	{
		printf("\nO usuário não se encontra no sistema!"); //Caso o usuário não exista/não foi encontrado ira aparecer essa mensagem
		printf("\n");
		system ("pause");
		fclose(file);
	}
	else 
	{
		fclose(file);
		remove(cpf);
		printf("\nUsuário apagado com sucesso!\n");
		printf("\n");
		system("pause");
	}
}

int main()
{
	int opcao=0; //Definindo as variáveis 
	int x=1;
	
	for(x=1;x=1;)
	{	
		system("cls"); //Responsável por limpar a tela
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //Início do menu
		printf("Porfavor, marque a opção que deseja no menu:\n\n");
		printf("\t1- Registrar nomes\n\n");
		printf("\t2- Consultar nomes\n\n");
		printf("\t3- Apagar nomes\n\n");
		printf("Opção: "); //Fim do menu

		scanf("%d", &opcao); //Armazenando a escolha do usuário
	
		system("cls"); //Responsável por limpar a tela
	
		switch(opcao) //Início da seleção do menu
		{
			case 1:
			registro(); //Chamada de funções
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			apagar();
			break;
			
			default: 
			printf("Essa opção não está disponível!\n\n"); 
			system("pause");
			break;
		}
	}	
}

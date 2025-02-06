#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() // Função responsável por cadastrar os usários no sistema
{
	//inicio de criação de string (conj. de variáveis)
	char arquivo [50];
	char cpf[40];
	char nome [50];
	char sobrenome [50];
	char cargo [40];
	// fim string
	
	printf("Digite o CPF a ser cadastrado: "); // Mensagem usuário para coletar info
	scanf("%s", cpf); //refere-se às strings
	
	strcpy (arquivo, cpf); // Variavél responsável por criar os valores das strig cpf p/ arquivo
	
	FILE *file; // cria o arquivo no bd
	file = fopen (arquivo, "w"); // explica o arquivo a ser criado
	fprintf (file, cpf); // salva o valor da variavel no arquivo
	fclose (file); // fecha o arquivo
	
	file = fopen (arquivo, "a"); // a = atualizar o arquivo
	fprintf (file, ", ");
	fclose (file);
	
	printf("Digite o Nome a ser cadastrado: "); // Mensagem usuário 
	scanf ("%s", nome);
	
	file = fopen (arquivo, "a");
	fprintf (file, nome);
	fclose (file);
	
	file = fopen (arquivo, "a"); 
	fprintf (file, ", ");
	fclose (file);
	
	printf ("Digite o Sobrenome a ser cadastrado: ");	// Mensagem usuário
	scanf ("%s", sobrenome);
	
	file = fopen (arquivo, "a");
	fprintf (file, sobrenome);
	fclose (file);
	
	file = fopen (arquivo, "a"); 
	fprintf (file, ", ");
	fclose (file);
	
	printf ("Digite o Cargo a ser cadastrado: ");
	scanf ("%s", cargo);
	
	file = fopen (arquivo, "a");
	fprintf (file, cargo);
	fclose (file);
	
	system("pause");
	
}

int consulta() //Função responsável por consultar os usários no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[50];
	char conteudo[200];
	
	printf ("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen (cpf, "r"); // r = ler 
	
	if (file == NULL)
	{
		printf ("Arquivo não localizado. \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf ("\nEssas são as informações do usuário: ");
		printf ("%s", conteudo);
		printf ("\n\n");
		
	}
	
	system("pause");
}

int deletar() //Função responsável por deletar os usários no sistema
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado:");
	scanf("%s", cpf);
		
	remove (cpf); // responsável por remover cadastro do banco de dados
		
	FILE *file;
	file = fopen(cpf, "r");
		
	if (file == NULL) 
	{
		printf("Usuário não encontrado. \n");
		system("pause");
	}

if (file != NULL) 
	{
		printf("Usuário deletado. \n");
		system("pause");
	}

}


int main ()
{
	int opcao=0; //Definindo Variáveis
	int x=1; //Definindo variável do FOR
	
	for(x=1;x=1;)
	{
	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cartório da EBAC ## \n\n"); //Inicio do menu
		printf("Escolha a opção desejada: \n\n");
		printf("\t1 - Registrar usuário \n");
		printf("\t2 - Consultar usuário\n");
		printf("\t3 - Deletar usuário\n\n");
		printf("Opção:"); //Final do Menu
	
		scanf("%d", &opcao); //Armazendo a escolha do usuário
	
		system("cls"); // responsável por limpar a tela
		
		switch(opcao) //Inicio seleção
		{
			case 1:
			registro(); // chamada da função registro
			break;
			
			case 2:
			consulta(); // chamada da função consulta
			break;
			
			case 3:
			deletar(); // chamada da função deletar
			break;
			
			default:
			printf("Opção não disponível :(\n");
			system("pause");
			break;	
		} // Fim da Seleção
	
	
		//criador
		printf("\n\n Esse software é da Marcelly Tadakuma \n");
	}
}

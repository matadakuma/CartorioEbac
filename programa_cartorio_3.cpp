#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() // Fun��o respons�vel por cadastrar os us�rios no sistema
{
	//inicio de cria��o de string (conj. de vari�veis)
	char arquivo [50];
	char cpf[40];
	char nome [50];
	char sobrenome [50];
	char cargo [40];
	// fim string
	
	printf("Digite o CPF a ser cadastrado: "); // Mensagem usu�rio para coletar info
	scanf("%s", cpf); //refere-se �s strings
	
	strcpy (arquivo, cpf); // Variav�l respons�vel por criar os valores das strig cpf p/ arquivo
	
	FILE *file; // cria o arquivo no bd
	file = fopen (arquivo, "w"); // explica o arquivo a ser criado
	fprintf (file, cpf); // salva o valor da variavel no arquivo
	fclose (file); // fecha o arquivo
	
	file = fopen (arquivo, "a"); // a = atualizar o arquivo
	fprintf (file, ", ");
	fclose (file);
	
	printf("Digite o Nome a ser cadastrado: "); // Mensagem usu�rio 
	scanf ("%s", nome);
	
	file = fopen (arquivo, "a");
	fprintf (file, nome);
	fclose (file);
	
	file = fopen (arquivo, "a"); 
	fprintf (file, ", ");
	fclose (file);
	
	printf ("Digite o Sobrenome a ser cadastrado: ");	// Mensagem usu�rio
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

int consulta() //Fun��o respons�vel por consultar os us�rios no sistema
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
		printf ("Arquivo n�o localizado. \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf ("\nEssas s�o as informa��es do usu�rio: ");
		printf ("%s", conteudo);
		printf ("\n\n");
		
	}
	
	system("pause");
}

int deletar() //Fun��o respons�vel por deletar os us�rios no sistema
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado:");
	scanf("%s", cpf);
		
	remove (cpf); // respons�vel por remover cadastro do banco de dados
		
	FILE *file;
	file = fopen(cpf, "r");
		
	if (file == NULL) 
	{
		printf("Usu�rio n�o encontrado. \n");
		system("pause");
	}

if (file != NULL) 
	{
		printf("Usu�rio deletado. \n");
		system("pause");
	}

}


int main ()
{
	int opcao=0; //Definindo Vari�veis
	int x=1; //Definindo vari�vel do FOR
	
	for(x=1;x=1;)
	{
	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cart�rio da EBAC ## \n\n"); //Inicio do menu
		printf("Escolha a op��o desejada: \n\n");
		printf("\t1 - Registrar usu�rio \n");
		printf("\t2 - Consultar usu�rio\n");
		printf("\t3 - Deletar usu�rio\n\n");
		printf("Op��o:"); //Final do Menu
	
		scanf("%d", &opcao); //Armazendo a escolha do usu�rio
	
		system("cls"); // respons�vel por limpar a tela
		
		switch(opcao) //Inicio sele��o
		{
			case 1:
			registro(); // chamada da fun��o registro
			break;
			
			case 2:
			consulta(); // chamada da fun��o consulta
			break;
			
			case 3:
			deletar(); // chamada da fun��o deletar
			break;
			
			default:
			printf("Op��o n�o dispon�vel :(\n");
			system("pause");
			break;	
		} // Fim da Sele��o
	
	
		//criador
		printf("\n\n Esse software � da Marcelly Tadakuma \n");
	}
}

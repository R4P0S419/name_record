#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca de string

int registro(){//fun��o de registro

    int escolha=0;
	
	setlocale(LC_ALL, "Portuguese");
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);//%s = strings
	
	strcpy(arquivo, cpf);// variavei char/string copiar outra variavel
	
	FILE *file; //criar arquivos
	file = fopen(arquivo, "w"); //criar arquivos
	fprintf(file,cpf);//salvar o valor da varievel no arquivo
	fclose(file);//fechar o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");//coletando nome do usuario
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");// "a" de atualizar, "r" ler ,"w" escrever
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");//coletando sobrenome do usuario
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Selecione o cargo desejado: \n");
	printf("\t1 - aluno\n ");
	printf("\t2 - professor\n ");
	printf("\t3 - visitante\n: ");
	printf("Op��o: ");
	scanf("%d", &escolha);//%d = double
	
	switch(escolha)
		{
			case 1:
			file = fopen(arquivo, "a");
			fprintf(file,"Aulo");
			fclose(file);
			break;
			
			case 2:
			file = fopen(arquivo, "a");
			fprintf(file,"Professor");
			fclose(file);
			break;
			
			case 3:
			file = fopen(arquivo, "a");
			fprintf(file,"Visitante");
			fclose(file);
			break;
			
			default:
			printf("Esta op��o n�o existe, por favor escolha uma op��o valida\n");
			system("pause");
			break;
		}
		
	
	
	system("pause");
}
int consulta(){//fun��o de consulta
	
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");//requisi��o de cpf para consulta
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)//resposta caso nao encontre as informa��es
	{
		printf("N�o foi possivel encontrar o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)//repeti��o ENQUANTO o valor nao for nulo
	{
		printf("\nEssas s�o as informa��es do usuario, ");
		printf("%s", conteudo);//informa�oes mostradas para o usuario
		printf("\n\n");
	}
	
	
	system("pause");
}
int deletar(){//fun��o de deletar 

	//fazer teste e primoramentos nessa parte
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	
	printf("Digite o CPF do usuario a ser deletado: ");//requisi�ao de cpf
	scanf("%s",cpf);
	
	remove(cpf);//metodo de remo��o
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL){
		printf("Esse usuario nao foi encontrado!.\n");//caso o cpf digitado for nulo esse sera o resultado
	}

	system("pause");
}

int main () //fun��o principal
	{
	int opcao=0; //Definindo variaveis	
	int laco=1; //inicio da repeti��o
	
	for(laco=1;laco=1;)
	{
	
		system("cls");//limpar a tela
	
		setlocale(LC_ALL, "Portuguese"); //linha para ativar a regi�io de interesse
	
		printf("### Tela de cadastro da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n"); 
		printf("\t1 - Cadastrar usuario\n");
		printf("\t2 - Consultar usuario\n");
		printf("\t3 - Deletar usuario\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: "); //fim do menu
		scanf("%d", &opcao);  //armazenando a escolha do usuario
	
		system("cls"); //Limpar a tela depois de uma escolha do usuario
		
		switch(opcao) //inicio do metodo switch case
		{
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema <3\n");
			return 0;//retorn 0 pode ser utilizado para fechar o sistema...
			break;
			
			default:
			printf("Esta op��o n�o existe, por favor escolha uma op��o valida\n");
			system("pause");
			break;
		}//finaL do switch case
	
	}
}

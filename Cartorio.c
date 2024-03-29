#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca de string

int registro(){//fun��o de registro

	system("cls");

	int dicida=0;

    int escolha=0;
	
	setlocale(LC_ALL, "Portuguese");
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[100];
	
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
	printf("\t3 - visitante\n ");
	printf("\t4 - Engenheiro de QA\n ");
	printf("\t5 - Desenvolvedor FullStack Python\n ");
	printf("\t6 - Desenvolvedor FullStack Java\n ");
	printf("\t7 - Cientista de dados\n ");
	printf("\t8 - Analista de dados\n ");
	printf("Op��o: ");
	scanf("%d", &escolha);//%d = double
	
	switch(escolha)
		{
			case 1:
			file = fopen(arquivo, "a");
			fprintf(file,"Aluno");
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
			
			case 4:
			file = fopen(arquivo, "a");
			fprintf(file,"engenheiroQA");
			fclose(file);
			break;
			
			case 5:
			file = fopen(arquivo, "a");
			fprintf(file,"devfullstackpython");
			fclose(file);
			break;
			
			case 6:
			file = fopen(arquivo, "a");
			fprintf(file,"devfullstackjava");
			fclose(file);
			break;
			
			case 7:
			file = fopen(arquivo, "a");
			fprintf(file,"cientistadedados");
			fclose(file);
			break;
			
			case 8:
			file = fopen(arquivo, "a");
			fprintf(file,"analistadedados");
			fclose(file);
			break;
			
			default:
			printf("Esta op��o n�o existe, por favor escolha uma op��o valida\n");
			system("pause");
			break;
		}
		
	system("cls");
		
	printf("Deseja registrar mais usuarios? \n\n");
	printf("1 - sim. \n");
	printf("2 - n�o. \n");
	printf("Op��o: ");
	scanf("%d", &dicida);	
		
	switch(dicida)
	{
		case 1:
		registro();
		break;
		
		case 2:
		menu();
		break;
		
		default:
		printf("Esta op��o n�o existe, por favor escolha uma op��o valida\n");
		system("pause");
		break;
	}
	system("pause");	
	

}
int consulta(){//fun��o de consulta
	system("cls");

	int dicide=0;
	
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[300];
	
	system("cls");
	
	printf("Digite o CPF a ser consultado: ");//requisi��o de cpf para consulta
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)//resposta caso nao encontre as informa��es
	{
		printf("N�o foi possivel encontrar o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 300, file) != NULL)//repeti��o ENQUANTO o valor nao for nulo
	{
		printf("\nEssas s�o as informa��es do usuario, ");
		printf("%s", conteudo);//informa�oes mostradas para o usuario
		printf("\n\n");
	}
	fclose(file);
	
	
	printf("Deseja consultar mais usuarios? \n\n");
	printf("1 - sim. \n");
	printf("2 - n�o. \n");
	printf("Op��o: ");
	scanf("%d", &dicide);
	
	switch(dicide)
	{
		case 1:
		consulta();
		break;
		
		case 2:
		menu();
		break;
		
		default:
		printf("Esta op��o n�o existe, por favor escolha uma op��o valida\n");
		system("pause");
		break;
	}
	
	
	system("pause");
	

}
int deletar(){//fun��o de deletar 

	system("cls");

	int dicidi=0;

	//fazer teste e primoramentos nessa parte
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	
	system("cls");
	printf("Digite o CPF do usuario a ser deletado: ");//requisi�ao de cpf
	scanf("%s",cpf);
	
	
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
	else
	{
		fclose(file);
		remove(cpf); //metodo de remo��o
		FILE *file;	
		file = fopen(cpf,"r");
		if(file == NULL)
		{
			printf("Usu�rio deletado com sucesso!.\n");
			system("pause");
		}
	}
	fclose(file);
	
	system("cls");
	
	printf("Deseja excluir mais usuarios? \n\n");
	printf("1 - sim. \n");
	printf("2 - n�o. \n");
	printf("Op��o: ");
	scanf("%d", &dicidi);
	
	switch(dicidi)
	{
		case 1:
		deletar();
		break;
		
		case 2:
		menu();
		break;
		
		default:
		printf("Esta op��o n�o existe, por favor escolha uma op��o valida\n");
		system("pause");
		break;
	}
	system("pause");
}
	


int menu(){
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
			printf("\t3 - Deletar usuario\n\n");
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
				exit(1);
				break;
			
				default:
				printf("Esta op��o n�o existe, por favor escolha uma op��o valida\n");
				system("pause");
				break;
			}//finaL do switch case
		}
}

int acessar(){
	
	system("cls");
	char arquivoteste[40];
	char senha2[40];
	char senhaadmin[40];

	
	printf("### Tela de cadastro da EBAC ###\n\n"); 
	printf("Login de administrador!\n\nDigite a sua senha: "); 
	scanf("%s",arquivoteste);
	
	FILE *file;
	file = fopen(arquivoteste,"r");
	
	
	if(file == NULL)//resposta caso nao encontre as informa��es
	{
		system("cls");
		printf("senha invalida!.\n");
		system("pause");
		acessar();
		
	}
	
	while(fgets(senhaadmin, 40, file) != NULL)//repeti��o ENQUANTO o valor nao for nulo
	{
		menu();
	}
	fclose(file);
}

int main() //fun��o principal
{
	system("cls");
	setlocale(LC_ALL, "Portuguese");

	int tela=0;
	
	printf("### Tela de cadastro da EBAC ###\n\n"); 
	printf("\t1 - Entrar como visitante\n");
	printf("\t2 - Entrar como administrador\n"); 
	printf("\t3 - Resgitrar senha de administrador\n\n"); 
	printf("Op��o: ");
	scanf("%d", &tela);
	
	switch(tela){
		
		case 1:
		visitante();
		break;
		
		case 2:
		acessar();
		break;
			
		case 3:
		senhamestre();
		break;
		
		default:
		system("cls");
		printf("Essa op��o � invalida, tente novamente.!\n\n");
		system("pause");
		main();
		break;
	}
}

int admincadastro(){
	

	system("cls");
	char arquivoteste[40];
	char senha1[40];
	char senha2[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	int comparacaoteste;
	
	int escolhajj=0;
	
	printf("Digite a senha desejada: ");
	scanf("%s", senha1);
	printf("Digite a senha novamente: ");
	scanf("%s", senha2);
	
	strcpy(arquivoteste, senha2);
	
	
	comparacaoteste = strcmp(senha1, senha2);
	
	
	if(comparacaoteste==0){
		
	FILE *file; //criar arquivos
	file = fopen(arquivoteste, "w"); //criar arquivos
	fprintf(file,senha2);//salvar o valor da varievel no arquivo
	fclose(file);
	
	file = fopen(arquivoteste, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);//%s = strings
	
	file = fopen(arquivoteste, "a");// "a" de atualizar, "r" ler ,"w" escrever
	fprintf(file,cpf);
	fclose(file);
	
	file = fopen(arquivoteste, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");//coletando nome do usuario
	scanf("%s",nome);
	
	file = fopen(arquivoteste, "a");// "a" de atualizar, "r" ler ,"w" escrever
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivoteste, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");//coletando sobrenome do usuario
	scanf("%s",sobrenome);
	
	file = fopen(arquivoteste, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivoteste, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Selecione o cargo desejado: \n");
	printf("\t1 - aluno\n ");
	printf("\t2 - professor\n ");
	printf("\t3 - visitante\n: ");
	printf("Op��o: ");
	scanf("%d", &escolhajj);//%d = double
	
	switch(escolhajj)
		{
			case 1:
			file = fopen(arquivoteste, "a");
			fprintf(file,"Aulo");
			fclose(file);
			break;
			
			case 2:
			file = fopen(arquivoteste, "a");
			fprintf(file,"Professor");
			fclose(file);
			break;
			
			case 3:
			file = fopen(arquivoteste, "a");
			fprintf(file,"Visitante");
			fclose(file);
			break;
			
			default:
			printf("Esta op��o n�o existe, por favor escolha uma op��o valida\n");
			system("pause");
			break;
		}
	
	system("cls");
	printf("Cadastro finalizado!\n");
	system("pause");
	system("cls");
	main();
	
	
	}
	else
		system("cls");
		printf("Senha incompativel!\n");
		system("pause");
		senhamestre();
	
}

int senhamestre(){
	
	system("cls");
	
	char senhadigitada[10]="a";
	int comparacao;
	int tela=0;
	
	printf("### Tela de cadastro da EBAC ###\n\n"); 
	printf("Login de administrador!\n\nDigite a sua senha mestre: "); 
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "7355608");
	
	if(comparacao==0)
	{
		admincadastro();
	}
	else
		system("cls");
		printf("Senha mestre incorreta!\n");
		system("pause");
		senhamestre();
}


int visitante(){
	int opcao=0; //Definindo variaveis	
	int laco=1; //inicio da repeti��o
	
	for(laco=1;laco=1;)
		{

			system("cls");//limpar a tela
		
			setlocale(LC_ALL, "Portuguese"); //linha para ativar a regi�io de interesse
	
			printf("### Tela de cadastro da EBAC ###\n\n"); //inicio do menu
			printf("Escolha a op��o desejada do menu:\n\n"); 
			printf("\t1 - Cadastrar usuario\n");
			printf("\t2 - Consultar usuario\n\n");
				
			printf("\t3 - Sair do sistema\n\n");
			
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
				printf("Obrigado por utilizar o sistema <3\n");
				exit(1);
				break;
			
				default:
				printf("Esta op��o n�o existe, por favor escolha uma op��o valida\n");
				system("pause");
				break;
			}//finaL do switch case
		}
}


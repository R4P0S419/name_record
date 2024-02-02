#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca de string

int registro(){//função de registro

	system("cls");

	int dicida=0;

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
	printf("Opção: ");
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
			printf("Esta opção não existe, por favor escolha uma opção valida\n");
			system("pause");
			break;
		}
		
	system("cls");
		
	printf("Deseja registrar mais usuarios? \n\n");
	printf("1 - sim. \n");
	printf("2 - não. \n");
	printf("Opção: ");
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
		printf("Esta opção não existe, por favor escolha uma opção valida\n");
		system("pause");
		break;
	}
	system("pause");	
	

}
int consulta(){//função de consulta
	system("cls");

	int dicide=0;
	
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	system("cls");
	
	printf("Digite o CPF a ser consultado: ");//requisição de cpf para consulta
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)//resposta caso nao encontre as informações
	{
		printf("Não foi possivel encontrar o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)//repetição ENQUANTO o valor nao for nulo
	{
		printf("\nEssas são as informações do usuario, ");
		printf("%s", conteudo);//informaçoes mostradas para o usuario
		printf("\n\n");
	}
	
	
	printf("Deseja consultar mais usuarios? \n\n");
	printf("1 - sim. \n");
	printf("2 - não. \n");
	printf("Opção: ");
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
		printf("Esta opção não existe, por favor escolha uma opção valida\n");
		system("pause");
		break;
	}
	
	
	system("pause");
	

}
int deletar(){//função de deletar 

	system("cls");

	int dicidi=0;

	//fazer teste e primoramentos nessa parte
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	
	system("cls");
	printf("Digite o CPF do usuario a ser deletado: ");//requisiçao de cpf
	scanf("%s",cpf);
	
	remove(cpf);//metodo de remoção
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL){
		printf("Esse usuario nao foi encontrado!.\n");//caso o cpf digitado for nulo esse sera o resultado
	}
	
	system("cls");
	
	printf("Deseja excluir mais usuarios? \n\n");
	printf("1 - sim. \n");
	printf("2 - não. \n");
	printf("Opção: ");
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
		printf("Esta opção não existe, por favor escolha uma opção valida\n");
		system("pause");
		break;
	}
	system("pause");
}

int menu(){
	int opcao=0; //Definindo variaveis	
	int laco=1; //inicio da repetição
	char senhadigitada[10]="a";
	int comparacao;
	int tela=0;
	
	for(laco=1;laco=1;)
		{

			system("cls");//limpar a tela
		
			setlocale(LC_ALL, "Portuguese"); //linha para ativar a regiãio de interesse
	
			printf("### Tela de cadastro da EBAC ###\n\n"); //inicio do menu
			printf("Escolha a opção desejada do menu:\n\n"); 
			printf("\t1 - Cadastrar usuario\n");
			printf("\t2 - Consultar usuario\n");
			printf("\t3 - Deletar usuario\n");
			printf("\t4 - Sair do sistema\n\n");
			printf("Opção: "); //fim do menu
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
				printf("Esta opção não existe, por favor escolha uma opção valida\n");
				system("pause");
				break;
			}//finaL do switch case
		}
}

int acessar(){
	
	system("cls");
	
	int opcao=0; //Definindo variaveis	
	int laco=1; //inicio da repetição
	char senhadigitada[10]="a";
	int comparacao;
	int tela=0;
	
	printf("### Tela de cadastro da EBAC ###\n\n"); 
	printf("Login de administrador!\n\nDigite a sua senha: "); 
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "7355608");
	
	if(comparacao==0)
	{
		menu();
	}
	else
		system("cls");
		printf("Senha incorreta!");
		main();
}

int main() //função principal
{
	system("cls");
	setlocale(LC_ALL, "Portuguese");
	
	int opcao=0; //Definindo variaveis	
	int laco=1; //inicio da repetição
	char senhadigitada[10]="a";
	int comparacao;
	int tela=0;
	
	printf("### Tela de cadastro da EBAC ###\n\n"); 
	printf("\t1 - Entrar como administrador\n"); 
	printf("\t2 - Resgitrar senha de administrador\n\n"); 
	printf("Opção: ");
	scanf("%d", &tela);
	
	switch(tela){
		case 1:
		acessar();
		break;
			
		case 2:
		return 0;
		break;
	}
}
	
	


/*	Universidade Cat�lica de Bras�lia
Professor: Andr� Gustavo Bastos de Lima
Curso: An�lise e Desenvolvimento de Sistemas
Disciplina: Teste de Software
Alunos : 	
Gabriel Bessa Rebou�as...................... UC20200683
Luiz Fernandes Veras........................ UC20201511
*/      
#include<stdio.h> /*Biblioteca de entrada e saida de dados*/
#include<locale.h> /* Biblioteca com fun��es de acentua��o*/
#include<string.h> /* Biblioteca com fun��es para manipula��o de string*/
#include<stdlib.h> /*Cont�m prot�tipos de fun��es variadas para: convers�o de n�meros em texto e texto em n�meros, aloca��o de mem�ria, n�meros aleat�rios; e outras fun��es com v�rias finalidades.*/
#include<time.h> /* fun��o para manipula��o de datas e hor�rios*/

/*vari�veis globais*/
int idUsuario[1000], vacina[1000], i=0, opc, cont=0,x=0;
char nome[1000][50], eMail[1000][50], sexo[1000][10], endereco[1000][150],telefone[1000][50],dataConsult[1000][50],horarioConsult[1000][50],medico[1000][50];
double altura[1000];

/* Declara��o de fun��es */
int menu();
void cadastrarId(); /*Fun��o respons�vel pelo cadastro da ID*/
void cadastrarNome(); /*Fun��o respons�vel pelo cadastro do nome*/
void cadastrarSexo(); /*Fun��o respons�vel pelo cadastro do sexo*/
void cadastrarAltura(); /*Fun��o respons�vel pelo cadastro da altura*/
void cadastrarVacina(); /*Fun��o respons�vel por indicar se tomou ou n�o vacina*/
void cadastrarEmail(); /*Fun��o respons�vel pelo cadastro do e-mail*/
void ordenacaoVetor(); /*Fun��o respons�vel pela ordena��o dos vetores*/
void cadastrarEndereco(); /*Fun��o respons�vel pelo cadastro da endere�o*/
void cadastrarTel(); /*Fun��o respons�vel pelo cadastro do telefone*/
void cadastrarDataConsulta(); /*Fun��o respons�vel pela data de consulta*/
void cadastrarHorario(); /*Fun��o respons�vel pelo cadastro da hora*/
void cadastrarmedico(); /*Fun��o respons�vel pelo cadastro do m�dico*/
void pesquisar(); /*Fun��o respons�vel por pesquisar o paciente*/
void backup(); /*Fun��o respons�vel pelo backup de todos os dados cadastrados*/
void editar(); /*Fun��o respons�vel pela edi��o completa do cadastro */
void excluir(); /*Fun��o respons�vel por excluir o cadastro*/
void excluirId(); /*Fun��o respons�vel pelo exclus�o da ID*/
int buscaBinariaId(int id[], int tamamnho, int x); /*Fun��o respons�vel pela busca binaria da ID e sua substitui��o*/

typedef struct {
	char login [30];
	char senha [30];
}pessoa; pessoa p[1];
int main(){ /*funcaoo principal*/
	system("color 0E");
	
	char login[30];
	char senha [30];
	int valida=0;
	
	strcpy (p[0].login, "admin");
	strcpy (p[0].senha, "****");
	
	do{
		printf("\n XXXXXXX XXXXXXX XXXXXXX XXXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXX");
		printf("\nX XXXXX X XXXXX                                  X XXXXX X XXXXX X XXX");
		printf("\nXX XXX XXX XXXX      BREAKING BAD DATALOG        XX XXX XXX XXX XXX XX");
		printf("\nXXX X XXXXX XXX                                  XXX X XXXXX X XXXXX X");
		printf("\nXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXX \n\n");
		
		printf("\n\tLogin:");
		scanf("%s", login);
		printf("\tSenha:");
		scanf("%s", senha);

	if((strcmp(login,p[0].login)==0)&& (strcmp(senha,p[0].senha)==0)){
		valida++;
		printf("Usuario logado");
		do{ /* Estrutura de repeti��o que executa o c�digo pelo menos uma vez */
		opc = menu();
		switch(opc){ /*Comando condicional que compara as condi��es de uma variavel, utilizamos para a cria��o do menu*/ 
			case 1:
				system("cls"); /*limpa a tela*/
				printf("\n XXXXXXX XXXXXXX XXXXXXX XXXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXX");
				printf("\nX XXXXX X XXXXX                                  X XXXXX X XXXXX X XXX");
				printf("\nXX XXX XXX XXXX      CADASTRAR NOVO PACIENTE     XX XXX XXX XXX XXX XX");
				printf("\nXXX X XXXXX XXX                                  XXX X XXXXX X XXXXX X");
				printf("\nXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXX \n\n");
				cadastrarId(); /*chamada da fun��o */
				cadastrarNome();/*chamada da fun��o */
				cadastrarEmail();/*chamada da fun��o */
				cadastrarSexo();/*chamada da fun��o */
				cadastrarVacina();/*chamada da fun��o */
				cadastrarEndereco();/*chamada da fun��o */
				cadastrarAltura();/*chamada da fun��o */
				cadastrarTel();	/*chamada da fun��o */
				printf("\n\n");			
				cadastrarDataConsulta();/*chamada da fun��o */
				cadastrarHorario(); /*chamada da fun��o */
				cadastrarmedico();				
				i++; /*controlador da posi��o do vetor */
				cont++;
				printf("\n\t\t\tCadastro realizado com sucesso!!!\n\n");				
				system("pause");
				break;
			case 2:
					ordenacaoVetor(); /*fun��o de ordena��o do vetor*/
					system("cls"); /*limpa tela */
				printf("\n XXXXXXX XXXXXXX XXXXXXX XXXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXX");
				printf("\nX XXXXX X XXXXX                                  X XXXXX X XXXXX X XXX");
				printf("\nXX XXX XXX XXXX       PACIENTES CADASTRADOS      XX XXX XXX XXX XXX XX");
				printf("\nXXX X XXXXX XXX                                  XXX X XXXXX X XXXXX X");
				printf("\nXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXX \n\n");
				for(i=0;i<cont;i++){
					if(idUsuario[i]!= 0){
						printf("\tID Paciente............................................: %i\n",idUsuario[i] );
						printf("\tNome...................................................: %s",nome[i]);
						printf("\tEmail cadastrado.......................................: %s\n",eMail[i]);
						printf("\tSexo...................................................: %s\n",sexo[i]);
						printf("\tTomou vacina?..........................................: ");					
						if(vacina[i] == 1){/*condicional bolleana*/
							printf("SIM\n");
						}else{
							printf("NAO\n");
						}
						printf("\tEndereco...............................................: %s", endereco[i]);
						printf("\tAltura.................................................:  %.2f\n", altura[i]);
						printf("\tTelefone...................................................: %s\n\n",telefone[i]);
						printf("\tData da Consulta............................................: %s\n",dataConsult[i]);						
						printf("\tHorario...................................................: %s\n",horarioConsult[i]);
						printf("\tMedico...................................................: %s\n",medico[i]);						
						printf("\n");					
					}					
				}
			system ("pause"); /* pause na execu��o */
				break;
			case 3:
				system("cls");
				printf("\n XXXXXXX XXXXXXX XXXXXXX XXXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXX");
				printf("\nX XXXXX X XXXXX                                  X XXXXX X XXXXX X XXX");
				printf("\nXX XXX XXX XXXX  PESQUISAR PACIENTES CADASTRADOS XX XXX XXX XXX XXX XX");
				printf("\nXXX X XXXXX XXX                                  XXX X XXXXX X XXXXX X");
				printf("\nXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXX \n\n");
				pesquisar();	/* chamada de fun��o*/		
			system ("pause");
				break;
			case 4:
				system("cls");
				printf("\n XXXXXXX XXXXXXX XXXXXXX XXXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXX");
				printf("\nX XXXXX X XXXXX                                  X XXXXX X XXXXX X XXX");
				printf("\nXX XXX XXX XXXX   EXCLUIR PACIENTES CADASTRADOS  XX XXX XXX XXX XXX XX");
				printf("\nXXX X XXXXX XXX                                  XXX X XXXXX X XXXXX X");
				printf("\nXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXX \n\n");
				excluir();	/* chamada de fun��o*/	
			system ("pause");
			break;
			case 5:
				system("cls");
				printf("\n XXXXXXX XXXXXXX XXXXXXX XXXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXX");
				printf("\nX XXXXX X XXXXX                                  X XXXXX X XXXXX X XXX");
				printf("\nXX XXX XXX XXXX    EDITAR PACIENTES CADASTRADOS  XX XXX XXX XXX XXX XX");
				printf("\nXXX X XXXXX XXX                                  XXX X XXXXX X XXXXX X");
				printf("\nXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXX \n\n");
				editar();/* chamada de fun��o*/	
			system ("pause");
				break;
			case 6:
               system("cls");
                printf("\n XXXXXXX XXXXXXX XXXXXXX XXXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXX");
				printf("\nX XXXXX X XXXXX                                  X XXXXX X XXXXX X XXX");
				printf("\nXX XXX XXX XXXX          REALIZAR BACKUP         XX XXX XXX XXX XXX XX");
				printf("\nXXX X XXXXX XXX                                  XXX X XXXXX X XXXXX X");
				printf("\nXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXX \n\n");
				backup();/* chamada de fun��o*/	
			system ("pause");
				break;
			case 7 :
               system("cls");
				printf("\n XXXXXXX XXXXXXX XXXXXXX XXXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXX");
				printf("\nX XXXXX X XXXXX                                  X XXXXX X XXXXX X XXX");
				printf("\nXX XXX XXX XXXX        FECHANDO SISTEMA...       XX XXX XXX XXX XXX XX");
				printf("\nXXX X XXXXX XXX                                  XXX X XXXXX X XXXXX X");
				printf("\nXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXX \n\n");

				break;
		}
	}while(opc !=7);		
			
	}else{
		
		printf("\tUsuario e/ou senha incorretos\n\n");
		system ("pause");
		system("cls");
	}
		
	}while(valida==0);
	return 0;
}
int menu(){
system ("cls");
	int opcao=0;
	do{
		system ("cls");
		printf("\n XXXXXXX XXXXXXX XXXXXXX XXXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXX");
		printf("\nX XXXXX X XXXXX                                  X XXXXX X XXXXX X XXX");
		printf("\nXX XXX XXX XXXX        SELECIONE UMA OPCAO:      XX XXX XXX XXX XXX XX");
		printf("\nXXX X XXXXX XXX                                  XXX X XXXXX X XXXXX X");
		printf("\nXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXX  \n\n");		
		printf(" \t[1]\tCadastrar Novo Usuario\n");
		printf(" \t[2]\tListar Usuarios Cadastrados\n");
		printf(" \t[3]\tPesquisar Usuario\n");
		printf(" \t[4]\tExcluir Cadastro\n");
		printf(" \t[5]\tEditar Cadastro\n");
		printf(" \t[6]\tBackup\n");
		printf(" \t[7]\tSair\n");
		printf("\nOpcao desejada: ");
		scanf("%d", &opcao);
		getchar();
		printf("\n");
		if(opcao > 7 || opcao < 1){
			printf("\n\tATENCAO!!!\n\n");
			printf("\tOpcao Invalida\n\n"); /*valida a opcao digitada*/
			system("pause");
		}
	}while(opcao == 0);
return opcao;
}
void cadastrarId(){ /* funcao para cadastrar id de forma randomica */
	int idTemp;
	do{
		srand(time(NULL));
		idTemp = rand()%100000;/*gera��o de um Id autom�tico por meio de numeros aleat�rios*/

	}while (idTemp == idUsuario[i]); /*estrutura de repeticao para repetir a fun��o randomica para gera��o de novo id, caso essej� exista */

	idUsuario[i] = idTemp;
	printf("ID Paciente...................................................: %i\n", idUsuario[i]);
}
void cadastrarNome(){ /*funcao para cadasrar nome*/
	do{
		printf("Informe o nome...............................................: ");
   		fgets(nome[i],sizeof(nome[i]), stdin); /* funcao para a leitura de uma string */
		if (strlen(nome[i])== 1){ /* verifica se a posicao est� vazia */
			printf("Este campo nao pode ser vazio\n");
		}
	}while(strlen(nome[i])== 1);
}
void cadastrarSexo(){/*funcao para cadastrar sexo*/
	do{
		printf("Informe sexo: Masculino, Feminino ou Nao-declarado...........: ");
   		scanf("%s", sexo[i]);
		fflush(stdin); /*limpa buffer */
   		strupr(sexo[i]); //fun��o que converte a string para mai�sculo.
		if(strcmp(sexo[i],"MASCULINO")!=0 && strcmp(sexo[i],"FEMININO")!=0 && strcmp(sexo[i], "NAO-DECLARADO")!=0){
			printf("Erro, opcao invalida\n");
		}
	}while(strcmp(sexo[i],"MASCULINO")!=0 && strcmp(sexo[i],"FEMININO")!=0 && strcmp(sexo[i], "NAO-DECLARADO")!=0);
}
void cadastrarEndereco(){/*funcao para cadastrar endereco*/
	fflush(stdin);
	do{
		printf("Informe o Endereco...........................................: ");
   		fgets(endereco[i],sizeof(endereco[i]), stdin);
		if (strlen(endereco[i])== 1){

			printf("Este campo nao pode ser vazio\n");
		}
	}while(strlen(endereco[i])== 1);
}
void cadastrarAltura(){/*funcao para cadastrar altura*/
	do{
		printf("Informe a altura separada por '.'ponto: ex: 1.60.............: ");
		scanf("%lf", &altura[i]);
		getchar();
		if (altura[i] < 1 || altura[i] > 2){
			printf("Erro, altura invalida\n");
			printf("valor n�o pode ser superior a 2.00 mts\n");
		}
	}while(altura[i] < 1 || altura[i] > 2);
}
void cadastrarVacina(){ /*funcao bolleana para verificar o cadastro da vacina */
	do{
		printf("Tomou a vacina? digite [1] para SIM ou [2] para NAO..........: ");
		scanf("%d", &vacina[i]);
		if (vacina[i] < 1 || vacina[i] > 2){
			printf("Erro, opcao invalida\n");
		}
	}while(vacina[i] < 1 || vacina[i] > 2);
}
void cadastrarEmail(){/*funcao para cadastrar email*/

    char *validador;
	do{
		printf("Informe o e-mail.............................................: ");
		scanf("%s", eMail[i]);
		strlwr(eMail[i]); //fun��o que converte a string para minusculo.
		validador = strchr(eMail[i],'@'); //fun��o que percorre a string comparando o caractere @ com cada caractere da string, caso n�o encontre retorna NULL.
		if(validador == NULL){/* condicional para verificar se o validor � == NULL, se for � porque n�o tem o @*/
			printf("digite um e-mail valido\n"); /*imprime na tela para o usu�rio digitar um email v�lido*/
		}
	}while(validador == NULL);/*estrutura de repeti��o euanquento a condi��o for verdadeira*/
}
void cadastrarTel(){ /*funcao para cadasrar nome*/
	do{
		printf("Informe o telefone...............................................: ");
   		fgets(telefone[i],sizeof(telefone[i]), stdin); /* funcao para a leitura de uma string */
		if (strlen(telefone[i])== 1){ /* verifica se a posicao est� vazia */
			printf("Este campo nao pode ser vazio\n");
		}
	}while(strlen(telefone[i])== 1);
}
void cadastrarDataConsulta(){ /*funcao para cadasrar nome*/
	do{
		printf("Data de Agendamento...............................................: ");
   		fgets(dataConsult[i],sizeof(dataConsult[i]), stdin); /* funcao para a leitura de uma string */
		if (strlen(dataConsult[i])== 1){ /* verifica se a posicao est� vazia */
			printf("Este campo nao pode ser vazio\n");
		}
		//getchar();
	}while(strlen(dataConsult[i])== 1);
}
void cadastrarHorario(){ /*funcao para cadasrar nome*/
	do{
		printf("Horario agendado...............................................: ");
   		fgets(horarioConsult[i],sizeof(horarioConsult[i]), stdin); /* funcao para a leitura de uma string */
		if (strlen(horarioConsult[i])== 1){ /* verifica se a posicao est� vazia */
			printf("Este campo nao pode ser vazio\n");
		}
		//getchar();
	}while(strlen(horarioConsult[i])== 1);
}
void cadastrarmedico(){ /*funcao para cadasrar nome*/
	do{
		printf("Medico...............................................: ");
   		fgets(medico[i],sizeof(medico[i]), stdin); /* funcao para a leitura de uma string */
		if (strlen(medico[i])== 1){ /* verifica se a posicao est� vazia */
			printf("Este campo nao pode ser vazio\n");
		}
		getchar();
	}while(strlen(medico[i])== 1);
}
void ordenacaoVetor(){/*funcao para ordenar o vetor*/
	
	int aux_idUsuario,contador=0, aux_vacina, j=0;
	char Aux_nome[50], auxEmail[50], auxSexo[10],auxEndereco[150], aux_tel[50],aux_datac[50],aux_hor[50],aux_med[50];
	double auxAltura;
	
	
	for(i = 0; i < cont; i++){/*Estrutura que percorre o vetor*/
		for(j = i+1; j < cont; j++){/*Estrutura para comparar a posi��o seguinte com a a*/
			if(idUsuario[i] > idUsuario[j]){ /*condicional que verifica se o id na posi��o i � maior que o id na posi��o "j" seguinte */
				
				aux_idUsuario = idUsuario[i]; /*variavel auxiliar para armazenar os dados da variavel id na posi��o i*/
				idUsuario[i] = idUsuario[j];/*atribui��o do valor de uma variavel na posi��o j para outra na posi��o i*/
				idUsuario[j] = aux_idUsuario;/*variavel na posicao j que vai receber os dados da vari�vel auxiliar*/
				
				strcpy(Aux_nome,nome[i]);// strcpy funcao da biblioteca string.h para copiar um vetor de string para uma variavela auxiliar.
				strcpy(nome[i],nome[j]); /*atribui��o do valor de uma variavel na posi��o j para outra na posi��o i*/
				strcpy(nome[j],Aux_nome); /*copiar os dados da variavel auxiliar para a variavel nome na posi��o j*/
				
				strcpy(auxEmail,eMail[i]); /*variavel auxiliar para armazenar os dados da string*/
				strcpy(eMail[i],eMail[j]); /*atribui��o do valor de uma variavel na posi��o j para outra na posi��o i*/
				strcpy(eMail[j],auxEmail); /* copiar dados da variavel auxiliar para a posi��o J da variavel eMail*/
				
				strcpy(auxSexo,sexo[i]);/*variavel auxiliar para armazenar os dados da variavel altura na posi��o i*/
				strcpy(sexo[i],sexo[j]);/*atribui��o do valor de uma variavel na posi��o j para outra na posi��o i*/
				strcpy(sexo[j],auxSexo);/* copiar dados de uma variavel auxiliar para a posi��o J do variavel sexo*/
				
				aux_vacina = vacina[i];/*variavel auxiliar para armazenar os dados da variavel altura na posi��o i*/
				vacina[i] = vacina[j];/*atribui��o do valor de uma variavel na posi��o j para outra na posi��o i*/
				vacina[j] = aux_vacina;/* copiar dados da variavel auxiliar para a posi��o J do variavel vacina*/
				
				strcpy(auxEndereco,endereco[i]);/*variavel auxiliar para armazenar os dados da string*/
				strcpy(endereco[i],endereco[j]);/*atribui��o do valor de uma variavel na posi��o j para outra na posi��o i*/
				strcpy(endereco[j],auxEndereco);/* copiar dados da variavel auxiliar para a posi��o J do variavel auxEndereco*/
				
				auxAltura = altura[i];/*variavel auxiliar para armazenar os dados da variavel altura na posi��o i*/
				altura[i] = altura[j]; /*atribui��o do valor de uma variavel na posi��o j para outra na posi��o i*/
				altura[j] = auxAltura;	/* copiar dados da variavel auxiliar para a posi��o J do variavel altura*/	
				
				strcpy(aux_tel,telefone[i]);// strcpy funcao da biblioteca string.h para copiar um vetor de string para uma variavela auxiliar.
				strcpy(telefone[i],telefone[j]); /*atribui��o do valor de uma variavel na posi��o j para outra na posi��o i*/
				strcpy(telefone[j],aux_tel); /*copiar os dados da variavel auxiliar para a variavel nome na posi��o j*/	
				
				strcpy(aux_datac,dataConsult[i]);// strcpy funcao da biblioteca string.h para copiar um vetor de string para uma variavela auxiliar.
				strcpy(dataConsult[i],dataConsult[j]); /*atribui��o do valor de uma variavel na posi��o j para outra na posi��o i*/
				strcpy(dataConsult[j],aux_datac); /*copiar os dados da variavel auxiliar para a variavel nome na posi��o j*/
				
				strcpy(aux_hor,horarioConsult[i]);// strcpy funcao da biblioteca string.h para copiar um vetor de string para uma variavela auxiliar.
				strcpy(horarioConsult[i],horarioConsult[j]); /*atribui��o do valor de uma variavel na posi��o j para outra na posi��o i*/
				strcpy(horarioConsult[j],aux_hor); /*copiar os dados da variavel auxiliar para a variavel nome na posi��o j*/
				
				strcpy(aux_med,medico[i]);// strcpy funcao da biblioteca string.h para copiar um vetor de string para uma variavela auxiliar.
				strcpy(medico[i],medico[j]); /*atribui��o do valor de uma variavel na posi��o j para outra na posi��o i*/
				strcpy(medico[j],aux_med); /*copiar os dados da variavel auxiliar para a variavel nome na posi��o j*/	
								
			}	
		}
	}			
}
void pesquisar(){
	
	int idPesquisado, opcao, resultado=0,identificador = 0;
	char opcao2[50];
	do{
		
		printf("\nInforme a opcao de pesquisa:\n[1] ID\n[2] EMAIL\n");
		scanf("%d",&opcao); /*l� o Id a ser pesquisado*/
		printf("\nOpcao desejada: %d\n\n",opcao);
		
		if(opcao < 1 || opcao > 2){
			printf("Erro, opcao invalida\n\n");	/* valida se a escolha do usu�rio est� dentro das op��es oferecidas*/		
		}		
			
	}while(opcao < 1 || opcao > 2);
	
	switch(opcao){
		case 1:
			printf("Digite o Id que deseja procurar: ");
			scanf("%d", &idPesquisado); /* le o id a ser pesquisado */
			resultado = buscaBinariaId(idUsuario, cont,idPesquisado);
			
			if(resultado != -1){
				printf("Valor %d foi encontrado na posicao %d que tem o valor %d\n\n",idPesquisado,resultado, idUsuario[resultado]);
				printf("\tID Paciente............................................: %i\n", idUsuario[resultado] );
				printf("\tNome...................................................: %s", nome[resultado]);
				printf("\tEmail cadastrado.......................................: %s\n",eMail[resultado]);
				printf("\tSexo...................................................: %s\n", sexo[resultado]);
				printf("\tTomou vacina?..........................................: ");
				if(vacina[i] == 1){
					printf("SIM\n");
				}else{
					printf("NAO\n");
				}
				printf("\tEndereco...............................................: %s", endereco[resultado]);
				printf("\tAltura.................................................:  %.2f\n", altura[resultado]);
				printf("\tTelefone...................................................: %s\n\n", telefone[resultado]);
				printf("\tData da Consulta............................................: %s\n",dataConsult[resultado]);						
				printf("\tHorario...................................................: %s\n",horarioConsult[resultado]);
				printf("\tMedico...................................................: %s\n",medico[resultado]);	
				printf("\n");
			}else{
			printf("Valor nao encontrado\n");	
			break;			
		case 2:			
				printf("Informe o e-mail......................................: ");
				scanf("%s", opcao2);
				fflush(stdin);
				strlwr(opcao2); //fun��o que converte a string para minusculo.
				for(i=0;i<cont;i++){
					if(strcmp(opcao2,eMail[i])==0){
						printf("\n\tID Paciente............................................: %i\n", idUsuario[i] );
						printf("\tNome...................................................: %s", nome[i]);
						printf("\tEmail cadastrado.......................................: %s\n",eMail[i]);
						printf("\tSexo...................................................: %s\n", sexo[i]);
						printf("\tTomou vacina?..........................................: ");
					
						if(vacina[i] == 1){
							printf("SIM\n");
							}else{
							printf("NAO\n");
							}
							printf("\tEndereco...............................................: %s", endereco[i]);
							printf("\tAltura.................................................:  %.2f\n", altura[i]);
							printf("\n");
							identificador++;					
					}
				}
					if(identificador==0){
						printf("Nao Localizado, tente novamente.\n");
						printf("%s\n", opcao2);
						printf("%s\n", eMail[i]);
					}
					break;
		}
	}
}
int buscaBinariaId(int id[1000], int tamanho, int x){
	int inicio = 0, fim = tamanho - 1, meio;
	
	while(inicio <= fim){
		meio = (inicio + fim) / 2; /* Identifica a metade do vetor */
		
		if(x==id[meio]){ /* verifica se o id est� na posi��o do meio do vetor */
			return meio; /*se sim, retorna o do meio */
		}else if(x < id[meio]){ /* Sen�o verifica se o Id pesquisado � menor que o Id na posi��o do meio do vetor, se sim a pesquisa ser� at� a metade do vetor*/
			fim = meio - 1;			
		}else{
			inicio = meio + 1;	/* sen�o o inicio ser� atualizado com a posi��o do meio + 1 e a pesquisa ser� realizada a partir daquela posi��o */		
		}		
	}
	return -1;	
}
void backup(){
	/* variaveis para guardar os dados do vetor principal, como forma de backup */	
	int bkp_idUsuario[1000], bkp_vacina[1000];
	char bkp_nome[1000][50], bkp_eMail[1000][50], bkp_sexo[1000][10], bkp_endereco[1000][150],bkp_tel[1000][50],bkp_dataConsult[1000][50],bkp_horarioConsult[1000][50],bkp_medico[1000][50];
	double bkp_altura[1000];
	
	int opcao=0, i=0;
	
	do{
		printf("[1] Sim\n[2] Nao\n[3] Restaurar backup\n", opcao);/* imprime na tela a opcao para o usuario*/	
		scanf("%d", &opcao);/*le a opcao desejada*/
		
		printf("Opcao desejada: %d\n", opcao);	/* imprime a opcao desejada */	
		
		if(opcao < 1 || opcao > 3){/* valida a opcao informada pelo usuario*/
			printf("\nErro, opcao invalida\n\n");/*imprime erro casa a opcao seja diferente da informada*/			
		}		
		
	}while(opcao < 1 || opcao > 3);	/* estrutura de repeticao que executa pelo menos uma vez e enquanto as condi��es forem verdadeira*/
	
	
	if(opcao == 1){
		if(idUsuario[i]!=NULL){
			for(i = 0; i < 1000; i++){
				bkp_idUsuario[i] = idUsuario[i];
				strcpy(bkp_nome[i],nome[i]);
				strcpy(bkp_eMail[i], eMail[i]);
				strcpy(bkp_sexo[i],sexo[i]);
				bkp_vacina[i] = vacina[i];
				strcpy(bkp_endereco[i],endereco[i]);
				bkp_altura[i] = altura[i];
				strcpy(bkp_tel[i],telefone[i]);
				strcpy(bkp_dataConsult[i],dataConsult[i]);
				strcpy(bkp_horarioConsult[i],horarioConsult[i]);
				strcpy(bkp_medico[i],medico[i]);				
				

				x++;/* contador para verificar se existe backup	*/
			}	
			printf("\t\t\tBackup realizado com sucesso!");//imprime mensagem para visualizacao do usuario.			
		}else{
			printf("\t\t\tBase de dados vazia, Backup nao realizado. ");			
		}		
	}else if (opcao == 2){
		printf("\t\t\tBackup nao realizado. ");	
	}else if(x != 0){
		for(i = 0; i < 1000; i++){
				idUsuario[i] = bkp_idUsuario[i];
				strcpy(nome[i],bkp_nome[i]);
				strcpy(eMail[i],bkp_eMail[i]);
				strcpy(sexo[i],bkp_sexo[i]);
				vacina[i]= bkp_vacina[i] ;
				strcpy(endereco[i],bkp_endereco[i]);
				altura[i]= bkp_altura[i];
				strcpy(bkp_tel[i],telefone[i]);
				strcpy(bkp_dataConsult[i],dataConsult[i]);
				strcpy(bkp_horarioConsult[i],horarioConsult[i]);
				strcpy(bkp_medico[i],medico[i]);
				x++;/* contador para verificar se existe backup	*/
		}			
		printf("\t\t\tBackup Restaurado! ");
	}else{
		printf("\t\t\tNao existe Backup para restauracao, operacao nao realizada. ");
	}		
		printf("\n\tLog:\n", bkp_idUsuario[i]);//imprime uma lista de Id's que foram restaurados//
	for(i = 0; i < cont; i++){	
		
		if(idUsuario[i] != 0 && x != 0 ){						
			printf("\n\tID Usuario...........................................: %i", bkp_idUsuario[i] ); /*Imprime um log com os Id's para mostrar para o usu�rio os Id's que fizemos backup*/						
		}
	}
	printf("\n\n");
}
void editar(){
	
	int id, identificador=0, opcao=0;	
	
	printf("Informe o Id do cadastro a ser editado: "); /*imprime a msg na tela*/
	scanf("%d", &id); /*l� o id que ser� editado*/
	fflush(stdin);

	for(i=0; i < cont; i++){ /* estrutura de repeti��o para percorrer o Vetor em busca do ID digitado */
		if(	idUsuario[i] == id){				
			cadastrarNome();
			cadastrarEmail();
			cadastrarSexo();
			cadastrarVacina();
			cadastrarEndereco();
			cadastrarAltura();
			cadastrarTel();
			identificador++; /*controla a entrada  da Id na condi��o criada*/			
			printf("\t\t\tCadastro editado com sucesso!\n\n");		
		}
	}
	if(identificador == 0){
		printf("Id nao foi localizado\n"); /*Imprime n�o localizado caso o identificador n�o entre na condicional do If*/
	}
			
}
void excluir(){
	int id, identificador=0, opcao=0;	
	printf("Informe o Id do cadastro a ser excluido: ");
	scanf("%d", &id);
	fflush(stdin); /* limpa o buffer do teclado*/
	for(i=0; i < cont; i++){
		if(	idUsuario[i] == id){				
			excluirId();			
			identificador++;
			printf("\t\t\tCadastro excluido com sucesso!\n\n");		
		}
	}
	if(identificador == 0){
		printf("\t\tId nao foi localizado!\n");
	}			
}
void excluirId(){ /*funcao excluir*/
	int idTemp, idEx = NULL;
	idUsuario[i] = idEx;
	//printf("ID Excluido com sucesso!\n");
}

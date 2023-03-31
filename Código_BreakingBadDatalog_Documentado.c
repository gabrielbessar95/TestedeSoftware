/*	Universidade Católica de Brasília
Professor: André Gustavo Bastos de Lima
Curso: Análise e Desenvolvimento de Sistemas
Disciplina: Teste de Software
Alunos : 	
Gabriel Bessa Rebouças...................... UC20200683
Luiz Fernandes Veras........................ UC20201511
*/      
#include<stdio.h> /*Biblioteca de entrada e saida de dados*/
#include<locale.h> /* Biblioteca com funções de acentuação*/
#include<string.h> /* Biblioteca com funções para manipulação de string*/
#include<stdlib.h> /*Contém protótipos de funções variadas para: conversão de números em texto e texto em números, alocação de memória, números aleatórios; e outras funções com várias finalidades.*/
#include<time.h> /* função para manipulação de datas e horários*/

/*variáveis globais*/
int idUsuario[1000], vacina[1000], i=0, opc, cont=0,x=0;
char nome[1000][50], eMail[1000][50], sexo[1000][10], endereco[1000][150],telefone[1000][50],dataConsult[1000][50],horarioConsult[1000][50],medico[1000][50];
double altura[1000];

/* Declaração de funções */
int menu();
void cadastrarId(); /*Função responsável pelo cadastro da ID*/
void cadastrarNome(); /*Função responsável pelo cadastro do nome*/
void cadastrarSexo(); /*Função responsável pelo cadastro do sexo*/
void cadastrarAltura(); /*Função responsável pelo cadastro da altura*/
void cadastrarVacina(); /*Função responsável por indicar se tomou ou não vacina*/
void cadastrarEmail(); /*Função responsável pelo cadastro do e-mail*/
void ordenacaoVetor(); /*Função responsável pela ordenação dos vetores*/
void cadastrarEndereco(); /*Função responsável pelo cadastro da endereço*/
void cadastrarTel(); /*Função responsável pelo cadastro do telefone*/
void cadastrarDataConsulta(); /*Função responsável pela data de consulta*/
void cadastrarHorario(); /*Função responsável pelo cadastro da hora*/
void cadastrarmedico(); /*Função responsável pelo cadastro do médico*/
void pesquisar(); /*Função responsável por pesquisar o paciente*/
void backup(); /*Função responsável pelo backup de todos os dados cadastrados*/
void editar(); /*Função responsável pela edição completa do cadastro */
void excluir(); /*Função responsável por excluir o cadastro*/
void excluirId(); /*Função responsável pelo exclusão da ID*/
int buscaBinariaId(int id[], int tamamnho, int x); /*Função responsável pela busca binaria da ID e sua substituição*/

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
		do{ /* Estrutura de repetição que executa o código pelo menos uma vez */
		opc = menu();
		switch(opc){ /*Comando condicional que compara as condições de uma variavel, utilizamos para a criação do menu*/ 
			case 1:
				system("cls"); /*limpa a tela*/
				printf("\n XXXXXXX XXXXXXX XXXXXXX XXXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXX");
				printf("\nX XXXXX X XXXXX                                  X XXXXX X XXXXX X XXX");
				printf("\nXX XXX XXX XXXX      CADASTRAR NOVO PACIENTE     XX XXX XXX XXX XXX XX");
				printf("\nXXX X XXXXX XXX                                  XXX X XXXXX X XXXXX X");
				printf("\nXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXX \n\n");
				cadastrarId(); /*chamada da função */
				cadastrarNome();/*chamada da função */
				cadastrarEmail();/*chamada da função */
				cadastrarSexo();/*chamada da função */
				cadastrarVacina();/*chamada da função */
				cadastrarEndereco();/*chamada da função */
				cadastrarAltura();/*chamada da função */
				cadastrarTel();	/*chamada da função */
				printf("\n\n");			
				cadastrarDataConsulta();/*chamada da função */
				cadastrarHorario(); /*chamada da função */
				cadastrarmedico();				
				i++; /*controlador da posição do vetor */
				cont++;
				printf("\n\t\t\tCadastro realizado com sucesso!!!\n\n");				
				system("pause");
				break;
			case 2:
					ordenacaoVetor(); /*função de ordenação do vetor*/
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
			system ("pause"); /* pause na execução */
				break;
			case 3:
				system("cls");
				printf("\n XXXXXXX XXXXXXX XXXXXXX XXXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXX");
				printf("\nX XXXXX X XXXXX                                  X XXXXX X XXXXX X XXX");
				printf("\nXX XXX XXX XXXX  PESQUISAR PACIENTES CADASTRADOS XX XXX XXX XXX XXX XX");
				printf("\nXXX X XXXXX XXX                                  XXX X XXXXX X XXXXX X");
				printf("\nXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXX \n\n");
				pesquisar();	/* chamada de função*/		
			system ("pause");
				break;
			case 4:
				system("cls");
				printf("\n XXXXXXX XXXXXXX XXXXXXX XXXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXX");
				printf("\nX XXXXX X XXXXX                                  X XXXXX X XXXXX X XXX");
				printf("\nXX XXX XXX XXXX   EXCLUIR PACIENTES CADASTRADOS  XX XXX XXX XXX XXX XX");
				printf("\nXXX X XXXXX XXX                                  XXX X XXXXX X XXXXX X");
				printf("\nXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXX \n\n");
				excluir();	/* chamada de função*/	
			system ("pause");
			break;
			case 5:
				system("cls");
				printf("\n XXXXXXX XXXXXXX XXXXXXX XXXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXX");
				printf("\nX XXXXX X XXXXX                                  X XXXXX X XXXXX X XXX");
				printf("\nXX XXX XXX XXXX    EDITAR PACIENTES CADASTRADOS  XX XXX XXX XXX XXX XX");
				printf("\nXXX X XXXXX XXX                                  XXX X XXXXX X XXXXX X");
				printf("\nXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXX \n\n");
				editar();/* chamada de função*/	
			system ("pause");
				break;
			case 6:
               system("cls");
                printf("\n XXXXXXX XXXXXXX XXXXXXX XXXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXX");
				printf("\nX XXXXX X XXXXX                                  X XXXXX X XXXXX X XXX");
				printf("\nXX XXX XXX XXXX          REALIZAR BACKUP         XX XXX XXX XXX XXX XX");
				printf("\nXXX X XXXXX XXX                                  XXX X XXXXX X XXXXX X");
				printf("\nXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXXX XXXXXXX XXXXXXX XXXXXXX XXXXXXX \n\n");
				backup();/* chamada de função*/	
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
		idTemp = rand()%100000;/*geração de um Id automático por meio de numeros aleatórios*/

	}while (idTemp == idUsuario[i]); /*estrutura de repeticao para repetir a função randomica para geração de novo id, caso essejá exista */

	idUsuario[i] = idTemp;
	printf("ID Paciente...................................................: %i\n", idUsuario[i]);
}
void cadastrarNome(){ /*funcao para cadasrar nome*/
	do{
		printf("Informe o nome...............................................: ");
   		fgets(nome[i],sizeof(nome[i]), stdin); /* funcao para a leitura de uma string */
		if (strlen(nome[i])== 1){ /* verifica se a posicao está vazia */
			printf("Este campo nao pode ser vazio\n");
		}
	}while(strlen(nome[i])== 1);
}
void cadastrarSexo(){/*funcao para cadastrar sexo*/
	do{
		printf("Informe sexo: Masculino, Feminino ou Nao-declarado...........: ");
   		scanf("%s", sexo[i]);
		fflush(stdin); /*limpa buffer */
   		strupr(sexo[i]); //função que converte a string para maiúsculo.
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
			printf("valor não pode ser superior a 2.00 mts\n");
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
		strlwr(eMail[i]); //função que converte a string para minusculo.
		validador = strchr(eMail[i],'@'); //função que percorre a string comparando o caractere @ com cada caractere da string, caso não encontre retorna NULL.
		if(validador == NULL){/* condicional para verificar se o validor é == NULL, se for é porque não tem o @*/
			printf("digite um e-mail valido\n"); /*imprime na tela para o usuário digitar um email válido*/
		}
	}while(validador == NULL);/*estrutura de repetição euanquento a condição for verdadeira*/
}
void cadastrarTel(){ /*funcao para cadasrar nome*/
	do{
		printf("Informe o telefone...............................................: ");
   		fgets(telefone[i],sizeof(telefone[i]), stdin); /* funcao para a leitura de uma string */
		if (strlen(telefone[i])== 1){ /* verifica se a posicao está vazia */
			printf("Este campo nao pode ser vazio\n");
		}
	}while(strlen(telefone[i])== 1);
}
void cadastrarDataConsulta(){ /*funcao para cadasrar nome*/
	do{
		printf("Data de Agendamento...............................................: ");
   		fgets(dataConsult[i],sizeof(dataConsult[i]), stdin); /* funcao para a leitura de uma string */
		if (strlen(dataConsult[i])== 1){ /* verifica se a posicao está vazia */
			printf("Este campo nao pode ser vazio\n");
		}
		//getchar();
	}while(strlen(dataConsult[i])== 1);
}
void cadastrarHorario(){ /*funcao para cadasrar nome*/
	do{
		printf("Horario agendado...............................................: ");
   		fgets(horarioConsult[i],sizeof(horarioConsult[i]), stdin); /* funcao para a leitura de uma string */
		if (strlen(horarioConsult[i])== 1){ /* verifica se a posicao está vazia */
			printf("Este campo nao pode ser vazio\n");
		}
		//getchar();
	}while(strlen(horarioConsult[i])== 1);
}
void cadastrarmedico(){ /*funcao para cadasrar nome*/
	do{
		printf("Medico...............................................: ");
   		fgets(medico[i],sizeof(medico[i]), stdin); /* funcao para a leitura de uma string */
		if (strlen(medico[i])== 1){ /* verifica se a posicao está vazia */
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
		for(j = i+1; j < cont; j++){/*Estrutura para comparar a posição seguinte com a a*/
			if(idUsuario[i] > idUsuario[j]){ /*condicional que verifica se o id na posição i é maior que o id na posiçõo "j" seguinte */
				
				aux_idUsuario = idUsuario[i]; /*variavel auxiliar para armazenar os dados da variavel id na posição i*/
				idUsuario[i] = idUsuario[j];/*atribuição do valor de uma variavel na posição j para outra na posição i*/
				idUsuario[j] = aux_idUsuario;/*variavel na posicao j que vai receber os dados da variável auxiliar*/
				
				strcpy(Aux_nome,nome[i]);// strcpy funcao da biblioteca string.h para copiar um vetor de string para uma variavela auxiliar.
				strcpy(nome[i],nome[j]); /*atribuição do valor de uma variavel na posição j para outra na posição i*/
				strcpy(nome[j],Aux_nome); /*copiar os dados da variavel auxiliar para a variavel nome na posição j*/
				
				strcpy(auxEmail,eMail[i]); /*variavel auxiliar para armazenar os dados da string*/
				strcpy(eMail[i],eMail[j]); /*atribuição do valor de uma variavel na posição j para outra na posição i*/
				strcpy(eMail[j],auxEmail); /* copiar dados da variavel auxiliar para a posição J da variavel eMail*/
				
				strcpy(auxSexo,sexo[i]);/*variavel auxiliar para armazenar os dados da variavel altura na posição i*/
				strcpy(sexo[i],sexo[j]);/*atribuição do valor de uma variavel na posição j para outra na posição i*/
				strcpy(sexo[j],auxSexo);/* copiar dados de uma variavel auxiliar para a posição J do variavel sexo*/
				
				aux_vacina = vacina[i];/*variavel auxiliar para armazenar os dados da variavel altura na posição i*/
				vacina[i] = vacina[j];/*atribuição do valor de uma variavel na posição j para outra na posição i*/
				vacina[j] = aux_vacina;/* copiar dados da variavel auxiliar para a posição J do variavel vacina*/
				
				strcpy(auxEndereco,endereco[i]);/*variavel auxiliar para armazenar os dados da string*/
				strcpy(endereco[i],endereco[j]);/*atribuição do valor de uma variavel na posição j para outra na posição i*/
				strcpy(endereco[j],auxEndereco);/* copiar dados da variavel auxiliar para a posição J do variavel auxEndereco*/
				
				auxAltura = altura[i];/*variavel auxiliar para armazenar os dados da variavel altura na posição i*/
				altura[i] = altura[j]; /*atribuição do valor de uma variavel na posição j para outra na posição i*/
				altura[j] = auxAltura;	/* copiar dados da variavel auxiliar para a posição J do variavel altura*/	
				
				strcpy(aux_tel,telefone[i]);// strcpy funcao da biblioteca string.h para copiar um vetor de string para uma variavela auxiliar.
				strcpy(telefone[i],telefone[j]); /*atribuição do valor de uma variavel na posição j para outra na posição i*/
				strcpy(telefone[j],aux_tel); /*copiar os dados da variavel auxiliar para a variavel nome na posição j*/	
				
				strcpy(aux_datac,dataConsult[i]);// strcpy funcao da biblioteca string.h para copiar um vetor de string para uma variavela auxiliar.
				strcpy(dataConsult[i],dataConsult[j]); /*atribuição do valor de uma variavel na posição j para outra na posição i*/
				strcpy(dataConsult[j],aux_datac); /*copiar os dados da variavel auxiliar para a variavel nome na posição j*/
				
				strcpy(aux_hor,horarioConsult[i]);// strcpy funcao da biblioteca string.h para copiar um vetor de string para uma variavela auxiliar.
				strcpy(horarioConsult[i],horarioConsult[j]); /*atribuição do valor de uma variavel na posição j para outra na posição i*/
				strcpy(horarioConsult[j],aux_hor); /*copiar os dados da variavel auxiliar para a variavel nome na posição j*/
				
				strcpy(aux_med,medico[i]);// strcpy funcao da biblioteca string.h para copiar um vetor de string para uma variavela auxiliar.
				strcpy(medico[i],medico[j]); /*atribuição do valor de uma variavel na posição j para outra na posição i*/
				strcpy(medico[j],aux_med); /*copiar os dados da variavel auxiliar para a variavel nome na posição j*/	
								
			}	
		}
	}			
}
void pesquisar(){
	
	int idPesquisado, opcao, resultado=0,identificador = 0;
	char opcao2[50];
	do{
		
		printf("\nInforme a opcao de pesquisa:\n[1] ID\n[2] EMAIL\n");
		scanf("%d",&opcao); /*lê o Id a ser pesquisado*/
		printf("\nOpcao desejada: %d\n\n",opcao);
		
		if(opcao < 1 || opcao > 2){
			printf("Erro, opcao invalida\n\n");	/* valida se a escolha do usuário está dentro das opções oferecidas*/		
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
				strlwr(opcao2); //função que converte a string para minusculo.
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
		
		if(x==id[meio]){ /* verifica se o id está na posição do meio do vetor */
			return meio; /*se sim, retorna o do meio */
		}else if(x < id[meio]){ /* Senão verifica se o Id pesquisado é menor que o Id na posição do meio do vetor, se sim a pesquisa será até a metade do vetor*/
			fim = meio - 1;			
		}else{
			inicio = meio + 1;	/* senão o inicio será atualizado com a posição do meio + 1 e a pesquisa será realizada a partir daquela posição */		
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
		
	}while(opcao < 1 || opcao > 3);	/* estrutura de repeticao que executa pelo menos uma vez e enquanto as condições forem verdadeira*/
	
	
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
			printf("\n\tID Usuario...........................................: %i", bkp_idUsuario[i] ); /*Imprime um log com os Id's para mostrar para o usuário os Id's que fizemos backup*/						
		}
	}
	printf("\n\n");
}
void editar(){
	
	int id, identificador=0, opcao=0;	
	
	printf("Informe o Id do cadastro a ser editado: "); /*imprime a msg na tela*/
	scanf("%d", &id); /*lê o id que será editado*/
	fflush(stdin);

	for(i=0; i < cont; i++){ /* estrutura de repetição para percorrer o Vetor em busca do ID digitado */
		if(	idUsuario[i] == id){				
			cadastrarNome();
			cadastrarEmail();
			cadastrarSexo();
			cadastrarVacina();
			cadastrarEndereco();
			cadastrarAltura();
			cadastrarTel();
			identificador++; /*controla a entrada  da Id na condição criada*/			
			printf("\t\t\tCadastro editado com sucesso!\n\n");		
		}
	}
	if(identificador == 0){
		printf("Id nao foi localizado\n"); /*Imprime não localizado caso o identificador não entre na condicional do If*/
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura de dados do Usuario
typedef struct
{
  char nome[60];
  double saldo;
  int numero_De_Conta;
  int iban;
} Usuario;

// Estrutura de dados Dos Menus
typedef struct
{
  char nome[40];
  int numeroDaOpcao;
} Opcoes;

// Estrutura de dados do menu Inicial
Opcoes opcoesIniciais[] = {
    {"Usuario", 1},
    {"Pagamentos", 2},
    {"Consultas", 3},
    {"Sair", 0}};

// Estrutura de dados do menu Usuarios
Opcoes opcoesUsuario[] = {
    {"Criar Conta", 1},
    {"Editar Conta", 2},
    {"Apagar Conta", 3},
    {"Voltar Para Tela Incial", 0}};

// Estrutura de dados do menu Pagamentos
Opcoes opcoesPagamentos[] = {
    {"Transferir Dinheiro", 1},
    {"", 2},
    {"", 3},
    {"Voltar Para Tela Incial", 0}};

// Estrutura de dados do menu Consultas
Opcoes opcoesConsultas[] = {
    {"Consultar Saldo", 1},
    {"Consular Iban", 2},
    {"Consultas De Movimento", 3},
    {"Voltar Para Tela Incial", 0}};

// Variaveis Globais

Usuario usuario;
int escolha_Do_Usuario = 0;

// Declaracão dos procedimentos e Funcoes
void menu(Opcoes *opcoes);
void userInput(int escolha_do_usuario);
void tela_Inicial(void);
void logotipo_Do_Banco(void);
void lista_De_Opcoes(Opcoes *opcoes, int tamanho_Das_Opcoes);

// Incio do nosso programa
int main(int argc, char const *argv[])
{

  // Procedimentos para a chamar a tela inicial
  tela_Inicial();
  return 0;
}

// Tela inicial do programa
void tela_Inicial()
{
label1:
  logotipo_Do_Banco();
  lista_De_Opcoes(opcoesIniciais, (sizeof(opcoesIniciais) / sizeof(opcoesIniciais[0])));
  scanf("%d", &escolha_Do_Usuario);

  switch (escolha_Do_Usuario)
  {
  case 0:
    userInput(0);
    break;
  case 1:
    userInput(1);
    break;
  case 2:
    userInput(2);
    break;
  case 3:
    userInput(3);
    break;

  default:
    system("clear");
    // sleep(2);
    printf("\nErro: As opções vão de 0 a 3.\n");
    printf("Pressiona qualquer tecla para continuar... \n");
    getchar();
    goto label1;
    break;
  }
}

void menu(Opcoes *opcoes)
{
  Opcoes *opcoes2 = NULL;
  opcoes2 = opcoesPagamentos;
  logotipo_Do_Banco();
  lista_De_Opcoes(opcoes2, (sizeof(opcoes2) / sizeof(opcoes2[0])));
}

// Funções responsaveis por criar o Usuario

// Funcao para criar usuario
Usuario criarUsuario()
{
  char nome[60];
  char sobrenome[20];
  double saldo = 20.000;
  int numeroDeConta;
  int iban;
  Usuario usuario;

  printf("\t\tNome: ");
  scanf("%s", nome);
  puts("");
  printf("\t\tSobenome: ");
  scanf("%s", sobrenome);
  puts("");
  printf("\t\tValor de deposito de entrada: ");
  scanf("%lf", &saldo);

  strcat(nome, sobrenome);
  strcpy(usuario.nome, nome);
  usuario.saldo = saldo;
  usuario.iban = 1219301;
  usuario.numero_De_Conta = 121930;

  return usuario;
}

/*
Usuario editarUsuario(Usuario usuario) {
  char nome[60];
  puts("\t\tNome Completo: ");
  scanf("%s",nome);

  strcpy(usuario.nome,nome);

  return usuario;

}


apagarUsuario() {
  char nome[60];
  int numeroDeConta ;
  int iban;
  Usuario usuario;
  puts("Nome Completo: ");
  scanf("%s",nome);

  return usuario;

} */

// Funcao que valida escolha do usuario
void userInput(int escolha_do_usuario)
{

  if (escolha_do_usuario == 1)
  {
    // Chama o menu de escolhas para o usuario
    logotipo_Do_Banco();
    lista_De_Opcoes(opcoesUsuario, (sizeof(opcoesUsuario) / sizeof(opcoesUsuario[0])));
    scanf("%d", &escolha_Do_Usuario);

    if (escolha_Do_Usuario == 1)
    {
      Usuario novo_Usuario = criarUsuario(usuario);
      char extensao_do_arquivo[] = ".txt";
      char nome_do_arquivo_usuario[60];

      strcpy(nome_do_arquivo_usuario, novo_Usuario.nome);
      strcat(nome_do_arquivo_usuario, extensao_do_arquivo);

      FILE *arquivo = fopen(nome_do_arquivo_usuario, "w");

      fprintf(arquivo, "%s\n", novo_Usuario.nome);
      fprintf(arquivo, "%.3lf\n", novo_Usuario.saldo);
      fprintf(arquivo, "%d\n", novo_Usuario.numero_De_Conta);
      fprintf(arquivo, "%d", novo_Usuario.iban);

      fclose(arquivo);

      system("clear");
      sleep(1);

      logotipo_Do_Banco();
      sleep(1);

      puts("\t\tCriando Usuario...");
      puts("");

      sleep(2);
      system("clear");

      logotipo_Do_Banco();
      puts("\t\tUsuario criado com sucesso...");
      puts("");

      printf("\t\tNome : %s\n\n\t\tSaldo Disponivel: %.3lf\n\n\t\tNumero da conta: %d\n\n\t\tIBAN: %d\n", novo_Usuario.nome, novo_Usuario.saldo, novo_Usuario.numero_De_Conta, novo_Usuario.iban);

      sleep(3);
      system("clear");

      tela_Inicial();
    }
    else if (escolha_Do_Usuario == 2)
    {
      /* Usuario editar_Usuario = criarUsuario();
      system("clear");
      sleep(1);

      logotipo_Do_Banco();
      sleep(1);

      puts("\t\tEditando Usuario...");
      puts("");

      sleep(2);
      system("clear");

      logotipo_Do_Banco();
      puts("\t\tUsuario criado com sucesso...");
      puts("");

      printf("\t\tNome : %s\n\n\t\tNumero da conta: %d\n\n\t\tIBAN: %d\n", editar_Usuario.nome,editar_Usuario.numero_De_Conta,editar_Usuario.iban);

      sleep(3);
      system("clear");

      tela_Inicial(); */
    }
    else if (escolha_Do_Usuario == 3)
    {
    }
    else if (escolha_Do_Usuario == 0)
    {
    }
    else
      printf("Escolha invalidado");
  }
  else if (escolha_do_usuario == 2)
  {

    // Chama o menu de escolhas para o pagamentos
    logotipo_Do_Banco();
    lista_De_Opcoes(opcoesPagamentos, (sizeof(opcoesPagamentos) / sizeof(opcoesPagamentos[0])));
    scanf("%d", &escolha_Do_Usuario);
  }
  else if (escolha_do_usuario == 3)
  {

    // Chama o menu de escolhas para o Movimentos
    logotipo_Do_Banco();
    lista_De_Opcoes(opcoesPagamentos, (sizeof(opcoesPagamentos) / sizeof(opcoesPagamentos[0])));
    scanf("%d", &escolha_Do_Usuario);
  }
  else if (escolha_do_usuario == 0)
  {

    exit(0);
  }
  else // Very rare case message
    printf("\n>> Unexpected Error occured. Report to program Administrator << \n");
}

// Funcão responsavel por exibir os elementos da estrutura de dados presentes na lista
void lista_De_Opcoes(Opcoes *opcoes, int tamanho_Das_Opcoes)
{
  for (int i = 0; i < tamanho_Das_Opcoes; i++)
  {
    printf("\t\t [%d] %s\n", opcoes[i].numeroDaOpcao, opcoes[i].nome);
    puts("");
  }
}

// Função responsavel por mostra o logo do banco
void logotipo_Do_Banco()
{
  puts("\t============================================");
  puts("\t\t\tBANCO MONAMI");
  puts("\t============================================");
  puts("");
  puts("");
}

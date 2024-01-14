#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>

// Estrutura de dados do Usuario
typedef struct
{
  char nome[30];
  char sobrenome[30];
  char nomeCompleto[60];
  double saldo;
  int numero_De_Conta;
  int iban;
} Usuario;

// Estrutura de dados para query na BD
typedef struct
{
  char nome[60];
} UsuarioConsulta;

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
    {"Consulta De Movimentos", 3},
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
void trabalhando_na_funcionalidade(void);

// Incio do nosso programa
int main(int argc, char const *argv[])
{
  mkdir("Database", 0777);
  mkdir("Database/usuario", 0777);
  mkdir("Database/transferencia", 0777);
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
  system("clear");
  sleep(1);

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
    sleep(2);
    printf("\nErro: As opções vão de 0 a 3.\n");
    /*  printf("Pressiona qualquer tecla para continuar... \n");
     getchar();
     goto label1; */
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

void substituir_primeira_linha(const char *arquivo_original, char *conteudo_novo, const char *novo_nome_arquivo)
{
  // Abre o arquivo original
  FILE *arquivo = fopen(arquivo_original, "r+");
  if (arquivo == NULL)
  {
    // O arquivo não existe
    return;
  }

  // Lê a primeira linha do arquivo
  char linha_1[100];
  fgets(linha_1, sizeof(linha_1), arquivo);

  // Atualiza o conteúdo da primeira linha
  fseek(arquivo, 0, SEEK_SET);
  fprintf(arquivo, "%s\n", conteudo_novo);

  // Fecha o arquivo original
  fclose(arquivo);

  // Adiciona o novo caminho para o arquivo
  // strcat(caminho_para_novo_arq,novo_nome_arquivo);

  // Renomeia o arquivo
  rename(arquivo_original, novo_nome_arquivo);
}
// Funções responsaveis por criar o Usuario
int procurar_arquivo(const char *diretorio, const char *nome_arquivo)
{
  // Abre o diretório
  DIR *diretorio_arquivo = opendir(diretorio);
  if (diretorio_arquivo == NULL)
  {
    return -1;
  }

  // Itera sobre os arquivos no diretório
  struct dirent *arquivo;
  while ((arquivo = readdir(diretorio_arquivo)) != NULL)
  {
    // Verifica se o arquivo é o arquivo que estamos procurando
    if (strcmp(arquivo->d_name, nome_arquivo) == 0)
    {
      // O arquivo foi encontrado
      closedir(diretorio_arquivo);
      return 1;
    }
  }

  // O arquivo não foi encontrado
  closedir(diretorio_arquivo);
  return 0;
}

// Funcao para criar usuario
Usuario criarUsuario()
{
  char nome[30];
  char sobrenome[30];
  char nomeCompleto[60];
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

  strcpy(nomeCompleto, nome);
  strcat(nomeCompleto, " ");
  strcat(nomeCompleto, sobrenome);
  strcpy(usuario.nome, nome);
  strcpy(usuario.sobrenome, sobrenome);
  strcpy(usuario.nomeCompleto, nomeCompleto);
  usuario.saldo = saldo;
  usuario.iban = 1219301;
  usuario.numero_De_Conta = 121930;

  return usuario;
}

UsuarioConsulta editarUsuario()
{
  // Dados antigos

  char nomeAntigo[60];
  char sobrenomeAntigo[30];
  char extensao_do_arquivo[] = ".txt";
  char nome_do_arquivo_usuarioAntigo[60];
  char caminho_para_salvar_arq[300] = "./Database/usuario/";
  char caminho_para_salvar_novo_arq[300] = "./Database/usuario/";

  char nome[30];
  char sobrenome[30];
  char nomeCompleto[60];
  char nome_do_novo_arquivo[60];

  UsuarioConsulta usuario;

  puts("\t\tDigite os seus antigos dados...");
  printf("\t\tNome: ");
  scanf("%s", nomeAntigo);
  puts("");
  printf("\t\tSobenome: ");
  scanf("%s", sobrenomeAntigo);
  puts("");

  strcat(nomeAntigo, sobrenomeAntigo);

  strcpy(nome_do_arquivo_usuarioAntigo, nomeAntigo);
  strcat(nome_do_arquivo_usuarioAntigo, extensao_do_arquivo);

  int res = procurar_arquivo(caminho_para_salvar_arq, nome_do_arquivo_usuarioAntigo);

  if (res == -1)
  {
    puts("Dir não escontrado");
  }
  else if (res == 1)
  {
    puts("");
    puts("");
    puts("");
    puts("\t\tDigite os novos dados...");
    puts("");
    puts("");
    printf("\t\tNome: ");
    scanf("%s", nome);
    puts("");
    printf("\t\tSobenome: ");
    scanf("%s", sobrenome);
    puts("");

    strcpy(nomeCompleto, nome);
    strcat(nomeCompleto, " ");
    strcat(nomeCompleto, sobrenome);

    // Nome do novo arquivo
    strcpy(nome_do_novo_arquivo, nome);
    strcat(nome_do_novo_arquivo, sobrenome);
    strcat(nome_do_novo_arquivo, extensao_do_arquivo);

    // Crinado dir para salvar o arquivo
    strcpy(caminho_para_salvar_arq, caminho_para_salvar_novo_arq);
    strcat(caminho_para_salvar_arq, nome_do_arquivo_usuarioAntigo);
    strcat(caminho_para_salvar_novo_arq, nome_do_novo_arquivo);

    substituir_primeira_linha(caminho_para_salvar_arq, nomeCompleto, caminho_para_salvar_novo_arq);
  }
  else if (res == 0)
  {
    puts("Arquivo nao encontrado");
  }

  return usuario;
}

Usuario apagarUsuario()
{
  char nome[60];
  int numeroDeConta;
  int iban;
  Usuario usuario;
  puts("Nome Completo: ");
  scanf("%s", nome);

  return usuario;
}

// Funcao que valida escolha do usuario
void userInput(int escolha_do_usuario)
{

  if (escolha_do_usuario == 1)
  {
    // Chama o menu de escolhas para o usuario
    logotipo_Do_Banco();
    lista_De_Opcoes(opcoesUsuario, (sizeof(opcoesUsuario) / sizeof(opcoesUsuario[0])));
    scanf("%d", &escolha_Do_Usuario);
    system("clear");
    sleep(1);

    if (escolha_Do_Usuario == 1) // Criar usuario
    {
      Usuario novo_Usuario = criarUsuario(usuario);
      char extensao_do_arquivo[] = ".txt";
      char nome_do_arquivo_usuario[60];
      char caminho_para_salvar_arq[200] = "./Database/usuario/";

      strcpy(nome_do_arquivo_usuario, novo_Usuario.nome);
      strcat(nome_do_arquivo_usuario, novo_Usuario.sobrenome);
      strcat(nome_do_arquivo_usuario, extensao_do_arquivo);
      strcat(caminho_para_salvar_arq, nome_do_arquivo_usuario);

      FILE *arquivo = fopen(caminho_para_salvar_arq, "w");

      fprintf(arquivo, "%s\n", novo_Usuario.nomeCompleto);
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

      printf("\t\tNome : %s\n\n\t\tSaldo Disponivel: %lf\n\n\t\tNumero da conta: %d\n\n\t\tIBAN: %d\n", novo_Usuario.nomeCompleto, novo_Usuario.saldo, novo_Usuario.numero_De_Conta, novo_Usuario.iban);

      sleep(6);
      system("clear");

      tela_Inicial();
    }
    else if (escolha_Do_Usuario == 2) // Editar usuario
    {

      UsuarioConsulta usuario_Editado = editarUsuario();
    }
    else if (escolha_Do_Usuario == 3)
    {
      trabalhando_na_funcionalidade();
      tela_Inicial();
    }
    else if (escolha_Do_Usuario == 0)
    {
      tela_Inicial();
    }
    else
      tela_Inicial();
  }
  else if (escolha_do_usuario == 2)
  {

    // Chama o menu de escolhas para o pagamentos
    logotipo_Do_Banco();
    lista_De_Opcoes(opcoesPagamentos, (sizeof(opcoesPagamentos) / sizeof(opcoesPagamentos[0])));
    scanf("%d", &escolha_Do_Usuario);

    if (escolha_Do_Usuario == 0)
    {
      trabalhando_na_funcionalidade();
      system("clear");
      sleep(1);
      tela_Inicial();
    }
    else if (escolha_Do_Usuario == 1)
    {
      trabalhando_na_funcionalidade();
      system("clear");
      sleep(1);
      tela_Inicial();
    }
    else
    {
      puts("\t\tESCOLHA INVALIDA");
      system("clear");
      tela_Inicial();
    }
  }
  else if (escolha_do_usuario == 3)
  {

    // Chama o menu de escolhas para o Movimentos
    logotipo_Do_Banco();
    lista_De_Opcoes(opcoesConsultas, (sizeof(opcoesConsultas) / sizeof(opcoesConsultas[0])));
    scanf("%d", &escolha_Do_Usuario);

    if (escolha_Do_Usuario == 0)
    {3
      system("clear");
      sleep(1);
      tela_Inicial();
    }
    else if (escolha_Do_Usuario == 1)
    {
      trabalhando_na_funcionalidade();
      system("clear");
      sleep(1);
      tela_Inicial();
    }
     else if (escolha_Do_Usuario == 2)
    {
      trabalhando_na_funcionalidade();
      system("clear");
      sleep(1);
      tela_Inicial();
    }
     else if (escolha_Do_Usuario == 3)
    {
      trabalhando_na_funcionalidade();
      system("clear");
      sleep(1);
      tela_Inicial();
    }
    else
    {
      puts("\t\tESCOLHA INVALIDA");
      system("clear");
      tela_Inicial();
    }
  }
  else if (escolha_do_usuario == 0)
  {

    exit(0);
  }
  else
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

void trabalhando_na_funcionalidade()
{
  printf("\t\tEsta funcionalidade esta em Desenvolvimento\n\n");
  sleep(5);
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

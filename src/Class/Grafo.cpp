#include <iostream>
#include <fstream> // Open File
#include <string>
#include <sstream>

#include "../Headers/Grafo.h" // .h Grafo
#include "../Headers/Lista.h"

using namespace std;

// Construtores e destrutor da classe
//
//

/*
 * Grafo() irá construir a classe quando não precisar
 * fazer a leitura de um arquivo de entrada para um 
 * grafo, assim, necessitando que o usuário adicione
 * arestas e vertices para proceguir com  as funções.
 */
Grafo::Grafo()
{
  cout << "Construindo Grafo" << endl;

  vertices = new Lista();

  arquivoIn = NULL;
  arquivoOut = NULL;

  numeroArestas = 0;
  numeroVertices = 0;
}

/*
 * Grafo(arquivoIn) espera o local do arquivo para 
 * leitura, assim construindo o grafo a partir desse
 */
Grafo::Grafo(string in)
{
  cout << "Construindo Grafo" << endl;

  vertices = new Lista();

  arquivoIn = new string;
  *arquivoIn = in;

  arquivoOut = NULL;

  numeroArestas = 0;
  numeroVertices = 0;

  leArquivo();
}

/*
 * Grafo(arquivoIn, arquivoOut) recebe o local do 
 * arquivo para leitura para contruir o grafo a partir
 * dos dados nele e o local do arquivo de saída das
 * análiizes do processamento
 */
Grafo::Grafo(string in, string out)
{
  cout << "Construindo Grafo" << endl;
  
  vertices = new Lista();

  arquivoIn = new string;
  *arquivoIn = in;

  arquivoOut = new string;
  *arquivoOut = out;

  numeroArestas = 0;
  numeroVertices = 0;

  leArquivo();
}

/*
 * ~Grafo() analiza memória alocada dinamicamente
 * que está sendo utilizado pela classe para 
 * desalocar e liberar o espaço.
 */
Grafo::~Grafo()
{
  cout << "Destruindo Grafo" << endl;
  
  delete vertices;

  if (arquivoIn)
    delete arquivoIn;
  if (arquivoOut)
    delete arquivoOut;
}
//
//
// End Contrutores e Destrutores

/*
 * leArquivo() faz a leitura do arquivo
 * de entrada e coloca em variáveis 
 * para o processamento
 */
void Grafo::leArquivo()
{
  fstream file;

  file.open(*arquivoIn);

  if(file.is_open())
  {
    bool link = false;
    while(!file.eof())
    {
      string str;
      getline(file, str);
      if(str[0] >= '0' && str[0] <= '9')
      {
        stringstream line(str);
        if(link)
        {
          int lixo, peso;
          string verticeA, verticeB;
          
          line >> lixo;
          line >> verticeA >> verticeB >> peso;
        
          //insere aresta

        }
        else
        {
          string vertice;
          int lixo,  peso;

          line >> vertice;
          line >> lixo;
          line >> lixo;
          line >> peso;

          vertices->insereVertice(vertice,  peso);
          numeroVertices++;
        }
      }
      else if(str == "link")
        link = true;
    }
  }
  else
  {
    cout << "Erro ao carregar arquivo" << endl;
  }
}

/*
 * ExportaGrafo() Exporta os dados 
 * analizados durante a execução do
 * programa com determinada entrada
 */
/*
void Grafo::exportaGrafo()
{
  cout << "Exportando analizes do Grafo!" << endl;

  if(0)
  {
    cout << "Exportando" << endl; // continuar com o export
  }
  else
    cout << "Erro ao exportar! Grafo não encontrado." << endl;  
}
*/
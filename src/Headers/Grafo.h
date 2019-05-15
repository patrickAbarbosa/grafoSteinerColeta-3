#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>

#include "Lista.h"
#include "Vertice.h"
#include "./Data.h"

using namespace std;

class Grafo
{
public:
  Grafo();
  Grafo(string in);
  Grafo(string in, string out);
  Grafo(string in, string out, string ehDigrafo);
  ~Grafo();

  //Public functions
  
  void addAresta(string id_a, string id_b, int peso);
  void deletaAresta(string id_a, string id_b);
  void imprimeGrafoPNG();
  void menuSelecionado(char a);
  void menu();
  Lista * getVertices(){ return vertices;}

  void buscaPorProfundidade(string verticeInicial);
  void buscaPorLargura(string verticeInicial);
  Vertice **ordenacaoTopologica();
  Grafo *complementar();

  void algoritmoKruskal();
  int algoritmoDijkstra(string origem, string destino);
  Grafo* algoritmoPrim();
  void auxPrim();

  //resolucao do problema de steiner

  int custo (Grafo * arvore);
  int auxGuloso(Vertice * p, Grafo * resultado);
  int guloso(Vertice * vertice_inicial);
  
  
  private:
    Lista  *vertices;
 
    string *arquivoIn;
    string *arquivoOut;
    
    int numeroArestas;
    int numeroVertices;

    bool ehDigrafo;
    Aresta * menorValor;

    Data *db;
    //private functions
    void leArquivo();
    void exportGrafo();
    void auxBuscaPorProfundidade(Vertice *vertice, vector <string> *nosLidos);
    bool ehConexo();
    void auxAddAresta(Vertice *a,  Vertice *b, int peso);
    int auxOrdenacaoTopologica(int vet[], int tam);
    Vertice **montaVetorVertices(int *cont, int tam);

};

#endif // GRAFO_H_INCLUDED

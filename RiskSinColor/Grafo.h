//
// Created by estudiante on 17/11/2023.
//

#ifndef RISKSINCOLOR_GRAFO_H
#define RISKSINCOLOR_GRAFO_H

#include <vector>
#include <list>
#include <utility>
#include <queue>
#include <string>
#include "PaisG.h"
#include "Carta.h"

class Grafo{
private:
    std::vector < PaisG > paises;
    std::vector < std::list < std::pair < int, int > > > conexiones;
public:
    //constructors
    Grafo();

    //getters
    std::vector < PaisG > getPaises();
    std::vector < std::list < std::pair < int, int > > > getEdges();

    //inserting
    bool addVertex(PaisG& vertex);
    bool addEdge(PaisG& origin, PaisG& destination, int cost);

    //searching
    int searchVertice(int vertex);
    bool searchEdge(int origin, int destination);

    //tours
    void plain();
    void showEdges();

    //inicializacion
    bool paisLleno(int idPais);
    void ocuparPais(int idJugador, int idPais, int unidades);
    bool lleno();

    //turno
    int calcularPaisesJugador(int idJugador);
    bool jugadorPuedeUbicar(int idJugador);
    bool paisFortificable(int idJugador, int idPais);
    int intercambioPaises(int idJugador, std::list<std::string>& continentes);
    bool jugadorOcupaPais(int idJugador, int idPais);

    //atacar
    bool puedeAtacar(int idJugador);
    bool paisAtacable(int idJugador, int idPais);
    bool origenAptoParaAtaque(int idJugador, int idPais);
    bool quitarUnidad(int idPais);

    //fortificar
    bool puedeFortificar(int idJugador);
    bool unidadesSuficientes(int idJugador, int idPais, int unidades);
    bool aptoParaFortificar(int idJugador, int idPais);
    void moverUnidades(int idJugador, int origen, int destino, int unidadesM);

    //algoritmos
    void conquistaMasBarata(int idJugador);
    void updateCosts();
    int dijkstra(int initial, int idJugador, std::vector<int>& distance, std::vector<std::list<int>>& paths);
    void conquistaCosto (int idJugador, int idPais);
    int dijkstraCostoConquista(int initial, int idJugador, int idPais, std::vector<int>& distance, std::vector<std::list<int>>& paths);
};

#endif //RISKSINCOLOR_GRAFO_H

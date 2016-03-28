#ifndef		__NEIGHBOR_OPERATOR_KP__
#define		__NEIGHBOR_OPERATOR_KP__

#include <vector>
#include <cmath>

#include "../lib/Miscelanea.hpp"

#include "SolucionMochila.hpp"


using namespace std;


class neighborOperatorKP{


	private:

		int _KPSize;						//Tamaño de la mochila
		vector <problem_element> _info;		//Informacion de cada elemento de la mochila

	public:

		//Constructor vacio
		neighborOperatorKP(){};
		neighborOperatorKP(const int KPSize, const vector <problem_element> &info){

			_KPSize = KPSize;
			_info = info;
		};


		//Metodo que genera un vecino de una solucion, teniendo en cuenta unos parametros
		SolucionMochila generateNeighbor(SolucionMochila &initialSolution, vector<int> &parametros){

		int i;
		SolucionMochila solucion(initialSolution);
		
		for (i = 0; i < parametros.size(); i++){
			solucion.setSolucion(parametros[i], abs(solucion.getSolucion(parametros[i]) - 1));
		}
				

                return solucion;
		}
		
		//Metodo que genera un vecino, invirtiendo un unico bit de una solucion dada
		SolucionMochila generateNeighbor(SolucionMochila &initialSolution, int pos){

			SolucionMochila solucion(initialSolution);
			solucion.setSolucion(pos, abs(solucion.getSolucion(pos) - 1));

		  return solucion;
		}
	

};

#endif
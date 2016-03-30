#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>


#include "lib/Interfaz.hpp"

#include "lib/Instance.hpp"
#include "kp/InstanceKP.hpp"
#include "tsp/InstanceTSP.hpp"
#include "kp/SolucionMochila.hpp"
#include "tsp/SolucionViajante.hpp"
#include "kp/SolGeneratorMochila.hpp"
#include "tsp/SolGeneratorViajante.hpp"

#include "kp/localSearchKP.hpp"
#include "tsp/localSearchTSP.hpp"
#include "kp/neighborExploratorKP.hpp"
#include "tsp/neighborExploratorTSP.hpp"
#include "kp/neighborOperatorKP.hpp"
#include "tsp/neighborOperatorTSP.hpp"



using namespace std;

int main(int argc, char **argv) {


	Interfaz cli;
	int i;
	int veces;
	srand(time(NULL));


	//Siempre se ejcuta hasta que el usuario quiera salir
	while(true) {

		if(not cli.option_menu())
			break;


		//Se ejecuta hasta que se carga una instancia de un fichero valido
		vector<problem_element> info = cli.read_instance(veces);



		//El problema seleccionado es TSP
		if(cli.getOpt() == 1){

			neighborOperatorTSP operadorVecindario(info);
			solGeneratorViajante randomSolution();

			//Generamos la solucion aleatoria inicial
			SolucionViajante initialSolution();
			initialSolution = randomSolution.randomSolutionGenerator(info.size());


			//Escogemos la primera mejora
			if(cli.getOptExplo() == 1){


				double localOptimumFitness;
				SolucionViajante localOptimumSolution();

				firstImprovementTSP exploradorVecindario(operadorVecindario);
				localSearchTSP busquedaLocal(operadorVecindario, exploradorVecindario);

				//Ejecutamos la busqueda local
				busquedaLocal.localOptimum(initialSolution, localOptimumSolution, localOptimumFitness);
			}


			//Escogemos la mejor mejora
			else{

				double localOptimumFitness;
				SolucionViajante localOptimumSolution();

				bestImprovementTSP exploradorVecindario(operadorVecindario);
				localSearchTSP busquedaLocal(operadorVecindario, exploradorVecindario);

				//Ejecutamos la busqueda local
				busquedaLocal.localOptimum(initialSolution, localOptimumSolution, localOptimumFitness);

			}



			//Por aqui habria que mostrar / guardar los resultados


		}
		/*####################################################################################*/
		/*####################################################################################*/



		//El problema seleccionado es KP
		else{


			neighborOperatorKP operadorVecindario(info);
			solGeneratorMochila randomSolution();

			//Generamos la solucion aleatoria inicial
			SolucionMochila initialSolution();
			initialSolution = randomSolution.randomSolutionGenerator(info.size());


			if(cli.getOptExplo() == 1){


				double localOptimumFitness;
				SolucionMochila localOptimumSolution();

				firstImprovementKP exploradorVecindario(operadorVecindario);
				localSearchKP busquedaLocal(operadorVecindario, exploradorVecindario);

				//Ejecutamos la busqueda local
				busquedaLocal.localOptimum(initialSolution, localOptimumSolution, localOptimumFitness);
			}



			else{

				double localOptimumFitness2;
				SolucionMochila localOptimumSolution2();

				bestImprovementKP exploradorVecindario(operadorVecindario);
				localSearchKP busquedaLocal(operadorVecindario, exploradorVecindario);

				//Ejecutamos la busqueda local
				busquedaLocal.localOptimum(initialSolution, localOptimumSolution, localOptimumFitness);

			}


			//Por aqui habria que mostrar / guardar los resultados
		}




	}	//Fin while(true)

	return 0;
}

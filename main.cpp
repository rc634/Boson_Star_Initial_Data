#include <iostream>
#include "BosonStarParams.hpp"
#include "BosonStarSolution.hpp"
#include "BosonStarSolution.impl.hpp"
#include "cmath"
#include <vector>

int main()
{
	double r_max = 512.;

	BosonStarParams a_BosonStarParams;


	double time_prev, time_new;

	/*for (int i = 0; i < 8; ++i)
	{
		time_prev = time(NULL);
		std::cout << "Gridsize : " << a_BosonStarParams.gridpoints << ", L : " << r_max << std::endl;
		BosonStarSolution a_boson_star;
		a_boson_star.set_initialcondition_params(a_BosonStarParams, r_max);
		a_boson_star.main();
		a_BosonStarParams.gridpoints = 2*a_BosonStarParams.gridpoints;
		time_new = time(NULL);
		std::cout << "Computation time : " << time_new - time_prev << " seconds" << std::endl << std::endl;
	}*/

	time_prev = time(NULL);

	BosonStarSolution a_boson_star;
	a_boson_star.set_initialcondition_params(a_BosonStarParams, r_max);
	a_boson_star.main();
	a_boson_star.output_csv();

	time_new = time(NULL);
	std::cout << "Computation time : " << time_new - time_prev << " seconds" << std::endl << std::endl;

	return 0;
}

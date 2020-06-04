#include <iostream>
#include "BosonStarParams.hpp"
#include "BosonStarSolution.hpp"
#include "BosonStarSolution.impl.hpp"
#include "cmath"
#include <vector>

int main()
{
	double r_max = 500.;

	BosonStarParams a_BosonStarParams;

	BosonStarSolution a_boson_star;

	a_boson_star.set_initialcondition_params(a_BosonStarParams, r_max);

	a_boson_star.main();

	a_boson_star.output_csv();

	return 0;
}
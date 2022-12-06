#include <iostream>
#include "BosonStarParams.hpp"
#include "BosonStarSolution.hpp"
#include "BosonStarSolution.impl.hpp"
#include "cmath"
#include <vector>

int main()
{
	double r_max = 1024., target_mass = 0.6031877;

	double upper_phi = 0.06, lower_phi = 0.01, mid_phi;

	BosonStarParams a_BosonStarParams;

	std::cout.precision(15);

	double m, r;

	double time_prev, time_new;

	std::ofstream mass_phi_file;//, mass_r_file;
	//mass_r_file.open("mass_vs_r.csv");
	mass_phi_file.open("mass_vs_phi.csv");

	for (int i = 0; i < 40; ++i)
	{
        mid_phi = 0.5*(upper_phi+lower_phi);
        std::cout << "+==============================================+" << std::endl;
		std::cout << "Iteration : " << i << std::endl;
		time_prev = time(NULL);
		std::cout << "Gridsize : " << a_BosonStarParams.gridpoints << ", L : " << r_max << std::endl;
		BosonStarSolution a_boson_star;
		a_BosonStarParams.central_amplitude_CSF = mid_phi;
		a_boson_star.set_initialcondition_params(a_BosonStarParams, r_max);
		a_boson_star.main();
		time_new = time(NULL);
		std::cout << "Upper bisection" << std::endl;
		std::cout << "Computation time : " << time_new - time_prev << " seconds" << std::endl << std::endl;
		//a_boson_star.output_csv();
		m = a_boson_star.get_mass();
		r = a_boson_star.get_r(0.01);
		mass_phi_file << a_BosonStarParams.central_amplitude_CSF << ", " << m << ", " << std::endl;
		//mass_r_file << r << ", " << m << ", " << std::endl;
		if (m > target_mass) upper_phi = mid_phi;
		else lower_phi = mid_phi;
	}

	mass_phi_file.close();
	//mass_r_file.close();



    /*
    BosonStarSolution a_boson_star;
    a_boson_star.set_initialcondition_params(a_BosonStarParams, r_max);
	a_boson_star.main();
	a_boson_star.output_csv();*/


	return 0;
}

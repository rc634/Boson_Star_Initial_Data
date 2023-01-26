#include <iostream>
#include "BosonStarParams.hpp"
#include "BosonStarSolution.hpp"
#include "BosonStarSolution.impl.hpp"
#include "cmath"
#include <vector>

int main()
{
	// maximum radius of solution, not stored in default params
	double r_max = 128.;

	// default parameters stored in BosonStarParams.hpp
	BosonStarParams a_BosonStarParams; 

	// working precision
	std::cout.precision(7); 

	// mass and radius of star
	double m, r;

	// used to time program
	double time_prev, time_new;

    // files for saving data
	std::ofstream mass_phi_file;//, mass_r_file;
	//mass_r_file.open("mass_vs_r.csv");
	mass_phi_file.open("mass_vs_phi.csv");

	for (int i = 0; i < 1; ++i)
	{

		// Print out parameters to terminal - can ignore if desired
		std::cout << "#############" << std::endl;
		std::cout << "Iteration : " << i << std::endl;
		time_prev = time(NULL);
		std::cout << "Gridsize : " << a_BosonStarParams.gridpoints << ", L : " << r_max << std::endl;
		std::cout << "#############" << std::endl;

		// initialise boson star object
		BosonStarSolution a_boson_star;

		// can set boson star params here if desired
		// useful if you want to loop over different settings
        //a_BosonStarParams.central_amplitude_CSF = 0.03775;


		a_boson_star.set_initialcondition_params(a_BosonStarParams, r_max);
		a_boson_star.main();
		time_new = time(NULL);
		std::cout << "Computation time : " << time_new - time_prev << " seconds" << std::endl << std::endl;
		//a_boson_star.output_csv();
		m = a_boson_star.get_mass();
		r = a_boson_star.get_r(0.01);
		mass_phi_file << a_BosonStarParams.central_amplitude_CSF << ", " << m << ", " << std::endl;
		//mass_r_file << r << ", " << m << ", " << std::endl;

		// Setup the parameters for each star and printout to terminal 
		std::cout << "#############" << std::endl;
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

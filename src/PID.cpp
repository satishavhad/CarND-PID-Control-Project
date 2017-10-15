#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {

	/*
	* Coefficients
	*/
	PID::Kp = Kp;
	PID::Ki = Ki;
	PID::Kd = Kd;

	/*
	* Errors
	*/
	p_error = 0.0;
	i_error = 0.0;
	d_error = 0.0;

}

void PID::UpdateError(double cte) {

	d_error = cte - p_error; // difference between old and new CTE
	p_error = cte;  // p_error becomes new CTE 
	i_error += cte; // Cumulative CTE
}

double PID::TotalError() {

	return -Kp*p_error - Kd*d_error - Ki*i_error;  // Compute and return total error
}


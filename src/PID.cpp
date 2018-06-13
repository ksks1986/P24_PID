#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	this->Kp = Kp;
	this->Ki = Ki;
	this->Kd = Kd;

	p_error = 0.0;
	i_error = 0.0;
        d_error = 0.0;

}

void PID::UpdateError(double cte) {
	static double prev_cte = 0.0;

	p_error  = cte;
	i_error += cte;
	d_error  = cte - prev_cte;
	prev_cte = cte;
}

double PID::TotalError() {
	double total_error;

	total_error = -(Kp * p_error + Ki * i_error + Kd * d_error);

        return total_error;
}


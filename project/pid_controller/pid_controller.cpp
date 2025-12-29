/**********************************************
 * Self-Driving Car Nano-degree - Udacity
 *  Created on: December 11, 2020
 *      Author: Mathilde Badoual
 **********************************************/

#include "pid_controller.h"
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kpi, double Kii, double Kdi, double output_lim_maxi, double output_lim_mini) {
   /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   **/
   _Kpi = Kpi;
   _Kii = Kii;
   _Kdi = Kdi;
   _output_lim_maxi = output_lim_maxi;
   _output_lim_mini = output_lim_mini;
  p_error = 0.0;
  i_error = 0.0;
  d_error = 0.0;
  cte = 0.0;
}


void PID::UpdateError(double cte) {
   /**
   * TODO: Update PID errors based on cte.
   **/
  d_error = _Kdi * (cte - this->cte)/_delta_time;
  p_error = _Kpi * cte;
  i_error += _Kpi * cte * _delta_time;
  this->cte = cte;
}

double PID::TotalError() {
   /**
   * TODO: Calculate and return the total error
    * The code should return a value in the interval [output_lim_mini, output_lim_maxi]
   */
    double control= p_error + i_error + d_error;
    if(control > _output_lim_maxi)
      control = _output_lim_maxi;
    else
      control = _output_lim_mini;
    return control;
}

double PID::UpdateDeltaTime(double new_delta_time) {
   /**
   * TODO: Update the delta time with new value
   */
 	_delta_time=new_delta_time;
}

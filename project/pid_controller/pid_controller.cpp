
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
  
  Kp = Kpi;
  Ki = Kii;
  Kd = Kdi;
  this->output_lim_maxi = output_lim_maxi;
  this->output_lim_mini = output_lim_mini;
  p_error = 0.0;
  i_error = 0.0;
  d_error = 0.0;
  this->cte = 0.0;
}


void PID::UpdateError(double cte) {
   /**
   * TODO: Update PID errors based on cte.
   **/
  if(abs(delta_time) < 0.000001) {
    return;
  }
  d_error = Kd * (cte - this->cte)/delta_time;
  p_error = Kp * cte;
  i_error += Ki  *cte*  delta_time;
  
  this->cte = cte;
}

double PID::TotalError() {
   /**
   * TODO: Calculate and return the total error
        * The code should return a value in the interval [output_lim_mini, output_lim_maxi]
   */
   
    double total_error = p_error + d_error + i_error;
  
    if(total_error > output_lim_maxi)
      total_error = output_lim_maxi;
    if(total_error < output_lim_mini)
      total_error = output_lim_mini;
    return total_error;
}

double PID::UpdateDeltaTime(double new_delta_time) {
   /**
   * TODO: Update the delta time with new value
   */
  delta_time=new_delta_time;
}
#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;
  prev_cte_is_set = false;
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  p_error = cte;
  i_error += cte;

  if (prev_cte_is_set == false)
  {
      prev_cte_is_set = true;
      prev_cte = cte;
  }
  d_error = cte - prev_cte;

  prev_cte = cte;
}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  return -p_error * Kp - d_error * Kd - i_error * Ki;  // TODO: Add your total error calc here!
}
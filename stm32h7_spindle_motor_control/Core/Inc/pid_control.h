#ifndef _MOON_PID_H
#define _MOON_PID_H

#include "arm_math.h"


/**
 * set pid argument 
 *
 * @param kp 
 * @param ki 
 * @param kd 
 */
static void __pid_set(q15_t kp, q15_t ki, q15_t kd);

/**
 * generate PWM for specified speed
 * 
 * @param s 
 * @return short 
 */
q15_t pid_gen_pwm(q15_t speed);

/**
 * update PID state 
 * 
 * @param s
 * @return arm_pid_instance_q15
 */
q15_t pid_state_out(q15_t speed);

/**
 * network auto update argument
 * 
 * @param batch
 * @return 
 */
q15_t pid_nn_auto_set(int batch);

#endif // _MOON_PID_H
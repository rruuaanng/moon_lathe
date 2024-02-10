#include "pid_control.h"

// 编码器测量的电机转速
#define NOP 0

// PID argument struct
static arm_pid_instance_q15 s = {
    .Kp = 0,
    .Ki = 0,
    .Kp = 0,
    // err, i_err and last_err
    .state = {0, 0, 0}
}; 

// import external train completed model
// ONNX
q15_t pid_nn_auto_set(int batch)
{
    return 0;
}

static void __pid_set(q15_t kp, q15_t ki, q15_t kd)
{
    s.Kp = kp;
    s.Ki = ki;
    s.Kd = kd;
}

q15_t pid_gen_pwm(q15_t speed)
{
    return 0;   
}

q15_t pid_state_out(q15_t t_speed)
{
    q15_t out;

    // now error
    s.state[0] = t_speed - NOP;
    // error integral 
    s.state[1] += s.state[0];
    out = s.Kp * s.state[0]
            + s.Ki * s.state[1]
            + s.Kd * (s.state[0] - s.state[2]);
    // last error
    s.state[2] = s.state[0];
    return out;
}
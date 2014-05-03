#ifndef SERVOCONF_H_INCLUDED
#define SERVOCONF_H_INCLUDED

struct ServoInfo {
    int n_min, n_max;   // PWM 'soft' limits - should be just within range
    float gain;         // PWM per radian
    float zero;         // Theoretical PWM for zero angle
};

// Function to set up a servo structure correctly
bool setup_servo (ServoInfo& svo, int n_min, int n_max,
                  float a_min, float a_max);

// Function to calculate PWM for a particular angle
int angle2pwm (const ServoInfo& svo, float angle);

#endif // SERVOCONF_H_INCLUDED

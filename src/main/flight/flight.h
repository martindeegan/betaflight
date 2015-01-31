/*
 * This file is part of Cleanflight.
 *
 * Cleanflight is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Cleanflight is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Cleanflight.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once


typedef enum {
    PIDROLL,
    PIDPITCH,
    PIDYAW,
    PIDALT,
    PIDPOS,
    PIDPOSR,
    PIDNAVR,
    PIDLEVEL,
    PIDMAG,
    PIDVEL,
    PID_ITEM_COUNT
} pidIndex_e;

#define IS_PID_CONTROLLER_FP_BASED(pidController) (pidController == 2)

typedef struct pidProfile_s {
    uint8_t pidController;                  // 0 = multiwii original, 1 = rewrite from http://www.multiwii.com/forum/viewtopic.php?f=8&t=3671, 1, 2 = Luggi09s new baseflight pid

    uint8_t P8[PID_ITEM_COUNT];
    uint8_t I8[PID_ITEM_COUNT];
    uint8_t D8[PID_ITEM_COUNT];

    float P_f[3];                           // float p i and d factors for lux float pid controller
    float I_f[3];
    float D_f[3];
    float A_level;
    float H_level;
    uint8_t H_sensitivity;
} pidProfile_t;

typedef enum {
    AI_ROLL = 0,
    AI_PITCH,
} angle_index_t;

#define ANGLE_INDEX_COUNT 2

// See http://en.wikipedia.org/wiki/Flight_dynamics
typedef enum {
    FD_ROLL = 0,
    FD_PITCH,
    FD_YAW
} flight_dynamics_index_t;

#define FLIGHT_DYNAMICS_INDEX_COUNT 3

#define DEGREES_TO_DECIDEGREES(angle) (angle * 10)
#define DECIDEGREES_TO_DEGREES(angle) (angle / 10.0f)

extern int16_t gyroData[FLIGHT_DYNAMICS_INDEX_COUNT];
extern int16_t gyroZero[FLIGHT_DYNAMICS_INDEX_COUNT];

extern int16_t gyroADC[XYZ_AXIS_COUNT], accADC[XYZ_AXIS_COUNT], accSmooth[XYZ_AXIS_COUNT];
extern int32_t accSum[XYZ_AXIS_COUNT];
extern int16_t axisPID[XYZ_AXIS_COUNT];

extern int32_t axisPID_P[3], axisPID_I[3], axisPID_D[3];

extern int16_t heading, magHold;

extern int32_t AltHold;
extern int32_t vario;

void setPIDController(int type);
void resetErrorAngle(void);
void resetErrorGyro(void);



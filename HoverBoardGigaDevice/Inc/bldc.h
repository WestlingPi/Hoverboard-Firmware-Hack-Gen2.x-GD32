/*
* This file is part of the hoverboard-firmware-hack-V2 project. The 
* firmware is used to hack the generation 2 board of the hoverboard.
* These new hoverboards have no mainboard anymore. They consist of 
* two Sensorboards which have their own BLDC-Bridge per Motor and an
* ARM Cortex-M3 processor GD32F130C8.
*
* Copyright (C) 2018 Florian Staeblein
* Copyright (C) 2018 Jakob Broemauer
* Copyright (C) 2018 Kai Liebich
* Copyright (C) 2018 Christoph Lehnert
*
* The program is based on the hoverboard project by Niklas Fauth. The 
* structure was tried to be as similar as possible, so that everyone 
* could find a better way through the code.
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef BLDC_H
#define BLDC_H

//#include "gd32f1x0.h"
//#include "../Inc/configSelect.h"
#include "../Inc/defines.h"

// Internal constants
#define BLDC_TIMER_MID_VALUE  (int16_t)(BLDC_TIMER_PERIOD / 2)   // = 1125
#define BLDC_TIMER_MIN_VALUE  (int16_t)10
#define BLDC_TIMER_MAX_VALUE  (BLDC_TIMER_PERIOD - 10) // = 2240


//----------------------------------------------------------------------------
// Set motor enable
//----------------------------------------------------------------------------
void SetEnable(FlagStatus setEnable);

//----------------------------------------------------------------------------
// Set pwm -1000 to 1000
//----------------------------------------------------------------------------
void SetPWM(int16_t setPwm);

//----------------------------------------------------------------------------
// Calculation-Routine for BLDC => calculates with 16kHz
//----------------------------------------------------------------------------
void CalculateBLDC(void);

// virtual method to be implemented by bldcBC.c and bldcSINE.c
void bldc_get_pwm(int pwm, int pos, int *y, int *b, int *g);

// virtual method call in the beginning of main()
void InitBldc();

#if defined(BLDC_BC)
	#include "../Inc/bldcBC.h"
#elif defined(BLDC_SINE)
	#include "../Inc/bldcSINE.h"
#endif



#endif

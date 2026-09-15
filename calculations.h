#ifndef CALCULATIONS_H
#define CALCULATIONS_H

#include "config.h"

#define L1_SURCHARGE 0.0
#define L2_SURCHARGE 0.2
#define L3_SURCHARGE 0.5

int calcWaitingTime(int specialtyIndex,int specialtyDailyCount[],const int CONSULT_TIME[]);
double calcSurcharge(int id,int specialtyIndex,int triageLevel[],const int BASE_FEE[]);



endif
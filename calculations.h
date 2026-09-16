#ifndef CALCULATIONS_H
#define CALCULATIONS_H

#include "config.h"

#define L1_SURCHARGE 0.0
#define L2_SURCHARGE 0.2
#define L3_SURCHARGE 0.5

#define AGE_DISCOUNT 0.15

extern double surchargeAmount;
extern double wardCostAmount;
extern double grossTotalAmount;
extern double discountAmount;
extern double finalPaybleAmount;

void calculationProcess(int id);
int calcWaitingTime(int specialtyIdx,int specialtyQueueCount[],const int CONSULT_TIME[]);
double calcSurcharge(int id,int specialtyIdx,int triageLevel[],const double BASE_FEE[]);
double calcTotalWardCost(int id,int wardIdx,int admittedStatus[],int daysAdmitted[],const double WARD_DAILY_RATES[]);
double grossTotalBill(int specialtyIdx,const double BASE_FEE[],double surchargeAmount,double wardCostAmount);
double calcAgeDiscount(int id,int patientAge[],double grossTotalAmount);
double calcFinalAmount(double grossTotalAmount,double discountAmount);

#endif
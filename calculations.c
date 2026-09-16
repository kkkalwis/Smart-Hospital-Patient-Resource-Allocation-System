#include <stdio.h>
#include "calculations.h"
#include "patients.h"
#include "specialty.h"

double surchargeAmount;
double wardCostAmount;
double grossTotalAmount;
double discountAmount;
double finalPaybleAmount;

void calculationProcess(int id){

    int wardIdx=wardId[id]-1;
    int specialtyIdx=specialtyId[id]-1;

    patientWaitTime[id]=calcWaitingTime(specialtyIdx,specialtyQueueCount, CONSULT_TIME);
    specialtyQueueCount[specialtyIdx]++;

    surchargeAmount=calcSurcharge(id,specialtyIdx,triageLevel,BASE_FEE);
    wardCostAmount=calcTotalWardCost(id,wardIdx,admittedStatus,daysAdmitted,WARD_DAILY_RATES);
    grossTotalAmount=grossTotalBill(specialtyIdx,BASE_FEE,surchargeAmount,wardCostAmount);
    discountAmount=calcAgeDiscount(id,patientAge,grossTotalAmount);
    finalPaybleAmount=calcFinalAmount(grossTotalAmount,discountAmount);
    patientBill[id]=finalPaybleAmount;

}

int calcWaitingTime(int specialtyIdx,int specialtyQueueCount[],const int CONSULT_TIME[]){
    int result= specialtyQueueCount[specialtyIdx] * CONSULT_TIME[specialtyIdx];
    return result;
}


double calcSurcharge(int id,int specialtyIdx,int triageLevel[],const double BASE_FEE[]){

    
    switch(triageLevel[id]){
        case 1:
            return BASE_FEE[specialtyIdx] * L1_SURCHARGE;
        case 2:
            return BASE_FEE[specialtyIdx] * L2_SURCHARGE;
        case 3: 
            return BASE_FEE[specialtyIdx] * L3_SURCHARGE;
        default:
            return 0.0;

    }
}

double calcTotalWardCost(int id,int wardIdx,int admittedStatus[],int daysAdmitted[],const double WARD_DAILY_RATES[]){
    if(admittedStatus[id]==1){
        return daysAdmitted[id] * WARD_DAILY_RATES[wardIdx];
    }
    return 0.0;
}


double grossTotalBill(int specialtyIdx,const double BASE_FEE[],double surchargeAmount,double wardCostAmount){
    double total=BASE_FEE[specialtyIdx] + surchargeAmount + wardCostAmount;
    return total;
}

double calcAgeDiscount(int id,int patientAge[],double grossTotalAmount){
    if(patientAge[id]<5 || patientAge[id]>65){
        return grossTotalAmount * AGE_DISCOUNT;
    }
    return 0.0;
}

double calcFinalAmount(double grossTotalAmount,double discountAmount){
    return grossTotalAmount-discountAmount;
}


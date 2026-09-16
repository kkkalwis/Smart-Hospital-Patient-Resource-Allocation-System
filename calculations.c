#include <stdio.h>
#include "calculations.h"
#include "patients.h"


void calculationProcess(int id){
    patientWaitTime[id]=calcWaitingTime(specialtyIndex,specialtyQueueCount, CONSULT_TIME);
    specialtyQueueCount[specialtyIndex]++;

    surchargeAmount=calcSurcharge(id,specialtyIndex,triageLevel,BASE_FEE);
    wardCostAmount=calcTotalWardCost(id,wardIndex,admittedStatus,daysAdmitted,WARD_DAILY_RATES);
    grossTotalAmount=grossTotalBill(specialtyIndex,BASE_FEE,surchargeAmount,wardCostAmount);
    discountAmount=calcAgeDiscount(id,patientAge,grossTotalAmount);
    finalPaybleAmount=calcFinalAmount(grossTotalAmount,discountAmount);
    patientBill[id]=finalPaybleAmount;

}

int calcWaitingTime(int specialtyIndex,int specialtyQueueCount[],const int CONSULT_TIME[]){
    int result= specialtyQueueCount[specialtyIndex] * CONSULT_TIME[specialtyIndex];
    return result;
}


double calcSurcharge(int id,int specialtyIndex,int triageLevel[],const double BASE_FEE[]){

    
    switch(triageLevel[id]){
        case 1:
            return BASE_FEE[specialtyIndex] * L1_SURCHARGE;
        case 2:
            return BASE_FEE[specialtyIndex] * L2_SURCHARGE;
        case 3: 
            return BASE_FEE[specialtyIndex] * L3_SURCHARGE;
        default:
            return 0.0;

    }
}

double calcTotalWardCost(int id,int wardIndex,int admittedStatus[],int daysAdmitted[],const double WARD_DAILY_RATES[]){
    if(admittedStatus[id]==1){
        return daysAdmitted[id] * WARD_DAILY_RATES[wardIndex];
    }
    return 0.0;
}


double grossTotalBill(int specialtyIndex,const double BASE_FEE[],double surchargeAmount,double wardCostAmount){
    double total=BASE_FEE[specialtyIndex] + surchargeAmount + wardCostAmount;
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


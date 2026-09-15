#include <stdio.h>
#include "calculations.h"
#include "patients.h"

int calcWaitingTime(int specialtyIndex,int specialtyDailyCount[],const int CONSULT_TIME[]){
    return specialtyDailyCount[specialtyIndex] * CONSULT_TIME[specialtyIndex];
}

double calcSurcharge(int id,int specialtyIndex,int triageLevel[],const int BASE_FEE[]){

    
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




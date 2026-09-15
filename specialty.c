#include "specialty.h"

int specialtyDailyCount[SPECIALITY_COUNT]={0};

int allocateSpecialty(int specialtyIndex){

    if(specialtyDailyCount[specialtyIndex]<DAILY_CAP[specialtyIndex]){
        specialtyDailyCount[specialtyIndex]++;
        return 1;
    }
    else{
        return -1;
    }


}
#include "specialty.h"

int specialtyDailyCount[SPECIALITY_COUNT];

int allocateSpecialty(int specialtyIdx){

    if(specialtyDailyCount[specialtyIdx]<DAILY_CAP[specialtyIdx]){
        specialtyDailyCount[specialtyIdx]++;
        return 1;
    }
    else{
        return -1;
    }


}
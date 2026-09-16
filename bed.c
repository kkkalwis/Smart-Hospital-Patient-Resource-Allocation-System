#include "bed.h"

int allocateBed(int wardIndex){
    for(int i=0;i<WARD_BED_CAP[wardIndex];i++){
        if(bedOccupancy[wardIndex][i]==0){
            bedOccupancy[wardIndex][i]=1;
            return i;
        }
    }

    return -1;

}
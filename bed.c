#include "bed.h"

int allocateBed(int wardindex){
    for(int i=0;i<WARD_BED_CAP[wardindex];i++){
        if(bedOccupancy[wardindex][i]==0){
            bedOccupancy[wardindex][i]=1;
            return i;
        }
    }

    return -1;

}
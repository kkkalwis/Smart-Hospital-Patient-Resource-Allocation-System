#include <stdio.h>
#include "bed.h"
#include "config.h"
#include "patients.h"

int allocateBed(int wardIndex){
    for(int i=0;i<WARD_BED_CAP[wardIndex];i++){
        if(bedOccupancy[wardIndex][i]==0){
            bedOccupancy[wardIndex][i]=1;
            return i;
        }
    }

    return -1;

}

void bedMetrix(){

    int wardChoice;

            printf("Available Wards\n");
            printf("----------------------------------------------------------------------\n");
            printf("%-15s %-25s \n","Ward ID","Ward Name");
            printf("----------------------------------------------------------------------\n");

            for(int i=0;i<WARD_COUNT;i++){
                printf("%-15d %-25s \n",i+1,WARD_NAMES[i]);
            }
            printf("----------------------------------------------------------------------\n");
            do{
                printf("Enter Ward ID: ");
                scanf("%d",&wardChoice);

            }while(wardChoice<1||wardChoice>WARD_COUNT);

            printf("\n");
            int wardIndex=wardChoice-1;
            printf("======================================================================\n");
            printf("           Bed Status for %s:\n", WARD_NAMES[wardIndex]);
            printf("======================================================================\n");
            printf("[x]=occupied [0]=vacent\n");
            printf("----------------------------------------------------------------------\n");
            

            for(int j=0;j<WARD_BED_CAP[wardIndex];j++){
                if(bedOccupancy[wardIndex][j] == 1){
                    printf("Bed %02d: [X]  ", j + 1);
                }
                else{
                    printf("Bed %02d: [0]  ", j + 1);
                }

                if ((j + 1) % 5 == 0) {
                printf("\n");
                }
            }
            printf("======================================================================\n");
    }




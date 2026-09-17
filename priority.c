#include <stdio.h>
#include <string.h>
#include "priority.h"
#include "patients.h"

void swapInt(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void swapDouble(double *a,double *b){
    double temp=*a;
    *a=*b;
    *b=temp;
}

void swapString(char a[], char b[]) {
    char temp[MAX_NAME_LEN];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

void prioritySorting(){
    for (int i = 0; i < patientCount - 1; i++) {
        for (int j = 0; j < patientCount - i - 1; j++) {
            if(triageLevel[j]<triageLevel[j+1]){

                swapInt(&triageLevel[j],&triageLevel[j+1]);
                swapInt(&patientId[j],&patientId[j+1]);
                swapString(patientName[j],patientName[j+1]);
                swapInt(&patientAge[j],&patientAge[j+1]);
                swapInt(&specialtyId[j],&specialtyId[j+1]);
                swapInt(&admittedStatus[j],&admittedStatus[j+1]);
                swapInt(&wardId[j],&wardId[j+1]);
                swapInt(&daysAdmitted[j],&daysAdmitted[j+1]);
                swapInt(&assignedBed[j],&assignedBed[j+1]);
                swapInt(&patientWaitTime[j],&patientWaitTime[j+1]);
                swapDouble(&patientDiscount[j],&patientDiscount[j+1]);
                swapDouble(&patientBill[j],&patientBill[j+1]);

            }
        }
    }
}


void patientsByUrgencyList(){

    prioritySorting();

    printf("\n=======================================================================================================\n");
    printf("                                 EMERGENCY PRIORITY TRIAGE QUEUE                          \n");
    printf("=======================================================================================================\n");
    printf(" %-4s | %-8s | %-12s | %-3s | %-18s | %-12s | %-12s | %-8s\n","Rank", "ID", "Name", "Age", "Urgency Level","Specialty","Ward", "Wait Time");
    printf("-------------------------------------------------------------------------------------------------------\n");

    for(int i=0;i<patientCount;i++){
        const char *UrgencyType;

        switch(triageLevel[i]){
            case 3:
                UrgencyType ="Level 3 (Critical)";
                break;

            case 2:
                UrgencyType ="Level 2 (Urgent)";
                break;

            case 1:
            default:
                UrgencyType = "Level 1 (Normal)";
                break;
        }

        const char *specialtyName=SPECIALITY_NAMES[specialtyId[i]-1];
        const char *wardName;

        if(admittedStatus[i]==1){
            wardName=WARD_NAMES[wardId[i]-1];
        }

        else{
            wardName="Outpatient";
        }


        printf(" %-4d | P%-7d | %-12.12s | %-3d | %-18s | %-12.12s | %-12.12s | %3d min\n",
               i + 1,
               patientId[i],
               patientName[i],
               patientAge[i],
               UrgencyType,
               specialtyName,
               wardName,
               patientWaitTime[i]);
    
    }
    printf("=======================================================================================================\n");
}


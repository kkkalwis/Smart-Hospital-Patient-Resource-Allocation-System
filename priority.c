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
                swapDouble(&patientBill[j],&patientBill[j+1]);

            }
        }
    }
}


void patientsByUrgencyList(){

    prioritySorting();

    printf("\n=================================================================================\n");
    printf("                       EMERGENCY PRIORITY TRIAGE QUEUE                          \n");
    printf("=================================================================================\n");
    printf(" %-5s | %-10s | %-18s | %-4s | %-18s | %-10s \n","Rank", "ID", "Name", "Age", "Urgency Level", "Wait Time");
    printf("---------------------------------------------------------------------------------\n");

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


        printf(" #%-4d | PAT-%-6d | %-18s | %-4d | %-18s | %d mins\n",
               i + 1,
               patientId[i],
               patientName[i],
               patientAge[i],
               UrgencyType,
               patientWaitTime[i]);
    
    }
    printf("=================================================================================\n");
}


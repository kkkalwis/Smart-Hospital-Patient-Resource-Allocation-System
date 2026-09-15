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

void prioritySorting(int patientCount){
    for (int i = 0; i < patientCount - 1; i++) {
        for (int j = 0; j < patientCount - i - 1; j++) {
            if(triageLevel[j]<triageLevel[j+1]){

                swapInt(&triageLevel[j],&triageLevel[j+1]);
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
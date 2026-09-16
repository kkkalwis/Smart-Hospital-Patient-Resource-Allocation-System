#include <stdio.h>
#include "analytics.h"
#include "patients.h"


void patientsByUrgencySummery(void){
    int level1Count=0;
    int level2Count=0;
    int level3Count=0;

    for(int i=0;i<patientCount;i++){
        if(triageLevel[i]==1){
            level1Count++;
        }
        else if(triageLevel[i]==2){
            level2Count++;
        }
        else{
            level3Count++;
        }
    }

    printf("\n========================================\n");
    printf("      PATIENT REGISTRATION BREAKDOWN\n");
    printf("========================================\n");
    printf("Total Patients Registered : %d\n",patientCount);
    printf("----------------------------------------\n");
    printf("  Critical (level 3)      : %d\n",level3Count);
    printf("  Urgent   (level 2)      : %d\n",level2Count);
    printf("  Normal   (level 1)      : %d\n",level1Count);
    printf("========================================\n");
    
}

void revenueAndDiscountSummery(void){

    double totalRevenue=0.0;
    double totalDiscunts=0.0;


    for(int i=0;i<patientCount;i++){
        totalDiscunts+=patientDiscount[i];
        totalRevenue+=patientBill[i];
    }

    printf("\n========================================\n");
    printf("      FINANTIAL SUMMERY\n");
    printf("========================================\n");
    printf("Total Revenue Generated : %12.2f",totalRevenue);
    printf("----------------------------------------\n");
    printf("Total Discounts Granted : %12.2f",totalDiscunts);
    printf("========================================\n");

}

void bedOccupancySummery(void){
    float wardPercentage[WARD_COUNT]={0};
    int wardOccupiedCount[WARD_COUNT]={0};
    

    for(int i=0;i<patientCount;i++){
        if(wardId[i]==1 && admittedStatus[i]==1){
            wardOccupiedCount[0]++;
        }
        if(wardId[i]==2 && admittedStatus[i]==1){
            wardOccupiedCount[1]++;
        }
        if(wardId[i]==3 && admittedStatus[i]==1){
            wardOccupiedCount[2]++;
        }
    }
    for(int i=0;i<WARD_COUNT;i++){
        wardPercentage[i]=(float)(wardOccupiedCount[i]/WARD_BED_CAP[i])*100;
    }
    
    

    printf("\n===========================================\n");
    printf("        BED OCCUPANCY BREAKDOWN \n");
    printf("===========================================\n");
     printf("\n%-15s %-25s %-17s\n","Ward ID","Ward Name","Daily Bed Rate");
    for(int i=0;i<WARD_COUNT;i++){
        printf("%-15d %-25s %-17.2f\n",i+1,WARD_NAMES[i],wardPercentage[i]);
    }
    printf("===========================================\n");

    
}

void highestPayingPatient(void){

    if(patientCount==0){
        printf("\n========================================\n");
        printf("        HIGHEST PAYING PATIENT          \n");
        printf("========================================\n");
        printf("No patients registered in the system.\n");
        printf("========================================\n");
        return;
    }
  
    double highestPayment=patientBill[0];
    
    for(int i=0;i<patientCount;i++){
        if(patientBill[i]>highestPayment){
            highestPayment=patientBill[i]
        }
    }

    printf("\n========================================\n");
    printf("        HIGHEST PAYING PATIENT          \n");
    printf("========================================\n");
    printf("Highest Bill Amount : %.2f\n",highestPayment);
    printf("----------------------------------------\n");
    printf("Highest Paying Patient Name: \n");

    for (int i = 0; i < patientCount; i++) {
        if (patientBill[i] == highestPayment) {
            printf(" - %s\n", patientName[i]);
        }
    }
    printf("========================================\n");

}
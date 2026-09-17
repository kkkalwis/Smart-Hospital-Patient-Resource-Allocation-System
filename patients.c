#include <stdio.h>
#include <string.h>
#include "patients.h"
#include "bed.h"
#include "specialty.h"
#include "calculations.h"
#include "priority.h"
#include "display.h"
#include "filehandling.h"


int patientId[MAX_PATIENTS];
char patientName[MAX_PATIENTS][MAX_NAME_LEN];
int patientAge[MAX_PATIENTS];
int triageLevel[MAX_PATIENTS];
int specialtyId[MAX_PATIENTS];
int admittedStatus[MAX_PATIENTS];
int wardId[MAX_PATIENTS];
int daysAdmitted[MAX_PATIENTS];
int assignedBed[MAX_PATIENTS];
int patientWaitTime[MAX_PATIENTS];
double patientDiscount[MAX_PATIENTS];
double patientBill[MAX_PATIENTS];



int patientCount=0;

void patientIntake()
{
    if (patientCount>=MAX_PATIENTS){
        printf("ERROR:Maximum patient capacity has been reached.\n");

    }

    else{
        int id=patientCount;
        patientId[id]=1001+id;

        printf("\n----PATIENT INTAKE PORTAL----\n");

        printf("\n1.Patient Details: \n");
        printf("\n");

        printf("Enter Patient Name: ");
        scanf(" %14[^\n]", patientName[id]);

        printf("Enter Patient Age: ");
        scanf("%d",&patientAge[id]);

        do{

            printf("Enter Triage Level(1 = Normal, 2 = Urgent, 3 = Critical): ");
            scanf("%d",&triageLevel[id]);

        }while(triageLevel[id]<1 || triageLevel[id]>3);

        printf("\n2.Specialty Selection: \n");

        printf("\nAvailable Specialties\n");
        printf("-----------------------------------------------------------\n");
        printf("%-15s %-25s %-15s\n","specialty ID","Specialty Name","Base fee");
        printf("-----------------------------------------------------------\n");

        for(int i=0;i<SPECIALITY_COUNT;i++)
        {
            printf("%-15d %-25s %-15.2f\n",i+1,SPECIALITY_NAMES[i],BASE_FEE[i]);
        }
        printf("-----------------------------------------------------------\n");

        do{
            printf("Enter Specialty ID(1 to 4): ");
            scanf("%d",&specialtyId[id]);

        }while(specialtyId[id]<1||specialtyId[id]>SPECIALITY_COUNT);

        int specialtyIndex=specialtyId[id]-1;
        int SpecialtyCapCheck=allocateSpecialty(specialtyIndex);

        if(SpecialtyCapCheck==-1){
            printf("Full Specialty Patient Capacity Has Been Reached\n");
            return;
        }

        printf("\n3.Ward Admission Details: \n");
        printf("\n");

        do{
            printf("Enter Ward Admission status(1=IS Admitted,0=Not admitted): ");
            scanf("%d",&admittedStatus[id]);

        }while(admittedStatus[id]<0||admittedStatus[id]>1);

        if(admittedStatus[id]==1){

            printf("\nAvailable Wards\n");
            printf("-----------------------------------------------------------\n");
            printf("%-15s %-25s %-17s\n","Ward ID","Ward Name","Daily Bed Rate");
            printf("-----------------------------------------------------------\n");

            for(int i=0;i<WARD_COUNT;i++){
                printf("%-15d %-25s %-17.2f\n",i+1,WARD_NAMES[i],WARD_DAILY_RATES[i]);
            }
            printf("-----------------------------------------------------------\n");
            do{
                printf("Enter Ward ID: ");
                scanf("%d",&wardId[id]);

            }while(wardId[id]<1||wardId[id]>WARD_COUNT);

            int wardIndex=wardId[id]-1;
            int bedAllocation=allocateBed(wardIndex);

            if(bedAllocation!=-1){
                assignedBed[id]=bedAllocation;
                printf("Patient Assigned to %s (Bed No: %d)\n",WARD_NAMES[wardIndex],bedAllocation+1);
            }
            else{
                printf("Full Bed Capacity Has Been Reached.\n");
                admittedStatus[id]=0;
                wardId[id]=0;
                assignedBed[id]=-1;
            }

            if(admittedStatus[id]==1){
                printf("Enter Days Admitted: ");
                scanf("%d",&daysAdmitted[id]);
            }
            else{
                daysAdmitted[id]=0;
            }

            }

        else{
            daysAdmitted[id]=0;
            wardId[id]=0;
            assignedBed[id]=-1;
        }

        patientCount++;
        calculationProcess(id);
        displayBill(id);
        appendPatientRecord(id);


}

}



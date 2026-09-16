#include <stdio.h>

#include "display.h"
#include "patients.h"
#include "calculations.h"
#include "config.h"
#include "bed.h"

void displayBill(int id){
    int specialtyIdx=specialtyId[id]-1;
    int wardIdx=wardId[id]-1;

    printf("\n===============================================================\n");
    printf("          SMART HOSPITAL ADMISSION & BILL\n");
    printf("---------------------------------------------------------------\n");

    printf("Patient ID              : PAT-%d\n",patientId[id]);
    printf("Patient Name            : %s\n",patientName[id]);

    int subsidyPct=(patientAge[id]<5 || patientAge[id]>65) ? 15 : 0;
    printf("Age                     : %d Years (%d%% Subsidy Eligible)\n",patientAge[id],subsidyPct);
    printf("Specialty               : %s\n",SPECIALITY_NAMES[specialtyIdx]);
    printf("Assigned Ward           : %s (Bed #%d)\n",WARD_NAMES[wardIdx],assignedBed[id]+1);
    printf("Urgency Level           : Level %d (%s)\n",triageLevel[id],TRIAGE_NAMES[triageLevel[id]-1]);
    printf("----------------------------------------------------------------\n");
    printf("Base Consultation Fee   : LKR %9.2f\n",BASE_FEE[specialtyIdx]);

    int surchargePct = (triageLevel[id] == 3) ? 50 : (triageLevel[id] == 2) ? 20 : 0;
    printf("Emergency Surcharge     : LKR %9.2f (%d%%)\n",surchargeAmount,surchargePct);
    printf("Ward Stay Cost  (%d Days): LKR %9.2f\n",daysAdmitted[id],wardCostAmount);
    printf("---------------------------------------------------------------\n");
    printf("Gross Total Bill        : LKR %9.2f\n",grossTotalAmount);
    printf("Age Subsidy Discount    : LKR -%8.2f (%d%%)\n",discountAmount,subsidyPct);
    printf("---------------------------------------------------------------\n");
    printf("Final Payable Amount    : LKR %9.2f\n",finalPaybleAmount);
    if (patientWaitTime[id] == 0) {
        printf("Estimated Waiting Time  : 0.00 mins (Immediate Attention)\n");
    } else {
        printf("Estimated Waiting Time  : %d.00 mins\n", patientWaitTime[id]);
    }
    printf("===============================================================\n");

}
#ifndef PATIENTS_H_INCLUDED
#define PATIENTS_H_INCLUDED

#include "config.h"

#define MAX_PATIENTS 100

extern int patientId[MAX_PATIENTS];
extern char patientName[MAX_PATIENTS][MAX_NAME_LEN];
extern int patientAge[MAX_PATIENTS];
extern int triageLevel[MAX_PATIENTS];
extern int specialtyId[MAX_PATIENTS];
extern int admittedStatus[MAX_PATIENTS];
extern int wardId[MAX_PATIENTS];
extern int daysAdmitted[MAX_PATIENTS];
extern int assignedBed[MAX_PATIENTS];
extern int patientWaitTime[MAX_PATIENTS];
extern double patientDiscount[MAX_PATIENTS];
extern double patientBill[MAX_PATIENTS];


extern int patientCount;

void patientIntake();






#endif

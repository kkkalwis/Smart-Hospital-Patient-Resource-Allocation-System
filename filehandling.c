#include <stdio.h>
#include "config.h"
#include "patients.h"
#include "bed.h"
#include "filehandling.h"


void saveBedStatus(void){

    FILE *file = fopen("beds_status.txt", "w");
    if(file == NULL){
        printf("Error : could not save bed status.\n");
        return;
    }

    for(int i=0;i<WARD_COUNT;i++){
        for(int j = 0; j < WARD_BED_CAP[i]; j++)
        {
            fprintf(file, "%d ", bedOccupancy[i][j]);
        }

        fprintf(file, "\n");
    }
    fclose(file);
    printf("Bed statuses saved successfully.\n");
}

void loadBedStatus(){

    FILE *file = fopen("beds_status.txt", "r");

        if(file == NULL){
        printf("Error : could not find bed status records.\n");
        return;
    }

    for(int i=0;i<WARD_COUNT;i++){
        for(int j=0;j<WARD_BED_CAP[i];j++){
            if (fscanf(file, "%d", &bedOccupancy[i][j]) != 1)
            {
                printf("Error: Invalid bed status file.\n");

                fclose(file);
                return;
            }

        }
    }
    fclose(file);
    printf("Bed statuses loaded successfully.\n");

}

void appendPatientRecord(int id){

    FILE *file = fopen("patient_records.txt", "a");

    if (file == NULL)
    {
        printf("Error: Could not open patient records file.\n");
        return;
    }

    fprintf(file, "========================================\n");

    fprintf(file, "Patient ID       : PAT-%d\n",
            patientId[id]);

    fprintf(file, "Patient Name     : %s\n",
            patientName[id]);

    fprintf(file, "Age              : %d\n",
            patientAge[id]);

    fprintf(file, "Urgency Level    : %d\n",
            triageLevel[id]);

    fprintf(file, "Specialty        : %s\n",
            SPECIALITY_NAMES[specialtyId[id] - 1]);

    if (admittedStatus[id] == 1)
    {
        fprintf(file, "Ward ID          : %d\n",
                wardId[id]);

        fprintf(file, "Assigned Bed     : %d\n",
                assignedBed[id] + 1);

        fprintf(file, "Days Admitted    : %d\n",
                daysAdmitted[id]);
    }
    else
    {
        fprintf(file, "Ward Admission   : Outpatient\n");
    }

    fprintf(file, "Discount         : %.2f\n",
            patientDiscount[id]);

    fprintf(file, "Final Bill       : %.2f\n",
            patientBill[id]);

    fprintf(file, "========================================\n\n");

    fclose(file);

    printf("Patient record saved successfully.\n");
}


void displayBillLog(void){
        FILE *file = fopen("patient_records.txt", "r");

    char line[256];

    if (file == NULL)
    {
        printf("\nNo patient billing records found.\n");
        return;
    }
        printf("\n===============================================================\n");
    printf("                  PATIENT BILLING LOG                          \n");
    printf("===============================================================\n\n");

    while (fgets(line, sizeof(line), file) != NULL)
    {
        printf("%s", line);
    }

    fclose(file);

    printf("\n===============================================================\n");
    printf("                END OF BILLING LOG                             \n");
    printf("===============================================================\n");

}

void clearAllFiles(void)
{
    FILE *file;

    file = fopen("beds_status.txt", "w");

    if (file == NULL)
    {
        printf("Error: Could not clear bed status file.\n");
    }
    else
    {
        fclose(file);
        printf("Bed status log cleared successfully.\n");
    }


    file = fopen("patient_records.txt", "w");

    if (file == NULL)
    {
        printf("Error: Could not clear patient records file.\n");
    }
    else
    {
        fclose(file);
        printf("Patient billing log cleared successfully.\n");
    }

    printf("\nAll logs cleared successfully.\n");
}
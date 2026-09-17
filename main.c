#include <stdio.h>
#include <stdlib.h>
#include "config.h"
#include "patients.h"
#include "bed.h"
#include "analytics.h"
#include "priority.h"
#include "calculations.h"
#include "display.h"

void subMenu();

int main(){

    int choice;
    
    
    do {
        printf("\n=================================================\n");
        printf("   SMART HOSPITAL RESOURCE ALLOCATION SYSTEM     \n");
        printf("=================================================\n");
        printf(" 1. Patient Intake & Billing                    \n");
        printf(" 2. Bed Occupancy Matrix                        \n");
        printf(" 3. Analytics & Reports Submenu                 \n");
        printf(" 4. displays registered patients in priority order\n");
        printf(" 5. Exit System                                 \n");
        printf("=================================================\n");
        printf(" Enter choice (1-5): ");

        if (scanf("%d",&choice)!=1){
            while (getchar() != '\n');
            choice=0;
        }

        printf("\n");

        switch(choice){
            case 1:
                patientIntake();
                break;

            case 2:
                bedMetrix();
                break;


            case 3:
                subMenu();
                break;

            case 4:
                patientsByUrgencyList();
                break;

            case 5:
                printf(" Exiting system. Goodbye!\n");
                break;

            default:
                printf(" Invalid option! Please select 1-5.\n");
                break;
        }

    } while (choice != 5);

    return 0;

}

void subMenu(){
    int subChoice;

    do {
        printf("\n-------------------------------------------------\n");
        printf("         PERFORMANCE REPORTS & ANALYTICS         \n");
        printf("-------------------------------------------------\n");
        printf(" 1. View Patient Intake & Urgency Breakdown     \n");
        printf(" 2. View Total Revenue & Discount Summary       \n");
        printf(" 3. View Ward Bed Occupancy Percentages         \n");
        printf(" 4. View Highest-Paying Patient Record          \n");
        printf(" 5. Back to Main Menu                           \n");
        printf("-------------------------------------------------\n");
        printf(" Enter sub-option (1-5): ");

        fflush(stdout);

        

        if (scanf("%d",&subChoice)!=1){
            while (getchar() != '\n');
            subChoice=0;
        }

        printf("\n");

        switch(subChoice){
            case 1:
            patientsByUrgencySummery();
            break;

            case 2:
            revenueAndDiscountSummery();
            break;

            case 3:
            bedOccupancySummery();
            break;

            case 4:
            highestPayingPatient();
            break;

            case 5:
            printf(" Exiting Sub Menu\n");
            break;

            default:
            printf(" Invalid option! Please select 1-5.\n");
            break;
        }

    } while (subChoice != 5);


}

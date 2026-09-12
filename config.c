#include "config.h"

const char SPECIALITY_NAMES[SPECIALITY_COUNT][MAX_NAME_LEN]={"General Practice (OPD)","Paediatrics","Cardiology","Neurology"};
const double BASE_FEE[SPECIALITY_COUNT]={1500.00, 2500.00, 4500.00, 5000.00};
const int CONSULT_TIME[SPECIALITY_COUNT]={15, 20, 30, 30};
const int DAILY_CAP[SPECIALITY_COUNT]={30, 20, 12, 10};

const char WARD_NAMES[WARD_COUNT][MAX_NAME_LEN]={"General Ward","Paediatric Ward","Surgical Ward","ICU (Intensive Care Unit)"};
const double WARD_DAILY_RATES[WARD_COUNT]={3000.00, 6000.00, 12000.00, 25000.00};
const int WARD_BED_CAP[WARD_COUNT]={20, 10, 10, 5};

int bedOccupancy[WARD_COUNT][MAX_BEDS]={0};

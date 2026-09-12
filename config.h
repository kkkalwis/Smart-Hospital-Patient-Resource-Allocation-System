#ifndef CONFIG_H_INCLUDED
#define CONFIG_H_INCLUDED

#define SPECIALITY_COUNT 4
#define WARD_COUNT 4
#define MAX_BEDS 20
#define MAX_NAME_LEN 30

extern const char SPECIALITY_NAMES[SPECIALITY_COUNT][MAX_NAME_LEN];
extern const double BASE_FEE[SPECIALITY_COUNT];
extern const int CONSULT_TIME[SPECIALITY_COUNT];
extern const int DAILY_CAP[SPECIALITY_COUNT];

extern const char WARD_NAMES[WARD_COUNT][MAX_NAME_LEN];
extern const double WARD_DAILY_RATES[WARD_COUNT];
extern const int WARD_BED_CAP[WARD_COUNT];

extern int bedOccupancy[WARD_COUNT][MAX_BEDS];


#endif // CONFIG_H_INCLUDED

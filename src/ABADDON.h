#ifndef abaddon
#define abaddon
#include <time.h>

#define MAX_NAME 50
#define MAX_PHONE 20

struct ABADDON {
    char fullName[MAX_NAME];
    char number[MAX_PHONE];
    struct tm registrationDate;
    double balance;
    double tarif;
};
#endif
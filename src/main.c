#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct ABADDON {
    char* fullName;
    char* number;
    struct tm registrationDate;
    double balance;
    double tarif;
};

int compare(struct ABADDON* a, struct ABADDON* b) {
    return strcomp(a, b);
}

void print(struct ABADDON* a) {
    printf(a->fullName);
    printf(a->number);
    printf(a->registrationDate)
}


int main(int argc, char* argv[])
{
    if (/*argc >= 2*/ 1) {
        //get n
        char* p;
        const long converted = strtol(argv[1], &p, 10);	//10 - base
        if (errno != 0 || *p != '\0' || converted > 12 || converted < 0) {
            printf("Incorrect command line argument for array size: %ld", converted);
            return -1;
        }
        const unsigned int n = converted;
        printf("%d\n", n);
        //
        //array
        struct ABADDON* arr = calloc(n, sizeof(struct ABADDON));
        char* temptime = malloc(11, sizeof(char));
        printf("I couldn't bother handling errors for each input so type correctly pls");
        for (unsigned int i = 0; i < n; i++) {
            memset(&temptime, 0, sizeof(temptime));
            printf("Enter name and initials: ");
            scanf("%s", &(arr[i].fullName));
            printf("Enter number: ");
            scanf("%s", &(arr[i].number));
            printf("Enter registration date(yyyy:mm:dd): ");
            scanf("%s", &temptime);
            strptime(temptime, "%Y:%m:%d", &(arr[i].registrationDate));  //adresses or just as is?
            printf("Enter balance: ");
            scanf("%lf", &(arr[i].balance));
            printf("Enter tariff: ");
            scanf("%lf", &(arr[i].tarif));
        }

        qsort(arr, n, sizeof(struct ABADDON), compare);

        time_t mytime = time(NULL);
        struct tm* now = localtime(&mytime);
        for (unsigned int i = 0; i < n; i++) {
            if (now->tm_year - arr[i].registrationDate.tm_year >= 10) {
                arr[i].balance += 20.0;
            }
        }

        for (unsigned int i = 0; i < n; i++) {
            if (arr[i].balance - arr[i].tarif < 0.0) {

            }
        }
    }
    else {
        printf("Incorrect number of arguments.");
        return -1;
    }
}

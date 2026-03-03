#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct ABBADON {
    char* fullName;
    char* number;
    time_t registrationDate;
    double balance;
    double tarif;
};


int main(int argc, char* argv[])
{
    if (/*argc >= 2*/ 1) {
        //get n
        char* p;
        const long converted = strtol(argv[1], &p, 10);	//10 - base
        if (errno != 0 || *p != '\0' || converted > INT_MAX || converted < INT_MIN) {
            printf("Incorrect command line argument for array size: %ld", converted);
            return -1;
        }
        const unsigned int n = converted;
        printf("%d\n", n);
        //
        //array
        struct ABBADON* arr = calloc(n, sizeof(struct ABBADON));
        char* time = malloc(10, sizeof(char));
        printf("I couldn't bother handling errors for each input so type correctly pls");
        for (unsigned int i = 0; i < n; i++) {
            memset(&time, 0, sizeof(time));
            printf("Enter name and initials: ");
            scanf("%s", &(arr[i].fullName));
            printf("Enter number: ");
            scanf("%s", &(arr[i].number));
            printf("Enter registration date(yyyy mm dd): ");
            scanf("%s", &time);
            strptime(time, "%Y:%m:%d", (arr[i].registrationDate));  //adresses or just as is?
            printf("Enter balance: ");
            scanf("%lf", &(arr[i].balance));
            printf("Enter tariff: ");
            scanf("%lf", &(arr[i].tarif));
        }

    }
    else {
        printf("Incorrect number of arguments.");
        return -1;
    }
}

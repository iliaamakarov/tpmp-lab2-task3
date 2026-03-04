#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#define MAX_NAME 50
#define MAX_PHONE 20

struct ABADDON {
    char fullName[MAX_NAME];
    char number[MAX_PHONE];
    struct tm registrationDate;
    double balance;
    double tarif;
};

int compare(const void* a, const void* b) {
    const struct ABADDON* aa = (const struct ABADDON*)a;
    const struct ABADDON* bb = (const struct ABADDON*)b;
    return strcmp(aa->fullName, bb->fullName);
}

void print(struct ABADDON* a) {
    if (a != NULL) {
        printf("---\n");
        printf("%s\n", a->fullName);
        printf("%s\n", a->number);
        printf("%d.%02d.%02d\n", a->registrationDate.tm_year, a->registrationDate.tm_mon + 1, a->registrationDate.tm_mday);
        printf("%lf\n", a->balance);
        printf("%lf\n", a->tarif);
        printf("---\n");
    }
}


int main(int argc, char* argv[])
{
    if (argc >= 2) {
        //get n
        char* p;
        errno = 0;
        const long converted = strtol(argv[1], &p, 10);	//10 - base
        if (errno != 0 || *p != '\0' || converted > 12 || converted < 0) {
            printf("Incorrect command line argument for array size: %ld\n", converted);
            return -1;
        }
        const unsigned int n = converted;
        printf("%d\n", n);
        //
        //array
        struct ABADDON* arr = (struct ABADDON*)calloc(n, sizeof(struct ABADDON));
        if (arr == NULL) {
            printf("Allocation error, idiot\n");
            return -1;
        }
        printf("I couldn't bother handling errors for each input so type correctly pls\n");
        ungetc('\n', stdin);
        for (unsigned int i = 0; i < n; i++) {

            while (getchar() != '\n');                          //clear buffer bcs it's C

            printf("Enter name and initials: \n");

            fgets(arr[i].fullName, MAX_NAME, stdin);            //whatever this is
            size_t len = strlen(arr[i].fullName);               //:)
            if (len > 0 && arr[i].fullName[len - 1] == '\n')    //remove trailing \n bcs it's C
                arr[i].fullName[len - 1] = '\0';

            printf("Enter number: \n");                           //same here
            fgets(arr[i].number, MAX_PHONE, stdin);
            len = strlen(arr[i].number);
            if (len > 0 && arr[i].number[len - 1] == '\n')
                arr[i].number[len - 1] = '\0';
            printf("Enter registration date(yyyy:mm:dd), including 0-s: \n");
            int y, m, d;
            scanf("%d:%d:%d", &y, &m, &d);
            arr[i].registrationDate.tm_year = y - 1900;
            arr[i].registrationDate.tm_mon = m - 1;
            arr[i].registrationDate.tm_mday = d;

            printf("Enter balance: \n");
            scanf("%lf", &(arr[i].balance));

            printf("Enter tariff: \n");
            scanf("%lf", &(arr[i].tarif));
        }

        qsort(arr, n, sizeof(struct ABADDON), compare);

        time_t mytime = time(NULL);
        struct tm* now = localtime(&mytime);
        for (unsigned int i = 0; i < n; i++) {
            if (now->tm_year - arr[i].registrationDate.tm_year >= 10) {
                arr[i].balance += 20.0;
                printf("added 20 dollar to %s\n", arr[i].fullName);
            }
        }

        printf("balances that go negative after subtracting their tariff:\n");
        int check = 0;
        for (unsigned int i = 0; i < n; i++) {
            if (arr[i].balance - arr[i].tarif < 0.0) {
                print(&arr[i]);
                check = 1;
            }
        } 
        if (!check) {
            printf("no such balances found, rich idiot\n");
        }

        char phone[MAX_PHONE];
        check = 0;
        printf("\nEnter phone number to search:\n");
        scanf("%s", phone);
        for (unsigned int i = 0; i < n; i++) {
            if (strcmp(phone, arr[i].number) == 0) {
                print(&arr[i]);
                check = 1;
                break;
            }
        }
        if (!check) {
            printf("no such phones, better luck next time.\n");
        }

        free(arr);
    }
    else {
        printf("Incorrect number of arguments.\n");
        return -1;
    }
    return 0;
}

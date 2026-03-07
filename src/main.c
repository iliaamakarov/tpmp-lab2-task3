#include <errno.h>
#include "ABADDON.h"
#include "functions.h"


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
        struct ABADDON* arr = InitializeArray(n);
        SortArray(arr, n);
        Add20ToOldAccounts(arr, n);
        ShowNegativeAccounts(arr, n);
        FindAccountByPhone(arr, n);

        free(arr);
    }
    else {
        printf("Incorrect number of arguments.\n");
        return -1;
    }
    return 0;
}

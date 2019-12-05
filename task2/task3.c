#include <stdio.h>
#include <unistd.h>

int main ()
{
        printf("REAL UID: %d\n", getuid());
        printf("Effective UID: %d\n", geteuid());

        FILE *f = fopen("./file.txt", "w+");
        if (!f) perror("SORRY NO\n");
        else {fclose(f); printf("SAS");}

        setuid(geteuid());

        printf("REAL UID: %d\n", getuid());
        printf("Effective UID: %d\n", geteuid());

        f = fopen("./file.txt", "w+");
        if (!f) perror("SORRY NO\n");
        else {fclose(f); printf("SAS");}

        return 0;
}


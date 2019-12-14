#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() {
   pid_t pid = fork();

   if (!pid) {
      system("cat file.txt");
   }
   else {
      int res;
      wait(&res);
      printf("child returned: %d\n", WEXITSTATUS(res));
   }
   fflush(stdout);
   return 10;
}


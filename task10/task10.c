#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

   int st;

   if (fork() == 0) {
      if (execvp(argv[1], &argv[1]) == -1) perror(argv[1]);
      exit(2);
   } else {
      wait(&st);
      printf("Child exit st: %d\n", WEXITSTATUS(st));

   return 0;
}

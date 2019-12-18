#include <string.h>
#include <termios.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



int main() {
   struct termios save;
   struct termios tty;
   int f = open("/dev/tty", O_RDONLY);
   tcgetattr(f, &tty);
   save = tty;
   tty.c_lflag &= ~(ICANON|ISIG);
   tty.c_cc[VMIN] = 11;
   tcsetattr(f, TCSAFLUSH, &tty);


   puts("ur moble phone number: ");
   fflush(stdout);



   char number[11] = {0};

   read(f, number, 11);

   printf("\n+7 (%c%c%c) %c%c%c-%c%c-%c%c\n",
      number[1], number[2], number[3],
      number[4], number[5], number[6], number[7],
      number[8], number[9], number[10]);



   tcsetattr(f, 0, &save);
   return 0;
}


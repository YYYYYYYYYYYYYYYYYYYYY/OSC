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
   tty.c_cc[VMIN] = 1;
   tcsetattr(f, TCSAFLUSH, &tty);
   puts("dota kal? [y/n]");
   fflush(stdout);
   int c[10];
   read(f, c, 10);

   write(f, &c, 10);
   tcsetattr(f, 0, &save);
   return 0;
}



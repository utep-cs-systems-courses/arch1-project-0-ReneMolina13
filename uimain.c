#include <stdio.h>
#include "draw.h"

int main() 
{
  puts("Welcome!");

  while (1) { // Infinite while loop

    fputs("Select which shape you want to print (Triangle = t, Square = s, Chars = c, Arrow = a) or 'q' to quit\n> ", stdout);
    fflush(stdout);		/* stdout only flushes automatically on \n */
    int c;
    while ((c = getchar()) == '\n'); /* ignore newlines */
    if (c == EOF)		     /* terminate on end-of-file */
      goto done;
    
    // Given the user answer, select which method to call
    switch (c) {
    case 't':
      puts("You selected triangle:");
      print_triangle(5, 7);
      break;
    case 's':
      puts("You selected square:");
      print_square(5, 5);
      break;
    case 'c':
      fputs("Select what font you would like (11x16 = l, 8x12 = m, 5x7 = s)\n", stdout);
      fflush(stdout);
      while ((c = getchar()) == '\n'); /* ignore newlines */
      if (c == EOF)
	goto done;
      else if (c == 'l') {
	int startC;
        puts("You selected chars:");
        fputs("Select the starting character for the sequence\n", stdout);
        fflush(stdout);
        while ((startC = getchar()) == '\n'); /* ignore newlines */
        if (startC > (0x7E - 0x02)) {
	  printf("Out of range, please try again!\n");
	  break;
	  }
	for (char c = startC; c < startC+3; c++)
	  print_char_11x16(c);
	}
      else if (c == 'm') {
	int startC;
        puts("You selected chars:");
        fputs("Select the starting character for the sequence\n", stdout);
        fflush(stdout);
        while ((startC = getchar()) == '\n'); /* ignore newlines */
        if (startC > (0x7E - 0x02)) {
	  printf("Out of range, please try again!\n");
	  break;
	  }
	for (char c = startC; c < startC+3; c++)
	  print_char_8x12(c);
        }
      else if (c == 's') {
	int startC;
        puts("You selected chars:");
        fputs("Select the starting character for the sequence\n", stdout);
        fflush(stdout);
        while ((startC = getchar()) == '\n'); /* ignore newlines */
        if (startC > (0x7E - 0x06)) {
	  printf("Out of range, please try again!\n");
	  break;
	  }
	for (char c = startC; c < startC+7; c++)
	  print_char_5x7(c);
        }
      else
	printf("Unrecognized option '%c', please try again!\n", c);
      break;
    case 'a':
      puts("You selected arrow:");
      print_arrow(5,7);
      break;
    case 'q':
      puts("Bye!");
      goto done; 		/* terminate */
    case '\n':
      break;
    default:
      printf("Unrecognized option '%c', please try again!\n", c);
    }
  }

 done: // To exit from program
  return 0;
}

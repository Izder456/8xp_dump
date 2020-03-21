////////////////////////////////////////
// { prgmSEIVEC } { v1.3 }
// Author: izder456
// License: n/a
// Description: generate primes up to n
////////////////////////////////////////

/* Keep these headers */
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

/* Standard headers */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Other available headers: stdarg.h, setjmp.h, assert.h, ctype.h, float.h, iso646.h, limits.h, errno.h */

/* uint8_t is an unsigned integer that can range from 0-255. */
/* It performs faster than just an int, so try to use it (or int8_t) when possible */

/* Put function prototypes here */
#define INPUT_SIZE 10
void printText(const char * text, uint8_t x, uint8_t y);

/* Put all your code here */
int main() {
  int i, j, c, n;
  const char * start = "Till? ";
  char prompt[] = "";
  char * ptr;
  char inputBuffer[INPUT_SIZE];
  char istr[12];

  os_ClrHomeFull();
  printText(start, 0, 0);
  os_GetStringInput(prompt, inputBuffer, INPUT_SIZE);
  n = strtol(inputBuffer, & ptr, INPUT_SIZE);

  os_ClrHomeFull();
  printText("Prime numbers: ", 0, 0);
  printText("", 0, 1);
  for (i = 2; i <= n; i++) {
    c = 0;
    for (j = 1; j <= i; j++) {
      if (i % j == 0) {
        c = c + 1;
      }
    }

    if (c == 2) {
      //printf("%d ",i);
      sprintf(istr, "%d ", i);
      os_PutStrFull(istr);
      os_NewLine();
    }
  }

  os_PutStrFull("DONE!");
  while (!os_GetCSC());
  return 0;
}

/* Draw text on the homescreen at the given X/Y cursor location */
void printText(const char * text, uint8_t xpos, uint8_t ypos) {
  os_SetCursorPos(ypos, xpos);
  os_PutStrFull(text);
}

////////////////////////////////////////
// { prgmFINANCE } { v1.0 }
// Author: izder456
// License: n/a
// Description: compound periodic interest calculator
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
#define INPUT_SIZE  10

/* uint8_t is an unsigned integer that can range from 0-255. */
/* It performs faster than just an int, so try to use it (or int8_t) when possible */

/* Put function prototypes here */
void printText(const char *text, uint8_t x, uint8_t y);
void float2str(float value, char *str);

/* Put all your code here */
int main(void)
{
    char *ptr;
    char inputBuffer[INPUT_SIZE];
    char prompt[] = "";

    int iPrincipal;
    float fRate;
    int iYears;
    int iTimes;
    float fPower;
    float fROI;
    char sROI[19];

    const char* one = "Principal? ";
    const char* two = "Rate? ";
    const char* three = "Years? ";
    const char* four = "Times (per year)? ";


    /* Clear the homescreen */
    os_ClrHomeFull();

    /* Print a few strings && get input */
    prompt[0] = 0;
    printText(one, 0, 0);
    os_GetStringInput(prompt, inputBuffer, INPUT_SIZE);
    iPrincipal = strtol(inputBuffer, &ptr, INPUT_SIZE);

    prompt[0] = 0;
    printText(two, 0, 1);
    os_GetStringInput(prompt, inputBuffer, INPUT_SIZE);
    fRate = strtod(inputBuffer, &ptr);

    prompt[0] = 0;
    printText(three, 0, 2);
    os_GetStringInput(prompt, inputBuffer, INPUT_SIZE);
    iYears = strtol(inputBuffer, &ptr, INPUT_SIZE);

    prompt[0] = 0;
    printText(four, 0, 3);
    os_GetStringInput(prompt, inputBuffer, INPUT_SIZE);
    iTimes = strtol(inputBuffer, &ptr, INPUT_SIZE);

    /* do the math */
    fPower = pow((1+(fRate/iTimes)),(iYears*iTimes));
    fROI = iPrincipal*fPower;

    /* printing */
    float2str(fROI, sROI);
    printText("sROI is : $", 0, 4);
    os_PutStrFull(sROI);

    /* Wait for a key press */
    while (!os_GetCSC());
    os_ClrHomeFull();

    return 0;
}

/* Draw text on the homescreen at the given X/Y cursor location */
void printText(const char *text, uint8_t xpos, uint8_t ypos)
{
    os_SetCursorPos(ypos, xpos);
    os_PutStrFull(text);
}
/* convert float to string */
void float2str(float value, char *str)
{
    real_t tmp_real = os_FloatToReal(value);
    os_RealToStr(str, &tmp_real, 8, 1, 2);
}

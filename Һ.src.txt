////////////////////////////////////////
// { h } { v1.2 }
// Author: u/izder456
// Description: vry funy
////////////////////////////////////////


#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

/* Standard headers */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Put function prototypes here */
void printText(const char *text, uint8_t x, uint8_t y);

/* Put all your code here */
void main(void)
{
    /* Initialize some gfx_SetDrawBuffer */
    const char* H = "h";
    const char* sub = "r/TheLetterH";
    const char* user = "u/izder456";
    int i;
    /* Clear the homescreen */
    os_ClrHomeFull();

    for (i=0; i<=250; i++)
    {
        /* Print a some sheiße */
        printText(H, randInt(0,25), randInt(0,8));
        printText(sub, 0, 9);
        printText(user, 14, 9);
    }
    while (!os_GetCSC());
    os_ClrHomeFull();
}

/* Draw text on the homescreen at the given X/Y cursor location */
void printText(const char *text, uint8_t xpos, uint8_t ypos)
{
    os_SetCursorPos(ypos, xpos);
    os_PutStrFull(text);
}


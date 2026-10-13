/*
 * unit:     yes
 * function: IRC_RESULT_GetFont, IRC_RESULT_GetPrintQueue, IRC_RESULT_GetMessages, IRC_RESULT_GetWordSet
 * address:  0x021B7CA0
 * packet:   pkt_021B7CA0
 * region:   ov105
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * four int getters at +0, +8, +4, +c.
 */
#include "../include/Obj22244.h"
#include "../include/Obj22245.h"
#include "../include/Obj22246.h"
#include "../include/Obj22247.h"

int IRC_RESULT_GetFont(void *p)
{
    return ((struct Obj22244 *)p)->f0;
}

int IRC_RESULT_GetPrintQueue(void *p)
{
    return ((struct Obj22245 *)p)->f8;
}

int IRC_RESULT_GetMessages(void *p)
{
    return ((struct Obj22246 *)p)->f4;
}

int IRC_RESULT_GetWordSet(void *p)
{
    return ((struct Obj22247 *)p)->fC;
}

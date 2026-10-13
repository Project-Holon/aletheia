/*
 * unit:     yes
 * function: IRC_RHYTHM_GetFont, IRC_RHYTHM_GetPrintQueue, IRC_RHYTHM_GetMessages, IRC_RHYTHM_GetWordSet
 * address:  0x021B7DE0
 * packet:   pkt_021B7DE0
 * region:   ov104
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * four int getters at +0, +8, +4, +c.
 */
#include "../include/Obj22220.h"
#include "../include/Obj22221.h"
#include "../include/Obj22222.h"
#include "../include/Obj22223.h"

int IRC_RHYTHM_GetFont(void *p)
{
    return ((struct Obj22220 *)p)->f0;
}

int IRC_RHYTHM_GetPrintQueue(void *p)
{
    return ((struct Obj22221 *)p)->f8;
}

int IRC_RHYTHM_GetMessages(void *p)
{
    return ((struct Obj22222 *)p)->f4;
}

int IRC_RHYTHM_GetWordSet(void *p)
{
    return ((struct Obj22223 *)p)->fC;
}

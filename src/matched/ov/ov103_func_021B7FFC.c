/*
 * unit:     yes
 * function: IRC_COMPATIBLE_TOUCH_TEST_TextGetFont, IRC_COMPATIBLE_TOUCH_TEST_TextGetPrintQueue, IRC_COMPATIBLE_TOUCH_TEST_TextGetMsgData, IRC_COMPATIBLE_TOUCH_TEST_TextGetWordSet
 * address:  0x021B7FFC
 * packet:   pkt_021B7FFC
 * region:   ov103
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * four int getters at +0, +8, +4, +c.
 */
#include "../include/Obj22186.h"
#include "../include/Obj22187.h"
#include "../include/Obj22188.h"
#include "../include/Obj22189.h"

int IRC_COMPATIBLE_TOUCH_TEST_TextGetFont(void *p)
{
    return ((struct Obj22186 *)p)->f0;
}

int IRC_COMPATIBLE_TOUCH_TEST_TextGetPrintQueue(void *p)
{
    return ((struct Obj22187 *)p)->f8;
}

int IRC_COMPATIBLE_TOUCH_TEST_TextGetMsgData(void *p)
{
    return ((struct Obj22188 *)p)->f4;
}

int IRC_COMPATIBLE_TOUCH_TEST_TextGetWordSet(void *p)
{
    return ((struct Obj22189 *)p)->fC;
}

/*
 * unit:     yes
 * function: IRC_COMPATIBLE_MENU_TextGetFont, IRC_COMPATIBLE_MENU_TextGetPrintQueue, IRC_COMPATIBLE_MENU_TextGetMsgData
 * address:  0x021B7CBC
 * packet:   pkt_021B7CBC
 * region:   ov102
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * three int getters at +0, +8, +4.
 */
#include "../include/Obj22144.h"
#include "../include/Obj22145.h"
#include "../include/Obj22146.h"

int IRC_COMPATIBLE_MENU_TextGetFont(void *p)
{
    return ((struct Obj22144 *)p)->f0;
}

int IRC_COMPATIBLE_MENU_TextGetPrintQueue(void *p)
{
    return ((struct Obj22145 *)p)->f8;
}

int IRC_COMPATIBLE_MENU_TextGetMsgData(void *p)
{
    return ((struct Obj22146 *)p)->f4;
}

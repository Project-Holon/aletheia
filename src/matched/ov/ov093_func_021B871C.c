/*
 * function: BTL_MAIN_GetPlayerStatus
 * address:  0x021B871C
 * packet:   pkt_021B871C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT* (extent 8, compiled 6, trailing padding)
 */
#include "../include/Obj20957.h"

int BTL_MAIN_GetPlayerStatus(char *p)
{
    return ((struct Obj20957 *)p)->fC0;
}

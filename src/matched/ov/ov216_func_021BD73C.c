/*
 * function: BEACON_DETAIL_GRA_UpdateTimer
 * address:  0x021BD73C
 * packet:   pkt_021BD73C
 * region:   ov216
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   KEY_GetTrg 0x020362DC arm
 */
#include "../include/Obj10950.h"

typedef unsigned int u32;

extern int TOUCHPANEL_GetTrg(void);
extern u32 KEY_GetTrg(void);

int BEACON_DETAIL_GRA_UpdateTimer(char *p)
{
    unsigned char c;
    if (TOUCHPANEL_GetTrg() != 0 || (KEY_GetTrg() & 1) != 0)
    {
        ((struct Obj10950 *)p)->f1 = 0;
        return 0;
    }
    c = ((struct Obj10950 *)p)->f1;
    ((struct Obj10950 *)p)->f1 = c - 1;
    if (c != 0)
    {
        return 1;
    }
    return 0;
}

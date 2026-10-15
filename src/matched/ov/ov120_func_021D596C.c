/*
 * function: GTSNEGO_DISP_CheckPartySelect
 * address:  0x021D596C
 * packet:   pkt_021D596C
 * region:   ov120
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GTSNEGO_MSG_IsCursorAnimDone  0x021D6AC0  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj22832.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern int GTSNEGO_MSG_IsCursorAnimDone(u8 *p);

int GTSNEGO_DISP_CheckPartySelect(u8 *p, int x)
{
    if (GTSNEGO_MSG_IsCursorAnimDone(((struct Obj22832 *)p)->f3C) == 0)
        x = 9;
    return x;
}

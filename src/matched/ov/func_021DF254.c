/*
 * function: BOX2_MAIN_HitPartyGrid
 * address:  0x021DF254
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_UI_GetGridSlotPoint  0x021EF224  thumb  ov170
 *
 * Wrap the -1/0xff query into the 0xc0..0xff window and hand the
 *   wrapped value back; 0xff is the error.  The three byte fields are
 *   unsigned char (ldrb) and the comparison is unsigned (blo).
 */
#include "../include/Obj00000.h"

extern int BOX2_UI_GetGridSlotPoint(int, int);
extern int BOX2_UI_GetGridSlotPoint(int, int);
int BOX2_MAIN_HitPartyGrid(unsigned char *p, short x, short y)
{
    int v = BOX2_UI_GetGridSlotPoint(*(int *)(*(int *)&((struct Obj00000 *)p)->f2C + 0xA180),
                          *(int *)(*(int *)&((struct Obj00000 *)p)->f2C + 0xA184));
    unsigned w;
    if (v == 0xff)
        return v;
    w = v - 0x24 + p[0x19];
    if (w >= p[0x15])
        w -= p[0x15];
    if (w == p[0x14])
        return 0xff;
    return v;
}


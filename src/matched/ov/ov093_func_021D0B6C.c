/*
 * function: BTL_CLIENT_SetChangeActionsFromChoice
 * address:  0x021D0B6C
 * packet:   pkt_ov093_021D0B6C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_ACTION_SetChange  0x021D8394  thumb  ov093
 */
#include "../include/Obj13365.h"

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern void BTL_ACTION_SetChange(void *dst, u8 a, u8 b);

void BTL_CLIENT_SetChangeActionsFromChoice(u8 *g, u8 *s)
{
    u8 i;

    for (i = 0; i < s[6]; i++)
        BTL_ACTION_SetChange(g + 0x124 + i * 4, s[i + 3], s[i]);
    *(u8 * *)&((struct Obj13365 *)g)->fD8 = g + 0x124;
    ((struct Obj13365 *)g)->fDC = s[6] << 2;
}

/*
 * function: MBi_GetAttribute
 * address:  0x021F62B4
 * packet:   pkt_ov107_021F62B4
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK: TwlSDK/libmb.TWL.HYB.a(mb_wm_base.o).
 *
 * symbols:
 *   d_021F6F90   0x021F6F90  data
 */

#include "../include/G_WmBase.h"

typedef unsigned short u16;
typedef unsigned char u8;

extern struct WmBase d_021F6F90;

unsigned char MBi_GetAttribute(void)
{
    char *base = *(char **)(((char *)&d_021F6F90) + 0xC);

    return (*(u16 *)(base + 0xE) ? 1 : 0) | (*(u16 *)(base + 0x12) ? 2 : 0) |
           (*(u16 *)(base + 0x14) ? 4 : 0) | (*(u16 *)(base + 0x16) ? 8 : 0);
}

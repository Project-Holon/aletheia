/*
 * function: MBi_IsSendEnabled
 * address:  0x021F45C8
 * packet:   pkt_ov107_021F45C8
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

static int MBi_IsSendEnabled(void)
{
    int ret = 0;
    int g = 0;
    int f = 0;
    char *base = *(char **)(((char *)&d_021F6F90) + 0xC);

    if (*(u16 *)(base + 0x528) == 1 && *(u8 *)(base + 0x50C) == 0)
        f = 1;
    if (f) {
        if (*(u16 *)(base + 0x526) == 0)
            g = 1;
    }
    if (g) {
        if (*(u16 *)(base + 0x52A) != 0)
            ret = 1;
    }
    return ret;
}

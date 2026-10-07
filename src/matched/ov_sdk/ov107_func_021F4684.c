/*
 * function: MBi_EndCommon
 * address:  0x021F4684
 * packet:   pkt_ov107_021F4684
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

static void MBi_EndCommon(void *arg)
{
    void (*callback)(int, void *);

    *(u8 *)(*(char **)(((char *)&d_021F6F90) + 0xC) + 0x50D) = 0;
    *(u16 *)(*(char **)(((char *)&d_021F6F90) + 0x10) + 0x1316) = 0;
    callback = *(void (**)(int, void *))(*(char **)(((char *)&d_021F6F90) + 0xC) + 0x51C);
    if (callback == 0)
        return;
    callback(0x11, arg);
}

/*
 * function: MBi_ChildPortCallback
 * address:  0x021F4E9C
 * packet:   pkt_ov107_021F4E9C
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

struct WMPortRecvCallback {
    char _0[2];
    u16 field2;
    u16 field4;
};

extern struct WmBase d_021F6F90;

static void MBi_ChildPortCallback(void *arg)
{
    struct WMPortRecvCallback *cb = arg;
    void (*callback)(int, void *);

    if (cb->field2 != 0)
        return;
    switch (cb->field4) {
    case 7:
    case 9:
    case 0x19:
    case 0x1A:
        break;
    case 0x15:
        callback = *(void (**)(int, void *))(*(char **)(((char *)&d_021F6F90) + 0xC) + 0x51C);
        callback(9, arg);
        break;
    }
}

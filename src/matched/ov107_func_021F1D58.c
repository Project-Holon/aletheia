/*
 * function: MBi_CommChangeParentStateCallbackOnly
 * address:  0x021F1D58
 * packet:   pkt_ov107_021F1D58
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK: TwlSDK/libmb.TWL.HYB.a(mb_parent.o).  decl_line 296.
 *
 * symbols:
 *   mbc   0x021F6FA0  data
 */
typedef unsigned short u16;

extern void *mbc;

typedef void (*WMCallback)(u16 child, int state, void *arg);

void MBi_CommChangeParentStateCallbackOnly(u16 child, int state, void *arg)
{
    WMCallback callback = *(WMCallback *)((char *)mbc + 0x14E4);

    if (callback)
        callback(child, state, arg);
}

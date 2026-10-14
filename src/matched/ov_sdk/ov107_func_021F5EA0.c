/*
 * function: MBi_CallReset
 * address:  0x021F5EA0
 * packet:   pkt_ov107_021F5EA0
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK: TwlSDK/libmb.TWL.HYB.a(mb_wm_base.o).  decl_line 1387, local errcode.
 *
 * symbols:
 *   gMbWm   0x021F6F90  data
 *   WM_Reset     0x0208F400  arm
 *   func_021F6334   0x021F6334  arm
 */

#include "../include/G_WmBase.h"

typedef unsigned long u32;
typedef unsigned short u16;

extern struct WmBase gMbWm;
extern int WM_Reset(u32 param);
extern void func_021F6334(u16 apiid, int errcode);

int MBi_CallReset(void)
{
    int errcode = WM_Reset(*(u32 *)(*(char **)(((char *)&gMbWm) + 0xC) + 0x508));

    func_021F6334(1, errcode);
    return errcode == 2 ? 0 : errcode;
}

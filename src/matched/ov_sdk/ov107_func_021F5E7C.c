/*
 * function: MB_StartParentFromIdle
 * address:  0x021F5E7C
 * packet:   pkt_ov107_021F5E7C
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK: TwlSDK/libmb.TWL.HYB.a(mb_wm_base.o).  decl_line 1337.
 *
 * symbols:
 *   d_021F6F90   0x021F6F90  data
 *   func_021F5CAC   0x021F5CAC  arm
 */

#include "../include/G_WmBase.h"

typedef unsigned long u32;

extern struct WmBase d_021F6F90;
extern int func_021F5CAC(int channel);

int MB_StartParentFromIdle(int channel)
{
    *(u32 *)(*(char **)(((char *)&d_021F6F90) + 0x10) + 0x1320) = 1;
    return func_021F5CAC(channel);
}

/*
 * function: MBi_GetGgid
 * address:  0x021F628C
 * packet:   pkt_ov107_021F628C
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK: TwlSDK/libmb.TWL.HYB.a(mb_wm_base.o).  decl_line 1646.
 *
 * symbols:
 *   d_021F6F90   0x021F6F90  data
 */

#include "../include/G_WmBase.h"

typedef unsigned long u32;

extern struct WmBase d_021F6F90;

u32 MBi_GetGgid(void)
{
    return *(u32 *)(*(char **)(((char *)&d_021F6F90) + 0xC) + 8);
}

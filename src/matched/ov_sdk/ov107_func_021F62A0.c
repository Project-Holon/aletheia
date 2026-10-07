/*
 * function: MB_GetTgid
 * address:  0x021F62A0
 * packet:   pkt_ov107_021F62A0
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK: TwlSDK/libmb.TWL.HYB.a(mb_wm_base.o).  decl_line 1221.
 *
 * symbols:
 *   d_021F6F90   0x021F6F90  data
 */

#include "../include/G_WmBase.h"

typedef unsigned short u16;

extern struct WmBase d_021F6F90;

u16 MB_GetTgid(void)
{
    return *(u16 *)(*(char **)(((char *)&d_021F6F90) + 0xC) + 0xC);
}

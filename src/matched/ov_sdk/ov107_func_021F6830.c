/*
 * function: MBi_SetParentPieceBuffer
 * address:  0x021F6830
 * packet:   pkt_ov107_021F6830
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK: TwlSDK/libmb.TWL.HYB.a(mb_block.o).  decl_line 84.
 *
 * symbols:
 *   d_021F7008   0x021F7008  data
 */

#include "../include/G_piece.h"

typedef unsigned long u32;

extern struct piece d_021F7008;
extern void MI_CpuFill8(void *dst, int val, u32 len);

void MBi_SetParentPieceBuffer(void *buf)
{
    *(void **)(((char *)&d_021F7008) + 4) = buf;
    MI_CpuFill8(buf, 0, 0x21C);
}

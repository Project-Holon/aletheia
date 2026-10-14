/*
 * function: MBi_ClearParentPieceBuffer
 * address:  0x021F6850
 * packet:   pkt_ov107_021F6850
 * region:   ov107
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MBi_ClearParentPieceBuffer (libmb.TWL.HYB.a mb_block.o)
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   g_021F7008     0x021F7008  data
 */

#include "../include/G_piece.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

extern struct piece g_021F7008;

extern void MI_CpuFill8(void *dst, int val, u32 len);

void MBi_ClearParentPieceBuffer(u16 child_aid)
{
    int i;

    if (g_021F7008.buf == 0)
        return;
    i = child_aid - 1;
    MI_CpuFill8(((u8 *)g_021F7008.buf) + i * 32, 0, 30);
    *(int *)(((u8 *)g_021F7008.buf) + 0x1E0 + i * 4) = 0;
}

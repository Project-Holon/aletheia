/*
 * function: func_021F6A24
 * address:  0x021F6A24
 * packet:   pkt_ov107_021F6A24
 * region:   ov107
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MBi_ReceiveRequestDataPiece (libmb.TWL.HYB.a mb_block.o)
 *
 * symbols:
 *   MI_CpuCopy8  0x02082D44  arm
 *   func_021F6AA4  0x021F6AA4  arm  ov107
 *   g_021F7008     0x021F7008  data
 */

#include "../include/G_piece.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

extern struct piece g_021F7008;

typedef struct {
    u8 type;
    u8 pad;
    u8 piece;
} ChildBlockHeader;

extern void MI_CpuCopy8(void *src, void *dst, unsigned long size);
extern int func_021F6AA4(int a);

u8 *func_021F6A24(ChildBlockHeader *hdr, u16 child)
{
    u8 piece;

    if (g_021F7008.buf == 0)
        return 0;
    piece = hdr->piece;
    if (piece > g_021F7008.max)
        return 0;
    MI_CpuCopy8((u8 *)hdr + 3,
                  ((u8 *)g_021F7008.buf) + (child - 1) * 32 + piece * g_021F7008.size,
                  g_021F7008.size);
    *(u32 *)(((u8 *)g_021F7008.buf) + 0x1E0 + (child - 1) * 4) |= 1 << piece;
    if (func_021F6AA4(child))
        return ((u8 *)g_021F7008.buf) + (child - 1) * 32;
    return 0;
}

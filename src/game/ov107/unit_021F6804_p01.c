/*
 * file:     unit_021F6804_p01.c
 * unit:     yes
 * function: func_021F6804, func_021F6830, func_021F6850
 * address:  0x021F6804
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021F7008   0x021F7008  data
 *   _s32_div_f   0x0209C0A4  arm
 *   func_02082BCC  0x02082BCC  arm
 *   g_021F7008     0x021F7008  data
 */
#include "../../matched/include/G_piece.h"

typedef unsigned short u16;

typedef int s32;

typedef unsigned long u32;

typedef unsigned char u8;

extern void MI_CpuFill8(void *dst, int val, u32 len);
extern void func_02082BCC(void *dst, int val, u32 len);
void MBi_SetChildMPMaxSize(u16 childMaxSize);
void MBi_SetParentPieceBuffer(void *buf);
void func_021F6850(u16 child_aid);
extern struct piece d_021F7008;
extern struct piece g_021F7008;


void MBi_SetChildMPMaxSize(u16 childMaxSize)
{
    s32 n = childMaxSize - 2;

    *(s32 *)(((char *)&d_021F7008) + 8) = n;
    *(s32 *)(((char *)&d_021F7008) + 0xC) = 0x1E / n;
    *(s32 *)(((char *)&d_021F7008) + 0x10) = 0x1E;
}


void MBi_SetParentPieceBuffer(void *buf)
{
    *(void **)(((char *)&d_021F7008) + 4) = buf;
    MI_CpuFill8(buf, 0, 0x21C);
}


/*
 * sdk:      MBi_ClearParentPieceBuffer (libmb.TWL.HYB.a mb_block.o)
 */
void func_021F6850(u16 child_aid)
{
    int i;

    if (g_021F7008.buf == 0)
        return;
    i = child_aid - 1;
    func_02082BCC(((u8 *)g_021F7008.buf) + i * 32, 0, 30);
    *(int *)(((u8 *)g_021F7008.buf) + 0x1E0 + i * 4) = 0;
}

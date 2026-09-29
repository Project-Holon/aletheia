/*
 * function: func_021F6850
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
 *   func_02082BCC  0x02082BCC  arm
 *   g_021F7008     0x021F7008  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

struct piece {
    int f0;
    u8 *buf;
    int size;
    int max;
};

extern struct piece g_021F7008;

extern void func_02082BCC(void *dst, int val, u32 len);

void func_021F6850(u16 child_aid)
{
    int i;

    if (g_021F7008.buf == 0)
        return;
    i = child_aid - 1;
    func_02082BCC(g_021F7008.buf + i * 32, 0, 30);
    *(int *)(g_021F7008.buf + 0x1E0 + i * 4) = 0;
}

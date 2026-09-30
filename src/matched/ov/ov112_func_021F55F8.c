/*
 * function: func_021F55F8
 * address: 0x021F55F8
 * packet: pkt_ov112_021F55F8
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   sub_02030734 0x02030734 arm
 *   d_021F83D4 0x021F83D4 data a1
 *   d_02FFFC3C 0x02FFFC3C data a4
 */
typedef unsigned int u32;
typedef unsigned short u16;
extern void *sub_02030734(u32, u32, int, const char *, u16);
extern const char d_021F83D4[];
extern u32 d_02FFFC3C;
void *func_021F55F8(int count, u32 heap)
{
    char *p;
    p = sub_02030734(heap, 28, 1, d_021F83D4, 132);
    *(int *)p = count;
    *(u32 *)(p + 20) = heap;
    *(void **)(p + 4) = sub_02030734(heap, count * 4, 1, d_021F83D4, 137);
    *(u32 *)(p + 24) = d_02FFFC3C;
    *(u32 *)(p + 12) = 3 << 16;
    *(u32 *)(p + 16) = 1 << 12;
    return p;
}

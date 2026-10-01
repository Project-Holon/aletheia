/*
 * function: func_021C4880
 * address: 0x021C4880
 * packet: pkt_ov127_021C4880
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_021C6120 0x021C6120 data a1
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02030734(u16, u32, int, const char *, u16);
extern const char d_021C6120[];
typedef struct { void *entries; u32 count; } Container;
Container *func_021C4880(u32 count, u32 heap)
{
    Container *p;
    p = func_02030734(heap, 8, 1, d_021C6120, 128);
    p->count = count;
    p->entries = func_02030734(heap, 24 * p->count, 1, d_021C6120, 133);
    return p;
}

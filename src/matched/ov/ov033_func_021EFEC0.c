/*
 * function: DOWSING_CreateSearch
 * address: 0x021EFEC0
 * packet: pkt_ov033_021EFEC0
 * region: ov033
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   sDowsingFileName 0x021F0E60 data ov033 a1
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef struct { void *f00; u16 f04; void *f08; u16 f0c; } Work;
extern const char sDowsingFileName[];
extern void *func_02030734(u32, u32, int, const char *, u16);
Work *DOWSING_CreateSearch(u32 heap, void *a, void *b)
{
    Work *p;
    p = func_02030734(heap, 0x10, 1, sDowsingFileName, 0x8d);
    p->f00 = a;
    p->f04 = 0;
    p->f08 = b;
    p->f0c = 0;
    return p;
}

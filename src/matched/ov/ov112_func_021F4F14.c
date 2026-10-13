/*
 * function: func_021F4F14
 * address: 0x021F4F14
 * packet: pkt_ov112_021F4F14
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   ARC_UTIL_LoadMember 0x0204A1BC arm
 *   d_021F83B4 0x021F83B4 data a1
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern char d_021F83B4[];
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int ARC_UTIL_LoadMember(int a0, int a1, int a2, int a3);
u32 *func_021F4F14(int heap)
{
    u32 *p = func_02030734(heap, 8, 0, d_021F83B4, 0x47);
    int r = ARC_UTIL_LoadMember(45, 0x65, 0, heap);
    p[0] = r;
    p[1] = r;
    return p;
}

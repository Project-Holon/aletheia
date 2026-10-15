/*
 * function: WF2DMAP_OBJ_CreateList
 * address: 0x021C4880
 * packet: pkt_ov127_021C4880
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   sWf2dmapObjFileName 0x021C6120 data a1
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02030734(u16, u32, int, const char *, u16);
extern const char sWf2dmapObjFileName[];
typedef struct { void *entries; u32 count; } Container;
Container *WF2DMAP_OBJ_CreateList(u32 count, u32 heap)
{
    Container *p;
    p = func_02030734(heap, 8, 1, sWf2dmapObjFileName, 128);
    p->count = count;
    p->entries = func_02030734(heap, 24 * p->count, 1, sWf2dmapObjFileName, 133);
    return p;
}

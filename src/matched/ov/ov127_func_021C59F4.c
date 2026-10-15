/*
 * function: WF2DMAP_SCRDRAW_CreateBitmapDesc
 * address: 0x021C59F4
 * packet: pkt_ov127_021C59F4
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   ARC_UTIL_LoadPaletteDataFromArchive 0x02049EB4 arm
 *   WF2DMAP_SCRDRAW_LoadPalette 0x021C5AAC thumb ov127
 *   sWf2dmapScrdrawFileName 0x021C6144 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { void *f0; u32 f4; void *f8; u32 fC, f10, f14, f18; } Obj;
extern void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short tag);
extern void *ARC_UTIL_LoadPaletteDataFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void WF2DMAP_SCRDRAW_LoadPalette(void *unused, u32 id, u8 *p);
extern const char sWf2dmapScrdrawFileName[];
Obj *WF2DMAP_SCRDRAW_CreateBitmapDesc(void *p, u32 n, const u8 *q, u32 heap)
{
    Obj *o = func_02030734((u16)heap, 28, 1, sWf2dmapScrdrawFileName, 104);
    o->f0 = p;
    o->f4 = n;
    o->f10 = q[0];
    o->f14 = q[1];
    WF2DMAP_SCRDRAW_LoadPalette((void *)n, q[1], (u8 *)q);
    o->f8 = ARC_UTIL_LoadPaletteDataFromArchive(q[8], q[9], q[10], (u32)(&o->fC), heap);
    return o;
}

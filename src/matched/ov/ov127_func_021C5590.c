/*
 * function: WF2DMAP_OBJDRAW_CreateAnimSeq
 * address: 0x021C5590
 * packet: pkt_ov127_021C5590
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   WIFI_2DCHAR_Create 0x021C3EE0 thumb ov127
 *   WIFI_2DCHAR_SetupBmpCell 0x021C3FDC thumb ov127
 *   WIFI_2DCHAR_RegisterBmp 0x021C40A0 thumb ov127
 *   sWf2dmapObjdrawFileName 0x021C6130 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { void *f0; void *f4; u16 count; u8 a,b; } Obj;
extern void *func_02030734(u16, u32, int, const char *, u16);
extern void *WIFI_2DCHAR_Create(void *, void *, u32, u32);
extern void WIFI_2DCHAR_SetupBmpCell(u8 *p, int a, int b, int c, int d);
extern void WIFI_2DCHAR_RegisterBmp(u8 *p, int a, int b, int c);
extern const char sWf2dmapObjdrawFileName[];
Obj *WF2DMAP_OBJDRAW_CreateAnimSeq(void *p, void *q, u32 n, void *r, int s, u32 b, u32 heap)
{
    Obj *o = func_02030734(heap, 12, 1, sWf2dmapObjdrawFileName, 161);
    o->f0 = WIFI_2DCHAR_Create(p, q, n, heap);
    o->count = n;
    o->f4 = func_02030734(heap, 20 * o->count, 1, sWf2dmapObjdrawFileName, 168);
    o->a = 2;
    o->b = b;
    WIFI_2DCHAR_SetupBmpCell(o->f0, (int)r, o->b, s, heap);
    WIFI_2DCHAR_RegisterBmp(o->f0, o->b, 255, heap);
    return o;
}

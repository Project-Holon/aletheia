/*
 * function: ZONEDATA_GetTimeLightColors
 * address:  0x0201493C
 * packet:   pkt_0201493C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The three-way fallback load of the 0x34-byte time-of-day table (member
 * 0x3e for an explicit id, 0x52 for the id ZONEDATA_GetLightId maps, else 0x3d
 * built through ZONEDATA_CreateAreaData), then ZONEDATA_FindLightEntryColors over it and a free.
 *
 * Closed in wave 13 by the declaration, not the body: the seventh
 * parameter is a u16 heap id (the ov094 caller at 0x021F7702 loads it
 * with ldrh), written `(heap & 0x7fff) | 0x8000` at each of the four
 * uses.  The earlier note (docs/notes/pkt_0201493C.c.txt) read it as the
 * low half of a word through `*(u16 *)((char *)&b0 + 8)` and had to spell
 * the first tag as 0x10000000; with the real parameter type both of its
 * "back-end tie-breaks" (the pooled 0x0FFFFFFF + 1 tag and the late b0
 * reload) disappear.
 *
 * symbols:
 *   ZONEDATA_GetLightTableMember  0x02014A10  thumb
 *   ZONEDATA_LoadLightTable  0x02014A20  thumb
 *   ZONEDATA_GetLightId  0x02013F2C  thumb
 *   ZONEDATA_GetAreaId  0x02013B38  thumb
 *   ZONEDATA_CreateAreaData  0x0201407C  thumb
 *   ZONEDATA_GetAreaLightType  0x020140DC  thumb
 *   ZONEDATA_DeleteAreaData  0x020140B4  thumb
 *   ZONEDATA_FindLightEntryColors  0x02014A80  thumb
 *   GFL_HEAP_Free   0x020307B0  arm
 */
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

typedef unsigned char  u8;
struct Sub020140BCObj;
extern u16 ZONEDATA_GetLightTableMember(u32 i);
extern void *ZONEDATA_LoadLightTable(u32 archive, u32 member, u32 *count_out, u32 heap);
extern u32 ZONEDATA_GetLightId(u32 id);
extern u32 ZONEDATA_GetAreaId(u32 id);
extern void *ZONEDATA_CreateAreaData(u16 heap, u32 a, u32 b);
extern u8 ZONEDATA_GetAreaLightType(struct Sub020140BCObj *p);
extern u32 ZONEDATA_DeleteAreaData(void *a);
extern void ZONEDATA_FindLightEntryColors(u8 *a0, u32 a1, s32 a2, u32 a3, u16 *out);
extern u32 GFL_HEAP_Free(void *p);
void ZONEDATA_GetTimeLightColors(u32 id, u32 a1, u32 a2, u32 a3,
                   u32 b0, u16 *b1, u16 heap)
{
    u32 count;
    void *p = 0;
    s32 o2;
    s32 o1;

    o1 = a2 * 0x3c;
    o2 = a1 * 0xe10;

    if (a3 != 0) {
        p = ZONEDATA_LoadLightTable(0x3e, ZONEDATA_GetLightTableMember(a3), &count, (u16)((heap & 0x7fff) | 0x8000));
    }
    if (p == 0) {
        u32 t = ZONEDATA_GetLightId((u16)id);
        if (t != 0xfffffff)
            p = ZONEDATA_LoadLightTable(0x52, t, &count, (u16)((heap & 0x7fff) | 0x8000));
    }
    if (p == 0) {
        void *q = ZONEDATA_CreateAreaData((heap & 0x7fff) | 0x8000, ZONEDATA_GetAreaId((u16)id), b0);
        p = ZONEDATA_LoadLightTable(0x3d, ZONEDATA_GetAreaLightType(q), &count, (u16)((heap & 0x7fff) | 0x8000));
        ZONEDATA_DeleteAreaData((void *)q);
    }
    ZONEDATA_FindLightEntryColors(p, count, o1 + o2, b0, b1);
    GFL_HEAP_Free(p);
}
